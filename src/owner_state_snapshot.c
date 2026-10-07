#pragma padloop on
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern void func_003C5420(u8 *,u8 *);
void func_003C5370(u8 *p,u8 *owner) {
 int count;unsigned int *dst,*src;
 src=(unsigned int *)(owner+0xec);dst=(unsigned int *)(p+0xec);count=49;
 ++p[4];
 do{*dst++=*src++;}while(--count>0);
 p[0x13c]=1;p[2]=owner[2];p[1]=owner[1];
 *(float *)(p+0x50)=*(float *)(owner+0x50);
 *(float *)(p+0x54)=*(float *)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];
 *(signed char *)(p+0x30)=*(signed char *)(owner+0x30);
 *(Vec3 *)(p+0x50)=*(Vec3 *)(owner+0x50);
 *(signed char *)(p+0x24)=*(signed char *)(owner+0x24);
 p[0x13c]=0;p[0x22]=255;
 func_003C5420(p,owner);
}
