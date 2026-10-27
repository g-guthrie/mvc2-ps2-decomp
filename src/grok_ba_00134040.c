typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00134230(u8 *, u8 *);
extern s32 func_001342D0(u8 *, u8 *);
extern s32 func_00134370(u8 *, u8 *);
extern void func_001341B0(u8 *, u8 *);
extern void func_001345B0(u8 *, u8 *);
extern void func_00134120(u8 *, u8 *);

/* Provisional: reset helpers are unary; a typed call still misses retail scheduling. */
void func_00134040(u8 *p, u8 *q)
{
    s16 t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t + 1;
    if (t < 0x5B) {
        if (t >= 0x1E) {
            if (p[0x20] != 4) {
                if (func_00134230(p, q) == 0)
                    return;
                if (func_001342D0(p, q) == 0)
                    return;
                if (func_00134370(p, q) == 0)
                    return;
            }
            func_001341B0(p, q);
        }
    } else {
        func_001345B0(p, q);
        if (p[0x20] != 4) {
            p[5] = 0;
            p[0x20] = 1;
        } else {
            p[5]++;
            func_00134120(p, q);
        }
    }
}
