#include "objects.h"
extern struct Actor *dat_0c2f8350[];
extern void func_0c0431ec(struct Actor *);
extern void func_0c043150(struct Actor *);

unsigned char func_0c0383a4(void)
{
    struct Actor *a = dat_0c2f8350[0];
    register struct Actor *b = dat_0c2f8350[3];
    unsigned char flags = a->b248 | b->b248;
    if (flags & (1 << a->b2))
        func_0c0431ec(a);
    if (flags & (1 << b->b2))
        func_0c0431ec(b);
    {
        register unsigned char current = a->b248 | b->b248;
        if (flags != current) {
            if (flags & (1 << a->b2))
                func_0c043150(a);
            if (flags & (1 << b->b2))
                func_0c043150(b);
        }
    }
    return flags;
}
