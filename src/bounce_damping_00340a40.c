/* Clamp a moving object to its selected origin height and damp its reflected velocity. */
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern Vec3 D_0045FAA0[];
extern void func_0032E690(u8 *);
void func_00340A40(u8 *p) {
 Vec3 *origin=&D_0045FAA0[p[0x20]];
 func_0032E690(p);
 if(*(float*)(p+0x38)<origin->y) {
  *(float*)(p+0x38)=origin->y;
  *(float*)(p+0x60)*=-0.12f;
  *(float*)(p+0x5C)*=0.8f;
  *(float*)(p+0x64)*=0.8f;
 }
}
