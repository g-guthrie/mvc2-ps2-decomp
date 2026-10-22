typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G9890;
extern G9890 *D_004C2794;

void func_003C9890(u8 *a, u8 *b)
{
    extern s32 func_00175910(u8 *, s32, s32, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    extern void func_003C9850(u8 *, u8 *);
    extern void func_003C99C0(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    s32 v = *(s8 *)(b + 0x151);
    s8 c;
    u8 t;
    s32 x;
    if (v >= 0) {
        if (a[0x22] != v) {
            a[0x22] = v;
            func_00175910(a, 0x16, 3, a[0x22]);
            t = a[0x15B];
            c = t;
            if (c != 0) {
                if (t == 0x3C) {
                    x = b[0x269];
                    if (x > 3) {
                        if (x < 3) c = 0x2F;
                    }
                }
                a[0x1B5] = c;
                a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
                *(s32 *)(a + 0x1D8) = 0;
                D_004C2794->f7c[a[2]]++;
            }
            func_003C9850(a, b);
        }
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(a + 0x60);
        if (*(s8 *)(b + 0x1B2) == 0) {
            func_001E7F60(a);
            return;
        }
    } else {
        a[0xD9] = 0;
        a[5]++;
        func_001757E0(a, 0x16, 5);
        func_003C99C0(a, b);
    }
}
