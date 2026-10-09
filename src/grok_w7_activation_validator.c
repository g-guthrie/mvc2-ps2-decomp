typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern u8 D_004D18A0;
extern u8 D_004D18D6[];
extern int func_0018A580(u8 *);
extern void func_00186A60(u8 *, int);
extern void func_001DD920(u8 *, u8, u8);
/* jtbl_0045D2D0[0] is the one-argument actor callback for this gate. */
void func_0030FE70(u8 *p)
{
    u8 *state = p + 0x2B8;
    int mode;
    if (p[0x2DB] != 0)
        goto done;
    if (state[8] != 0)
        goto done;
    if (*(s16 *)(p + 0x434) >= 0x33)
        goto done;
    if (*(s8 *)(D_004D18D6 + p[2]) < 2)
        goto done;
    if (func_0018A580(p) == 0)
        goto done;
    mode = p[0x20D];
    if (mode == 2)
        goto done;
    if (mode == 3)
        goto done;
    if (D_004D18A0 == 5)
        goto done;
    if (D_004D18A0 == 6)
        goto done;
    if (p[0x425] != 0)
        goto done;
    state[8] = 1;
    state[0x21] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 29);
    func_001DD920(p, 16, 0);
done:
    return;
}
