/* Integrate motion, detect state thresholds, and finish the fading object. */
typedef unsigned char u8;
void func_001C4C30(u8 *p) {
 *(float *)(p+0x34)+=*(float *)(p+0x5c);
 *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60);
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (*(float *)(p+0x60)<=0.0f) ++p[5];
}
void func_0013C9A0(u8 *p) {
 float value=*(float *)(p+0x74)-0.0500000007450580596923828125f;
 *(float *)(p+0x74)=value;
 if (value<=0.0f) { ++p[4];*(float *)(p+0x74)=0.0f;p[0x13c]=0; }
}
void func_00298FC0(u8 *p) {
 float previous=*(float *)(p+0x60);
 *(float *)(p+0x38)+=previous;
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (previous * *(float *)(p+0x60)<0.0f) *(float *)(p+0x6c)=-1.205357074737548828125f;
}
void func_002CEC40(u8 *p) {
 float previous=*(float *)(p+0x60);
 *(float *)(p+0x38)+=previous;
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (previous * *(float *)(p+0x60)<0.0f) *(float *)(p+0x6c)=-1.205357074737548828125f;
}
