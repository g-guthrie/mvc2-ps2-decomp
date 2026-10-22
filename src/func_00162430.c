typedef unsigned char u8;
typedef signed int s32;

extern void func_00152550(void *, void (*)(u8 *));
extern void func_00162610(u8 *);

void func_00162430(u8 *p) {
    p[0x13C] = 1;
    p[4]++;
    *(s32 *)(p + 0x64) = 0xC2B40000;
    *(s32 *)(p + 0x70) = 0xC1200000;
    func_00152550(p, func_00162610);
}
