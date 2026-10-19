typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175C00(u8 *, int);
extern void func_00318500(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);

void func_00318B60(u8 *p)
{
    unsigned int offset;
    u8 cmd;

    p[6]++;
    func_00175C00(p, 0);
    func_00318500(p);
    func_0018C4B0(p, 5);
    if (p[0x1B7] == 0) {
        cmd = 49;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    } else {
        cmd = 78;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    }
    func_001757E0(p, 22, ((p[0x1B7] << 1) + 6) & 0xFF);
    func_00183D10(p);
}
