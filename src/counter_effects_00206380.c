typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;
extern s8 func_00175700(u8 *);
extern void *func_0034B070(void *,u8);
extern u8 *func_0034B5A0(u8 *,int);
extern u8 *func_00198690(u8 *,int,int);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_00206380(u8 *p)
{
    int i, offset;
    u8 *owner;
    p[0x40C]=2;
    p[0x33C]=5;
    p[0x33C]=5;
    if (--*(s16 *)(p+0x1E)<0) {
        func_00175700(p);
        if (*(s8 *)(p+0x151)!=0) {
            p[6]++;
            p[0x151]=0;
            p[0x1B2]=0;
            if (++*(s16 *)(p+0x1C)>=4) {
                u8 *child;
                p[0x40D]=0;
                p[0x40C]=0;
                p[0x33B]=0;
                p[0x33C]=0;
                *(s16 *)(p+0x1E)=0;
                if ((child=func_0034B070(p,2))!=0) {
                    u8 *target=*(u8 **)(p+0x14);
                    if (!target) target=*(u8 **)(p+0x220);
                    F(child,0x34)=F(target,0x34);
                    child[0x22]=0;
                    if (*(s8 *)(p+0x539)==0 && (*(u16 *)(p+0x354)&0x8000)) child[0x22]=1;
                }
            } else {
                *(s16 *)(p+0x1E)=96;
                if ((owner=func_0034B5A0(p,p[0x1C]))!=0) {
                    for (i=0,offset=0;i<4;++i,offset+=32) func_00198690(owner,2,(u8)offset);
                }
            }
        }
    }
}
