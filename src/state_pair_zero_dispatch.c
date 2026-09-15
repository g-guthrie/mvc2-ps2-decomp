typedef unsigned char u8;

extern void func_001861B0(u8 *);
extern void func_00216670(u8 *);
extern void func_00216760(u8 *);
extern void func_002168B0(u8 *);
extern void func_002169A0(u8 *);
extern void func_00233C90(u8 *);
extern void func_00233D80(u8 *);
extern void func_00233E70(u8 *);
extern void func_00233F60(u8 *);
extern void func_0023F6E0(u8 *);
extern void func_0023F7D0(u8 *);
extern void func_0023F8C0(u8 *);
extern void func_0023F9B0(u8 *);
extern void func_002DCAD0(u8 *);
extern void func_002DCBC0(u8 *);
extern void func_002DCCB0(u8 *);
extern void func_002DCDA0(u8 *);
extern void func_0031BA60(u8 *);
extern void func_0031BB50(u8 *);
extern void func_0031BCA0(u8 *);
extern void func_0031BD90(u8 *);

void func_002165F0(u8 *p) {
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0) func_00216670(p);
        else func_00216760(p);
    } else {
        if (p[525] == 0) func_002168B0(p);
        else func_002169A0(p);
    }
}
void func_00233C10(u8 *p) {
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0) func_00233C90(p);
        else func_00233D80(p);
    } else {
        if (p[525] == 0) func_00233E70(p);
        else func_00233F60(p);
    }
}
void func_0023F660(u8 *p) {
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0) func_0023F6E0(p);
        else func_0023F7D0(p);
    } else {
        if (p[525] == 0) func_0023F8C0(p);
        else func_0023F9B0(p);
    }
}
void func_002DCA50(u8 *p) {
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0) func_002DCAD0(p);
        else func_002DCBC0(p);
    } else {
        if (p[525] == 0) func_002DCCB0(p);
        else func_002DCDA0(p);
    }
}
void func_0031B9E0(u8 *p) {
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0) func_0031BA60(p);
        else func_0031BB50(p);
    } else {
        if (p[525] == 0) func_0031BCA0(p);
        else func_0031BD90(p);
    }
}
