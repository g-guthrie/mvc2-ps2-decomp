/* rb28_b: MW 3.0.3: ./try.sh src/rb28_b.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004B75BA[];
extern u8 D_004B75B8[];

void func_002D4020(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_00126470();
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_00126470();
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
        if (*(s16 *)(p + 0x1C) != 0) {
            if ((s8)p[0x539] != 0) {
                if (p[0x212] == 0) {
                    *(s16 *)(p + 0x1C) = 0;
                    goto clr;
                }
            } else if ((*(u16 *)(p + 0x35E) & 0x400) == 0) {
                goto zero;
            }
            *(s16 *)(p + 0x1C) = *(s16 *)((s32)p + 0x1C) - 1;
            p[6] = 2;
            *(u32 *)(p + 0x60) = 0x41AB6DB6;
            *(u32 *)(p + 0x6C) = 0xBF092492;
            switch (p[0x1E6]) {
            default:
                *(u32 *)(p + 0x5C) = 0x41FCD000;
                break;
            case 0:
                *(u32 *)(p + 0x5C) = 0xC1FCD000;
                break;
            }
            *(u32 *)(p + 0x68) = 0;
            func_001757E0(p, 0x15, 0x12);
            return;
        }
      zero:
        *(s16 *)(p + 0x1C) = 0;
      clr:
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (*(s16 *)(p + 0x140) != 0) p[0x22] = D_004B75BA[p[0x1B7]];
        else p[0x22] = D_004B75B8[p[0x1B7]];
        func_001757E0(p, 0x15, 0x13);
    }
}
