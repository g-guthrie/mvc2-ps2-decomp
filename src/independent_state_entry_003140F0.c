typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_003141E0(u8 *, void *);

void func_003140F0(u8 *p, void *context)
{
    u8 *state = (u8 *)context;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[7]++;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    state[0x13] = 0;
    state[2] = 0;
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 0xB);
    func_003141E0(p, state);
}
