/* func_0014BDA0: MW 3.0 (./try30.sh) "-O3 -Op -fp off -sdatathreshold 8".
 * Colouring fix (r16_03): flag written as if/else so its web stays in the named
 * variable (a ternary routes it through a compiler temp @N, which always gets a
 * lower vreg index than any named local), and flag declared before p2 so it is
 * pushed after p2 in simplify and coloured first (flag=v1, p2=a0). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b[64]; } T64;

typedef struct {
    u8 pad0[0x30];
    u32 w30;
    u32 w34;
    u32 w38;
    u32 w3C;
} D14;

typedef struct O14 {
    u8 pad0[0x10];
    void *w10;
    u8 pad14[0xC];
    u8 b20;
    u8 pad21[2];
    u8 b23;
    u8 pad24[0x10];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x10];
    f32 f50;
    f32 f54;
    u8 pad58[0x20];
    f32 f78;
    f32 f7C;
    f32 f80;
    s32 w84;
    u8 pad88[0x44];
    s16 hCC;
    u8 padCE[2];
    s32 wD0;
    u8 padD4[4];
    struct O14 *wD8;
    u8 padDC[0x60];
    u8 b13C;
} O14;

extern T64 D_00444070;
extern D14 *D_004C2840;
extern s32 D_004C27FC;
extern O14 *D_004CAD50[];

void func_0014BDA0(void)
{
    extern O14 *func_003DA750(s32, s32, s32);
    extern void func_0014AA10(void);
    extern void func_0014AFB0(void);
    extern void func_00170DF0(s32);
    T64 tab;
    f32 fx;
    f32 fy;
    O14 **slot;
    s32 i;
    s32 j;
    O14 *o;
    O14 *o2;
    s32 s4;
    s32 bit;
    s32 flag;
    u32 *p2;
    u32 *p1;
    u32 m;
    s32 n;
    tab = D_00444070;
    fy = 3.25f;
    i = 0;
    do {
        fx = -11.239999771118164f;
        j = 0;
        do {
            s4 = tab.b[i * 8 + j];
            if (s4 != -1) {
                o = func_003DA750(0, 0xD, 1);
                if (o == 0) return;
                n = s4 & 0x3F;
                bit = n;
                if (n >= 0x20) {
                    bit = n - 0x20;
                    p1 = &D_004C2840->w34;
                    p2 = &D_004C2840->w3C;
                } else {
                    p1 = &D_004C2840->w30;
                    p2 = &D_004C2840->w38;
                }
                m = *p1;
                bit = 1 << bit;
                if (m & bit) flag = 0; else flag = 0xC7;
                if (n >= 0x18) s4 -= 3;
                n = s4 & 0x3F;
                slot = &D_004CAD50[n];
                *slot = o;
                o->b20 = i * 8 + j;
                o->b23 = s4;
                o->b13C = 1;
                o->w10 = func_0014AA10;
                if (flag == 0) flag = n + 0x3A;
                o->hCC = flag;
                o->w84 = D_004C27FC;
                o->wD0 = 0x411;
                o->f34 = fx;
                o->f38 = fy;
                o->f3C = -12.880000114440918f;
                o->f80 = 0.800000011920929f;
                o->f7C = 0.800000011920929f;
                o->f78 = 0.800000011920929f;
                o->f54 = 1.0f;
                o->f50 = 1.0f;
                if (flag == 0xC7 && (s4 & 0x80)) o->b13C = 0;
                if (flag != 0xC7) {
                    if ((*p2 & bit) != 0) {
                        o2 = func_003DA750(0, 0xD, 1);
                        if (o2 == 0) return;
                        o2->b13C = 1;
                        o2->w10 = func_0014AFB0;
                        o2->hCC = 0xC8;
                        o2->w84 = D_004C27FC;
                        o2->wD0 = 0x11;
                        o2->f34 = fx;
                        o2->f38 = fy;
                        o2->f3C = -12.859999656677246f;
                        o2->f54 = 1.0f;
                        o2->f50 = 1.0f;
                        (*slot)->wD8 = o2;
                        func_00170DF0(o2->w84);
                    } else {
                        (*slot)->wD8 = 0;
                    }
                }
            }
            fx += 1.5f;
            j++;
        } while (j < 8);
        fy -= 1.5f;
        i++;
    } while (i < 8);
}
