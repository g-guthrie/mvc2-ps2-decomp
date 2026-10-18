typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C1380[2];
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
void func_002FA020(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
    case 1:
        p[0x168] = 1;
        *(u8 **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x14);
        break;
    case 2:
        p[0x168] = 2;
        *(u8 **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x16);
        break;
    }
    func_001757E0(p, 0x16, p[0x168]);
}
