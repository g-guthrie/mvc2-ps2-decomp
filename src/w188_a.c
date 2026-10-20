typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/w188_a.c sn   (-O2, -G0) */

extern volatile u8 D_004891B4;
#include "HtciFileRequest.h"
extern HtciFileRequest D_00489220[13];

void func_0040B2E8(void) {
    HtciFileRequest *p;
    s32 i;
    s32 c;
    extern void func_00411288(void);
    extern void func_004112B0(void);
    extern void func_0040B220(HtciFileRequest *);
    func_00411288();
    if ((s8)D_004891B4 == 1) {
        func_004112B0();
        return;
    }
    D_004891B4 = 1;
    func_004112B0();
    c = 1;
    for (i = 12, p = D_00489220; i >= 0; i--, p++) {
        if (p->slot_state == c) func_0040B220(p);
    }
    D_004891B4 = 0;
}

extern char D_004BC618[], D_004BC648[];
extern u8 D_0062F908[];
void func_00402C20(u8 *a, s32 b, s32 c) {
    char buf[16];
    s32 l[3];
    s32 r;
    extern void func_003FB128(char *);
    extern void func_00401868(void);
    extern s32 func_003FD748(s32, s32, u8 *, s32 *, s32 *, s32 *);
    extern s32 func_004003C8(u8 *, s32, s32, s32, s32);
    extern void func_003FB2E8(s32);
    extern void func_003FB178(char *, char *);
    extern void func_00401708(u8 *, s32, char *, s32);
    if (a == 0) {
        func_003FB128(D_004BC618);
        return;
    }
    func_00401868();
    if (func_003FD748(b, c, D_0062F908, &l[0], &l[1], &l[2]) == 0) {
        r = func_004003C8(D_0062F908, l[0], l[1], l[2], *(s32 *)(a + 0x10));
        *(s32 *)(a + 8) = r;
        if (r == 0) {
            func_003FB2E8(b);
            func_003FB178(D_004BC648, buf);
            *(s16 *)(a + 0x60) = -1;
            a[1] = 6;
        } else {
            func_00401708(a, c, buf, 16);
            a[2] = 1;
            a[0x98] = 0;
        }
    }
}
