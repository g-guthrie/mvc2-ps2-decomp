typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00175700(u8 *p);
extern s32 func_0024C590(u8 *p);
extern void func_00126400(void);

void func_0024C4F0(u8 *p) {
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    if (*(s8 *)(p + 0x151)) func_00175700(p);
    if (func_0024C590(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00126400();
    }
}
