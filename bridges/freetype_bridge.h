#ifndef __FREETYPE_BRIDGE_H__
#define __FREETYPE_BRIDGE_H__

#define FT_BRIDGE \
    FT_DECL_FWD   (FT_Init_FreeType,                        FT_Error,              (FT_Library* alibrary), (alibrary)) \
	FT_DECL_FWD   (FT_Done_FreeType,                        FT_Error,              (FT_Library library), (library)) \
	FT_DECL_FWD   (FT_New_Face,                             FT_Error,              (FT_Library library, const char* filepathname, FT_Long face_index, FT_Face* aface), (library, filepathname, face_index, aface)) \
	FT_DECL_FWD   (FT_New_Memory_Face,                      FT_Error,              (FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face* aface), (library, file_base, file_size, face_index, aface)) \
	FT_DECL_FWD   (FT_Open_Face,                            FT_Error,              (FT_Library library, const FT_Open_Args* args, FT_Long face_index, FT_Face* aface), (library, args, face_index, aface)) \
	FT_DECL_FWD   (FT_Attach_File,                          FT_Error,              (FT_Face face, const char* filepathname), (face, filepathname)) \
	FT_DECL_FWD   (FT_Attach_Stream,                        FT_Error,              (FT_Face face, FT_Open_Args* parameters), (face, parameters)) \
	FT_DECL_FWD   (FT_Reference_Face,                       FT_Error,              (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Done_Face,                            FT_Error,              (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Select_Size,                          FT_Error,              (FT_Face face, FT_Int strike_index), (face, strike_index)) \
	FT_DECL_FWD   (FT_Request_Size,                         FT_Error,              (FT_Face face, FT_Size_Request req), (face, req)) \
	FT_DECL_FWD   (FT_Set_Char_Size,                        FT_Error,              (FT_Face face, FT_F26Dot6 char_width, FT_F26Dot6 char_height, FT_UInt horz_resolution, FT_UInt vert_resolution), (face, char_width, char_height, horz_resolution, vert_resolution)) \
	FT_DECL_FWD   (FT_Set_Pixel_Sizes,                      FT_Error,              (FT_Face face, FT_UInt pixel_width, FT_UInt pixel_height), (face, pixel_width, pixel_height)) \
	FT_DECL_FWD   (FT_Load_Glyph,                           FT_Error,              (FT_Face face, FT_UInt glyph_index, FT_Int32 load_flags), (face, glyph_index, load_flags)) \
	FT_DECL_FWD   (FT_Load_Char,                            FT_Error,              (FT_Face face, FT_ULong char_code, FT_Int32 load_flags), (face, char_code, load_flags)) \
	FT_DECL_FWD   (FT_Render_Glyph,                         FT_Error,              (FT_GlyphSlot slot, FT_Render_Mode render_mode), (slot, render_mode)) \
	FT_DECL_FWD   (FT_Get_Kerning,                          FT_Error,              (FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector* akerning), (face, left_glyph, right_glyph, kern_mode, akerning)) \
	FT_DECL_FWD   (FT_Get_Track_Kerning,                    FT_Error,              (FT_Face face, FT_Fixed point_size, FT_Int degree, FT_Fixed* akerning), (face, point_size, degree, akerning)) \
	FT_DECL_FWD   (FT_Get_Glyph_Name,                       FT_Error,              (FT_Face face, FT_UInt glyph_index, FT_Pointer buffer, FT_UInt buffer_max), (face, glyph_index, buffer, buffer_max)) \
	FT_DECL_FWD   (FT_Select_Charmap,                       FT_Error,              (FT_Face face, FT_Encoding encoding), (face, encoding)) \
	FT_DECL_FWD   (FT_Set_Charmap,                          FT_Error,              (FT_Face face, FT_CharMap charmap), (face, charmap)) \
	FT_DECL_FWD   (FT_Get_Charmap_Index,                    FT_Int,                (FT_CharMap charmap), (charmap)) \
	FT_DECL_FWD   (FT_Get_Char_Index,                       FT_UInt,               (FT_Face face, FT_ULong charcode), (face, charcode)) \
	FT_DECL_FWD   (FT_Get_First_Char,                       FT_ULong,              (FT_Face face, FT_UInt* agindex), (face, agindex)) \
	FT_DECL_FWD   (FT_Get_Next_Char,                        FT_ULong,              (FT_Face face, FT_ULong char_code, FT_UInt* agindex), (face, char_code, agindex)) \
	FT_DECL_FWD   (FT_Face_Properties,                      FT_Error,              (FT_Face face, FT_UInt num_properties, FT_Parameter* properties), (face, num_properties, properties)) \
	FT_DECL_FWD   (FT_Get_Name_Index,                       FT_UInt,               (FT_Face face, FT_String* glyph_name), (face, glyph_name)) \
	FT_DECL_FWD   (FT_Get_SubGlyph_Info,                    FT_Error,              (FT_GlyphSlot glyph, FT_UInt sub_index, FT_Int* p_index, FT_UInt* p_flags, FT_Int* p_arg1, FT_Int* p_arg2, FT_Matrix* p_transform), (glyph, sub_index, p_index, p_flags, p_arg1, p_arg2, p_transform)) \
	FT_DECL_FWD   (FT_Get_FSType_Flags,                     FT_UShort,             (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Face_GetCharVariantIndex,             FT_UInt,               (FT_Face face, FT_ULong charcode, FT_ULong variantSelector), (face, charcode, variantSelector)) \
	FT_DECL_FWD   (FT_Face_GetCharVariantIsDefault,         FT_Int,                (FT_Face face, FT_ULong charcode, FT_ULong variantSelector), (face, charcode, variantSelector)) \
	FT_DECL_FWD   (FT_Face_GetVariantSelectors,             FT_UInt32*,            (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Face_GetVariantsOfChar,               FT_UInt32*,            (FT_Face face, FT_ULong charcode), (face, charcode)) \
	FT_DECL_FWD   (FT_Face_GetCharsOfVariant,               FT_UInt32*,            (FT_Face face, FT_ULong variantSelector), (face, variantSelector)) \
	FT_DECL_FWD   (FT_MulDiv,                               FT_Long,               (FT_Long a, FT_Long b, FT_Long c), (a, b, c)) \
	FT_DECL_FWD   (FT_MulFix,                               FT_Long,               (FT_Long a, FT_Long b), (a, b)) \
	FT_DECL_FWD   (FT_DivFix,                               FT_Long,               (FT_Long a, FT_Long b), (a, b)) \
	FT_DECL_FWD   (FT_RoundFix,                             FT_Fixed,              (FT_Fixed a), (a)) \
	FT_DECL_FWD   (FT_CeilFix,                              FT_Fixed,              (FT_Fixed a), (a)) \
	FT_DECL_FWD   (FT_FloorFix,                             FT_Fixed,              (FT_Fixed a), (a)) \
	FT_DECL_FWD   (FT_Face_CheckTrueTypePatents,            FT_Bool,               (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Face_SetUnpatentedHinting,            FT_Bool,               (FT_Face face, FT_Bool value), (face, value)) \
	FT_DECL_FWD   (FT_Get_Advance,                          FT_Error,              (FT_Face face, FT_UInt gindex, FT_Int32 load_flags, FT_Fixed* padvance), (face, gindex, load_flags, padvance)) \
	FT_DECL_FWD   (FT_Get_Advances,                         FT_Error,              (FT_Face face, FT_UInt start, FT_UInt count, FT_Int32 load_flags, FT_Fixed* padvances), (face, start, count, load_flags, padvances)) \
	FT_DECL_FWD   (FT_Outline_Get_BBox,                     FT_Error,              (FT_Outline* outline, FT_BBox* abbox), (outline, abbox)) \
	FT_DECL_FWD   (FT_Get_BDF_Charset_ID,                   FT_Error,              (FT_Face face, const char** acharset_encoding, const char** acharset_registry), (face, acharset_encoding, acharset_registry)) \
	FT_DECL_FWD   (FT_Get_BDF_Property,                     FT_Error,              (FT_Face face, const char* prop_name, BDF_PropertyRec* aproperty), (face, prop_name, aproperty)) \
	FT_DECL_FWD   (FT_Bitmap_Copy,                          FT_Error,              (FT_Library library, const FT_Bitmap* source, FT_Bitmap* target), (library, source, target)) \
	FT_DECL_FWD   (FT_Bitmap_Embolden,                      FT_Error,              (FT_Library library, FT_Bitmap* bitmap, FT_Pos xStrength, FT_Pos yStrength), (library, bitmap, xStrength, yStrength)) \
	FT_DECL_FWD   (FT_Bitmap_Convert,                       FT_Error,              (FT_Library library, const FT_Bitmap* source, FT_Bitmap* target, FT_Int alignment), (library, source, target, alignment)) \
	FT_DECL_FWD   (FT_GlyphSlot_Own_Bitmap,                 FT_Error,              (FT_GlyphSlot slot), (slot)) \
	FT_DECL_FWD   (FT_Bitmap_Done,                          FT_Error,              (FT_Library library, FT_Bitmap* bitmap), (library, bitmap)) \
	FT_DECL_FWD   (FT_Stream_OpenBzip2,                     FT_Error,              (FT_Stream stream, FT_Stream source), (stream, source)) \
	FT_DECL_FWD   (FT_Get_Glyph,                            FT_Error,              (FT_GlyphSlot slot, FT_Glyph* aglyph), (slot, aglyph)) \
	FT_DECL_FWD   (FT_Glyph_Copy,                           FT_Error,              (FT_Glyph source, FT_Glyph* target), (source, target)) \
	FT_DECL_FWD   (FT_Glyph_Transform,                      FT_Error,              (FT_Glyph glyph, FT_Matrix* matrix, FT_Vector* delta), (glyph, matrix, delta)) \
	FT_DECL_FWD   (FT_Glyph_To_Bitmap,                      FT_Error,              (FT_Glyph* the_glyph, FT_Render_Mode render_mode, FT_Vector* origin, FT_Bool destroy), (the_glyph, render_mode, origin, destroy)) \
	FT_DECL_FWD   (FT_Matrix_Invert,                        FT_Error,              (FT_Matrix* matrix), (matrix)) \
	FT_DECL_FWD   (FTC_Manager_New,                         FT_Error,              (FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager* amanager), (library, max_faces, max_sizes, max_bytes, requester, req_data, amanager)) \
	FT_DECL_FWD   (FTC_Manager_LookupFace,                  FT_Error,              (FTC_Manager manager, FTC_FaceID face_id, FT_Face* aface), (manager, face_id, aface)) \
	FT_DECL_FWD   (FTC_Manager_LookupSize,                  FT_Error,              (FTC_Manager manager, FTC_Scaler scaler, FT_Size* asize), (manager, scaler, asize)) \
	FT_DECL_FWD   (FTC_CMapCache_New,                       FT_Error,              (FTC_Manager manager, FTC_CMapCache* acache), (manager, acache)) \
	FT_DECL_FWD   (FTC_CMapCache_Lookup,                    FT_UInt,               (FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code), (cache, face_id, cmap_index, char_code)) \
	FT_DECL_FWD   (FTC_ImageCache_New,                      FT_Error,              (FTC_Manager manager, FTC_ImageCache* acache), (manager, acache)) \
	FT_DECL_FWD   (FTC_ImageCache_Lookup,                   FT_Error,              (FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph* aglyph, FTC_Node* anode), (cache, type, gindex, aglyph, anode)) \
	FT_DECL_FWD   (FTC_ImageCache_LookupScaler,             FT_Error,              (FTC_ImageCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FT_Glyph* aglyph, FTC_Node* anode), (cache, scaler, load_flags, gindex, aglyph, anode)) \
	FT_DECL_FWD   (FTC_SBitCache_New,                       FT_Error,              (FTC_Manager manager, FTC_SBitCache* acache), (manager, acache)) \
	FT_DECL_FWD   (FTC_SBitCache_Lookup,                    FT_Error,              (FTC_SBitCache cache, FTC_ImageType type, FT_UInt gindex, FTC_SBit* sbit, FTC_Node* anode), (cache, type, gindex, sbit, anode)) \
	FT_DECL_FWD   (FTC_SBitCache_LookupScaler,              FT_Error,              (FTC_SBitCache cache, FTC_Scaler scaler, FT_ULong load_flags, FT_UInt gindex, FTC_SBit* sbit, FTC_Node* anode), (cache, scaler, load_flags, gindex, sbit, anode)) \
	FT_DECL_FWD   (FT_Get_CID_Registry_Ordering_Supplement, FT_Error,              (FT_Face face, const char** registry, const char** ordering, FT_Int* supplement), (face, registry, ordering, supplement)) \
	FT_DECL_FWD   (FT_Get_CID_Is_Internally_CID_Keyed,      FT_Error,              (FT_Face face, FT_Bool* is_cid), (face, is_cid)) \
	FT_DECL_FWD   (FT_Get_CID_From_Glyph_Index,             FT_Error,              (FT_Face face, FT_UInt glyph_index, FT_UInt* cid), (face, glyph_index, cid)) \
	FT_DECL_FWD   (FT_Get_Gasp,                             FT_Int,                (FT_Face face, FT_UInt ppem), (face, ppem)) \
	FT_DECL_FWD   (FT_ClassicKern_Validate,                 FT_Error,              (FT_Face face, FT_UInt validation_flags, FT_Bytes* ckern_table), (face, validation_flags, ckern_table)) \
	FT_DECL_FWD   (FT_Stream_OpenGzip,                      FT_Error,              (FT_Stream stream, FT_Stream source), (stream, source)) \
	FT_DECL_FWD   (FT_Gzip_Uncompress,                      FT_Error,              (FT_Memory memory, FT_Byte* output, FT_ULong* output_len, const FT_Byte* input, FT_ULong input_len), (memory, output, output_len, input, input_len)) \
	FT_DECL_FWD   (FT_Library_SetLcdFilter,                 FT_Error,              (FT_Library library, FT_LcdFilter filter), (library, filter)) \
	FT_DECL_FWD   (FT_Library_SetLcdFilterWeights,          FT_Error,              (FT_Library library, unsigned char* weights), (library, weights)) \
	FT_DECL_FWD   (FT_List_Find,                            FT_ListNode,           (FT_List list, void* data), (list, data)) \
	FT_DECL_FWD   (FT_List_Iterate,                         FT_Error,              (FT_List list, FT_List_Iterator iterator, void* user), (list, iterator, user)) \
	FT_DECL_FWD   (FT_Stream_OpenLZW,                       FT_Error,              (FT_Stream stream, FT_Stream source), (stream, source)) \
	FT_DECL_FWD   (FT_Has_PS_Glyph_Names,                   FT_Int,                (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Get_PS_Font_Info,                     FT_Error,              (FT_Face face, PS_FontInfo afont_info), (face, afont_info)) \
	FT_DECL_FWD   (FT_Get_PS_Font_Private,                  FT_Error,              (FT_Face face, PS_Private afont_private), (face, afont_private)) \
	FT_DECL_FWD   (FT_Get_PS_Font_Value,                    FT_Long,               (FT_Face face, PS_Dict_Keys key, FT_UInt idx, void* value, FT_Long value_len), (face, key, idx, value, value_len)) \
	FT_DECL_FWD   (FT_Get_Multi_Master,                     FT_Error,              (FT_Face face, FT_Multi_Master* amaster), (face, amaster)) \
	FT_DECL_FWD   (FT_Get_MM_Var,                           FT_Error,              (FT_Face face, FT_MM_Var** amaster), (face, amaster)) \
	FT_DECL_FWD   (FT_Done_MM_Var,                          FT_Error,              (FT_Library library, FT_MM_Var* amaster), (library, amaster)) \
	FT_DECL_FWD   (FT_Set_MM_Design_Coordinates,            FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Long* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Set_Var_Design_Coordinates,           FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Get_Var_Design_Coordinates,           FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Set_MM_Blend_Coordinates,             FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Get_MM_Blend_Coordinates,             FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Set_Var_Blend_Coordinates,            FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Get_Var_Blend_Coordinates,            FT_Error,              (FT_Face face, FT_UInt num_coords, FT_Fixed* coords), (face, num_coords, coords)) \
	FT_DECL_FWD   (FT_Get_Var_Axis_Flags,                   FT_Error,              (FT_MM_Var* master, FT_UInt axis_index, FT_UInt* flags), (master, axis_index, flags)) \
	FT_DECL_FWD   (FT_Set_Named_Instance,                   FT_Error,              (FT_Face face, FT_UInt instance_index), (face, instance_index)) \
	FT_DECL_FWD   (FT_Add_Module,                           FT_Error,              (FT_Library library, const FT_Module_Class* clazz), (library, clazz)) \
	FT_DECL_FWD   (FT_Get_Module,                           FT_Module,             (FT_Library library, const char* module_name), (library, module_name)) \
	FT_DECL_FWD   (FT_Remove_Module,                        FT_Error,              (FT_Library library, FT_Module module), (library, module)) \
	FT_DECL_FWD   (FT_Property_Set,                         FT_Error,              (FT_Library library, const FT_String* module_name, const FT_String* property_name, const void* value), (library, module_name, property_name, value)) \
	FT_DECL_FWD   (FT_Property_Get,                         FT_Error,              (FT_Library library, const FT_String* module_name, const FT_String* property_name, void* value), (library, module_name, property_name, value)) \
	FT_DECL_FWD   (FT_Reference_Library,                    FT_Error,              (FT_Library library), (library)) \
	FT_DECL_FWD   (FT_New_Library,                          FT_Error,              (FT_Memory memory, FT_Library* alibrary), (memory, alibrary)) \
	FT_DECL_FWD   (FT_Done_Library,                         FT_Error,              (FT_Library library), (library)) \
	FT_DECL_FWD   (FT_Get_TrueType_Engine_Type,             FT_TrueTypeEngineType, (FT_Library library), (library)) \
	FT_DECL_FWD   (FT_OpenType_Validate,                    FT_Error,              (FT_Face face, FT_UInt validation_flags, FT_Bytes* BASE_table, FT_Bytes* GDEF_table, FT_Bytes* GPOS_table, FT_Bytes* GSUB_table, FT_Bytes* JSTF_table), (face, validation_flags, BASE_table, GDEF_table, GPOS_table, GSUB_table, JSTF_table)) \
	FT_DECL_FWD   (FT_Outline_Decompose,                    FT_Error,              (FT_Outline* outline, const FT_Outline_Funcs* func_interface, void* user), (outline, func_interface, user)) \
	FT_DECL_FWD   (FT_Outline_New,                          FT_Error,              (FT_Library library, FT_UInt numPoints, FT_Int numContours, FT_Outline* anoutline), (library, numPoints, numContours, anoutline)) \
	FT_DECL_FWD   (FT_Outline_Done,                         FT_Error,              (FT_Library library, FT_Outline* outline), (library, outline)) \
	FT_DECL_FWD   (FT_Outline_Check,                        FT_Error,              (FT_Outline* outline), (outline)) \
	FT_DECL_FWD   (FT_Outline_Copy,                         FT_Error,              (const FT_Outline* source, FT_Outline* target), (source, target)) \
	FT_DECL_FWD   (FT_Outline_Embolden,                     FT_Error,              (FT_Outline* outline, FT_Pos strength), (outline, strength)) \
	FT_DECL_FWD   (FT_Outline_EmboldenXY,                   FT_Error,              (FT_Outline* outline, FT_Pos xstrength, FT_Pos ystrength), (outline, xstrength, ystrength)) \
	FT_DECL_FWD   (FT_Outline_Get_Bitmap,                   FT_Error,              (FT_Library library, FT_Outline* outline, const FT_Bitmap* abitmap), (library, outline, abitmap)) \
	FT_DECL_FWD   (FT_Outline_Render,                       FT_Error,              (FT_Library library, FT_Outline* outline, FT_Raster_Params* params), (library, outline, params)) \
	FT_DECL_FWD   (FT_Outline_Get_Orientation,              FT_Orientation,        (FT_Outline* outline), (outline)) \
	FT_DECL_FWD   (FT_Get_PFR_Metrics,                      FT_Error,              (FT_Face face, FT_UInt* aoutline_resolution, FT_UInt* ametrics_resolution, FT_Fixed* ametrics_x_scale, FT_Fixed* ametrics_y_scale), (face, aoutline_resolution, ametrics_resolution, ametrics_x_scale, ametrics_y_scale)) \
	FT_DECL_FWD   (FT_Get_PFR_Kerning,                      FT_Error,              (FT_Face face, FT_UInt left, FT_UInt right, FT_Vector* avector), (face, left, right, avector)) \
	FT_DECL_FWD   (FT_Get_PFR_Advance,                      FT_Error,              (FT_Face face, FT_UInt gindex, FT_Pos* aadvance), (face, gindex, aadvance)) \
	FT_DECL_FWD   (FT_Get_Renderer,                         FT_Renderer,           (FT_Library library, FT_Glyph_Format format), (library, format)) \
	FT_DECL_FWD   (FT_Set_Renderer,                         FT_Error,              (FT_Library library, FT_Renderer renderer, FT_UInt num_params, FT_Parameter* parameters), (library, renderer, num_params, parameters)) \
	FT_DECL_FWD   (FT_New_Size,                             FT_Error,              (FT_Face face, FT_Size* size), (face, size)) \
	FT_DECL_FWD   (FT_Done_Size,                            FT_Error,              (FT_Size size), (size)) \
	FT_DECL_FWD   (FT_Activate_Size,                        FT_Error,              (FT_Size size), (size)) \
	FT_DECL_FWD   (FT_Get_Sfnt_Name_Count,                  FT_UInt,               (FT_Face face), (face)) \
	FT_DECL_FWD   (FT_Get_Sfnt_Name,                        FT_Error,              (FT_Face face, FT_UInt idx, FT_SfntName* aname), (face, idx, aname)) \
	FT_DECL_FWD   (FT_Get_Sfnt_LangTag,                     FT_Error,              (FT_Face face, FT_UInt langID, FT_SfntLangTag* alangTag), (face, langID, alangTag)) \
	FT_DECL_FWD   (FT_Outline_GetInsideBorder,              FT_StrokerBorder,      (FT_Outline* outline), (outline)) \
	FT_DECL_FWD   (FT_Outline_GetOutsideBorder,             FT_StrokerBorder,      (FT_Outline* outline), (outline)) \
	FT_DECL_FWD   (FT_Stroker_New,                          FT_Error,              (FT_Library library, FT_Stroker* astroker), (library, astroker)) \
	FT_DECL_FWD   (FT_Stroker_ParseOutline,                 FT_Error,              (FT_Stroker stroker, FT_Outline* outline, FT_Bool opened), (stroker, outline, opened)) \
	FT_DECL_FWD   (FT_Stroker_BeginSubPath,                 FT_Error,              (FT_Stroker stroker, FT_Vector* to, FT_Bool open), (stroker, to, open)) \
	FT_DECL_FWD   (FT_Stroker_EndSubPath,                   FT_Error,              (FT_Stroker stroker), (stroker)) \
	FT_DECL_FWD   (FT_Stroker_LineTo,                       FT_Error,              (FT_Stroker stroker, FT_Vector* to), (stroker, to)) \
	FT_DECL_FWD   (FT_Stroker_ConicTo,                      FT_Error,              (FT_Stroker stroker, FT_Vector* control, FT_Vector* to), (stroker, control, to)) \
	FT_DECL_FWD   (FT_Stroker_CubicTo,                      FT_Error,              (FT_Stroker stroker, FT_Vector* control1, FT_Vector* control2, FT_Vector* to), (stroker, control1, control2, to)) \
	FT_DECL_FWD   (FT_Stroker_GetBorderCounts,              FT_Error,              (FT_Stroker stroker, FT_StrokerBorder border, FT_UInt* anum_points, FT_UInt* anum_contours), (stroker, border, anum_points, anum_contours)) \
	FT_DECL_FWD   (FT_Stroker_GetCounts,                    FT_Error,              (FT_Stroker stroker, FT_UInt* anum_points, FT_UInt* anum_contours), (stroker, anum_points, anum_contours)) \
	FT_DECL_FWD   (FT_Glyph_Stroke,                         FT_Error,              (FT_Glyph* pglyph, FT_Stroker stroker, FT_Bool destroy), (pglyph, stroker, destroy)) \
	FT_DECL_FWD   (FT_Glyph_StrokeBorder,                   FT_Error,              (FT_Glyph* pglyph, FT_Stroker stroker, FT_Bool inside, FT_Bool destroy), (pglyph, stroker, inside, destroy)) \
	FT_DECL_FWD   (FT_Sin,                                  FT_Fixed,              (FT_Angle angle), (angle)) \
	FT_DECL_FWD   (FT_Cos,                                  FT_Fixed,              (FT_Angle angle), (angle)) \
	FT_DECL_FWD   (FT_Tan,                                  FT_Fixed,              (FT_Angle angle), (angle)) \
	FT_DECL_FWD   (FT_Atan2,                                FT_Angle,              (FT_Fixed x, FT_Fixed y), (x, y)) \
	FT_DECL_FWD   (FT_Angle_Diff,                           FT_Angle,              (FT_Angle angle1, FT_Angle angle2), (angle1, angle2)) \
	FT_DECL_FWD   (FT_Vector_Length,                        FT_Fixed,              (FT_Vector* vec), (vec)) \
	FT_DECL_FWD   (FT_Get_WinFNT_Header,                    FT_Error,              (FT_Face face, FT_WinFNT_HeaderRec* aheader), (face, aheader)) \
	FT_DECL_FWD   (FT_Get_Sfnt_Table,                       void*,                 (FT_Face face, FT_Sfnt_Tag tag), (face, tag)) \
	FT_DECL_FWD   (FT_Load_Sfnt_Table,                      FT_Error,              (FT_Face face, FT_ULong tag, FT_Long offset, FT_Byte* buffer, FT_ULong* length), (face, tag, offset, buffer, length)) \
	FT_DECL_FWD   (FT_Sfnt_Table_Info,                      FT_Error,              (FT_Face face, FT_UInt table_index, FT_ULong* tag, FT_ULong* length), (face, table_index, tag, length)) \
	FT_DECL_FWD   (FT_Get_CMap_Language_ID,                 FT_ULong,              (FT_CharMap charmap), (charmap)) \
	FT_DECL_FWD   (FT_Get_CMap_Format,                      FT_Long,               (FT_CharMap charmap), (charmap)) \
	FT_DECL_FWD_NR(FT_GlyphSlot_Embolden,                   void,                  (FT_GlyphSlot slot), (slot)) \
	FT_DECL_FWD_NR(FT_GlyphSlot_Oblique,                    void,                  (FT_GlyphSlot slot), (slot)) \
	FT_DECL_FWD_NR(FT_Stroker_ExportBorder,                 void,                  (FT_Stroker stroker, FT_StrokerBorder border, FT_Outline* outline), (stroker, border, outline)) \
	FT_DECL_FWD_NR(FT_Stroker_Export,                       void,                  (FT_Stroker stroker, FT_Outline* outline), (stroker, outline)) \
	FT_DECL_FWD_NR(FT_Stroker_Done,                         void,                  (FT_Stroker stroker), (stroker)) \
	FT_DECL_FWD_NR(FT_Stroker_Set,                          void,                  (FT_Stroker stroker, FT_Fixed radius, FT_Stroker_LineCap line_cap, FT_Stroker_LineJoin line_join, FT_Fixed miter_limit), (stroker, radius, line_cap, line_join, miter_limit)) \
	FT_DECL_FWD_NR(FT_Stroker_Rewind,                       void,                  (FT_Stroker stroker), (stroker)) \
	FT_DECL_FWD_NR(FT_Outline_Get_CBox,                     void,                  (const FT_Outline* outline, FT_BBox* acbox), (outline, acbox)) \
	FT_DECL_FWD_NR(FT_Outline_Translate,                    void,                  (const FT_Outline* outline, FT_Pos xOffset, FT_Pos yOffset), (outline, xOffset, yOffset)) \
	FT_DECL_FWD_NR(FT_Set_Default_Properties,               void,                  (FT_Library library), (library)) \
	FT_DECL_FWD_NR(FT_Set_Debug_Hook,                       void,                  (FT_Library library, FT_UInt hook_index, FT_DebugHook_Func debug_hook), (library, hook_index, debug_hook)) \
	FT_DECL_FWD_NR(FT_Add_Default_Modules,                  void,                  (FT_Library library), (library)) \
	FT_DECL_FWD_NR(FT_OpenType_Free,                        void,                  (FT_Face face, FT_Bytes table), (face, table)) \
	FT_DECL_FWD_NR(FT_List_Add,                             void,                  (FT_List list, FT_ListNode node), (list, node)) \
	FT_DECL_FWD_NR(FT_List_Insert,                          void,                  (FT_List list, FT_ListNode node), (list, node)) \
	FT_DECL_FWD_NR(FT_List_Remove,                          void,                  (FT_List list, FT_ListNode node), (list, node)) \
	FT_DECL_FWD_NR(FT_List_Up,                              void,                  (FT_List list, FT_ListNode node), (list, node)) \
	FT_DECL_FWD_NR(FT_List_Finalize,                        void,                  (FT_List list, FT_List_Destructor destroy, FT_Memory memory, void* user), (list, destroy, memory, user)) \
	FT_DECL_FWD_NR(FT_TrueTypeGX_Free,                      void,                  (FT_Face face, FT_Bytes table), (face, table)) \
	FT_DECL_FWD_NR(FT_ClassicKern_Free,                     void,                  (FT_Face face, FT_Bytes table), (face, table)) \
    FT_DECL_FWD_NR(FTC_Node_Unref,                          void,                  (FTC_Node node, FTC_Manager manager), (node, manager)) \
	FT_DECL_FWD_NR(FTC_Manager_RemoveFaceID,                void,                  (FTC_Manager manager, FTC_FaceID face_id), (manager, face_id)) \
    FT_DECL_FWD_NR(FT_Glyph_Get_CBox,                       void,                  (FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox* acbox), (glyph, bbox_mode, acbox)) \
	FT_DECL_FWD_NR(FT_Done_Glyph,                           void,                  (FT_Glyph glyph), (glyph)) \
	FT_DECL_FWD_NR(FT_Matrix_Multiply,                      void,                  (const FT_Matrix* a, FT_Matrix* b), (a, b)) \
	FT_DECL_FWD_NR(FTC_Manager_Reset,                       void,                  (FTC_Manager manager), (manager)) \
	FT_DECL_FWD_NR(FTC_Manager_Done,                        void,                  (FTC_Manager manager), (manager)) \
    FT_DECL_FWD_NR(FT_Bitmap_Init,                          void,                  (FT_Bitmap* abitmap), (abitmap)) \
	FT_DECL_FWD_NR(FT_Bitmap_New,                           void,                  (FT_Bitmap* abitmap), (abitmap)) \
    FT_DECL_FWD_NR(FT_Set_Transform,                        void,                  (FT_Face face, FT_Matrix* matrix, FT_Vector* delta), (face, matrix, delta)) \
	FT_DECL_FWD_NR(FT_Vector_Transform,                     void,                  (FT_Vector* vec, const FT_Matrix* matrix), (vec, matrix)) \
	FT_DECL_FWD_NR(FT_Library_Version,                      void,                  (FT_Library library, FT_Int* amajor, FT_Int* aminor, FT_Int* apatch), (library, amajor, aminor, apatch)) \
	FT_DECL_FWD_NR(FT_Outline_Transform,                    void,                  (const FT_Outline* outline, const FT_Matrix* matrix), (outline, matrix)) \
	FT_DECL_FWD_NR(FT_Outline_Reverse,                      void,                  (FT_Outline* outline), (outline)) \
	FT_DECL_FWD_NR(FT_Vector_Unit,                          void,                  (FT_Vector* vec, FT_Angle angle), (vec, angle)) \
	FT_DECL_FWD_NR(FT_Vector_Rotate,                        void,                  (FT_Vector* vec, FT_Angle angle), (vec, angle)) \
	FT_DECL_FWD_NR(FT_Vector_Polarize,                      void,                  (FT_Vector* vec, FT_Fixed* length, FT_Angle* angle), (vec, length, angle)) \
	FT_DECL_FWD_NR(FT_Vector_From_Polar,                    void,                  (FT_Vector* vec, FT_Fixed length, FT_Angle angle), (vec, length, angle))

#endif /* __FREETYPE_BRIDGE_H__ */