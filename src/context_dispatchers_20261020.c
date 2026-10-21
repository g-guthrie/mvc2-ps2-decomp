/* Complete native dispatch entries; trailing alignment is not C credit. */
typedef unsigned char u8;
typedef signed char s8;
extern void (*D_0045DF00[][11])(u8 *);
void func_00323610(u8 *p)
{
    D_0045DF00[(s8)p[0x4DD]][p[0x1FD]](p);
}

extern int *D_004C2958;
extern int *D_004C2954;
extern void (*jtbl_00462460[])(u8 *);
void func_0034FB40(u8 *p)
{
    u8 *parent = *(u8 **)(p+0x18);
    D_004C2958 = (int *)(p+0xD0);
    D_004C2954 = (int *)(parent+0x2B8);
    jtbl_00462460[p[4]](p);
}

extern int *D_004C2974;
extern int *D_004C2978;
extern void (*D_004637D0[])(u8 *);
void func_00366090(u8 *p)
{
    u8 *parent = *(u8 **)(p+0x18);
    D_004C2974 = (int *)(p+0xD0);
    D_004C2978 = (int *)(parent+0x2B8);
    D_004637D0[p[0x20]](p);
}

extern int *D_004C297C;
extern int *D_004C2980;
extern void (*D_00463930[])(u8 *);
void func_00368000(u8 *p)
{
    u8 *parent = *(u8 **)(p+0x18);
    D_004C297C = (int *)(p+0xD0);
    D_004C2980 = (int *)(parent+0x2B8);
    D_00463930[p[0x20]](p);
}
