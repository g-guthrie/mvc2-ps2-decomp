typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34]; f32 f34; f32 f38; u8 pad3c[0x20];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x1A2];
    u8 b212; u8 b213;
} S2D6;

void func_002D6A60(S2D6 *p)
{
    extern void func_00183D90(S2D6 *);
    extern void func_001863F0(S2D6 *);
    extern s32 func_00175700(S2D6 *);
    extern void func_001843A0(S2D6 *);
    extern void func_002D69E0(S2D6 *);
    extern void func_00182380(S2D6 *);
    extern void func_001821D0(S2D6 *);
    extern void func_001820A0(S2D6 *);
    extern void func_00182300(S2D6 *);
    extern void func_00184540(S2D6 *);
    extern s32 func_001864a0(S2D6 *);
    extern void func_001865B0(S2D6 *);
    switch (p->b213) {
    case 3:
        func_00183D90(p);
    case 0:
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        func_001863F0(p);
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p->b212 == 0) {
            func_002D69E0(p);
        }
        break;
    case 2:
        func_00182380(p);
        func_001821D0(p);
    case 1:
        func_001820A0(p);
        func_00182300(p);
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        }
        if (func_001864a0(p) != 0) func_001865B0(p);
        break;
    }
}
