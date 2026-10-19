/* Metrowerks 3.0: ./try.sh src/grok_nopi_371370.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern void func_001E3710(u8 *, int);
extern void func_0015B200(u8 *, f32 *, int, int);
extern void func_001E7F60(u8 *);

void func_00371370(u8 *p)
{
    s16 t;

    if (*(s8 *)(p + 0x1B2) != 0) {
        p[5]++;
        *(s16 *)(p + 28) = 2;
        func_001E3710(p, 73);
        *(f32 *)(p + 56) += 102.85713958740234f;
        func_0015B200(p, (f32 *)(p + 52), 1, 201);
        return;
    }
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = (s16)(t - 1);
    if (t == 0) {
        p[5]++;
        *(s16 *)(p + 28) = 2;
        func_001E3710(p, 73);
        *(f32 *)(p + 56) += 68.57142639160156f;
        func_0015B200(p, (f32 *)(p + 52), 1, 201);
        return;
    }
    func_001E7F60(p);
}
