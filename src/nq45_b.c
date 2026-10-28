typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; } G2970;
extern G2970 *D_004C2970;
extern void (*D_004C1C38[2])(u8 *);

typedef struct { u8 pad[0x1C]; s16 h; } S1C;
void func_00365B30(u8 *p) {
    extern s32 func_00174240(u8 *);
    extern void func_00365F50(u8 *);
    extern void func_0018D9A0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern s32 func_003657D0(u8 *, s32, s32);
    s32 v;
    u32 t;
    if (*(s16 *)(p + 0x1C) == 0 || --((S1C *)p)->h == 0) {
      if (func_00174240(p) == 0) {
        p[4] = 3;
        D_004C2970->b1 = 0;
        func_00365F50(p);
        return;
    }
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        func_0018D9A0(p);
        func_001E3210(p, 0x2C);
    } else {
        if (D_004C2970->b4 == 0) {
            if (func_003657D0(p, *(s32 *)(p + 0x18), 0x40) != 0) {
                D_004C2970->b4 = 1;
            }
        }
        D_004C1C38[p[5]](p);
    }
}
