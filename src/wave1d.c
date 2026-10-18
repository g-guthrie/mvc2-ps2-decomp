typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_001845F0(u8 *);

u32 func_001879C0(u8 *a0)
{
    if (*(float *)(a0 + 0x38) - *(float *)(a0 + 0x430) < 68.57142639f) {
        *(float *)(a0 + 0x38) = *(float *)(a0 + 0x430);
        return 0;
    }
    func_001845F0(a0);
    return 1;
}

void func_00380A40(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x1C4);
    *(float *)(a0 + 0x34) = *(float *)(p + 0x34);
    *(float *)(a0 + 0x38) = *(float *)(p + 0x38) + 2.14285707474f * (float)(*(u8 *)(p + 0x14C) / 2);
}
