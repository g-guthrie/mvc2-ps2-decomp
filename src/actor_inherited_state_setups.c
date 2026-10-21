#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
#include "actor_inherited_state.h"
extern u16 *D_004C26E0, *D_004C26E8;
void func_001B8870(u8 *p)
{
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x24] = 0;
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34);
    *(f32 *)(p+0x38) = *(f32 *)(*(u8 **)(p+0x18)+0x38);
    *D_004C26E0 = *(u16 *)(*(u8 **)(p+0x18)+0x168);
}

void func_001B9030(u8 *p)
{
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x13C] = 0;
    p[0x24] = 7;
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34);
    *(f32 *)(p+0x38) = *(f32 *)(*(u8 **)(p+0x18)+0x38);
    *D_004C26E8 = *(u16 *)(*(u8 **)(p+0x18)+0x168);
}

typedef unsigned int u32;
extern int func_001754A0(u8 *, int, int);

void func_001B1390(u8 *p)
{
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    *(f32 *)(p + 0x34) += *(s16 *)(*(u8 **)(p + 0x18) + 0x140) ? 400.0f : -400.0f;
    *(f32 *)(p + 0x34) += *(s16 *)(*(u8 **)(p + 0x18) + 0x140) ? -106.66666412353516f : 106.66666412353516f;
    *(f32 *)(p + 0x38) += 51.428569793701172f;
    if (*(s16 *)(q + 0x140))
        func_001754A0(p, 0x1B, 5);
    else
        func_001754A0(p, 0x1B, 6);
}

/* Additional inherited-state users with real timer, offset-pair and parent fields. */
extern void func_003DAA40(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern int func_00175670(u8 *);
extern u8 *func_001CCC20(u8 *);
extern void func_001E3210(u8 *, u8);
extern u8 *D_004C2840;
typedef struct { f32 x, y; } SpawnOffset;
extern SpawnOffset D_0044DD50[];
typedef struct { u8 prefix[0x1C]; s16 timer; } ActorTimer;

void func_001D1F10(u8 *p) {
    unsigned int state=p[4];
    u8 *q=*(u8 **)(p+0x18);
    switch(state) {
    case 0:
        p[4]=state+1;
        *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
        func_001757E0(p,0x17,11);
    case 1:
        if(q[0x1E4]!=p[0x22] || q[0x1FD]!=p[0x23]) {
            p[4]++;p[0x13C]=0;
        } else {
            *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
            if(!*(s8 *)(q+0x1B4) && (s8)func_00175700(p)<0) {p[4]++;p[0x13C]=0;}
        }
        break;
    case 2: func_003DAA40(p);break;
    }
}

void func_001CCDA0(u8 *p,u8 *q) {
    ActorTimer *timer=(ActorTimer *)p;
    unsigned int state=p[4];
    if(state==0) {
        p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
        *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
        *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
        *(int *)(p+0xD4)=0;
        timer->timer=1;
        p[0x13C]=0;
    }
    if(*(int *)(p+0xD0)!=*(u16 *)(q+0x168)) {
        func_003DAA40(p);return;
    }
    {
    s16 remaining=timer->timer;
    --remaining;
    timer->timer=remaining;
    if(remaining<=0) {
        u8 *child;
        timer->timer=16;
        child=func_001CCC20(p);
        if(child) {
            f32 x;
            ++*(int *)(p+0xD4);
            *(int *)(p+0xD4)&=3;
            x=D_0044DD50[*(int *)(p+0xD4)].x;
            *(f32 *)(child+0x38)=*(f32 *)(p+0x38)+D_0044DD50[*(int *)(p+0xD4)].y;
            if(*(s16 *)(p+0x140)) x=-x;
            *(f32 *)(child+0x34)=*(f32 *)(p+0x34)+x;
        }
    }
}
}

void func_001D3A60(u8 *p,u8 *q) {
    unsigned int state=p[4];
    if(state==0) {
        p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
        *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
        *(s8 *)(p+0x31)=-4;
        func_001754A0(p,0x1B,5);
        func_001E3210(p,0x21);
    }
    *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
    if(q[5]!=1 || !*(s8 *)(q+0x150)) {func_003DAA40(p);return;}
    {
        s16 offset=*(s16 *)(q+0x140)?72:-72;
        *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+1.6666666269302368f*offset;
        *(f32 *)(p+0x38)=248.57142639160156f+*(f32 *)(q+0x38);
    }
    func_00175670(p);
    if(*(int *)(D_004C2840+0x1C)&1) p[0x13C]=0;
    else p[0x13C]=1;
}

extern u16 *D_004C26E4, *D_004C26EC;

void func_001B8B70(u8 *p)
{
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x24] = 7;
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34);
    *(f32 *)(p+0x38) = *(f32 *)(*(u8 **)(p+0x18)+0x38);
    func_001754A0(p, 0x1B, 12);
    *D_004C26E4 = *(u16 *)(*(u8 **)(p+0x18)+0x168);
}

void func_001B9480(u8 *p)
{
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x24] = 7;
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34);
    *(f32 *)(p+0x38) = *(f32 *)(*(u8 **)(p+0x18)+0x38);
    *(f32 *)(p+0x34) += *(s16 *)(p+0x140) ? 65.0f : -65.0f;
    *(f32 *)(p+0x38) += 231.428558349609375f;
    *(f32 *)(p+0x5C) = 0.0f;
    *(f32 *)(p+0x68) = 0.0f;
    *(f32 *)(p+0x60) = 2.142857074737549f;
    *(f32 *)(p+0x6C) = -0.5357142686843872f;
    func_001754A0(p, 0x1B, 18);
    *D_004C26EC = *(u16 *)(*(u8 **)(p+0x18)+0x168);
}
