/* Complete native Sony pad port close RPC. */
typedef unsigned char u8;
typedef struct {u8 *buffer;int reserved[3];int enabled;int tail[2];} BufferSlot;
typedef struct {int command,port,slot,result,flags;} ClosePacket;
extern BufferSlot D_004C83D0[][4];
extern u8 D_004C85C0[],D_004C8380[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010D7A8(int port,int slot)
{
 ClosePacket *packet;
 if(!D_004C83D0[port][slot].enabled)return 0;
 packet=(ClosePacket *)D_004C85C0;
 packet->command=14;
 packet->port=port;
 packet->slot=slot;
 packet->flags=1;
 if(func_00106E68(D_004C8380,1,0,packet,128,packet,128,0,0)<0)return 0;
 D_004C83D0[port][slot].enabled=0;
 return packet->result;
}
