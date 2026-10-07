/* Consume signed animation displacement and advance an animation event. */
typedef unsigned char u8;
extern void func_00185490(u8 *), func_00175700(u8 *);
extern void func_00298390(u8 *);
void func_002984B0(u8 *p) {
    func_00185490(p); func_00298390(p); p[0x209] = 2; func_00175700(p);
    if (*(signed char *)(p+0x150)) {
        float displacement = *(signed char *)(p+0x150);
        p[0x150] = 0;
        displacement = 1.6666666269302368164f * displacement;
        if (p[0x1e6]) displacement = -displacement;
        *(float *)(p+0x34) += displacement;
    }
    if (*(signed char *)(p+0x151)) { p[0x151] = 0; p[6]++; }
}
extern void func_00298390(u8 *);
void func_00298790(u8 *p) {
    func_00185490(p); func_00298390(p); p[0x209] = 2; func_00175700(p);
    if (*(signed char *)(p+0x150)) {
        float displacement = *(signed char *)(p+0x150);
        p[0x150] = 0;
        displacement = 1.6666666269302368164f * displacement;
        if (p[0x1e6]) displacement = -displacement;
        *(float *)(p+0x34) += displacement;
    }
    if (*(signed char *)(p+0x151)) { p[0x151] = 0; p[6]++; }
}
extern void func_002ADE20(u8 *);
void func_002ADF90(u8 *p) {
    func_00185490(p); func_002ADE20(p); p[0x209] = 2; func_00175700(p);
    if (*(signed char *)(p+0x150)) {
        float displacement = *(signed char *)(p+0x150);
        p[0x150] = 0;
        displacement = 1.6666666269302368164f * displacement;
        if (p[0x1e6]) displacement = -displacement;
        *(float *)(p+0x34) += displacement;
    }
    if (*(signed char *)(p+0x151)) { p[0x151] = 0; p[6]++; }
}
