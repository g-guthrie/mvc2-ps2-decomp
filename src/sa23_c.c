typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_00632750[];
extern f32 D_00632760[];

void func_003DD260(void *);
void func_003DF850(s32, void *);
void func_003DE680(void *, void *);

void func_00417980(f32 *a, f32 *b, f32 *c, f32 x, f32 y, f32 z) {
    f32 m[16];
    func_003DD260(m);
    func_003DF850(0x19, m);
    D_00632750[0] = x;
    D_00632750[1] = y;
    D_00632750[2] = z;
    func_003DE680(D_00632760, D_00632750);
    *a = D_00632760[0];
    *b = D_00632760[1];
    *c = D_00632760[2];
}
