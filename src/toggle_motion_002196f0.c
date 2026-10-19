/* Actor callback witnessed at table slot 00451038; padding is uncredited. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern int func_00354460(u8 *,int);
extern void func_001E3210(u8 *,int);
#define F(o,n) (*(f32 *)((o)+(n)))
void func_002196F0(u8 *p)
{
    f32 *vx=(f32 *)(p+0x5C), *ax=(f32 *)(p+0x68);
    s32 direction;
    F(p,0x34)+=F(p,0x5C);
    F(p,0x5C)+=F(p,0x68);
    F(p,0x38)+=F(p,0x60);
    F(p,0x60)+=F(p,0x6C);
    direction=*(s8 *)(p+0x211);
    if(direction && (s8)direction!=(1<<p[0x1E6])) goto finish;
    if((s8)func_00175700(p)>=0) {
        if(*(s8 *)(p+0x20)<=0 && *(s16 *)(p+0x1C)>1) {
            if(*(s8 *)(p+0x539)==0) {
                if((u16)(*(u16 *)(p+0x35C)|*(u16 *)(p+0x366))&0x300) {
                    p[0x20]=255;
                    *(u16 *)(p+0x366)=0;
                }
            } else if(p[0x425]==0) p[0x20]=255;
        }
        goto done;
    }
    if(--*(s16 *)(p+0x1C)==0) goto finish;
    if((*(s16 *)(p+0x1E)^=1)!=0) {
        if(p[0x20]) p[0x20]=0;
        else {
            p[0x20]=1;
            *(s16 *)(p+0x1C)=1;
        }
        if(*(s16 *)(p+0x1C)==1) p[0x20]=1;
    }
    func_00354460(p,*(s16 *)(p+0x1E));
    func_001757E0(p,21,(u8)(*(s16 *)(p+0x1E)*3+25+p[0x1B7]));
    func_001E3210(p,31);
    return;
finish:
    p[6]++;
    p[7]=0;
    *(u32 *)vx=0;
    *(u32 *)ax=0;
    func_001757E0(p,21,(u8)(p[0x1B7]+31));
done:;
}
