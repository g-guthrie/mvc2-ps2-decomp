/* State callbacks for the func_00312950 dispatcher (selector p[0x1FD]). */
/* Each slot receives the actor and its work block at p + 0x2B8. */
typedef unsigned char u8;
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);
extern void func_00312DB0(u8 *, u8 *);
extern void func_00313100(u8 *, u8 *);
extern void func_00313AE0(u8 *, u8 *);
extern void func_003140D0(u8 *, u8 *);
extern void func_00314740(u8 *, u8 *);
extern void func_003149D0(u8 *, u8 *);
extern void func_00314B90(u8 *, u8 *);
extern void func_00314FC0(u8 *, u8 *);
extern void func_00315120(u8 *, u8 *);
extern void func_00315230(u8 *, u8 *);
const Mvc2OwnerByteCallback jtbl_0045D450[11] = {
    func_00312DB0,
    func_00313100,
    func_00313AE0,
    func_003140D0,
    func_00314740,
    func_003149D0,
    func_00312DB0,
    func_00314B90,
    func_00314FC0,
    func_00315120,
    func_00315230,
};
