#include "objects.h"

struct Glob_02bb60 {
    unsigned char pad0;
    char b1;
    unsigned char pad1[0x80 - 2];
    char b128;
};

typedef void (*Handler_02bb60)(void);

extern struct Glob_02bb60 *dat_0c2d6f84;
extern Handler_02bb60 table_0c23aa20[];
extern void func_0c03522c(void);
extern void func_0c02bed8(void);
extern void func_0c021aa0(void);

void func_0c02bb60(void)
{
    func_0c03522c();
    dat_0c2d6f84->b128 += 1;
    func_0c02bed8();
    table_0c23aa20[dat_0c2d6f84->b1]();
    func_0c021aa0();
}
