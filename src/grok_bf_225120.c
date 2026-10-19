typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 t7c[1]; } G2;
extern G2 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00186A20(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00225210(u8 *);

void residual_00225120(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00186A20(p);
    p[0x1B5] = (s8)p[0x1B7] + 0x36;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->t7c[p[2]]++;
    func_0018C4B0(p, 5);
    func_001757E0(p, 0x15, ((p[0x1B7] ^ 1) + 8) & 0xFF);
    {
        u32 bits = 0x41000000;
        f32 eight = *(f32 *)&bits;
        *(f32 *)(p + 0x5C) /= eight;
        *(f32 *)(p + 0x60) /= eight;
        *(f32 *)(p + 0x68) /= eight;
        *(f32 *)(p + 0x6C) /= eight;
    }
    *(s16 *)(p + 0x1C) = 0x28;
    func_00225210(p);
}
