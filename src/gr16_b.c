typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u16 w; u8 pad[18]; } E20;
extern E20 D_004F4484[];
extern E20 D_004F4490[];

static void func_001734D0(u8 *p)
{
    *(s16 *)(p + 0x4DA) = 40;
    *(s8 *)(p + 0x4D3) = 1;
}

void func_00173A50(u8 *p) {
    extern void func_00173470();
    extern void func_001734F0();
    extern s32 func_001733E0();
    extern void func_00173650();
    u32 t;
    s32 i;
    if (func_001733E0(p) != 0) return;
    i = *(s8 *)(p + 0x538) & 1;
    t = D_004F4484[i].w;
    if ((t & 0x3F0) != 0) {
        func_001734D0(p);
        if (*(s16 *)(p + 0x4D8) != 0) {
            *(s16 *)(p + 0x4D6) += 0x12C;
            p[0x544 + *(s8 *)(p + 0x4D2)] = 0x2A;
            *(s8 *)(p + 0x4D2) = *(s8 *)(p + 0x4D2) - 1;
            *(s16 *)(p + 0x4D8) = (s8)p[0x544 + *(s8 *)(p + 0x4D2)];
            *(s8 *)(p + 0x520) ^= 1 << *(s8 *)(p + 0x4D2);
            return;
        }
        func_00173650();
        func_001734F0(p);
        return;
    }
    if ((t & 0xC00) != 0 || (D_004F4490[i].w & 0xC00) != 0) {
        func_001734D0(p);
    } else {
        func_00173470(p);
    }
    i = *(s8 *)(p + 0x538) & 1;
    if (D_004F4484[i].w == 0x400 || D_004F4490[i].w == 0x400) {
        *(s16 *)(p + 0x4D8) = *(s16 *)(p + 0x4D8) + 1;
    }
    i = *(s8 *)(p + 0x538) & 1;
    if (D_004F4484[i].w == 0x800 || D_004F4490[i].w == 0x800) {
        *(s16 *)(p + 0x4D8) = *(s16 *)(p + 0x4D8) - 1;
    }
    *(s16 *)(p + 0x4D8) = *(s16 *)(p + 0x4D8) & 1;
    p[0x547] = 0x2D - *(s8 *)(p + 0x4D8);
}
