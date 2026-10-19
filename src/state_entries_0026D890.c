typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_001757E0(void *, int, int);
extern void func_00185490(void *);
extern void func_00183D10(void *);
extern u8 *D_004C2794;

void func_0026D890(u8 *p) {
    u32 t;
    s16 *e;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_00183D10(p);
    *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x3B;
    p[0x1B2] = *(u16*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1D8) = 0;
    e = (s16*)((p[2] << 1) + (u32)D_004C2794);
    e[0x3E] = e[0x3E] + 1;
    func_001757E0(p, 0x16, 3);
}
