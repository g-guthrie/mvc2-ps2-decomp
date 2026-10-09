/* Copy 16 halfwords per 48-byte animation record; mark remaining slots. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_00175B40(void *context, u8 *destination, const u16 *source, int count) {
 u16 *data;
 int i,j;
 for(i=0;i<count;i++) {
  data=(u16 *)(destination+16);
  *(u32 *)(destination+8)=1;
  for(j=0;j<16;j+=8) {
   data[0]=source[0];
   data[1]=source[1];
   data[2]=source[2];
   data[3]=source[3];
   data[4]=source[4];
   data[5]=source[5];
   data[6]=source[6];
   data[7]=source[7];
   data+=8;
   source+=8;
  }
  destination+=48;
 }
 for(;i<8;i++) {
  *(u32 *)(destination+8)=1;
  destination+=48;
 }
}
