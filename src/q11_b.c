typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_001E3710(void *p, s32 n);
extern void func_001757E0(void *p, s32 a, s32 b);
extern u8 D_004C1380[4];

void func_002FA150(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
    case 1:
        p[0x168] = 5;
        *(u8 **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x14);
        break;
    case 2:
        p[0x168] = 6;
        *(u8 **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x16);
        break;
    }
    func_001757E0(p, 0x16, p[0x168]);
    {
        s8 a = *(s8 *)(p + 0x1EA);
        if ((a & 0xF) != 0) {
            p[0x1EA] = a - 1;
        }
    }
}

