/* Select retreat speed or transition to the owner-distance state. */
typedef unsigned char u8;
typedef signed short s16;
extern float func_001AC390(u8 *,int);
extern void func_001ABE90(u8 *,u8 *),func_001ABDF0(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_001ABCC0(u8 *p,u8 *owner)
{
 float distance;
 p[7]++;
 distance=*(float*)(p+0x34)-func_001AC390(owner,56);
 if(!(distance<0.0f))*(s16*)(p+0x140)=0;
 else {*(s16*)(p+0x140)=1;distance*=-1.0f;}
 if(!(distance<93.3333282470703125f)) {p[6]=4;p[7]=0;func_001ABE90(p,owner);return;}
 if(*(s16*)(owner+0x140)==*(s16*)(p+0x140))*(float*)(p+0x5C)=-6.666666507720947265625f;
 else *(float*)(p+0x5C)=-5.0f;
 *(float*)(p+0x68)=0;
 if(*(s16*)(p+0x140))*(float*)(p+0x5C)*=-1.0f;
 if(p[6]!=*(int*)(p+0xD0))func_001757E0(p,23,12);
 func_001ABDF0(p,owner);
}
