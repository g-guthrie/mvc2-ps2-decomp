/* Advance a bounded frame table and apply its scale to all three axes. */
typedef unsigned char u8;
typedef struct ScaleKey { int frame; float value; } ScaleKey;
extern void func_003DAA40(u8 *);
extern float func_00154710(ScaleKey *, u8 *, short);
extern ScaleKey D_00444BB0[];
extern ScaleKey D_00444E70[];
extern ScaleKey D_004449B0[];
extern ScaleKey D_004449C0[];

void func_00156830(u8 *p) {
 if (*(short *)(p+0x1c) >= 4) {
  func_003DAA40(p);
 } else {
  *(float *)(p+0x78) = func_00154710(D_00444BB0,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x7c) = *(float *)(p+0x78);
  *(float *)(p+0x80) = *(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}

void func_00159A90(u8 *p) {
 if (*(short *)(p+0x1c) >= 6) {
  func_003DAA40(p);
 } else {
  *(float *)(p+0x78) = func_00154710(D_00444E70,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x7c) = *(float *)(p+0x78);
  *(float *)(p+0x80) = *(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}

/* Interpolate the current key pair; advance once its final frame is reached. */
float func_00154710(ScaleKey *keys, unsigned char *cursor, short frame) {
 unsigned int offset = *cursor * sizeof(ScaleKey);
 ScaleKey *key;
 float result;
 offset += (unsigned int)keys;
 key = (ScaleKey *)offset;
 result = key->value + (key[1].value - key->value) * (float)(frame - key->frame) / (float)(key[1].frame - key->frame);
 if (frame >= key[1].frame) ++*cursor;
 return result;
}

void func_00154BF0(u8 *p) {
 if (*(short *)(p+0x1c) > 3) {
  func_003DAA40(p);
 } else {
  *(float *)(p+0x78) = func_00154710(D_004449B0,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x7c) = *(float *)(p+0x78);
  *(float *)(p+0x80) = *(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}

void func_00154CF0(u8 *p) {
 if (*(short *)(p+0x1c) > 8) {
  func_003DAA40(p);
 } else {
  *(float *)(p+0x78) = func_00154710(D_004449C0,p+4,*(short *)(p+0x1c));
  *(float *)(p+0x7c) = *(float *)(p+0x78);
  *(float *)(p+0x80) = *(float *)(p+0x78);
  ++*(short *)(p+0x1c);
 }
}
