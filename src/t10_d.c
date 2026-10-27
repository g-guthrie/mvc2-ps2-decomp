typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00448430[];
extern void *func_003A23F0(u8 *p, u8 a, u8 b);
extern void func_0018F9E0();
extern void func_00190540(void *p, s32 a);
extern void func_001902F0(void *p);
extern u8 *D_004C2794;
extern s32 func_00175670();
extern void func_001D0F70(void *a, void *b);
extern s32 func_00175700();
extern void func_00313BF0();
extern void func_00313B80();
extern void func_00313C40();
extern void func_00313C70();
extern void func_001E3710();
extern void func_001843A0();
extern s32 func_003CE510();
extern void func_00175910();
extern void func_0035B160();
extern u8 D_004F1F45;
extern u8 D_004F1F46;
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x1C]; f32 f58; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0x430 - 0x70]; f32 f430; } F;
extern void func_001757E0();
extern void func_00183d50();
extern s32 func_00189B40();
extern s8 D_004F7FC8[];

void func_00182300(u8 *p) {
    if (p[0x210] == 1 && *(f32 *)(p + 0x60) <= 0.0f) {
        p[0x210] = 2;
        *(f32 *)(p + 0x6C) = 2.1428570747f * (f32)D_00448430[p[1]] / 256.0f;
    }
}

void func_00207220(F *p) {
    f32 *a3, *t0, *t1, *t2;
    a3 = &p->f5c;
    t1 = &p->f68;
    t0 = &p->f60;
    t2 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        p->f38 = p->f430;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        *(s32 *)t2 = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3710(p, 0x2F, t + 1);
    }
}

void func_002B0A80(F *p) {
    f32 *v1, *a3, *t0, *t1;
    func_00175700(p);
    v1 = &p->f5c;
    t0 = &p->f68;
    a3 = &p->f60;
    t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        *((u8 *)p + 6) = 9;
        *(s32 *)v1 = 0;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        p->f38 = p->f430;
        func_001757E0(p, 0x16, 8);
        func_00183d50(p);
    }
}

void func_00317DE0(F *p) {
    f32 z = 0.0f;
    f32 *a;
    f32 *b;
    if ((s8)func_00175700(p) >= 0) {
        a = &p->f5c;
        b = &p->f68;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (!(p->f5c * p->f68 < z)) {
            *a = z;
            *b = z;
        }
    } else {
        *(s32 *)&p->f5c = 0;
        *(s32 *)&p->f60 = 0;
        *(s32 *)&p->f68 = 0;
        *(s32 *)&p->f6c = 0;
        func_001843A0(p);
    }
}

void func_003A2BF0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        if (func_003A23F0(p, 4, 0) != 0) {
            if (func_003A23F0(p, 4, 1) == 0) p[4] = 2;
        }
        *(s16 *)(p + 0x1C) = 10;
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
    }
}

