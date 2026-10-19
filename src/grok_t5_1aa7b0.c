typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G7;
extern G7 *D_004C2794;
extern u8 D_004D18A6[];

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_001AA7B0(u8 *p, u8 *q)
{
    if (q[0x1E4] != 29 || q[0x1FD] != 4) {
        *(s32 *)(p + 0xD0) = p[6];
        *(s32 *)(p + 0xD4) = p[7];
        p[6] = 16;
        p[7] = 0;
        return;
    }
    func_00175700(p);
    if (*(s8 *)(q + 0x151) == 0) {
        return;
    }
    if (D_004D18A6[0] != 0) {
        return;
    }
    p[7]++;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x17, 0x43);
}
