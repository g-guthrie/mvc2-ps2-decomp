typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_0019DB00(u8 *, int, int);

void func_0022ADA0(u8 *p)
{
    u8 x;

    p[1036] = 2;
    p[828] = 5;
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if ((s8)func_00175700(p) < 0) {
        if (--S(p, 28) <= 0) {
            p[1037] = 0;
            p[1036] = 0;
            p[827] = 0;
            p[828] = 0;
            p[6]++;
            func_001757E0(p, 21, 53);
        } else {
            p[33] ^= 1;
            x = *(s8 *)(p + 33) + 11;
            if (S(p, 28) == 1) {
                *(s32 *)(p + 92) = 0;
                x += 2;
            }
            func_001757E0(p, 22, x);
        }
    } else {
        if (*(s8 *)(p + 337)) {
            func_0019DB00(p, *(s8 *)(p + 337), p[347]);
            func_0019DB00(p, *(s8 *)(p + 337) - 1, p[347]);
            p[337] = 0;
        }
        if (*(s8 *)(p + 336)) {
            func_0019DB00(p, 128, p[347]);
            func_0019DB00(p, 129, p[347]);
            func_0019DB00(p, 130, p[347]);
            func_0019DB00(p, 131, p[347]);
            p[336] = 0;
        }
    }
}
