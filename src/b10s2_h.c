typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 D_004C23C8;
extern void func_003F9630(void);
extern void func_003FFE60(void);
extern void func_00404178(void *);
extern void func_003FF1F8(void);
extern void func_003F9660(void);
extern s8 D_0047C620[];

void func_00402498(void) {
    s8 *p;
    s32 k;
    s8 *end;
    if (D_004C23C8 == 0) {
        func_003F9630();
        D_004C23C8 = 1;
        func_003FFE60();
        D_004C23C8 = 2;
        p = D_0047C620;
        k = 1;
        end = p + 0xAC0;
        do {
            if (*p == k) {
                func_00404178(p);
            }
            p += 0xAC;
        } while ((s32)p < (s32)end);
        D_004C23C8 = 3;
        func_003FF1F8();
        D_004C23C8 = 0;
        func_003F9660();
    }
}
