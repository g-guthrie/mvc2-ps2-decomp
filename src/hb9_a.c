/* EE GCC 2.96 -O2 -G0 (./tryee.sh src/hb9_a.c sn 0 O2). */
typedef signed int s32;
typedef unsigned int u32;

extern void *func_0011D8F8(void *, s32, u32); /* memset */
extern volatile s32 D_00487328;
extern char D_004872F0[];

/* The do/while(0) statement wrapper (macro idiom) keeps this a jal rather
   than a sibling call with -foptimize-sibling-calls on. */
void func_00407BC0(void) {
    do {
        (void)D_00487328;
        func_0011D8F8(D_004872F0, 0, 0x38);
    } while (0);
}

/* Must follow func_00407BC0 in this unit: EE GCC 2.96 treats calls to
   functions it has already compiled as non-throwing, which lets reorg fill
   the third beq's slot with the lui of D_004BD520 as retail does. */
typedef signed char s8;
typedef unsigned char u8;
extern s32 D_00487354;
extern char D_004BD4E0[];
extern char D_004BD520[];
extern void func_00411288(void);
extern void func_004112B0(void);
extern void func_0011EB60(const char *, ...);

void func_00407C80(u8 *p)
{
    func_00411288();
    if (p != (u8 *)D_004872F0) {
        func_0011EB60(D_004BD4E0, p, D_004872F0);
        func_004112B0();
        return;
    }
    if (((s8 *)p)[2] != 0 && ((s8 *)p)[2] != 3 && ((s8 *)p)[2] != 9)
        func_0011EB60(D_004BD520);
    func_00407BC0();
    D_004872F0[0] = 0;
    D_00487354++;
    func_004112B0();
}
