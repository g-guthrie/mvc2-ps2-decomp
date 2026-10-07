/* Clamp the shared counter and complete the selected table-driven state. */
extern int D_004D17B8;
void func_00131340(int delta) {
 D_004D17B8+=delta;
 if (D_004D17B8<0) D_004D17B8=0;
 if (D_004D17B8>9999) D_004D17B8=9999;
}

typedef unsigned char u8;
extern u8 D_00583BC4[];
void func_001395D0(u8 *p) {
 int count=D_00583BC4[p[0x20]];
 if (count) {
  if ((u8)count-1==p[0x21]) {
   ++p[4];
   if (!p[0x20]) *(int *)(p+0x44)=0x8000;
  }
 }
}
