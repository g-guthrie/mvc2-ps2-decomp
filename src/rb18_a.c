typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x58]; s8 f58; u8 pad2[0x8F - 0x59]; s8 f8F; } G2840;
extern G2840 *D_004C2840;
typedef struct { s16 v; u8 pad[0x5B8 - 2]; } Ent;
extern Ent D_004F24E4[];
extern s16 D_004F3054[], D_004F3BC4[], D_004F2A9C[], D_004F360C[], D_004F417C[];

void func_003D8540(u8 *a)
{
    extern s32 func_003D86A0(u8 *);
    extern s32 func_003D8680(u8 *);
    extern s32 func_003D8690(u8 *);
    s32 x, y;
    u8 *q;
    s8 k;
    a[3] = 1;
    if (D_004C2840->f58 != 0) {
        x = D_004F24E4[a[0x8A]].v;
        y = D_004F24E4[a[0x8B]].v;
    } else {
        y = D_004F24E4[0].v + D_004F3054[0];
        x = (s16)(D_004F3BC4[0] + y);
        y = D_004F2A9C[0] + D_004F360C[0];
        y = (s16)(D_004F417C[0] + y);
    }
    if ((s16)x == (s16)y) {
        func_003D86A0(a);
        return;
    }
    if ((s16)y < (s16)x) {
        func_003D8680(a);
    } else {
        func_003D8690(a);
    }
    k = a[0x3E];
    q = *(u8 **)((u8 *)(k * 12) + (s32)a + 0x18);
    if (D_004C2840->f8F == 0 && q[1] == 0x19 && ((s8 *)q)[0x539] != 0) {
        a[0x3E] = k ^ 1;
    }
}
