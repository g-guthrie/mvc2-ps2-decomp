typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0029E980(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00179150(u8 *, u32);
    extern void func_0018FDB0(u8 *);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_001E3B70(u8 *, s32);
    extern void func_001548D0(u8 *, u32 *, s32);
    u32 *a, *b, *c;
    u32 v[4];
    s16 h;
    u32 t;
    c = (u32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a = (u32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        t = p[7];
        p[7] = t + 1;
        *a = 0;
        *c = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x16, 0xB);
        *(s8 *)(p + 0x16A) = -1;
        *(u8 *)((s32)p + 0x160) = 0x22;
        b = (u32 *)((s32)p + 0x160);
        func_00179150(p, *(u32 *)(p + 0x1DC));
        *(s8 *)(p + 0x16A) = -1;
        *(u8 *)b = 0;
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x3E;
        func_0018FDB0(p);
        func_00191480(q, p, 1);
        func_001E3B70(q, 3);
        v[0] = 0xC2555555;
        v[1] = 0x42092492;
        func_001548D0(p, v, 3);
    }
}
