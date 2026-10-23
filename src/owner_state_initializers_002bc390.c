/* Native actor/state entry points, with explicit owner and state arguments. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001E3710(u8 *,int);
extern void func_0015E620(u8 *);
extern void func_00328AA0(u8 *,u8 *);
extern void func_0018C4B0(u8 *,int);
extern void func_00185490(u8 *);
extern void func_001E3210(u8 *,int);
extern int func_001757E0(u8 *,int,int);
#define F(p,o) (*(float *)((p)+(o)))
void func_00328A20(u8 *p,u8 *context) {
    u8 *owner=context;
    p[4]++;
    p[1]=owner[1];
    F(p,0x34)=F(owner,0x34);
    F(p,0x38)=F(owner,0x38);
    *(s8 *)(p+0x24)=*(s8 *)(owner+0x24);
    *(s16 *)(p+0x1C)=0;
    *(s16 *)(p+0x1E)=150;
    func_001E3710(p,80);
    func_0015E620(owner);
    func_00328AA0(p,owner);
}
void func_002C8090(u8 *p,void *context) {
    u8 *state=context;
    u32 counterOffset;
    p[7]++;
    p[0x1B5]=48;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_0018C4B0(p,10);
    func_00185490(p);
    state[2]=0;
    func_001757E0(p,21,3);
}
void func_002BC390(u8 *p,void *context) {
    u8 *state=context;
    u32 counterOffset;
    p[6]++;
    p[0x1B5]=p[0x1B7]?69:67;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_0018C4B0(p,10);
    func_00185490(p);
    *(u32 *)(p+0x5C)=0;
    *(u32 *)(p+0x60)=0;
    *(u32 *)(p+0x68)=0;
    *(u32 *)(p+0x6C)=0;
    *(float *)state=F(p,0x38);
    func_001E3210(p,22);
    func_001757E0(p,21,21);
}

extern void func_00183D10(u8 *);
typedef struct { float velocity, acceleration; } VerticalMotion;
extern VerticalMotion D_004584E0[];
void func_002A2D30(u8 *p,void *context) {
    u32 counterOffset;
    p[7]++;
    p[0x1B5]=p[0x1B7]?50:48;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_0018C4B0(p,5);
    func_00185490(p);
    F(p,0x38)=F(p,0x430);
    p[0x20D]=0;
    *(u32 *)(p+0x5C)=0;
    *(u32 *)(p+0x60)=0;
    *(u32 *)(p+0x68)=0;
    *(u32 *)(p+0x6C)=0;
    func_00183D10(p);
    F(p,0x60)=D_004584E0[p[0x1B7]].velocity;
    F(p,0x6C)=D_004584E0[p[0x1B7]].acceleration;
    func_001757E0(p,21,(u8)(p[0x1B7]?1:0));
}
