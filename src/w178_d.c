typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[49]; } S49_1C8DE0;
typedef struct { f32 x, y, z; } V3_1C8DE0;
extern s8 D_004BFA48[8];
extern s8 D_004BFA44[8];
static void func_001C8D60(u8 *p) {
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) {
        *(float *)(p + 0x34) = *(float *)(p + 0x34) +
                               1.6666666f * (float)D_004BFA44[p[0x20]];
    }
    ((s8 *)p)[0x24] = ((s8 *)*(u8 **)(p + 0x18))[0x24];
    ((s8 *)p)[0x31] = -1;
}

void func_001C8DE0(u8 *p) {
    extern void func_001757E0();
    p[4]++;
    *(S49_1C8DE0 *)(p + 0xEC) = *(S49_1C8DE0 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3_1C8DE0 *)(p + 0x50) = *(V3_1C8DE0 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24) + 8;
    *(s16 *)(p + 0x140) = 0;
    func_001C8D60(p);
    func_001757E0(p, 0x17, D_004BFA48[p[0x20]]);
}

