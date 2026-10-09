typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

/* Word 1 of data_u32_004C2500 is the runtime reference count. */
extern u32 D_004C2504;
/* Reinitialized when the runtime reference count returns to zero. */
extern u8 D_004C2B20[8];
extern void func_00411B28(void);
extern void *func_0011D8F8(void *destination, s32 value, u32 size);

void func_00411B98(void)
{
    if (D_004C2504 == 0)
        func_00411B28();
    D_004C2504++;
}

void func_00411BC8(void)
{
    u32 count = D_004C2504 - 1;

    D_004C2504 = count;
    if (count == 0)
    {
        func_00411B28();
        func_0011D8F8(D_004C2B20, 0, 8);
    }
}
