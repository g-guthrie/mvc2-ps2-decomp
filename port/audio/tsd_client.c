#include "tsd_client.h"
#include <string.h>

/* D_00633E30: 64 x {u32 w0; u32 w1}; w0 < 0 = free. w1 holds the s8/s8/s16
 * parameters at bytes 4/5/6 (little-endian, as on the EE). */
typedef struct Entry { int32_t w0; uint32_t w1; } Entry;

static Entry Q[64];
static int tail;          /* D_00633E20: next free */
static int head;          /* D_00633E28: next to send */
static uint8_t buf[0x200];/* D_00634100 */
static int cursor;        /* D_00633E18 */
static TsdcSink S;
static int ready;         /* D_004C2BB4 */

static uint8_t b4(const Entry *e) { return (uint8_t)e->w1; }
static uint8_t b5(const Entry *e) { return (uint8_t)(e->w1 >> 8); }
static uint16_t h6(const Entry *e) { return (uint16_t)(e->w1 >> 16); }
static uint32_t pack(int a1, int a2, int a3) { return (uint8_t)a1 | (uint32_t)(uint8_t)a2 << 8 | (uint32_t)(uint16_t)a3 << 16; }

void tsdc_set_sink(const TsdcSink *sink) { if (sink) S = *sink; else memset(&S, 0, sizeof S); }

void tsdc_reset(void)                                   /* 0x422CC0 */
{
    cursor = 0;
    head = 0;
    tail = 0;
    for (int i = 0; i < 64; i++) Q[i].w0 = -1;
}

int tsdc_init(void)                                     /* 0x422DB0 (+ 0x419F70 tail) */
{
    if (ready) return 0;
    tsdc_reset();
    ready = 1;
    return 0;
}

static int put(uint32_t w0, uint32_t w1)
{
    Entry *e = &Q[tail];
    if (e->w0 >= 0) return -1;
    e->w0 = (int32_t)w0;
    e->w1 = w1;
    tail = (tail + 1) % 64;
    return 0;
}

int tsdc_play(uint32_t id, int a1, int a2, int a3)      /* 0x422EA0 */
{
    int fl = ((int8_t)a1 >= 0) | ((int8_t)a2 >= 0) << 1 | ((int16_t)a3 >= 0) << 2;
    return put((uint32_t)fl << 24 | (id & 0xFFFFFF), pack(a1, a2, a3));
}

int tsdc_stop(uint32_t a)                               /* 0x422FB0 */
{
    const uint32_t mask = 0x7F7F7F, am = a & mask;
    int i = head;
    while (Q[i].w0 >= 0) {
        uint32_t v = (uint32_t)Q[i].w0;
        if ((v & mask) == am) {
            if ((int32_t)v >> 24 == 8) return 0;  /* a stop is already queued */
            Q[i].w0 = 0x7F000000;                 /* cancel the pending play/change */
        }
        i = (i + 1) % 64;
        if (i == tail) break;
    }
    if (Q[tail].w0 >= 0) return -1;
    Q[tail].w0 = (int32_t)((a & 0xFFFFFF) | 0x08000000);
    tail = (tail + 1) % 64;
    return 0;
}

int tsdc_change(uint32_t a, int b, int c, int d)        /* 0x4230B0 */
{
    if (Q[tail].w0 >= 0) return -1;
    int fl = ((int8_t)b >= 0) | ((int8_t)c >= 0) << 1 | ((int16_t)d >= 0) << 2 | 8;
    if (fl == 8) return 1;
    return put((uint32_t)fl << 24 | (a & 0xFFFFFF), pack(b, c, d));
}

int tsdc_stop_all_tq(void) { return put(0x28000000u, 0); }                               /* 0x4231D0 */
int tsdc_master_volume(uint32_t v) { return put(0x29000000u | ((v & 0xFFFF) << 8), 0); } /* 0x423240 */

int tsdc_cmd77(uint32_t a0, uint32_t a1, uint32_t a2)    /* 0x4232C0 */
{
    if (Q[tail].w0 >= 0) return -1;
    if (a1 > 0x18 || a2 > 0x18) return -2;
    a0 = (a0 + 0x3F) >> 6;
    return put(((((a0 & 0xFFFF) << 8) | a1) & 0xFFFFFF) | 0x77000000u, a2 & 0xFF);
}

