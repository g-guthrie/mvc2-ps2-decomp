typedef signed int s32;
typedef s32 (*Callback)(void *context);

extern s32 func_00411288(void);
extern s32 func_004112B0(void);
extern s32 func_00409810(void);
extern s32 func_003FE9E8(void *context);
extern s32 func_00411858(Callback callback, void *context);
extern s32 func_003FB108(Callback callback, void *context);

s32 func_003FE9B0(void) { return func_00411288(); }
s32 func_003FECF8(void) { return func_00411288(); }
s32 func_003FE9C8(void) { return func_004112B0(); }
s32 func_003FED10(void) { return func_004112B0(); }
s32 func_004086B8(void) { return func_004112B0(); }
s32 func_00410F68(void) { return func_00409810(); }
s32 func_00402818(Callback callback, void *context) {
    return func_003FB108(callback, context);
}
s32 func_003FEAB8(void *context) { return func_003FE9E8(context); }
s32 func_003FE5C0(Callback callback, void *context) {
    return func_00411858(callback, context);
}
