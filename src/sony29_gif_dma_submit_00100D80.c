typedef unsigned int u32;
typedef unsigned long long u64;
extern char gPs2SystemText_004AA9C8[];
extern void func_00105E80(void *context,...);
#define GIF_CHCR (*(volatile u32 *)0x1000a000u)
#define GIF_MADR (*(volatile u32 *)0x1000a010u)
#define GIF_QWC (*(volatile u32 *)0x1000a020u)
int func_00100D80(void *packet)
{
    u32 timeout=0,address=(u32)packet;
    u64 tag;
    const u64 *aligned_packet=(const u64 *)packet;
    int count;
    while(GIF_CHCR&0x100u) {
        if(timeout++>0x1000000u) {
            func_00105E80(gPs2SystemText_004AA9C8);
            return -1;
        }
    }
    __builtin_memcpy(&tag,aligned_packet,sizeof(tag));
    count=(int)(tag&0x7fffu);
    GIF_QWC=count+1;
    if((address&0x70000000u)==0x70000000u)
        GIF_MADR=(address&0x0fffffffu)|0x80000000u;
    else GIF_MADR=address&0x0fffffffu;
    GIF_CHCR=0x101;
    return 0;
}
