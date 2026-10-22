typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_002534D0(u8 *p) {
    V3 sv[2];
    f32 w4[4];
    V3 *bp;
    u8 *o;
    extern void func_001266A0();
    extern void func_0018C6E0(void *);
    extern void func_0015D010();
    extern void func_001757E0();
    extern void func_00178F20();
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    *(u32 *)&w4[0] = 0xC2FD5555;
    *(u32 *)&w4[1] = 0x4304DB6D;
    *(u32 *)&w4[2] = 0;
    func_0015D010(p, w4);
    func_001757E0(p, 0xF, 1);
    bp = &sv[1];
    sv[0] = *(V3 *)(p + 0x34);
    o = *(u8 **)(p + 0x1DC);
    *bp = *(V3 *)(o + 0x34);
    func_00178F20(p, o);
    *(V3 *)(p + 0x34) = sv[0];
    *(V3 *)(*(u8 **)(p + 0x1DC) + 0x34) = *bp;
}
