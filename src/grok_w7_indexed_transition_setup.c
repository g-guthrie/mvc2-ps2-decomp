typedef unsigned char u8;
typedef unsigned short u16;
/* Native code addresses this byte table through gp; its full bound is unresolved. */
typedef float f32;
typedef struct { f32 x; f32 y; f32 z; } Vec3;
extern u8 D_004C1324[] __attribute__((section(".sdata")));
extern u8 D_004C1328[] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_002F50D0(u8 *, void *);
extern void func_002F5170(u8 *, void *);
void func_002F5070(u8 *p, void *q)
{
    p[6]++;
    func_001757E0(p, 21, D_004C1324[*(u16 *)q]);
    func_002F50D0(p, q);
}

void func_002F50D0(u8 *p, void *source)
{
    p[0x209] = 2;
    if (*(u16 *)((u8 *)source + 2) == 0) {
        func_00175700(p);
        return;
    }

    p[6]++;
    func_001757E0(p, 21, D_004C1328[*(u16 *)source]);
    *(Vec3 *)(p + 0x34) = *(Vec3 *)((u8 *)source + 4);
    func_002F5170(p, source);
}
