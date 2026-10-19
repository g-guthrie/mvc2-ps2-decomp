typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_0018CEA0(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_00176980(u8 *p) {
    if (p[6] == 0) {
        p[6]++;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
    } else {
        func_0018CEA0(p);
        if (func_00175700(p) < 0)
            func_001843A0(p);
    }
}
