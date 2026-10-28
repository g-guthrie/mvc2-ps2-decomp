/* s5d: MW 3.0, ./try30.sh src/s5d_c.c "-O3 -Op -sdatathreshold 0". static func_00191F50 is the real callee (credited in src/dupcluster_00191F50.c); it moves the s8 sign-extension into v1. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { unsigned char prefix[0x38]; float y; unsigned char reserved[0x3f4]; float floor; } HeightState;
static void func_00191F50(unsigned char *owner) {
 HeightState *p=(HeightState *)owner;
 if (p->y<=34.28571319580078125000f+p->floor)
  p->y=34.28571319580078125000f+p->floor;
}

void func_001925A0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    if (p[6] == 0) {
        f32 a, b;
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        a = 13.33333302f;
        b = 0.3125f;
        if ((p[0x22] & 3) == 1) {
            func_001757E0(p, 0x14, 3);
        } else {
            a = -a;
            b = -b;
            func_001757E0(p, 0x14, 2);
        }
        if (p[0x1E6] != 0) {
            a = -a;
            b = -b;
        }
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = b;
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_00184540(p);
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_00191F50(p);
        }
    }
}
