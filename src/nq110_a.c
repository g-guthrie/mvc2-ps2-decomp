typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern s8 *D_004C2840;
extern volatile s32 D_004C28AC;
extern volatile s32 D_004C28B8;
extern s32 D_004C281C;
extern u8 D_004F20B0[];
extern u8 D_004B5380[];

void func_0016FFC0(void)
{
    extern void func_0016F4D0(s32, s32);
    extern void func_0016F4B0(s32, s32, s32);
    extern void func_004161D0(s32 *, s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_001E6B80(s32, s32);
    extern void func_001E6670(s32, s32, s32, s32, s32);
    extern void func_0016F530(s32, s32, s32, s32, s32, s32);
    s32 buf[8];
    s32 ch;
    s32 i;
    s32 k;
    s32 off;
    s32 c;
    s32 *q;
    s32 base;
    u8 *e;
    s32 b;
    s8 *pp;
    s32 A0, A1, A2, A3, A4;
    ch = D_004C2840[0x9F];
    b = D_004C2840[0xB1];

    k = 9;
    if (b == 1) k = 0xD;
    if (b == 2) k = 9;
    A1 = D_004C28B8;
    A0 = D_004C28AC;
    func_0016F4D0(A0, A1);
    i = 0; off = 0;
    do {
        A2 = D_004C28B8;
        func_0016F4B0(k + i, A2 + 0x1D0000 + off, A2);
        i++; off += 0x10000;
    } while (i < 3);
    b = D_004C2840[0xB1];
    base = D_004C28B8;
    c = 0xB;
    if (b == 1) c = 0xF;
    if (b == 2) c = 0xB;
    q = (s32 *)((c << 4) + base + 0x18);
    func_004161D0(buf, *q);
    func_003DCDC0(*(s32 *)((u8 *)D_004C2840 + 0x98), *q, buf[6]);
    pp = D_004C2840;
    e = D_004F20B0 + ch * 0x5B8;
    b = pp[0xB1];
    if (b == 1) {
        func_001E6B80(*(s8 *)(e + 0x53B), base);
    } else {
        c = b != 0 ? 8 : 8;
        func_001E6670(*(s32 *)(e + 0x548), *(s32 *)(e + 0x54C),
                      *(s32 *)((c << 4) + base + 8), 4, (s32)D_004B5380);
    }
    A2 = D_004C28AC;
    A0 = 0x810;
    A3 = D_004C28B8;
    A4 = 6;
    A1 = D_004C281C;
    func_0016F530(A0, A1, A2, A3, A4, 0);
}
