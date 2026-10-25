#pragma padloop on
typedef unsigned char u8;
typedef short s16;
extern u8 D_00476140[][16],D_00476141[][16],D_00476142[][16],D_00476143[][16],D_00476144[][16],D_00476146[][16];
extern float D_00476148[][4],D_0047614C[][4];
extern int func_001757E0(u8*,int,int);
extern void func_003C8BD0(u8*,void*);
void func_003C8A70(u8 *p,void *owner)
{
 float vx;
 ++p[6];p[0x1B0]=68;p[0x1B1]=68;
 p[0x14C]=D_00476140[p[0x20]][0];p[0x14D]=D_00476141[p[0x20]][0];
 p[0x14E]=D_00476142[p[0x20]][0];p[0x14F]=D_00476143[p[0x20]][0];
 if(D_00476144[p[0x20]][0])*(s16*)(p+0x140)^=1;
 *(float*)(p+0x60)=D_0047614C[p[0x20]][0];vx=D_00476148[p[0x20]][0];
 if(*(s16*)(p+0x140))vx=-vx;*(float*)(p+0x5C)=vx;
 func_001757E0(p,20,D_00476146[p[0x20]][0]);*(s16*)(p+0x1C)=32;func_003C8BD0(p,owner);
}
