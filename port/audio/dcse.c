/* Dreamcast common sound effects in place of the PS2's (see dcse.h). */
#include "dcse.h"
#include "hdbank.h"
#include "../platform/fs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dcse_map.h"

#define NMAP (int)(sizeof DCSE_MAP / sizeof DCSE_MAP[0])
#define NBANK (int)(sizeof DCSE_BANKS / sizeof DCSE_BANKS[0])

static struct {
    int16_t *pcm[NMAP]; /* decoded Dreamcast sample per map row (shared rows point at one copy) */
    int owner[NMAP];    /* this row allocated pcm[] */
    int n;              /* rows available */
    int last;           /* dcse_last_applied() */
} D;

static uint32_t fnv1a(const uint8_t *p, size_t n)
{
    uint32_t h = 0x811C9DC5u;
    while (n--) h = (h ^ *p++) * 0x01000193u;
    return h;
}
static uint32_t le32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

/* Yamaha 4-bit ADPCM, low nibble first, as the AICA decodes it (flycast
 * core/hw/aica/sgc_if.cpp DecodeADPCM): the step is applied to the magnitude
 * and then signed, which matters for the rounding. */
static void aica_adpcm(const uint8_t *in, int16_t *out, int n)
{
    static const int qs[8] = { 0xE6, 0xE6, 0xE6, 0xE6, 0x133, 0x199, 0x200, 0x266 };
    int s = 0, q = 127;
    for (int i = 0; i < n; i++) {
        int nib = (in[i >> 1] >> ((i & 1) * 4)) & 15;
        int m = (q * (2 * (nib & 7) + 1)) >> 3;
        if (m > 0x7FFF) m = 0x7FFF;
        s += nib & 8 ? -m : m;
        s = s < -32768 ? -32768 : s > 32767 ? 32767 : s;
        q = (q * qs[nib & 7]) >> 8;
        q = q < 127 ? 127 : q > 24576 ? 24576 : q;
        out[i] = (int16_t)s;
    }
}

void dcse_clear(void)
{
    for (int i = 0; i < NMAP; i++)
        if (D.owner[i]) free(D.pcm[i]);
    memset(D.pcm, 0, sizeof D.pcm);
    memset(D.owner, 0, sizeof D.owner);
    D.n = 0;
}

int dcse_load(const uint8_t *d, size_t size)
{
    dcse_clear();
    if (!d || size != DCSE_SE_COMN_SIZE || memcmp(d, "DTPK", 4) || fnv1a(d, size) != DCSE_SE_COMN_FNV) return -1;
    uint32_t tab = le32(d + 0x3C);
    if (tab + 4 > size) return -1;
    uint32_t nsmp = le32(d + tab) + 1;
    for (int r = 0; r < NMAP; r++) {
        int k = DCSE_MAP[r].dc;
        if ((uint32_t)k >= nsmp || tab + 4 + 16u * (k + 1) > size) continue;
        const uint8_t *e = d + tab + 4 + 16 * k;
        uint32_t loc = le32(e), bytes = le32(e + 12), off = loc & 0x7FFFFF;
        int adpcm = (loc & 0x1000000) != 0;
        uint32_t len = adpcm ? bytes * 2 : bytes / 2;
        if (off + (uint64_t)bytes > size || len != DCSE_MAP[r].dc_len || le32(e + 8)) continue;
        for (int j = 0; j < r; j++) /* the same Dreamcast sample serves both banks */
            if (D.pcm[j] && DCSE_MAP[j].dc == k) { D.pcm[r] = D.pcm[j]; break; }
        if (!D.pcm[r]) {
            int16_t *p = (int16_t *)malloc(sizeof(int16_t) * len);
            if (!p) continue;
            if (adpcm) aica_adpcm(d + off, p, (int)len);
            else for (uint32_t i = 0; i < len; i++) p[i] = (int16_t)(d[off + 2 * i] | d[off + 2 * i + 1] << 8);
            D.pcm[r] = p;
            D.owner[r] = 1;
        }
        D.n++;
    }
    return D.n;
}

int dcse_loaded(void) { return D.n; }

int dcse_last_applied(void) { return D.last; }

int dcse_apply(HdBank *b)
{
    D.last = 0;
    if (!D.n || !b || !b->bd || !b->vag) return 0;
    int afs01 = -1;
    for (int i = 0; i < NBANK; i++)
        if (b->bd_size == DCSE_BANKS[i].bd_size && fnv1a(b->bd, b->bd_size) == DCSE_BANKS[i].bd_fnv) {
            afs01 = DCSE_BANKS[i].afs01;
            break;
        }
    if (afs01 < 0) return 0;
    int done = 0;
    for (int r = 0; r < NMAP; r++) {
        if (DCSE_MAP[r].afs01 != afs01 || !D.pcm[r] || DCSE_MAP[r].vag >= b->nvag) continue;
        VagPcm *v = &b->vag[DCSE_MAP[r].vag];
        if (!v->pcm || v->looped || (uint32_t)v->first_len != DCSE_MAP[r].ps2_len || v->rate != DCSE_MAP[r].ps2_hz)
            continue;
        /* The PS2 samples open with a silent block (28 samples, 3.5 ms at
         * 8 kHz) that the Dreamcast ones lack: keep the PS2 onset time. */
        int lead = 0, dlead = 0, n = (int)DCSE_MAP[r].dc_len;
        while (lead < v->first_len && !v->pcm[lead]) lead++;
        while (dlead < n && !D.pcm[r][dlead]) dlead++;
        int pad = (int)((int64_t)lead * DCSE_MAP[r].dc_hz / DCSE_MAP[r].ps2_hz) - dlead;
        if (pad < 0 || pad > n / 4) pad = 0;
        int16_t *p = (int16_t *)calloc((size_t)(pad + n), sizeof(int16_t));
        if (!p) continue;
        memcpy(p + pad, D.pcm[r], sizeof(int16_t) * n);
        free(v->pcm);
        v->pcm = p;
        v->len = v->first_len = pad + n;
        v->loop_start = 0;
        v->rate = DCSE_MAP[r].dc_hz;
        done++;
    }
    return D.last = done;
}

uint8_t *dcse_read_disc(const char *path, size_t *size)
{
    FsSource s;
    Iso iso;
    uint8_t magic[4] = { 0 };
    FILE *f = path ? fopen(path, "rb") : NULL;
    if (!f) return NULL;
    if (fread(magic, 1, 4, f) == 4 && !memcmp(magic, "DTPK", 4)) { /* SE_COMN.BIN itself */
        fseek(f, 0, SEEK_END);
        long n = ftell(f);
        uint8_t *d = n > 0 && n < (64 << 20) ? (uint8_t *)malloc((size_t)n) : NULL;
        fseek(f, 0, SEEK_SET);
        if (d && fread(d, 1, (size_t)n, f) != (size_t)n) { free(d); d = NULL; }
        fclose(f);
        if (d) *size = (size_t)n;
        return d;
    }
    fclose(f);
    if (fs_source_open_gd(&s, path)) return NULL;
    uint8_t *d = iso_open(&iso, s) ? NULL : iso_load(&iso, "/SE_COMN.BIN", size);
    iso_close(&iso);
    return d;
}
