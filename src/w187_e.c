typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003CE3D0(u8 *, u8 *);
extern void func_003CE2D0(u8 *, u8 *);
extern void func_00175700(u8 *);

typedef struct { u8 p0[0x24]; s8 b24; u8 p1[0x0F]; f32 f34; f32 f38; u8 p2[0x104]; s16 h140; u8 p3[0xE]; s8 b150; s8 b151; u8 p4[0x16]; u16 h168; } SB;
typedef struct { u8 p0[0x24]; s8 b24; u8 p1[0x0F]; f32 f34; f32 f38; } SA;

void func_003CDDF0(u8 *actor, u8 *owner) {
    SB *b = (SB *)owner;
    SA *a = (SA *)actor;
    if (((u8 *)b)[4] >= 2 || b->h168 != *(u32 *)((u8 *)a + 0xD0)) {
        *(u32 *)((u8 *)a + 0x118) = 0;
        func_003CE3D0((u8 *)a, (u8 *)b);
    } else {
        f32 v;
        a->b24 = b->b24;
        v = 1.6666666269302368f * (f32)b->b151;
        if (b->h140 != 0) v = -v;
        a->f34 = b->f34 + v;
        a->f38 = b->f38 + 2.142857074737549f * (f32)b->b150;
        func_00175700((u8 *)a);
        func_003CE2D0((u8 *)a, (u8 *)b);
    }
}
