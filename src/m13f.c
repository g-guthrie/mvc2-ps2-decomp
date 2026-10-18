typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} V4;

extern s8 D_004F7F30;
extern s8 D_004F7F32;
extern V4 D_00476B70;
extern V4 D_00476B60;
extern void func_003DAA40(u8 *);

void func_003D0940(u8 *p) {
    if (D_004F7F30 != 2) {
        func_003DAA40(p);
    } else {
        V4 *q = (V4 *)(p + 0x74);
        *(V4 *)(p + 0x74) = D_00476B70;
        if (D_004F7F32 == p[0x20]) {
            *q = D_00476B60;
        }
    }
}
