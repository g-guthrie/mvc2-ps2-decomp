typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define B(o) (*(u8 *)(a + (o)))
#define SB(o) (*(s8 *)(a + (o)))
#define H(o) (*(s16 *)(a + (o)))
#define W(o) (*(s32 *)(a + (o)))

void func_002DBE80(u8 *a) {
    u8 *q;
    s32 t;
    s32 v;
    extern s8 func_00175700();
    extern void func_00184540(u8 *);
    extern void func_002DC1B0(u8 *);
    extern void func_00126400();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001D0D30(u8 *, s32);

    B(0x1FE) = 1;
    if ((B(0x20B) & 0x3F) == 0) {
        if (func_00175700(a) < 0) {
            if (B(0x20D) == 2) {
                func_00184540(a);
                return;
            }
            func_002DC1B0(a);
        } else if (SB(0x151) != 0) {
            *(s8 *)((s32)a + 0x151) = 0;
            q = *(u8 **)(a + 0x1DC);
            *(u8 **)(q + 0x1C8) = a;
            q[0x20A] = 0x10;
            q[0x1B5] = 0x20;
            B(0x1B5) = 0x20;
            v = SB(0x1E6) ^ 1;
            q[0x1E6] = v;
            *(s16 *)(q + 0x140) = (u8)v;
            func_00126400();
        }
    } else if (B(6) == 0) {
        func_00175700(a);
        t = H(0x1C);
        q = *(u8 **)(a + 0x1DC);
        t -= 1;
        H(0x1C) = t;
        if ((s16)t < 0) {
            t = B(6);
            B(6) = t + 1;
            *(u8 **)(q + 0x1C8) = a;
            q[0x20A] = 0x10;
            q[0x1B5] = 0x21;
            B(0x1B5) = 0x21;
            v = SB(0x1E6) ^ 1;
            q[0x1E6] = v;
            *(s16 *)(q + 0x140) = (u8)v;
            func_00126400();
            func_001757E0(a, 0xF, 2);
        } else {
            if (SB(0x151) != 0) {
                *(s8 *)((s32)a + 0x151) = 0;
                q[0x1B5] = 0x22;
                func_0018FDB0(a);
            }
            if (SB(0x150) != 0) {
                SB(0x150) = 0;
                func_001D0D30(a, 2);
            }
        }
    } else {
        if (func_00175700(a) < 0) {
            if (B(0x20D) == 2) {
                W(0x60) = 0;
                W(0x68) = 0;
                W(0x5C) = 0;
                W(0x6C) = 0xBF4DB6DB;
                func_00184540(a);
            } else {
                func_002DC1B0(a);
            }
        }
    }
}
