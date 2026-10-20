/* Complete native SIF RPC server and queue removal operations. */
#include "sony29_rpc_server_types.h"
typedef SonyRpcServer RpcServer;
typedef SonyRpcQueue RpcQueue;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
RpcServer *func_00107200(RpcServer *server,RpcQueue *queue)
{
 RpcServer *current;
 func_0010CA20();
 current=queue->servers;
 if(current==server)queue->servers=current->link;
 else{
  while(current){
   if(current->link==server){current->link=server->link;break;}
   current=current->link;
  }
 }
 func_0010CA68();return current;
}

extern SonyRpcPacketPool D_004C5480;
RpcQueue *func_00107298(RpcQueue *queue)
{
 RpcQueue *current;
 func_0010CA20();
 current=D_004C5480.queues;
 if(current==queue)D_004C5480.queues=current->next;
 else{
  while(current){
   if(current->next==queue){current->next=queue->next;break;}
   current=current->next;
  }
 }
 func_0010CA68();return current;
}
