#include "wav.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void w32(FILE *f, uint32_t v) { uint8_t b[4] = { (uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24) }; fwrite(b, 1, 4, f); }
static void w16(FILE *f, uint16_t v) { uint8_t b[2] = { (uint8_t)v, (uint8_t)(v >> 8) }; fwrite(b, 1, 2, f); }

int wav_write16(const char *path, const int16_t *pcm, int frames, int ch, int rate, long ls, long le)
{
    FILE *f = fopen(path, "wb");
    if (!f) return -1;
    uint32_t data = (uint32_t)frames * ch * 2;
    uint32_t smpl = le >= 0 ? 8 + 36 + 24 : 0;
    fwrite("RIFF", 1, 4, f);
    w32(f, 4 + 8 + 16 + smpl + 8 + data);
    fwrite("WAVEfmt ", 1, 8, f);
    w32(f, 16);
    w16(f, 1); w16(f, (uint16_t)ch); w32(f, (uint32_t)rate); w32(f, (uint32_t)rate * ch * 2);
    w16(f, (uint16_t)(ch * 2)); w16(f, 16);
    if (le >= 0) {
        fwrite("smpl", 1, 4, f);
        w32(f, 36 + 24);
        w32(f, 0); w32(f, 0); w32(f, (uint32_t)(1e9 / rate)); w32(f, 60); w32(f, 0);
        w32(f, 0); w32(f, 0); w32(f, 1); w32(f, 0);
        w32(f, 0); w32(f, 0); w32(f, (uint32_t)ls); w32(f, (uint32_t)le); w32(f, 0); w32(f, 0);
    }
    fwrite("data", 1, 4, f);
    w32(f, data);
    for (long i = 0; i < (long)frames * ch; i++) w16(f, (uint16_t)pcm[i]);
    fclose(f);
    return 0;
}

int wav_write_float_stereo(const char *path, const float *pcm, int frames, int rate)
{
    int16_t *t = (int16_t *)malloc(sizeof(int16_t) * 2 * (size_t)frames);
    if (!t) return -1;
    for (long i = 0; i < 2L * frames; i++) {
        long v = lrintf(pcm[i] * 32768.0f);
        t[i] = (int16_t)(v > 32767 ? 32767 : v < -32768 ? -32768 : v);
    }
    int r = wav_write16(path, t, frames, 2, rate, 0, -1);
    free(t);
    return r;
}

int16_t *wav_read16(const char *path, int *frames, int *ch, int *rate)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    uint8_t h[12];
    if (fread(h, 1, 12, f) != 12 || memcmp(h, "RIFF", 4) || memcmp(h + 8, "WAVE", 4)) { fclose(f); return NULL; }
    int16_t *out = NULL;
    *ch = 0;
    for (;;) {
        uint8_t c[8];
        if (fread(c, 1, 8, f) != 8) break;
        uint32_t n = c[4] | c[5] << 8 | c[6] << 16 | (uint32_t)c[7] << 24;
        if (!memcmp(c, "fmt ", 4)) {
            uint8_t fm[16];
            if (n < 16 || fread(fm, 1, 16, f) != 16) break;
            *ch = fm[2] | fm[3] << 8;
            *rate = (int)(fm[4] | fm[5] << 8 | fm[6] << 16 | (uint32_t)fm[7] << 24);
            fseek(f, (long)(n - 16 + (n & 1)), SEEK_CUR);
        } else if (!memcmp(c, "data", 4) && *ch) {
            out = (int16_t *)malloc(n ? n : 2);
            size_t got = fread(out, 1, n, f);
            *frames = (int)(got / 2 / *ch);
            /* host is little-endian on every target we build for */
            break;
        } else {
            fseek(f, (long)(n + (n & 1)), SEEK_CUR);
        }
    }
    fclose(f);
    return out;
}
