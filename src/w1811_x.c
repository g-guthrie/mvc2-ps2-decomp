typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O {
    u8 pad0[0x0C];
    struct O *p0C;
    u8 pad10[0x14 - 0x10];
    s16 **p14;
    u8 pad18[0x1C - 0x18];
    s16 s1C;
    s16 s1E;
    u8 pad20[0x60 - 0x20];
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6C;
    f32 f70;
    u8 pad74[0x1C4 - 0x74];
    s16 **p1C4;
} O;

s32 func_001A6A70(O *p) {
    s16 **ptr;
    s16 *q;
    s32 r;
    O *a1;
    s32 n;
    s32 i;
    f32 z = 0.0f;
    ptr = p->p1C4;
    r = 1;
    q = *ptr++;
    if (q == 0) {
        q = ptr[-2];
        r = 0;
        ptr--;
    }
    p->p1C4 = ptr;
    p->f6C = p->f68;
    p->f68 = (f32)q[0];
    p->f70 = (f32)q[1] * (p->f68 - p->f6C);
    if (p->f70 < z) {
        p->f70 = 256.0f + p->f70;
    }
    p->f70 *= (f32)q[1];
    p->f70 /= 12.0f;
    p->s1C = q[2];
    *(s32 *)&p->f6C = 0;
    n = p->s1E;
    if (n > 1) {
        i = 1;
        do {
            a1 = p->p0C;
            a1->f6C = p->f6C + a1->f60;
            a1->f70 = p->f70;
            a1->s1C = p->s1C;
            a1->f64 = p->f70 / (f32)p->s1C;
            if (a1->f6C < z) {
                a1->f6C += 256.0f;
            }
            if (!(a1->f6C < 256.0f)) {
                a1->f6C -= 256.0f;
            }
            i++;
            p = a1;
        } while (i < n);
    }
    return r;
}

s32 func_001A5420(O *p) {
    s16 **ptr;
    s16 *q;
    s32 r;
    O *a1;
    s32 n;
    s32 i;
    f32 z = 0.0f;
    ptr = p->p14;
    r = 1;
    q = *ptr++;
    if (q == 0) {
        q = ptr[-2];
        r = 0;
        ptr--;
    }
    p->p14 = ptr;
    p->f6C = p->f68;
    p->f68 = (f32)q[0];
    p->f70 = (f32)q[1] * (p->f68 - p->f6C);
    if (p->f70 < z) {
        p->f70 = 256.0f + p->f70;
    }
    p->f70 *= (f32)q[1];
    p->f70 /= 12.0f;
    p->s1C = q[2];
    *(s32 *)&p->f6C = 0;
    n = p->s1E;
    if (n > 1) {
        i = 1;
        do {
            a1 = p->p0C;
            a1->f6C = p->f6C + a1->f60;
            a1->f70 = p->f70;
            a1->s1C = p->s1C;
            a1->f64 = p->f70 / (f32)p->s1C;
            if (a1->f6C < z) {
                a1->f6C += 256.0f;
            }
            if (!(a1->f6C < 256.0f)) {
                a1->f6C -= 256.0f;
            }
            i++;
            p = a1;
        } while (i < n);
    }
    return r;
}

s32 func_001A09B0(O *p) {
    s16 **ptr;
    s16 *q;
    s32 r;
    O *a1;
    s32 n;
    s32 i;
    f32 z = 0.0f;
    ptr = p->p1C4;
    r = 1;
    q = *ptr++;
    if (q == 0) {
        q = ptr[-2];
        r = 0;
        ptr--;
    }
    p->p1C4 = ptr;
    p->f6C = p->f68;
    p->f68 = (f32)q[0];
    p->f70 = (f32)q[1] * (p->f68 - p->f6C);
    if (p->f70 < z) {
        p->f70 = 256.0f + p->f70;
    }
    p->f70 *= (f32)q[1];
    p->f70 /= 12.0f;
    p->s1C = q[2];
    *(s32 *)&p->f6C = 0;
    n = p->s1E;
    if (n > 1) {
        i = 1;
        do {
            a1 = p->p0C;
            a1->f6C = p->f6C + a1->f60;
            a1->f70 = p->f70;
            a1->s1C = p->s1C;
            a1->f64 = p->f70 / (f32)p->s1C;
            if (a1->f6C < z) {
                a1->f6C += 256.0f;
            }
            if (!(a1->f6C < 256.0f)) {
                a1->f6C -= 256.0f;
            }
            i++;
            p = a1;
        } while (i < n);
    }
    return r;
}
