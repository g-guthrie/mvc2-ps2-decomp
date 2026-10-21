/* Preserve retail links through the first child in the five-child loop. */
typedef unsigned char u8;
typedef signed short s16;
extern u8 *func_003DA750(u8 *, int, int);
extern void func_003B4240(u8 *);
void func_003B4120(u8 *p)
{
    u8 *first, *next;
    s16 value = 5;
    int i;
    if ((first = func_003DA750(p, 1, 2)) != 0) {
        *(void (**)(u8 *))(first + 0x10) = func_003B4240;
        *(void **)(first + 0x18) = *(void **)(p + 0x18);
        *(u8 **)(first + 0x14) = p;
        first[0x22] = p[0x22];
        first[0x23] = 0;
        first[0x20] = 1;
        *(s16 *)(first + 0x26) = 0x3400;
        *(s16 *)(first + 0x1e) = value--;
        *(u8 **)(first + 0x88) = p;
        *(u8 **)(first + 0x8c) = first;
        *(u8 **)(p + 0x8c) = first;
    }
    i = 0;
    do {
        next = func_003DA750(p,1,2);
        if (next) {
            *(void (**)(u8 *))(next + 0x10) = func_003B4240;
            *(void **)(next + 0x18) = *(void **)(p + 0x18);
            *(u8 **)(next + 0x14) = p;
            next[0x22] = p[0x22];
            next[0x23] = 1;
            next[0x20] = 1;
            *(s16 *)(next + 0x26) = 0x3400;
            *(s16 *)(next + 0x1e) = value--;
            *(u8 **)(first + 0x88) = p;
            *(u8 **)(first + 0x8c) = *(u8 **)(p + 0x8c);
        }
        i++;
    } while(i<5);
}
