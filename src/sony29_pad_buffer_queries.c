/* Complete Sony pad double-buffer access and actuator/status queries. */
typedef unsigned char u8;
typedef struct { u8 *buffer; int reserved[3]; int enabled; int tail[2]; } BufferSlot;
extern BufferSlot D_004C83D0[][4];
extern void func_001046D8(void *,void *);
extern void *func_0011D740(void *,const void *,unsigned int);
extern int func_0010E1B0(int,int,int);
extern u8 *func_0010D860(int port,int slot);
int func_0010D8C0(int port,int slot)
{
 if(!D_004C83D0[port][slot].enabled)return 0;
 return *(int *)(func_0010D860(port,slot)+88);
}
int func_0010D910(int port,int slot,void *destination)
{
 u8 *buffer;
 if(!D_004C83D0[port][slot].enabled)return 0;
 buffer=func_0010D860(port,slot);
 func_0011D740(destination,buffer,*(unsigned int *)(buffer+96));
 return *(int *)(buffer+96);
}
int func_0010D990(int port,int slot)
{
 u8 *buffer;
 if(!D_004C83D0[port][slot].enabled)return 99;
 buffer=func_0010D860(port,slot);
 if(buffer[112]==6 && buffer[113]==2)return 5;
 return buffer[112];
}
int func_0010DAA8(int port,int slot)
{
 if(!D_004C83D0[port][slot].enabled)return 0;
 return func_0010D860(port,slot)[113];
}
int func_0010E0F8(int port,int slot)
{
 u8 *buffer;
 if(!D_004C83D0[port][slot].enabled)return 0;
 buffer=func_0010D860(port,slot);
 if(buffer[114]!=1)return 0;
 if(buffer[100]<2)return 0;
 if(buffer[102]<2)return 0;
 return (int)((unsigned long)buffer[121]+((unsigned long)buffer[122]<<8)
   +((unsigned long)buffer[123]<<16)+((unsigned long)buffer[124]<<24));
}
int func_0010E260(int port,int slot)
{
 if(!D_004C83D0[port][slot].enabled)return 0;
 return func_0010E0F8(port,slot)==0x3ffff;
}
int func_0010E2C0(int port,int slot)
{
 if(!D_004C83D0[port][slot].enabled)return 0;
 return func_0010E1B0(port,slot,4095);
}
