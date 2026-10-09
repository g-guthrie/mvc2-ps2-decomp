typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef union { f32 value; u32 bits; } FloatBits;
typedef struct { u8 prefix[0x60]; FloatBits f60; u8 padding[8]; FloatBits f6c; } ActorView;

extern u8 D_004C1320[] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);
extern void func_002F4FC0(u8 *, void *);

void func_002F4F40(u8 *p, void *q)
{
    ActorView *actor = (ActorView *)p;

    p[6]++;
    func_001757E0(p, 21, D_004C1320[*(u16 *)q]);
    if (*(u16 *)q != 0) {
        actor->f60.bits = 0x3E092492;
        actor->f6c.bits = 0xBF4DB6DB;
    }
    func_002F4FC0(p, q);
}
