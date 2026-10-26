typedef unsigned char u8;
typedef signed char s8;
extern void (*const jtbl_00472460[3])(u8*,void*);
void func_00396200(u8 *p,void *owner_context) {
 u8 *owner=owner_context;
 p[0x24]=*(s8*)(owner+0x24)+*(s8*)(p+0x31);
 jtbl_00472460[p[5]](p,owner_context);
}
