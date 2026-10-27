/* Placeholder: entry path, bounds, and DATA callback contracts remain unproved. */
typedef unsigned char u8; typedef signed short s16;
void func_00337710(u8 *p) {
 s16 *timer=(s16 *)(p+0x1c);
 *timer = *timer + 1;
 { s16 remainder = *timer % 20; *timer = remainder;
 if (remainder == 0) {
  if (*(s16 *)(p+0x1e)==1) {*(float *)(p+0x78)=1.0f;*(float *)(p+0x7c)=1.0f;*(float *)(p+0x80)=1.0f;}
  else {*(float *)(p+0x78)=0.0f;*(float *)(p+0x7c)=0.0f;*(float *)(p+0x80)=0.0f;}
  *(s16 *)(p+0x1e) = -*(s16 *)(p+0x1e); p[4]=1;
 }
 }
 *(float *)(p+0x78)+=(float)*(s16 *)(p+0x1e)/20.0f;
 *(float *)(p+0x7c)+=(float)*(s16 *)(p+0x1e)/20.0f;
 *(float *)(p+0x80)+=(float)*(s16 *)(p+0x1e)/20.0f;
}
