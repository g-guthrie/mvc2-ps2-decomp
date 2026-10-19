typedef unsigned short u16;

extern u16 func_0012ABC0(int, int);
extern void func_001E3CE0(int);

void func_0012A590(float *p)
{
    u16 bits = func_0012ABC0(3, 0);

    if (bits & 0x800) {
        p[4] -= 1.0f;
        if (p[4] < -10.0f)
            p[4] = -10.0f;
        else
            func_001E3CE0(4);
    } else if (bits & 0x400) {
        p[4] += 1.0f;
        if (p[4] > 10.0f)
            p[4] = 10.0f;
        else
            func_001E3CE0(4);
    }

    if (bits & 0x2000) {
        p[5] -= 1.0f;
        if (p[5] < -10.0f)
            p[5] = -10.0f;
        else
            func_001E3CE0(4);
    } else if (bits & 0x1000) {
        p[5] += 1.0f;
        if (p[5] > 10.0f)
            p[5] = 10.0f;
        else
            func_001E3CE0(4);
    }
}
