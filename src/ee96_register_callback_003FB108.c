typedef signed int s32;
typedef s32 (*Callback)(void *context);

extern s32 D_004C22A0;
extern s32 D_004C22A4;
extern s32 func_00411858(Callback callback, void *context);

s32 func_003FB108(Callback callback, void *context)
{
    D_004C22A0 = (s32)callback;
    D_004C22A4 = (s32)context;
    return func_00411858(callback, context);
}
