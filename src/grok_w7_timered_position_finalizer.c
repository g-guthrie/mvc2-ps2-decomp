typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern void func_001266A0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_0018C6E0(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *func_001DA7F0(u8 *, int);
extern void func_00185960(u8 *, u8 *);
extern void func_00184540(u8 *);
void func_00308490(u8 *p)
{
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position __attribute__((aligned(16)));
    p[0x1B4] = 10;
    p[7] = 0;
    p[6] = 0;
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    func_001266A0(p, 5, 5);
    position.pair.bits[0] = 0xC2F00000;
    position.pair.bits[1] = 0x42CDB6DB;
    func_0015D010(p, position.pair.values);
    p[0x2BC] = 0;
    func_0018C6E0(p);
    func_001757E0(p, 21, 14);
    p[0x1B7] = 1;
    {
        u8 *event = func_001DA7F0(p, 4);
        if (event != 0)
            func_00185960(p, event);
        else
            func_00184540(p);
    }
}
