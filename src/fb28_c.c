typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } E28;
extern E28 D_00451C70[];
extern E28 D_00451CB0[];

void func_0022F750(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_0022F590(u8 *, u8 *);
    extern void func_001863F0(u8 *);
    extern void func_00186A20(u8 *);
    extern void func_0022F9E0(u8 *, u8 *);
    E28 *e;
    s32 a0, a2;
    u32 t;

    func_00175700(p);
    func_0022F590(p, q);
    switch (p[0x20D]) {
    case 0:
        if (*(s8 *)(p + 0x151) >= 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_001863F0(p);
            break;
        }
        func_00186A20(p);
        e = D_00451C70 + p[0x1B7];
        a0 = e->w0;
        a2 = e->w4;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x34) += 80.0f;
        } else {
            *(f32 *)(p + 0x34) -= 80.0f;
            a0 = -a0;
            a2 = -a2;
        }
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)a0 / 65536.0f;
        *(f32 *)(p + 0x68) = 1.6666666269302368f * (f32)a2 / 65536.0f;
        *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)e->w8 / 65536.0f;
        *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)e->wC / 65536.0f;
    case 2:
        if (*(s8 *)(p + 0x151) < 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            break;
        }
        t = p[7];
        p[7] = t + 1;
        e = D_00451CB0 + p[0x1B7];
        a0 = e->w0;
        a2 = e->w4;
        if (*(s16 *)(p + 0x140) == 0) {
            a0 = -a0;
            a2 = -a2;
        }
        *(f32 *)(p + 0x5C) = (f32)a0;
        *(f32 *)(p + 0x68) = (f32)a2;
        *(f32 *)(p + 0x60) += 2.142857074737549f * (f32)e->w8 / 65536.0f;
        *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)e->wC / 65536.0f;
        func_0022F9E0(p, q);
        break;
    default:
        break;
    }
}
