/* Update motion through the mode handler unless an active transition consumes it. */
typedef unsigned char u8;
extern int func_00188110(u8 *), func_001864A0(u8 *);
extern void func_001820A0(u8 *), func_00182300(u8 *), func_001865B0(u8 *);
extern void func_00244D60(u8 *), func_00244C20(u8 *);
void func_00244B90(u8 *p) {
    if (p[0x215] && func_00188110(p)) return;
    func_001820A0(p); func_00182300(p);
    if (p[0x212] == 1) func_00244D60(p);
    else func_00244C20(p);
    if (func_001864A0(p)) func_001865B0(p);
}
extern void func_002EA770(u8 *), func_002EA650(u8 *);
void func_002EA5C0(u8 *p) {
    if (p[0x215] && func_00188110(p)) return;
    func_001820A0(p); func_00182300(p);
    if (p[0x212] == 1) func_002EA770(p);
    else func_002EA650(p);
    if (func_001864A0(p)) func_001865B0(p);
}
extern void func_00301DF0(u8 *), func_00301CD0(u8 *);
void func_00301C40(u8 *p) {
    if (p[0x215] && func_00188110(p)) return;
    func_001820A0(p); func_00182300(p);
    if (p[0x212] == 1) func_00301DF0(p);
    else func_00301CD0(p);
    if (func_001864A0(p)) func_001865B0(p);
}
