/* State callbacks for the func_00396A40 dispatcher (selector p[5]). */
/* Each slot receives the actor and its owner. */
typedef unsigned char u8;
typedef void (*OwnerCallback)(u8 *, u8 *);
extern void func_00396A70(u8 *, u8 *);
extern void func_00396BD0(u8 *, u8 *);
extern void func_00397180(u8 *, u8 *);
extern void func_00397250(u8 *, u8 *);
extern void func_00397FC0(u8 *, u8 *);
extern void func_003980C0(u8 *, u8 *);
OwnerCallback const jtbl_004C1E38[6] = {
    func_00396A70,
    func_00396BD0,
    func_00397180,
    func_00397250,
    func_00397FC0,
    func_003980C0,
};
