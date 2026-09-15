typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_002BA910(u8 *);

void func_00308640(u8 *p) {
    func_00175700(p);
    if ((s8)p[336] != 0) {
        p[336] = 0;
        p[6]++;
    }
}
void func_003087C0(u8 *p) {
    func_00175700(p);
    if ((s8)p[336] != 0) {
        p[336] = 0;
        p[6]++;
    }
}
void func_002B6690(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
    }
}
void func_002C2940(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
    }
}
void func_0026AAE0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0)
        p[6]++;
}
void func_00278FA0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0)
        p[6]++;
}
void func_002ACD00(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0)
        p[6]++;
}
void func_002F5FD0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0)
        p[6]++;
}
void func_001C21C0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 2;
        p[7] = 0;
    }
}
void func_001C4290(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 2;
        p[7] = 0;
    }
}
void func_002BA6D0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0)
        func_002BA910(p);
}
void func_002BC450(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0)
        func_002BA910(p);
}
