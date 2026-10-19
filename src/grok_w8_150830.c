typedef signed short s16;

typedef struct {
    s16 a;
    s16 b;
} Pair;

void func_00150830(Pair *p, unsigned int n)
{
    unsigned int i;
    unsigned int j;
    unsigned int lim;
    Pair *row;
    Pair tmp;

    for (i = 0; i < n - 1; i++) {
        lim = n - 1 - i;
        row = p;
        for (j = 0; j < lim; j++, row++) {
            if (row[0].a < row[1].a) {
                tmp = row[1];
                row[1] = row[0];
                row[0] = tmp;
            }
        }
    }
}
