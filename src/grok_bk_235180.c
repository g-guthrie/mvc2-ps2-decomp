typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00174170(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001266A0(u8 *, s32, s32);

void residual_00235180(u8 *p, u8 *q)
{
    u8 kind;

    p[6]++;
    kind = p[0x20];
    if (kind == 4)
        goto L134;
    if (kind == 3)
        goto L134;
    if (kind == 1)
        goto L134;
    if (kind == 2) {
        func_001757E0(p, 0x13, 2);
        return;
    }
    if (kind != 0)
        return;
    p[0x21] = (u8)(func_00174170() & 1);
    if (p[0x21]) {
        func_001757E0(p, 0x13, 1);
        q[0x39] = 0;
        func_001266A0(p, 1, 0xD);
    } else {
        func_001757E0(p, 0x13, 0);
    }
    return;
L134:
    func_001757E0(p, 0x13, 3);
}
