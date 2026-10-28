/* EE GCC 2.96: -O2 -G8.
 *
 * func_004044D0 is defined before func_004044E0 on purpose: GCC 2.96 treats a
 * call to a function it has already compiled as non-throwing, and only then
 * does reorg see $v0 dead after that call, giving retail's plain bne at +0xC8
 * (an extern callee leaves bnel there).
 */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 D_004C2410;

void func_004044D0(void) { D_004C2410 = 1; }

extern s32 func_003FA728(s32, s32, s32, u8 *, s32, s32, u8 *, s32, s32);
extern s32 func_003FB040(s32, s32, s32, u8 *, s32, u8 *, s32, s32, u8 *, s32, s32);

void func_004044E0(u8 *p)
{
    s32 r;
    if (*(s32 *)(p + 0xC) == 1)
        *(s32 *)(p + 0xC) = 2;
    if (*(s32 *)(p + 0xC) != 2)
        return;
    if (*(s32 *)(p + 0x14) == 1) {
        *(s32 *)(p + 0x10) = func_003FA728(*(s32 *)(p + 0x18), *(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), p + 0x28,
            *(s16 *)(p + 0x30), *(s16 *)(p + 0x32), p + 0x34, *(s16 *)(p + 0x36), *(s16 *)(p + 0x38));
    } else {
        r = func_003FB040(*(s32 *)(p + 0x18), *(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), p + 0x28,
            *(s32 *)(p + 0x24), p + 0x2C, *(s16 *)(p + 0x30), *(s16 *)(p + 0x32), p + 0x34, *(s16 *)(p + 0x36), *(s16 *)(p + 0x38));
        *(s32 *)(p + 0x10) = r;
        if (r % 2 == 1)
            func_004044D0();
    }
    *(s32 *)(p + 0xC) = 3;
}
