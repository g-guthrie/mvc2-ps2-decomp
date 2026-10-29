#include "hdbank.h"
#include <stdlib.h>
#include <string.h>

static uint32_t le32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }
static uint16_t le16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }

/* IECS chunk table: +8 size, +0xC maxIndex, +0x10 u32 ofs[maxIndex+1] (rel. to chunk) */
static int chunk(const HdBank *b, uint32_t at, uint32_t *n, const uint8_t **tab)
{
    if (at == 0xFFFFFFFFu || at + 0x10 > b->hd_size) { *n = 0; return -1; }
    uint32_t mx = le32(b->hd + at + 0xC);
    if (at + 0x10 + 4ull * (mx + 1) > b->hd_size) { *n = 0; return -1; }
    *n = mx + 1;
    *tab = b->hd + at + 0x10;
    return 0;
}

static const uint8_t *entry(const HdBank *b, uint32_t at, const uint8_t *tab, uint32_t i, uint32_t need)
{
    uint32_t o = le32(tab + 4 * i);
    if (o == 0xFFFFFFFFu) return NULL;
    if ((uint64_t)at + o + need > b->hd_size) return NULL;
    return b->hd + at + o;
}

int hd_bank_load(HdBank *b, const void *hd, uint32_t hd_size, const void *bd, uint32_t bd_size,
                 const void *tq, uint32_t tq_size, const void *tbl, uint32_t tbl_size)
{
    memset(b, 0, sizeof *b);
    size_t tot = (size_t)hd_size + bd_size + tq_size + tbl_size;
    b->mem = (uint8_t *)malloc(tot ? tot : 1);
    if (!b->mem) return -1;
    uint8_t *p = b->mem;
    memcpy(p, hd, hd_size); b->hd = p; b->hd_size = hd_size; p += hd_size;
    if (bd_size) memcpy(p, bd, bd_size);
    b->bd = p; b->bd_size = bd_size; p += bd_size;
    if (tq_size) memcpy(p, tq, tq_size);
    b->tq = p; b->tq_size = tq_size; p += tq_size;
    if (tbl_size) memcpy(p, tbl, tbl_size);
    b->tbl = p; b->tbl_size = tbl_size;

    if (hd_size < 0x40 || memcmp(b->hd, "IECSsreV", 8) || memcmp(b->hd + 0x10, "IECSdaeH", 8)) {
        hd_bank_free(b);
        return -2;
    }
    uint32_t prog_at = le32(b->hd + 0x24), sset_at = le32(b->hd + 0x28);
    uint32_t smpl_at = le32(b->hd + 0x2C), vagi_at = le32(b->hd + 0x30);
    const uint8_t *tab;
    uint32_t n;

    /* Vagi -> decoded PCM */
    if (!chunk(b, vagi_at, &n, &tab)) {
        b->nvag = (int)n;
        b->vag = (VagPcm *)calloc(n, sizeof(VagPcm));
        for (uint32_t i = 0; i < n; i++) {
            const uint8_t *e = entry(b, vagi_at, tab, i, 8);
            if (!e) continue;
            vag_decode(b->bd, b->bd_size, le32(e), le16(e + 4), &b->vag[i]);
        }
    }
    if (!chunk(b, smpl_at, &n, &tab)) {
        b->nsmpl = (int)n;
        b->smpl = (HdSample *)calloc(n, sizeof(HdSample));
        for (uint32_t i = 0; i < n; i++) {
            const uint8_t *e = entry(b, smpl_at, tab, i, 0x2A);
            HdSample *s = &b->smpl[i];
            if (!e) { s->vag = 0xFFFF; continue; }
            s->vag = le16(e);
            s->vel_lo = e[2] & 0x7F;
            s->vel_hi = e[4] & 0x7F;
            s->base = e[0xB];
            s->detune = (int8_t)e[0xC];
            s->pan = e[0xD];
            s->group = e[0xE];
            s->prio = e[0xF];
            s->vol = e[0x10];
            s->adsr1 = le16(e + 0x12);
            s->adsr2 = le16(e + 0x14);
        }
    }
    if (!chunk(b, sset_at, &n, &tab)) {
        b->nsset = (int)n;
        b->sset = (HdSset *)calloc(n, sizeof(HdSset));
        for (uint32_t i = 0; i < n; i++) {
            const uint8_t *e = entry(b, sset_at, tab, i, 4);
            if (!e) continue;
            HdSset *s = &b->sset[i];
            s->vel_lo = e[1] & 0x7F;
            s->vel_hi = e[2] & 0x7F;
            s->n = e[3];
            if ((size_t)(e + 4 + 2 * s->n - b->hd) > b->hd_size) s->n = 0;
            s->idx = e + 4;
        }
    }
    if (!chunk(b, prog_at, &n, &tab)) {
        b->nprog = (int)n;
        b->prog = (HdProg *)calloc(n, sizeof(HdProg));
        for (uint32_t i = 0; i < n; i++) {
            const uint8_t *e = entry(b, prog_at, tab, i, 0x24);
            if (!e) continue;
            HdProg *p = &b->prog[i];
            uint32_t so = le32(e);
            int ns = e[4], sz = e[5];
            p->vol = e[6];
            p->pan = e[7];
            p->transpose = (int8_t)e[8];
            p->detune = (int8_t)e[9];
            p->kf_pan = (int8_t)e[0xA];
            p->kf_pan_center = e[0xB];
            p->valid = 1;
            if (sz < 20) ns = 0;
            if ((size_t)(e - b->hd) + so + (size_t)ns * sz > b->hd_size) ns = 0;
            p->nsplit = ns;
            p->split = ns ? (HdSplit *)calloc(ns, sizeof(HdSplit)) : NULL;
            for (int k = 0; k < ns; k++) {
                const uint8_t *s = e + so + k * sz;
                HdSplit *d = &p->split[k];
                d->sset = le16(s);
                d->lo = s[2] & 0x7F;
                d->hi = s[4] & 0x7F;
                d->bend_lo = le16(s + 6);
                d->bend_hi = le16(s + 8);
                d->vol = s[0x10];
                d->pan = s[0x11];
                d->transpose = (int8_t)s[0x12];
                d->detune = (int8_t)s[0x13];
            }
        }
    }
    if (b->tq_size >= 0x10) {
        int num = le16(b->tq + 0xE);
        if (0x10 + 4u * num <= b->tq_size) b->tq_num = num;
    }
    return 0;
}

