typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[4]; } SlotTab;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 v[4]; } PosTab;
typedef struct { f32 a, b; } V2;
typedef struct { V2 v[4]; } ScaleTab;

extern SlotTab D_004A6E70;
extern PosTab D_004A6E80;
extern ScaleTab D_004A6EB0;
extern s32 D_004C27FC;
extern s32 D_004C2B70;
extern s32 D_004C2B74;
extern u8 *D_006338B4[];
extern u8 *D_006338CC[];
extern void D_0041CD20();
extern void D_0041D5F0();
extern void D_0041D560();
extern void D_0041D640();
extern void func_0041D390();

u8 *func_0041D6E0(s32 a)
{
    extern void func_0041CB60(void);
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_00131830(s32, s32);
    extern void func_0041CCA0(s16, s32 *, s32 *);
    SlotTab slot;
    PosTab pos;
    ScaleTab sc;
    V3 *vp;
    V2 *sp2;
    s32 i, k, sv;
    u8 *o;

    slot = D_004A6E70;
    pos = D_004A6E80;
    sc = D_004A6EB0;
    func_0041CB60();
    vp = &pos.v[0];
    sp2 = &sc.v[0];
    i = 0;
    k = 0;
    do {
        o = func_003DA750(0, 0xD, 1);
        if (o == 0) return o;
        sv = slot.w[i];
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)D_0041CD20;
        *(s16 *)(o + 0xCC) = sv;
        *(s32 *)(o + 0x84) = D_004C27FC;
        o[0x20] = sv;
        *(s32 *)(o + 0xD0) = 0x11;
        *(f32 *)(o + 0x34) = vp->x;
        *(f32 *)(o + 0x38) = vp->y;
        *(f32 *)(o + 0x3C) = vp->z;
        vp++;
        *(f32 *)(o + 0x50) = sp2->a;
        *(f32 *)(o + 0x54) = sp2->b;
        sp2++;
        if (i == 2) {
            *(s32 *)(o + 0xD0) |= 0x400;
            D_006338CC[0] = o;
        }
        i++;
    } while (i < 4);
    o = func_003DA750(0, 0xD, 1);
    if (o == 0) return o;
    D_006338B4[0] = o;
    o[0x13C] = 1;
    *(s16 *)(o + 0xCC) = 0xBC;
    *(s32 *)(o + 0x84) = D_004C27FC;
    *(void **)(o + 0x10) = (void *)D_0041D5F0;
    o[0x23] = 1;
    *(s32 *)(o + 0xD0) = 0x31;
    *(u32 *)(o + 0x50) = 0x3F333333;
    *(u32 *)(o + 0x54) = 0x3E4CCCCD;
    *(s32 *)(o + 0x74) = 0;
    i = 0;
    do {
        if (func_00131830(a, 0) != 0) break;
        a++;
        a = a % 64;
        i++;
    } while (i < 64);
    if (i != 64) {
        *(void **)(D_006338CC[0] + 0x10) = (void *)func_0041D390;
        D_006338CC[0][0x23] = 1;
        func_0041CCA0((s16)a, &D_004C2B70, &D_004C2B74);
        D_006338CC[0][5] = a;
        D_006338CC[0][6] = (a + 1) % 58;
    } else {
        *(void **)(D_006338CC[0] + 0x10) = (void *)D_0041D560;
        D_006338CC[0][0x23] = 0;
        *(void **)(D_006338B4[0] + 0x10) = (void *)D_0041D640;
    }
    return D_006338B4[0];
}
