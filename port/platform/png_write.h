#ifndef PORT_PNG_WRITE_H
#define PORT_PNG_WRITE_H
#include <stdint.h>
/* Minimal RGBA8 PNG writer (stored deflate blocks, no zlib dependency). 0 = ok. */
int png_write_rgba(const char *path, int w, int h, const uint8_t *rgba);
#endif
