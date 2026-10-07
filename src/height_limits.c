/* Cap the vertical value at the reference height plus its authored offset. */
typedef unsigned char u8;
void func_00316940(u8 *p) {
 float upper=548.5714111328125f+*(float *)(p+0x430);
 if (upper<*(float *)(p+0x38)) *(float *)(p+0x38)=upper;
}
