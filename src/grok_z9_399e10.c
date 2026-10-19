typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_00399E10(u8 *p)
{
    unsigned int offset;
    s16 t;

    p[0x24] = 0;
    func_00175700(p);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        p[5]++;
        *(s16 *)(p + 0x1C) = p[0x1B7] ? 80 : 20;
        {
            u8 cmd = 60;
            p[0x1B5] = cmd;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(int *)(p + 0x1D8) = 0;
        }
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
    }
    func_001E7F60(p);
}
