typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;

#include "actor_inherited_state.h"
typedef ActorState Payload;

extern void func_0015E630(u8*);
extern int func_001757E0(u8*,int,int);
extern void func_001DEC50(u8*,u8*);
void func_001D3240(u8*p,u8*q){f32 *fp=(f32*)p;f32 offset;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[4]++;p[0x24]=12;offset=-60.0f;p[0x14e]=48;p[0x14f]=48;fp[23]=10.0f;
if(q[0x1e6]){offset=-offset;fp[23]=-fp[23];}
*(f32*)(p+0x34)=*(f32*)(q+0x34)+offset;*(f32*)(p+0x38)=*(f32*)(q+0x430);
func_0015E630(p);func_001757E0(p,23,30);}

void func_001DEB20(u8*p,u8*q){f32 *fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;*(s8*)(p+0x31)=-1;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
fp[23]=-65.0f;*(f32*)(p+0x60)=216.428558349609375f;
if(*(s16*)(p+0x140))fp[23]=-fp[23];
func_001757E0(p,23,29);func_001DEC50(p,q);}

extern int func_001754A0(u8*,int,int);
extern void func_001D9700(u8*,u8*);
extern void func_001D8F60(u8*,u8*);

void func_001D9550(u8*p,u8*q){f32 *fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;*(s8*)(p+0x31)=-1;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
fp[23]=-256.666656494140625f;
if(*(s16*)(p+0x140))fp[23]=-fp[23];
*(f32*)(p+0x60)=154.28570556640625f;func_001754A0(p,27,0);func_001D9700(p,q);}

void func_001D8E10(u8*p,u8*q){f32*fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
*(s8*)(p+0x31)=-1;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=184.28570556640625f+*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
fp[23]=-11.6666660308837890625f;if(*(s16*)(p+0x140))fp[23]=-fp[23];fp[13]+=fp[23];
func_001757E0(p,23,6);func_001D8F60(p,q);}

extern void func_001D5CF0(u8*,u8*);
extern void func_001DA3F0(u8*,u8*);

void func_001D5B80(u8*p,u8*q){f32 *fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;p[0x31]=2;
*(f32*)(p+0x5c)=0;*(f32*)(p+0x60)=0;*(f32*)(p+0x68)=0;*(f32*)(p+0x6c)=0;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
if(!*(s16*)(p+0x140)){f32 position=fp[13]; f32 displacement=33.333332061767578125f; fp[13]=position+displacement;}
else fp[13]=fp[13]-33.333332061767578125f;
func_001757E0(p,18,10);*(s16*)(p+0x1c)=60;func_001D5CF0(p,q);}

void func_001DA290(u8*p,u8*q){f32 *fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;p[0x31]=1;
*(f32*)(p+0x5c)=0;*(f32*)(p+0x60)=0;*(f32*)(p+0x68)=0;*(f32*)(p+0x6c)=0;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
if(!*(s16*)(p+0x140)){f32 position=fp[13]; f32 displacement=33.333332061767578125f; fp[13]=position+displacement;}
else fp[13]=fp[13]-33.333332061767578125f;
func_001757E0(p,18,10);*(s16*)(p+0x1c)=60;func_001DA3F0(p,q);}

extern s16 D_004BF770[] __attribute__((section(".sdata")));
extern s16 D_004BF772[] __attribute__((section(".sdata")));
extern void func_001A7500(u8*,void*);
void func_001A7340(u8*p,u8*q){f32*fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;*(s8*)(p+0x31)=-1;*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
fp[23]=1.66666662693023681640625f*(f32)D_004BF770[p[0x21]*2];
fp[24]=2.142857074737548828125f*(f32)D_004BF772[p[0x21]*2];
if(*(s16*)(p+0x140))fp[23]=-fp[23];
func_001757E0(p,23,17);func_001A7500(p,q);}
extern void func_001DE470(u8*,u8*);
void func_001DE300(u8*p,u8*q){f32*fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;*(s8*)(p+0x31)=-1;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
if(!*(s16*)(p+0x140))fp[13]-=16.6666660308837890625f;
else {f32 position=fp[13];f32 displacement=16.6666660308837890625f;fp[13]=position+displacement;}
{f32 position=fp[14];f32 displacement=77.142852783203125f;fp[14]=position+displacement;}
func_001757E0(p,23,21);func_001DE470(p,q);}

#pragma padloop on
extern void func_001D9960(u8 *, u8 *);

void func_001D9780(u8 *p, u8 *q) {
    f32 *fp = (f32 *)p;
    u8 *r = p + 0xD0;
    p[4]++;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
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
    fp[0x50 / 4] = 1.5f;
    fp[0x118 / 4] = 0.5f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (p[0x21] == 0)
        p[0x168] = 7;
    else
        p[0x168] = 8;
    func_001754A0(p, 27, p[0x168]);
    fp[0x5C / 4] = 0.0f;
    if (*(s16 *)(p + 0x140) != 0)
        fp[0x5C / 4] = -fp[0x5C / 4];
    if (p[0x20] == 2) {
        fp[0x60 / 4] = 188.57142639160156f;
    } else {
        fp[0x60 / 4] = 229.28570556640625f;
        *(s32 *)(p + 0x48) = 2560;
    }
    r[2] = 0;
    r[3] = 3;
    func_001D9960(p, q);
}

/* Interleaved signed coordinate views; callers select the native pose index. */
extern s16 D_0044ED30[];
extern s16 D_0044ED32[];
extern u8 D_0044ED58[];
extern void func_001DEA90(u8 *, u8 *);
void func_001DE8D0(u8 *p, u8 *q) {
    f32 *fp = (f32 *)p;
    p[4]++;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
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
    *(s8 *)(p + 0x31) = -1;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    fp[23] = 1.6666666269302368f * D_0044ED30[p[0x21] * 2];
    *(f32 *)(p + 0x38) += 2.1428570747375488f * D_0044ED32[p[0x21] * 2];
    if (*(s16 *)(p + 0x140)) fp[23] = -fp[23];
    *(f32 *)(p + 0x34) += fp[23];
    func_001757E0(p, 23, D_0044ED58[p[0x21]]);
    func_001DEA90(p, q);
}

extern s8 D_004BF780[] __attribute__((section(".sdata")));
extern s16 D_004BF778[] __attribute__((section(".sdata")));
extern f32 D_004F1FD0;
extern void func_001A7820(u8 *, u8 *);
void func_001A7560(u8 *p, u8 *q) {
    f32 *fp = (f32 *)p;
    p[4]++;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
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
    p[0x13C] = 0;
    *(s8 *)(p + 0x31) = D_004BF780[p[0x21]];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = D_004F1FD0;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (*(s16 *)(p + 0x140) == 0)
        fp[13] += 1.6666666269302368f * D_004BF778[p[0x21]];
    else
        fp[13] -= 1.6666666269302368f * D_004BF778[p[0x21]];
    *(f32 *)(p + 0x60) = -12.857142448425293f;
    *(f32 *)(p + 0x6C) = -0.8035714030265808f;
    func_001757E0(p, 19, 7);
    *(s16 *)(p + 0x1C) = p[0x21] * 8;
    func_001A7820(p, q);
}