static void put4f(int i, uint32_t lo, uint32_t hi)       /* 0x423370 PUT_ENTRY */
{
    hi = (hi + 0xF) & ~0xFu;
    Q[i].w0 = (int32_t)(((hi >> 4) & 0xFFFFFF) | 0x4F000000u);
    Q[i].w1 = lo | (hi >> 20);
}

int tsdc_load_bank(uint32_t a0, uint32_t a1, int32_t a2, uint32_t a3, int32_t t0, uint32_t t1, int32_t t2) /* 0x423480 */
{
    if (a0 > 0xFFF) return -2;
    if (((a1 | a3 | t1) & 0xF) != 0) return -3;
    if (a2 > 0x1FFFF0 || t0 > 0x1FFFF0 || t2 > 0x1FFFF0) return -4;
    for (int n = 0, i = tail; n < 4; n++, i = (i + 1) % 64)
        if (Q[i].w0 >= 0) return -1;
    Q[tail].w0 = (int32_t)(((a0 << 8) & 0xFFFFFF) | 0x4D000000u);
    int i = (tail + 1) % 64;
    put4f(i, a1, (uint32_t)a2); i = (i + 1) % 64;
    put4f(i, a3, (uint32_t)t0); i = (i + 1) % 64;
    put4f(i, t1, (uint32_t)t2);
    tail = (i + 1) % 64;
    return 0;
}

int tsdc_unload_bank(uint32_t v) { return put(0x48000000u | ((v & 0xFF) << 16), 0); }   /* 0x4235D0 */
int tsdc_stop_all(void) { return put(0x40000000u, 0); }                                 /* 0x423650 */
int tsdc_set_stereo(int en) { return put(0x42000000u | (en ? 1u << 16 : 0), 0); }       /* 0x4236C0 */

/* ---- 0x423E30 serializer and its byte writers ---- */
static int wr_tq(uint32_t h, uint8_t f4, uint8_t f5, uint16_t f6) /* 0x4239D0 */
{
    uint32_t fl = h >> 24;
    int len = 4 + (fl & 1) + ((fl >> 1) & 1) + ((fl & 4) ? 2 : 0);
    if (cursor + len >= 0x200) return -1;
    uint8_t *o = buf + cursor;
    *o++ = (uint8_t)(h >> 24); *o++ = (uint8_t)(h >> 16); *o++ = (uint8_t)(h >> 8); *o++ = (uint8_t)h;
    if (fl & 1) *o++ = f4;
    if (fl & 2) *o++ = f5;
    if (fl & 4) { *o++ = (uint8_t)(f6 >> 8); *o++ = (uint8_t)f6; }
    cursor += len;
    *o = 0xFF;
    return 0;
}

static int wr_top(uint32_t v, int n)                     /* 0x423D00 */
{
    if (n > 4 || cursor + n >= 0x200) return -1;
    for (int sh = 24; n > 0; n--, sh -= 8) buf[cursor++] = (uint8_t)(v >> sh);
    buf[cursor] = 0xFF;
    return 0;
}

static int wr_words(const Entry *e)                      /* 0x423AA0 */
{
    if (cursor + 8 >= 0x200) return -1;
    uint32_t v = (uint32_t)e->w0;
    for (int sh = 24; sh >= 0; sh -= 8) buf[cursor++] = (uint8_t)(v >> sh);
    for (int sh = 16; sh >= 0; sh -= 8) buf[cursor++] = (uint8_t)(e->w1 >> sh);
    buf[cursor] = 0xFF;
    return 0;
}

static int wr_n(uint32_t v, int n, uint8_t x0, uint8_t x1, uint8_t x2, uint8_t x3) /* 0x423B70 */
{
    if (n > 8 || cursor + n >= 0x200) return -1;
    int sh = 24;
    for (int c = 4; c > 0 && n > 0; c--, n--, sh -= 8) buf[cursor++] = (uint8_t)(v >> sh);
    if (n-- > 0) buf[cursor++] = x0;
    if (n-- > 0) buf[cursor++] = x1;
    if (n-- > 0) buf[cursor++] = x2;
    if (n > 0) buf[cursor++] = x3;
    buf[cursor] = 0xFF;
    return 0;
}

static int wr_reserve(uint32_t v, int n, int m)          /* 0x423DA0 */
{
    if (n >= m || n > 4 || cursor + m >= 0x200) return -1;
    for (int sh = 24; n > 0; n--, sh -= 8) buf[cursor++] = (uint8_t)(v >> sh);
    return 0;
}

