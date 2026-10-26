typedef unsigned char u8;typedef short s16;
void func_00374210(u8*p) {
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);*(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(!(*(float*)(p+0xD4)<*(float*)(p+0x38))) {
  *(float*)(p+0x38)=*(float*)(p+0xD4);++p[6];*(s16*)(p+0x1C)=5;
  *(float*)(p+0x5C)=0;*(float*)(p+0x68)=0;*(float*)(p+0x60)=3.2142856121063232f;*(float*)(p+0x6C)=-0.234375f;
 }
}
