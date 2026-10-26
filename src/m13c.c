typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);

extern void func_00248320(u8 *);
extern void func_00360530(u8 *, s32, s32);

void func_00246250(u8 *p,void *work_context_unused) {
    s32 i;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    func_00248320(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        for (i = 0; i < 10; i++) {
            func_00360530(p, 0, (u8)i);
        }
    }
}
