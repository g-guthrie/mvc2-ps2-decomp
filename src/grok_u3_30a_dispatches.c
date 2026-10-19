typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C28DC;
extern DispatchFn jtbl_0045CE20[12];
extern DispatchFn jtbl_0045CE80[7];
extern DispatchFn jtbl_0045CEA0[5];
extern DispatchFn jtbl_0045CEC0[11];
extern DispatchFn jtbl_0045CEF0[5];

void func_0030A2A0(u8 *p)
{
    D_004C28DC = p + 0x2B8;
    jtbl_0045CE20[p[6] + 8](p);
}

void func_0030A530(u8 *p)
{
    D_004C28DC = p + 0x2B8;
    jtbl_0045CE80[p[6]](p);
}

void func_0030A9A0(u8 *p)
{
    p[6]++;
    jtbl_0045CEA0[p[0x20]](p);
}

void func_0030AA50(u8 *p)
{
    D_004C28DC = p + 0x2B8;
    jtbl_0045CEC0[p[0x1FD]](p);
}

void func_0030AA80(u8 *p)
{
    jtbl_0045CEF0[p[6]](p);
}
