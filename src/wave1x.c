typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00176230(s16 *, s16 *);
extern void func_00170E60(s32, s32, s32, s32, s32, u8 *);
extern void func_00330FF0(void);



u8 *func_003DBA00(u32 *a0, u32 a1, s32 a2)
{
    *(__int128 *)a0 = 0;
    a0[0] = a1 + 0x10000000;
    if (a2 == 1) a0[0] = a0[0] | 0x80000000;
    return (u8 *)(a0 + 4);
}

void func_00330E70(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x84);
    func_00170E60(*(s32 *)(p + 0x14), *(s32 *)(*(u8 **)(p + 0x1C) + *(s16 *)(a0 + 0xCC) * 4), *(s32 *)(p + 0x14), *(s32 *)(*(u8 **)(p + 0x1C) + *(s16 *)(a0 + 0xCC) * 4), (s32)func_00330FF0, a0);
}

void func_0013C4C0(u8 *a0)
{
    *(s32 *)(a0 + 0x44) -= 0x100;
    *(s32 *)(a0 + 0x44) = *(u16 *)(a0 + 0x44);
    if (*(s32 *)(a0 + 0x44) > 0 && *(s32 *)(a0 + 0x44) < 0x71C) {
        *(u8 *)(a0 + 4) += 1;
        *(s16 *)(a0 + 0x1C) = 0x3C;
    }
}

extern void func_003DAA40(u8 *);
extern u8 D_00445530[];
extern u8 D_00462500[];
extern u8 D_004765E0[];
extern void func_00351AC0(u8 *);

void func_00160E50(u8 *a0)
{
    if (*(s16 *)(a0 + 0x1C) > 0x28) {
        func_003DAA40(a0);
    } else {
        *(float *)(a0 + 0x74) = ((float *)D_00445530)[*(s16 *)(a0 + 0x1C)];
        *(s16 *)(a0 + 0x1C) = *(s16 *)(a0 + 0x1C) + 1;
    }
}

void func_00351210(u8 *a0)
{
    if (*(u8 *)(*(u8 **)(a0 + 0x18) + 0x425) != 0) {
        func_00351AC0(a0);
    } else {
        (*(void (**)(void))(D_00462500 + *(u8 *)(a0 + 5) * 4))();
    }
}

u32 func_001BA290(u8 *a0)
{
    a0 = *(u8 **)(a0 + 0x18);
    if (*(u8 *)(a0 + 0x1FD) != 4) return 1;
    if (*(u8 *)(a0 + 0x169) != 0x15) return 1;
    if (*(u8 *)(a0 + 0x1E4) != 0x15) return 1;
    return *(u8 *)(a0 + 5) != 0;
}

extern void func_00175700(u8 *);
void func_0025B220(u8 *a0)
{
    if (*(s8 *)(a0 + 0x151) != 0) {
        *(u8 *)(a0 + 6) += 1;
        *(s16 *)(a0 + 0x1C) = 1;
        *(s32 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x68) = 0;
    } else {
        *(u8 *)(a0 + 0x20D) = 2;
        *(float *)(a0 + 0x34) += *(float *)(a0 + 0x5C);
        *(float *)(a0 + 0x5C) += *(float *)(a0 + 0x68);
    }
    func_00175700(a0);
}

extern s32 func_00294BC0(u8 *);
extern void func_00294B20(u8 *, u8 *);
extern u8 D_004574C0[];
void func_002902F0(u8 *a0)
{
    if (func_00294BC0(a0) == 0) {
        *(u8 *)(a0 + 7) += 1;
        func_00294B20(a0, D_004574C0);
        func_00294BC0(a0);
    }
}

extern void func_0015D010(u8 *, float *);
extern void func_001757E0(u8 *, s32, s32);
void func_0024D150(u8 *a0)
{
    u32 v[4];
    v[0] = 0xC2FD5555;
    v[1] = 0x42B40000;
    func_0015D010(a0, (float *)v);
    *(u8 *)(a0 + 0x1B4) = 10;
    func_001757E0(a0, 0xF, 3);
}
