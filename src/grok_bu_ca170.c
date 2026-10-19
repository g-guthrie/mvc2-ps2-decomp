typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x1C]; u32 f1c; } G1;
extern G1 *D_004C2840;

extern void func_00175670(u8 *);

void func_001CA170(u8 *p)
{
    u8 *q;
    u8 *v;
    s8 st;
    int id = 0x1D;
    q = *(u8 **)(p + 0x18);
    v = *(u8 **)(p + 0x14);
    if (q[0x1E4] != id || q[0x1FD] != 1 || *(s8 *)(v + 0x151) == -1) {
        p[4] = 2;
        return;
    }
    st = (s8)(*(s8 *)(v + 0x151) & 1);
    p[0x13C] = st;
    if (st == 0)
        return;
    if (D_004C2840->f1c & 1) {
        *(u32 *)(p + 0x34) = 0xC3555555;
        *(u32 *)(p + 0x38) = 0x437CDB6D;
    } else {
        *(u32 *)(p + 0x34) = 0xC3805555;
        *(u32 *)(p + 0x38) = 0x43722492;
    }
    if (*(s16 *)(v + 0x140) != 0)
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(v + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(v + 0x38);
    func_00175670(p);
}
