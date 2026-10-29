#include "adx.h"
#include <math.h>
#include <string.h>

static uint32_t be32(const uint8_t *p) { return (uint32_t)p[0] << 24 | (uint32_t)p[1] << 16 | (uint32_t)p[2] << 8 | p[3]; }
static uint16_t be16(const uint8_t *p) { return (uint16_t)(p[0] << 8 | p[1]); }

int adx_parse_header(const uint8_t *d, size_t n, AdxHeader *h)
{
    memset(h, 0, sizeof *h);
    if (n < 0x18 || d[0] != 0x80 || d[1] != 0x00) return -1;
    uint32_t cofs = be16(d + 2);
    h->data_off = cofs + 4;
    h->enc = d[4];
    h->block = d[5];
    h->bits = d[6];
    h->channels = d[7];
    h->rate = be32(d + 8);
    h->total = be32(d + 12);
    h->highpass = be16(d + 16);
    h->version = d[18];
    h->flags = d[19];
    if (h->enc != 3 || h->block != 18 || h->bits != 4 || h->channels < 1 || h->channels > 2 || !h->rate)
        return -2;
    /* coefficients exactly as adx.py: floor(c*8192), floor(-c*c*4096) */
    double a = sqrt(2.0) - cos(2.0 * M_PI * h->highpass / h->rate);
    double b = sqrt(2.0) - 1.0;
    double c = (a - sqrt((a + b) * (a - b))) / b;
    h->c1 = (int)floor(c * 8192);
    h->c2 = (int)floor(-c * c * 4096);
    uint32_t lo = h->version == 3 ? 0x18 : 0x24;
    if (h->version == 3 && n >= 0x18) h->loop_align = be16(d + 0x14);
    if (lo + 0x14 <= h->data_off && lo + 0x14 <= n) {
        if (be32(d + lo) == 1) {
            h->has_loop = 1;
            h->loop_start = be32(d + lo + 4);
            h->loop_start_byte = be32(d + lo + 8);
            h->loop_end = be32(d + lo + 12);
            h->loop_end_byte = be32(d + lo + 16);
        }
    }
    return 0;
}

static size_t mem_read(void *ctx, uint64_t off, void *dst, size_t n)
{
    AdxStream *s = (AdxStream *)ctx;
    if (off >= s->size) return 0;
    if (n > s->size - off) n = (size_t)(s->size - off);
    memcpy(dst, s->mem + off, n);
    return n;
}

static int start(AdxStream *s, int loop)
{
    uint8_t hdr[0x400];
    size_t got = s->read(s->ctx, 0, hdr, sizeof hdr);
    if (adx_parse_header(hdr, got, &s->h)) return -1;
    s->loop = loop && s->h.has_loop && s->h.loop_end > s->h.loop_start && s->h.loop_end <= s->h.total;
    s->cache_len = 0;
    s->cache_off = 0;
    memset(s->hist, 0, sizeof s->hist);
    s->frame_len = s->frame_pos = 0;
    s->next_frame = 0;
    s->pos = 0;
    s->loops = 0;
    s->ended = 0;
    s->saved_ok = 0;
    s->loop_mode = ADX_LOOP_RESTORE;
    return 0;
}

int adx_open_mem(AdxStream *s, const uint8_t *data, size_t size, int loop)
{
    s->mem = data;
    s->size = size;
    s->read = mem_read;
    s->ctx = s;
    return start(s, loop);
}

int adx_open_reader(AdxStream *s, AdxRead read, void *ctx, uint64_t size, int loop)
{
    s->mem = NULL;
    s->size = size;
    s->read = read;
    s->ctx = ctx;
    return start(s, loop);
}

/* bytes [off, off+n) through the cache; NULL if past the end */
static const uint8_t *fetch(AdxStream *s, uint64_t off, size_t n)
{
    if (s->mem) return off + n <= s->size ? s->mem + off : NULL;
    if (off < s->cache_off || off + n > s->cache_off + s->cache_len) {
        s->cache_off = off;
        s->cache_len = s->read(s->ctx, off, s->cache, ADX_CACHE);
        if (s->cache_len < n) return NULL;
    }
    return s->cache + (off - s->cache_off);
}

/* decode frame s->next_frame into s->frame; 0 = ok */
static int decode_frame(AdxStream *s)
{
    const int ch = s->h.channels, bs = s->h.block, spf = (bs - 2) * 2;
    if (s->loop && !s->saved_ok && s->next_frame == s->h.loop_start / (uint32_t)spf) {
        memcpy(s->saved, s->hist, sizeof s->saved);
        s->saved_ok = 1;
    }
    uint64_t off = s->h.data_off + (uint64_t)s->next_frame * bs * ch;
    const uint8_t *f = fetch(s, off, (size_t)bs * ch);
    if (!f) return -1;
    for (int c = 0; c < ch; c++) {
        const uint8_t *p = f + bs * c;
        int32_t scale = be16(p);
        int32_t h1 = s->hist[c][0], h2 = s->hist[c][1];
        for (int k = 0; k < spf; k++) {
            int b = p[2 + (k >> 1)];
            int nib = (k & 1) ? (b & 0xF) : (b >> 4);
            if (nib & 8) nib -= 16;
            /* >> on a negative int is an arithmetic shift on every target we
             * build for (GCC/Clang/Emscripten), matching Python's floor shift */
            int32_t v = nib * scale + ((s->h.c1 * h1 + s->h.c2 * h2) >> 12);
            if (v < -32768) v = -32768;
            if (v > 32767) v = 32767;
            h2 = h1;
            h1 = v;
            s->frame[c][k] = (int16_t)v;
        }
        s->hist[c][0] = h1;
        s->hist[c][1] = h2;
    }
    s->next_frame++;
    s->frame_len = spf;
    return 0;
}

int adx_decode(AdxStream *s, int16_t *out, int frames)
{
    const int ch = s->h.channels, spf = (s->h.block - 2) * 2;
    int done = 0;
    while (done < frames && !s->ended) {
        uint32_t end = s->loop ? s->h.loop_end : s->h.total;
        if (s->pos >= end) {
            if (!s->loop) { s->ended = 1; break; }
            /* loop jump: continue at loopStart, keep the predictor history */
            s->next_frame = s->h.loop_start / spf;
            s->frame_len = 0;
            if (s->loop_mode == ADX_LOOP_RESTORE && s->saved_ok) memcpy(s->hist, s->saved, sizeof s->hist);
            if (decode_frame(s)) { s->ended = 1; break; }
            s->frame_pos = (int)(s->h.loop_start % spf);
            s->pos = s->h.loop_start;
            s->loops++;
            continue;
        }
        if (s->frame_pos >= s->frame_len) {
            if (decode_frame(s)) { s->ended = 1; break; }
            s->frame_pos = 0;
        }
        int n = s->frame_len - s->frame_pos;
        if ((uint32_t)n > end - s->pos) n = (int)(end - s->pos);
        if (n > frames - done) n = frames - done;
        for (int i = 0; i < n; i++)
            for (int c = 0; c < ch; c++)
                out[(done + i) * ch + c] = s->frame[c][s->frame_pos + i];
        s->frame_pos += n;
        s->pos += n;
        done += n;
    }
    return done;
}
