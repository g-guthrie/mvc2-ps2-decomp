typedef unsigned char u8;
typedef void (*MotionHandler)(u8 *, u8 *);
extern void func_001BCB60(u8 *, u8 *);
extern void func_001BCCE0(u8 *, u8 *);
extern void func_001BCD70(u8 *, u8 *);
extern void func_001BCE00(u8 *);
extern void func_001BCF60(u8 *, u8 *);
extern void func_001BD130(u8 *);
extern void func_001BD140(u8 *, u8 *);
extern void func_001BD1C0(u8 *, u8 *);

const MotionHandler jtbl_0044C220[11] = {
    func_001BCB60,
    func_001BCCE0,
    func_001BCD70,
    (MotionHandler)func_001BCE00,
    func_001BCF60,
    func_001BCCE0,
    func_001BCD70,
    (MotionHandler)func_001BCE00,
    (MotionHandler)func_001BD130,
    func_001BD140,
    func_001BD1C0,
};
