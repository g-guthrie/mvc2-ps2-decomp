#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 func_001C1DA0(u8 *);
extern void func_001C18A0(u8 *);

void func_001C1780(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u8 *slot;
    u8 *flag;
    u16 code;
    u8 one;
    u8 *self;
    code = 0x1C02;
    self = p;
    n = 0x31;
    one = 1;
    self[4] = self[4] + 1;
    *(u16 *)(self + 0x26) = code;
    q = *(u8 **)(p + 0x18);
    slot = q + 0x2B8;
    flag = self + 0xD8;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(self + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    self[0x13C] = one;
    self[2] = q[2];
    self[1] = q[1];
    *(f32 *)(self + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(self + 0x54) = *(f32 *)(q + 0x54);
    self[0x1B7] = q[0x1B7];
    self[0x1B8] = q[0x1B8];
    *(s8 *)(self + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(self + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(self + 0x24) = *(s8 *)(q + 0x24);
    self[0x13C] = 0;
    *(s8 *)(self + 0x31) = -1;
    slot[0] = one;
    if (*flag == 0) {
        slot[0xA] = one;
        if (func_001C1DA0(self) != 0)
            *flag = 1;
    }
    func_001C18A0(self);
}
