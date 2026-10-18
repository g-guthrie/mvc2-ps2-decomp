typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_h;
extern G_h *D_004C2794;

void func_00263C40(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    u8 v;
    u32 t;
    u8 *a2, *a3, *t0, *t1;
    switch (p[0x1FC]) {
    case 2:
        if (func_00175700(p) < 0) {
            func_00184540(p);
            return;
        }
        t = p[0x15B];
        if (t == 0)
            return;
        v = t;
        if (v == 1)
            p[0x1B5] = 0xE;
        a2 = p + 0x1C0;
        a3 = p + 0x1B2;
        t0 = p + 0x1D8;
        t1 = p + 2;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        if (p[0x15B] == 2)
            p[0x1B5] = 0x1C;
        *a3 = *(u16 *)a2 = 0;
        *(s32 *)t0 = 0;
        D_004C2794->f7c[*t1]++;
        p[0x15B] = 0;
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0)
            func_00184540(p);
        break;
    }
}
