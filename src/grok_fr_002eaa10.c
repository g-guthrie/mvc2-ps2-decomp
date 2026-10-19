typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003A6DC0(u8 *, int, int);

void func_002EAA10(u8 *p)
{
    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        func_0018C4B0(p, 5);
        p[525] = 0;
        func_001757E0(p, 20, 6);
        p[437] = 0x1C;
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001E3710(p, 22);
    }
    if (p[531] == 3)
        func_00183D90(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_003A6DC0(p, 1, 4);
    }
}
