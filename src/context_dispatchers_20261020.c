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

typedef signed short s16;
typedef void (*Dispatch)(u8 *);
extern int *D_004C26DC;
extern const Dispatch jtbl_0044BEF0[];
extern const Dispatch jtbl_004BFC90[] __attribute__((section(".sdata")));
extern const Dispatch jtbl_004C1C30[] __attribute__((section(".sdata")));
extern int *D_004C296C, *D_004C2970;
extern int *D_004C2984, *D_004C2988;
void func_001B8260(u8 *p)
{
    D_004C26DC = (int *)(p + 0xD0);
    jtbl_0044BEF0[p[4]](p);
}
void func_001F8860(u8 *p)
{
    jtbl_004BFC90[*(s16 *)(p + 0x1C)](p);
}
void func_00364F20(u8 *p)
{
    u8 *parent = *(u8 **)(p + 0x18);
    D_004C296C = (int *)(p + 0xD0);
    D_004C2970 = (int *)(parent + 0x2B8);
    jtbl_004C1C30[p[0x20]](p);
}
void func_00369070(u8 *p)
{
    u8 *parent = *(u8 **)(p + 0x18);
    D_004C2984 = (int *)(p + 0xD0);
    D_004C2988 = (int *)(parent + 0x2B8);
    (jtbl_004C1C30 + 10)[p[0x20]](p);
}

typedef unsigned short u16;
extern u16 *D_004C26E0, *D_004C26E8;
extern Dispatch jtbl_0044BF00[], jtbl_0044BF40[];
void func_001B8840(u8 *p) {
    D_004C26E0 = (u16 *)(p + 0xD0);
    jtbl_0044BF00[p[4]](p);
}
void func_001B9000(u8 *p) {
    D_004C26E8 = (u16 *)(p + 0xD0);
    jtbl_0044BF40[p[4]](p);
}

extern u16 *D_004C26E4, *D_004C26EC;
extern Dispatch jtbl_0044BF10[], jtbl_0044BF60[];
void func_001B8B40(u8 *p) {
    D_004C26E4 = (u16 *)(p+0xD0);
    jtbl_0044BF10[p[4]](p);
}
void func_001B9450(u8 *p) {
    D_004C26EC = (u16 *)(p+0xD0);
    jtbl_0044BF60[p[4]](p);
}
