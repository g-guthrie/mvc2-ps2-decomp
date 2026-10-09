typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef union { f32 value; u32 bits; } FloatBits;
typedef struct { u8 prefix[0x60]; FloatBits f60; u8 padding[8]; FloatBits f6c; } ActorView;

extern u8 D_004C1320[] __attribute__((section(".sdata")));
extern u8 D_004C1310[] __attribute__((section(".sdata")));
extern u32 data_u32_0045BC50[4];
extern int func_001757E0(u8 *, int, int);
extern void func_002F4FC0(u8 *, void *);
extern void func_001266A0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_002F4B20(u8 *, void *);

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

void func_002F4A50(u8 *p, void *q, int state)
{
    u8 value;
    s32 half;

    func_001266A0(p, 5, 5);
    value = ((u8 *)data_u32_0045BC50)[(*(u16 *)(p + 0x35e) & 0x3c00) >> 10];
    if (state != 0 && value >= 10)
        state = 0;
    p[0x20] = state;
    *(u16 *)q = value;
    half = value / 2;
    func_001757E0(p, 21, D_004C1310[half]);
    p[6] = 6;
    func_00175700(p);
    func_002F4B20(p, q);
}
