typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_002BEBF0(u8 *p) {
    extern void func_0015D010();
    extern void func_001757E0();
    s16 t = p[0x1E6] ^ 1;
    f32 v[4]; f32 w;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = t;
    *(s16 *)(p + 0x1C) = 0x10;
    w = (p[0x1E6] != 0) ? 1.6666666269302368f : -1.6666666269302368f;
    *(f32 *)(p + 0x5C) = w;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x42092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)&v[0] = 0xC22D5555;
    *(u32 *)&v[2] = 0;
    *(u32 *)&v[1] = 0x42960000;
    func_0015D010(p, v);
    func_001757E0(p, 0xF, 6);
}

void func_002BEA80(u8 *p) {
    extern void func_0018C6E0(u8 *);
    extern void func_0015D010(u8 *, f32 *);
    extern int func_001757E0(u8 *, int, int);
    s16 t;
    f32 w;
    f32 v[3];
    func_0018C6E0(p);
    t = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = t;
    w = p[0x1E6] ? 6.6666665077209473f : -6.6666665077209473f;
    *(f32 *)(p + 0x5C) = w;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)&v[0] = 0xC22D5555;
    *(u32 *)&v[1] = 0x42960000;
    *(u32 *)&v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_001757E0(p, 0xF, 4);
}
