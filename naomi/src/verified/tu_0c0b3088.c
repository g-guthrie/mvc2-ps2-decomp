/* Cleanup handler and four state-selection callbacks; labels before the tail call
 * reproduce retail scratch-register choice. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c045248(struct Actor *,unsigned char);
void func_0c0b3088(struct Actor *a)
{
 if (func_0c02a026(a)<0) {
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  func_0c0437b8(a);
 }
}
void func_0c0b30ba(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9) {
 case 0:a->b1e9=5;break;
 case 1:a->b1e9=5;break;
 case 2:a->b1e9=4;break;
 default:break;
 }
 goto f; f: func_0c045248(a,29);
}
void func_0c0b30ea(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9) {
 case 0:a->b1e9=5;break;
 case 1:a->b1e9=5;break;
 case 2:a->b1e9=4;break;
 default:break;
 }
 goto f; f: func_0c045248(a,29);
}
void func_0c0b311a(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9) {
 case 0: a->b1e9=0;goto selected;
 case 1: a->b1e9=1;goto selected;
 case 2: goto c2; c2: a->b1e9=2;
selected:
  a->b1a3=1;break;
 default:break;
 }
 goto f; f: func_0c045248(a,21);
}

void func_0c0b316c(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9) {
 case 0: a->b1e9=0;goto selected;
 case 1: a->b1e9=1;goto selected;
 case 2: goto c2; c2: a->b1e9=2;
selected:
  a->b1a3=1;break;
 default:break;
 }
 goto f; f: func_0c045248(a,21);
}
