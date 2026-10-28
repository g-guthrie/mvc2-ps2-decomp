typedef unsigned char u8;
typedef float f32;

extern void func_001551A0(f32 *, unsigned int, f32, int);

/* Retail handles kind 0..3 only; any other kind leaves f (in $f20)
 * uninitialised, exactly as the binary does. */
void func_001550D0(f32 *pos, int kind, unsigned int n, int type)
{
    f32 f;
    int i;

    switch (kind) {
    case 0:
        f = 10.0f;
        break;
    case 1:
        f = 20.0f;
        break;
    case 2:
        f = 30.0f;
        break;
    case 3:
        f = 40.0f;
        break;
    }
    for (i = 0; i < 10; i++)
        func_001551A0(pos, n, f, type);
}
