typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef unsigned long long u64;
extern void func_00186A60();
void func_0021B610(u8 *p) {
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        p[0x22] = 2;
        if (p[0x1E6] == 0) p[0x22] = 6;
        break;
    }
    func_00186A60(p, 0x15);
}

extern void func_0033F3C0();
extern void func_0033F560();
extern void func_0033F890();
#pragma padloop on
void func_0033FA20(void) {
    s32 i = 0;
    do { func_0033F3C0(i); i++; } while (i < 2);
    i = 0;
    do { func_0033F560(i); i++; } while (i < 2);
    func_0033F890();
}
#pragma padloop off
