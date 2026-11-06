#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(struct Obj_tu5_03 *,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c233154;
extern struct Vec3_tu5_03 dat_0c233160;
extern struct Vec3_tu5_03 dat_0c23319c;
extern struct Vec3_tu5_03 dat_0c2331c0;
extern struct Vec3_tu5_03 dat_0c2331e4;
extern struct Vec3_tu5_03 dat_0c233208;
extern struct Vec3_tu5_03 dat_0c233220;
extern struct Vec3_tu5_03 dat_0c233238;
extern struct Vec3_tu5_03 dat_0c233250;
extern struct Vec3_tu5_03 dat_0c23328c;
extern struct Vec3_tu5_03 dat_0c2fb640;
extern struct Vec3_tu5_03 dat_0c2fb64c;
extern struct Vec3_tu5_03 dat_0c2fb658;
extern struct Vec3_tu5_03 dat_0c2fb664;
extern struct Vec3_tu5_03 dat_0c2fb670;
extern struct Vec3_tu5_03 dat_0c2fb67c;
extern struct Vec3_tu5_03 dat_0c2fb688;
extern struct Vec3_tu5_03 dat_0c23316c[];
extern struct Vec3_tu5_03 dat_0c233184[];
extern struct Vec3_tu5_03 dat_0c2331a8[];
extern struct Vec3_tu5_03 dat_0c2331cc[];
extern struct Vec3_tu5_03 dat_0c2331f0[];
extern struct Vec3_tu5_03 dat_0c233268[];
extern struct Vec3_tu5_03 dat_0c233298[];
extern float dat_0c233218;
extern float dat_0c233230;
extern float dat_0c233248;
extern float dat_0c233260;
extern void (*dat_0c262340[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262348[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262350[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262358[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262360[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262368[2])(struct Obj_tu5_03 *);
extern void (*dat_0c262370[2])(struct Obj_tu5_03 *);
void func_0c1de70c(struct Obj_tu5_03 *);
void func_0c1de752(int);
void func_0c1de792(struct Obj_tu5_03 *);
void func_0c1de7a6(struct Obj_tu5_03 *);
void func_0c1de826(struct Obj_tu5_03 *);
void func_0c1de934(int);
void func_0c1de978(struct Obj_tu5_03 *);
void func_0c1de9c0(struct Obj_tu5_03 *);
void func_0c1dea40(struct Obj_tu5_03 *);
void func_0c1deb30(struct Obj_tu5_03 *);
void func_0c1debbc(struct Obj_tu5_03 *);
void func_0c1debd0(struct Obj_tu5_03 *);
void func_0c1dec50(struct Obj_tu5_03 *);
void func_0c1ded18(int);
void func_0c1ded5c(struct Obj_tu5_03 *);
void func_0c1ded70(struct Obj_tu5_03 *);
void func_0c1dedf0(struct Obj_tu5_03 *);
void func_0c1deeec(struct Obj_tu5_03 *);
void func_0c1def78(struct Obj_tu5_03 *);
void func_0c1defc8(struct Obj_tu5_03 *);
void func_0c1df048(struct Obj_tu5_03 *);
void func_0c1df138(int);
void func_0c1df1b0(struct Obj_tu5_03 *);
void func_0c1df1f6(int);
void func_0c1df29c(struct Obj_tu5_03 *);
void func_0c1df2f2(int);
void func_0c1df356(struct Obj_tu5_03 *);
void func_0c1df36a(struct Obj_tu5_03 *);
void func_0c1df42c(struct Obj_tu5_03 *);
void func_0c1df4b2(int);
void func_0c1df4f6(struct Obj_tu5_03 *);
void func_0c1df50a(struct Obj_tu5_03 *);
void func_0c1df5b8(struct Obj_tu5_03 *);
void func_0c1df686(struct Obj_tu5_03 *);
void func_0c1df748(struct Obj_tu5_03 *);
void func_0c1df79e(int);
void func_0c1df802(struct Obj_tu5_03 *);
void func_0c1df88c(int);
void func_0c1df8f0(void);
void func_0c1de70c(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->angles.array[0]=(int)((float)a->w28*98304.0f/360.0f+0.5f)&65535;
        if(++a->w28>=240)a->w28=0;
        break;
    }
}

void func_0c1de752(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1de70c;
        a->l84=(int)((void **)dat_0c2d964c->p0)[8];
        a->lcc=0x803; a->pos=dat_0c233154;
    }
}

void func_0c1de792(struct Obj_tu5_03 *a)
{
    dat_0c262340[a->b4](a);
    return;
}

void func_0c1de7a6(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c23316c[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c23316c[(unsigned char)a->b5];
    duration=150.0f;
    dat_0c2fb664.x=(a->f104-a->f92)/duration;
    dat_0c2fb664.y=(a->f108-a->f96)/duration;
    dat_0c2fb664.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1de826(a);
    return;
}

void func_0c1de826(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>150){a->b4=0; a->w28=0; return;}
    a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[0]+=(int)(dat_0c2fb664.x*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]+=(int)(dat_0c2fb664.y*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]+=(int)(dat_0c2fb664.z*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
}

void func_0c1de934(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1de792;
        a->l84=(int)((void **)dat_0c2d964c->p0)[9];
        a->lcc=0x803; a->pos=dat_0c233160;
        func_0c1deb30(a);
    }
}

void func_0c1de978(struct Obj_tu5_03 *a)
{
    dat_0c262348[a->b4](a);
    return;
}

void func_0c1de9c0(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c233184[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c233184[(unsigned char)a->b5];
    duration=150.0f;
    dat_0c2fb670.x=(a->f104-a->f92)/duration;
    dat_0c2fb670.y=(a->f108-a->f96)/duration;
    dat_0c2fb670.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1dea40(a);
    return;
}

void func_0c1dea40(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>150){a->b4=0; a->w28=0; return;}
    a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[0]+=(int)(dat_0c2fb670.x*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]+=(int)(dat_0c2fb670.y*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]+=(int)(dat_0c2fb670.z*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
}

void func_0c1deb30(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1de978;
        a->l84=(int)((void **)dat_0c2d964c->p0)[10];
        a->lcc=0x803; a->pos=dat_0c23319c;
        a->angles.array[0]=(int)(dat_0c233184[0].x*65536.0f/360.0f+0.5f)&65535;
        a->angles.array[1]=(int)(dat_0c233184[0].y*65536.0f/360.0f+0.5f)&65535;
        a->p20=parent; a->p200=&parent->f136;
    }
}

void func_0c1debbc(struct Obj_tu5_03 *a)
{
    dat_0c262350[a->b4](a);
    return;
}

void func_0c1debd0(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c2331a8[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c2331a8[(unsigned char)a->b5];
    duration=100.0f;
    dat_0c2fb640.x=(a->f104-a->f92)/duration;
    dat_0c2fb640.y=(a->f108-a->f96)/duration;
    dat_0c2fb640.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1dec50(a);
    return;
}

void func_0c1dec50(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>100){a->b4=0; a->w28=0; return;}
    a->pos.x=a->f92;
    a->pos.y=a->f96;
    a->pos.z=a->f100;
    a->pos.x+=dat_0c2fb640.x*(float)a->w28;
    a->pos.y+=dat_0c2fb640.y*(float)a->w28;
    a->pos.z+=dat_0c2fb640.z*(float)a->w28;
}

void func_0c1ded18(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1debbc;
        a->l84=(int)((void **)dat_0c2d964c->p0)[13];
        a->lcc=0x801; a->pos=dat_0c2331a8[0];
        func_0c1deeec(a);
    }
}

void func_0c1ded5c(struct Obj_tu5_03 *a)
{
    dat_0c262358[a->b4](a);
    return;
}

void func_0c1ded70(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c2331cc[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c2331cc[(unsigned char)a->b5];
    duration=100.0f;
    dat_0c2fb64c.x=(a->f104-a->f92)/duration;
    dat_0c2fb64c.y=(a->f108-a->f96)/duration;
    dat_0c2fb64c.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1dedf0(a);
    return;
}

void func_0c1dedf0(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>100){a->b4=0; a->w28=0; return;}
    a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[0]+=(int)(dat_0c2fb64c.x*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]+=(int)(dat_0c2fb64c.y*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]+=(int)(dat_0c2fb64c.z*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
}

void func_0c1deeec(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1ded5c;
        a->l84=(int)((void **)dat_0c2d964c->p0)[14];
        a->lcc=0x807; a->pos=dat_0c2331c0;
        a->angles.array[0]=(int)(dat_0c2331cc[0].x*65536.0f/360.0f+0.5f)&65535;
        a->angles.array[1]=(int)(dat_0c2331cc[0].y*65536.0f/360.0f+0.5f)&65535;
        a->p20=parent; a->p200=&parent->f136;
    }
}

void func_0c1def78(struct Obj_tu5_03 *a)
{
    dat_0c262360[a->b4](a);
    return;
}

void func_0c1defc8(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c2331f0[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c2331f0[(unsigned char)a->b5];
    duration=100.0f;
    dat_0c2fb658.x=(a->f104-a->f92)/duration;
    dat_0c2fb658.y=(a->f108-a->f96)/duration;
    dat_0c2fb658.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1df048(a);
    return;
}

void func_0c1df048(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>100){a->b4=0; a->w28=0; return;}
    a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[0]+=(int)(dat_0c2fb658.x*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]+=(int)(dat_0c2fb658.y*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]+=(int)(dat_0c2fb658.z*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
}

void func_0c1df138(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1def78;
        a->l84=(int)((void **)dat_0c2d964c->p0)[15];
        a->lcc=0x807; a->pos=dat_0c2331e4;
        a->angles.array[0]=(int)(dat_0c2331f0[0].x*65536.0f/360.0f+0.5f)&65535;
        a->angles.array[1]=(int)(dat_0c2331f0[0].y*65536.0f/360.0f+0.5f)&65535;
    }
}

void func_0c1df1b0(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->angles.array[0]=(int)((float)a->w28*32768.0f/360.0f+0.5f)&65535;
        if(++a->w28>=720)a->w28=0;
        break;
    }
}

void func_0c1df1f6(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df1b0;
        a->l84=(int)((void **)dat_0c2d964c->p0)[16];
        a->lcc=0x807; a->pos=dat_0c233208;
        a->angles.array[1]=(int)(dat_0c233218*65536.0f/360.0f+0.5f)&65535;
    }
}

