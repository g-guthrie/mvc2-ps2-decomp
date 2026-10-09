typedef unsigned char u8;
/* Retail offsets occupy a 16-byte-aligned stack slot; the helper reads x/y. */
typedef float PlanarOffset[2] __attribute__((aligned(16)));
extern void func_0015D010(u8 *,float *);
extern void func_001266A0(u8 *,int,int);
extern void func_0018C6E0(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_00214B00(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,1);
}
void func_00214B60(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,2);
}
void func_00214BC0(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,3);
}
void func_00214CB0(u8 *p) {
 PlanarOffset position;position[0]=-53.33333206176757812500f;position[1]=171.42855834960937500000f;
 func_0015D010(p,position);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,8);
}

void func_002F6270(u8 *p)
{
    PlanarOffset position;
    func_001266A0(p, 5, 5);
    *(unsigned int *)(p + 92) = 0;
    *(unsigned int *)(p + 96) = 0;
    *(unsigned int *)(p + 104) = 0;
    *(unsigned int *)(p + 108) = 0;
    p[525] = 0;
    *(float *)(p + 56) = *(float *)(p + 1072);
    position[0] = -213.3333282470703125f;
    position[1] = 137.142852783203125f;
    func_0015D010(p, position);
    func_001757E0(p, 15, 1);
}

void func_002F62F0(u8 *p)
{
    PlanarOffset position;
    func_001266A0(p, 5, 5);
    *(unsigned int *)(p + 92) = 0;
    *(unsigned int *)(p + 96) = 0;
    *(unsigned int *)(p + 104) = 0;
    *(unsigned int *)(p + 108) = 0;
    p[525] = 0;
    *(float *)(p + 56) = *(float *)(p + 1072);
    position[0] = -213.3333282470703125f;
    position[1] = 137.142852783203125f;
    func_0015D010(p, position);
    func_001757E0(p, 15, 2);
}

void func_002F6370(u8 *p)
{
    PlanarOffset position;
    func_001266A0(p, 5, 5);
    *(unsigned int *)(p + 96) = 0x41092492;
    *(unsigned int *)(p + 108) = 0xBF4DB6DB;
    if (p[528] != 0) {
        *(float *)(p + 92) /= 2.0f;
        *(float *)(p + 104) /= 2.0f;
    }
    position[0] = -106.66666412353515625f;
    position[1] = 171.428558349609375f;
    func_0015D010(p, position);
    func_001757E0(p, 15, 3);
}

void func_002F1780(u8 *p)
{
    u8 mode = p[0x20B] & 0x3F;

    if (mode == 0)
        p[0x1E6] ^= 1;

    if ((p[0x22] & 1) == 0) {
        *(short *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }

    {
        /* The helper reads two floats; padding preserves retail's 16-byte slot. */
        struct { union { float values[2]; int bits[2]; } offsets; int padding[2]; } position;
        position.offsets.bits[0] = 0xC262AAAA;
        position.offsets.bits[1] = 0x43362492;
        func_0015D010(p, position.offsets.values);
    }

    func_001266A0(p, 5, 5);
    if ((p[0x20B] & 0x3F) != 0)
        p[0x1B4] = 10;
    func_001757E0(p, 15, p[0x20B] & 0x3F);
    func_0018C6E0(p);
}

void func_002D0590(u8 *p)
{
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(short *)(p + 0x140) = p[0x1E6];
    }

    func_001266A0(p, 5, 5);
    {
        struct { union { float values[2]; unsigned int bits[2]; } offset; unsigned int padding[2]; } position;
        position.offset.bits[0] = 0xC2A6AAAA;
        position.offset.bits[1] = 0x431E9249;
        func_0015D010(p, position.offset.values);
    }
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 15, 1);
}
