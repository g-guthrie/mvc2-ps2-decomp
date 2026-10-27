typedef unsigned char u8;
typedef float f32;

extern void func_001551A0(f32 *, unsigned int, f32, int);

/* Provisional: the kind domain and initialization path need proof. */
void func_001550D0(f32 *a0, int kind, int a2, int a3)
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
        func_001551A0(a0, (unsigned int)a2, f, a3);
}
