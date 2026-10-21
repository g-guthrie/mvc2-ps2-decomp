typedef unsigned int u32;
void func_00104630(void *first,void *last)
{
    int index;
    u32 tag;
    for(index=0;index<0x1000;index+=64) {
        __asm__ volatile("sync\ncache 0x10,0(%1)\nsync\nmfc0 %0,$28" : "=r"(tag) : "r"(index) : "memory");
        tag=(tag&0xfffff000u)+(u32)index;
        if(tag>=(u32)first && tag<=(u32)last)
            __asm__ volatile("sync\ncache 0x14,0(%0)\nsync" : : "r"(index) : "memory");
        __asm__ volatile("sync\ncache 0x10,1(%1)\nsync\nmfc0 %0,$28" : "=r"(tag) : "r"(index) : "memory");
        tag=(tag&0xfffff000u)+(u32)index;
        if(tag>=(u32)first && tag<=(u32)last)
            __asm__ volatile("sync\ncache 0x14,1(%0)\nsync" : : "r"(index) : "memory");
        __asm__ volatile("sync" : : : "memory");
    }
}

void func_00104770(void *first,void *last)
{
    int index;
    u32 tag;
    for(index=0;index<0x1000;index+=64) {
        __asm__ volatile("sync\ncache 0x10,0(%1)\nsync\nmfc0 %0,$28" : "=r"(tag) : "r"(index) : "memory");
        tag=(tag&0xfffff000u)+(u32)index;
        if(tag>=(u32)first && tag<=(u32)last)
            __asm__ volatile("sync\ncache 0x16,0(%0)\nsync" : : "r"(index) : "memory");
        __asm__ volatile("sync\ncache 0x10,1(%1)\nsync\nmfc0 %0,$28" : "=r"(tag) : "r"(index) : "memory");
        tag=(tag&0xfffff000u)+(u32)index;
        if(tag>=(u32)first && tag<=(u32)last)
            __asm__ volatile("sync\ncache 0x16,1(%0)\nsync" : : "r"(index) : "memory");
        __asm__ volatile("sync" : : : "memory");
    }
}
