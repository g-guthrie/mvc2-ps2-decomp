typedef unsigned char u8;
void func_00278F50(u8 *p) {
 *(float *)(p+0x118)+=0.05000000074505805969f;
 if (!(*(float *)(p+0x118)<1.0f)) { *(float *)(p+0x118)=1.0f; ++p[6]; }
}
