#pragma padloop on
typedef unsigned char u8;
typedef short s16;
extern void func_00370AB0(u8*);
void func_00370990(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);u8 *work=owner+0x2B8;
 if(owner[0x1E4]!=29||owner[0x1FD]!=5){
  p[5]=5;*(float*)(p+0x5C)=*(s16*)(p+0x140)?-15.833333015441895f:15.833333015441895f;
  *(float*)(p+0x68)=*(s16*)(p+0x140)?-0.3125f:0.3125f;
  *(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;*(s16*)(p+0x1C)=60;work[14]=0;
 }else{
  ++p[5];*(float*)(p+0x5C)=*(s16*)(p+0x140)?25.0f:-25.0f;
  *(float*)(p+0x68)=*(s16*)(p+0x140)?-0.3125f:0.3125f;
  *(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;*(s16*)(p+0x1C)=24;*(s16*)(work+16)=0;func_00370AB0(p);
 }
}
