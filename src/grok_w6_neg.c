typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00175700();
extern void func_001843A0(u8 *);
extern void func_001ECF90(u8 *);
extern void func_00368FB0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_0020D2F0(u8 *);

extern void func_00361830(u8 *, u8 *);
extern void func_00361850(u8 *, u8 *);
extern void func_00362C20(u8 *, u8 *);
extern void func_003A58E0(u8 *, u8 *);
extern void func_003B1A50(u8 *, u8 *);
extern void func_003B3810(u8 *, u8 *);
extern void func_003B3860(u8 *, u8 *);
extern void func_001CFEA0(u8 *);
extern void func_001D0100(u8 *);

void func_00361420(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_00361830(p, q);
    }
}

void func_003617D0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_00361850(p, q);
    }
}

void func_00362BC0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_00362C20(p, q);
    }
}

void func_00363070(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_00362C20(p, q);
    }
}

void func_003A5460(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003A58E0(p, q);
    }
}

void func_003B15B0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003B1A50(p, q);
    }
}

void func_003B3460(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003B3810(p, q);
    }
}

void func_003B37B0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003B3860(p, q);
    }
}

void func_001ECDC0(u8 *p)
{
    if ((s8)func_00175700() < 0)
        func_001843A0(p);
    else
        func_001ECF90(p);
}

void func_00368BE0(u8 *p)
{
    if ((s8)func_00175700() < 0)
        func_00368FB0(p);
    else
        func_001E7F60(p);
}

void func_001D00B0(u8 *p)
{
    func_001CFEA0(p);
    if ((s8)func_00175700() < 0) {
        p[4]++;
        func_001D0100(p);
    }
}

void func_0037F000(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    } else {
        func_001E7F60(p);
    }
}

void func_0020BF50(u8 *p)
{
    func_0020D2F0(p);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(short *)(p + 0x1c) = 0x12c;
        *(short *)(p + 0x1e) = 0;
        p[7] = 0;
    }
}


