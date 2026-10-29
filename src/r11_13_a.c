/* Metrowerks 3.0 (./try30.sh), -O3 -Op -sdatathreshold 0.
 * func_00413600 transforms a quad's four corners by m through the VU0 leaf
 * func_004135D0 and converts them to 12.4 screen coordinates. The leaf is a
 * static copy of the real callee (it sits immediately before the caller and is
 * credited in src/vu0_d.c); being in the same file lets MW keep v and o in
 * $t7/$t6 across the calls, as retail does. Only its COP2 instructions are
 * inline asm, with C parameters as operands. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0062BF8C[];
extern s32 D_0062BF90[];
extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern s32 D_0062BC00[];

static void func_004135D0(f32 *d, f32 *s, u8 *m)
{
    asm {
        lqc2 vf4, 0(s)
        lqc2 vf5, 0(m)
        lqc2 vf6, 0x10(m)
        lqc2 vf7, 0x20(m)
        lqc2 vf8, 0x30(m)
        vmulax.xyzw ACC, vf5, vf4x
        vmadday.xyzw ACC, vf6, vf4y
        vmaddaz.xyzw ACC, vf7, vf4z
        vmaddw.xyzw vf4, vf8, vf4w
        vftoi4.xy vf4, vf4
        sqc2 vf4, 0(d)
    }
}

s32 func_00413600(u8 *m, f32 *v, f32 *o, u32 fl, f32 s) {
    u32 r;
    s32 gx, gy, ox, oy;
    u32 x0, y0, x1, y1, x2, y2, x3, y3;
    s32 sh;
    u32 t;
    s32 *w;

    v[4] = v[0] + s;
    v[5] = v[1];
    v[8] = v[0];
    v[9] = v[1] + s;
    v[12] = v[0] + s;
    v[13] = v[1] + s;
    v[14] = 0.0f;
    v[10] = 0.0f;
    v[6] = 0.0f;
    v[2] = 0.0f;
    v[15] = 1.0f;
    v[11] = 1.0f;
    v[7] = 1.0f;
    v[3] = 1.0f;
    func_004135D0(v, v, m);
    func_004135D0(v + 4, v + 4, m);
    func_004135D0(v + 8, v + 8, m);
    func_004135D0(v + 12, v + 12, m);
    s *= 0.0078125f;
    gx = D_0062BF8C[0] << 4;
    gy = D_0062BF90[0] << 4;
    ox = D_0062BF84[0] << 4;
    oy = D_0062BF88[0] << 4;
    sh = D_0062BC00[0] == 0 ? 1 : 0;
    w = (s32 *)v;
    x0 = ox + (w[0] - gx);
    y0 = oy + ((s32)(w[1] - gy) >> sh);
    x1 = ox + (w[4] - gx);
    y1 = oy + ((s32)(w[5] - gy) >> sh);
    x2 = ox + (w[8] - gx);
    y2 = oy + ((s32)(w[9] - gy) >> sh);
    x3 = ox + (w[12] - gx);
    y3 = oy + ((s32)(w[13] - gy) >> sh);
    r = 0;
    if (x0 == x1) {
        if (y1 < y0) r |= 0x8000;
        if (x2 < x0) r |= 0x4000;
    }
    if (x0 == x2) {
        if (y2 < y0) r |= 0x4000;
        if (x1 < x0) r |= 0x8000;
    }
    t = fl ^ r;
    if (t & 1) {
        o[16] -= 0.00013899999612476677f;
        o[17] -= 0.00013899999612476677f;
    } else if (t & 0x8000) {
        o[16] -= 0.00013899999612476677f;
        o[17] -= 4.999999873689376e-05f;
    } else if (t & 0x4000) {
        o[16] -= 4.999999873689376e-05f;
        o[17] -= 0.00013899999612476677f;
    }
    switch (fl & 0xC000) {
    case 0:
        o[20] = o[16] + s;
        o[21] = o[17];
        o[24] = o[16];
        o[25] = o[17] + s;
        o[28] = o[16] + s;
        o[29] = o[17] + s;
        break;
    case 0x8000:
        o[20] = o[16];
        o[21] = o[17];
        o[16] = o[16] + s;
        o[17] = o[17];
        o[28] = o[20];
        o[29] = o[21] + s;
        o[24] = o[20] + s;
        o[25] = o[21] + s;
        break;
    case 0x4000:
        o[24] = o[16];
        o[25] = o[17];
        o[28] = o[16] + s;
        o[29] = o[17];
        o[16] = o[16];
        o[17] = o[17] + s;
        o[20] = o[24] + s;
        o[21] = o[25] + s;
        break;
    case 0xC000:
        o[28] = o[16];
        o[29] = o[17];
        o[24] = o[16] + s;
        o[25] = o[17];
        o[20] = o[16];
        o[21] = o[17] + s;
        o[16] = o[16] + s;
        o[17] = o[17] + s;
        break;
    }
    if (x0 < 0x10000 && x1 < 0x10000 && x2 < 0x10000 && x3 < 0x10000 &&
        y0 < 0x10000 && y1 < 0x10000 && y2 < 0x10000 && y3 < 0x10000) {
    } else {
        return 0;
    }
    {
        *(u16 *)((u8 *)o + 0x48) = x0;
        *(u16 *)((u8 *)o + 0x4A) = y0;
        *(u16 *)((u8 *)o + 0x58) = x1;
        *(u16 *)((u8 *)o + 0x5A) = y1;
        *(u16 *)((u8 *)o + 0x68) = x2;
        *(u16 *)((u8 *)o + 0x6A) = y2;
        *(u16 *)((u8 *)o + 0x78) = x3;
        *(u16 *)((u8 *)o + 0x7A) = y3;
    }
    return 1;
}
