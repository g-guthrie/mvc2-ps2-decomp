typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x10];
    void (*f10)();
    u8 pad1[0xC];
    u8 b20;
    u8 pad2[0x13];
    u32 f34;
    u32 f38;
    f32 f3c;
    u8 pad3[0x44];
    u32 f84;
    u8 pad4[0x44];
    s16 fcc;
} O;

extern u32 *D_00444760[];
extern f32 *D_00444790[];
extern s16 D_004447C0[];
extern u32 D_004C27F4;

void func_001517C0(s32 a, s32 b)
{
    extern void func_003DA650(s32);
    extern O *func_00151780();
    extern void func_00151720();
    u32 *s0;
    f32 *s1;
    s32 k;
    O *o;
    func_003DA650(13);
    s0 = D_00444760[a];
    s1 = D_00444790[a];
    while ((k = *s0) != -1) {
        if ((o = func_00151780()) == 0) {
            s0++;
            s1++;
            continue;
        }
        o->fcc = k;
        o->f84 = D_004C27F4;
        o->b20 = k;
        o->f34 = 0;
        *(f32 *)&o->f38 = *s1;
        o->f3c = -13.0f;
        if (k == 2 || k == 0x1A) {
            if ((o = func_00151780()) != 0) {
                o->fcc = D_004447C0[b * 4];
                o->f84 = D_004C27F4;
                if (a == 3) {
                    o->f34 = 0x3FDD70A4;
                    o->f38 = 0xC0C00000;
                    o->f3c = -13.0f;
                } else {
                    o->f34 = 0x409DD2F2;
                    o->f38 = 0xC0C00000;
                    o->f3c = -13.0f;
                }
                o->b20 = 3;
            }
            if ((o = func_00151780()) != 0) {
                o->fcc = D_004447C0[b * 4 + 2];
                o->f84 = D_004C27F4;
                if (a == 3) {
                    o->f34 = 0x40233333;
                    o->f38 = 0xC0C00000;
                    o->f3c = -13.0f;
                } else {
                    o->f34 = 0x40B81062;
                    o->f38 = 0xC0C00000;
                    o->f3c = -13.0f;
                }
                o->b20 = 3;
            }
        } else if (k == 0xD) {
            o->f3c += 0.1f;
            o->f10 = func_00151720;
        }
        s0++;
        s1++;
    }
}
