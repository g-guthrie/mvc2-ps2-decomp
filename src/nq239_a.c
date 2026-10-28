typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

static void func_00141540(V3 *out, V3 *a, V3 *b, f32 s) {
    V3 t;
    t.x = (a->x - b->x) / s;
    t.y = (a->y - b->y) / s;
    t.z = (a->z - b->z) / s;
    *out = t;
}

#define ANG(x) ((s32)(0.5 + k * (double)(x) / 360.0) & 0xFFFF)

void func_001415B0(u8 *p)
{
    V3 v, w;
    V3 *vc, *vd;
    s16 key;
    double k;
    s16 *q;
    s16 dur;
    V3 *va, *vb;
    f32 fa, fb, r, d;
    u8 fl;

    if (p[0x23] == 0x28) {
        q = *(s16 **)(p + 0x10);
        if (q[8] == -1) goto none;
        vb = (V3 *)(q + 2);
        *(s16 *)(p + 0x1C) = q[8] - q[0];
        *(s16 **)(p + 0x10) = q + 8;
        func_00141540(&v, (V3 *)(q + 10), vb, (f32)*(s16 *)(p + 0x1C));
        *(f32 *)(p + 0x3C) = 10.0f * vb->x;
        *(f32 *)(p + 0x58) = vb->y;
        *(f32 *)(p + 0x64) = v.x;
        *(f32 *)(p + 0x70) = v.y;
        return;
    }
    if (p[0x23] == 0x27) {
        q = *(s16 **)(p + 0x10);
        if (q[12] == -1) goto none;
        *(s16 *)(p + 0x1C) = q[12] - q[0];
        fa = *(f32 *)(q + 14);
        fb = *(f32 *)(q + 2);
        r = fa - fb;
        *(f32 *)(p + 0x64) = 10.0f * (r / (f32)*(s16 *)(p + 0x1C));
        k = 65536.0;
        *(s32 *)(p + 0xDC) = ANG(((f32)q[16] - (f32)q[4]) / (f32)*(s16 *)(p + 0x1C));
        func_00141540(&v, (V3 *)(q + 18), (V3 *)(q + 6), (f32)*(s16 *)(p + 0x1C));
        *(V3 *)(p + 0x68) = v;
        *(s16 **)(p + 0x10) = q + 12;
        return;
    }
    switch (p[0x20]) {
    case 1:
        q = *(s16 **)(p + 0x10);
        if ((key = q[8]) == -1) goto none;
        va = (V3 *)(q + 10);
        vb = (V3 *)(q + 2);
        dur = key - q[0];
        *(s16 **)(p + 0x10) = q + 8;
        break;
    case 2:
        q = *(s16 **)(p + 0x10);
        if ((key = q[2]) == -1) goto none;
        dur = key - q[0];
        fa = q[3];
        fb = q[1];
        *(s16 **)(p + 0x10) = q + 2;
        break;
    case 3:
        q = *(s16 **)(p + 0x10);
        if ((key = q[8]) == -1) goto none;
        va = (V3 *)(q + 10);
        dur = key - q[0];
        fa = q[9];
        fb = q[1];
        vb = (V3 *)(q + 2);
        *(s16 **)(p + 0x10) = q + 8;
        break;
    case 4:
        q = *(s16 **)(p + 0x10);
        if ((key = q[6]) == -1) goto none;
        vc = (V3 *)(q + 8);
        vd = (V3 *)(q + 2);
        dur = key - q[0];
        *(s16 **)(p + 0x10) = q + 6;
        break;
    case 5:
        q = *(s16 **)(p + 0x10);
        if ((key = q[12]) == -1) goto none;
        va = (V3 *)(q + 14);
        vb = (V3 *)(q + 2);
        vc = (V3 *)(q + 20);
        vd = (V3 *)(q + 8);
        dur = key - q[0];
        *(s16 **)(p + 0x10) = q + 12;
        break;
    case 6:
        q = *(s16 **)(p + 0x10);
        if ((key = q[6]) == -1) goto none;
        if (q[6] == -3) {
            fa = q[-5];
            fb = q[-11];
            dur = 0x3C;
            vc = (V3 *)(q - 10);
            vd = (V3 *)(q + 2);
            *(s16 **)(p + 0x10) = q - 12;
            break;
        }
        if (key == -2) q -= 12;
        vc = (V3 *)(q + 8);
        vd = (V3 *)(q + 2);
        dur = q[6] - q[0];
        fa = q[7];
        fb = q[1];
        *(s16 **)(p + 0x10) = q + 6;
        break;
    case 0:
    default:
        return;
    }
    *(s16 *)(p + 0x1C) = dur;
    if (p[0x20] & 1) {
        func_00141540(&v, va, vb, (f32)*(s16 *)(p + 0x1C));
        *(f32 *)(p + 0x34) = 10.0f * vb->x;
        *(f32 *)(p + 0x38) = 10.0f * vb->y;
        *(f32 *)(p + 0x3C) = 10.0f * vb->z;
        *(f32 *)(p + 0x5C) = v.x;
        *(f32 *)(p + 0x60) = v.y;
        *(f32 *)(p + 0x64) = v.z;
    }
    fl = p[0x20];
    if (fl & 2) {
        d = fa - fb;
        r = d / (f32)*(s16 *)(p + 0x1C);
        if (fl == 3) {
            k = 65536.0;
            *(s32 *)(p + 0x44) = ANG(fb);
        } else if (key != -3) {
            k = 65536.0;
            *(s32 *)(p + 0x48) = ANG(fb);
        }
        *(s32 *)(p + 0xD4) = 0;
        if (p[0x20] == 3) {
            k = 65536.0;
            *(s32 *)(p + 0xD8) = ANG(r);
            *(s32 *)(p + 0xDC) = 0;
        } else {
            *(s32 *)(p + 0xD8) = 0;
            k = 65536.0;
            *(s32 *)(p + 0xDC) = ANG(r);
        }
    }
    if (p[0x20] & 4) {
        func_00141540(&w, vc, vd, (f32)*(s16 *)(p + 0x1C));
        if (key != -3) {
            *(f32 *)(p + 0x50) = vd->x;
            *(f32 *)(p + 0x54) = vd->y;
        }
        *(f32 *)(p + 0x68) = w.x;
        *(f32 *)(p + 0x6C) = w.y;
        *(f32 *)(p + 0x70) = 0.0f;
    }
    return;
none:
    if (!(p[0x20] & 2)) {
        *(s32 *)(p + 0xDC) = 0;
        *(s32 *)(p + 0xD8) = 0;
        *(s32 *)(p + 0xD4) = 0;
    }
    *(f32 *)(p + 0x64) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x70) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(s16 *)(p + 0x1C) = 0xF0;
}
