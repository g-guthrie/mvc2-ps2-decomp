typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34, f38; } S14;
typedef struct { u8 pad[0x7C]; s16 t[1]; } G;
extern G *D_004C2794;
void func_0034DF50(u8 *p) {
    extern void func_001757E0();
    f32 q5;
    S14 *q = *(S14**)(p + 0x14);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x46;
    p[0x1B2] = *(u16*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]] += 1;
    p[0x24] = 0;
    *(f32*)(p + 0x34) = q->f34;
    *(f32*)(p + 0x38) = q->f38;
    *(u32*)(p + 0x5C) = 0;
    *(u32*)(p + 0x60) = 0;
    *(u32*)(p + 0x68) = 0;
    *(u32*)(p + 0x6C) = 0;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x10;
    p[0x14F] = 0x40;
    if (*(s16*)(p + 0x140) != 0) {
        f32 k = 10.833333f;
        q5 = k;
    } else {
        f32 k = -10.833333f;
        q5 = k;
    }
    *(f32*)(p + 0x5C) = q5;
    func_001757E0(p, 0x17, 8);
}

