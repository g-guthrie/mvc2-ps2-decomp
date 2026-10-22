typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define Q (*(u8 **)(p + 0x1DC))

void func_002BE800(u8 *p)
{
    extern void func_0018C6E0(void *);
    extern void func_0015D010(u8 *, f32 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 v[3];
    f32 a;
    s16 t;
    func_0018C6E0(p);
    t = p[0x1E6] ^ 1;
    *(s16 *)(Q + 0x140) = t;
    Q[0x1E6] = t;
    if ((p[0x22] & 1) == 0) {
        t = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = t;
        p[0x1E6] = t;
        t = p[0x1E6] ^ 1;
        *(s16 *)(Q + 0x140) = t;
        Q[0x1E6] = t;
    }
    if (p[0x1E6] != 0) a = -3.3333332538604736f; else a = 3.3333332538604736f;
    *(f32 *)(p + 0x5C) = a;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xC0892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    v[0] = -50.0f;
    v[1] = 158.57142639160156f;
    v[2] = 0.0f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 1);
}
