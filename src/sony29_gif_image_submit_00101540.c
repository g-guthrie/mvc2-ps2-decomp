typedef unsigned int u32;
typedef unsigned long long u64;
extern char gPs2SystemText_004AACB0[];
extern void func_00105E80(void *context,...);
#define GIF_CHCR (*(volatile u32 *)0x1000a000u)
#define GIF_MADR (*(volatile u32 *)0x1000a010u)
#define GIF_QWC (*(volatile u32 *)0x1000a020u)
int func_00101540(void *setup,void *data)
{
    u32 timeout=0,setup_address=(u32)setup,data_address=(u32)data;
    u64 image_tag;
    while(GIF_CHCR&0x100u) {
        if(timeout++>0x1000000u) {
            func_00105E80(gPs2SystemText_004AACB0);
            return -1;
        }
    }
    GIF_QWC=6;
    if((setup_address&0x70000000u)==0x70000000u)
        GIF_MADR=(setup_address&0x0fffffffu)|0x80000000u;
    else GIF_MADR=setup_address&0x0fffffffu;
    GIF_CHCR=0x101;
    while(GIF_CHCR&0x100u) {
        if(timeout++>0x1000000u) {
            func_00105E80(gPs2SystemText_004AACB0);
            return -1;
        }
    }
    {
      const u64 *aligned_tag=(const u64 *)((const unsigned char *)setup+0x50);
      __builtin_memcpy(&image_tag,aligned_tag,sizeof(image_tag));
    }
    GIF_QWC=(int)(image_tag&0x7fffu);
    if((data_address&0x70000000u)==0x70000000u)
        GIF_MADR=(data_address&0x0fffffffu)|0x80000000u;
    else GIF_MADR=data_address&0x0fffffffu;
    GIF_CHCR=0x101;
    return 0;
}
