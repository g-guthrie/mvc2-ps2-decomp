typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x430];
    f32 f430;
} Q3BB;

extern f32 D_00474550[];

void func_003BB5B0(u8 *a)
{
    Q3BB *q = *(Q3BB **)(a + 0x18);
    extern void func_003BB910(u8 *);
    extern void func_003BB890(u8 *);
    extern void func_003BB8F0(u8 *);
    extern s32 func_003BD650();
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);

    if (*(s8 *)(a + 0x1B2) != 0) {
        u8 *r = *(u8 **)(a + 0x1C4);
        if (r[3] == 0) {
            s32 v;
            if (r[0x425] != 0 || ((v = r[1]) >= 0x18 && v < 0x1B)) {
                func_003BB910(a);
                return;
            }
            if (((s8)*(s8 *)(a + 0x1B2) & 0x7F) != 0) {
                func_003BB910(a);
            } else {
                func_003BB890(a);
            }
        } else {
            func_003BB910(a);
        }
    } else {
        f32 v;
        if (func_003BD650(a) != 0) {
            func_003BB8F0(a);
        } else {
            *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
            *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
            *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
            *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
            v = *(f32 *)(a + 0x38) - D_00474550[a[0x21]];
            if (!(q->f430 <= v)) {
                *(f32 *)(a + 0x38) = q->f430 - D_00474550[a[0x21]];
                func_003BB910(a);
            } else {
                func_00175700(a);
                func_001E7F60(a);
            }
        }
    }
}
