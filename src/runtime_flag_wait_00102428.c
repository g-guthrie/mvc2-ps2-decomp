typedef unsigned int u32;
typedef signed int s32;
extern char D_004AAEC0[];
extern void func_00105E80(void *context, ...);
extern s32 func_00102BC0(volatile s32 *state);
void func_00102428(void *context) {
    volatile u32 *state = (volatile u32 *)context;
    s32 remaining = 0x1000000;
    while ((*state & 0x100u) != 0) {
        if (--remaining < 0) {
            func_00105E80(D_004AAEC0);
            func_00102BC0((volatile s32 *)state);
        }
    }
}
