typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern s32 func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_00282A60(u8 *);

void func_00282970(u8 *p)
{
    switch (p[0x1FC]) {
    case 2:
        if (p[6] != 0)
            func_00282A60(p);
        else if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        else if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t[p[2]] += 1;
            p[0x15B] = 0;
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        break;
    }
}
