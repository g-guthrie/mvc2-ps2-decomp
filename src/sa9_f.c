typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/sa9_f.c "-O3 -Op -sdatathreshold 8" */

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7E;
extern G7E *D_004C2794;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad1[4];
    u8 b7;
    u8 pad2[0x34 - 8];
    f32 f34, f38;
    u8 pad3[0x5C - 0x3C];
    f32 f5c, f60;
    u8 pad4[4];
    f32 f68, f6c;
    u8 pad5[0x430 - 0x70];
    f32 f430;
} S7E;

void func_002C7E50(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001E3210(u8 *, s32);
    extern void func_00183D50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *s0, *s1, *s2, *s3;
    s3 = (f32 *)(p + 0x6C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    s0 = (f32 *)(p + 0x5C);
    ((S7E *)p)->f34 += ((S7E *)p)->f5c;
    ((S7E *)p)->f5c += ((S7E *)p)->f68;
    ((S7E *)p)->f38 += ((S7E *)p)->f60;
    ((S7E *)p)->f60 += ((S7E *)p)->f6c;
    func_00175700();
    if (q[2] == 0 && *(s8 *)(p + 0x1B2) != 0) {
        q[2] = 1;
        func_001E3210(p, 3);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (p[0x269] != 3) {
            p[0x1B5] = (p[0x1B7] != 0) ? 0x35 : 0x31;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1B5] = 0x43;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    if (*(f32 *)&p[0x38] <= *(f32 *)&p[0x430]) {
        u32 t = ((S7E *)p)->b7;
        ((S7E *)p)->b7 = t + 1;
        *(f32 *)&p[0x38] = *(f32 *)&p[0x430];
        p[0x20D] = 0;
        *(s32 *)s0 = 0;
        *(s32 *)s1 = 0;
        *(s32 *)s2 = 0;
        *(s32 *)s3 = 0;
        func_00183D50(p);
        func_001757E0(p, 0x15, 2);
    }
}