void func_0c1df29c(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->angles.array[0]=(int)((float)a->w28*65536.0f/360.0f+0.5f)&65535;
        a->w28+=3;
        if(a->w28>=360)a->w28%=360;
        break;
    }
}

void func_0c1df2f2(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df29c;
        a->l84=(int)((void **)dat_0c2d964c->p0)[17];
        a->lcc=0x807; a->pos=dat_0c233220;
        a->angles.array[1]=(int)(dat_0c233230*65536.0f/360.0f+0.5f)&65535;
    }
}

void func_0c1df356(struct Obj_tu5_03 *a)
{
    dat_0c262368[a->b4](a);
    return;
}

void func_0c1df36a(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c233268[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c233268[(unsigned char)a->b5];
    duration=60.0f;
    dat_0c2fb688.x=(a->f104-a->f92)/duration;
    dat_0c2fb688.y=(a->f108-a->f96)/duration;
    dat_0c2fb688.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1df42c(a);
    return;
}

void func_0c1df42c(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>60){a->b4=0; a->w28=0; return;}
    a->pos.x=a->f92;
    a->pos.y=a->f96;
    a->pos.z=a->f100;
    a->pos.x+=dat_0c2fb688.x*(float)a->w28;
    a->pos.y+=dat_0c2fb688.y*(float)a->w28;
    a->pos.z+=dat_0c2fb688.z*(float)a->w28;
}

