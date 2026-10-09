typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_00176090(u8 *, int, int, int);
extern void func_0030F650(u8 *);
void func_0030EDB0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        p[0x20D] = 0;
        *(s16 *)(p + 0x1E) = 60;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 19, 0);
        func_001E3210(p, 16);
        return;
    }
    func_00175700(p);
    {
        s16 timer = *(s16 *)(p + 0x1E);
        timer--;
        *(s16 *)(p + 0x1E) = timer;
        if (timer <= 0) {
            func_00176090(p, 0, 0, 1);
            func_0030F650(p);
        }
    }
}
