typedef unsigned char u8;
extern void func_002FC640(u8 *, u8 *);
extern void func_002FC3D0(u8 *, u8 *);
extern void func_002FC440(u8 *, u8 *);
extern void func_002FC6B0(u8 *, u8 *);
extern void func_002FC850(u8 *, u8 *);
extern void func_002FC890(u8 *, u8 *);

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
