typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00184540();
extern u8 D_00448DF0[];
extern u32 func_00174170();
void func_00182C30(u8 *p, s32 a) {
    s16 v = a + (s8)D_00448DF0[func_00174170() & 0x1F];
    *(s16 *)(p + 0x270) = v;
    if (v <= 0) *(s16 *)(p + 0x270) = 1;
}

extern void func_00175C00();
extern void func_003DAA40();
void func_00329050(u8 *p, u8 *q) {
    if (q[0x23E] == 3) {
        s8 v = *(s8 *)(q + 0x23D) - 1;
        *(s8 *)(q + 0x23D) = v;
        if (v < 0) q[0x23D] = 0;
    }
    func_00175C00(q, 1);
    func_003DAA40(p);
}

extern s32 func_00175700();
extern void func_003DBAF0(u8 *, s32, s32, s32);

void func_00349C30(u8 *p) {
    u8 *o = *(u8 **)(p + 0x14);
    f32 a = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + a;
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + *(f32 *)(p + 0x60);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}

extern void func_001BE700();
void func_001BE690(u8 *p, u8 *q) {
    if (q[4] != 0 && q[0x1E4] == 0) {
        u32 t = p[5]; p[5] = t + 1;
        *(s16 *)(p + 0x1C) = (func_00174170() & 7) + 8;
        p[0x23] = 0;
        func_001BE700(p, q);
    }
}

typedef unsigned long long u64;
extern void func_003DBAF0(u8 *, s32, s32, s32);
extern void func_003DBBD0(u8 *, s32);
extern void func_001757E0();
void func_00325960(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0x1E;
            func_001757E0(p, 0x16, 0x15);
        }
    }
}

extern void func_001BAD70();
extern s32 func_00175670();
typedef struct { f32 x, y, z; } V3;
extern s32 func_0016B250();
extern void func_0016B0C0();
extern s32 func_00166C80();
s32 func_00166410(u8 *p, u8 *q) {
    u8 *r = p + 0x2B8;
    if (!func_0016B250(p, 4)) return 0;
    func_0016B0C0(p, q, 0);
    return func_00166C80(p, q, r[0xE] == 0);
}

extern void func_0013B6A0();
extern void func_0013B770();
typedef void (*Mvc2StateCallback)(u8 *);
extern Mvc2StateCallback jtbl_00440330[];
void func_0013B4A0(u8 *p) {
    u8 *state = *(u8 **)(p + 0x18);
    jtbl_00440330[state[4]](p);
}

void func_0013B4D0(u8 *p) {
    p[0x13C] = 0;
}

void func_0013B4E0(u8 *p) {
    switch (p[5]) {
    case 0:
        p[5] = p[5] + 1;
    case 1:
        if (p[0x21] != *(s8 *)(*(u8 **)(p + 0x14) + 0x4DD))
            p[0x13C] = 0;
        else
            p[0x13C] = 1;
        func_0013B6A0(p);
        func_0013B770(p);
    }
}


extern void func_0011D8F8();
extern void func_0018EA00();
extern void func_0018E810();
void func_0018E260(u8 *p, u8 *q) {
    p[0x248] = 1;
    p[0x247] = 10;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    func_0018EA00(p, q);
    func_0018E810(p, q);
    func_001757E0(p, 0xD, 0x1C);
}

extern s32 func_00174470();
extern void func_00350FD0();
extern void func_001843A0();
void func_002D7E00(u8 *p) {
    if (*(s8 *)(p + 0x1B2) & 1) *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        p[0x2B8] = 0;
        func_001843A0(p);
    }
}

extern void func_003A5000();
void func_003A53E0(u8 *p, u8 *q) {
    s32 v;
    func_00175700();
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    v = *(s16 *)(p + 0x1C);
    func_003A5000(p, 1, v & 1, v & 3);
    if (q[0x2B8] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 6);
    }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_001E7F60();
extern void func_00390370();
extern u8 *func_003DA750();
void func_00390300(u8 *p, s32 a) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00390370;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = a;
        *(s16 *)(r + 0x26) = 0x1F01;
        *(u32 *)(r + 0xD0) = p[0x169];
        *(u32 *)(p + 0x30C) = 1;
    }
}

void func_002AC530(u8 *p) {
    u8 *q = p + 0x2B8;
    u8 *r = (u8 *)((u32)q + 0xF);
    if (*(s8 *)(p + 0x2C7) != 0 && *(s32 *)(p + 0xD0) == 0) {
        if (p[5] != 0 || p[0x1E4] != 0x15 || (p[0x1FD] != 0 && p[0x1FD] != 0xD))
            *r = 0;
    }
}

u8 func_00186120(u8 *p) {
    if (*(f32 *)(p + 0x38) == *(f32 *)(p + 0x430)) {
        return *(s8 *)(p + 0x224) = 0;
    }
    func_00184540();
    return 1;
}
