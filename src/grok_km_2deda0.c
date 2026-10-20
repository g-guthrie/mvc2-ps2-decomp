typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00183D90(u8 *);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002DEDA0(u8 *p)
{
    int mode;
    s16 t;
    f32 *vx;
    f32 *ax;

    p[0x40C] = 2;
    p[0x33C] = 5;
    vx = (f32 *)(p + 92);
    ax = (f32 *)(p + 104);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if (*(f32 *)(p + 92) > 0.0f)
        func_00183D90(p);
    if ((s8)func_00175700(p) < 0) {
        *(s16 *)(p + 0x1C) = 20;
        t = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = t;
        if (t == 3) {
            p[7]++;
            mode = 6;
        } else {
            p[7]--;
            mode = ((*(s16 *)(p + 0x1E) & 1) << 1) + 1;
        }
        func_00185490(p);
        func_001757E0(p, 22, (u8)mode);
    } else if (*(s8 *)(p + 0x151) & 1) {
        p[0x151] = 0;
        *vx = 0;
        *ax = 0;
    }
}
