typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00238B70(u8 *, f32 *);
void func_00236350(u8 *p, u8 *ctx)
{
    if (ctx[5] == 1) {
        *(f32 *)(p+0x34) += *(f32 *)(p+0x5C);
        *(f32 *)(p+0x5C) += *(f32 *)(p+0x68);
        *(f32 *)(p+0x38) += *(f32 *)(p+0x60);
        *(f32 *)(p+0x60) += *(f32 *)(p+0x6C);
        func_00175700(p);
        func_00238B70(p, (f32 *)ctx);
        if ((*(signed char *)(p + 0x211) & (1 << (p[0x1E6] ^ 1))) ||
            !(0xFC00000Fu & (1u << p[0x22]))) ctx[5]=2;
    } else {
        p[6]++;
        p[7]=0;
        *(u32 *)(p+0x5C)=0xC0A00000;
        *(u32 *)(p+0x68)=0;
        *(u32 *)(p+0x60)=0x40AB6DB6;
        *(u32 *)(p+0x6C)=0xBF092492;
        if (*(short *)(p+0x140)) {
            *(f32 *)(p+0x5C)=-*(f32 *)(p+0x5C);
            *(f32 *)(p+0x68)=-*(f32 *)(p+0x68);
        }
        func_001757E0(p,0x15,(u8)(3*p[0x20]+0xD));
    }
}
