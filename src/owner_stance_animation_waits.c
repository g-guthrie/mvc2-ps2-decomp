/* Follow the owner position, then wait for stance or animation completion. */
typedef unsigned char u8;
extern void func_001754A0(u8 *,int,int);
extern signed char func_00175670(u8 *);
extern void func_001B81D0(u8 *);
void func_001B8090(u8 *p) {
 *(float *)(p+0x34)=*(float *)(*(u8 **)(p+0x18)+0x34);
 *(float *)(p+0x38)=*(float *)(*(u8 **)(p+0x18)+0x38);
 func_001754A0(p,0x1b,1);
 for (;;) {
  if (*(signed char *)(*(u8 **)(p+0x18)+0x161)==*(signed char *)(p+0x150)) { p[0x13c]=1; break; }
  if (func_00175670(p)<0) { func_001B81D0(p); break; }
 }
}

extern void func_001757E0(u8 *,int,int);
extern signed char func_00175700(u8 *);
extern void func_003793F0(u8 *);
void func_00379190(u8 *p) {
 *(float *)(p+0x34)=*(float *)(*(u8 **)(p+0x18)+0x34);
 *(float *)(p+0x38)=*(float *)(*(u8 **)(p+0x18)+0x38);
 func_001757E0(p,0x15,5);
 for (;;) {
  if (*(signed char *)(*(u8 **)(p+0x18)+0x161)==*(signed char *)(p+0x161)) { p[0x13c]=1; break; }
  if (func_00175700(p)<0) { func_003793F0(p); break; }
 }
}
void func_00379220(u8 *p) {
 *(float *)(p+0x34)=*(float *)(*(u8 **)(p+0x18)+0x34);
 *(float *)(p+0x38)=*(float *)(*(u8 **)(p+0x18)+0x38);
 func_001757E0(p,0x15,6);
 for (;;) {
  if (*(signed char *)(*(u8 **)(p+0x18)+0x161)==*(signed char *)(p+0x161)) { p[0x13c]=1; break; }
  if (func_00175700(p)<0) { func_003793F0(p); break; }
 }
}
