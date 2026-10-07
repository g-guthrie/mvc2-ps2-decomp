/* Advance airborne motion, clamp a landing, and defer consumed animation events. */
typedef unsigned char u8;
extern void func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_001EAFD0(u8 *);
void func_001EB3B0(u8 *p) {
    func_001EAFD0(p);
    if (!(*(float *)(p+0x38) <= *(float *)(p+0x430))) {
        if (!*(signed char *)(p+0x151)) func_00175700(p);
    } else {
        p[6]++; p[0x20d]=0;
        *(float *)(p+0x38)=*(float *)(p+0x430);
        func_00183D50(p);
    }
}
extern void func_00297120(u8 *);
void func_00297510(u8 *p) {
    func_00297120(p);
    if (!(*(float *)(p+0x38) <= *(float *)(p+0x430))) {
        if (!*(signed char *)(p+0x151)) func_00175700(p);
    } else {
        p[6]++; p[0x20d]=0;
        *(float *)(p+0x38)=*(float *)(p+0x430);
        func_00183D50(p);
    }
}
extern void func_002CDA00(u8 *);
void func_002CDDF0(u8 *p) {
    func_002CDA00(p);
    if (!(*(float *)(p+0x38) <= *(float *)(p+0x430))) {
        if (!*(signed char *)(p+0x151)) func_00175700(p);
    } else {
        p[6]++; p[0x20d]=0;
        *(float *)(p+0x38)=*(float *)(p+0x430);
        func_00183D50(p);
    }
}
