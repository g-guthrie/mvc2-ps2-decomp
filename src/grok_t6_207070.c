/* Metrowerks 3.0: ./try.sh src/grok_t6_207070.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_00450500[];
extern u8 D_004D18A0;
extern s8 func_00175700(u8 *);
extern void func_00206A80(u8 *);
extern int func_00174170(void);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_00207070(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    p[0x33C] = 5;
    func_00206A80(p);
    p[0x22] = 0;
    p[0x209] = 3;
    if (p[0x269] == 5 || ((s8)p[0x539] == 0 && p[0x269] == 4)) {
        if ((D_004C2840[0x84] & 7) == 0) {
            p[0x22] = (func_00174170() & 3) + 1;
            p[0x21] = D_00450500[func_00174170() & 0xF];
        }
    } else {
        u16 w = *(u16 *)(p + 0x35C);
        if (w & 0x360) {
            if (w & 0x200)
                p[0x22] = 1;
            if (*(u16 *)(p + 0x35C) & 0x100)
                p[0x22] = 2;
            if (*(u16 *)(p + 0x35C) & 0x40)
                p[0x22] = 3;
            if (*(u16 *)(p + 0x35C) & 0x20)
                p[0x22] = 4;
            p[0x21] = (*(u16 *)(p + 0x354) & 0x3C00) >> 10;
        }
    }
    {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t == 0 || D_004D18A0 >= 5) {
            p[6]++;
            *(f32 *)(p + 0x60) = 0;
            *(f32 *)(p + 0x6C) = -45.0f / 56.0f;
            *(f32 *)(p + 0x5C) = 0;
            *(f32 *)(p + 0x68) = 0;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            func_00185490(p);
            func_001757E0(p, 0x16, 0x16);
        }
    }
}
