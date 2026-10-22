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
#define F(o) (*(f32 *)(a + (o)))
#define W(o) (*(s32 *)(a + (o)))

typedef struct { u8 pad[0x5C]; f32 f5C; } Q5C;
extern f32 func_00117078(f32);

void func_002A4A00(u8 *a) {
    f32 *v5C, *v68;
    u8 *q;
    f32 f, g;
    u32 t;
    extern void func_00175700();
    extern s32 func_00185980(u8 *);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);

    B(0x40C) = 2;
    B(0x33C) = 5;
    func_00175700(a);
    v5C = (f32 *)(a + 0x5C);
    v68 = (f32 *)(a + 0x68);
    F(0x34) += F(0x5C);
    F(0x5C) += F(0x68);
    if (SB(0x1B2) != 0) {
        if (func_00185980(a) != 0) {
            t = B(6);
            B(6) = t + 1;
            func_00185490(a);
            (*(u8 **)(a + 0x1C4))[0x1B4] = 0x20;
            (*(u8 **)(a + 0x1C4))[0x20D] = 0;
            q = *(u8 **)(a + 0x1C4);
            *(f32 *)(q + 0x38) = *(f32 *)(q + 0x430);
            q = *(u8 **)(a + 0x1C4);
            g = *(f32 *)(q + 0x34);
            if (B(0x1E6) != 0) {
                f = -93.33332824707031f;
            } else {
                f = 93.33332824707031f;
            }
            F(0x34) = g + f;
            func_001757E0(a, 0x16, 1);
            return;
        }
        B(6) = 6;
        B(0x20D) = 2;
        B(0x40D) = 0;
        B(0x40C) = 0;
        B(0x33B) = 0;
        B(0x33C) = 0;
        *v5C = 0;
        *v68 = 0;
        W(0x60) = 0x41CDB6DB;
        W(0x6C) = 0xBFF00000;
        func_001757E0(a, 0x16, 2);
    } else {
        s16 h = H(0x1C) - 1;
        H(0x1C) = h;
        if (h == 0) {
            B(6) = 7;
            B(0x40D) = 0;
            B(0x40C) = 0;
            B(0x33B) = 0;
            B(0x33C) = 0;
            func_001757E0(a, 0x16, 3);
        } else {
            f = func_00117078(((Q5C *)a)->f5C);
            g = F(0x60);
            if (!(f < g)) {
                F(0x5C) = B(0x1E6) != 0 ? g : -g;
                F(0x68) = 0;
            }
        }
    }
}
