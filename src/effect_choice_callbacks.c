/* Choose an effect from the shared threshold or mode before dispatching. */
extern int D_004C2B84;
extern int D_006336F0[];
extern void func_004220B0(float, void *, int, int);
extern void func_004212D0(int);
extern unsigned char D_004A9060[], D_004A9120[], D_004AA5D0[], D_004AA690[];
extern unsigned char D_004AA8A0[], D_004AA800[], D_004A9E10[];

#define CHOICE_EFFECT(name, condition, first, second) \
void name(void) { \
    if (condition) func_004220B0(0.090000003576278687f, first, 0, 2); \
    else func_004220B0(0.090000003576278687f, second, 0, 2); \
}

CHOICE_EFFECT(func_00421430, D_004C2B84 < 100, D_004A9060, D_004A9120)
CHOICE_EFFECT(func_00421DC0, D_004C2B84 < 100, D_004AA5D0, D_004AA690)
CHOICE_EFFECT(func_00421A70, D_006336F0[0], D_004AA800, D_004A9E10)

void func_00421F30(void) {
    if (D_004C2B84 < 100)
        func_004220B0(0.090000003576278687f, D_004AA8A0, 0, 2);
    else
        func_004220B0(0.090000003576278687f, D_004AA8A0, 0, 2);
    func_004212D0(302);
}

extern unsigned char D_004A9C50[], D_004A9D30[];
void func_004219F0(void) {
    if (D_004C2B84 < 100)
        func_004220B0(0.090000003576278687f, D_004A9C50, 0, 2);
    else
        func_004220B0(0.090000003576278687f, D_004A9D30, 0, 2);
    func_004212D0(302);
}
