/* Select the effect variant from shared state, then dispatch at scale 0.09. */
extern signed char D_004D17CC;
extern void func_004220B0(float, void *, int, int);
extern unsigned char D_004A8F80[], D_004A94A0[], D_004A95E0[];
extern unsigned char D_004A9750[], D_004A9810[], D_004A98E0[];
extern unsigned char D_004A9AF0[], D_004AA3B0[];
extern unsigned char D_004A8FF9, D_004A9522, D_004A9647, D_004A97DC;
extern unsigned char D_004A988A, D_004A9982, D_004A9B9A, D_004AA425;

#define STATE_EFFECT(name, data, variant) \
void name(void) { \
    variant = D_004D17CC + 17; \
    func_004220B0(0.090000003576278687f, data, 0, 2); \
}

STATE_EFFECT(func_004213D0, D_004A8F80, D_004A8FF9)
STATE_EFFECT(func_00421650, D_004A94A0, D_004A9522)
STATE_EFFECT(func_004216F0, D_004A95E0, D_004A9647)
STATE_EFFECT(func_00421840, D_004A9750, D_004A97DC)
STATE_EFFECT(func_004218A0, D_004A9810, D_004A988A)
STATE_EFFECT(func_004218E0, D_004A98E0, D_004A9982)
STATE_EFFECT(func_00421990, D_004A9AF0, D_004A9B9A)
STATE_EFFECT(func_00421CE0, D_004AA3B0, D_004AA425)

extern unsigned char D_004A9990[], D_004A9A3A;
extern void func_004212D0(int);
void func_00421920(void) {
    D_004A9A3A = D_004D17CC + 17;
    func_004220B0(0.090000003576278687f, D_004A9990, 0, 2);
    func_004212D0(262);
}
