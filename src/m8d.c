typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FCC;
extern f32 D_004F1FC8;
extern s32 func_00118FA8(f32 x);

void func_001DEE30(u8 *p) {
    s16 *q = (s16 *)(p + 0xD8);
    if (*(s16 *)(p + 0x140) == 0) {
        q[1] = func_00118FA8(D_004F1FCC);
    } else {
        q[1] = func_00118FA8(D_004F1FC8);
    }
    if ((f32)q[0] > 586.6666259765625f) {
        q[0] = 0x24A;
    }
}
