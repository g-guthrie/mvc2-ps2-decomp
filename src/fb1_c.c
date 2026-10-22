typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004B33C0[6];

static void func_001450C0(u8 *p) {
    f32 *b = &D_004B33C0[3];
    *(f32 *)(p + 0x34) = D_004B33C0[0] + (f32)*(s16 *)(p + 0x1C) * (b[0] - D_004B33C0[0]) / 20.0f;
    *(f32 *)(p + 0x38) = D_004B33C0[1] + (f32)*(s16 *)(p + 0x1C) * (b[1] - D_004B33C0[1]) / 20.0f;
    *(f32 *)(p + 0x3C) = D_004B33C0[2] + (f32)*(s16 *)(p + 0x1C) * (b[2] - D_004B33C0[2]) / 20.0f;
}

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0xC]; s16 h; } G145;
extern G145 *D_004C2840;

void func_00145F30(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    func_001450C0(p);
    if (*(s16 *)(p + 0x1C) == 0x14) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(V3 *)(p + 0x34) = *(V3 *)&D_004B33C0[3];
        *(s32 *)(p + 0xDC) = D_004C2840->h;
        p[6] = 1;
    }
}
