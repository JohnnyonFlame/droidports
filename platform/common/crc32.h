#ifndef __CRC32_H__
#define __CRC32_H__

#include <stdint.h>

uint32_t crc32(uint32_t crc, const void *buf, uint32_t size);

#endif //__CRC32_H__