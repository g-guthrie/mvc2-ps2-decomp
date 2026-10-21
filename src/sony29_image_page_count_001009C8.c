typedef unsigned int u32;
typedef unsigned long long u64;
extern void *func_00100468(void);
short func_001009C8(short format,short width,short height)
{
    u64 mode;
    int columns,rows;
    short pages;
    const u64 *state=(const u64 *)func_00100468();
    columns=(width+63)/64;
    if(format&2)rows=(height+63)/64;
    else rows=(height+31)/32;
    __builtin_memcpy(&mode,state,sizeof(mode));
    if((mode&0x0000ffff0000ffffULL)==1)pages=columns*rows;
    else pages=columns*rows*2;
    return (short)pages;
}
