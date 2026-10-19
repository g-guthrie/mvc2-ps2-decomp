/* Metrowerks 3.0: ./try.sh src/grok_q5_41ab30.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

typedef struct {
    f32 x, y, z;
} Vec3;

extern void func_00175670(u8 *);
extern void func_00175580(u8 *, int, int, s8);

void func_0041AB30(u8 *p, u8 *src)
{
    *(Vec3 *)(p + 0x34) = *(Vec3 *)(src + 0x34);
    *(s8 *)(p + 0x24) = *(s8 *)(src + 0x24);
    func_00175670(p);
    if (*(s8 *)(p + 0x150) != *(s8 *)(src + 0x150))
        func_00175580(p, 0x1B, 0x2B, *(s8 *)(src + 0x150));
}
