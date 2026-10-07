/* Dispatch the fixed-scale effect before the numbered follow-up operation. */
extern void func_004220B0(float, void *, int, int);
extern void func_004212D0(int);
extern unsigned char D_004A91E0[], D_004A9530[], D_004AA010[], D_004AA320[];

#define FOLLOWUP_EFFECT(name, data, operation) \
void name(void) { \
    func_004220B0(0.090000003576278687f, data, 0, 2); \
    func_004212D0(operation); \
}

FOLLOWUP_EFFECT(func_004214A0, D_004A91E0, 420)
FOLLOWUP_EFFECT(func_00421690, D_004A9530, 410)
FOLLOWUP_EFFECT(func_00421B80, D_004AA010, 286)
FOLLOWUP_EFFECT(func_00421CA0, D_004AA320, 286)
