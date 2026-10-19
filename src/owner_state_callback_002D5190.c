typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);

void func_002D5190(u8 *p)
{
    u32 counterOffset;
    u8 state;

    p[6]++;
    func_001757E0(p, 0x15, 0x15);
    if (p[0x269] == 3) {
        state = 0x4C;
        p[0x1B5] = state;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        counterOffset = p[2] * 2;
        counterOffset += (u32)D_004C2794;
        counterOffset += 0x7C;
        ++*(s16 *)counterOffset;
    } else {
        state = 8;
        p[0x1B5] = state;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        counterOffset = p[2] * 2;
        counterOffset += (u32)D_004C2794;
        counterOffset += 0x7C;
        ++*(s16 *)counterOffset;
    }
}
