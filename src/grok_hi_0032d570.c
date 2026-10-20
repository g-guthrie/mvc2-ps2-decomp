/* ./try.sh src/grok_hi_0032d570.c "-O4,p -sdatathreshold 8" */
typedef signed int s32;
typedef float f32;

typedef struct {
    s32 i0;
    s32 i1;
    char p0[4];
    f32 f12;
    char p1[12];
    f32 f28;
    f32 f32;
} MixDiv;

extern void func_0032D350(MixDiv *);

void func_0032D570(f32 *p, s32 n)
{
    MixDiv s;
    s32 t;

    s.i0 = n;
    n = s.i0;
    t = n * (n - 1);
    t = t / 2;
    s.i1 = n + t;
    s.f12 = 0;
    s.f32 = p[0x6C / 4];
    if (s.i0 != 0)
        func_0032D350(&s);
    else
        s.f28 = 0;
    p[0x60 / 4] = s.f28;
}