static int serialize(const Entry *e)
{
    uint32_t w = (uint32_t)e->w0;
    int c = (int32_t)w >> 24;
    if (c == 0x7F) return 0; /* cancelled */
    switch (c & 0xF0) {
    case 0x50: case 0x60: return wr_top(w, 2);
    case 0x00: return wr_tq(w, b4(e), b5(e), h6(e));
    case 0x20:
        if (c & 8) return wr_top(w, c == 0x29 ? 3 : 1);
        return wr_top(w, (c == 0x20 || c == 0x22 || c == 0x23 || c == 0x24) ? 3 : 2);
    case 0x30: case 0x70:
        if (c == 0x38 || c == 0x30 || c == 0x31 || c == 0x71 || c == 0x73) return wr_top(w, 2);
        if (c == 0x37 || (c >= 0x39 && c <= 0x3B) || c == 0x3D || c == 0x72 || c == 0x75) return wr_top(w, 3);
        if (c == 0x36 || c == 0x74) return wr_top(w, 4);
        if (c == 0x77 || c == 0x3C || c == 0x3E) return wr_n(w, 5, b4(e), 0, 0, 0);
        if (c == 0x3F) return wr_n(w, 7, b4(e), b5(e), (uint8_t)(e->w1 >> 16), 0);
        if (c == 0x35) return wr_words(e);
        return wr_top(w, 1);
    case 0x40:
        if ((c >= 0x47 && c <= 0x4A) || c == 0x41 || c == 0x42) return wr_top(w, 2);
        if (c == 0x4B) return wr_top(w, 3);
        if (c == 0x45 || c == 0x4C) return wr_top(w, 4);
        if (c == 0x44) return wr_n(w, 6, b4(e), b5(e), 0, 0);
        if (c == 0x4D || c == 0x4E) return wr_reserve(w, 3, 0x15);
        if (c == 0x4F) return wr_n(e->w1, 6, (uint8_t)(w >> 8), (uint8_t)w, 0, 0);
        return wr_top(w, 1);
    default: return 0;
    }
}

int tsdc_flush(int wait)                                 /* 0x423750 */
{
    (void)wait;
    int h = head;
    while (Q[h].w0 >= 0) {
        if (serialize(&Q[h]) < 0) break;
        Q[h].w0 = -1;
        h = (h + 1) % 64;
    }
    head = h;
    if (cursor) {
        int n = (cursor + 16) & -16;
        if (n > (int)sizeof buf) n = sizeof buf;
        if (S.rpc) S.rpc(S.ctx, buf, (size_t)n);
        cursor = 0;
    }
    return 0;
}

int tsdc_status(int fno, int arg)                        /* 0x423990 */
{
    return S.status ? S.status(S.ctx, fno, (uint32_t)arg) : 0;
}

int tsdc_queue_used(void)
{
    int n = 0;
    for (int i = 0; i < 64; i++) n += Q[i].w0 >= 0;
    return n;
}

/* ---- host pointers for cmd 0x4D on 64-bit builds ---- */
#define TOKENS 64
static const void *tok[TOKENS];
static uint32_t tok_size[TOKENS];
static int tok_next;

uint32_t tsdc_addr(const void *p, uint32_t size)
{
    if (!p) return 0;
    int i = tok_next++ % TOKENS;
    tok[i] = p;
    tok_size[i] = size;
    return 0xF0000000u | (uint32_t)i << 4;
}

const void *tsdc_resolve(void *ctx, uint32_t a, uint32_t *size)
{
    (void)ctx;
    if ((a & 0xF0000000u) == 0xF0000000u) {
        int i = (int)((a >> 4) % TOKENS);
        if (size && *size > tok_size[i]) *size = tok_size[i];
        return tok[i];
    }
    return (const void *)(uintptr_t)a; /* 32-bit game build: the EE address is the pointer */
}

int tsdc_load_bank_ptr(uint32_t slot, const void *hd, int32_t hd_size, const void *bd, int32_t bd_size,
                       const void *tq, int32_t tq_size)
{
    /* the protocol rounds sizes up to 16; tokens remember the exact length.
     * Buffers must stay valid until the next tsdc_flush() (the "DMA"). */
    return tsdc_load_bank(slot, tsdc_addr(hd, (uint32_t)hd_size), hd_size, tsdc_addr(bd, (uint32_t)bd_size), bd_size,
                          tsdc_addr(tq, (uint32_t)tq_size), tq_size);
}
