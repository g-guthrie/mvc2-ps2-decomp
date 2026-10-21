#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;
typedef struct {u8 prefix[0x366];u16 pressed;} OwnerInput;
typedef struct {u8 prefix[15];s8 count;} Control;
extern void func_003AB180(u8 *,u8 *);
extern void func_003AADA0(u8 *,u8 *);
extern void func_003AD2D0(u8 *,u8 *);
extern void func_003AA3C0(int,f32 *);
void func_003AAA60(u8 *p,void *context)
{
 u8 *q=context;
 u8 *owner=*(u8 **)(p+0x18);
 OwnerInput *input=(OwnerInput *)owner;
 Control *control=(Control *)q;
 f32 delta[2];
 if(((s8 *)owner)[0x1b2] || ((s8 *)p)[0x1b2]) {func_003AB180(p,q);return;}
 input->pressed|=*(s16 *)(owner+0x362)&0x360;
 if(control->count>7) {
 u16 pressed=input->pressed;
 u16 mask=0x300;
 input->pressed=0;
 if(owner[0x20d]==2)mask|=0x60;
 if(pressed&mask) {func_003AADA0(p,q);return;}
 }
 if(!(*(f32 *)(owner+0x430)<=*(f32 *)(p+0x38))) {func_003AD2D0(p,q);return;}
 func_003AA3C0(p[0x22],delta);
 *(f32 *)(p+0x5c)+=delta[0];
 *(f32 *)(p+0x60)+=delta[1];
 *(f32 *)(p+0x34)=*(f32 *)(q+0x10)+*(f32 *)(p+0x5c);
 *(f32 *)(p+0x38)=*(f32 *)(q+0x14)+*(f32 *)(p+0x60);
 p[0x13c]=1;q[15]=0;q[0x34]=1;
}
