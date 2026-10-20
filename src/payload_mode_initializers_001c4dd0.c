typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u32 words[49];} Payload;
extern s32 func_001754A0(u8*,u8,u8);
extern void func_001C4EC0(u8*);
extern void func_001C5030(u8*);
void func_001C4DD0(u8*p) {
u8*q;
p[4]++;
*(u16*)(p+0x26)=0x1c05;
q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;
p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);
*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);
*(s8*)(p+0x24)=*(s8*)(q+0x24);
*(s8*)(p+0x31)=-1;
p[0x24]=9;
func_001754A0(p,27,8);
func_001C4EC0(p);
}
void func_001C4F40(u8*p) {
u8*q;
p[4]++;
*(u16*)(p+0x26)=0x1c05;
q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;
p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);
*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);
*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x31]=1;
p[0x24]=9;
func_001754A0(p,27,9);
func_001C5030(p);
}
