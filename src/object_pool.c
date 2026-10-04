/* Fixed 0x1e4-byte objects: allocate from the free list and unlink by kind. */
typedef unsigned char u8;
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
extern void (*D_00477850[])(void *,Object *,int);
extern void func_0011D8F8(void *,int,int);
Object *func_003DA780(void *owner,int kind,int initialize);
Object *func_003DA780(void *owner,int kind,int initialize) {
 Object *object;
 if (D_004C27A0 == 0) return 0;
 object=D_004C27AC;
 D_004C27AC=object->previous;
 --D_004C27A4;
 if (--D_004C27A0 == 0) D_004C27A8=0;
 ++D_004D3460[(u8)kind];
 func_0011D8F8(object,0,sizeof(Object));
 object->kind=kind;
 D_00477850[(u8)initialize](owner,object,kind);
 return object;
}
extern Object *D_004D3690[];
extern Object *D_004D3520[];
void func_003DAA40(Object *object) {
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

/* Insert at either end of a kind list, or next to an existing object. */
void func_003DA860(void *unused,Object *object,int kind) {
 u8 k=(u8)kind;
 if (D_004D3690[k] == 0 && D_004D3520[k] == 0) {
  D_004D3520[k]=object;
  D_004D3690[k]=object;
 } else {
  object->previous=0;
  object->next=D_004D3690[k];
  D_004D3690[k]->previous=object;
  D_004D3690[k]=object;
 }
}
void func_003DA8C0(void *unused,Object *object,int kind) {
 u8 k=(u8)kind;
 if (D_004D3690[k] == 0 && D_004D3520[k] == 0) {
  D_004D3520[k]=object;
  D_004D3690[k]=object;
 } else {
  object->next=0;
  object->previous=D_004D3520[k];
  D_004D3520[k]->next=object;
  D_004D3520[k]=object;
 }
}
void func_003DA930(Object *at,Object *object,int kind) {
 Object *previous=at->previous;
 if (previous == 0) {
  object->previous=0;
  object->next=at;
  at->previous=object;
  D_004D3690[(u8)kind]=object;
 } else {
  object->previous=previous;
  object->next=at;
  at->previous->next=object;
  at->previous=object;
 }
}
void func_003DA980(Object *at,Object *object,int kind) {
 if (at->next == 0) {
  object->next=0;
  object->previous=at;
  at->next=object;
  D_004D3520[(u8)kind]=object;
 } else {
  object->previous=at;
  object->next=at->next;
  at->next->previous=object;
  at->next=object;
 }
}
