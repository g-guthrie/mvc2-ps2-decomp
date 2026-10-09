typedef signed int s32;
/* func_003FB128 passes its text buffer as the callback argument; V0 is ignored. */
typedef void (*Callback)(void *context, void *argument);

/* These dispatchers ignore A0, forward A1, and have no observed result consumers. */
extern void func_00411288(void *unused, void *argument);
extern void func_004112B0(void *unused, void *argument);
extern s32 func_00409810(void);
extern s32 func_003FE9E8(void *context);
extern s32 func_00411858(Callback callback, void *context);
extern s32 func_003FB108(Callback callback, void *context);

void func_003FE9B0(void *unused, void *argument) { func_00411288(unused, argument); }
void func_003FECF8(void *unused, void *argument) { func_00411288(unused, argument); }
void func_003FE9C8(void *unused, void *argument) { func_004112B0(unused, argument); }
void func_003FED10(void *unused, void *argument) { func_004112B0(unused, argument); }
void func_004086B8(void *unused, void *argument) { func_004112B0(unused, argument); }
s32 func_00410F68(void) { return func_00409810(); }
s32 func_00402818(Callback callback, void *context) {
    return func_003FB108(callback, context);
}
s32 func_003FEAB8(void *context) { return func_003FE9E8(context); }
s32 func_003FE5C0(Callback callback, void *context) {
    return func_00411858(callback, context);
}
