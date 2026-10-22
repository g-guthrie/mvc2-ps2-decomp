typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

typedef struct B14FD { u8 pad0[0x18]; struct B14FD *f18; u8 pad1c[0x74-0x1C]; f32 f74; u8 pad78[0x13C-0x78]; s8 b13C; } B14FD;

void func_0014FD80(B14FD *p)
{
    func_0014E770((u8 *)p);
    p->b13C = p->f18->b13C;
    p->f74 = p->f18->f74;
}
