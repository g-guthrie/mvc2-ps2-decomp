typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00200E40(u8 *p) {
    extern s8 func_00175700();
    extern void func_00198100();
    extern void func_00190D50();
    extern void func_00200990();
    extern void func_001757E0();
    extern void func_0018FDB0();
    u8 **ip;
    u8 *q;
    s32 v;
    ip = (u8 **)(p + 0x2B8);
    *(f32 *)(*(u8 **)(p + 0x2B8) + 0x38) = *(f32 *)(p + 0x38);
    func_00175700(p);
    v = *(s8 *)(p + 0x151);
    if (v != 0) {
        if ((s8)v == 0x3F) {
            u32 t = p[7];
            p[7] = t + 1;
            func_00198100(p, 2);
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x1B5] = 0x3F;
            *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140);
            q[0x20A] = 1;
            q[0x20D] = 2;
            func_00190D50(q, p);
            func_00190D50(q, p);
            func_00200990(p);
            func_001757E0(p, 0x16, 0x12);
        } else {
            q = *ip;
            *(u8 **)(q + 0x1C8) = p;
            p[0x1B5] = *(s8 *)(p + 0x151);
            q[0x1B5] = *(s8 *)(p + 0x151);
            func_0018FDB0(p);
            func_00190D50(q, p);
            func_0018FDB0(p);
            func_00190D50(q, p);
            p[0x151] = 0;
        }
        func_00200990(p);
    }
}
