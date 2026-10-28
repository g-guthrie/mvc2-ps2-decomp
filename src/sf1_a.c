/* func_001056F0: Sony EE GCC 2.9, ./trysony29.sh src/sf1_a.c 0 O2 -msoft-float; .rodata literals anchored via config/readonly_sections.csv */
extern void (*D_00438264)(int);
extern char D_004AAFD0[], D_004AAFD8[], D_004AAFE0[];
extern int func_00118D78(double);
extern int func_00105660(int);
extern void func_00105E48(const char *, ...);

void func_001056F0(double x)
{
    int e = 0;
    if (x < 0.0) {
        x = 0.0 - x;
        D_00438264('-');
    }
    if (x < 0.1) {
        while (x < 0.1) {
            x *= 10.0;
            e--;
        }
    } else if (x >= 1.0) {
        while (x >= 1.0) {
            x /= 10.0;
            e++;
        }
    }
    {int m = func_00118D78(x * 1000000.0); m = func_00105660(m); func_00105E48(D_004AAFD0, m);}
    if (e >= 0)
        func_00105E48(D_004AAFD8, e);
    else
        func_00105E48(D_004AAFE0, e);
}
