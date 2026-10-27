/* Draw the three resource-selected strips and the native option rectangle. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int Address;
typedef struct {float x,y;u8 opaque[8];} Vertex;
typedef struct {Vertex v[4];} Quad;
extern u8 D_004771D0[];
/* This native GP slot contains a 32-bit address. */
extern Address *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern s16 D_004F7F7C,D_004F7F7A;
extern float D_004F7FD0,D_004F7FD4;
extern void func_00417AE0(int,int *);
/* Provisional: player selector, resource extent, and nonzero count need proof. */
void func_003D3B40(void)
{
 u8 *graphics=D_004771D0;
 u8 *resource=*(u8**)((u8*)D_004C2794[(D_004F7F7C-1)*3+6]+0x1AC);
 s16 count=resource[0];
 int row=0;
 int index=D_004F7F7A;
 Quad *quad;
 for(;row<3;row++,index++) {
  index%=(s16)count;
  if(*(u16*)(resource+*(u16*)(resource+2+index*2))==0)quad=(Quad*)(graphics+0x100);
  else quad=(Quad*)(graphics+0x140);
  quad->v[0].x=quad->v[2].x=D_004F7FD0;
  quad->v[1].x=quad->v[3].x=640.0f+D_004F7FD0;
  quad->v[0].y=quad->v[1].y=32.0f*(float)row+D_004F7FD4;
  quad->v[2].y=quad->v[3].y=(32.0f+32.0f*(float)row)+D_004F7FD4;
  quad->v[0].y+=16.0f;quad->v[1].y+=16.0f;quad->v[2].y+=16.0f;quad->v[3].y+=16.0f;
  func_00417AE0(4,(int*)quad);
 }
 quad=(Quad*)(graphics+0x180);
 if(*(signed char*)(D_004C2840+0xB2)) {
  quad->v[0].x=quad->v[2].x=260.0f+D_004F7FD0;
  quad->v[1].x=quad->v[3].x=430.0f+D_004F7FD0;
 } else {
  quad->v[0].x=quad->v[2].x=430.0f+D_004F7FD0;
  quad->v[1].x=quad->v[3].x=640.0f+D_004F7FD0;
 }
 quad->v[0].y=quad->v[1].y=96.0f+D_004F7FD4;
 quad->v[2].y=quad->v[3].y=118.40000152587890625f+D_004F7FD4;
 quad->v[0].y+=16.0f;quad->v[1].y+=16.0f;quad->v[2].y+=16.0f;quad->v[3].y+=16.0f;
 func_00417AE0(4,(int*)quad);
}
