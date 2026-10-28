typedef unsigned char u8;
/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);
extern void func_003C7E60(u8 *, u8 *);
extern void func_003C8020(u8 *, u8 *);
extern void func_003C80A0(u8 *, u8 *);
extern void func_003C80B0(u8 *, u8 *);
extern void func_003C7D20(u8 *, u8 *);
extern void func_003C7F70(u8 *, u8 *);
const Mvc2OwnerByteCallback jtbl_004760E0[8] = {
    func_003C7D20,
    func_003C7E60,
    func_003C80A0,
    func_003C80B0,
    func_003C7F70,
    func_003C8020,
    func_003C80A0,
    func_003C80B0,
};
