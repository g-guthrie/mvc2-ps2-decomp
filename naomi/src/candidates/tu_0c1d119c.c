/* Candidate: 1254/1256 bytes. In func_0c1d1368 retail compares s28 with a
 * separate `mov #20,r3; cmp/ge`; writing `>=20` makes SHC share 20 with the
 * final `>20` test in r5, so this spells it `>19` (mov #19; cmp/gt). */
#include "objects.h"
extern struct Effect1cf *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct Vec3_tu5_03 dat_0c260ec8;
extern unsigned char dat_0c2f836b;
extern void func_0c02725c(int,int);
extern void func_0c037688(struct Effect1cf *);
extern void func_0c1d108c(struct Effect1cf *);
void func_0c1d11f0(struct Effect1cf *a);
void func_0c1d1368(struct Effect1cf *a);
void func_0c1d14de(struct Effect1cf *a);
void func_0c1d119c(struct Vec3_tu5_03 *pos)
{
    struct Effect1cf *a;
    if((a=func_0c0374da(0,7,1))!=0){
        a->b12c=1;
        a->p16=func_0c1d108c;
        a->l84=((int *)dat_0c2d9650->p0)[62];
        a->pos=*pos;
        a->v80=dat_0c260ec8;
        a->lcc=49;
    }
}
void func_0c1d11f0(struct Effect1cf *a)
{
    a->s28++;
    switch(a->b4){
    case 0:
        if(a->s28>=7)a->b4++;
        break;
    case 1:
        a->v80.x+=0.0460000001f;
        a->v80.z+=0.0460000001f;
        break;
    }
    switch(a->b5){
    case 0:
        a->v80.y+=0.571f;
        if(a->s28>=7)a->b5++;
        break;
    case 1:
        a->v80.y-=0.308f;
        break;
    }
    switch(a->b6){
    case 0:
        a->sc.f116+=0.16f;
        a->sc.f120+=0.16f;
        a->sc.f124+=0.16f;
        a->sc.f128+=0.16f;
        if(a->s28>=6)goto next6;
        break;
    case 1:
        a->sc.f116-=0.083f;
        a->sc.f120-=0.083f;
        a->sc.f124-=0.083f;
        a->sc.f128-=0.083f;
        if(a->s28>=18){next6:a->b6++;}
        break;
    case 2:
        break;
    }
    if(a->s28>20)func_0c037688(a);
}
void func_0c1d1314(struct Vec3_tu5_03 *pos)
{
    struct Effect1cf *a;
    if((a=func_0c0374da(0,7,1))!=0){
        a->b12c=1;
        a->p16=func_0c1d11f0;
        a->l84=((int *)dat_0c2d9650->p0)[63];
        a->pos=*pos;
        a->v80=dat_0c260ec8;
        a->lcc=57;
    }
}
void func_0c1d1368(struct Effect1cf *a)
{
    a->s28++;
    switch(a->b4){
    case 0:
        a->v80.x+=0.050000001f;
        a->v80.z+=0.050000001f;
        if(a->s28>19)a->b4++;
        break;
    }
    switch(a->b5){
    case 0:
        a->v80.y+=0.1875f;
        if(a->s28>=8)a->b5++;
        break;
    case 1:
        a->v80.y+=-0.125f;
        break;
    }
    switch(a->b6){
    case 0:
        a->sc.f116+=0.14285715f;
        a->sc.f120+=0.14285715f;
        a->sc.f124+=0.14285715f;
        a->sc.f128+=0.14285715f;
        if(a->s28>=7)goto next7;
        break;
    case 1:
        if(a->s28>=17){next7:a->b6++;}
        break;
    case 2:
        a->sc.f116+=-0.3333333433f;
        a->sc.f120+=-0.3333333433f;
        a->sc.f124+=-0.3333333433f;
        a->sc.f128+=-0.3333333433f;
        break;
    }
    if(a->s28>20)func_0c037688(a);
}
void func_0c1d148a(struct Vec3_tu5_03 *pos)
{
    struct Effect1cf *a;
    if((a=func_0c0374da(0,7,1))!=0){
        a->b12c=1;
        a->p16=func_0c1d1368;
        a->l84=((int *)dat_0c2d9650->p0)[64];
        a->pos=*pos;
        a->v80=dat_0c260ec8;
        a->lcc=57;
    }
}
void func_0c1d14de(struct Effect1cf *a)
{
    a->s28++;
    switch(a->b4){
    case 0:
        a->v80.x+=0.050000001f;
        a->v80.z+=0.050000001f;
        break;
    }
    switch(a->b5){
    case 0:
        a->v80.y+=-0.0250000004f;
        break;
    }
    switch(a->b6){
    case 0:
        a->sc.f116+=0.1000000015f;
        a->sc.f120+=0.1000000015f;
        a->sc.f124+=0.1000000015f;
        a->sc.f128+=0.1000000015f;
        if(a->s28>=10)goto next10;
        break;
    case 1:
        if(a->s28>=13){next10:a->b6++;}
        break;
    case 2:
        a->sc.f116+=-0.14285715f;
        a->sc.f120+=-0.14285715f;
        a->sc.f124+=-0.14285715f;
        a->sc.f128+=-0.14285715f;
        break;
    }
    if(a->s28>20)func_0c037688(a);
}
void func_0c1d15ce(struct Vec3_tu5_03 *pos)
{
    struct Effect1cf *a;
    if((a=func_0c0374da(0,7,1))!=0){
        a->b12c=1;
        a->p16=func_0c1d14de;
        a->l84=((int *)dat_0c2d9650->p0)[65];
        a->pos=*pos;
        a->v80=dat_0c260ec8;
        a->lcc=57;
    }
}
void func_0c1d1622(struct Vec3_tu5_03 *pos,int sound)
{
    if(sound>=0){
        dat_0c2f836b=1;
        func_0c02725c(sound,4);
    }
    func_0c1d119c(pos);
    func_0c1d1314(pos);
    func_0c1d148a(pos);
    func_0c1d15ce(pos);
}
