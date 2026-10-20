#ifndef MVC2_SONY29_RPC_SERVER_TYPES_H
#define MVC2_SONY29_RPC_SERVER_TYPES_H
#include "sony29_rpc_packet_header.h"
/* Native Server68 and Queue24 layouts, also corroborated by sifrpc-common.h
 * at public PS2SDK revision 329e2bb43287e16af16c4dde1c614e2662c24468. */
typedef void *(*SonyRpcFunction)(int,void *,int);
typedef struct SonyRpcServer SonyRpcServer;
typedef struct SonyRpcQueue SonyRpcQueue;
struct SonyRpcServer {
 int sid;SonyRpcFunction function;void *buffer;int size;
 SonyRpcFunction callback;void *callback_buffer;int size2;
 SonyRpcClient *client;void *packet;int number;
 void *receive_buffer;int receive_size,receive_mode,rpc_id;
 SonyRpcServer *link,*next;SonyRpcQueue *queue;
};
struct SonyRpcQueue {int thread,active;SonyRpcServer *servers,*first,*last;SonyRpcQueue *next;};
void func_00107098(SonyRpcQueue *,int);
void func_00107130(SonyRpcServer *,int,SonyRpcFunction,void *,SonyRpcFunction,void *,SonyRpcQueue *);
SonyRpcServer *func_00107200(SonyRpcServer *,SonyRpcQueue *);
SonyRpcQueue *func_00107298(SonyRpcQueue *);
void func_00107548(SonyRpcQueue *);
#endif
