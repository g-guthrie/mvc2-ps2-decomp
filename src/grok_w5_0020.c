typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001E3240(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_00126400(void);
extern void func_00199DE0(u8 *, int, int);
extern void func_0019A3D0(u8 *, int);
extern void func_0034FA80(u8 *, int);
extern void func_00212030(u8 *);
extern void func_002174F0(u8 *);
extern void func_00217650(u8 *);
extern void func_0020C0E0(u8 *, u8 *);
extern void func_0020D2F0(u8 *, u8 *);
extern void func_0020D250(u8 *, u8 *, int);
extern void func_0021C770(u8 *, u8 *);

void func_00210C70(u8 *p)
{
    if (!*(s8 *)(p + 0x1b4) || p[5])
        p[0x2bc] = 0;
}

void func_00207C30(u8 *p)
{
    *(f32 *)(p + 100) += *(f32 *)(p + 112);
    {
        s16 t = *(s16 *)(p + 28) - 1;
        *(s16 *)(p + 28) = t;
        if (t == 0) {
            p[6]++;
            *(s16 *)(p + 28) = 4;
        }
    }
}

void func_00213FD0(u8 *p)
{
    *(s32 *)(p + 92) = 0x41555555;
    *(s32 *)(p + 104) = 0xBED55555;
    if (p[486] == 0) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    *(s16 *)(p + 868) = 0;
    *(s16 *)(p + 870) = 0;
    *(s16 *)(p + 28) = 0;
}

void residual_00202E60(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        func_001843A0(p);
    }
}

void func_0020A880(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 1, 3);
    }
}

void func_0020C980(u8 *p, u8 *q)
{
    func_00175700(p);
    if (!*(s8 *)(p + 337)) {
        p[7]++;
        q[10] = 0;
    }
}

void residual_0020A5D0(u8 *p)
{
    p[7]++;
    func_0034FA80(p, 3);
    S(p, 28) = 24;
    func_001757E0(p, 0, 0);
}

void residual_00211E90(u8 *p)
{
    p[6]++;
    p[316] = 1;
    func_0019A3D0(p, 2);
    func_001757E0(p, 18, 0);
}

void func_0021F6F0(u8 *p)
{
    p[6]++;
    if (H(p, 730) == 1)
        func_001E3210(p, 21);
    func_001E3210(p, 33);
}

void func_0020F250(u8 *p)
{
    s8 *q = (s8 *)(p + 696);
    if (--q[6] < 0) {
        q[6] = 8;
        func_00199DE0(p, 1, 12);
    }
}

void func_0020C090(u8 *p, u8 *q)
{
    p[7]++;
    func_001757E0(p, 20, 3);
    func_0020C0E0(p, q);
}

void func_0020D2A0(u8 *p, u8 *q)
{
    q[9] = 0;
    q[10] = 0;
    p[490] = 0;
    p[488] = 1;
    func_001266A0(p, 0, 0);
    I(p, 92) = 0;
    I(p, 104) = 0;
    func_00184540(p);
}

void func_00211F30(u8 *p)
{
    func_00212030(p);
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[336] = 0;
        p[6]++;
        p[703] = 0;
        p[702] = 0;
    }
}

void func_002174A0(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (!p[530])
        func_002174F0(p);
    else
        func_00217650(p);
}

void func_0021C840(u8 *p, u8 *q)
{
    p[337] = 10;
    func_001E3710(p, 5);
    func_00126400();
    func_0021C770(p, q);
}

void func_0020C7B0(u8 *p, u8 *q)
{
    func_0020D2F0(p, q);
    if ((s8)func_00175700(p) < 0)
        func_0020D250(p, q, 0);
}

void func_0020D010(u8 *p, u8 *q)
{
    func_0020D2F0(p, q);
    if ((s8)func_00175700(p) < 0)
        func_0020D250(p, q, 0);
}

void func_00213F00(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3240(p, 31);
        func_001E3240(p, 32);
        p[525] = 0;
        func_001843A0(p);
    }
}
