/* Raw DEFLATE + CRC-32 (port/host/inflate.c). */
#ifndef PORT_HOST_INFLATE_H
#define PORT_HOST_INFLATE_H
#include <stddef.h>
#include <stdint.h>
/* inflate a raw deflate stream; returns the output length or -1 */
long host_inflate(uint8_t *out, size_t out_n, const uint8_t *in, size_t in_n);
uint32_t host_crc32(uint32_t crc, const uint8_t *p, size_t n);
#endif
