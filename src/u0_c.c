typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
typedef struct { s32 cls; s32 sign; s32 normal_exp; u32 fraction; } fp_t;
typedef union { float value; u32 word; struct { u32 fraction : 23; u32 exp : 8; u32 sign : 1; } bits; } flo_t;
float func_00118E90(fp_t *src) {
    flo_t dst;
    u32 fraction = src->fraction;
    s32 sign = src->sign;
    s32 exp = 0;
    if ((src->cls ^ 2) == 0) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < -126) {
            exp = 0;
            fraction = 0;
        } else if (src->normal_exp > 128 || (src->normal_exp == 128 && (s32)fraction < 0)) {
            exp = 255;
            fraction = 0;
        } else {
            exp = src->normal_exp + 127;
            fraction >>= 7;
        }
    }
    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}
typedef struct { u8 pad[0x60]; s32 (*fn)(void *, s32, s32, s32); } T;
extern char D_004BD330[], D_004BD358[], D_004BD380[];
extern T *func_00406128(s32);
extern void func_00405DC8(char *), func_0011D8F8(void *, s32, s32);
s32 func_00407868(s32 a, s32 b) {
    s32 v[5];
    T *t;
    if (a == 0) {
        func_00405DC8(D_004BD330);
        return -1;
    }
    if (b == 0) {
        func_00405DC8(D_004BD358);
        return -1;
    }
    t = func_00406128(a);
    if (t == 0) {
        func_00405DC8(D_004BD380);
        return -1;
    }
    func_0011D8F8(v, 0, 0x14);
    v[1] = b;
    if (t->fn != 0) return t->fn(v, 3, 0, 0);
    return -1;
}
typedef struct { s32 a, b; } E8;
typedef struct { s32 pad; u8 b[12]; } E16;
extern volatile s32 D_004872E0[]; extern s32 D_004872EC;
extern E8 D_0062FA08[]; extern E16 D_0062FB48[]; extern u8 D_0062FD48[];
extern void func_0011D8F8(void *, s32, s32);
void func_00405DF0(void) {
    s32 i;
    (void)D_004872E0[0];
    if (D_004872EC == 0) {
        for (i = 0; i < 40; i++) {
            D_0062FA08[i].a = 0;
            D_0062FA08[i].b = 0;
        }
        for (i = 0; i < 32; i++) D_0062FB48[i].b[0] = 0;
        func_0011D8F8(D_0062FD48, 0, 9);
        D_0062FD48[0] = 0;
    }
    D_004872EC++;
}
typedef struct { u8 f0; s8 k; u8 pad[2]; void *f4; s32 pad8; s32 fC; u8 pad2[0x78]; s32 f88; } O;
extern void func_003FF178(s32);
extern s32 func_003FFFF0(void *), func_003FFF78(void *), func_003FFFA8(void *);
void func_00401980(O *a, s32 *b, s32 *c) {
    if ((u8)(a->k - 3) < 2) {
        func_003FF178(a->fC);
    } else if (a->k == 5) {
        *b = func_003FFFF0(a->f4);
        *c = func_003FFF78(a->f4);
        *b = *b * (16 / func_003FFFA8(a->f4));
    } else {
        *b = 0;
        *c = 1;
    }
    *b += a->f88;
}
typedef void (*Fn)(s32, s32 *, u32);
extern Fn D_00488110[]; extern s32 D_00488210[];
extern void func_0040EFE0(), func_0040EFF8();
extern s32 func_00409250(s32, s32, s32, s32);
extern void func_004093E8(s32);
s32 *func_00408F88(u32 a, s32 *b, u32 c) {
    func_0040EFE0();
    switch (a) {
    case 0:
    case 1:
        break;
    case 2:
        *b = func_00409250(b[0], b[1], b[2], b[3]);
        break;
    case 3:
        func_004093E8(b[0]);
        break;
    default:
        if (a - 0x400 < 0x40 && D_00488110[a - 0x400] != 0) {
            D_00488110[a - 0x400](D_00488210[a - 0x400], b, c >> 2);
        }
        break;
    }
    func_0040EFF8();
    return b;
}
typedef struct { u8 pad[0x48]; s32 (*fn)(s32, s32, s32); } T48;
extern char D_004BCEF0[];
extern void func_00406688(char *, char *, s32), func_004067B8(char *), func_00407B08(char *, char *), func_00405DC8(char *);
s32 func_004071C0(s32 a, s32 b, s32 c) {
    char buf[0x130];
    char buf2[0x130];
    s32 r;
    T48 *t;
    func_00406688(buf, buf2, a);
    r = 0;
    if (buf[0] == 0) {
        func_004067B8(buf);
        if (buf[0] == 0) {
            func_00405DC8(D_004BCEF0);
            return 0;
        }
    }
    func_00407B08(buf, buf2);
    if ((t = (T48 *)func_00406128((s32)buf)) != 0) {
        if (t->fn != 0) r = t->fn(a, b, c);
    }
    return r;
}
