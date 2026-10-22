typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;

typedef struct { u8 *x, *y, *z; } E3;
typedef struct { u8 pad[0x18]; E3 e[4]; } P3;

void func_003D8BF0(u8 *p)
{
    extern void func_00191210(u8 *);
    extern void func_001E42D0(s32);
    extern void func_00135DB0(s32);
    s16 v;
    u32 t;
    u8 *q;

    v = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = v;
    if (v > 0) return;
    func_00191210(*(u8 **)(p + 0x18));
    func_00191210(*(u8 **)(p + 0x1C));
    func_00191210(*(u8 **)(p + 0x20));
    func_00191210(*(u8 **)(p + 0x24));
    func_00191210(*(u8 **)(p + 0x28));
    func_00191210(*(u8 **)(p + 0x2C));
    t = p[0x45];
    p[0x45] = t + 1;
    if (*(s8 *)(p + 0x3E) >= 0) {
        if (*(s8 *)(p + 0x3E) != 0) q = *(u8 **)(p + 0x18);
        else q = *(u8 **)(p + 0x24);
        if (p[0x48] == 8) {
            if (*(s8 *)(D_004C2840 + 0xAF) != 0) {
                if ((*(u32 *)(q + 0x428) & 0x3000000) != 0) {
                    p[1] = 2;
                    *(s16 *)(p + 0x12) = 0x168;
                    p[0] = 7;
                    return;
                }
            }
        }
    }
    *(s16 *)(p + 0x12) = 0x78;
    p[0] = 8;
    func_001E42D0(0x3C);
    if (*(s8 *)(p + 0x3E) >= 0) {
        q = *(u8 **)(p + 0x18);
        if (*(s8 *)(p + 0x3E) != 0) q = *(u8 **)(p + 0x24);
        if (*(s8 *)(q + 0x539) == 0) {
            P3 *r = (P3 *)p;
            s16 s0;
            s0 = *(s16 *)(r->e[q[2]].x + 0x434);
            s0 += *(s16 *)(r->e[q[2]].y + 0x434);
            s0 += *(s16 *)(r->e[q[2]].z + 0x434);
            if (s0 == 0x1B0) func_00135DB0(3);
            else func_00135DB0(0x83);
            return;
        }
    }
    p[0] = 9;
    if (p[0x48] == 8) {
        if (*(s8 *)(D_004C2840 + 0xAF) != 0) {
            if (p[0x45] == 3) {
                *(s16 *)(p + 0x12) = *(s16 *)(p + 0x12) + 0x5A;
            }
        }
    }
}
