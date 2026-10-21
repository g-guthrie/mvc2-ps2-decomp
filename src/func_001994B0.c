typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void *func_003DA750(void *, s32, s32);
extern void func_001996B0(u8 *);

void func_001994B0(u8 *p)
{
    u8 *child;
    s32 i;
    child = func_003DA750(0, 3, 0);
    if (child != 0) {
        *(void (**)(u8 *))(child + 0x10) = func_001996B0;
        *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
        *(u8 **)(child + 0x14) = p;
        child[0x20] = 1;
        child[0x21] = 0;
        child[0x22] = 0;
        *(u16 *)(child + 0x26) = 0x501;
    }
    child = func_003DA750(0, 3, 0);
    if (child != 0) {
        *(void (**)(u8 *))(child + 0x10) = func_001996B0;
        *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
        *(u8 **)(child + 0x14) = p;
        child[0x20] = 1;
        child[0x21] = 1;
        child[0x22] = 1;
        *(u16 *)(child + 0x26) = 0x501;
    }
    i = 0;
    do {
        child = func_003DA750(0, 3, 0);
        if (child != 0) {
            *(void (**)(u8 *))(child + 0x10) = func_001996B0;
            *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(child + 0x14) = p;
            child[0x20] = 2;
            child[0x21] = i;
            child[0x22] = 0;
            *(u16 *)(child + 0x26) = 0x501;
        }
        child = func_003DA750(0, 3, 0);
        if (child != 0) {
            *(void (**)(u8 *))(child + 0x10) = func_001996B0;
            *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(child + 0x14) = p;
            child[0x20] = 2;
            child[0x21] = i;
            child[0x22] = 1;
            *(u16 *)(child + 0x26) = 0x501;
        }
        i++;
    } while (i <= 0);
    i = 0;
    do {
        child = func_003DA750(0, 3, 0);
        if (child != 0) {
            *(void (**)(u8 *))(child + 0x10) = func_001996B0;
            *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(child + 0x14) = p;
            child[0x20] = 3;
            child[0x21] = i;
            child[0x22] = 0;
            *(u16 *)(child + 0x26) = 0x501;
        }
        child = func_003DA750(0, 3, 0);
        if (child != 0) {
            *(void (**)(u8 *))(child + 0x10) = func_001996B0;
            *(u8 **)(child + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(child + 0x14) = p;
            child[0x20] = 3;
            child[0x21] = i;
            child[0x22] = 1;
            *(u16 *)(child + 0x26) = 0x501;
        }
        i++;
    } while (i < 3);
}
