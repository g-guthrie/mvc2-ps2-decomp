typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

void func_00152560(u8 *p)
{
    (*(DispatchFn *)(p + 0x28))(p);
}
