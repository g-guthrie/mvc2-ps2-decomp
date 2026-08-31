typedef unsigned char u8;

extern u8 D_0044F270[];
extern u8 D_0044F280[];
extern u8 D_00450A80[];
extern u8 D_00450A90[];
extern u8 D_00457C80[];
extern u8 D_0045A010[];
extern u8 D_0045A060[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);

int func_001E9200(u8 *p) {
    if (!func_00189310(p, D_0044F270, p + 0x380)) return 0;
    func_0018A990(p, p + 0x380);
    p[509] = 1;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_001E9270(u8 *p) {
    if (!func_00189310(p, D_0044F280, p + 0x388)) return 0;
    func_0018A990(p, p + 0x388);
    p[509] = 2;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_00210800(u8 *p) {
    if (!func_00189310(p, D_00450A90, p + 0x390)) return 0;
    func_0018A990(p, p + 0x390);
    p[509] = 3;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_00210A10(u8 *p) {
    if (!func_00189310(p, D_00450A80, p + 0x3B0)) return 0;
    func_0018A990(p, p + 0x3B0);
    p[509] = 7;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_002950D0(u8 *p) {
    if (!func_00189310(p, D_00457C80, p + 0x388)) return 0;
    func_0018A990(p, p + 0x388);
    p[509] = 2;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_002CC030(u8 *p) {
    if (!func_00189310(p, D_0045A010, p + 0x388)) return 0;
    func_0018A990(p, p + 0x388);
    p[509] = 2;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_002CC190(u8 *p) {
    if (!func_00189310(p, D_0045A060, p + 0x3B8)) return 0;
    func_0018A990(p, p + 0x3B8);
    p[509] = 5;
    p[5] = 0;
    func_00186A60(p, 29);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
