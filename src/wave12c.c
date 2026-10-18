typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


void func_001B50B0(u8 *a, u8 *b) {
    float y, c;
    s16 h;
    *(float *)(b + 0x34) = *(float *)(a + 0x34);
    y = *(float *)(a + 0x38);
    *(float *)(b + 0x38) = y;
    *(float *)(b + 0x38) += -137.142852783203125f;
    h = *(s16 *)(a + 0x140);
    *(s16 *)(b + 0x140) = h;
    c = 6.666666507720947f;
    if (h == 0) c = -c;
    *(float *)(b + 0x34) = *(float *)(b + 0x34) + c;
}
