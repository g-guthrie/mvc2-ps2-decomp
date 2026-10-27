typedef unsigned char u8;typedef signed char s8;typedef float f32;
extern void func_00183D50(u8 *);extern int func_00175700(u8 *);extern void func_00299580(u8 *);extern void func_00299010(u8 *);
static void func_00298FC0(u8 *p) {
 float previous=*(float *)(p+0x60);
 *(float *)(p+0x38)+=previous;
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (previous * *(float *)(p+0x60)<0.0f) *(float *)(p+0x6c)=-1.205357074737548828125f;
}
void func_00299500(u8 *p) {
    func_00298FC0(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_00299580(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
        func_00299010(p);
    }
}
