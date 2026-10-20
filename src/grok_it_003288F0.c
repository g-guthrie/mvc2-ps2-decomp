/* ./try.sh src/grok_it_003288F0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern void func_003DAA40(u8 *);

void func_003288F0(u8 *a0)
{
    u8 *q = *(u8 **)(a0 + 0x18);
    f32 x;

    if (q[0x1FD] != 1)
        goto call;
    if (q[0x1E4] != 21)
        goto call;
    if (q[0x169] != 21)
        goto call;
    if (q[0x168] == 20) {
        x = D_004F1FC8[0] + 40.0f;
        if (q[0x1E6])
            x = D_004F1FCC[0] + -40.0f;
        *(f32 *)(q + 0x34) = x;
    }
    return;
call:
    func_003DAA40(a0);
}
