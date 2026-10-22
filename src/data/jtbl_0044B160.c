typedef unsigned char u8;
/* func_001A4770 passes actor, owner and owner + 0x2B8. */
typedef void (*Mvc2Callback)(u8 *, u8 *, u8 *);
extern void func_001A47F0(u8 *, u8 *, u8 *);
extern void func_001A49A0(u8 *, u8 *, u8 *);
extern void func_001A4A80(u8 *, u8 *, u8 *);
const Mvc2Callback jtbl_0044B160[3] = {
    func_001A47F0,
    func_001A49A0,
    func_001A4A80,
};
