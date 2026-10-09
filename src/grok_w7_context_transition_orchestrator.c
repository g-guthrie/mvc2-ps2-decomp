typedef unsigned char u8;
typedef unsigned int u32;
extern void func_002FC640(u8 *, void *);
extern void func_002FC3D0(u8 *, void *);
extern void func_002FC440(u8 *, void *);
extern void func_002FC6B0(u8 *, void *);
extern void func_002FC850(u8 *, void *);
extern void func_002FC890(u8 *, void *);
extern int func_00174170(void);
extern void func_001D91E0(u8 *, u8, u8);

void func_002FC360(u8 *p)
{
    u8 *context = p + 0x2b8;

    func_002FC640(p, context);
    func_002FC3D0(p, context);
    func_002FC440(p, context);
    func_002FC6B0(p, context);
    func_002FC850(p, context);
    func_002FC890(p, context);
}

void func_002FC3D0(u8 *p, void *context)
{
    u8 *q = (u8 *)context;
    u32 count;
    if (p[0x169] != 0)
        return;
    count = q[6] + 1;
    q[6] = (u8)count;
    count = (u8)count;
    if (count & 0xf)
        return;
    if (func_00174170() & 7)
        return;
    func_001D91E0(p, 0, 0);
}
