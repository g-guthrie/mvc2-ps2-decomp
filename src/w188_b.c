typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w188_b.c "-O3,p -sdatathreshold 0" */

s32 func_0041B710(u32 *a) {
    u16 *p; u32 n; s32 count; u32 i; u32 flags; u32 h; u32 j; u32 type;
    n = a[1]; p = (u16 *)a[2]; count = 0;
    for (i = 0; i < n; i++) {
        flags = a[0];
        h = *p++;
        if (flags & 0x400000) p++;
        if (flags & 0x100000) p += 2;
        type = a[3];
        for (j = 0; j < (h & 0x3FFF); j++) {
            switch (type) {
            case 0x25: case 0x35: case 0x235:
                if (flags & 0x1000) {
                    p++;
                    count++;
                }
                break;
            }
        }
    }
    return count;
}

void func_003EB5D0(s32 w, s32 h, u8 *src, u8 *dst) {
    u8 buf[0x2000];
    s32 bh;
    s32 i;
    s32 j;
    s32 k;
    s32 bw;
    u8 *p;
    u8 *q;
    s32 off;
    extern void func_0011D740(u8 *, u8 *, s32);
    extern void func_003EB720(u8 *, u8 *, s32);
    bw = (w - 1) / 128 + 1;
    bh = (h - 1) / 64 + 1;
    for (j = 0; j < bh; j++) {
        for (i = 0; i < bw; i++) {
            off = bw * (j * 0x2000);
            q = buf;
            p = src + off + i * 0x80;
            for (k = 0; k < 0x40; k++) {
                func_0011D740(q, p, 0x80);
                p += bw << 7;
                q += 0x80;
            }
            func_003EB720(buf, dst + off + i * 0x100, bw);
        }
    }
}

typedef struct { u8 b0; u8 pad[3]; s32 f4; s32 f8; s32 fC; s32 f10; } E_001E48B0;
extern E_001E48B0 D_004CBE80[];
extern u8 D_004B6C00[];
void func_001E48B0(void) {
    s32 i;
    s32 r1;
    s32 off;
    s32 r2;
    E_001E48B0 *e;
    s32 *py;
    s32 *px;
    extern s32 func_00422FB0(s32);
    extern void func_00422C70(void);
    extern void func_004231D0(void);
    extern void func_0011EB60(u8 *, s32, s32);
    for (i = 0, off = 0; i < 0x24; i++, off += 0x14) {
        e = (E_001E48B0 *)((u8 *)D_004CBE80 + off);
        px = &e->f4;
        py = &e->f8;
        r1 = func_00422FB0(((*px & 0x7F) << 16) | ((*py & 0x7F) << 8) | 1);
        r2 = func_00422FB0(((*px & 0x7F) << 16) | ((*py & 0x7F) << 8) | (i & 0x7F));
        if (r1 < 0 || r2 < 0) {
            func_00422C70();
            func_004231D0();
            r1 = func_00422FB0(((*px & 0x7F) << 16) | ((*py & 0x7F) << 8) | 1);
            r2 = func_00422FB0(((*px & 0x7F) << 16) | ((*py & 0x7F) << 8) | (i & 0x7F));
            func_0011EB60(D_004B6C00, r1, r2);
        }
        e->b0 = 0;
        *px = 0;
        *py = 0;
        e->fC = 0;
        e->f10 = 0;
    }
}
