typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

void func_0034C3C0(u8 *p) {
    extern void (*D_004C1A18[2])(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    if (o[0x1E4] != 0x1D || o[0x1FD] != 5) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        D_004C1A18[p[0x20]](p);
    }
}

void func_0013C910(u8 *p) {
    extern u8 D_004B1298[];
    extern s32 D_004C2830;
    if (*(*(u8 **)(p + 0x18) + 4) >= 3) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (*(s16 *)(p + 0x1E) <= 0) {
            u32 t;
            *(s16 *)(p + 0x1E) = 4;
            t = p[0x22];
            p[0x22] = t + 1;
            if (p[0x22] > 5) p[0x22] = 0;
            *(s16 *)(p + 0xCC) = D_004B1298[p[0x22]];
            *(s32 *)(p + 0x84) = D_004C2830;
        }
    }
}
