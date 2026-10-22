typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C0060[8];
extern u8 D_004C0068[8];
extern u8 D_004C0070[8];
extern u8 D_004C0078[8];
extern u8 *D_004C2794;
extern u32 D_00451610[];

#define RESET_ACTION(p,code) do {u32 ca; (p)[0x1B5]=(code);(p)[0x1B2]=*(u16 *)((p)+0x1C0)=0;*(u32 *)((p)+0x1D8)=0;ca=(p)[2]*2;ca+=(u32)D_004C2794;ca+=0x7C;++*(s16 *)ca;}while(0)

void func_00226B20(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 k;
    p[7] = 0;
    p[6] = 0;
    k = p[0x1FC];
    if (p[0x212] != 0) {
        k = (k + 3) & 0xFF;
    }
    *(u32 *)(p + 0x334) = 0;
    p[0x1BB] = D_004C0068[p[0x1FC]];
    RESET_ACTION(p, D_004C0060[(u8)k]);
    func_001757E0(p, D_004C0078[(u8)k], D_004C0070[(u8)k]);
    if ((u8)k == 5 && (*(u16 *)(p + 0x20E) & 0x1000) != 0) {
        *(u32 *)(p + 0x334) = 1;
        p[0x1EA] = *(s8 *)(p + 0x1EA) & 0xF;
        func_001757E0(p, 0xC, 5);
    }
    if (p[0x210] != 0) {
        k = (k + 6) & 0xFF;
    }
    *(u32 *)(p + 0x408) = D_00451610[(u8)k];
    if (p[0x212] == 0) {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF) != 0) {
            p[0x1EA] = t - 1;
        }
    } else {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF0) != 0) {
            p[0x1EA] = t - 0x10;
        }
    }
}
