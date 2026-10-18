typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x20]; f32 f5C; f32 f60; u8 p2[4]; f32 f68; f32 f6C; } PF;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern void func_00361F90();
extern void func_001E7F60();
extern s32 func_00174170();

void func_00361D70(PF *p, u8 *q) {
    u32 *z0, *z1;
    u32 t;
    s32 h;
    s32 r;
    z1 = (u32 *)((u8 *)p + 0x68);
    z0 = (u32 *)((u8 *)p + 0x5C);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00361F90(p);
    if (q[0x169] != ((u8 *)p)[0xD1]) {
        t = ((u8 *)p)[4];
        ((u8 *)p)[4] = t + 1;
    } else if (((s8 *)p)[0x1B3] != 0) {
        t = ((u8 *)p)[4];
        ((u8 *)p)[4] = t + 1;
    } else {
        func_001E7F60(p);
        h = *(s16 *)((u8 *)p + 0x1C);
        *(s16 *)((u8 *)p + 0x1C) = h - 1;
        if (h == 0) {
            t = ((u8 *)p)[5];
            ((u8 *)p)[5] = t + 1;
            ((u8 *)p)[0x1B5] = 0x36;
            t = ((u8 *)p)[0x1B5];
            ((u8 *)p)[0x1B5] = t;
            ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
            *(s32 *)((u8 *)p + 0x1D8) = 0;
            D_004C2794->h7C[((u8 *)p)[2]]++;
            *z0 = 0;
            *z1 = 0;
            r = func_00174170() & 3;
            if (*(s16 *)(q + 0x140) == 0) ((u8 *)p)[0x22] = r + 0x17;
            else ((u8 *)p)[0x22] = r + 6;
            t = ((u8 *)p)[0x22];
            ((u8 *)p)[0x22] = t & 0x1F;
        }
    }
}
