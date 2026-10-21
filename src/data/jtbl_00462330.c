typedef unsigned char u8;
typedef void (*EffectDispatchFn)(u8 *);
extern void residual_0034EAD0(u8 *);
extern void func_0034ED30(u8 *);
extern void func_0034F3F0(u8 *);
extern void func_0034FA70(u8 *);
extern void func_0034F5A0(u8 *);
extern void func_0034F7E0(u8 *);
extern void func_0034F970(u8 *);
EffectDispatchFn const jtbl_00462330[7] = {
    residual_0034EAD0,
    func_0034ED30,
    func_0034F3F0,
    func_0034FA70,
    func_0034F5A0,
    func_0034F7E0,
    func_0034F970,
};
