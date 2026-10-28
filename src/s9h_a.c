/* MW 3.0.3 -O3 -Op -sdatathreshold 8. opt_propagation off is scoped to func_00230770 only. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad38[0x5C-0x38]; f32 f5c; u32 f60; u8 pad64[4]; f32 f68; u32 f6c; } FS;
extern void func_00175700(u8 *);
typedef unsigned short u16;
extern u8 *D_004C2794;

static void func_002304C0(p)
u8 *p;
{
    float x = 18.333332061767578125f;
    float y = -0.833333313465118408203125f;
    if (*(short *)(p + 320) == 0) {
        x = -x;
        y = -y;
    }
    *(float *)(p + 92) = x;
    *(float *)(p + 104) = y;
    *(unsigned int *)(p + 96) = 0;
    *(unsigned int *)(p + 108) = 0;
}

static void func_00230670(u8 *p, u8 *context) {
    s8 v = p[0x151];
    u32 low = (u8)v & 0xF;
    if (low) {
        s8 l = low;
        p[0x151] = v & ~0xF;
        p[0x1B5] = l + 0x4F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        { s16 *q = (s16 *)D_004C2794; q[p[2] + 0x3E]++; }
    }
}

#pragma push
#pragma opt_propagation off
void func_00230770(u8 *p, u8 *q) {
    s32 sw;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_00230670(p, q);
    sw = *(s8 *)(p + 0x150);
    switch (sw) {
    case 0:
        break;
    case 1:
        p[0x150] = sw + 1;
        func_002304C0(p, q);
    case 2: {
        f32 v = *(f32 *)(p + 0x5C);
        f32 z;
        v += *(f32 *)(p + 0x68);
        if (*(s16 *)(p + 0x140) == 0) {
            z = 0.0f;
            if (v > z) {
                ((FS *)p)->f68 = z;
                v = z;
            }
        } else {
            z = 0.0f;
            if (v < z) {
                ((FS *)p)->f68 = z;
                v = z;
            }
        }
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x34) += v;
        return;
    }
    case 3: {
        f32 a, b;
        u32 t = p[7];
        p[7] = t + 1;
        p[0x150] = 0;
        p[0x20D] = 2;
        b = 80.0f;
        a = 6.666666507720947f;
        if (p[0x1E6] == 0) {
            b = -b;
            a = -a;
        }
        *(f32 *)(p + 0x34) += b;
        *(f32 *)(p + 0x5C) = a;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x421A4924;
        *(u32 *)(p + 0x6C) = 0x3F892492;
        return;
    }
    }
}
#pragma pop
