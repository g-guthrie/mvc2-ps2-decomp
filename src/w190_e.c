typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w190_e.c "-O3 -Op -sdatathreshold 0" */

extern s32 func_00175700(u8 *);
extern u8 D_0044ACA0[], D_0044ACA2[], D_0044ACA4[];
extern void func_001757E0(u8 *, s32, s32);

void func_0019E2E0(u8 *p,u8 *work_unused) {
    u8 *q = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    p[5] = 0;
    *(f32 *)(p + 0x5C) = 1.66666662693f * (f32)*(s16 *)(D_0044ACA0 + p[0x21] * 6) / 256.0f;
    *(f32 *)(p + 0x60) = 2.14285707474f * (f32)*(s16 *)(D_0044ACA2 + p[0x21] * 6) / 256.0f;
    p[0x168] = *(s8 *)(D_0044ACA4 + p[0x21] * 6);
    if (*(s16 *)(q + 0x140) == 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
    func_001757E0(p, 0x17, p[0x168]);
}

extern u8 D_0044A410[], D_0044A412[], D_0044A414[], D_0044A416[];
extern void func_001754A0(u8 *, s32, s32);
extern void func_00175580(u8 *, s32, s32, s32);

void func_00198B50(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    if (q[4] == 2 || q[5] != 0) {
        p[5] = 3;
        func_001754A0(p, 0x1B, 4);
        return;
    }
    p[0x22] = (*(s8 *)(p + 0x22) + 4) & 0x7C;
    *(f32 *)(p + 0x34) = 1.66666662693f * (f32)*(s16 *)(D_0044A410 + p[0x22] * 2);
    *(f32 *)(p + 0x38) = 2.14285707474f * (f32)*(s16 *)(D_0044A412 + p[0x22] * 2);
    p[0x24] = *(s8 *)(D_0044A414 + p[0x22] * 2);
    if (*(s16 *)(q + 0x140) != 0) *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    func_00175580(p, 0x1B, 5, *(s16 *)(D_0044A416 + p[0x22] * 2));
}


extern void func_0018FDB0(u8 *);
extern void func_001E3B70(u8 *, s32);
extern void func_00191480(u8 *, u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001548D0(u8 *, f32 *, s32);
extern void func_00178F20(u8 *, u8 *);

void func_0029EC70(u8 *a, u8 *b) {
    f32 x, y;
    f32 v[4];
    s8 t;
    if ((s8)func_00175700(a) < 0) {
        u32 u = a[7];
        a[7] = u + 1;
        a[0x160] = 0x21;
    } else {
        t = *(s8 *)(a + 0x151);
        if (t >= 0) {
            if (t > 0) {
                *(s8 *)(a + 0x151) = 0;
                *(f32 *)(a + 0x60) += 10.7142848969f;
                *(u8 **)(b + 0x1C8) = a;
                b[0x1B5] = 0x3E;
                func_0018FDB0(a);
                func_001E3B70(b, 1);
                func_00191480(b, a, 1);
                func_001E3210(a, 0x24);
                v[0] = 0.0f;
                *(u32 *)&v[1] = 0x424DB6DB;
                func_001548D0(b, v, 3);
            }
            *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
            *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
            *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
            *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        }
    }
    x = *(f32 *)(b + 0x34);
    y = *(f32 *)(b + 0x38);
    func_00178F20(a, b);
    *(f32 *)(b + 0x34) = x;
    *(f32 *)(b + 0x38) = y;
}

extern u8 D_0044A510[], D_0044A512[], D_0044A514[], D_0044A516[];
void func_00198E30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    if (q[4] == 2 || q[5] != 0) {
        p[5] = 1;
        func_001754A0(p, 0x1B, 4);
        return;
    }
    p[0x22] = (*(s8 *)(p + 0x22) + 4) & 0x7C;
    *(f32 *)(p + 0x34) = 1.66666662693f * (f32)*(s16 *)(D_0044A510 + p[0x22] * 2);
    *(f32 *)(p + 0x38) = 2.14285707474f * (f32)*(s16 *)(D_0044A512 + p[0x22] * 2);
    p[0x24] = *(s8 *)(D_0044A514 + p[0x22] * 2);
    if (*(s16 *)(q + 0x140) != 0) *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    func_00175580(p, 0x1B, 5, *(s16 *)(D_0044A516 + p[0x22] * 2));
}
