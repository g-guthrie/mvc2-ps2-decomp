typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_003A0190(void);
void func_003A0110(u8 *p)
{
    u32 i = 0;
    do {
        u8 *v = func_003DA750(0, 1, 0);
        if (v != 0) {
            *(void **)(v + 0x10) = func_003A0190;
            *(u8 **)(v + 0x18) = p;
            *(s16 *)(v + 0x26) = 0x2A03;
            v[1] = p[1];
        }
        i++;
    } while (i < 2);
}
