typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5B8]; } E5B8;
extern E5B8 D_004F20B0[];
typedef struct { u8 pad[0xAF]; s8 bAF; } G2840;
extern G2840 *D_004C2840;

void func_003D8DD0(u8 *p) {
    extern s32 func_003D9000(void *);
    extern void func_003D91B0(void);
    extern void func_00180640(s32);
    extern void func_001E42D0(s32);
    s32 i;
    s32 off;
    u8 *a1;
    s16 h = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = h;
    if (h > 0) {
        i = 0;
        off = 0;
        do {
            if (func_003D9000((E5B8 *)((u8 *)D_004F20B0 + off)) != 0) return;
            i++;
            off += 0x5B8;
        } while (i < 6);
    }
    func_003D91B0();
    a1 = (*(s8 *)(p + 0x3E) != 0) ? *(u8 **)(p + 0x18) : *(u8 **)(p + 0x24);
    if (p[0x48] == 8 && D_004C2840->bAF != 0 && (*(u32 *)(a1 + 0x428) & 0x3000000) != 0) {
        if (a1[1] == 0x18) {
            func_00180640(0);
        } else {
            func_00180640(1);
        }
        func_001E42D0(0x3C);
    }
    p[0] = 0;
}
