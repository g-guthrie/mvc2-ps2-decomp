typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w1913_b.c "-O3 -sdatathreshold 8" */
typedef struct P21 { u8 pad0[0x34]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; } P21;
typedef struct H21 { u8 pad[0x7C]; s16 f7c[1]; } H21;
extern H21 *D_004C2794;
void func_0021E6C0(P21 *p) {
    extern void func_001861B0(P21 *);
    extern int func_001757E0(P21 *, int, int);
    extern void func_001E3710(P21 *, int);
    extern void func_001E3210(P21 *, int);
    extern void func_0018C4B0(P21 *, int);
    extern void func_00183D90(P21 *);
    extern void func_001863F0(P21 *);
    extern s32 func_00175700(P21 *);
    extern void func_001843A0(P21 *);
    u8 *pb = (u8 *)p;
    u32 t;
    if (pb[6] == 0) {
        func_001861B0(p);
        t = pb[6];
        pb[6] = t + 1;
        pb[0x20D] = 1;
        if (pb[0x212] == 0) {
            func_001757E0(p, 0x14, 8);
            pb[0x1B5] = 0x53;
            pb[0x1B2] = *(u16 *)(pb + 0x1C0) = 0;
            *(s32 *)(pb + 0x1D8) = 0;
            D_004C2794->f7c[pb[2]] += 1;
        }
        func_001E3710(p, 0x15);
        func_001E3210(p, 0x20);
        func_0018C4B0(p, 5);
    }
    if (pb[0x213] == 3)
        func_00183D90(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

typedef struct P26 { u8 pad0[0x1C]; s16 h1C; u8 pad1E[0x34 - 0x1E]; f32 f34, f38; u8 pad3C[0x5C - 0x3C]; f32 f5C, f60, f64, f68, f6C; u8 pad70[0x430 - 0x70]; f32 f430; } P26;
void func_002653D0(P26 *p) {
    extern int func_00175700(P26 *);
    extern void func_00183d50(P26 *);
    extern void func_001843A0(P26 *);
    u8 *pb = (u8 *)p;
    f32 *s0, *s1, *s2, *s3;
    s3 = &p->f6C;
    s2 = &p->f68;
    s1 = &p->f60;
    s0 = &p->f5C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->h1C != pb[0x1B7] + 1) {
        if (*(s8 *)(pb + 0x1B2) != 0) {
            p->h1C = p->h1C + 1;
            if (p->h1C < pb[0x1B7] + 2) {
                pb[0x1B5] = 0x37;
                pb[0x1B2] = *(u16 *)(pb + 0x1C0) = 0;
                *(s32 *)(pb + 0x1D8) = 0;
                D_004C2794->f7c[pb[2]] += 1;
            }
        }
    }
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        pb[0x20D] = 0;
        func_00183d50(p);
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001843A0(p);
    }
}

