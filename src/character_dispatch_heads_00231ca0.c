/* Context is supplied as p + 0x2B8 by func_0022F160. */
typedef unsigned char u8;
extern void (*jtbl_004C0160[])(u8 *,void *) __attribute__((section(".sdata")));
extern void (*jtbl_00451FD0[])(u8 *,void *);
extern void (*jtbl_004C0168[])(u8 *,void *) __attribute__((section(".sdata")));
extern void (*jtbl_00452000[])(u8 *,void *);
void func_00231CA0(u8 *p, void *context)
{
    p[0x1FE]=1;
    p[0x201]=2;
    p[0x209]=2;
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_004C0160[p[7]](p,context);
}
void func_00231CE0(u8 *p, void *context)
{
    p[0x40C]=2;
    p[0x33C]=5;
    p[0x1FE]=1;
    p[0x201]=2;
    p[0x209]=2;
    jtbl_00451FD0[p[7]](p,context);
}
void func_00231D20(u8 *p, void *context)
{
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_004C0168[p[7]](p,context);
}
void func_00231D50(u8 *p, void *context) { jtbl_00452000[p[6]](p,context); }
extern void (*jtbl_00451ED0[])(u8 *,void *);
void func_0022F160(u8 *p) { jtbl_00451ED0[p[0x1FD]](p,p+0x2B8); }
extern void (*jtbl_00451FA8[])(u8 *,void *);
extern void (*jtbl_00451FB8[])(u8 *,void *);
void func_00231C30(u8 *p,void *context)
{
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_00451FA8[p[7]](p,context);
}
void func_00231C60(u8 *p,void *context)
{
    p[0x1FE]=1;
    p[0x201]=2;
    p[0x209]=2;
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_00451FB8[p[7]](p,context);
}

extern void (*jtbl_00452020[])(u8 *,void *);
extern void (*jtbl_00452040[])(u8 *,void *);
void func_00232490(u8 *p,void *context)
{
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_00452020[p[7]](p,context);
}
void func_002324C0(u8 *p,void *context)
{
    p[0x40C]=2;
    p[0x33C]=5;
    jtbl_00452040[p[7]](p,context);
}
