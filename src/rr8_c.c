typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct F41B_Q { u8 pad0[0x18]; s32 w18; } F41B_Q;
typedef struct F41B_T { u8 pad0[8]; s32 w8; u8 padC[0x1C - 0xC]; s32 w1C; u8 pad20[0x40 - 0x20]; F41B_Q *w40; u8 pad44[0x170 - 0x44]; } F41B_T;
typedef struct F41B_A { s32 w0; u8 pad4[0x20 - 4]; u32 w20; } F41B_A;
typedef struct F41B_E { u32 w0, w4; } F41B_E;

extern F41B_T D_005BF2F0[];
extern F41B_E D_004A6D54[];

static u8 *func_0041B2C0(u32 *p) {
    u32 w = p[0];
    u32 n = w & 0xFFFF;
    u8 *q = (u8 *)p + 0x10;
    switch (w & 0x70000000) {
    case 0x10000000: return q + n * 16;
    case 0x20000000: return (u8 *)(p[1] & 0x7FFFFFFF);
    case 0x30000000:
    case 0x40000000: return q;
    case 0: return 0;
    case 0x50000000: return (u8 *)(p[1] & 0x7FFFFFFF);
    case 0x60000000:
    case 0x70000000: return 0;
    }
    return 0;
}

void func_0041B8B0(F41B_A *a, u16 *out)
{
    extern s32 func_003DD030(s32);
    F41B_T *s;
    u8 *base, *cur;
    u32 *pk;
    u16 *hp;
    u32 flags, total, w, type, size, cnt, n, i;

    s = &D_005BF2F0[a->w0 - 1];
    base = (u8 *)func_003DD030(s->w1C);
    flags = D_004A6D54[s->w40->w18].w0;
    total = 0;
    cur = base;
    pk = (u32 *)base;
    do {
        w = *pk;
        type = w & 0x70000000;
        size = (w & 0xFFFF) << 4;
        cnt = 0;
        cnt += 0x10;
        cur += 0x10;
        if (cnt < size) do {
            if (type == 0x70000000 || type == 0x10000000) {
                hp = (u16 *)(cur + 0x20);
                cur += 0x30;
                cnt += 0x30;
                n = *hp & 0x7FFF;
                for (i = 0; i < n; i++) {
                    switch (s->w8) {
                    case 0x25:
                        if (flags & 1) { cnt += 0x10; out[1] = cur - base; cur += 0x10; out += 2; }
                        if (flags & 2) { cur += 0x10; cnt += 0x10; }
                        if (flags & 4) { cur += 0x10; cnt += 0x10; }
                        break;
                    case 0x35:
                        if (flags & 1) { cnt += 0x10; out[1] = cur - base; cur += 0x10; out += 2; }
                        if (flags & 2) { cur += 0x10; cnt += 0x10; }
                        if (flags & 4) { cur += 0x10; cnt += 0x10; }
                        if (flags & 8) { cur += 0x10; cnt += 0x10; }
                        break;
                    }
                }
                cur += 0x10;
                cnt += 0x10;
            } else {
                cnt += size;
            }
        } while (cnt < size);
        pk = (u32 *)func_0041B2C0(pk);
        total += cnt;
        cur = (u8 *)pk;
    } while (pk != 0);
    a->w20 = total;
}
