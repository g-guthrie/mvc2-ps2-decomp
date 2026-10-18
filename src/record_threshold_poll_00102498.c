typedef unsigned int u32;
typedef unsigned char u8;
extern u32 D_004AAEC0[];
extern int func_00102BC0(void *p);
extern void func_00105E80(void *context, ...);
struct WaitRecord { u8 pad[0x10]; volatile u32 value; };

void func_00102498(struct WaitRecord *p, u32 limit, int timeout)
{
    int timer = 0x01000000;

    if (timeout)
        timer = timeout;
    if (p->value < limit) {
        do {
            timer--;
            if (timer < 0) {
                func_00105E80(D_004AAEC0);
                func_00102BC0(p);
            }
        } while (p->value < limit);
    }
}