void func_0c1df4b2(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df356;
        a->l84=(int)((void **)dat_0c2d964c->p0)[11];
        a->lcc=0x801; a->pos=dat_0c233268[0];
        func_0c1df686(a);
    }
}

void func_0c1df4f6(struct Obj_tu5_03 *a)
{
    dat_0c262370[a->b4](a);
    return;
}

void func_0c1df50a(struct Obj_tu5_03 *a)
{
    float duration;
    *(struct Vec3_tu5_03 *)&a->f92=dat_0c233298[(unsigned char)a->b5];
    a->b5++; a->b5&=1;
    *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c233298[(unsigned char)a->b5];
    duration=60.0f;
    dat_0c2fb67c.x=(a->f104-a->f92)/duration;
    dat_0c2fb67c.y=(a->f108-a->f96)/duration;
    dat_0c2fb67c.z=(a->f112-a->f100)/duration;
    a->b4=1; func_0c1df5b8(a);
    return;
}

void func_0c1df5b8(struct Obj_tu5_03 *a)
{
    a->w28++;
    if(a->w28>60){a->b4=0; a->w28=0; return;}
    a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[0]+=(int)(dat_0c2fb67c.x*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[1]+=(int)(dat_0c2fb67c.y*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
    a->angles.array[2]+=(int)(dat_0c2fb67c.z*(float)a->w28*65536.0f/360.0f+0.5f)&65535;
}

void func_0c1df686(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df4f6;
        a->l84=(int)((void **)dat_0c2d964c->p0)[12];
        a->lcc=0x807; a->pos=dat_0c23328c;
        a->angles.array[0]=(int)(dat_0c233298[0].x*65536.0f/360.0f+0.5f)&65535;
        a->angles.array[1]=(int)(dat_0c233298[0].y*65536.0f/360.0f+0.5f)&65535;
        a->p20=parent; a->p200=&parent->f136;
    }
}

void func_0c1df748(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->angles.array[0]=(int)((float)a->w28*65536.0f/360.0f+0.5f)&65535;
        a->w28+=2;
        if(a->w28>=360)a->w28%=360;
        break;
    }
}

void func_0c1df79e(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df748;
        a->l84=(int)((void **)dat_0c2d964c->p0)[18];
        a->lcc=0x807; a->pos=dat_0c233238;
        a->angles.array[1]=(int)(dat_0c233248*65536.0f/360.0f+0.5f)&65535;
    }
}

void func_0c1df802(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->angles.array[0]=(int)((float)a->w28*65536.0f/360.0f+0.5f)&65535;
        a->w28++;
        if(a->w28>=360)a->w28%=360;
        break;
    }
}

void func_0c1df88c(int unused_type)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1; a->p16=func_0c1df802;
        a->l84=(int)((void **)dat_0c2d964c->p0)[19];
        a->lcc=0x807; a->pos=dat_0c233250;
        a->angles.array[1]=(int)(dat_0c233260*65536.0f/360.0f+0.5f)&65535;
    }
}

void func_0c1df8f0(void)
{
    func_0c1de752(8);
    func_0c1de934(9);
    func_0c1ded18(13);
    func_0c1df138(15);
    func_0c1df1f6(16);
    func_0c1df2f2(17);
    func_0c1df79e(18);
    func_0c1df88c(19);
    func_0c1df4b2(11);
}
