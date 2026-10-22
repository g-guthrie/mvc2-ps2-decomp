typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x14]; s32 w14; s32 w18; u32 w1C; u32 w20; } C40;
typedef struct { s32 e0; s32 e4; } T8;
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    u8 pad2C[4];
    s32 w30;
    s32 w34;
    s32 w38;
    u8 pad3C[4];
    C40 *w40;
    u8 pad44[0xC];
    u8 b50[0x20];
} OBJ_c;
typedef struct { u32 flags; s32 cnt; u16 *ptr; } SRC_c;

extern T8 D_00478E10[];
extern s32 D_00478DF0[];

void func_003EE9A0(SRC_c *src, OBJ_c *o)
{
    extern void func_003DCD40(void *, s32, s32);
    extern s32 func_003DCFE0(s32, s32);
    s8 buf[0x20];
    s32 total;
    s32 chunk;
    C40 *c;
    s32 i;
    s32 j;
    s32 pos;
    u32 lim;
    s32 prev;
    s32 cur;
    s32 cnt;
    s32 count;
    u16 *p;
    u16 w;
    u16 n;
    u32 sz;
    u32 fl;

    chunk = 0;
    c = o->w40;
    total = 0;
    func_003DCD40(buf, 0, 0x20);
    count = src->cnt;
    prev = -1;
    p = src->ptr;
    cur = 0;
    pos = 0;
    cnt = 0;
    o->w34 = 0;
    o->w30 = 0;
    o->w38 = 0;
    lim = c->w20 + 0x20;
    chunk += 0x10;
    for (i = 0; i < count; i++) {
        w = *p++;
        n = w & 0x3FFF;
        o->w34 += n;
        o->w30 += n - 2;
        fl = src->flags;
        if ((fl & 0x400000) != 0) {
            cur = *p++;
        }
        if ((fl & 0x100000) != 0) p += 2;
        if ((fl & 0x1000) != 0) p += w & 0x3FFF;
        if (prev != cur) {
            o->w38 += 1;
            buf[cur] = 1;
            prev = cur;
            if (cnt != 0) {
                chunk += pos;
                total += chunk;
            }
            chunk = 0x10;
            pos = chunk;
            total += 0x10;
            chunk += 0x20;
            pos += 0x10;
        }
        j = 0;
        while (j < n) {
            sz = D_00478E10[c->w18].e0;
            if ((u32)(pos + sz) >= c->w20) {
                chunk += pos;
                if ((u32)(chunk + lim) >= 0x100000) {
                    total += chunk;
                    chunk = 0x10;
                }
                pos = 0x10;
                chunk += 0x20;
                pos += 0x10;
            }
            cnt += sz / sz;
            pos += sz;
            j++;
        }
    }
    chunk += pos;
    total += chunk;
    o->w18 = total;
    o->w28 = 0;
    for (i = 0; i < 0x20; i++) {
        if (buf[i] != 0) {
            o->b50[o->w28++] = i;
        }
    }
    o->w20 = func_003DCFE0(o->w28 * D_00478DF0[c->w14], 3);
    o->w1C = func_003DCFE0(o->w18, 3);
    o->w24 = func_003DCFE0(o->w38 << 2, 3);
}
