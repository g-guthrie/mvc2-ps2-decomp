typedef unsigned int u32;
typedef signed int s32;

extern u32 D_006327B0[];
extern s32 D_004C2B40;
extern void func_003DD260(u32 *matrix);

void func_004171E0(void)
{
    func_003DD260(D_006327B0 + (D_004C2B40 << 4));
}
