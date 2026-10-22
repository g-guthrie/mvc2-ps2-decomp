typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

#define RESET_ACTION(p,code) do {u32 ca; (p)[0x1B5]=(code);(p)[0x1B2]=*(u16 *)((p)+0x1C0)=0;*(u32 *)((p)+0x1D8)=0;ca=(p)[2]*2;ca+=(u32)D_004C2794;ca+=0x7C;++*(s16 *)ca;}while(0)

void func_00392730(u8 *p, u8 *q) {
    extern s32 func_00174470(u8 *);
    extern void func_003928B0(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *r;
    u32 t;
    r = *(u8 **)(p + 0x14) + 0xD0;
    if (p[5] == 0) {
        if (q[5] != 0) {
            p[5]++;
            p[0x1B2] = 1;
        }
        if (*(s8 *)(p + 0x1B2) != 0) {
            r[2] = 1;
            r[3] = 8;
            p[0x1B2] = 0;
        }
        if (*(s8 *)(r + 3) != 0) {
            p[0x1B0] = 0;
        } else if (*(s8 *)(r + 2) < 0) {
            t = p[5];
            p[5] = t + 1;
        } else {
            p[0x1B0] = 0x42;
            if (*(s8 *)(r + 4) != 0) {
                RESET_ACTION(p, 0x5E);
            } else {
                RESET_ACTION(p, 0x53);
            }
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(s16 *)(p + 0x1C) -= 1;
    p[0x13C] = 1;
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
        if (*(s16 *)(p + 0x1C) < 0) {
            func_003928B0(p);
            return;
        }
    }
    func_001E7F60(p);
}

void func_003923D0(u8 *p, u8 *q) {
    extern s32 func_00174470(u8 *);
    extern void func_003928B0(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *r;
    s32 t;
    s16 h;
    r = *(u8 **)(p + 0x14) + 0xD0;
    if (*(s8 *)(r + 2) > 0) {
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h <= 0) {
            *(s8 *)(r + 2) = -1;
        } else {
            r[2] = 0;
            if (*(s16 *)(p + 0x1E) < 3) r[4] = 1;
        }
    }
    if (*(s8 *)(r + 3) != 0) {
        t = *(s8 *)(r + 3);
        r[3] = t - 1;
    }
    if (p[5] == 0) {
        if (q[5] != 0) {
            p[5]++;
            p[0x1B2] = 1;
        }
        if (*(s8 *)(p + 0x1B2) != 0) {
            r[2] = 1;
            r[3] = 8;
            p[0x1B2] = 0;
        }
        if (*(s8 *)(r + 3) != 0) {
            p[0x1B0] = 0;
        } else if (*(s8 *)(r + 2) < 0) {
            t = p[5];
            p[5] = t + 1;
        } else {
            p[0x1B0] = 0x42;
            if (*(s8 *)(r + 4) != 0) {
                RESET_ACTION(p, 0x5E);
            } else {
                RESET_ACTION(p, 0x53);
            }
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(s16 *)(p + 0x1C) -= 1;
    p[0x13C] = 1;
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
        if (*(s16 *)(p + 0x1C) < 0) {
            func_003928B0(p);
            return;
        }
    }
    func_001E7F60(p);
}
