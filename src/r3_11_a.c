typedef signed short s16; typedef signed int s32; typedef float f32; typedef struct { s16 x, y; f32 pad; f32 a; } Ang;
extern double func_001173A0(double, double);
void func_003DB7F0(Ang *p){ double d; f32 a; if ((p->y | p->x) == 0) { a = 0.0f; } else { d = func_001173A0(-p->y, p->x); a = d; if (a < 0.0f) a += 6.2831854820251465f; } p->a = a; }
