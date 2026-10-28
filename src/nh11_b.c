typedef unsigned char u8; typedef signed int s32; typedef unsigned int u32; typedef signed short s16; typedef unsigned short u16; typedef signed char s8;
extern s32 D_004C2804;
extern s32 D_004C27F8;
extern s32 D_004C27FC;
typedef struct Object {
 u8 header[3];
 u8 kind;
 int unused04;
 struct Object *previous;
 struct Object *next;
 u8 fields10[0x12c];
 signed char active;
 u8 fields13d[0xa7];
} Object;
extern short D_004C27A0;
extern short D_004C27A4;
extern Object *D_004C27A8;
extern Object *D_004C27AC;
extern short D_004D3460[];
extern Object *D_004D3690[];
extern Object *D_004D3520[];
static void func_003DAA40(Object *object) {
 Object *previous;
 Object *next;
 object->active=0;
 previous=object->previous;
 if (previous == 0) {
  next=object->next;
  D_004D3690[object->kind]=next;
  if (next == 0) D_004D3520[object->kind]=0;
  else next->previous=0;
 } else {
  next=object->next;
  if (next == 0) {
   D_004D3520[object->kind]=previous;
   previous->next=0;
  } else {
   previous->next=next;
   object->next->previous=object->previous;
  }
 }
 --D_004D3460[object->kind];
 if (D_004C27A8 != 0) D_004C27A8->previous=object;
 else D_004C27AC=object;
 object->previous=0;
 D_004C27A8=object;
 ++D_004C27A4;
 ++D_004C27A0;
}
void func_00146AE0(u8 *p, s32 g, s32 k, u8 m)
{
    extern void func_00146710(u8 *, s32, s32);
    extern void func_001467E0(u8 *, s32, s32, u8);
    s32 t;
    g = p[0x21];
    if (g < 4) g = D_004C2804;
    else if (g == 8) g = D_004C27F8;
    else if (g == 9) g = D_004C2804;
    else g = D_004C27FC;
    k = p[0x20] << 1;
    t = p[4];
    if (t == 0) { func_00146710(p, g, k); return; }
    m = t;
    if (m == 1) func_001467E0(p, g, k, m);
    else func_003DAA40((Object *)p);
}
