/* Advance the effect after crossing its owner-selected target. */
typedef unsigned char u8;
typedef signed short s16;
extern const u8 D_00463631[][2];
extern int func_00175700(u8 *),func_00174470(const void *),func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
void func_003639B0(u8 *p,u8 *owner)
{
 u8 *work=owner+0x2B8;
 u8 *target=*(u8**)work;
 func_00175700(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 if(work[4]&&target[3]==4&&*(unsigned short*)(target+0x26)==0x1003) {
  if((*(s16*)(p+0x140)==0&&*(float*)(p+0x34)<=*(float*)(target+0x34))||(*(s16*)(p+0x140)!=0&&!(*(float*)(p+0x34)<*(float*)(target+0x34)))) {
   p[5]++;(*(s16*)(target+0x1E))++;func_001757E0(p,23,D_00463631[p[0x20]][0]);
  }
 } else if(func_00174470(p)) {p[5]++;func_001757E0(p,23,D_00463631[p[0x20]][0]);}
 func_001E7F60(p);
}
