/* Face the owner-relative target and initialize horizontal movement. */
#pragma padloop on
typedef unsigned char u8;
extern float func_001C3A20(u8 *,int);
extern int func_001757E0(u8 *,int,int);
extern void func_001C2D30(u8 *,u8 *);
void func_001C2C70(u8 *p,u8 *owner)
{
 float distance;
 ++p[7];
 distance=*(float*)(p+0x34)-func_001C3A20(owner,48);
 if(distance>=0){*(short*)(p+0x140)=0;*(float*)(p+0x5C)=-7.0833330154418945f;}
 else {*(short*)(p+0x140)=1;*(float*)(p+0x5C)=7.0833330154418945f;}
 *(float*)(p+0x68)=0;
 if(p[6]!=p[0xD6])func_001757E0(p,25,5);
 func_001C2D30(p,owner);
}
