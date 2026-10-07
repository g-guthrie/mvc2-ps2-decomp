/* Update animation, then advance the phase event or its pending state. */
typedef unsigned char u8;
extern signed char *D_004C29D4;
extern int func_00393390(u8 *);
extern void func_00175700(u8 *);
extern void func_00393A20(void);
void func_00393800(u8 *p) {
    func_00175700(p);
    if (func_00393390(p)) func_00393A20();
    else if (D_004C29D4[9]) p[5]++;
}
extern void func_00394080(void);
void func_00393E60(u8 *p) {
    func_00175700(p);
    if (func_00393390(p)) func_00394080();
    else if (D_004C29D4[9]) p[5]++;
}
extern void func_00394700(void);
void func_003944E0(u8 *p) {
    func_00175700(p);
    if (func_00393390(p)) func_00394700();
    else if (D_004C29D4[9]) p[5]++;
}
