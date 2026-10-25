#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;typedef struct {u32 words[49];} State;
extern void func_001BE640(u8*);
extern void func_001C4010(u8*);
void func_001BE590(u8*p){
 u8*owner;
 p[4]++;*(u16*)(p+0x26)=0x1802;owner=*(u8**)(p+0x18);
 *(State*)(p+0xec)=*(State*)(owner+0xec);
 p[0x13c]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];*(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);*(s8*)(p+0x24)=*(s8*)(owner+0x24);

 p[0x13c]=0;func_001BE640(p);
}

void func_001C3F40(u8*p){
 u8*owner;
 p[4]++;*(u16*)(p+0x26)=0x1C04;owner=*(u8**)(p+0x18);
 *(State*)(p+0xec)=*(State*)(owner+0xec);
 p[0x13c]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];*(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);*(s8*)(p+0x24)=*(s8*)(owner+0x24);

 p[0x14c]=24;p[0x14d]=24;p[0x14e]=16;p[0x14f]=16;p[0x24]=0;func_001C4010(p);
}
