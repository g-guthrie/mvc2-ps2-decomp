typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 D_00473B80[];
extern s8 D_00473B81[];
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 p0[0x34]; V3 pos; } Q;
typedef struct {
    u8 p0[0x18]; Q *q; u8 p1[0x21 - 0x1C]; u8 b21; u8 p2[0x34 - 0x22];
    V3 pos; u8 p3[0xD0 - 0x40]; s32 i; u8 p4[0x140 - 0xD4]; s16 flag;
} H;
void func_003AE2C0(H *p)
{
    f32 t;
    p->pos = p->q->pos;
    t = 1.6666666269302368f * (f32)D_00473B80[p->i * 4 + p->b21 * 2];
    p->pos.y += 2.142857074737549f * (f32)D_00473B81[p->i * 4 + p->b21 * 2];
    if (p->flag != 0) t = -t;
    p->pos.x += t;
}
