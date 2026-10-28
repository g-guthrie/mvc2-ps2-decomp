typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32;
extern u16 D_004D18DC; extern u8 D_004D18DB;
typedef struct {s8 i; u8 b1,b2,b3; u8 gap[3];u8 b7;} Q; typedef struct {u8 pad[0x1c];s16 c;} P;
static void func_00396F00(u8 *p,u8 *q) { if(q[2]<12){u32 v=q[3]-1;q[3]=v;if((u8)v<=0){q[3]=2;q[2]++;}} }
static void func_00396F40(P *p,Q *q) { if(--p->c<=0){p->c=2;q->i++;if(q->i>=8)q->i=5;} }
/* D_004C1E40 state reached from func_00397140 with (actor, owner, work = actor+0x88). */
void func_00397180(u8 *p,u8 *owner,u8 *work_arg) {
 Q *work=(Q *)work_arg;
 if(owner[0x169]!=22) {p[4]++;p[0x13c]=0;}
 else if(owner[0x168]!=12) {p[5]++;work->i=4;*(s16 *)(p+0x1c)=2;}
 else if(!(D_004D18DC & (1 << D_004D18DB))) {
  work->b7=0; if(*(s16 *)(owner+0x1c)<=0) {p[5]++;work->i=4;*(s16 *)(p+0x1c)=2;}
  func_00396F00(p,(u8 *)work);func_00396F40((P*)p,work);
 }
}
