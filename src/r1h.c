typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;typedef signed int s32;
extern void (*D_0044C040[])(u8 *, u8 *);
extern s32 func_001BB8D0(u8 *a, u8 *b);
s32 func_001BB0D0(u8 *a, u8 *b) { D_0044C040[a[4]](a, b); if (a[1] != b[1]) { return func_001BB8D0(a, b); } }
