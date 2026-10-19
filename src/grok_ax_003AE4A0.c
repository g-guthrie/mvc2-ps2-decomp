typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_003AE370(u8 *);
extern u8 *func_003DA750(int, int, int);
extern void func_003AD6E0(u8 *);
extern void func_003AE2C0(u8 *);
extern int func_00175700(u8 *);

void func_003AE4A0(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = t;
    if (t <= 0) {
        *(u32 *)(p + 0xD0) += 1;
        func_003AE370(p);
        if (*(s16 *)(p + 0x1E) == 0) {
            p[4]++;
            if (!p[0x21]) {
                (*(u8 **)(p + 0x18))[7] = 2;
                return;
            }
            return;
        } else {
            u8 *o = func_003DA750(0, 1, 1);
            if (o) {
                *(void (**)(u8 *))(o + 0x10) = func_003AD6E0;
                *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
                o[0x20] = 8;
                o[0x21] = p[0x21];
                *(s16 *)(o + 0x26) = 0x3002;
                {
                    f32 x = *(f32 *)(p + 0x34);
                    f32 y = *(f32 *)(p + 0x38);
                    f32 z = *(f32 *)(p + 0x3C);
                    *(f32 *)(o + 0x34) = x;
                    *(f32 *)(o + 0x38) = y;
                    *(f32 *)(o + 0x3C) = z;
                }
            }
        }
    }
    func_003AE2C0(p);
    func_00175700(p);
}
