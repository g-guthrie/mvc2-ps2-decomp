typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x160]; s8 b[8]; } S160;
typedef struct { f32 x, y, z; } V3;
extern void func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_00183D10(u8 *);
extern u8 *func_003749E0(u8 *, u8);
extern void func_001843A0(u8 *);
extern void func_00183d50(u8 *);
extern void func_001E3A40(u8 *);
extern s32 func_00175700(u8 *);
extern void func_003BD7F0(u8 *);
extern void func_003BD7A0(u8 *);
extern void func_001BAD70(u8 *);
extern void func_00175580(u8 *, s32, s32, s32);
extern s32 D_004C283C;
extern V3 D_004B7F30[];
extern void func_003B9220(u8 *);
extern void func_001E3710(u8 *, s32);
extern u8 *func_003DA750(int, int, int);
extern void func_00336900();
extern void func_00335950(u8 *);
static inline void reset_command(u8 *p, u8 command) {
    unsigned int offset;
    p[0x1b5] = command;
    p[0x1b2] = *(u16 *)(p+0x1c0) = 0;
    *(int *)(p+0x1d8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset+0x7c);
}

void func_001BAC90(u8 *p, S160 *q) {
    s8 *pp;
    s8 *s;
    s32 t;
    *(V3*)(p+0x34) = *(V3*)((u8*)q+0x34);
    if (p[1] != ((u8*)q)[1]) {
        func_001BAD70(p);
        return;
    }
    if (*(u16*)((u8*)q+0x168) != 0xF01) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    pp = q->b;
    t = pp[1];
    s = pp + 1;
    if (t != 0) {
        if ((s8)t == 0x10) {
            p[0x13C] = 0;
            *s = 0;
        } else {
            p[0x13C] = 1;
            func_00175580(p, 0x1B, p[0x168], *s - 1);
            *s = 0;
        }
    }
}

void func_00268DD0(u8 *p) {
    u8 *o;
    p[6]++;
    *(s16*)(p+0x1C) = 0x78;
    func_00185490(p);
    func_0018C4B0(p, 5);
    func_00183D10(p);
    p[0x20D] = 0;
    *(f32*)(p+0x38) = *(f32*)(p+0x430);
    reset_command(p, p[0x1B7]);
    p[0x151] = 0;
    func_001757E0(p, 0x15, 0x12);
    o = func_003749E0(p, 0);
    *(u8**)(p+0x14) = o;
    if (o == 0) func_001843A0(p);
}

void func_002703C0(u8 *p) {
    s16 v;
    f32 f;
    func_00175700(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    v = *(s16*)(p+0x1E);
    *(s16*)(p+0x1E) = v - 1;
    if (v == 0) {
        p[6]++;
        if (p[0x1E6] != 0) f = -1.6666666f; else f = 1.6666666f;
        *(f32*)(p+0x68) = f;
        func_001757E0(p, 2, 2);
    }
}

void func_002CF1D0(u8 *p) {
    u8 c = p[0x15B];
    if (c > 0) {
        if (!(*(f32*)(p+0x38) < 720.0f + *(f32*)(p+0x430))) {
            reset_command(p, 0x4E);
            *(s16*)(p+0x1C0) = 0;
        } else {
            reset_command(p, c);
            *(s16*)(p+0x1C0) = 0x10;
        }
        p[0x15B] = 0;
    }
}

void func_002FFF60(u8 *p) {
    f32 *a, *b;
    u8 *q;
    u32 t;
    a = (f32*)(p+0x60);
    b = (f32*)(p+0x6C);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (!(*(f32*)(p+0x430) < *(f32*)(p+0x38))) {
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        *(u32*)a = 0;
        *(u32*)b = 0;
        func_00183d50(p);
        p[6]++;
        func_001757E0(p, 0xF, 8);
        q = *(u8**)(p+0x1DC);
        q[0x20A] = 2;
        q[0x20D] = 2;
        q[0x1B5] = 0x23;
        p[0x1B5] = 0x23;
        q[0x1E6] = p[0x1E6];
        t = q[0x1E6];
        q[0x1E6] = t ^ 1;
        func_001E3A40(q);
    }
}

void func_00336840(void) {
    s32 i = 0;
    u8 *o;
    do {
        if ((o = func_003DA750(0, 6, 1)) == 0) return;
        o[0x23] = i;
        o[0x13C] = 1;
        *(u32*)(o+0x10) = (u32)func_00336900;
        *(s16*)(o+0xCC) = 0x23;
        *(s32*)(o+0x84) = D_004C283C;
        *(u32*)(o+0xD0) = 0x801;
        *(s16*)(o+0x140) = 1;
        *(V3*)(o+0x34) = D_004B7F30[o[0x23]];
        func_00335950(o);
        i++;
    } while (i < 3);
}

void func_00365E30(u8 *p) {
    func_00175700(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(f32*)(p+0x38) <= *(f32*)(*(u8**)(p+0x18)+0x430)) {
        p[5]++;
        *(f32*)(p+0x38) = *(f32*)(*(u8**)(p+0x18)+0x430);
        *(u32*)(p+0x118) = 0x3F800000;
        func_001757E0(p, 0x17, 8);
    }
}

void func_003B8690(u8 *p) {
    u8 *s = *(u8**)(p+0x18);
    func_003B9220(p);
    p[0x24] = 0xB;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(f32*)(p+0x34) = *(f32*)(s+0x34);
    *(f32*)(p+0x38) = *(f32*)(s+0x38);
    *(u32*)(p+0x54) = 0x4019999A;
    func_001E3710(p, 0x4C);
    reset_command(p, 0x3B);
    func_001757E0(p, 0x15, 0x19);
}

void func_003BB930(u8 *p) {
    s8 *r = (s8*)(p + 0xD0);
    if (p[6] == 0) {
        p[6]++;
        if (r[7] >= 0) func_003BD7F0(p);
        if (p[5] == 0) func_001757E0(p, 0x19, 0x17);
        else func_001757E0(p, 0x19, 0xA);
        func_003BD7A0(p);
    } else {
        if ((s8)func_00175700(p) < 0) {
            p[4]++;
            p[0x13C] = 0;
        } else {
            func_003BD7A0(p);
        }
    }
}

