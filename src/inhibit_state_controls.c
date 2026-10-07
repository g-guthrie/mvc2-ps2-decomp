typedef unsigned char u8;
extern u8 D_004D18A6,D_004F1F46,D_004F1F45,D_004F1F44,D_004F1F43;
extern void func_0016CDF0(float);
void func_0016CE10(void) {
 if (!D_004D18A6) func_0016CDF0(1.0f); else func_0016CDF0(0.5f);
}
void func_00183A70(u8 *p) {
 p[0x25c] |= (u8)(1<< *(signed char *)(p+2));
 D_004D18A6=p[0x25c];p[0x25d]=0;
 D_004F1F46=1; D_004F1F45=0;D_004F1F44=10;D_004F1F43=10;
}
