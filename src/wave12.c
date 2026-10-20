typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern s32 func_001BF550(u8 *);
extern void func_00418000(void *);
extern void func_00418010(void);
extern s8 D_004F1D20[];
extern u8 D_004F1D30[];

void func_0035BE70(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    r = (u8 *)(p[0x23] + (u32)r);
    r[1] &= 0xFD;
    p[4] = 3;
    p[0x13C] = 0;
}




extern void func_00122770(void *, void *, void *, void *);
extern void func_00417270(void *);
extern void func_00417350(s32);
extern void func_004172E0(s32);

void func_001227A0(void *a, void *b) {
    s32 x, y, z;
    func_00122770(a, &x, &y, &z);
    func_00417270(b);
    func_00417350(y);
    func_004172E0(z);
}

extern void func_00184540(u8 *);


extern void func_00140F80(u8 *);
void func_00140F30(u8 *p) {
    s16 a, b;
    a = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = a;
    if (a >= 360) *(s16 *)(p + 0x1C) = 0;
    b = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = b;
    if (b >= 200) *(s16 *)(p + 0x1E) = 0;
    func_00140F80(p);
}

extern void func_003419F0(u8 *, s32);


extern void func_0011D8F8(u8 *, s32, s32);
extern void func_0015B200(u8 *, float *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00138900(u8 *);
extern s32 func_00182E80(u8 *);
extern float D_004F1FDC;
extern float D_004F1FD8;


s32 func_00335390(u8 *p) {
    float x = *(float *)(p + 0x34);
    s32 r;
    if (x < D_004F1FDC) goto L2;
    r = (*(s16 *)(p + 0x140) != 0) ^ 1;
    goto end;
L2:
    r = 0;
    if (x <= D_004F1FD8) r = *(s16 *)(p + 0x140) != 0;
end:
    return r;
}

void func_00390CB0(u8 *p, u8 *q) {
    float v[3];
    v[0] = *(float *)(p + 0x34);
    v[1] = *(float *)(p + 0x38);
    func_0015B200(q, v, 1, 0xF9);
    func_001E3710(q, 7);
}


extern void func_00191210(u8 *);
extern void (*D_0045DFD0[])(u8 *);

void func_00323ED0(u8 *p) {
    p[0x1FF] = 2;
    *(s32 *)(p + 0xD0) = 3;
    func_00191210(p);
    D_0045DFD0[p[6]](p);
}


extern s32 func_0016A3F0(u8 *, u8 *);
extern s32 func_00165180(u8 *, u8 *);

s32 func_001642A0(u8 *p, u8 *q) {
    if (func_0016A3F0(p, q)) {
        p[0x451]--;
        *(s16 *)(p + 0x4F0) = 0;
        return 1;
    }
    return func_00165180(p, q);
}

extern void func_001757E0(u8 *, s32, s32);
extern void func_001AB110(u8 *, u8 *);

void func_001AB0B0(u8 *p, u8 *q) {
    p[7]++;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    func_001757E0(p, 0x17, 0x19);
    func_001AB110(p, q);
}

extern u8 D_004D18A0[];

void func_002103A0(u8 *p) {
    u8 *q = p + 0x2B8;
    s8 v;
    v = D_004D18A0[0] >= 5 ? *(s8 *)(q + 1) : 0;
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    q[1] = v;
}

extern s32 func_00174240(u8 *);
extern void func_00355B10(u8 *);
extern void func_001E7F60(u8 *);

void func_00355A70(u8 *p) {
    if (*(s8 *)(p + 0x1B2) == 0) {
        if (func_00174240(p) != 0) goto call;
    }
    p[4] = 3;
    p[0x13C] = 0;
    goto end;
call:
    func_00355B10(p);
    func_001E7F60(p);
end:
    return;
}

extern void func_003C3A50(u8 *, u8 *);
extern void (*D_00475CB0[])(u8 *, u8 *);

void func_003C1350(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x16) func_003C3A50(p, q);
    else D_00475CB0[p[0x20]](p, q);
}

extern u8 D_004CD183[][20];
extern void func_001E4EB0(s32, s32, s32, float);

void func_001E32C0(u8 *p, s32 b, s16 c) {
    if ((u8)b < 0x40) { u8 x = D_004CD183[p[0x1B8]][0]; func_001E4EB0(x, b, c, 2.0f); }
}
