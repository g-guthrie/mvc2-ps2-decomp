#pragma padloop on
/* Ease toward the attached owner's position; release when animation ends. */
typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_003DAA40(u8 *);

void func_003C0B30(u8 *p)
{
    u8 *owner = *(u8 **)(p + 0xD8);
    float offset = 40.0f;
    if (*(short *)(owner + 0x140)) offset = -offset;
    {
        float y;
        offset += *(float *)(owner + 0x34);
        y = 342.85711669921875f + *(float *)(owner + 0x38);
        *(float *)(p + 0x34) = (offset + 3.0f * *(float *)(p + 0x34)) / 4.0f;
        *(float *)(p + 0x38) = (y + 3.0f * *(float *)(p + 0x38)) / 4.0f;
    }
    if ((s8)func_00175700(p) < 0) {
        p[0x13C] = 0;
        func_003DAA40(p);
    }
}
