extern void func_00405EB8(void);
extern void func_003FE710(void);
extern signed int func_003FEBD8(void);
extern void func_004015C8(void);
extern void func_003FEAE8(void);
extern signed int func_003FEBB8(void);

void func_00400130(void) { func_00405EB8(); }
void func_003FECA8(void) { func_003FE710(); }
void func_00401628(void) { func_004015C8(); }
signed int func_003FEBF8(void) { return func_003FEBD8(); }

signed int func_003FEBD8(void)
{
    func_003FEAE8();
    return func_003FEBB8();
}
