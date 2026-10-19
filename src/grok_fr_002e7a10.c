typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, float *, int);
extern void func_003A43F0(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002E7A10(u8 *p)
{
    if (p[7] == 0) {
        p[1036] = 2;
        p[828] = 5;
        p[1029] = (p[617] == 6) ? 2 : 0;
        func_00175700(p);
        if (*(s8 *)(p + 337) & 1) {
            f32 sp[4];
            p[1028] = 0;
            p[1029] = 0;
            p[7]++;
            p[337] = *(s8 *)(p + 337) ^ 1;
            *(u32 *)&sp[0] = 0x42855555u;
            *(u32 *)&sp[1] = 0xC304DB6Du;
            func_001830D0(p, sp, 1);
            return;
        }
        return;
    }
    p[1036] = 2;
    p[828] = 5;
    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 337) & 2) {
            p[337] = *(s8 *)(p + 337) ^ 2;
            func_003A43F0(p);
        }
    } else if ((*(s16 *)(p + 28) = *(s16 *)(p + 28) - 1) == 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[6]++;
        p[7] = 0;
        func_001757E0(p, 22, 9);
    }
}
