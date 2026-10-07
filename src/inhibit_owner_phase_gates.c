typedef unsigned char u8;
typedef void (*Callback)(u8 *,u8 *);
extern u8 D_004D18A6;
extern Callback D_0044B6A0[], D_0044CAB0[], D_00449410[];
void func_001A9870(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (!(D_004D18A6 & (1 << (owner[2]^1)))) {
  if (!(D_004D18A6 && owner[0x1e4]==29 && owner[0x1fd]==6)) D_0044B6A0[p[6]](p,owner);
 }
}

void func_001C1F60(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (!(D_004D18A6 & (1 << (owner[2]^1)))) {
  if (!(D_004D18A6 && owner[0x1e4]==29 && owner[0x1fd]==8)) D_0044CAB0[p[6]](p,owner);
 }
}
void func_00194000(u8 *p,u8 *owner) {
 if (owner[5] || (owner[0x1e4]!=29 && !D_004D18A6)) { ++p[4];p[0x13c]=0; }
 else D_00449410[p[5]](p,owner);
}
