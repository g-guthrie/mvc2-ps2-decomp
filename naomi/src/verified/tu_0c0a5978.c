#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c244210[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c14b8d8(struct Actor *, int, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);

extern float dat_0c243f68[],dat_0c243da8[];
extern int func_0c02887e(float *,float *);
void func_0c0a5978(struct Actor *a)
{
    float *choices=dat_0c243f68;
    float *table;
    unsigned short index;
    if (a->s30<4) {
        a->b35=(unsigned char)func_0c02887e(&a->f52,&a->p20c->f52)>>3;
        table=dat_0c243da8;
        a->b35=(int)choices[a->b35];
        index=a->b35;
        table+=index*7;
        a->b6=a->b6+1;
        a->s28=30;
        a->s30=a->s30+1;
        a->f92=table[0];
        a->f104=table[1];
        a->f96=table[2];
        a->f108=table[3];
        a->b7=(int)table[6];
        a->w130=(int)(!(table[5]<0) ? table[5] : (float)(short)a->w130);
        func_0c19fadc(a,0);
        func_0c19fadc(a,1);
        a->i72=0;
        func_0c02a0c4(a,22,1);
    }
}
void func_0c0a5a52(struct Actor *a)
{
    table_0c244210[a->b6](a);
}
void func_0c0a5a64(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1a1 = 62;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 9);
}

