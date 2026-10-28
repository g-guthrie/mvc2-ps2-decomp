/* State callbacks for the func_0031A6E0 dispatcher (selector p[0x20B]). */
/* Each slot receives the actor and the owner pointer stored at p + 0x1DC. */
typedef unsigned char u8;
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_0031A710(u8 *, u8 *);
extern void func_0031ABD0(u8 *, u8 *);
extern void func_0031AC80(u8 *, u8 *);
extern void func_0031A900(u8 *, u8 *);
extern void func_0031AA10(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_0045D930[6] = {
    func_0031A710,
    func_0031ABD0,
    func_0031AC80,
    func_0031A710,
    func_0031A900,
    func_0031AA10,
};
