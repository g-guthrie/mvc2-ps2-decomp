typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x7C];
    s16 f7c[16];
} G;

extern G *D_004C2794;
extern u8 D_004C01D0[8];

void func_00237680(u8 *a, u8 *b)
{
    extern s32 func_00237CD0(u8 *, u8 *);
    extern s32 func_00237BC0(u8 *, u8 *);
    extern s8 func_00175700(u8 *);
    extern s32 func_00174170(void);
    extern u8 func_00237E40(u8 *, u8 *);
    extern s32 func_00237B70(u8 *, u8 *, s32);
    extern void func_00237D40(u8 *, s32);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_00126400(void);
    s32 m;
    s32 t2;
    s32 val;
    u8 arg;
    u32 t;
    f32 zero;

    a[0x40C] = 2;
    a[0x33C] = 5;
    if (b[0x1C] == 0) {
        if (func_00237CD0(a, b) == 0) {
            b[0x1B] &= 0xFC;
        }
    } else {
        if (func_00237BC0(a, b) == 0) {
            b[0x1B] &= 0xF3;
        }
    }
    if (func_00175700(a) >= 0) {
        return;
    }
    if (*(u8 *)(*(u32 *)(b + 0x20) + 5) == 3 && b[0x19] != 0 && --b[0x16] != 0) {
        if ((*(s8 *)(a + 0x1B2) != 0 && --b[0x18] == 0) || b[0x1A] != 0) {
            b[0x1A] = (0x7FFF >> (func_00174170() & 0xF)) & 1;
            b[0x1E] = a[0x22];
            a[0x22] = func_00237E40(a, *(u8 **)(b + 0x20));
            t2 = (D_004C01D0[((a[0x22] + 4) & 0x3F) >> 3] & (m = b[0x1B])) & 0xFF;
            if (t2 == m) {
                goto L81C;
            }
            a[0x22] = b[0x1E];
        }
        if ((b[0x1B] & 3) != 0) {
            if (func_00237B70(a, b, 0x30) != 0) {
                goto L81C;
            }
        }
        if ((b[0x1B] & 0xC) != 0) {
            func_00237B70(a, b, 0x10);
        }
L81C:
        func_00237D40(a, a[0x22]);
        val = (a[0x22] >> 3) + 0x4D;
        arg = 0;
        if (b[0x18] == 0) {
            val = 0x5D;
            arg = 0x20;
        }
        a[0x1B5] = val;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(u32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        *(u16 *)(a + 0x1C0) = arg;
        t = a[7];
        a[7] = t - 1;
        *(s16 *)(a + 0x1C) = 0x1E;
        b[0x17] = 5;
        b[0x1D] = b[0x1B];
        b[0x1C] = 0;
        b[0x1B] = 0;
        func_001757E0(a, 0x16, (((a[0x22] + 2) & 0x3F) >> 2) + 0xC);
        return;
    }
    a[0x40D] = 0;
    a[0x40C] = 0;
    a[0x33B] = 0;
    a[0x33C] = 0;
    t = a[6];
    a[6] = t + 1;
    a[7] = 0;
    a[0x20D] = 2;
    *(u16 *)(a + 0x140) = b[0x1F];
    a[0x1E6] = b[0x1F];
    b[0x18] = 0;
    func_00126400();
    if (b[0x1C] == 0) {
        zero = 0.0f;
        *(f32 *)(a + 0x5C) = *(f32 *)(a + 0x5C) / 16.0f;
        *(f32 *)(a + 0x68) = zero;
        *(u32 *)(a + 0x60) = 0x41AB6DB6;
        *(u32 *)(a + 0x6C) = 0xBF700000;
        if ((b[0x1B] & 8) != 0) {
            *(f32 *)(a + 0x60) = zero;
        }
        func_001757E0(a, 0x16, 2);
    } else {
        f32 v = *(f32 *)(a + 0x5C) / 16.0f;
        *(f32 *)(a + 0x5C) = -v;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x412B6DB6;
        *(u32 *)(a + 0x6C) = 0xBF700000;
        func_001757E0(a, 0x16, 3);
    }
}
