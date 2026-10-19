typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_0010CA80(void);
extern void func_0010CB98(void);
extern void func_0010D170(void);
extern void func_00104BB8(void);
extern void func_0010CDB8(void);
extern void func_0010C2F8(void);
void func_0010CCA8(void) {
    func_0010CA80();
    func_0010CB98();
    func_0010D170();
    func_00104BB8();
    func_0010CDB8();
    func_0010C2F8();
}
extern s32 D_004891A8;
extern s32 D_004891B8;
extern void func_0040CAA0(s32);
extern void func_0040CB30(const char *source);
s32 *func_0040AEE8(void) {
    volatile s32 *v = &D_004891A8;
    s32 x = *v;
    func_0040CAA0(0);
    func_0040CB30(0);
    return &D_004891B8;
}
