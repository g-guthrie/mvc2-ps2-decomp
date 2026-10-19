/* Metrowerks 3.0: ./try.sh src/grok_q2_3e640.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_0023E6C0(u8 *, u8 *);

void residual_0023E640(u8 *p, u8 *q)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 0x14, 2);
    func_0023E6C0(p, q);
}
