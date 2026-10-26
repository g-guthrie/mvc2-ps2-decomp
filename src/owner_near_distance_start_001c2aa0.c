/* Enter near-target motion or transfer immediately to the far-target state. */
typedef unsigned char u8;
typedef short s16;
extern float func_001C3A20(u8*,int);
extern void func_001C2C70(u8*,u8*);
extern void func_001C2BD0(u8*,u8*);
extern int func_001757E0(u8*,int,int);
void func_001C2AA0(u8*p,u8*owner){
 float distance;
 ++p[7];distance=*(float*)(p+0x34)-func_001C3A20(owner,48);
 if(!(distance<0.0f))*(s16*)(p+0x140)=0;
 else {*(s16*)(p+0x140)=1;distance*= -1.0f;}
 if(!(distance<93.33332824707031f)){p[6]=4;p[7]=0;func_001C2C70(p,owner);return;}
 if(*(s16*)(owner+0x140)==*(s16*)(p+0x140))*(float*)(p+0x5C)=-5.833333015441895f;
 else *(float*)(p+0x5C)=-5.0f;
 *(float*)(p+0x68)=0.0f;
 if(*(s16*)(p+0x140))*(float*)(p+0x5C)*=-1.0f;
 if(p[6]!=p[0xD6])func_001757E0(p,25,4);
 func_001C2BD0(p,owner);
}
