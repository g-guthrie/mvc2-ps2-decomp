/* Advance the shared event when its check or global phase permits it. */
typedef unsigned char u8;
extern signed char *D_004C29D4;
extern int func_00393390(u8 *);
extern void func_00393A20(void);
void func_00393910(u8 *p) {
    if (func_00393390(p)) func_00393A20();
    else if (D_004C29D4[9] >= 3) func_00393A20();
}
extern void func_00394080(void);
void func_00393F70(u8 *p) {
    if (func_00393390(p)) func_00394080();
    else if (D_004C29D4[9] >= 3) func_00394080();
}
extern void func_00394700(void);
void func_003945F0(u8 *p) {
    if (func_00393390(p)) func_00394700();
    else if (D_004C29D4[9] >= 3) func_00394700();
}
