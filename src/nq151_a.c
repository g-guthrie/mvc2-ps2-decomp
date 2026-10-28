typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G67a;
extern G67a *D_004C2794;
extern u8 D_004C1630[8];
extern u8 D_0045D120[];
extern u8 D_0045D0F0[];
extern u8 D_0045D110[];
extern u8 D_0045D100[];
extern s32 D_0045CFD0[];

void func_0030CE90(u8 *p) {
    extern void func_001861B0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001DD470(u8 *, s32);
    s32 idx;
    u8 *s6, *s1, *s2, *s3, *s4;
    u32 a;
    func_001861B0(p);
    p[7] = 0;
    p[6] = 0;
    a = p[0x1FC];
    if (p[0x20D] == 1) a = (a + 6) & 0xFF;
    if (p[0x212] != 0) a = (a + 3) & 0xFF;
    idx = a & 0xFF;
    *(s32 *)(p + 0x334) = D_0045D120[idx];
    *(s32 *)(p + 0x408) = D_0045CFD0[idx % 6];
    p[0x1BB] = D_004C1630[p[0x1FC]];
    p[0x1B5] = D_0045D0F0[idx];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    s6 = p + 0x1B5; s1 = p + 0x1C0; s2 = p + 0x1B2; s3 = p + 0x1D8;
    s4 = p + 2;
    func_001757E0(p, D_0045D110[idx], D_0045D100[idx]);
    if (idx == 5) {
        if ((*(u16 *)(p + 0x20E) & 0x400) != 0) {
            *s6 = 0x13;
            *s2 = *(u16 *)s1 = 0;
            *(s32 *)s3 = 0;
            D_004C2794->f7c[*s4]++;
            func_001757E0(p, 8, 3);
        }
    }
    if (idx == 2) func_00176160(p, 1, 0xB, 1);
    if (idx == 7) func_001DD470(p, 2);
}
