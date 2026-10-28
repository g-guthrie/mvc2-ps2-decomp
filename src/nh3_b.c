typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern f32 D_004F1F4C[];
extern V3 D_00460CF0[];
extern f32 D_00460D20[];
void func_00343E80(f32 *a, f32 *b, int i) {
    V3 *t = (V3 *)((char *)D_00460CF0 + i * 12);
    f32 *k = (f32 *)(int)D_004F1F4C;
    *a = k[0] - (k[2] * (k[0] - t->x)) / (k[2] - t->z);
    *b = D_00460D20[i];
}
