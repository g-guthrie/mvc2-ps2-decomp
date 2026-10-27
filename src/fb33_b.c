struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V33;
typedef struct { u8 pad[6]; u8 b6; } G33b;
extern G33b *D_004C2794;
extern u8 D_004D18A6[];

#define TAIL33 \
    if (D_004C2794->b6 == 0) {\
        p[4] += 1;\
        p[0x13C] = 0;\
    }\
    if (D_004D18A6[0] == 0) {\
        p[0x13C] = 0;\
        func_003DAA40((struct Object *)p);\
    }

void func_00135B70(u8 *p) {
    extern void func_003DAA40(struct Object *);
    s16 v;
    if (p[0x20] == 0) {
        if (p[5] == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x50) -= 0.0666666701436043f;
            *(f32 *)(p + 0x54) -= 0.0666666701436043f;
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v <= 0) {
                p[5] += 1;
                *(f32 *)(p + 0x5C) /= 20.0f;
                *(s16 *)(p + 0x1C) = 4;
            }
        } else {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            *(s16 *)(p + 0x1C) = 4;
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        }
        TAIL33
        }
    } else {
        if (p[5] == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
            *(f32 *)(p + 0x50) -= 0.100000001490116f;
            *(f32 *)(p + 0x54) -= 0.100000001490116f;
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v <= 0) {
                p[5] += 1;
                *(f32 *)(p + 0x50) = 1.0f;
                *(f32 *)(p + 0x54) = 1.0f;
                *(V33 *)(p + 0x34) = *(V33 *)(p + 0x68);
            }
        }
        TAIL33
    }
}
