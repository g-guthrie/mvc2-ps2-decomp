typedef unsigned char u8;
typedef signed char s8;
extern void func_00176090(u8 *, int, int, int);
extern void func_00176160(u8 *, int, int, int);
void func_0030CDE0(u8 *p)
{
    int mode;
    if (p[0x169] == 17) {
        mode = *(s8 *)(p + 0x150);
        if (mode == 0)
            goto zero_mode;
        p[0x150] = 0;
        mode = (mode == 1) ? 0 : 1;
        func_00176160(p, mode, 0, 1);
        goto mode_done;
zero_mode:
        func_00176090(p, 0, 0, 2);
mode_done:;
    }
    if (*(unsigned int *)(p + 0x2C0) != 0)
        (*(unsigned int *)(p + 0x2C0))--;
    if (*(unsigned int *)(p + 0x2CC) != 0)
        (*(unsigned int *)(p + 0x2CC))--;
    if (*(unsigned int *)(p + 0x2D4) != 0)
        (*(unsigned int *)(p + 0x2D4))--;
}
