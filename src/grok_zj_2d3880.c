typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004B75AA;
extern u8 D_004B75A8[];
extern void func_001E3210(u8 *, int);
extern void func_002D3230(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002D3880(u8 *p)
{
    unsigned int offset;

    *(u16 *)(p + 0x2BA) = 0;
    func_001E3210(p, 22);
    func_002D3230(p);
    func_0018C4B0(p, 8);
    func_00183D10(p);
    if (p[0x1FD] == 8) {
        {
            u8 cmd = D_004B75AA;
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
        }
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
        p[6] += 3;
        func_001757E0(p, 21, 14);
        return;
    }
    if (p[0x269] == 3) {
        {
            u8 cmd = 52;
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
        }
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    } else {
        {
            u8 cmd = D_004B75A8[p[0x1B7]];
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
        }
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    }
    if (p[0x1B7] == 0) {
        p[6] += 3;
        func_001757E0(p, 21, 12);
    } else {
        p[6] += 1;
        func_001757E0(p, 21, 10);
    }
}
