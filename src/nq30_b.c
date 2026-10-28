typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 b0; u8 pad[3]; s32 a4; s32 a8; s32 c; s32 d; } E47;
extern E47 D_004CBE80[];

void func_001E47E0(s32 a, s32 b)
{
    extern void func_00422FB0(s32);
    s32 i;
    s32 o;
    E47 *e;
    s32 *pa;
    s32 *pb;
    o = 0;
    i = 0;
    do {
        if ((a & 0xFF) == *(pa = &(e = (E47 *)((u8 *)D_004CBE80 + o))->a4) && (b & 0xFF) == *(pb = &e->a8)) {
            func_00422FB0((i & 0x7F) | (((e->a4 & 0x7F) << 16) | ((e->a8 & 0x7F) << 8)));
            e->b0 = 0;
            *pa = 0;
            *pb = 0;
            e->c = 0;
            e->d = 0;
        }
        i++;
        o += 0x14;
    } while (i <= 0x24);
}
