#include <math.h>
#include <stdlib.h>
#include "platform.h"
#include "so_util.h"
#include "libyoyo_internals.h"
#include "libyoyo.h"

#define STB_ONLY_PNG
#include "stb_image.h"
#include "io_util.h"
#include "gles2.h"

int *g_TextureScale = NULL;
ABI_ATTR uint32_t *(*ReadPNGFile)(void *a1, int a2, int *a3, int *a4, int a5) = NULL;
ABI_ATTR void (*FreePNGFile)() = NULL;
ABI_ATTR void (*InvalidateTextureState)() = NULL;
int setup_ended = 0;

typedef struct pvrtc_file {
    uint8_t pad1[0x08];
    uint64_t format;
    uint32_t pad2[0x02];
    int32_t width;
    int32_t height;
    uint32_t pad3[0x04];
    uint32_t metadata_size;
    uint8_t data[];
} __attribute__((packed)) pvrtc_file;

void LoadTextureFromPNG_generic(uint32_t arg1, uint32_t arg2, uint32_t *flags, uint32_t *tex_id, uint32_t *texture) {
    int width, height;
    uint32_t *data = ReadPNGFile(arg1 , arg2, &width, &height, (*flags & 2) == 0);
    if (data) {
        InvalidateTextureState();
        glGenTextures(1, tex_id);
        glBindTexture(GL_TEXTURE_2D, *tex_id);

        if (width == 2 && height == 1) {
            if (data[0] == 0xFFBEADDE) {
                int fd;
                pvrtc_file *ext_data = NULL;
                size_t ext_data_sz = 0;
                uint32_t idx = (data[1] << 8) >> 8;
                char fname[256];

				// Load from APK first and then try the gamedir
                sprintf(fname, "assets/%u.pvr", idx);
				if (!zip_inflate_buf(zip_get_current_apk(), fname, &ext_data_sz, &ext_data)) {
                	sprintf(fname, "%s%u.pvr", get_platform_savedir(), idx);
                	io_buffer_from_file(fname, &fd, &ext_data, &ext_data_sz, 0);
				}

                warning("Trying to load %s... %p\n", fname, ext_data);
                
                if (ext_data) {
                    uintptr_t texture_data = (uintptr_t)&ext_data->data + (uintptr_t)ext_data->metadata_size;
                    size_t texture_data_size = (ext_data_sz + (uintptr_t)ext_data) - texture_data;

                    width = ext_data->width;
                    height = ext_data->height;
                    warning("Texture size: %dx%d fmt: 0x%04llX (%p: %d bytes)\n", width, height, ext_data->format, texture_data, (int)texture_data_size);
                    switch (ext_data->format) {
					case 0x00:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x01:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x02:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x03:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x04:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_PVRTC_2BPPV2_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x05:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_PVRTC_4BPPV2_IMG, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x06:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_ETC1_RGB8_OES, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x07:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, width, height, 0, texture_data_size, texture_data);
						break;
					case 0x09:
						glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, width, height, 0, texture_data_size, texture_data);
						break;
                    }
                    GLint err = glGetError();
                    if (err != GL_NO_ERROR) {
                        fatal_error("Failed to upload texture, 0x%04X\n", err);
                    }

                    free(ext_data);
                }
            } else {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            }
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        *flags = *flags | 0x40;
        FreePNGFile();
        texture[0] = 0x06;
        if (flags != &texture[2]) {
            texture[1] = width;
            texture[2] = height;
        } else {
            texture[1] = ((width * *g_TextureScale - 1) | texture[1] & 0xFFFFE000) & 0xFC001FFF | ((height * *g_TextureScale - 1) << 13);
        }
        warning("Texture size: %dx%d\n", width, height);
    } else {
        fatal_error("ERROR: Failed to load a PNG texture!\n");
    }
}

ABI_ATTR void LoadTextureFromPNG_1(uint32_t *texture, int has_mips) {
    LoadTextureFromPNG_generic(texture[23], texture[24], &texture[5], &texture[6], texture);
}

ABI_ATTR void LoadTextureFromPNG_2(uint32_t *texture, int has_mips) {
    LoadTextureFromPNG_generic(texture[11], texture[12], &texture[4], &texture[5], texture);
}

ABI_ATTR void LoadTextureFromPNG_3(uint32_t *texture) {
    LoadTextureFromPNG_generic(texture[9], texture[10], &texture[2], &texture[3], texture);
}

