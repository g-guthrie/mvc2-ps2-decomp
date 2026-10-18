typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x7C];
    s16 h7C[1];
} G2EE;

extern G2EE *D_004C2794;
extern u8 D_004C1218[8];
extern u8 D_0045B840[];
extern u8 D_0045B810[];
extern u8 D_0045B820[];
extern u8 D_0045B830[];
extern s32 D_0045B6D0[];
extern s32 D_0045B708[];

void func_002EE480(u8 *p)
{
    extern void func_001861B0();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F1D90(u8 *);
    s32 i;
    u8 j;
    s32 a;
    s32 r;

    func_001861B0(p);
    p[7] = 0;
    p[6] = 0;
    i = p[0x1FC];
    if (p[0x20D] == 1) {
        i = (u8)(i + 6);
    }
    if (p[0x212] != 0) {
        i = (u8)(i + 3);
    }
    j = i;
    *(s32 *)(p + 0x334) = D_0045B840[j];
    r = j % 6;
    a = D_0045B6D0[r];
    if (*(s32 *)(p + 0x2D4) == 1) {
        a = D_0045B708[r];
    }
    *(s32 *)(p + 0x408) = a;
    p[0x1BB] = D_004C1218[p[0x1FC]];
    p[0x1B5] = D_0045B810[j];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, D_0045B830[j], D_0045B820[j]);
    func_002F1D90(p);
}
