typedef unsigned char u8;
typedef float f32;

extern void func_001266A0(u8 *, int, int);
extern void func_0018C6E0(u8 *);
extern void func_0015D010(u8 *, f32 *);
extern int func_001757E0(u8 *, int, int);

void func_002A5D10(u8 *p)
{
    unsigned v[3];

    func_001266A0(p, 6, 6);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    v[0] = 0xC2A00000;
    v[1] = 0x43009249;
    v[2] = 0;
    func_0015D010(p, (f32 *)v);
    func_001757E0(p, 15, 0);
}
