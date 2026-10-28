typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_nq76a;
typedef struct { u8 a, b, c; } T3_nq76a;

extern T3_nq76a D_0045BC80[];
extern u8 *D_004C2794;

void func_002F4CD0(u8 *p, u8 *q)
{
    extern void func_002F3DE0(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_0018C4B0(u8 *, int);
    extern int func_001757E0(u8 *, int, int);
    extern void func_002F4E00(u8 *, u8 *);
    u8 v;

    p[6]++;
    func_002F3DE0(p);
    func_00183D10(p);
    func_0018C4B0(p, 0x10);
    p[0x210] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    *(s16 *)(q + 2) = 0;
    *(V3_nq76a *)(q + 4) = *(V3_nq76a *)(p + 0x34);
    *(s16 *)q = p[0x1B7];
    func_001757E0(p, 0x15, D_0045BC80[*(u16 *)q].a);
    p[0x22] = D_0045BC80[*(u16 *)q].b;
    v = D_0045BC80[*(u16 *)q].c;
    if (p[0x269] == 3) v = 0x46;
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_002F4E00(p, q);
}
