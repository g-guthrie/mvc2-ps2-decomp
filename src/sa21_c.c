typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
static void func_001CB680(u8 *p, u8 *o)
{
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3 *)(p + 80) = *(V3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}
extern void func_001754A0(u8 *, s32, s32);
extern void func_003DAA40(u8 *);
extern void func_001E3210(u8 *, s32);
extern s8 func_00175670(u8 *);
void func_001CB7C0(u8 *a, u8 *b) {
    u32 t;
    s32 w;
    if (a[4] == 0) {
        func_001CB680(a, b);
        func_001754A0(a, 0x1B, 0x21);
        *(s32 *)(a + 0xD0) = -1;
        *(s8 *)(a + 0x31) = -1;
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x430);
        a[0x24] = 0xB;
    }
    if (a[5] == 0) {
        if (b[0x425] != 0) {
            a[5] = 1;
            func_001754A0(a, 0x1B, 0x24);
            return;
        }
        if (b[5] == 3) {
            func_003DAA40(a);
        } else {
            w = *(s32 *)(b + 0x304);
            if (w != *(s32 *)(a + 0xD0)) {
                if (w == 0x24) a[5] = a[5] + 1;
                *(s32 *)(a + 0xD0) = *(s32 *)(b + 0x304);
                func_001754A0(a, 0x1B, a[0xD0]);
            } else {
                if (*(s8 *)(a + 0x151) != 0) {
                    a[0x151] = 0;
                    func_001E3210(b, 0x23);
                }
                func_00175670(a);
            }
        }
    } else {
        if (func_00175670(a) < 0) {
            t = a[4];
            a[4] = t + 1;
            a[0x13C] = 0;
        }
    }
}
