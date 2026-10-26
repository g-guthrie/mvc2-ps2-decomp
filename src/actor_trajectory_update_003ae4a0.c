typedef unsigned char u8;typedef short s16;typedef unsigned short u16;typedef int s32;typedef float f32;
typedef struct {f32 x,y,z;} V3;typedef struct {u8 p0[0x34];V3 pos;} Q;
typedef struct {u8 p0[0x18];Q*q;u8 p1[0x21-0x1C];u8 b21;u8 p2[0x34-0x22];V3 pos;u8 p3[0xD0-0x40];s32 i;u8 p4[0x140-0xD4];s16 flag;} H;
typedef struct {u8 pad0[0x10];void (*callback)(u8*);u8 pad14[4];void *owner;u8 pad1c[4];u8 field20,field21;u8 pad22[4];u16 value;u8 pad28[0xC];V3 pos;} Event;
extern void *func_003DA750(void*,int,int);extern void func_003AD6E0(u8*);extern int func_00175700(u8*);
extern s16 D_004C1F50[] __attribute__((section(".sdata")));
static void func_003AE370(u8*p) {*(s16*)(p+0x1E)=D_004C1F50[*(int*)(p+0xD0)];}
extern signed char D_00473B80[],D_00473B81[];
static void func_003AE2C0(H *p)
{
    f32 t;
    p->pos = p->q->pos;
    t = 1.6666666269302368f * (f32)D_00473B80[p->i * 4 + p->b21 * 2];
    p->pos.y += 2.142857074737549f * (f32)D_00473B81[p->i * 4 + p->b21 * 2];
    if (p->flag != 0) t = -t;
    p->pos.x += t;
}

void func_003AE4A0(u8*p) {
 if(--*(s16*)(p+0x1E)<=0) {
  ++*(int*)(p+0xD0);func_003AE370(p);
  if(!*(s16*)(p+0x1E)) {++p[4];if(!p[0x21])(*(u8**)(p+0x18))[7]=2;return;}
  {Event*e=func_003DA750(0,1,1);if(e) {e->callback=func_003AD6E0;e->owner=*(u8**)(p+0x18);e->field20=8;e->field21=p[0x21];e->value=0x3002;e->pos=*(V3*)(p+0x34);}}
 }
 func_003AE2C0((H*)p);func_00175700(p);
}
