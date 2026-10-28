typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct P {
    u8 pad0[0x1C];
    s16 h1c;
    u8 pad1[0x40 - 0x1E];
    u32 w40;
    u32 w44;
    u8 pad2[0x54 - 0x48];
    f32 f54;
    u8 pad3[0xD4 - 0x58];
    s32 wd4;
} P;

s32 func_00333950(P *p) {
    p->h1c += 1;
    p->w44 += (u16)((u32)(s32)(0.5 + 65536.0 * (double)(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}

s32 func_00332580(P *p) {
    p->h1c += 1;
    p->w40 += (u16)((u32)(s32)(0.5 + 65536.0 * (double)(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}

s32 func_003333C0(P *p) {
    p->h1c += 1;
    p->w40 += (u16)((u32)(s32)(0.5 + 65536.0 * (double)(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}