ABI_ATTR void LoadTextureFromPNG_4(uint32_t *texture) {
    LoadTextureFromPNG_generic(texture[8], texture[9], &texture[2], &texture[3], texture);
}

int image_preload_idx = 0;
uint32_t png_get_IHDR_hook(uint32_t *png_ptr, uint32_t *info_ptr, uint32_t *width, uint32_t *height, int *bit_depth, int *color_type, int *interlace_type, int *compression_type, int *filter_type) {
	if (!png_ptr || !info_ptr || !width || !height)
		return 0;
	
	*width = info_ptr[0];
	*height = info_ptr[1];

	if (bit_depth)
		*bit_depth = *((uint8_t *)info_ptr + 24);

	if (color_type)
		*color_type = *((uint8_t *)info_ptr + 25);

	if (compression_type)
		*compression_type = *((uint8_t *)info_ptr + 26);

	if (filter_type)
		*filter_type = *((uint8_t *)info_ptr + 27);

	if (interlace_type)
		*interlace_type = *((uint8_t *)info_ptr + 28);

	if (!setup_ended && *width == 2 && *height == 1) {
		char fname[256];
		FILE *f;
		uint32_t _sz;
		uint32_t *buffer;

		*width = 0;
		*height = 0;

		sprintf(fname, "assets/%u.pvr", image_preload_idx);
		if (zip_inflate_buf_sz(zip_get_current_apk(), fname, &_sz, &buffer, 0x20)) {
			*width = buffer[6];
			*height = buffer[7];
			free(buffer);
		} else {
			sprintf(fname, "%s%d.pvr", get_platform_savedir(), image_preload_idx);
			FILE *f = fopen(fname, "rb");
			if (f) {
				fseek(f, 0x18, SEEK_SET);
				fread(height, 1, 4, f);
				fread(width, 1, 4, f);
				fclose(f);
			}
		}

		if (*width == 0 || *height == 0) {
			warning("Texture %d metadata preload failure.\n", image_preload_idx);
		}
		
		image_preload_idx++;
	}
	return 1;
}

void register_texture_functs(so_module *mod)
{
    ENSURE_SYMBOL(mod, InvalidateTextureState, "_Z23_InvalidateTextureStatev");
    ENSURE_SYMBOL(mod, FreePNGFile, "_Z11FreePNGFilev");
    ENSURE_SYMBOL(mod, ReadPNGFile, "_Z11ReadPNGFilePviPiS0_b");
    ENSURE_SYMBOL(mod, g_TextureScale, "g_TextureScale");

    hook_symbol(mod, "png_get_IHDR", (uintptr_t)&png_get_IHDR_hook, 0);

    uint8_t has_mips = 1;
	uint32_t *LoadTextureFromPNG = (uint32_t *)so_symbol(mod, "_Z18LoadTextureFromPNGP7Texture10eMipEnable");
	if (!LoadTextureFromPNG) {
		LoadTextureFromPNG = (uint32_t *)so_symbol(mod, "_Z18LoadTextureFromPNGP7Texture");
		has_mips = 0;
	}

    if (!has_mips) {
		uint32_t *p = LoadTextureFromPNG;
		for (;;) {
			if (*p == 0xE5900020) { // LDR R0, [R0,#0x20]
				warning("Patching LoadTextureFromPNG to variant #4\n");
				hook_address(mod, LoadTextureFromPNG, (uintptr_t)&LoadTextureFromPNG_4);
				break;
			} else if (*p == 0xE5900024) { // LDR R0, [R0,#0x24]
				warning("Patching LoadTextureFromPNG to variant #3\n");
				hook_address(mod, LoadTextureFromPNG, (uintptr_t)&LoadTextureFromPNG_3);
				break;
			}
			p++;
		}
	} else {
		switch (*LoadTextureFromPNG >> 16) {
		case 0xE92D:
			warning("Patching LoadTextureFromPNG to variant #1\n");
			hook_address(mod, LoadTextureFromPNG, (uintptr_t)&LoadTextureFromPNG_1);
			break;
		case 0xE590:
			warning("Patching LoadTextureFromPNG to variant #2\n");
			hook_address(mod, LoadTextureFromPNG, (uintptr_t)&LoadTextureFromPNG_2);
			break;
		default:
			fatal_error("Error: Unrecognized LoadTextureFromPNG signature: 0x%08X.", *LoadTextureFromPNG);
			break;
		}
	}
}