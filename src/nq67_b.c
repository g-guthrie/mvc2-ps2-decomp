typedef unsigned char u8;
typedef signed short s16;
typedef struct { u8 *a; u8 *b; u8 *c; } E;
extern E D_004D18BC[];
extern E D_004D18C0[];

void func_00326F50(u8 *p) {
    extern void func_00326DE0(u8 *);
    extern void func_00180D20(u8 *, u8 *);
    u8 *s0;
    u8 *o;
    if (p[0x425] == 0) {
        s0 = D_004D18BC[p[2]].a;
        if (*(s16 *)(s0 + 0x434) == 0) return;
        o = D_004D18C0[p[2]].a;
        if (*(s16 *)(o + 0x434) != 0) {
            o[0x425] = 1;
            p[0x425] = 2;
        } else {
            p[0x425] = 1;
        }
        p[0x13C] = 0;
        p[0] = 0;
        func_00326DE0(s0);
        func_00180D20(s0, p);
    } else {
        p[0x13C] = 0;
        p[0] = 0;
        if (*(s16 *)(p + 0x434) != 0 || p[0x425] == 2) return;
        o = D_004D18C0[p[2]].a;
        if (*(s16 *)(o + 0x434) != 0) {
            p[0x425] = 2;
            o[0x425] = 1;
        }
    }
}
