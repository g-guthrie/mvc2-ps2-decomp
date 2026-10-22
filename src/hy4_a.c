typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct G { u8 pad[0x1C]; s32 f1C; } G;

extern G *D_004C2840;
extern void (*D_00454360[])(u8 *, u8 *);

void func_00267230(u8 *p) {
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00191210(u8 *);
    extern void func_00154470(u8 *, s32, s32, f32, f32);
    s16 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(u16 *)(p + 0x4F0) & 0x60) {
        t = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = t + 1;
        if (t > 0x96) {
            *(s16 *)(p + 0x1E) = 10;
            p[6]++;
            p[7] = 0;
            func_00176160(p, 0, p[0x25] + 6, 1);
            return;
        }
    } else {
        t = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = t + 1;
        if (t > 0x3C) {
            *(s16 *)(p + 0x1E) = 10;
            p[6]++;
            p[7] = 0;
            func_00176160(p, 0, p[0x25] + 6, 1);
            return;
        }
    }
    D_00454360[p[7]](p, (u8 *)((s32)p + 0x2B8));
    p[0x216] |= 0x80;
    p[0x1FF] = 2;
    func_00191210(p);
    if (!(D_004C2840->f1C & 1)) {
        func_00176160(p, 0, p[0x25] * 2 + 0x14, 1);
    } else {
        func_00176160(p, 0, p[0x25] * 2 + 0x15, 1);
    }
    if ((D_004C2840->f1C & 3) == 0) {
        func_00154470(p, 0, 0, 3.8f, 0.4f);
    }
}

#define F(p, n) (*(f32 *)((p) + (n)))
extern u8 *D_004C2794 __attribute__((section(".sdata")));

void func_00212410(u8 *p, u8 *q) {
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001861B0(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 counterOffset;
    u8 a;
    p[6]++;
    func_00175C00(p, 0);
    func_00185490(p);
    func_0018C4B0(p, 5);
    if (p[0x20D] == 2) {
        F(p, 0x5C) /= 16.0f;
        F(p, 0x60) /= 8.0f;
        F(p, 0x6C) /= 64.0f;
        *(u32 *)(p + 0x68) = 0;
        *(s16 *)(p + 0x1C) = 10;
        q[0] = 12;
        p[0x1B5] = 0x34;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        counterOffset = p[2] * 2;
        counterOffset += (u32)D_004C2794;
        counterOffset += 0x7C;
        ++*(s16 *)counterOffset;
        func_001757E0(p, 0x15, 3);
        return;
    }
    func_001861B0(p);
    func_00183D10(p);
    p[0x20D] = 0;
    a = *(s8 *)(p + 0x1B7) + 0x31;
    if (p[0x269] == 3) a = 0x41;
    p[0x1B5] = a;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    counterOffset = p[2] * 2;
    counterOffset += (u32)D_004C2794;
    counterOffset += 0x7C;
    ++*(s16 *)counterOffset;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2));
    if (p[0x1B7] == 0) {
        q[0] = 12;
        *(s16 *)(p + 0x1C) = 12;
    } else {
        q[0] = 14;
        *(s16 *)(p + 0x1C) = 10;
    }
}
