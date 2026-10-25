#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern int func_00175700(u8*);
extern void func_0039E450(u8*);
struct Object;
void func_0039C8B0(struct Object *actor)
{
 u8 *p=(u8*)actor;u8 *owner=*(u8**)(p+0x18);u32 frame;
 *(float*)(p+0x34)=*(float*)(owner+0x34);*(float*)(p+0x38)=*(float*)(owner+0x38);p[0x24]=*(s8*)(owner+0x24);
 for(;;){
  if(!(frame=(s8)(*(s8*)(owner+0x161)&-2))){p[0x13C]=0;return;}
  if((s8)frame<0){func_0039E450(p);return;}
  if(*(s8*)(p+0x161)==(s8)frame)break;
  func_00175700(p);
 }
 p[0x13C]=1;
}
