/* Allocate a child motion event, preserving allocation failure. */
typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *, int, int);
extern void func_0039E550(u8 *);
u8 *func_0039E4E0(u8 *owner, int mode) {
 u8 *event=func_003DA750(owner,1,2);
 if(event) {
  *(void (**)(u8 *))(event+16)=func_0039E550;
  *(u8 **)(event+24)=owner;
  event[32]=mode;
  *(s16 *)(event+38)=10241;
  event[1]=owner[1];
  event[33]=0;
  *(u8 **)(event+20)=owner;
  return event;
 }
 return 0;
}
