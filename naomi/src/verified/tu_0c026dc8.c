#include "objects.h"

struct GameState_026dc8 { unsigned char pad[72]; char show; };
extern struct GameState_026dc8 *dat_0c2d6f84;
extern unsigned char dat_0c22b398[];
extern unsigned char dat_0c22b39c[];
extern unsigned char dat_0c22b3a4[];
extern void func_0c02c32e(int, int, int, unsigned char *, ...);

void func_0c026dc8(int x, int score)
{
    int base;
    int pos;
    if (dat_0c2d6f84->show) {
        pos = 23;
        if (x)
            pos = 129;
        base = pos;
        if (score > 9)
            pos = pos - 3;
        if (score > 99)
            pos = pos - 3;
        func_0c02c32e(pos, 88, 20, dat_0c22b398, score);
        func_0c02c32e(base + 251, 96, 13, dat_0c22b39c, score);
        func_0c02c32e(base + 248, 102, 20, dat_0c22b3a4);
    }
}
