typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004CD178[];
extern f32 D_004CD17C[];
extern u8 D_004CD181[];

void func_001E4480(u16 idx, u32 a)
{
    f32 z = 0.0f;
    f32 r = ((f32)(u32)D_004CD181[idx * 20] - D_004CD17C[idx * 5]) / (f32)a;
    r = r != z ? r : 1.0f;
    D_004CD178[idx * 5] = r;
}
