typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_004C2974;

void func_00366760(u8 *p) {
    extern void func_00367F60(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_00179160(u8 *, u8 *);
    extern void func_003671D0(u8 *, u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_00184C60(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00367140(u8 *);
    u8 *q = *(u8 **)(p + 0x1E0);
    s16 v;
    q[0x1FF] = 1;
    if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) != p) {
        func_00367F60(p);
        return;
    }
    if (D_004C2974[0xE] != 0) {
        *(s16 *)(p + 0x1E) = 1;
    }
    if (q[5] == 3) {
        *(s16 *)(p + 0x1E) = 1;
    }
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        func_00175700(p);
        func_00179160(p, q);
        func_003671D0(p, q);
        if (func_00182D30(q) == 0) {
            return;
        }
    }
    p[0x24] = 0xC;
    q[0x20A] = 0;
    if (q[5] != 3) {
        q[0x203] = 8;
        if (q[0x20D] == 2) {
            func_00184C60(q);
        } else {
            func_001843A0(q);
        }
    }
    D_004C2974[7] = *(s8 *)(p + 0x140) ^ 1;
    D_004C2974[6] = 1;
    func_00367140(p);
}
