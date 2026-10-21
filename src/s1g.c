typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct E { u16 a, b, c, d; } E;
typedef struct B { char pad[0x4B8]; E e[1]; } B;
static inline void ga(B *p, s32 i, s32 *o) { if (o) *o = p->e[i].a; }
static inline void gb(B *p, s32 i, s32 *o) { if (o) *o = p->e[i].b; }
static inline void gc(B *p, s32 i, s32 *o) { if (o) *o = p->e[i].c; }
static inline void gd(B *p, s32 i, s32 *o) { if (o) *o = p->e[i].d; }
void func_00405388(B *p, s32 i, s32 *a, s32 *b, s32 *c, s32 *d) { ga(p,i,a); gb(p,i,b); gc(p,i,c); gd(p,i,d); }
extern float func_003DE700(float,float);
