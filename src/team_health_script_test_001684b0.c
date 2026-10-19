#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004F20B0[];
extern void func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_00166C80(u8 *, u8 *, s32);

/* Compare the script value against the three interleaved team slots. */
s32 func_001684B0(u8 *owner, u8 *script)
{
    u8 *slot;
    s32 health, i;

    func_0016B0C0(owner, script, 0);
    func_0016B0C0(owner, script, 2);
    slot = D_004F20B0 + owner[2] * 0x5B8;
    health = 0;
    i = 0;
    do {
        health += *(s16 *)(slot + 0x434);
        slot += 0xB70;
        ++i;
    } while (i < 3);
    health = (health * 144) / 200;
    i = (*(s32 *)(owner + 0x4C8) * 144) / 200;
    return func_00166C80(owner, script, health <= i);
}

/* Compare the script value against the three opposing interleaved team slots. */
s32 func_001685A0(u8 *owner, u8 *script)
{
    u8 *slot;
    s32 health, i;

    func_0016B0C0(owner, script, 0);
    func_0016B0C0(owner, script, 2);
    slot = D_004F20B0 + (owner[2] ^ 1) * 0x5B8;
    health = 0;
    i = 0;
    do {
        health += *(s16 *)(slot + 0x434);
        slot += 0xB70;
        ++i;
    } while (i < 3);
    health = (health * 144) / 200;
    i = (*(s32 *)(owner + 0x4C8) * 144) / 200;
    return func_00166C80(owner, script, health <= i);
}
