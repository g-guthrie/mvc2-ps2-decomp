typedef unsigned char u8;
typedef signed int s32;
extern void func_003DAA40(u8 *);
#pragma padloop on
void func_001D2610(u8 *p) {
    u8 *n = *(u8 **)(p + 0xC);
    s32 i = 0;
    do {
        func_003DAA40(n);
        n = *(u8 **)(n + 0xC);
        i++;
    } while (i < 12);
    func_003DAA40(p);
}
