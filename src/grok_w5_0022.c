typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_0019C4A0(u8 *);
extern void func_0019D270(u8 *, int);
extern void func_0019D740(u8 *, int);
extern void func_00185870(u8 *, int);
extern void func_00226B20(u8 *);
extern void func_0022EEE0(u8 *);

void func_00227AF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        p[5]++;
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_0019D270(p, 1);
    }
}

void func_00228580(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 0x151)) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x10;
        *(s32 *)(p + 0x2DC) = 4;
        func_0019D740(p, 0);
    }
}

void func_00226C90(u8 *p)
{
    if (!p[0x212]) {
        if (*(s8 *)(p + 0x1EA) & 0xF)
            func_00226B20(p);
    } else if (*(s8 *)(p + 0x1EA) & 0xF0)
        func_00226B20(p);
}

void func_0022EF50(u8 *p)
{
    if (*(s8 *)(p + 0x2C9)) {
        p[7]++;
        p[0x169] = 0x13;
        p[0x168] = 5;
        func_001757E0(p, p[0x169], p[0x168]);
        func_0022EEE0(p);
    }
}

void func_00231270(u8 *p, u8 *q)
{
    p[7]++;
    func_001757E0(p, 0x16, 5);
    p[0x20B] = 0xC5;
    func_00185870(p, *(int *)(q + 4));
}

void func_002250A0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if ((s8)func_00175700(p) < 0) {
        q[1] = 3;
        q[0] = 1;
        func_0019C4A0(p);
        func_001843A0(p);
    }
}

