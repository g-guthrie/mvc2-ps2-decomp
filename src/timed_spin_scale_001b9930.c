typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern float D_004F1F4C,D_004F1FE8;
extern u8 D_004F1F45,D_004F1F46;
extern int func_001754A0(u8*,int,int);
extern void func_001E3210(u8*,int);
void func_001B9930(u8 *p) {
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(u32*)(p+0x48)+=192;*(float*)(p+0x50)+=0.032f;
 *(float*)(p+0x54)+=(0.16f * *(s16*)(p+0x1C))*(0.16f * *(s16*)(p+0x1C));
 ++*(s16*)(p+0x1C);
 if(*(s16*)(p+0x1C)>16) {
  ++p[5];*(float*)(p+0x50)=1.5f;*(float*)(p+0x54)=1.5f;*(u32*)(p+0x48)=0;
  *(float*)(p+0x34)=*(s16*)(p+0x140)?600.0f+D_004F1F4C:D_004F1F4C-600.0f;
  *(float*)(p+0x38)=360.0f+D_004F1FE8;
  func_001754A0(p,27,17);func_001E3210(p,45);D_004F1F45=3;D_004F1F46=1;
 }
}
