typedef signed int s32;
typedef signed char s8;
typedef signed short s16;
extern s32 D_004C220C;
extern char D_00478E78[];
extern void func_0011D8F8(void *, int, int);
void func_003F5F00(void) {
    if (D_004C220C == 0) func_0011D8F8(D_00478E78, 0, 0x180);
    D_004C220C++;
}

extern s32 D_004C2238;
typedef struct { int a[8]; } Q;
extern Q D_004C2240;
extern void func_003F78F0(void);
extern void func_003F79A8(s8 *, s16 *, s16 *, s16 *);
void func_003F7B18(s16 *a, s16 *b, s16 *c) {
    if (D_004C2238 == 0) func_003F78F0();
    do { func_003F79A8((s8 *)&D_004C2240, a, b, c); } while (0);
}

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u16 D_004C2248;
extern u16 D_004C224A;
extern u16 D_004C224C;
/* Follows func_003F7B18 in this unit; EE GCC 2.96 then treats that call as
   non-throwing, which retail's plain bnez depends on. */
s32 func_003F8260(u8 *p, u8 a, u8 b, u16 *x, u16 *y, u16 *z)
{
    if (a >= 4) {
        if (b >= 16) {
            func_003F7B18((s16 *)x, (s16 *)y, (s16 *)z);
            goto end;
        }
        if (b >= 8) {
            if (*(u32 *)(p + 0x9C) == 0 && *(s16 *)(p + 0xA0) == 0) {
                u16 t0 = D_004C2248, t1 = D_004C224A, t2 = D_004C224C;
                *(u16 *)(p + 0x9C) = t0;
                *(u16 *)(p + 0x9E) = t1;
                *(u16 *)(p + 0xA0) = t2;
            }
            *x = *(u16 *)(p + 0x9C);
            *y = *(u16 *)(p + 0x9E);
            *z = *(u16 *)(p + 0xA0);
            goto end;
        }
    }
    *x = 0;
    *y = 0;
    *z = 0;
end:
    return 0;
}
