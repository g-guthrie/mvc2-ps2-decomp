typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef void (*Fn)(u8 *);

typedef struct { s32 w[3]; } E12;
extern E12 *D_004C2794;
void func_001913C0(u8 *a0) {
    *(s16 *)(D_004C2794[a0[2] ^ 1].w[6] + 0x284) = 0;
    *(s16 *)(D_004C2794[a0[2] ^ 1].w[7] + 0x284) = 0;
    *(s16 *)(D_004C2794[a0[2] ^ 1].w[8] + 0x284) = 0;
}

extern s32 func_003ED300();
extern void func_003DADD0();
extern void func_003DAE10();
extern u8 D_0058EFD0[];
extern u8 D_0058EC40[];
extern u8 D_004BA400[];
extern void *D_004C2A68;
extern void *D_004C2A6C;
s32 func_003DAD60(void) {
    s32 i;
    s32 r = func_003ED300();
    func_003DADD0();
    D_004C2A68 = D_0058EFD0;
    D_004C2A6C = D_0058EC40;
    i = 0;
    do {
        func_003DAE10(D_004BA400, i);
        i++;
    } while (i < 5);
    return r;
}

extern u8 D_004C1760[8];
extern void func_001757E0();
extern void func_001E3210();
void func_0031E950(u8 *a0) {
    s32 v;
    a0[0x1E6] = D_004C1760[a0[0x22]];
    *(u16 *)(a0 + 0x140) = a0[0x1E6];
    v = a0[0x22];
    if (v >= 5) {
        v = -(v - 8);
    }
    func_001757E0(a0, 0x15, (v * 2 + 0xA) & 0xFF);
    func_001E3210(a0, 0x20);
}

extern s32 func_003D92F0();
extern void func_001843A0();
extern Fn D_004BFD18[2];
void func_001FEB20(u8 *a0) {
    u8 *s = a0 + 0x2B8;
    if (func_003D92F0(a0)) {
        s[0xC] = 0;
        func_001843A0(a0);
    } else {
        D_004BFD18[a0[7]](a0);
    }
}

extern u16 *D_004C2A08;
extern u8 D_004C1E50[8];
extern void func_0039BBF0();
extern void func_001757E0();
void func_0039BAF0(u8 *a) {
    a[0x24] = 0;
    *(f32 *)(a + 0x34) = *(f32 *)(*(u8 **)(a + 0x18) + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(*(u8 **)(a + 0x18) + 0x38);
    if (*D_004C2A08 != *(u16 *)(*(u8 **)(a + 0x18) + 0x168)) {
        func_0039BBF0(a);
    } else { /*A*/
        if (*(s8 *)(a + 0x150) != *(s8 *)(*(u8 **)(a + 0x18) + 0x150)) {
            func_001757E0(a, 0x15, D_004C1E50[*(s8 *)(*(u8 **)(a + 0x18) + 0x150) >> 1]);
        }
    /*B*/ }
}

extern u8 D_004C0C28[8];
