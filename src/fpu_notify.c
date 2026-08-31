typedef unsigned char u8;
extern int func_00175700();
extern int func_001864A0();
extern void func_001757E0();
extern void func_00183D50();
#define UPDATE(name) void name(u8 *p) { \
    func_00175700(p); \
    *(float *)(p + 52) += *(float *)(p + 92); \
    *(float *)(p + 92) += *(float *)(p + 104); \
    *(float *)(p + 56) += *(float *)(p + 96); \
    *(float *)(p + 96) += *(float *)(p + 108); \
    if (func_001864A0(p)) { p[6]++; func_001757E0(p, 20, 1); func_00183D50(p); } \
}
UPDATE(func_001FBCF0) UPDATE(func_002021F0) UPDATE(func_0023BE60)
UPDATE(func_00245CA0) UPDATE(func_0024C9C0) UPDATE(func_0026CC00)
UPDATE(func_00272990) UPDATE(func_0028D030) UPDATE(func_00294380)
UPDATE(func_002B4BC0) UPDATE(func_002FB1C0)
