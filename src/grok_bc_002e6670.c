typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);

void func_002E6670(u8 *p, u8 *q)
{
    if (*(s8 *)(p + 337) == 0) {
        func_00175700(p);
        *(f32 *)(p + 52) = 0;
        *(f32 *)(p + 92) = 0;
        *(f32 *)(p + 56) = 0;
        *(f32 *)(p + 96) = 0;
    } else if ((s8)func_00175700(p) < 0) {
        q[5] = 0;
        func_001757E0(p, 21, 9);
    }
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[6]++;
    p[7] = 0;
    p[525] = 0;
    *(u32 *)(p + 1072) = 0;
    q[5] = (u8)-1;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    func_00183D50(p);
    func_001757E0(p, 21, 11);
}
