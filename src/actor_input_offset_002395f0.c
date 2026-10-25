/* Select input-dependent facing and place the effect from one offset-table entry. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;u8 remainder[4];} Offset;
extern Offset D_00452160[];
extern void func_001266A0(u8 *,int,int),func_0018C6E0(u8 *),func_0015D010(u8 *,const float *);
extern int func_001757E0(u8 *,int,int);
void func_002395F0(u8 *p)
{
 float offset[3];
 u16 mask;
 const Offset *entry;
 func_001266A0(p,5,5);
 mask=p[0x20B]==0?0x800:0x400;
 if(*(u16*)(p+0x20E)&mask){*(short*)(p+0x140)^=1;p[0x1E6]^=1;}
 func_0018C6E0(p);
 entry=&D_00452160[p[0x20B]];
 offset[0]=1.6666666269302368f*entry->x;
 offset[1]=2.142857074737549f*entry->y;
 func_0015D010(p,offset);
 p[6]=0;p[7]=0;p[0x1B4]=10;
 func_001757E0(p,15,p[0x20B]);
}
