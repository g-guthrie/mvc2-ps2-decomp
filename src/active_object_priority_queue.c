/* Shared object prefix used by the active priority queue, including larger pools. */
typedef unsigned char u8;
typedef struct Object {
 u8 header[3];
 u8 kind;
 int unused04;
 struct Object *previous;
 struct Object *next;
 u8 fields10[0x12c];
 signed char active;
} Object;

extern signed char D_004D1960[];
extern Object *D_004D1970[][96];
void func_003DAB30(Object *object) {
 int palette;
 signed char index;
 Object *previous;
 int slot,count;
 if(object->kind<5) {
 if(object->active) {
 palette=*((signed char *)object+0x24);
 if(D_004D1960[palette]<96) {
 D_004D1970[palette][D_004D1960[palette]++]=object;
 count=D_004D1960[palette];
 index=count-2;
 if(index<0)return;
 slot=(signed char)(count-1);
 do {
  previous=D_004D1970[palette][slot-1];
  if(*((signed char *)previous+0x31)>*((signed char *)object+0x31)) {
   D_004D1970[palette][slot-1]=object;
   D_004D1970[palette][slot]=previous;
  } else break;
  --slot;
 } while(--index>=0);
 }
 }
 }
}
