typedef signed short s16;

typedef struct {
    s16 a;
    s16 b;
} Pair;

void func_00150830(Pair *p, unsigned int n)
{
    unsigned int i, j;
    Pair tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (p[j].a < p[j + 1].a) {
                tmp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = tmp;
            }
        }
    }
}
