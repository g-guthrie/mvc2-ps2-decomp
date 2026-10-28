/* s8d_b: MW 3.0 (try30.sh) -O3,p -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x88]; s8 b88; s8 b89; } G88;

extern G88 *D_004C2840;
extern s8 D_004C2910[6];
extern s8 D_004C2908[6];
extern s8 D_004C1850[6];
extern u32 D_00583BCC[];
extern u32 D_00583BD0[];
extern u32 D_00583BD4[];
extern u32 D_00583BD8[];
extern u8 D_00583B90[];
extern s8 D_004F20B0[];
extern s16 D_0045E338[];

s8 func_0032DAB0(u8 *a, u8 *b, s32 c)
{
    extern u8 func_0032D620(u32 *, s32);
    u32 *pv;
    u32 v[3];
    u32 out;
    u8 ok;
    s32 g;
    u8 side;
    u8 mask;
    s8 c0, r, x, y;
    s32 t0, t1, t2;
    s8 *e;
    u32 x0;

    pv = &v[1];
    *pv = 0;
    v[0] = 0;
    g = D_004C2840->b88 | D_004C2840->b89;
    ok = 1;
    if (g & 1) {
        v[0] = v[0] | (s32)D_00583BCC[0];
        *pv = *pv | (s32)D_00583BD0[0];
    }
    if (g & 2) {
        v[0] = v[0] | (s32)D_00583BD4[0];
        *pv = *pv | (s32)D_00583BD8[0];
    }
    x0 = v[func_0032D620(&out, (s8)b[0x540])];
    if ((out & x0) == 0) {
        if ((s16)c == 0x80 || (s16)c == 0x10) c = (s16)(c << 1);
    } else {
        ok = 0;
    }
    side = (s8)a[0x538] ^ 1;
    mask = 0;
    for (c0 = 0, t0 = 0; c0 < 3; c0++, t0 += 2) {
        if (D_00583B90[side + 2] & (1 << c0)) {
            e = D_004F20B0 + (side + t0) * 0x5B8;
            x = e[0x540];
            D_004C2910[side * 3 + c0] = x;
            y = e[0x541];
            D_004C2908[side * 3 + c0] = y;
            if ((s8)b[0x540] == x) mask |= 1 << y;
        }
    }
    for (c0 = 0, t1 = 0; c0 < 3; c0++, t1 += 2) {
        (D_004C2910 + (s8)a[0x538] * 3)[c0] = D_004F20B0[((s8)a[0x538] + t1) * 0x5B8 + 0x540];
        (D_004C2908 + (s8)a[0x538] * 3)[c0] = D_004F20B0[((s8)a[0x538] + t1) * 0x5B8 + 0x541];
        if ((s8)b[0x538] != (s8)a[0x538] + t1) {
            if (D_00583B90[(s8)a[0x538] + 2] & (1 << c0)) {
                e = D_004F20B0 + ((s8)a[0x538] + t1) * 0x5B8;
                if ((s8)b[0x540] == e[0x540]) mask |= 1 << e[0x541];
            }
        }
    }
    r = 0;
    for (c0 = 0, t2 = 0; c0 < 6; c0++, t2 += 2) {
        if ((s16)c == *(s16 *)((u8 *)D_0045E338 + t2)) {
            r = D_004C1850[c0];
            break;
        }
    }
    if (mask & (1 << r)) {
        for (c0 = 0; c0 < 6; c0++) {
            if (!(mask & (1 << c0))) {
                r = c0;
                break;
            }
        }
    }
    if (ok && r == 4) r = 0;
    else if (ok && r == 5) r = 1;
    return r;
}
