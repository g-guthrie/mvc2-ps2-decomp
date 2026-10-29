#include "vag.h"
#include <stdlib.h>
#include <string.h>

static const int F[5][2] = { { 0, 0 }, { 60, 0 }, { 115, -52 }, { 98, -55 }, { 122, -60 } };

static void block(const uint8_t *p, int32_t *h1, int32_t *h2, int16_t *dst)
{
    int sh = p[0] & 0xF, pr = p[0] >> 4;
    int f0 = pr < 5 ? F[pr][0] : 0, f1 = pr < 5 ? F[pr][1] : 0;
    for (int k = 0; k < 28; k++) {
        int b = p[2 + (k >> 1)];
        int n = (k & 1) ? (b >> 4) : (b & 0xF);
        int32_t s = (int32_t)(int16_t)(uint16_t)(n << 12);
        s = (s >> sh) + ((*h1 * f0 + *h2 * f1) >> 6);
        if (s < -32768) s = -32768;
        if (s > 32767) s = 32767;
        *h2 = *h1;
        *h1 = s;
        dst[k] = (int16_t)s;
    }
}

int vag_decode(const uint8_t *bd, size_t limit, uint32_t off, uint32_t rate, VagPcm *out)
{
    memset(out, 0, sizeof *out);
    out->rate = rate;
    if (off >= limit) return -1;
    /* pass 1: count blocks up to the end flag */
    size_t nblk = 0, loop_blk = (size_t)-1;
    int looped = 0;
    for (size_t p = off; p + 16 <= limit; p += 16) {
        uint8_t fl = bd[p + 1];
        if ((fl & 4) && loop_blk == (size_t)-1) loop_blk = nblk;
        nblk++;
        if (fl & 1) { looped = (fl & 2) != 0; break; }
    }
    if (!nblk) return -1;
    if (looped && loop_blk == (size_t)-1) loop_blk = 0;
    size_t extra = looped ? nblk - loop_blk : 0;
    out->pcm = (int16_t *)malloc(sizeof(int16_t) * 28 * (nblk + extra));
    if (!out->pcm) return -1;
    int32_t h1 = 0, h2 = 0;
    for (size_t b = 0; b < nblk; b++) block(bd + off + 16 * b, &h1, &h2, out->pcm + 28 * b);
    out->first_len = (int)(28 * nblk);
    out->len = out->first_len;
    if (looped) {
        /* second pass over the loop with the carried history = steady-state loop body */
        for (size_t b = loop_blk; b < nblk; b++)
            block(bd + off + 16 * b, &h1, &h2, out->pcm + out->len + 28 * (b - loop_blk));
        out->loop_start = out->first_len;
        out->len += (int)(28 * extra);
        out->looped = 1;
    }
    return 0;
}

void vag_free(VagPcm *v)
{
    free(v->pcm);
    memset(v, 0, sizeof *v);
}
