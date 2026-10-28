/* Callback receives (owner, actor); forwards to func_00178F20(actor, owner),
 * whose real definition is in src/rr15_c.c. */
typedef unsigned char u8;
extern void func_00178F20(u8 *actor, u8 *owner);
void func_00239C60(u8 *owner, u8 *actor) { func_00178F20(actor, owner); }
