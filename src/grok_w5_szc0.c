typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001A8CF0(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001E3A40(u8 *);

void func_001FF790(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 96) = 0xC0892492;
        *(u32 *)(p + 108) = 0xBF892492;
        func_001757E0(p, 21, 9);
    }
    if (*(s8 *)(p + 337)) {
        p[525] = 2;
        F(p, 52) += F(p, 92);
        F(p, 92) += F(p, 104);
        F(p, 56) += F(p, 96);
        F(p, 96) += F(p, 108);
    }
}

void func_0024AE10(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 337)) {
        p[7]++;
        func_001A8CF0(p, 0);
        func_001A8CF0(p, 1);
        func_001A8CF0(p, 2);
        func_001A8CF0(p, 3);
        func_001A8CF0(p, 4);
        func_001A8CF0(p, 5);
        func_001A8CF0(p, 6);
        func_001A8CF0(p, 7);
        func_001A8CF0(p, 8);
        func_001A8CF0(p, 10);
        func_001A8CF0(p, 11);
    }
}

void func_00202790(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        u8 *q;
        p[6]++;
        *(u32 *)(p + 92) = 0x41200000;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 96) = 0x41AB6DB6;
        *(u32 *)(p + 108) = 0xBF892492;
        if (S(p, 320))
            F(p, 92) = -F(p, 92);
        func_001757E0(p, 15, 4);
        q = *(u8 **)(p + 476);
        *(u8 **)(q + 456) = p;
        q[522] = 2;
        q[437] = 33;
        q[486] = p[486] ^ 1;
        func_001266A0(p, 0, 0);
        func_001E3A40(p);
    }
}
