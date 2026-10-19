typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2794;
extern s32 func_003D6850(s32, s32, s32);
extern void func_003D72F0(void);

void func_003D68B0(s8 *a0, s32 a1)
{
    s8 n = (s8)(a0[0x2C] - 1);
    if (a0[0x1A] == 0) {
        *(s16 *)(a0 + 0x2A) = 0;
        if (*(s16 *)(a0 + 0xA) != 0)
            *(s16 *)(a0 + 0xA) -= 1;
        else
            a0[0x1A] += 1;
    } else {
        u8 *row = D_004C2794 + n * 12;
        s16 cnt = *(u8 *)(*(s32 *)(*(s32 *)(row + 0x18) + 0x1AC));
        s32 flags = func_003D6850(n, a1, cnt);
        s16 slot = *(s16 *)(a0 + 0x2A);
        if (flags & 0x2000)
            slot -= 1;
        if (flags & 0x1000)
            slot += 1;
        *(s16 *)(a0 + 0x2A) = (s16)((slot + cnt) % cnt);
    }
    func_003D72F0();
}
