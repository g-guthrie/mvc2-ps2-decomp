typedef signed int s32;
typedef unsigned int u32;

extern s32 D_004C22A0;
extern s32 D_004C22A4;
extern s32 func_00411858(u32 callback_address, u32 context_address);

s32 func_003FB108(u32 callback_address, u32 context_address)
{
    D_004C22A0 = (s32)callback_address;
    D_004C22A4 = (s32)context_address;
    return func_00411858(callback_address, context_address);
}
