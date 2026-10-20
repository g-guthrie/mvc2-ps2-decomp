typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001845F0(u8 *);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);

void func_002E8920(u8 *p)
{
    u32 *v92 = (u32 *)(p + 92);
    u32 *v96 = (u32 *)(p + 96);
    u32 *v104 = (u32 *)(p + 104);
    u32 *v108 = (u32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (p[32]) {
        if ((s8)func_00175700(p) < 0) {
            p[488] = 1;
            func_001845F0(p);
            return;
        }
    } else if (p[7] == 0) {
        func_00175700(p);
    } else {
        goto grounded;
    }
    if (*(f32 *)(p + 56) <= *(f32 *)(p + 1072)) {
        p[7]++;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        *v92 = 0;
        *v96 = 0;
        *v104 = 0;
        *v108 = 0;
        func_00183D50(p);
        func_001757E0(p, 15, 10);
    }
    goto done;
 grounded:
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
 done:
    ;
}
