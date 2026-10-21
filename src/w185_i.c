typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[2]; s8 b2; } G2;
extern G2 *D_004C2840;

extern s32 D_004C2838;

void func_0015AD80(s32 a0, V3 *pos, f32 vel, s32 n, s32 k, u32 flags)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_00118FA8(f32);
    extern void func_0015AC20(u8 *);
    u8 *o;
    u32 f = flags & 0xFFFF;
    u32 s1;
    if ((f & 0x10) != 0) {
        s1 = f & 0x200;
        if (!(n > 1 && k != n - 1)) {
            if (s1 != 0) {
                if ((o = func_003DA750(0, 0x24, 1)) == 0) return;
            } else {
                if ((o = func_003DA750(0, 0x25, 1)) == 0) return;
            }
            o[0x13C] = 0;
            *(void **)(o + 0x10) = (void *)func_0015AC20;
            *(u32 *)(o + 0xD0) = 0x800431;
            *(V3 *)(o + 0x34) = *pos;
            if (s1 != 0) {
                *(f32 *)(o + 0x3C) -= 135.0f;
            }
            *(s16 *)(o + 0x1C) = 9;
            *(s16 *)(o + 0x1E) = 0xF;
            *(u32 *)(o + 0x74) = 0x3E800000;
            *(u32 *)(o + 0x78) = 0;
            *(u32 *)(o + 0x7C) = 0;
            *(u32 *)(o + 0x80) = 0;
            *(s16 *)(o + 0xCC) = 0xB6;
            *(s32 *)(o + 0x84) = D_004C2838;
            *(f32 *)(o + 0x50) = vel;
            *(f32 *)(o + 0x54) = vel;
            *(f32 *)(o + 0x58) = vel;
            o[0x23] = k;
            *(s32 *)(o + 0xD4) = k << 3;
            *(s32 *)(o + 0xD8) = func_00118FA8(vel);
        }
    }
}
