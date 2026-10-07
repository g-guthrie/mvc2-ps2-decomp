/* Keep an owner-linked effect active only for its matching side, mode, and phase. */
typedef unsigned char u8;
extern void func_00328DE0(u8 *,u8 *),func_00328E00(u8 *,u8 *);
void func_00328D30(u8 *p,u8 *owner) {
 if (owner[0] && (owner[0x23e]==2 || owner[0x23e]==0) && p[1]==owner[1] && --*(short *)(p+0x1c) && (owner[5]==3 || owner[5]==2))
  func_00328DE0(p,owner);
 else func_00328E00(p,owner);
}
extern void func_00329030(u8 *,u8 *),func_00329050(u8 *,u8 *);
void func_00328F80(u8 *p,u8 *owner) {
 if (owner[0] && (owner[0x23e]==3 || owner[0x23e]==0) && p[1]==owner[1] && --*(short *)(p+0x1c) && (owner[5]==3 || owner[5]==2))
  func_00329030(p,owner);
 else func_00329050(p,owner);
}
extern void func_00329680(u8 *,u8 *),func_003296A0(u8 *,u8 *);
void func_003295D0(u8 *p,u8 *owner) {
 if (owner[0] && (owner[0x23e]==4 || owner[0x23e]==0) && p[1]==owner[1] && --*(short *)(p+0x1c) && (owner[5]==3 || owner[5]==2))
  func_00329680(p,owner);
 else func_003296A0(p,owner);
}
