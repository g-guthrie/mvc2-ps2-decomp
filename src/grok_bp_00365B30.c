typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00174240(u8 *);
extern void func_00365F50(u8 *);
extern void func_0018D9A0(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_003657D0(u8 *, u8 *, int);
extern u8 *D_004C2970;
extern void (*D_004C1C38[])(u8 *);

void func_00365B30(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1C);
    if (t) {
        t = t - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t)
            goto rest;
    }
    if (!func_00174240(p)) {
        p[4] = 3;
        D_004C2970[1] = 0;
        func_00365F50(p);
        return;
    }
rest:
    if (*(s8 *)(p + 0x1B3)) {
        p[4]++;
        p[5] = 0;
        func_0018D9A0(p);
        func_001E3210(p, 0x2C);
    } else {
        if (D_004C2970[4] == 0) {
            if (func_003657D0(p, *(u8 **)(p + 0x18), 0x40))
                D_004C2970[4] = 1;
        }
        D_004C1C38[p[5]](p);
    }
}
