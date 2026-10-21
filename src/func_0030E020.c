typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {
    u8 pad[0x7C];
    s16 count[2];
} CounterState;
extern CounterState *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_00183D10(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern s32 func_00175700(u8 *);
extern void func_0030F650(s32 *);
extern void func_003BF6A0(u8 *);
extern void func_003297B0(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_00176160(u8 *, s32, s32, s32);

void func_0030E020(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x11;
        p[0x20D] = 0;
        func_00185490(p);
        func_0018C4B0(p, 5);
        func_00183D10(p);
        p[0x1B5] = 0x33;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[p[2]]++;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 6));
    }
    if ((s8)func_00175700(p) < 0) {
        func_0030F650((s32 *)p);
        return;
    }
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        func_003BF6A0(p);
        if (*(u32 *)(p + 0x2CC) == 0)
            func_003297B0(p);
        func_001E3210(p, 0x22);
        p[0x28F] = 0;
        p[0x28E] = 0x10;
    }
    *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) & ~1;
    if (*(s8 *)(p + 0x150) != 0) {
        *(s16 *)(p + 0x1C) ^= 7;
        if ((*(s8 *)(p + 0x150) & 1) != 0)
            func_00176160(p, 1, *(s16 *)(p + 0x1C), 1);
    }
}
