typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Bigint {
    struct Bigint *_next;
    s32 _k, _maxwds, _sign, _wds;
    u32 _x[1];
} Bigint;

union double_union {
    double d;
    u32 i[2];
};

#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
#define Exp_shift 20
#define Exp_msk1 0x100000
#define Frac_mask 0xfffff
#define Bias 1023
#define P 53

extern double func_0011E640(Bigint *a, s32 *e);

double func_0011E960(Bigint *a, Bigint *b) {
    union double_union da, db;
    s32 k, ka, kb;

    da.d = func_0011E640(a, &ka);
    db.d = func_0011E640(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0)
        word0(da) += k * Exp_msk1;
    else {
        k = -k;
        word0(db) += k * Exp_msk1;
    }
    return da.d / db.d;
}
