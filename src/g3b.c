typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00338100(int);

extern u8 *D_004C2840;
extern u8 D_004F2607[];
extern u8 D_004F2BBF[];
extern u8 D_004F3177[];
extern u8 D_004F3CE7[];
extern u8 D_004F372F[];
extern u8 D_004F429F[];
void func_0032A870(void) {
    *(s16*)(D_004C2840+8) = *(s16*)(D_004C2840+8) - 1;
    if (*(s16*)(D_004C2840+8) <= 0) {
        (*(s8*)(D_004C2840+4))++;
        D_004F3177[0] = D_004F2607[0];
        D_004F3CE7[0] = D_004F2607[0];
        D_004F372F[0] = D_004F2BBF[0];
        D_004F429F[0] = D_004F2BBF[0];
    }
}

extern u8 *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
void func_002D69E0(u8 *a0) {
    if (a0[0x20D] == 1 && a0[0x1FC] == 1 && *(s8*)(a0+0x151) != 0) {
        a0[0x151] = 0;
        a0[0x1B5] = 0x19;
        a0[0x1B2] = *(u16*)(a0+0x1C0) = 0;
        *(u32*)(a0+0x1D8) = 0;
        { s16 *base = (s16*)D_004C2794; base[a0[2] + 0x3E] += 1; }
        D_004F1F45[0] = 1;
        D_004F1F46[0] = 1;
    }
}
