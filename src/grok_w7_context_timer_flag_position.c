typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00183920(u8 *, f32 *);
extern void func_003B38F0(u8 *, int, int);

void func_00303FF0(u8 *p, void *context)
{
    s16 timer;

    func_00175700(p);
    timer = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = timer - 1;
    if (timer == 0) {
        p[6]++;
        func_001757E0(p, 21, 13);
        return;
    }
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        *(s8 *)(p + 0x151) &= (s8)~1;
        func_003B38F0(p, 1, 8);
    }
    if ((*(s8 *)(p + 0x151) & 2) != 0) {
        struct {
            union { f32 values[2]; u32 bits[2]; } position;
            u32 padding[2];
        } position __attribute__((aligned(16)));

        *(s8 *)(p + 0x151) &= (s8)~2;
        position.position.bits[0] = 0;
        position.position.bits[1] = 0x42FCDB6D;
        func_00183920(p, position.position.values);
    }
}
