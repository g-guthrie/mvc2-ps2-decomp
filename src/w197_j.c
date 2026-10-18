typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002368E0(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00182C30(u8 *, s32);
    extern void func_00182DB0(u8 *, s32);
    extern void func_00185960(u8 *, u8 *);
    extern void func_00238B70(u8 *, u8 *);
    u32 t;
    if (*(s8 *)(q + 7) < 0) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x206] = 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x19));
        return;
    }
    p[0x1FE] = 1;
    p[0x206] = 3;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        q[7] = 2;
        *(u16 *)(q + 0xA) = 0;
        *(u16 *)(q + 0xC) = 0;
        *(u16 *)(q + 0xE) = 2;
        *(u16 *)(q + 0x12) = 5;
        q = *(u8 **)(p + 0x1DC);
        t = q[6];
        q[6] = t + 1;
        func_001266A0(p, 5, 5);
        func_00182C30(q, 0x10);
        func_00182DB0(p, 0xA);
        func_001757E0(p, 0xF, 3);
        func_00185960(p, p);
        *(s8 *)(p + 0x16A) = -1;
        p[0x20B] = 0xC5;
    } else {
        func_00238B70(p, q);
        *(s8 *)(p + 0x22) = *(s8 *)(p + 0x150);
    }
}
