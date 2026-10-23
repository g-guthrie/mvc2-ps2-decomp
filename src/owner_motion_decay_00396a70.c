/* Decay motion on the actual owner-ground, contact, and timer conditions. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
void func_00396A70(u8 *p,void *owner_context)
{
 u8 *owner=owner_context;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);*(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if((p[0x20]==7&&!(*(float*)(owner+0x430)<=*(float*)(p+0x38)))||*(s8*)(p+0x1B2)||*(s8*)(p+0x1B3)||--*(s16*)(p+0x1C)==0) {
  p[5]++;
  *(float*)(p+0x5C)/=4.0f;*(float*)(p+0x68)/=4.0f;*(float*)(p+0x60)/=4.0f;*(float*)(p+0x6C)/=4.0f;
  if(p[0x20]==6)func_001757E0(p,23,29);else func_001757E0(p,23,31);
 }
 func_001E7F60(p);
}
