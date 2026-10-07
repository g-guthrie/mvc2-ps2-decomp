/* Interpolate uniform scale and motion vectors until the final frame. */
typedef unsigned char u8;
typedef struct { int frame; float value; } ScaleKey;
extern float func_00154710(ScaleKey *,u8 *,short);
extern void func_003DAA40(u8 *);
extern ScaleKey D_00445000[],D_00445010[];
void func_0015C940(u8 *p) {
 if (*(short *)(p+0x1c)>6) func_003DAA40(p);
 else {
  *(float *)(p+0x50)=func_00154710(D_00445000,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x54)=*(float *)(p+0x50);
  *(float *)(p+0x58)=*(float *)(p+0x50);
  *(float *)(p+0x78)=func_00154710(D_00445010,p+5,*(short *)(p+0x1c));
  *(float *)(p+0x7c)=*(float *)(p+0x78);
  *(float *)(p+0x80)=*(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}
extern ScaleKey D_00445020[],D_00445030[];
void func_0015CA60(u8 *p) {
 if (*(short *)(p+0x1c)>4) func_003DAA40(p);
 else {
  *(float *)(p+0x50)=func_00154710(D_00445020,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x54)=*(float *)(p+0x50);
  *(float *)(p+0x58)=*(float *)(p+0x50);
  *(float *)(p+0x78)=func_00154710(D_00445030,p+5,*(short *)(p+0x1c));
  *(float *)(p+0x7c)=*(float *)(p+0x78);
  *(float *)(p+0x80)=*(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}
extern ScaleKey D_00445050[],D_00445060[];
void func_0015CB80(u8 *p) {
 if (*(short *)(p+0x1c)>4) func_003DAA40(p);
 else {
  *(float *)(p+0x50)=func_00154710(D_00445050,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x54)=*(float *)(p+0x50);
  *(float *)(p+0x58)=*(float *)(p+0x50);
  *(float *)(p+0x78)=func_00154710(D_00445060,p+5,*(short *)(p+0x1c));
  *(float *)(p+0x7c)=*(float *)(p+0x78);
  *(float *)(p+0x80)=*(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}
extern ScaleKey D_00445080[],D_00445090[];
void func_0015CCA0(u8 *p) {
 if (*(short *)(p+0x1c)>6) func_003DAA40(p);
 else {
  *(float *)(p+0x50)=func_00154710(D_00445080,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x54)=*(float *)(p+0x50);
  *(float *)(p+0x58)=*(float *)(p+0x50);
  *(float *)(p+0x78)=func_00154710(D_00445090,p+5,*(short *)(p+0x1c));
  *(float *)(p+0x7c)=*(float *)(p+0x78);
  *(float *)(p+0x80)=*(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}
