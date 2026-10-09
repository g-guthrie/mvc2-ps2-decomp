typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_0018C4B0(u8 *, int);
extern void func_001E3210(u8 *, s32);

void func_002E6040(u8 *p, s8 *state)
{
    if (state[2] == 0) {
        if (p[0x425] != 0) {
            p[6]++;
            p[7] = 0;
        }
    }
    if (state[2] >= 0) {
        if (state[2] == 0x3F) {
            state[3] = 1;
            func_0018C4B0(p, 5);
            func_001E3210(p, 0x20);
        } else {
            return;
        }
    }
    p[6]++;
    p[7] = 0;
}