int hd_bank_load_afs01(HdBank *b, const uint8_t *d, size_t size)
{
    uint32_t o[4], s[4];
    if (size < 0x40) return -1;
    for (int i = 0; i < 4; i++) {
        o[i] = le32(d + 8 * i);
        s[i] = le32(d + 8 * i + 4);
        if ((uint64_t)o[i] + s[i] > size) return -1;
    }
    return hd_bank_load(b, d + o[0], s[0], d + o[1], s[1], d + o[2], s[2], d + o[3], s[3]);
}

void hd_bank_free(HdBank *b)
{
    if (b->vag)
        for (int i = 0; i < b->nvag; i++) vag_free(&b->vag[i]);
    if (b->prog)
        for (int i = 0; i < b->nprog; i++) free(b->prog[i].split);
    free(b->vag);
    free(b->prog);
    free(b->sset);
    free(b->smpl);
    free(b->mem);
    memset(b, 0, sizeof *b);
}

int hd_tq_entry(const HdBank *b, int sound, int *prio, uint32_t *ofs)
{
    if (sound < 0 || sound >= b->tq_num) return -1;
    uint32_t w = le32(b->tq + 0x10 + 4 * sound);
    *prio = (int)(w >> 24);
    *ofs = w & 0xFFFF;
    return *ofs < b->tq_size ? 0 : -1;
}
