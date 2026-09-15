typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00185870(u8 *, u8 *);
extern void func_00174910(u8 *, int);
extern void func_001E7F60(u8 *);
extern void func_00368FB0(u8 *);
extern void func_0036F5A0(u8 *);
extern void func_00370730(u8 *);
extern void func_00372B50(u8 *);
extern void func_00373A80(u8 *);

extern void (*jtbl_00463E60[])(u8 *);
extern void (*jtbl_00463EF8[])(u8 *);
extern void (*jtbl_00463FB0[])(u8 *);
extern void (*jtbl_00463E90[])(u8 *);
extern void (*jtbl_00463EB0[])(u8 *);


void func_00377860(s8 *p, s8 *q)
{
    s8 *r = q + 0x2B8;
    if (p[316]) {
        p[316] = 0;
        *r = *r - 1;
        if (*r < 0)
            *r = 0;
    }
}

void func_0036F560(u8 *p, u8 *q, u8 **r)
{
    if (*r) {
        u8 *s = *(u8 **)(p + 452);
        s[523] = 194;
        q[523] = 194;
        func_00185870(p, s);
    }
}

void func_003706F0(u8 *p, u8 *q, u8 **r)
{
    if (r[2]) {
        u8 *s = *(u8 **)(p + 452);
        s[523] = 194;
        q[523] = 194;
        func_00185870(p, s);
    }
}

void func_003749A0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (q[484] == 29 && q[509] == 6)
        return;
    p[4] = 2;
    p[316] = 0;
}

void func_003654D0(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 337))
        p[5] = 0;
    func_001E7F60(p);
}

void func_0036EAA0(u8 *p, u8 *q)
{
    u8 *s = *(u8 **)(p + 452);
    s[523] = 194;
    q[523] = 194;
    func_00185870(p, s);
    s[522] = 6;
}

int func_003760D0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (q[1061] != p[35]) {
        p[5] = 4;
        func_001757E0(p, 23, 3);
        return 1;
    }
    return 0;
}

void func_00370610(u8 *p)
{
    s16 t;
    func_00370730(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_00372310(u8 *p)
{
    func_00372B50(p);
    jtbl_00463E60[p[4]](p);
}

void func_0036A710(u8 *p, u8 *q)
{
    s32 v = p[7] - 1;
    p[7] = v;
    if (!(v & 0xff)) {
        p[6]++;
        func_001757E0(q, 13, 16);
    }
}

void func_0036F450(u8 *p)
{
    func_0036F5A0(p);
    if (*(s8 *)(*(u8 **)(p + 24) + 337) == 15) {
        p[4]++;
        p[316] = 0;
    }
}

void func_0036FC70(u8 *p)
{
    if (*(s8 *)(p + 339) < 0) {
        p[5]++;
        func_001757E0(p, 23, 26);
    } else
        func_00175700(p);
}

void func_0036FEE0(u8 *p)
{
    if (*(s8 *)(p + 339) < 0) {
        p[5]++;
        func_001757E0(p, 23, 27);
    } else
        func_00175700(p);
}

void func_00374630(u8 *p)
{
    jtbl_00463EF8[p[6]](p);
    (*(u8 **)(p + 24))[510] = 1;
}

void func_00368BE0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00368FB0(p);
    else
        func_001E7F60(p);
}

void func_00360FE0(u8 *p)
{
    func_00174910(p, 1600);
    func_001E7F60(p);
    if (*(s8 *)(p + 434) || *(s8 *)(p + 435))
        p[4]++;
}

void func_00376110(u8 *p)
{
    if (!func_003760D0(p)) {
        func_00175700(p);
        p[36] = 0;
        if (*(s8 *)(p + 337))
            p[5]++;
    }
}

void func_00376660(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (q[1061] != p[35]) {
        p[4] = 2;
        return;
    }
    jtbl_00463FB0[p[5]](p);
}

void func_0037F000(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    } else
        func_001E7F60(p);
}

void func_00372E70(u8 *p)
{
    if (p[4] < 2)
        func_00373A80(p);
    jtbl_00463E90[p[4]](p);
}

void func_00373B10(u8 *p)
{
    if (p[4] < 2)
        func_003749A0(p);
    jtbl_00463EB0[p[4]](p);
}
