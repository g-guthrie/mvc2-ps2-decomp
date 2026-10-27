typedef struct StreamGroup StreamGroup;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BC7C0[];

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s32 h;
    s32 w8;
    s32 wC;
    u8 pad10[0x28];
    s32 w38;
    s16 h3c;
    s16 h3e;
    s16 h40;
    s16 h42;
    u8 pad44[4];
    s32 w48;
    u8 pad4c[4];
    s32 w50;
    u8 pad54[0x20];
    s32 w74;
    u8 pad78[0x14];
    s32 w8C;
    s32 w90;
} C43;

void func_004035D8(C43 *p)
{
    extern s32 func_003FF5C8(s32);
    extern s32 func_003FFF90(void *);
    extern void func_003FB2E8(s32, s32, u8 *, s32);
    extern void func_003FB178(u8 *, u8 *);
    extern void func_00401868(C43 *);
    extern s32 func_003FFF78(void *);
    extern s32 func_00400020(void *);
    extern s32 func_003FFFC0(void *);
    extern void func_003FF600(StreamGroup *, s32);
    extern s32 func_00400098(void *);
    extern void func_004007A0(s32, s32);
    extern void func_00400790(s32, void *, C43 *);
    extern s32 func_00400080(s32);
    extern void func_003FFF30(s32, s32);
    extern void func_003FFF50(s32, s32);
    extern void func_003FFF40(s32, s32);
    extern void func_003FFF20(s32, void *, C43 *);
    extern s32 func_003FFFF0(StreamGroup *);
    extern s32 func_003FFFA8(s32);
    extern void func_003FF288(void *, s32);
    typedef struct S_0040ED28 S_0040ED28;
    extern void func_003FF240(S_0040ED28 *, s32);
    extern void func_003FF228(void *, s32);
    extern void func_003FF328(s32, s32);
    extern void func_003FF258(s32 *, s32);
    extern void func_00403228(C43 *);
    extern void func_003F6470(s32, s32);
    extern s32 func_003FFF60(s32);
    extern s32 func_004000D0(s32);
    extern void func_003FF338(s32, s32);
    extern void func_003FF148(s32, s32);
    extern void func_004031A8();
    extern void func_00403020();
    extern void func_00403308();
    u8 buf[32];
    s32 unit = 0x800;
    s32 a, h, b, c, n, v, w, x;
    h = p->h;
    if (func_003FF5C8(h) != 2) return;
    b = func_003FFF90((void *)h);
    if (p->b3 < b) {
        func_003FB2E8(b, p->b3, buf, 16);
        func_003FB178(D_004BC7C0, buf);
        func_00401868(p);
        return;
    }
    a = func_003FFF78((void *)h);
    b = func_00400020((void *)h);
    if (b > 0) {
        p->w48 = a / p->w38 * 3;
    } else {
        p->w48 = a / p->w38 * 3 / 2;
    }
    w = func_003FFFC0((void *)h) * 2;
    {
        s32 t;
        t = p->w48 + w;
        p->w48 = t / w * w;
    }
    func_003FF600((StreamGroup *)h, p->w48);
    if (b > 0) {
        if (p->b2 == 2) {
            p->w50 = 0;
        } else {
            v = func_00400098((void *)h);
            p->w50 = unit - v % unit;
            p->w50 = p->w50 % unit;
            n = (v + 0x7FF) / unit;
            p->w8C = n;
            func_004007A0(p->w8, n);
            func_00400790(p->w8, func_004031A8, p);
        }
        p->w90 = func_00400080(h);
        func_003FFF30(h, p->w90);
        func_003FFF50(h, 0);
        func_003FFF40(h, 0);
        func_003FFF20(h, func_00403020, p);
    } else {
        if (p->w8) func_004007A0(p->w8, 0x7FFFFFFF);
        func_003FFF30(h, func_003FFFF0((StreamGroup *)h));
        func_003FFF50(h, 0);
        func_003FFF40(h, 0);
        func_003FFF20(h, func_00403308, p);
    }
    a = func_003FFF78((void *)h);
    b = func_003FFF90((void *)h);
    c = func_003FFFF0((StreamGroup *)h);
    v = func_003FFFA8(h);
    func_003FF288((void *)p->wC, v);
    func_003FF240((S_0040ED28 *)p->wC, a);
    func_003FF228((void *)p->wC, b);
    func_003FF328(p->wC, c);
    func_003FF258((s32 *)p->wC, p->h40);
    func_00403228(p);
    if (p->w74) func_003F6470(p->w74, a);
    unit = 2;
    if (func_003FFF60(h) == unit) {
        func_003FF338(p->wC, func_004000D0(h));
    }
    func_003FF148(p->wC, 1);
    p->b1 = unit;
}
