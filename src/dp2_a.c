typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_004B7890;
extern f32 D_004B7A50[], D_004B7A54[], D_004B7A58[];

typedef struct Actor Actor;
struct Actor {
 u8 prefix[0x14];Actor *parent;u8 pad18[0x1C];V3 position;
 int pad40;int rotation;u8 pad48[0x14];V3 saved;
 u8 pad68[0x20];float matrix[16];void *anchor;
 u8 padCC[12];int mode,enabled;
};
extern int func_00416AE0(float*),func_00416CC0(int);
extern void func_00416F80(float*);
static void func_00331EB0(Actor *p)
{
 if((p->enabled=p->parent->enabled)){
  switch(p->enabled=p->parent->mode){case 0:break;case 1:p->position.y-=1.0f;break;case 2:p->position.y+=1.0f;break;}
  if(!p->anchor){p->anchor=p->parent->matrix;p->position=p->saved;p->rotation=0;}
  return;
 }
 if(p->anchor){
  p->anchor=0;p->saved=p->position;func_00416AE0(0);func_00416F80(p->matrix);func_00416CC0(1);
  p->rotation=p->parent->parent->parent->rotation;
 }
}

typedef struct {
    u8 _0[0x10]; void *f10; u8 *f14; u8 _18[0x1C]; V3 f34; s32 f40, f44, f48;
    u8 _4c[0x38]; s32 f84; u8 _88[0x40]; u8 *fC8; s16 fCC; s16 _ce; s32 fD0; u8 _d4[8]; s32 fDC;
    u8 _e0[0x5C]; u8 f13C;
} O331;
void func_00331FE0(u8 *a) {
    extern O331 *func_003DA750(s32, s32, s32);

    O331 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o->f13C = 1;
        o->f10 = func_00331EB0;
        o->fCC = 5;
        o->f84 = D_004C283C;
        o->fD0 = 0x80F;
        o->f34 = D_004B7890;
        o->f14 = a;
        o->fC8 = a + 0x88;
        o->f40 = (s32)D_004B7A50[0];
        o->f44 = (s32)D_004B7A54[0];
        o->f48 = (s32)D_004B7A58[0];
        o->fDC = *(s32 *)(o->f14 + 0xDC);
    }
}
