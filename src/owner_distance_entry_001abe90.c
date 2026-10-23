/* Choose motion toward the owner and forward the actual owner argument. */
typedef unsigned char u8;
typedef signed short s16;
extern float func_001AC390(u8 *,int);
extern void func_001ABF50(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_001ABE90(u8 *p,u8 *owner)
{
 p[7]++;
 if(!(*(float*)(p+0x34)-func_001AC390(owner,56)<0.0f)) {
  *(s16*)(p+0x140)=0;*(float*)(p+0x5C)=-7.916666507720947265625f;
 } else {
  *(s16*)(p+0x140)=1;*(float*)(p+0x5C)=7.916666507720947265625f;
 }
 *(float*)(p+0x68)=0;
 if(p[6]!=*(int*)(p+0xD0))func_001757E0(p,23,13);
 func_001ABF50(p,owner);
}
