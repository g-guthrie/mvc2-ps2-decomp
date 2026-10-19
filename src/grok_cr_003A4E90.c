typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x;
    f32 y;
    u32 a;
    u32 b;
} Rec;

extern void func_00175910(u8 *, u8, u8, int);

void func_003A4E90(u8 *p, u8 *q)
{
    Rec *s0;
    int i;
    u8 *src;

    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x88);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x8C);
    *(u16 *)(p + 0x168) = *(u16 *)(p + 0x90);
    s0 = (Rec *)(p + 0x88);
    func_00175910(p, p[0x169], p[0x168], *(int *)(p + 0x94));
    i = 0;
    do {
        s0[0] = s0[1];
        s0++;
        i++;
    } while (i < 3);
    if (!p[0x20]) {
        s0->x = *(f32 *)(q + 0x34);
        s0->y = *(f32 *)(q + 0x38);
        s0->a = *(u16 *)(q + 0x168);
        s0->b = q[0x15B];
    } else {
        src = *(u8 **)(p + 8);
        s0->x = *(f32 *)(src + 0x34);
        s0->y = *(f32 *)(src + 0x38);
        s0->a = *(u16 *)(src + 0x168);
        s0->b = src[0x15B];
    }
}
