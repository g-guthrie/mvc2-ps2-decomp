/* Provisional: callback table, context ABI and selector bounds need proof. */
#pragma padloop on
typedef unsigned char u8; typedef signed char s8;typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;typedef struct {float x,y,z;} V3;
extern int func_0035AED0(u8 *);
extern void func_00358F30(u8 *,u8 *);
#define OWNER (*(u8 **)(p+0x18))
void lbl_00358E30(u8 *p,u8 *work)
{
 ++p[4];*(Fields *)(p+0xec)=*(Fields *)(OWNER+0xec);p[0x13c]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float *)(p+0x50)=*(float *)(OWNER+0x50);*(float *)(p+0x54)=*(float *)(OWNER+0x54);
 p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];p[0x30]=*(s8 *)(OWNER+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(OWNER+0x50);p[0x24]=*(s8 *)(OWNER+0x24);
 func_0035AED0(p);func_00358F30(p,work);
}
