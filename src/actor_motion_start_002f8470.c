typedef unsigned char u8;typedef short s16;
void func_002F8470(u8*p) {
 float speed;
 float *vx,*ax,*vy,*ay;
 vx=(float*)(p+0x5C);vy=(float*)(p+0x60);ax=(float*)(p+0x68);ay=(float*)(p+0x6C);
 ++p[6];*(s16*)(p+0x1C)=24;*vx=0;*vy=0;*ax=0;*ay=0;
 speed=p[0x1E6]?13.333333015441895f:-13.333333015441895f;*(float*)(p+0x5C)=speed;
 *(float*)(p+0x34)+=*vx;*vx+=*ax;*(float*)(p+0x38)+=*vy;*vy+=*ay;
}
