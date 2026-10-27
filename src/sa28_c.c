typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#pragma pack(1)
typedef struct { s8 b[5]; } P5;
#pragma pack()

extern u8 D_004BDC40[];
extern u8 D_00489128[];

s32 func_0040A740(u8 *a, s32 b) {
    extern s32 func_0011FB38(P5 *, u8 *);
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_0040A440(u8 *, u8 *);
    extern void func_0010F148(s32);
    extern s32 func_004098D8(void *, u8 *);
    extern s32 func_0010F968(s32, s32, s32, u8 *);
    extern s32 func_0040C2C0(u8 *, s32);
    s32 w[12];
    u8 q[4];
    P5 loc;
    s32 r;
    loc = *(P5 *)a;
    loc.b[4] = 0;
    if (func_0011FB38(&loc, D_004BDC40) == 0) {
        return func_0040C2C0(a + 4, b);
    }
    func_0011D8F8(D_00489128, 0, 0x80);
    func_0040A440(a, D_00489128);
    func_0010F148(0);
    r = func_004098D8(w, D_00489128);
    if (r != 0) {
        q[1] = 1;
        q[0] = 0;
        q[2] = 0;
        q[3] = 0;
        r = func_0010F968(w[0], 2, b, q);
        if (r != 0) {
            func_0010F148(0);
            r = 1;
        }
    }
    return r;
}
