typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_001757E0(void *, int, int);
extern void func_00185490(void *);
extern void func_00183D10(void *);
extern u8 *D_004C2794;

void func_0022AA50(u8 *p)
{
    p[6]++;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    p[525] = 0;
    *(float *)(p + 56) = *(float *)(p + 1072);
    func_00185490(p);
    func_00183D10(p);
    p[437] = 0x77;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((short *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x16, 9);
}
