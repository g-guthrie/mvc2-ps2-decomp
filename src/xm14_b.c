typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A0[];
extern u8 D_004F20B0[];
extern u8 D_00446DA0[];
extern s8 *D_004C2840;

void func_0018B500(u8 *p, u8 *q) {
    extern void func_0016EDA0(u8, s32);
    extern s32 func_0018B890(u8 *, u8 *, u8 *, s32);
    extern void func_0018F8C0(u8 *, s16 *);
    extern void func_0018FEB0(u8 *);
    extern void func_00190540(u8 *, s32);
    extern void func_001902F0(u8 *);
    extern s32 func_00174170(void);
    extern void func_00191770(u8 *, u8 *);
    u8 *r;
    s16 t;
    u8 type;
    u8 s1;
    r = *(u8 **)(p + 0x1D0);
    p[0x245] = r[3];
    p[0x2B3] = 0;
    if (*(u8 *)(*(u8 **)(p + 0x1CC) + 0x425) != 0) {
        p[0x28B]++;
    }
    func_0016EDA0(p[2], r[0] > 0xD ? 3 : 1);
    if ((t = r[0]) != 0 && D_004D18A0[0] == 4) {
        t = func_0018B890(p, D_004F20B0 + q[0x1B8] * 0x5B8, r, t);
    }
    if (D_004D18A0[0] == 4) {
        if (*(s16 *)(p + 0x434) != 0) {
            s16 v;
            func_0018F8C0(p, &t);
            v = *(s16 *)(p + 0x434) - t;
            *(s16 *)(p + 0x434) = v;
            if (v <= 0) {
                if ((r[0x12] & 0x20) == 0 && D_004C2840[0xAA] == 0) {
                    func_0018FEB0(p);
                } else {
                    *(s16 *)(p + 0x434) = 1;
                    if (*(s16 *)(p + 0x438) <= 0) {
                        *(s16 *)(p + 0x438) = 1;
                    }
                }
            }
            func_00190540(p, t);
            func_001902F0(p);
        }
    }
    p[0x244] = r[2];
    p[0x246] = r[6];
    *(s16 *)(p + 0x240) = r[7];
    type = (s8)r[1] & 0x1F;
    if (*(u16 *)(q + 0x1C0) & 8) {
        type = 9;
    }
    if (type == 9) {
        if (p[5] == 3 && (p[0x247] == 9 || p[0x247] == 0x17) && (p[0x245] & 7) != 5) {
            type = 1;
        }
    }
    if (type == 0x14) {
        if (p[5] == 3 && p[0x247] == 0x14) {
            type = 1;
        }
    }
    p[0x247] = type;
    if (p[0x20D] == 3 && (*(u16 *)(q + 0x1C0) & 0x40)) {
        p[0x1EF] = 0xFF;
    }
    if (r[0x16] != 0) {
        p[0x201] = (s8)r[0x16] & 0x3F;
        p[0x1B1] = 0;
        if (q[3] == 0) {
            *(s8 *)(q + 0x201) = *(s8 *)(p + 0x201);
            *(s8 *)(q + 0x1B1) = *(s8 *)(p + 0x1B1);
        }
    }
    s1 = r[4];
    if (s1 != 0) {
        s1 += D_00446DA0[func_00174170() & 0x1F];
        if (p[0x1F5] != 1 && p[0x1F5] <= s1 && s1 < 0x14) {
            p[0x1F5] = 1;
        } else {
            if (p[0x1F3] == 0 && *(s8 *)(p + 0x1F4) == 0) {
                if ((s8)(p[0x1F5] -= s1) < 0) {
                    p[0x1F5] = 0;
                }
            }
        }
    }
    p[0x242] = r[8];
    if (p[0x1B6] & 0x80) {
        p[0x242] = q[0x22];
    }
    p[0x243] = r[9];
    if (*(u16 *)(q + 0x1C0) & 0x400) {
        p[0x247] = 10;
        p[0x242] = 0;
    }
    p[0x1F6] = 0x3C;
    if (D_004D18A0[0] == 4) {
        func_00191770(*(u8 **)(p + 0x1CC), *(u8 **)(p + 0x1D0));
    }
}
