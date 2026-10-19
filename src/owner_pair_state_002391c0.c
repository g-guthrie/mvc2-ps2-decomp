/* MWCCPS2 3.0.3: -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001A2610(u32, s32, u32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00238B70(u8 *, f32 *);

void func_002391C0(u8 *p, void *owner)
{
    p[6]++;
    p[7] = 0;
    p[34] = 28;
    p[518] = 12;
    p[519] = 22;
    ((u8 *)owner)[58] = 0;
    func_001A2610((u32)p, 8, 0);
    func_001757E0(p, 20, 0);
    func_00238B70(p, (f32 *)owner);
}
