typedef unsigned int u32;

extern volatile u32 D_004C28AC;
extern volatile u32 D_004C28B8;
extern void func_0011D740(u32, u32, u32);
extern void func_0016F720(void);

void func_0016F7D0(void) {
    u32 offset = 0x49000;
    u32 second = D_004C28B8;
    u32 first = D_004C28AC;

    func_0011D740(first, second + offset, 0x1E000);
    func_0016F720();
}
