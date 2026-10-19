typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern s32 D_004C0B08;
extern s32 D_004C0B0C;
extern s32 D_004C0B10;
extern s32 D_004C0B20;
extern s32 D_004C0B24;
extern s32 D_004C0B28;
extern s32 D_004C0B14;
extern s32 D_004C0B18;
extern s32 D_004C0B1C;
extern s32 D_004C0B2C;
extern s32 D_004C0B30;
extern s32 D_004C0B34;
extern void func_001E3710(u8 *, u8);
extern int func_001757E0(u8 *, s32, s32);
/* Partial actor view; no object is allocated by this type. */
typedef struct {u8 prefix[0x1B5];u8 action;} ActorActionView;
typedef char ActorActionOffsetCheck[((unsigned int)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];
extern void func_0038F440(void *, u8);

void func_0029C080(u8 *p) {
    u8 s;
    s32 a;
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x1B5] = 0xC;
        s = 0;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B08;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B20;
        p[0x1BB] = 0;
        break;
    case 1:
        s = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B0C;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B24;
        p[0x1BB] = 1;
        break;
    case 2:
        s = 2;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B10;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B28;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0xB, (u8)(s + 3));
    a = (s8)p[0x1EA];
    if ((a & 0xF) != 0) p[0x1EA] = a - 1;
}


void func_0029C1E0(u8 *p) {
    u8 s;
    s32 a;
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x1B5] = 0xF;
        s = 0;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B14;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B2C;
        p[0x1BB] = 0;
        break;
    case 1:
        s = 1;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B18;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B30;
        p[0x1BB] = 1;
        break;
    case 2:
        s = 2;
        p[0x1B5] = 0x11;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C0B1C;
        else *(s32 *)(p + 0x408) = (s32)&D_004C0B34;
        p[0x1BB] = 2;
        func_0038F440(p, 2);
        break;
    }
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0xC, (u8)(s + 3));
    a = (s8)p[0x1EA];
    if ((a & 0xF0) != 0) p[0x1EA] = a - 0x10;
}
