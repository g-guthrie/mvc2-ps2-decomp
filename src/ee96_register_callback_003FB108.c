typedef signed int s32;
/* func_003FB128 invokes a registered callback with (context, buffer); it ignores V0. */
typedef void (*Callback)(void *context, void *buffer);

extern Callback D_004C22A0;
extern void *D_004C22A4;
extern s32 func_00411858(Callback callback, void *context);

s32 func_003FB108(Callback callback, void *context)
{
    D_004C22A0 = callback;
    D_004C22A4 = context;
    return func_00411858(callback, context);
}
