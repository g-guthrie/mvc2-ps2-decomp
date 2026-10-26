/* EE GCC 2.96: -O2 -G8 -fno-optimize-sibling-calls. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef struct S25 {
    u8 pad0;
    s8 b1;
    u8 pad2[2];
    s32 f4;
    u8 pad8[0xC];
    s32 f14;
    u8 pad18[8];
    s32 f20;
} S25;
typedef struct E138 { S25 payload; u8 pad[0x138 - sizeof(S25)]; } E138;

typedef s32 (*RuntimeCallback)(s32);
extern void func_00411720(s32, s32, RuntimeCallback, s32);
void func_003FEF20(RuntimeCallback callback, s32 argument)
{
    func_00411720(1, 0, callback, argument);
}
void func_003FEF48(RuntimeCallback callback, s32 argument)
{
    func_00411720(6, 0, callback, argument);
}

/* Shared task IDs are cleared by 003FE780/003FE7F0 during shutdown. */
extern volatile s32 D_004C2334;
extern s32 D_0047D0F8[];
extern void func_003FDD28(s32, s32);
void func_003FDE10(void) { func_003FDD28(D_004C2334, D_0047D0F8[0]); }

extern void func_003F9630(void);
extern void func_003F9660(void);
extern void func_003FD228(S25 *);
extern E138 D_00479E00[];
void func_003FD2A0(void)
{
    s32 i;
    E138 *p;
    func_003F9630();
    p = D_00479E00;
    for (i = 15; i >= 0; i--, p++) {
        if (*(s8 *)p == 1) func_003FD228(&p->payload);
    }
    func_003F9660();
}

struct T3FCCF0 { char b0; signed char b1; char pad[2]; s32 f4; };
extern void func_003FB510(s32, s32, s32, s32, s32);
extern s32 func_003FD138(void *);
extern void func_004005F8(u8 *);
extern void func_0011D8F8(void *, s32, s32);
void func_003FCCF0(struct T3FCCF0 *p)
{
    func_003FB510(3, 0, (s32)p, -1, -1);
    if (p) {
        if (p->b1 == 2) func_003FD138(p);
        if (p->f4) func_004005F8((u8 *)p->f4);
        func_0011D8F8(p, 0, 0x138);
        func_003FB510(3, 1, (s32)p, -1, -1);
    }
}

extern volatile s32 D_004C2330;
extern s32 func_003FE190(void *);
extern void func_003FE120(void *);
extern s32 func_003FE4F0(void);
void func_003FEAE8(void)
{
    if (func_003FE190((void *)D_004C2330) == D_004C2330)
        func_003FE120((void *)D_004C2330);
    if (func_003FE4F0() == 1) {
        if (func_003FE190((void *)D_004C2334) == D_004C2334)
            func_003FE120((void *)D_004C2334);
    }
}

extern s32 D_004C22CC;
extern s32 D_004C22D0, D_004C232C, D_004C239C;
extern void func_003FE780(void);
extern void func_003FE7F0(void);
extern void func_003FE860(void);
extern void func_003FE8D0(void);
extern void func_003FE940(void);
extern void func_00103C70(s32, s32);
extern void func_00411898(s32, s32);
extern s32 func_004118A8(s32, s32);
extern void func_00411BC8(void);
void func_003FEEA8(void)
{
    if (--D_004C22CC == 0) {
        func_003FE780();
        func_003FE7F0();
        func_003FE860();
        func_003FE8D0();
        func_003FE940();
        func_00103C70(D_004C232C, D_004C239C);
        func_00411898(0, 0);
        func_004118A8(0, 0);
        D_004C22D0 = 0;
        func_00411BC8();
    }
}
