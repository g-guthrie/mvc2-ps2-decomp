/* Provisional: state-table ABI, selector bounds and owner lifetime remain unresolved. */
typedef unsigned char u8;
typedef struct { u8 pad0[0x34]; float x,y,z; u8 pad40[0x1c]; float vx,vy; u8 pad64[4]; float ax,ay; u8 pad70[0x430-0x70]; float ground; } Motion;
extern int func_00175700(u8 *);
void func_0017E0D0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x1dc);
 unsigned int kind=owner[1];
 Motion *m=(Motion *)p;
 if (kind == 44 || kind == 49) return;
 if (kind == 54 || kind == 16) func_00175700(p);
 p[0x209]=0;
 if (p[0x20d] == 2) {
  m->x+=m->vx; m->vx+=m->ax; m->y+=m->vy; m->vy+=m->ay;
  if(m->y <= m->ground) { m->y=m->ground; p[0x20d]=0; }
 }
}
