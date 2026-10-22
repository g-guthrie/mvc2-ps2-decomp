typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[0x31]; } B7d;
typedef struct { f32 x, y, z; } V7d;

#define Q (*(u8 **)(q + 0x1DC))

void func_001D40F0(u8 *p, u8 *q) {
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_003DAA40();
    extern void func_00175670(u8 *);
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001D3E60();
    extern s32 func_00174170(void);
    u8 *o;
    s32 i;
    if (p[4] == 0) {
        s32 t;
        p[4] = p[4] + 1;
        *(B7d *)(p + 0xEC) = *(B7d *)(Q + 0xEC);
        p[0x13C] = 1;
        p[2] = Q[2];
        p[1] = Q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(Q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(Q + 0x54);
        p[0x1B7] = Q[0x1B7];
        p[0x1B8] = Q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(Q + 0x30);
        *(V7d *)(p + 0x50) = *(V7d *)(Q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(Q + 0x24);
        func_001754A0(p, 0x1B, (u8)(p[0x20] + 5));
        *(s16 *)(p + 0x1C) = 0x12C;
        p[0x13C] = 0;
        t = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = t;
        if (t != 0) {
            *(s32 *)(p + 0xD0) = -*(s32 *)(p + 0xD0);
        }
        *(s8 *)(p + 0x31) = -1;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        if (q[0x23E] != 0) {
            func_003DAA40();
            return;
        }
        if (q[5] == 3 || q[5] == 2) {
            f32 a, b;
            p[0x13C] = 1;
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.666666627f * (f32)*(s32 *)(p + 0xD0);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857075f * (f32)*(s32 *)(p + 0xD4);
            func_00175670(p);
        } else {
            i = 0;
            do {
                s32 r;
                if ((o = func_003DA750(0, 3, 0)) == 0) break;
                *(void **)(o + 0x10) = (void *)func_001D3E60;
                o[0x20] = (func_00174170() & 7) + 0x80;
                o[0x21] = 0;
                *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
                o[1] = Q[1];
                *(s16 *)(o + 0x26) = 0x2C02;
                *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
                *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
                *(s32 *)(o + 0x68) = 0;
                *(u32 *)(o + 0x6C) = 0xBE092492;
                r = ((func_00174170() & 0x7F) - 0x40) << 12;
                *(f32 *)(o + 0x5C) = 1.666666627f * (f32)r / 65536.0f;
                r = ((func_00174170() & 0x2F) - 0x20) << 12;
                *(f32 *)(o + 0x60) = 2.142857075f * (f32)-r / 65536.0f;
                i++;
            } while (i < 2);
            func_003DAA40(p);
        }
    }
}
