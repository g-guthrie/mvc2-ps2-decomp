typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00207AC0(u8 *p) {
    extern void func_001266A0();
    extern void func_0018C6E0();
    extern void func_0015D010();
    extern void func_001757E0();
    f32 v[4];
    f32 t;
    if (p[0x269] != 8 && p[0x269] != 3) func_001266A0(p, 1, 1);
    func_0018C6E0(p);
    *(s16 *)(p + 0x1C) = 0xC;
    p[0x1FE] = 1;
    t = *(f32 *)(p + 0x64);
    if (t > 0.0f) v[0] = -t; else v[0] = t;
    *(u32 *)&v[1] = 0x3F1C6DB7;
    func_0015D010(p, v);
    if (p[0x20D] != 2) {
        if (p[0x269] != 8) {
            func_001757E0(p, 0x15, 0xB);
        } else {
            func_001757E0(p, 0x15, 0x15);
        }
    } else {
        func_001757E0(p, 0x15, 0x10);
    }
}
