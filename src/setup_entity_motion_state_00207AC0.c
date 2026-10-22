typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern void func_001266A0(u8 *, s32, s32);
extern void func_0018C6E0(void *);
extern void func_0015D010(u8 *, f32 *);
extern s32 func_001757E0(u8 *, s32, s32);
void func_00207AC0(u8 *p) {
    f32 values[2] __attribute__((aligned(16)));
    if (p[0x269] != 8 && p[0x269] != 3)
        func_001266A0(p, 1, 1);
    func_0018C6E0(p);
    *(s16 *)(p + 0x1C) = 12;
    p[0x1FE] = 1;
    if (*(f32 *)(p + 0x64) > 0.0f)
        values[0] = -*(f32 *)(p + 0x64);
    else
        values[0] = *(f32 *)(p + 0x64);
    *(u32 *)&values[1] = 0x3F1C6DB7;
    func_0015D010(p, values);
    if (p[0x20D] == 2)
        goto state_two;
    if (p[0x269] == 8)
        goto state_eight;
    func_001757E0(p, 21, 11);
    goto done;
state_eight:
    func_001757E0(p, 21, 21);
    goto done;
state_two:
    func_001757E0(p, 21, 16);
done:;
}
