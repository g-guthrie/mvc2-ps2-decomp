typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);

void func_00220080(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    *(s16 *)(p + 28) -= 1;
    if (*(s16 *)(p + 28) < 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        p[492] = 0;
        p[528] = 0;
        *(s8 *)(p + 488) += 1;
        *(s8 *)(p + 489) += 1;
        p[493] = 127;
        func_00184540(p);
    }
}
