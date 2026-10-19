/* Metrowerks 3.0: ./try.sh src/grok_q2_3e9c0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_0018C6E0(u8 *);

void residual_0023E9C0(u8 *p)
{
    struct {
        union { f32 values[3]; u32 bits[3]; } pos;
    } local;
    if (p[0x22] & 2) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    local.pos.bits[0] = 0xC36E5555;
    local.pos.bits[1] = 0x43294924;
    local.pos.bits[2] = 0;
    func_0015D010(p, local.pos.values);
    func_0018C6E0(p);
}
