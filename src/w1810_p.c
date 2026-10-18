typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct P {
    u8 p0[1]; u8 b1; u8 b2; u8 p3; u8 b4; u8 b5; u8 p6[0x1E]; u8 b24; u8 p25[0xB]; f32 f34; f32 f38; u8 p3c[0x14]; V3 v50;
    f32 f5c_unused;
} Pdummy;
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define V(p, o) (*(V3 *)((u8 *)(p) + (o)))
void func_001DFE40(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    s32 *d;
    s32 *s;
    u8 *r;
    s16 h;
    if (p[4] == 0) {
        p[4] = p[4] + 1;
        s = (s32 *)(q + 0xEC);
        d = (s32 *)(p + 0xEC);
        i = 0x31;
        do {
            *d = *s;
            i--;
            s++;
            d++;
        } while (i > 0);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        F32(p, 0x50) = F32(q, 0x50);
        F32(p, 0x54) = F32(q, 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        S8(p, 0x30) = S8(q, 0x30);
        V(p, 0x50) = V(q, 0x50);
        S8(p, 0x24) = S8(q, 0x24);
        r = *(u8 **)(p + 0x14);
        F32(p, 0x34) = F32(r, 0x34);
        F32(p, 0x38) = F32(r, 0x38);
        *(s16 *)(p + 0x1C) = 0x20;
        func_001757E0(p, 0x12, 6);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0092492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
    }
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[4] = 2;
    } else {
        F32(p, 0x34) += F32(p, 0x5C);
        F32(p, 0x5C) += F32(p, 0x68);
        F32(p, 0x38) += F32(p, 0x60);
        F32(p, 0x60) += F32(p, 0x6C);
    }
}
