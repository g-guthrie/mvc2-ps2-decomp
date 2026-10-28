typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[5]; u8 b5; u8 b6; u8 pad7[0x15]; s16 s1C; u8 pad1E[0x3E]; f32 f5C; u8 pad60[8]; f32 f68; } A45;
typedef struct { u8 pad0[0xC]; s16 sC; } G45;
extern G45 *D_004C2840;
extern f32 D_004B33F0[];

void func_00145180(A45 *p, f32 *q)
{
    extern void func_00145220(A45 *);
    u32 t = p->b5;
    f32 a;
    p->b5 = t + 1;
    switch (p->b6) {
    case 0:
        q = &D_004B33F0[D_004C2840->sC];
        p->s1C = 0x19;
        break;
    case 1:
        q = &D_004B33F0[D_004C2840->sC];
        p->s1C = 10;
        break;
    default:
        break;
    }
    a = *q;
    a -= p->f5C;
    p->f68 = a / (f32)p->s1C;
    *(f32 *)((u8 *)p + 0x50) = *q;
    func_00145220(p);
}
