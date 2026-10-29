typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0041CEB0(u8 a)
{
    if (a > 0x38) {
        return -1;
    }
    if (a >= 0x18) {
        return a + 3;
    }
    return a;
}

extern s32 func_00104990(s32);
void func_003F0470(void)
{
    while ((func_00104990(2) | func_00104990(1)) != 0) {
        __asm__("nop;nop;nop;nop;nop;nop");
    }
}

typedef struct { u8 pad[0x2C]; s16 h; u8 pad2[18]; } E64;
extern E64 D_006207A0[];
extern s32 func_003EA130(void *);
s32 func_003EA070(u32 a)
{
    E64 *p = &D_006207A0[a - 1];
    if (a > 0x180) {
        return 0;
    }
    if (p->h != 0) {
        return func_003EA130(p);
    }
    return 0;
}
