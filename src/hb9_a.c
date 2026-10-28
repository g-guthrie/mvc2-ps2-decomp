/* EE GCC 2.96 -O2 -G0 -fno-optimize-sibling-calls (./tryee.sh src/hb9_a.c sn 0 O2 -fno-optimize-sibling-calls). */
typedef signed int s32;
typedef unsigned int u32;

extern void *func_0011D8F8(void *, s32, u32); /* memset */
extern volatile s32 D_00487328;
extern char D_004872F0[];

void func_00407BC0(void) {
    (void)D_00487328;
    func_0011D8F8(D_004872F0, 0, 0x38);
}
