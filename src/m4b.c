typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00186A60(void *p, s32 n);
void func_0021B590(u8 *p) {
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
