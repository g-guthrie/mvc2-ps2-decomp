typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

void func_001F6C70(u8 *a)
{
    extern void func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001843A0(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern s32 func_00417A40();
    extern void func_001757E0(u8 *, s32, s32);
    s32 m;
    s32 v;
    s16 sv;
    u8 *p;
    u32 h;

    func_00175700(a);
    sv = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = sv;
    if (sv < 0) {
        func_001266A0(a, 0, 0);
        p = *(u8 **)(a + 0x1DC);
        *(u8 **)(p + 0x1C8) = a;
        p[0x20A] = 7;
        p[0x1B5] = 0x27;
        a[0x1B5] = 0x27;
        func_001843A0(a);
        return;
    }
    if (*(s8 *)(a + 0x539) != 0) {
        if (func_0018AB10(a) == 0) return;
        v = *(s16 *)(a + 0x1E);
        *(s16 *)(a + 0x1E) = v + 1;
        if (v > 10) return;
        if (func_00417A40() & 1) m = 0; else m = 1;
    } else {
        h = *(u16 *)(a + 0x35E);
        if ((h & 0x120) == 0) return;
        if ((h & 0x100) != 0) {
            m = 0;
            if ((h & 0x400) != 0) {
                v = *(s16 *)(a + 0x140) ^ 1;
                *(s16 *)(a + 0x140) = v;
                a[0x1E6] = *(s8 *)(a + 0x140);
                p = *(u8 **)(a + 0x1DC);
                v = *(s16 *)(p + 0x140) ^ 1;
                *(s16 *)(p + 0x140) = v;
                p[0x1E6] = *(s8 *)(p + 0x140);
            }
        } else {
            m = 1;
        }
    }
    switch (m) {
    case 0:
        a[6] = 1;
        func_001757E0(a, 0xF, 0x34);
        break;
    case 1:
        a[6] = 2;
        a[7] = 0;
        func_001757E0(a, 0xF, 7);
        break;
    }
}
