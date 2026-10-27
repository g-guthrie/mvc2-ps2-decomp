typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_001F0F10(u8 *p) {
    extern s8 func_00175700();
    extern u8 *func_001E8070(u8 *);
    extern void func_001757E0();
    extern void func_001266A0();
    extern void func_001E3210();
    extern void func_0015D010();
    extern void func_00185770();
    u8 *o;
    f32 v[4];
    if (func_00175700(p) < 0) {
        p[7] = 8;
        func_001757E0(p, 0xF, 9);
        return;
    }
    if ((o = func_001E8070(p)) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001266A0(p, 5, 5);
        func_001E3210(p, 5);
        *(u32 *)&v[0] = 0xC312AAAA;
        *(u32 *)&v[1] = 0x432B6DB6;
        func_0015D010(p, v);
        func_001757E0(p, 0xF, 0xA);
        p[0x20B] = 0xC3;
        func_00185770(p, o);
    }
}
