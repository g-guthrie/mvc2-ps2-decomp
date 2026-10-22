typedef unsigned char u8;
typedef signed short s16;
/* State initialization followed by one position/velocity integration step. */
void func_00204EC0(u8 *p)
{
 float *vx,*ax,*vy,*ay;
 vx=(float*)(p+0x5C);
 vy=(float*)(p+0x60);
 ax=(float*)(p+0x68);
 ay=(float*)(p+0x6C);
 p[6]++;
 *(s16*)(p+0x1C)=4;
 *(float*)(p+0x5C)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 *(float*)(p+0x5C)=p[0x1E6]?12.5f:-12.5f;
 *(float*)(p+0x68)=p[0x1E6]?-0.078125f:0.078125f;
 *(float*)(p+0x34)+=*vx;
 *vx+=*ax;
 *(float*)(p+0x38)+=*vy;
 *vy+=*ay;
}

void func_00205120(u8 *p)
{
 float *vx,*ax,*vy,*ay;
 vx=(float*)(p+0x5C);
 vy=(float*)(p+0x60);
 ax=(float*)(p+0x68);
 ay=(float*)(p+0x6C);
 p[6]++;
 *(s16*)(p+0x1C)=4;
 *(float*)(p+0x5C)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 *(float*)(p+0x5C)=p[0x1E6]?-8.333333015441895f:8.333333015441895f;
 *(float*)(p+0x68)=p[0x1E6]?0.0651041641831398f:-0.0651041641831398f;
 *(float*)(p+0x34)+=*vx;
 *vx+=*ax;
 *(float*)(p+0x38)+=*vy;
 *vy+=*ay;
}

void func_0029CD30(u8 *p)
{
 float *vx,*ax,*vy,*ay;
 vx=(float*)(p+0x5C);
 vy=(float*)(p+0x60);
 ax=(float*)(p+0x68);
 ay=(float*)(p+0x6C);
 p[6]++;
 *(s16*)(p+0x1C)=24;
 *(float*)(p+0x5C)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 *(float*)(p+0x5C)=p[0x1E6]?10.0f:-10.0f;
 *(float*)(p+0x68)=p[0x1E6]?-0.078125f:0.078125f;
 *(float*)(p+0x34)+=*vx;
 *vx+=*ax;
 *(float*)(p+0x38)+=*vy;
 *vy+=*ay;
}

void func_0029CF90(u8 *p)
{
 float *vx,*ax,*vy,*ay;
 vx=(float*)(p+0x5C);
 vy=(float*)(p+0x60);
 ax=(float*)(p+0x68);
 ay=(float*)(p+0x6C);
 p[6]++;
 *(s16*)(p+0x1C)=24;
 *(float*)(p+0x5C)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 *(float*)(p+0x5C)=p[0x1E6]?-8.333333015441895f:8.333333015441895f;
 *(float*)(p+0x68)=p[0x1E6]?0.0651041641831398f:-0.0651041641831398f;
 *(float*)(p+0x34)+=*vx;
 *vx+=*ax;
 *(float*)(p+0x38)+=*vy;
 *vy+=*ay;
}
