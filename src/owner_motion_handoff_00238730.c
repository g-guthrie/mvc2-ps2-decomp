typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00238B70(u8 *, f32 *);
extern void func_00238A10(u8 *, u8 *);
extern void func_00126400(void);
extern void func_001E3A40(u8 *);
void func_00238730(u8 *p,void *c)
{
    u8 *owner;
    p[0x40C]=2; p[0x33C]=5; p[0x1FE]=1;
    owner=*(u8 **)(p+0x1DC); owner[0x208]=2;
    *(f32 *)(p+0x34)+=*(f32 *)(p+0x5C); *(f32 *)(p+0x5C)+=*(f32 *)(p+0x68);
    *(f32 *)(p+0x38)+=*(f32 *)(p+0x60); *(f32 *)(p+0x60)+=*(f32 *)(p+0x6C);
    func_00175700(p); func_00238B70(p,(f32 *)c); func_00238A10(p,c);
    if (*(signed char *)(p+0x150)!=0) {
        p[0x40D]=0; p[0x40C]=0; p[0x33B]=0; p[0x33C]=0;
        p[6]++; p[7]=0; *((signed char *)c+0x38)=-1;
        *(u8 **)(owner+0x1C8)=p; owner[0x20A]=1; owner[0x1E6]=p[0x1E6]; owner[0x20D]=2; owner[0x1B5]=0x24; owner[6]=0; owner[0x211]=0;
        func_00126400(); func_001E3A40(p);
        *(u32 *)(p+0x5C)=0x41055555; *(u32 *)(p+0x68)=0xBEA00000;
        *(u32 *)(p+0x60)=0x41092492; *(u32 *)(p+0x6C)=0xBF700000;
        if (p[0x1E6]) { *(f32 *)(p+0x5C)=-*(f32 *)(p+0x5C); *(f32 *)(p+0x68)=-*(f32 *)(p+0x68); }
    }
}
