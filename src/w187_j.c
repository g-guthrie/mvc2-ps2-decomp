typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003A7B10(u8 *, u8 *, s16 *);
extern void func_003A7AF0(u8 *, u8 *);
extern s8 func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_003A75C0(u8 *a, u8 *b) {
    s16 *c;
    u32 t;
    if (*(u16 *)(b + 0x168) != *(u16 *)(a + 0xD0)) {
        c = (s16 *)(a + 0xD0);
        func_003A7B10(a, b, c);
        return;
    }
    c = (s16 *)(a + 0xD0);
    a[0x24] = (s8)b[0x24] + (s8)a[0x31];
    if ((s8)a[0x24] > 7) a[0x24] = 7;
    if ((s8)a[0x24] < 0) a[0x24] = 0;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(f32 *)(a + 0x34) += (f32)c[1];
    *(f32 *)(a + 0x38) += (f32)c[2];
    if (func_00175700(a) < 0) {
        t = a[4];
        a[4] = t + 1;
        func_003A7AF0(a, b);
    } else if (a[0x1B5] != 0xFF) {
        func_001E7F60(a);
    }
}
