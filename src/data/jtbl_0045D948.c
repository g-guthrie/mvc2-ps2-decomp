/* Sub-state callbacks for the func_0031A710 dispatcher (selector p[6]). */
/* Consumer: src/grok_u3_31a6_dispatches.c (jtbl_0045D948). */
typedef unsigned char u8;
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void residual_0031A730(u8 *, u8 *);
extern void func_0031A800(u8 *, u8 *);
extern void func_0031A8C0(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_0045D948[3] = {
    residual_0031A730,
    func_0031A800,
    func_0031A8C0,
};
