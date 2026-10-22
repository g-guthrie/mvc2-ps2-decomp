typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern s8 D_004C27D0;
extern u8 D_004F20B0[];

void func_00171700(void) {
    extern s32 func_0012E560();
    extern void func_00174150();
    extern void func_00417FA0();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00176300();
    extern void func_0016F2D0();
    extern void func_00174F50();
    extern void func_00170160(int);
    extern void func_001E2150();
    extern void func_003D7F10();
    extern void func_003DA410();
    extern void func_00180360();
    extern void func_001E7F20();
    extern void func_001E3F50();
    extern void func_00122DA0();
    extern void func_0016D160();
    extern void func_0016CDA0();
    extern void func_003D0EE0();
    extern void func_00128330();
    extern void func_0016F3C0();
    s32 i;
    u8 *q;
    s32 off;
    if (func_0012E560()) {
        ((s8 *)D_004C2840)[4] = ((s8 *)D_004C2840)[4] + 1;
        D_004C2840[0x19] = 1;
        *(s32 *)(D_004C2840 + 0x94) = 0;
        if (((s8 *)D_004C2840)[0x4C] == 5) {
            func_00174150();
            func_00417FA0(1);
        }
        func_003D6D50();
        func_003D6E20();
        func_00176300();
        i = 0;
        off = 0;
        do {
            q = D_004F20B0 + off;
            func_0016F2D0(q, q[0x570]);
            func_00174F50(q, i);
            i++;
            off += 0x5B8;
        } while (i < 6);
        if (*(s32 *)(D_004C2840 + 0x14) != 0x40) {
            func_00170160(2);
            func_00170160(4);
            func_00170160(1);
        } else {
            func_00170160(0x18);
            func_00170160(0x17);
        }
        if (*(s32 *)(D_004C2840 + 0x14) == 0x40) {
            func_001E2150();
        } else {
            func_001E2150();
        }
        func_003D7F10();
        func_003DA410();
        func_00180360();
        func_001E7F20();
        func_001E3F50(D_004C27D0);
        func_00122DA0();
        func_0016D160();
        func_0016CDA0();
        if (*(s32 *)(D_004C2840 + 0x14) != 0x40) {
            func_003D0EE0();
            func_00128330();
            if (((s8 *)D_004C2840)[0x4C] != 5) func_0016F3C0();
        }
    }
}
