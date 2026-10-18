typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
extern GA *D_004C2794;
typedef struct { u8 pad[0x1C]; s32 f1c; } GB;
extern GB *D_004C2840;
extern f32 D_004B8330[];
extern s8 D_004B8348[];

static inline void reset_command(u8 *p, u8 command) {
    *(volatile u8 *)(p + 0x1b5) = command;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(s32 *)(p + 0x1d8) = 0;
    D_004C2794->f7c[p[2]]++;
}

extern u8 D_00459630[];
extern u16 D_00459632[];
extern f32 D_004F1F4C[];

void func_002BD190(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    u8 idx;
    u16 h;
    u8 c;
    *(s16 *)(p + 0x1E) = 0;
    idx = p[0x22];
    h = 0;
    if (idx > 0x10) {
        p[0x1E6] = *(s16 *)(p + 0x140) = 0;
        idx = ((s8)idx ^ 0x1F) + 1;
    } else {
        p[0x1E6] = *(s16 *)(p + 0x140) = 1;
    }
    if (*(f32 *)(*(u8 **)(p + 0x220) + 0x34) <= D_004F1F4C[0]) {
        h ^= 9;
    }
    if (p[0x1E6] != 0) {
        h ^= 9;
    }
    h += D_00459632[idx * 2];
    if ((c = q[0xC]) != 0) {
        if (c == 1) {
            reset_command(p, 0x5D);
        } else {
            reset_command(p, h);
        }
    }
    func_001757E0(p, 0x16, D_00459630[idx * 4]);
}
