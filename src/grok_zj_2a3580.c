typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001CBDA0(u8 *, int, int);
extern void func_001757E0(u8 *, int, int);
typedef struct { f32 x, y; } Pair;
extern Pair data_f32_00458580[];

void residual_002A3580(u8 *p)
{
    unsigned int offset;
    u8 cmd;

    p[6]++;
    cmd = p[0x1B7] ? 57 : 56;
    p[0x1B5] = cmd;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(int *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    func_00183D10(p);
    *(short *)(p + 0x366) = 0;
    *(short *)(p + 0x1C) = 30;
    *(f32 *)(p + 0x68) = p[0x1E6] ? data_f32_00458580[p[0x1B7]].x : -data_f32_00458580[p[0x1B7]].x;
    *(f32 *)(p + 0x60) = p[0x1E6] ? data_f32_00458580[p[0x1B7]].y : -data_f32_00458580[p[0x1B7]].y;
    func_001CBDA0(p, 0, 0);
    func_001757E0(p, 21, (unsigned char)(p[0x1B7] ? 9 : 8));
}
