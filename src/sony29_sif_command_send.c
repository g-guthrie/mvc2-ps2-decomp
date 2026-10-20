/* Public command send adapters select the native backend mode. */
typedef unsigned int u32;
extern u32 func_00106298(u32,int,void *,int,void *,void *,int);
u32 func_001063D0(u32 command,void *packet,int packet_size,void *source,void *destination,int size)
{
    return func_00106298(command,0,packet,packet_size,source,destination,size);
}
u32 func_00106410(u32 command,void *packet,int packet_size,void *source,void *destination,int size)
{
    return func_00106298(command,1,packet,packet_size,source,destination,size);
}
