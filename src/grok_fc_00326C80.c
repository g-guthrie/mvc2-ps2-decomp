/* ./try.sh src/grok_fc_00326C80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *v[3]; } Row;
extern Row D_004D18B8[];
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern void func_00186A60(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_00191210(u8 *);
extern void func_00180D20(u8 *, u8 *);

void func_00326C80(u8 *p)
{
    u8 *q = D_004D18B8[p[2]].v[p[0x26B]];

    p[0x425] = p[0x26B];
    D_004D18B8[p[2]].v[p[0x26B]] = p;
    q[0] = 1;
    q[0x13C] = 1;
    q[0x425] = 0;
    q[4] = 1;
    q[5] = 0;
    q[6] = 0;
    q[7] = 0;
    func_00186A60(q, 0x1C);
    q[0x26A] = 9;
    p[0x269] = p[0x268];
    q[0x269] = p[0x268];
    if (p[0x1E6] == 0)
        *(f32 *)(q + 0x34) = 133.3333282470703125f + D_004F1FCC;
    else
        *(f32 *)(q + 0x34) = D_004F1FC8 - 133.3333282470703125f;
    *(f32 *)(q + 0x38) = 137.14285278320312f + *(f32 *)(q + 0x430);
    q[0x208] = 8;
    q[0x159] = 0xFF;
    func_00185490(q);
    p[0x1B1] = 0;
    p[0x201] = 3;
    func_00191210(p);
    func_00180D20(q, p);
}
