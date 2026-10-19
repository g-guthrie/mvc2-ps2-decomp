typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_00175700(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001A59C0(u8 *, u8 *);
extern s32 func_00182D30(u8 *);
extern void func_00182C30(u8 *, s32);
extern void func_001843A0(u8 *);

void func_001A5880(u8 *p, u8 *q, u8 *r)
{
    s16 t;
    func_00175700(p);
    if (*(s8 *)(r + 0x1B3) != 0) {
        p[4] = 2;
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0;
        r[0x13C] = 1;
        r[0x203] = 8;
        r[0x1FF] = 10;
        func_001E3210(p, 35);
        func_001A59C0(p, q);
        return;
    }
    r[0x13C] = 0;
    if (func_00182D30(r) != 0) { /* keep r in a0 before jal */
        p[0x152] = 1;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 7;
        func_00175700(p);
        func_00182C30(r, 10);
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t < 0) {
        r[0x203] = 8;
        r[0x1FF] = 10;
        r[0x13C] = 1;
        func_001843A0(r);
        p[4] = 2;
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0;
        func_001E3210(p, 35);
        func_001A59C0(p, q);
    }
}
