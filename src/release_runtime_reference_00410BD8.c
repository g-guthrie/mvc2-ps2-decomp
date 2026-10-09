typedef unsigned int u32;

/* Word 1 of data_u32_00495BB0 is the runtime reference count. */
extern u32 D_00495BB4;
extern void func_00409698(void);

void func_00410BD8(void)
{
    u32 count = D_00495BB4 - 1;

    D_00495BB4 = count;
    if (count == 0)
        func_00409698();
}
