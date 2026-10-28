typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s8 f1c; } G36b;
extern G36b *D_004C2840;
typedef struct { s16 a[8]; } T36b;
extern T36b D_0044E680;

void func_001D7AB0(u8 *p, u8 *q) {
    extern int func_00175670(u8 *);
    extern s32 func_00174170();
    extern void func_001D7800(u8 *, u8 *);
    extern void func_001D7CD0(u8 *, u8 *);
    T36b tbl = D_0044E680;
    u8 *r = *(u8 **)(p + 0x88);
    if (*(s8 *)(r + 0x13C) == 0) {
        *(s8 *)(p + 0x13C) = 0;
        return;
    }
    if (p[0x20] == 0) {
        if (*(s32 *)(q + 0x2CC) == 0 || *(s32 *)(q + 0x2D0) == 0 ||
            *(s32 *)(p + 0xDC) != *(s32 *)(q + 0x2D4)) {
            goto err;
        }
        if (*(s16 *)(q + 0x160) <= 0) return;
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v >= 0) return;
        }
        {
            s32 t = *(s32 *)(p + 0xD8) + 1;
            *(s32 *)(p + 0xD8) = t;
            if (t >= 6) *(s32 *)(p + 0xD8) = 0;
        }
        {
            u8 idx = 0;
            u8 m = q[0x1E4];
            if (m == 0) idx = 2;
            if (m == 1) idx = 4;
            if (m == 6) idx = 6;
            if (*(s32 *)(p + 0xD8) == 5) idx++;
            *(s16 *)(p + 0x1C) = tbl.a[idx];
        }
        if (*(s32 *)(p + 0xDC) != 1 || *(s32 *)(p + 0xD8) == 1 || *(s32 *)(p + 0xD8) == 5) {
            func_001D7800(p, q);
        }
    } else {
        if ((s8)func_00175670(p) < 0) goto err;
        p[0x13C] = (p[0x22] + D_004C2840->f1c) & 1;
        if (*(s8 *)(p + 0x13C) == 0) return;
        *(s8 *)(p + 0x24) = 8;
        if (p[0x23] == 0) *(s8 *)(p + 0x24) = *(s8 *)(r + 0x24);
        if (*(s32 *)(q + 0xDC) != 1) return;
        *(s16 *)(p + 0x140) = func_00174170() & 1;
        *(s32 *)(p + 0x8C) = r[0x15A];
    }
    return;
err:
    func_001D7CD0(p, q);
}
