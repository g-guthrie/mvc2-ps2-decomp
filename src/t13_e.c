typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001EAC70(f32 *p) {
    extern double func_00119058(f32);
    extern void func_001843A0(void *);
    extern void func_00175700(void *);
    f32 o = p[0x5C / 4];
    p[0x34 / 4] += o;
    p[0x5C / 4] += p[0x68 / 4];
    p[0x38 / 4] += p[0x60 / 4];
    p[0x60 / 4] += p[0x6C / 4];
    if (func_00119058(o * p[0x5C / 4]) < 0.0) {
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}
