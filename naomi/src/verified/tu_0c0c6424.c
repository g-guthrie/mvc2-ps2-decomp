#include "objects.h"
extern void (*table_0c24780c[])(struct Actor *);
extern void (*table_0c247828[])(struct Actor *);
extern void (*table_0c24781c[])(struct Actor *);
/* func_0c0c6424: no twin (128 bytes) */
extern char func_0c02a026(struct Actor*);
extern void func_0c0437b8(struct Actor*);
extern void func_0c02a0c4(struct Actor *,int,int);
extern int func_0c02849a(void);
extern unsigned char table_0c247814[][2];
void func_0c0c6424(struct Actor *a);
void func_0c0c64a4(struct Actor *a);
void func_0c0c6510(struct Actor *a);
void func_0c0c6522(struct Actor *a);
void func_0c0c6544(struct Actor *a);
void func_0c0c6558(struct Actor *a);

void func_0c0c6424(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f41c < a->f56)) {
        a->b6 = a->b6 + 1;
        a->f56 = a->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        a->b1f9 = 0;
        func_0c02a0c4(a, 2, 3);
    }
}

void func_0c0c64a4(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(func_0c02a026(a)<0)func_0c0437b8(a);if(a->b141){a->b141=0;a->f92=0;a->f104=0;}}

void func_0c0c6510(struct Actor *a){table_0c24780c[a->b6](a);}

void func_0c0c6522(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b32 = table_0c247814[func_0c02849a() & 3][0];
    func_0c0c6544(a);
}

void func_0c0c6544(struct Actor *a) { table_0c24781c[a->b32](a); }

void func_0c0c6558(struct Actor *a){table_0c247828[a->b7](a);}
