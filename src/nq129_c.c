typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } F3_c;
typedef struct { f32 a, b; } F2_c;
extern f32 D_00444120[];
extern F3_c D_00444140[];
extern f32 D_00444170[];
extern f32 D_00444174[];
extern u8 D_004B38A0[];
extern u8 D_0014C0D0[];
extern s32 D_004C27FC;

void func_0014C760(u8 **out, s32 a1, s32 a2, s32 a3, s32 t0, f32 y)
{
    extern s32 func_0011F938();
    extern u8 *func_003DA750(s32, s32, s32);
    u8 buf[16];
    f32 x;
    F3_c *v;
    f32 za, zb;
    s32 i;
    u8 *s;
    u8 *o;
    s32 c;
    x = D_00444120[a1];
    v = &D_00444140[a3];
    za = D_00444170[t0 * 2];
    zb = D_00444174[t0 * 2];
    i = 4 - func_0011F938(buf, D_004B38A0, a2);
    if (i < 0) {
        s = buf - i;
        i = 0;
    } else {
        s = buf;
    }
    x += 0.7f * (f32)i;
    if (i < 4) {
        do {
            if ((o = func_003DA750(0, 0xD, 1)) == 0) return;
            c = *(s8 *)s;
            o[0x13C] = 1;
            *(u8 **)(o + 0x10) = D_0014C0D0;
            *(s16 *)(o + 0xCC) = c - 0xB;
            *(s32 *)(o + 0x84) = D_004C27FC;
            *(u32 *)(o + 0xD0) = 0x800411;
            *(f32 *)(o + 0x34) = x;
            *(f32 *)(o + 0x38) = y;
            *(u32 *)(o + 0x3C) = 0xC14CCCCD;
            x += 0.7f;
            *(f32 *)(o + 0x78) = v->x;
            *(f32 *)(o + 0x7C) = v->y;
            *(f32 *)(o + 0x80) = v->z;
            *(f32 *)(o + 0x50) = za;
            *(f32 *)(o + 0x54) = zb;
            *out = o;
            out++;
            i++;
            s++;
        } while (i < 4);
    }
}
