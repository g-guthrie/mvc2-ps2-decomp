/* Provisional: native callback ownership and selector bounds remain unresolved. */
typedef unsigned char u8;
extern void func_00178F20(u8 *, u8 *);
void func_002435F0(u8 *actor, u8 *owner) { func_00178F20(owner, actor); }
