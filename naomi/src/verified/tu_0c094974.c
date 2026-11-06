/* Landing, hop and fall handlers, spawn checks and hit-reaction setups for one
 * move family; two calls are tail-merged into fall-through to the next function. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, void *);
struct ActorCounts { unsigned char pad[124]; short counts[64]; };
typedef void (*ActorHandler_0c11543c)(struct Actor *);
struct Vec3_0c11543c { float x, y, z; };
extern struct ActorCounts *dat_0c2f83f8;
extern ActorHandler_0c11543c table_0c24c2e8[];
void func_0c11548e(struct Actor *, struct Actor *);
void func_0c0949f4(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c1d2a56(struct LinkedActorVec3 *,int);
extern unsigned char func_0c044e52(struct Actor *),func_0c044846(struct Actor *);
extern short dat_0c23b9d0[],dat_0c23ba08[];
extern void (*table_0c242ef4[])(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c046030(struct Actor *),func_0c0464c4(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044ae4(struct Actor *);
void func_0c03b37a(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c179a48(struct Actor *,int,int);
extern int func_0c17a03c(struct Actor *,int,int);
extern void (*table_0c24cb6c[])(struct Actor *),(*table_0c24cb74[])(struct Actor *),(*table_0c24cb7c[])(struct Actor *);
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c1185c2(struct Actor *a,struct ActorSub2a4 *b);
void func_0c094b66(struct Actor *a);
void func_0c094b1e(struct Actor *a,struct ActorSub2a4 *b);
void func_0c1188c2(struct Actor *a,struct ActorSub2a4 *b);
extern void (*table_0c242efc[])(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);
extern ActorHandler table_0c24d608[];
extern ActorSubHandler table_0c242f04[];
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c1bc740(struct Actor *, int, int);
extern void func_0c0439c4(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorHandler table_0c23f41c[];
extern ActorFactory table_0c23f424[];
extern void ;
extern struct Actor *func_0c037d54(struct Actor *);
void func_0c0547dc(struct Actor *a);
extern ActorHandler table_0c23f400[];
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern ActorFactory table_0c240974[];
extern ActorHandler table_0c240984[];
extern void func_0c190d1c(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern ActorFactory table_0c242f28[];
extern ActorFactory table_0c24298c[];
extern void func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *), func_0c048ce6(struct Actor *);

void func_0c094974(struct Actor *a, struct Actor *b)
{
    register int arg6;

    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    arg6 = 6;
    a->b1a1 = 62;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 21, arg6);
    func_0c0949f4(a, b);
}

void func_0c0949f4(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        struct LinkedActorVec3 v;

        a->b141 = 0;
        v.x = 55.0f;
        v.y = 158.57143f;
        func_0c043014(a, &v);
    }
}

void func_0c094a3e(struct Actor *a){table_0c242ef4[a->b6](a);}

void func_0c094a50(struct Actor *a,struct ActorSub2a4 *b)
{
 void *zero;
 if(a->b201){func_0c094b66(a);return;}
 a->b6++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 if(a->b1f9!=2)func_0c0432ca(a);
 zero=0;
 a->b201=1;
 b->s10=480;
 a->b1f9=2;
 a->b1fc=(int)zero;
 a->b1d4=(int)zero;
 a->pad7f2=(int)zero;
 a->f92=0.0f;a->f104=0.0f;
 a->f96=12.85714245f;
 a->f108=-0.2678571343422f;
 func_0c02a0c4(a,26,(int)zero);
 func_0c094b1e(a,b);
}

void func_0c094b1e(struct Actor *a, struct ActorSub2a4 *b)
{
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}



void func_0c094b66(struct Actor *a)
{
 a->b201=0;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f108=-0.80357140303f;
 func_0c0438de(a);
}

void func_0c094b8a(struct Actor *a){table_0c242efc[a->b6](a);}

void func_0c094b9c(struct Actor *a)
{
 if((unsigned char)a->b159==26){
  func_0c0442fa(a);
  if(a->b201){
   a->f92/=8.0f;a->f104/=8.0f;a->f96/=8.0f;a->f108/=8.0f;
  }else{
   a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
   a->f108=-0.80357140303f;
  }
 }
}



void func_0c094c38(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    table_0c242f04[a->b1e9](a, sub);
}

struct Actor *func_0c094c50(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return r;
        }
    }
    return 0;
}

struct Actor *func_0c094cc8(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 2;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 3;
            return r;
        }
    }
    return 0;
}



int func_0c094d5c(void) { return 0; }

struct Actor *func_0c094d60(struct Actor *a)
{
    return table_0c242f28[a->b1f9](a);
}

void func_0c094d78(struct Actor *a)
{
    struct LinkedActorVec3 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 0);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -238.33333f;
    v.y = 184.28571f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}

void func_0c094de6(struct Actor *a)
{
    struct LinkedActorVec3 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 2);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -238.33333f;
    v.y = 184.28571f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}
