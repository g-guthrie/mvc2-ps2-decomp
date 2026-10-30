/*
 * Minimal raw-DEFLATE decoder (RFC 1951) and CRC-32 for the arcade-accuracy
 * option (arcade.c): the user's own MAME zip is read at run time, so the
 * port needs to inflate two of its members.  No zlib dependency (the web
 * build has no zlib port); stored, fixed and dynamic Huffman blocks.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "inflate.h"

typedef struct {
    const uint8_t *in;
    size_t in_n, in_pos;
    uint32_t bitbuf;
    int bitcnt;
    uint8_t *out;
    size_t out_n, out_pos;
    int err;
} St;

typedef struct {
    uint16_t count[16];
    uint16_t sym[320];
} Huff;

static int bits(St *s, int need)
{
    uint32_t v = s->bitbuf;
    while (s->bitcnt < need) {
        if (s->in_pos >= s->in_n) {
            s->err = 1;
            return 0;
        }
        v |= (uint32_t)s->in[s->in_pos++] << s->bitcnt;
        s->bitcnt += 8;
    }
    s->bitbuf = v >> need;
    s->bitcnt -= need;
    return (int)(v & ((1u << need) - 1));
}

static int build(Huff *h, const uint8_t *len, int n)
{
    uint16_t offs[16];
    int i, left = 1;
    memset(h->count, 0, sizeof h->count);
    for (i = 0; i < n; i++)
        h->count[len[i]]++;
    if (h->count[0] == n)
        return 0;
    for (i = 1; i < 16; i++) {
        left <<= 1;
        left -= h->count[i];
        if (left < 0)
            return -1;
    }
    offs[1] = 0;
    for (i = 1; i < 15; i++)
        offs[i + 1] = offs[i] + h->count[i];
    for (i = 0; i < n; i++)
        if (len[i])
            h->sym[offs[len[i]]++] = (uint16_t)i;
    return left;
}

static int decode(St *s, const Huff *h)
{
    int code = 0, first = 0, index = 0, len;
    for (len = 1; len < 16; len++) {
        int count;
        code |= bits(s, 1);
        if (s->err)
            return -1;
        count = h->count[len];
        if (code - count < first)
            return h->sym[index + (code - first)];
        index += count;
        first += count;
        first <<= 1;
        code <<= 1;
    }
    s->err = 1;
    return -1;
}

static const uint16_t LBASE[29] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
                                   35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
static const uint8_t LEXT[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
                                 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
static const uint16_t DBASE[30] = {1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
                                   257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
                                   8193, 12289, 16385, 24577};
static const uint8_t DEXT[30] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
                                 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

static int codes(St *s, const Huff *lc, const Huff *dc)
{
    for (;;) {
        int sym = decode(s, lc);
        if (sym < 0)
            return -1;
        if (sym < 256) {
            if (s->out_pos >= s->out_n)
                return -1;
            s->out[s->out_pos++] = (uint8_t)sym;
        } else if (sym == 256) {
            return 0;
        } else {
            int len, dist;
            sym -= 257;
            if (sym >= 29)
                return -1;
            len = LBASE[sym] + bits(s, LEXT[sym]);
            sym = decode(s, dc);
            if (sym < 0 || sym >= 30)
                return -1;
            dist = DBASE[sym] + bits(s, DEXT[sym]);
            if (s->err || (size_t)dist > s->out_pos || s->out_pos + (size_t)len > s->out_n)
                return -1;
            while (len--) {
                s->out[s->out_pos] = s->out[s->out_pos - (size_t)dist];
                s->out_pos++;
            }
        }
    }
}

static int fixed(St *s)
{
    static Huff lc, dc;
    static int init;
    if (!init) {
        uint8_t l[288];
        int i;
        for (i = 0; i < 144; i++) l[i] = 8;
        for (; i < 256; i++) l[i] = 9;
        for (; i < 280; i++) l[i] = 7;
        for (; i < 288; i++) l[i] = 8;
        build(&lc, l, 288);
        for (i = 0; i < 30; i++) l[i] = 5;
        build(&dc, l, 30);
        init = 1;
    }
    return codes(s, &lc, &dc);
}

static int dynamic(St *s)
{
    static const uint8_t ORD[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
    uint8_t l[320];
    Huff lc, dc;
    int nlen = bits(s, 5) + 257, ndist = bits(s, 5) + 1, ncode = bits(s, 4) + 4, i, err;
    if (s->err || nlen > 286 || ndist > 30)
        return -1;
    for (i = 0; i < ncode; i++)
        l[ORD[i]] = (uint8_t)bits(s, 3);
    for (; i < 19; i++)
        l[ORD[i]] = 0;
    if (build(&lc, l, 19) != 0)
        return -1;
    for (i = 0; i < nlen + ndist;) {
        int sym = decode(s, &lc), rep, v = 0;
        if (sym < 0)
            return -1;
        if (sym < 16) {
            l[i++] = (uint8_t)sym;
            continue;
        }
        if (sym == 16) {
            if (i == 0)
                return -1;
            v = l[i - 1];
            rep = 3 + bits(s, 2);
        } else if (sym == 17) {
            rep = 3 + bits(s, 3);
        } else {
            rep = 11 + bits(s, 7);
        }
        if (i + rep > nlen + ndist)
            return -1;
        while (rep--)
            l[i++] = (uint8_t)v;
    }
    if (l[256] == 0)
        return -1;
    err = build(&lc, l, nlen);
    if (err < 0 || (err > 0 && nlen - lc.count[0] != 1))
        return -1;
    err = build(&dc, l + nlen, ndist);
    if (err < 0 || (err > 0 && ndist - dc.count[0] != 1))
        return -1;
    return codes(s, &lc, &dc);
}

long host_inflate(uint8_t *out, size_t out_n, const uint8_t *in, size_t in_n)
{
    St s;
    int last;
    memset(&s, 0, sizeof s);
    s.in = in;
    s.in_n = in_n;
    s.out = out;
    s.out_n = out_n;
    do {
        int type, r;
        last = bits(&s, 1);
        type = bits(&s, 2);
        if (s.err)
            return -1;
        if (type == 0) {
            unsigned len, nlen;
            s.bitbuf = 0;
            s.bitcnt = 0;
            if (s.in_pos + 4 > s.in_n)
                return -1;
            len = s.in[s.in_pos] | s.in[s.in_pos + 1] << 8;
            nlen = s.in[s.in_pos + 2] | s.in[s.in_pos + 3] << 8;
            s.in_pos += 4;
            if (len != (~nlen & 0xFFFFu) || s.in_pos + len > s.in_n || s.out_pos + len > s.out_n)
                return -1;
            memcpy(s.out + s.out_pos, s.in + s.in_pos, len);
            s.in_pos += len;
            s.out_pos += len;
            r = 0;
        } else if (type == 1) {
            r = fixed(&s);
        } else if (type == 2) {
            r = dynamic(&s);
        } else {
            return -1;
        }
        if (r != 0 || s.err)
            return -1;
    } while (!last);
    return (long)s.out_pos;
}

uint32_t host_crc32(uint32_t crc, const uint8_t *p, size_t n)
{
    static uint32_t tab[256];
    size_t i;
    if (!tab[1]) {
        uint32_t k, c;
        int j;
        for (k = 0; k < 256; k++) {
            c = k;
            for (j = 0; j < 8; j++)
                c = c & 1 ? 0xEDB88320u ^ (c >> 1) : c >> 1;
            tab[k] = c;
        }
    }
    crc = ~crc;
    for (i = 0; i < n; i++)
        crc = tab[(crc ^ p[i]) & 0xFF] ^ (crc >> 8);
    return ~crc;
}
