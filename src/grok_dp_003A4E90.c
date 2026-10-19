typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175910(u8 *, int, int, int);

typedef struct { f32 a, b, c, d; } Q;

void func_003A4E90(u8 *p, u8 *q)
{
    Q *s0;
    int i;
    u8 *src;
    int rec;
    int a;
    int b;

    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x88);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x8C);
    *(u16 *)(p + 0x168) = *(u16 *)(p + 0x90);
    rec = *(volatile int *)(p + 0x94);
    a = p[0x169];
    b = p[0x168];
    s0 = (Q *)(p + 0x88);
    func_00175910(p, a, b, rec);
    i = 0;
    do {
        Q t = s0[1];
        s0[0] = t;
        s0++;
        i++;
    } while (i < 3);
    if (!p[0x20]) {
        s0->a = *(f32 *)(q + 0x34);
        s0->b = *(f32 *)(q + 0x38);
        *(u32 *)&s0->c = *(u16 *)(q + 0x168);
        *(u32 *)&s0->d = q[0x15B];
    } else {
        src = *(u8 **)(p + 8);
        s0->a = *(f32 *)(src + 0x34);
        s0->b = *(f32 *)(src + 0x38);
        *(u32 *)&s0->c = *(u16 *)(src + 0x168);
        *(u32 *)&s0->d = src[0x15B];
    }
}
