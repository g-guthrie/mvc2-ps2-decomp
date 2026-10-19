#pragma padloop on
typedef signed char s8;
typedef signed int s32;

extern void func_00405DC8(char *s);
extern s32 func_0011FFA0(s8 *s);
extern s32 func_00120288(s8 *a, s8 *b, s32 n);
extern char D_004BC928[];

extern struct {
    s32 val;
    s8 name[12];
} D_0062FB48[32];

void func_00406220(s8 *s)
{
    s32 n;
    s32 i;
    if (s == 0) {
        func_00405DC8(D_004BC928);
        return;
    }
    n = func_0011FFA0(s);
    i = 0;
    do {
        if (func_00120288(s, D_0062FB48[i].name, n) == 0) {
            D_0062FB48[i].name[0] = 0;
            return;
        }
        i++;
    } while (i < 32);
}
