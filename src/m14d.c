typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern int func_00175700(u8 *);
extern void func_001830D0(void *p, void *v, s32 n);
void func_0022A370(u8 *p) {
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    } else {
        p[0x404] = 0;
        p[0x405] = 0;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        p[0x151] = 0;
        v[0] = 0xC13AAAAA;
        v[1] = 0x43452492;
        func_001830D0(p, v, 3);
    }
}

extern void func_003C4910(void *p, s32 a, s32 b);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_00319770(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001266A0(p, 0xD, 7);
        t = p[6];
        p[6] = t + 1;
        p[0x2B9] = 1;
        p[0x2B8] = 1;
        p[0x2BB] = 0;
        p[0x2BA] = 0;
        func_003C4910(p, 1, 0);
        func_003C4910(p, 3, 0);
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001E3710(void *p, s32 a);
void func_003160D0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0) {
        if (*(s8 *)(p + 0x211) != 2) return;
    } else {
        if (*(s8 *)(p + 0x211) != 1) return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_001757E0(p, 0xF, 8);
    func_001E3710(p, 0x2F);
}

extern void func_00183DF0();
extern void func_001843A0(void *p);
void func_0020E160(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00183DF0(p, 3);
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}
