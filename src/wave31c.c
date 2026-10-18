typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(void *, s32, s32);
extern void func_0015D010(void *, f32 *);
extern void func_0018C6E0(void *);
void func_00304500(u8 *p) {
    f32 v[3];
    if (p[0x22] & 1) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 4);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    v[0] = -58.333333f;
    v[1] = 135.0f;
    v[2] = 0.0f;
    func_0015D010(p, v);
    func_0018C6E0(p);
    *(s16 *)(p + 0x1C) = 0x3C;
}
