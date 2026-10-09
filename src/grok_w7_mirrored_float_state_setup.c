typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern void func_0015D010(u8 *, f32 *);
extern void func_00176160(u8 *, int, int, int);
extern void func_00328E60(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_0030BEB0(u8 *p)
{
    u8 *q;
    s16 toggled;
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position __attribute__((aligned(16)));
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if ((p[0x22] & 1) != 0) {
        toggled = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = toggled;
        p[0x1E6] = toggled;
        q = *(u8 **)(p + 0x1DC);
        toggled = q[0x1E6] ^ 1;
        *(s16 *)(q + 0x140) = toggled;
        ((u8 *)(*(u32 *)(p + 0x1DC)))[0x1E6] = toggled;
    }
    position.pair.bits[0] = 0xC2855555;
    position.pair.bits[1] = 0x43809249;
    func_0015D010(p, position.pair.values);
    func_00176160(p, 1, 5, 1);
    ((u8 *)(*(u32 *)(p + 0x1DC)))[0x23E] = 3;
    ((u8 *)(*(u32 *)(p + 0x1DC)))[0x23C] = 3;
    func_00328E60(*(u8 **)(p + 0x1DC));
    p[0x1B4] = 10;
    func_001757E0(p, 15, 4);
}
