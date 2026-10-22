typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

#define RESET_ACTION(p,code) do {u32 ca; (p)[0x1B5]=(code);(p)[0x1B2]=*(u16 *)((p)+0x1C0)=0;*(u32 *)((p)+0x1D8)=0;ca=(p)[2]*2;ca+=(u32)D_004C2794;ca+=0x7C;++*(s16 *)ca;}while(0)

void func_00375B20(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_00375CA0(u8 *, u8 *);
    u8 *o;
    u8 *r;
    s32 a;
    s32 b;
    o = *(u8 **)(p + 0x18);
    r = p + 0xD0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        RESET_ACTION(p, 0x45);
    }
    func_001E7F60(p);
    if (o[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    a = o[0x1FD];
    if (a == 7) {
        b = o[6];
        if (b == 3) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
        if (b == 4) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    if (a == 0xC) {
        b = o[6];
        if (b == 7) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
        if (b == 8) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    *r = o[0x168];
    func_00375CA0(o, p);
    p[0x24] = 0;
}
