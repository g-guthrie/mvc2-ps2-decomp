typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern u8 D_00446FD0[];
extern u8 D_00446FD1[];
extern void func_00190C10(u8 *);
extern void func_00197600(u8 *, u8 *);
extern void func_00197620(u8 *, u8 *);
extern void func_00197660(u8 *, u8 *);
extern void func_00197760(u8 *, u8 *);
extern void func_001977A0(u8 *, u8 *);
extern void func_001977E0(u8 *, u8 *);
extern void func_00175670();
extern void func_001975C0(u8 *, u8 *);
extern s8 func_00175700(u8 *);
extern void func_0019C470(u8 *);
extern void func_00195630(u8 *, u8 *);
typedef struct {
    u8 field0;
    u8 field1;
    u8 pad2[14];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u8 pad28[4];
    u8 field32;
    u8 field33;
    u8 pad34[4];
    u16 value;
} Entry;
extern Entry *func_003DA750(s32, s32, s32);
extern void func_00192BD0(void);
extern void func_001981E0(void);

void func_001906C0(u8 *p, s16 a1, u8 a2, u8 a3) {
    S(p, 0x3F8) = a1;
    p[0x295] = 0;
    p[0x294] = 0;
    if (!a2 && !a3)
        func_00190C10(p);
    else {
        p[0x292] = a2;
        p[0x293] = a3;
    }
}

void func_00190C10(u8 *p) {
    u8 i;
    p[0x295] = 0;
    p[0x294] = 0;
    i = p[1];
    p[0x292] = D_00446FD0[i * 2];
    i = p[1];
    p[0x293] = D_00446FD1[i * 2];
}

void func_00194C30(u8 *p, u8 *q) {
    p[0x13C] = 0;
    func_00197600(p, q);
    func_00197620(p, q);
    func_00197660(p, q);
    func_00197760(p, q);
    func_001977E0(p, q);
}

void func_00194CA0(u8 *p, u8 *q) {
    p[0x13C] = 0;
    func_00197600(p, q);
    func_00197620(p, q);
    func_00197660(p, q);
    func_001977A0(p, q);
    func_001977E0(p, q);
}

void func_00195690(u8 *p, u8 *q) {
    if (*(s8 *)(q + 0x151)) {
        func_00175670(p);
        func_001975C0(p, q);
    }
}

void func_0019C420(u8 *p) {
    if (func_00175700(p) < 0) {
        p[4]++;
        func_0019C470(p);
    }
}

void func_001956E0(u8 *p, u8 *q) {
    s16 t = S(p, 0x1C);
    S(p, 0x1C) = t - 1;
    if (t == 0)
        p[6]++;
    func_00195630(p, q);
    func_00175670();
    func_001975C0(p, q);
}

void func_00192B00(u8 *p) {
    Entry *e = func_003DA750(0, 4, 0);
    if (e) {
        e->callback = func_00192BD0;
        e->arg = p;
        e->value = 0;
    }
}

void func_00193DA0(u8 *p, u8 *q) {
    u8 *blk = p + 0x88;
    if (H(p, 0x98) != H(q, 0x168)) {
        H(blk, 0x10) = H(q, 0x168);
        p[5]++;
        S(p, 0x1C) = 1;
    } else if (q[6] < 3) {
        if (*(s8 *)(p + 0x150) == 2)
            func_00175670(p);
    }
}

void func_00198100(u8 *p, u8 a1) {
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001981E0;
        e->arg = p;
        e->field1 = p[1];
        e->field32 = a1;
        e->field33 = 0;
        e->value = 0x304;
    }
}
