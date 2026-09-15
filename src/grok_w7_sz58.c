typedef unsigned char u8;

extern u8 D_00454AE0[];
extern u8 D_00454D30[];
extern u8 D_00454D50[];
extern u8 D_00454D80[];
extern u8 D_004551E0[];
extern u8 D_004551F0[];
extern u8 D_00455200[];
extern u8 D_00455210[];
extern u8 D_00455220[];
extern u8 D_00455230[];
extern u8 D_00455240[];
extern u8 D_00455250[];
extern u8 D_00455260[];
extern u8 D_00455270[];
extern u8 D_00455280[];
extern u8 D_004580C0[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_00186A60(u8 *, int);

#define TRANS(str, off, st, anim) \
    { \
        if (!func_00189310(p, (str), p + (off))) \
            return 0; \
        p[5] = 0; \
        p[7] = 0; \
        p[6] = 0; \
        p[0x1FD] = (st); \
        func_00186A60(p, (anim)); \
        return 1; \
    }

int func_00273BB0(u8 *p) TRANS(D_00454AE0, 0x3A8, 2, 21)
int func_002783D0(u8 *p) TRANS(D_00454D30, 0x378, 5, 21)
int func_002784B0(u8 *p) TRANS(D_00454D50, 0x388, 1, 29)
int func_00278590(u8 *p) TRANS(D_00454D80, 0x398, 3, 29)
int func_0027D1E0(u8 *p) TRANS(D_004551E0, 0x380, 1, 21)
int func_0027D250(u8 *p) TRANS(D_004551F0, 0x388, 2, 21)
int func_0027D2C0(u8 *p) TRANS(D_00455200, 0x390, 3, 21)
int func_0027D330(u8 *p) TRANS(D_00455210, 0x398, 4, 21)
int func_0027D3A0(u8 *p) TRANS(D_00455220, 0x3A0, 5, 21)
int func_0027D410(u8 *p) TRANS(D_00455230, 0x3A8, 6, 21)
int func_0027D480(u8 *p) TRANS(D_00455240, 0x3B0, 7, 21)
int func_0027D4F0(u8 *p) TRANS(D_00455250, 0x3B8, 8, 21)
int func_0027D560(u8 *p) TRANS(D_00455260, 0x3C0, 9, 21)
int func_0027D5D0(u8 *p) TRANS(D_00455270, 0x3C8, 10, 21)
int func_0027D640(u8 *p) TRANS(D_00455280, 0x3E0, 11, 21)
int func_0029B710(u8 *p) TRANS(D_004580C0, 0x3C8, 9, 21)
