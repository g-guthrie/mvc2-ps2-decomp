typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004CD168[];
extern f32 D_004CD158[];
extern u8 D_004C272A;
extern u8 D_004C2726;
extern s32 D_004C2B50;

void func_001E46E0(void) {
    extern s32 func_00119098(f32);
    extern s32 func_00118FA8(f32);
    extern s32 func_001E1FF0();
    extern void func_004020D8();
    f32 z = 0.0f;
    f32 v = D_004CD168[0] + D_004CD158[0];
    s32 s;
    u8 r;
    if (v < z) {
        D_004CD158[0] = z;
        v = z;
    }
    s = D_004C272A;
    if (s < (u8)func_00119098(v)) {
        v = (f32)(u32)s;
        D_004CD158[0] = 0.0f;
    }
    r = func_00119098(v);
    if (r != D_004C2726) {
        func_004020D8(D_004C2B50, (s16)func_001E1FF0(func_00118FA8(v)));
    }
    D_004C2726 = func_00119098(v);
    D_004CD168[0] = v;
}
