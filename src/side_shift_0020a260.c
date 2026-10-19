typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
extern int func_001757E0(u8 *,int,int);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_0020A260(u8 *p,void *context)
{
    f32 x;
    u8 *q=context;
    p[7]++;
    F(q,0x10)=F(p,0x34);
    F(q,0x14)=F(p,0x38);
    x=p[0x1E6] ? -320.0f : 320.0f;
    F(p,0x34)+=x;
    F(p,0x38)+=171.42855834960938f;
    F(p,0x68)=0;
    F(p,0x6C)=0;
    F(p,0x5C)=p[0x1E6] ? 13.333333015441895f : -13.333333015441895f;
    F(p,0x60)=-1.0714285373687744f;
    *(s16 *)(p+0x1C)=32;
    func_001757E0(p,18,0);
}
extern void (*jtbl_004506E0[])(u8 *);
extern void (*jtbl_004506F0[])(u8 *,void *);
void func_0020A210(u8 *p) { jtbl_004506E0[*(s16 *)(p+0x1E)](p); }
void func_0020A230(u8 *p) { jtbl_004506F0[p[7]](p,p+0x2B8); }

extern void (*jtbl_00450780[])(u8 *);
void func_0020ABC0(u8 *p) { jtbl_00450780[*(s16 *)(p+0x1C)](p); }
