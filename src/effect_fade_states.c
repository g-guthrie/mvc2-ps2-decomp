/* Fade the current effect and switch its state when the fade expires. */
typedef unsigned char u8;
extern void func_00175670(u8 *);
extern void func_001B7C40(u8 *);
extern void func_00175670(u8 *);
void func_001B7A30(u8 *p) {
    func_00175670(p);
    if ((*(float *)(p+0x118) -= 0.012000000104308128357f) <= 0.0f) func_001B7C40(p);
}
extern void func_00367F60(u8 *);
extern void func_00175700(u8 *);
void func_00366F50(u8 *p) {
    func_00175700(p);
    if ((*(float *)(p+0x118) -= 0.050000000745058059692f) <= 0.0f) func_00367F60(p);
}
extern void func_00367F60(u8 *);
extern void func_00175700(u8 *);
void func_00366FB0(u8 *p) {
    func_00175700(p);
    if ((*(float *)(p+0x118) -= 0.050000000745058059692f) <= 0.0f) func_00367F60(p);
}
