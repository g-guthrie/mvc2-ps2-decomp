typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_003AE8A0(void *);

void func_003ADF90(u8 *p) {
    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(*(u8 **)(p + 0x18) + 0x1DC) + 0x24);
    *(s8 *)(p + 0x31) = -1;
    switch (p[4]) {
    case 0:
    case 1:
        p[0x13C] = 1;
        break;
    case 2:
    case 3:
    default:
        func_003AE8A0(p);
        break;
    }
}
