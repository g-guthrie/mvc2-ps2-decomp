/* Metrowerks 3.0: ./try.sh src/grok_noph_2fa9e0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002FAAC0(u8 *, u8 *);

void residual_002FA9E0(u8 *p, u8 *q)
{
    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00183D10(p);
    p[437] = 56;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 9);
    q[22] = 0;
    func_002FAAC0(p, q);
}
