typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 D_0045A810[];
extern f32 D_0045A814[];
void func_002D8A30(u8 *p) {
    extern s8 func_00175700();
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    extern void func_001843A0();
    extern void func_00184540();
    extern void func_00126400();
    extern void func_001E3A40();
    extern void func_001E3B70();
    extern void func_0018FDB0();
    extern void func_00154790();
    u8 *q;
    u32 t;
    u32 a;
    f32 v[4];
    q = *(u8 **)(p + 0x1DC);
    p[0x1FE] = 1;
    if (p[6] == 0) {
        v[0] = *(f32 *)((u8 *)D_0045A810 + p[0x20B] * 8);
        v[1] = *(f32 *)((u8 *)D_0045A814 + p[0x20B] * 8);
        func_0015D010(p, v);
        func_0018C6E0(p);
        p[0x1B4] = 10;
        p[0x2BD] = 0;
        t = p[6];
        p[6] = t + 1;
    }
    switch (p[0x20B]) {
    case 0:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 2;
            q[0x20D] = 2;
            func_00126400();
            q[0x1B5] = 0x20;
            q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
            func_001E3A40(*(u8 **)(p + 0x1DC));
        }
        break;
    default: break;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            s32 t = *(s8 *)(p + 0x151);
            if (t != 0) {
                if ((s8)t > 0) {
                    *(u8 **)(q + 0x1C8) = p;
                    q[0x1B5] = 0x21;
                    func_0018FDB0(p);
                } else {
                    *(u8 **)(q + 0x1C8) = p;
                    q[0x20A] = 1;
                    q[0x20D] = 2;
                    func_00126400();
                    q[0x1B5] = 0x22;
                    q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
                }
                func_001E3B70(q, 2);
                p[0x151] = 0;
                v[0] = -171.66665649414062f;
                if (*(s16 *)(p + 0x140) != 0) v[0] = -v[0];
                v[0] += *(f32 *)(p + 0x34);
                v[1] = 182.14285278320312f + *(f32 *)(p + 0x38);
                func_00154790(v, p[0x1E6], 2, 0);
                p[0x151] = 0;
            }
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 1;
            q[0x20D] = 2;
            func_00126400();
            q[0x1B5] = 0x23;
            q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        }
        break;
    }
}
