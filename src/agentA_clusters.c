typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001C3A80(u8 *, u8 *);
extern void func_001AC3F0(u8 *, u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0015B200(u8 *, u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_00152550(u8 *, int);
extern void func_001E3210(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_001C24C0(u8 *p, u8 *q) { func_00175700(p); if (--*(s16 *)(p + 30) == 0) func_001C3A80(p, q); }
void func_001C26C0(u8 *p, u8 *q) { func_00175700(p); if (--*(s16 *)(p + 30) == 0) func_001C3A80(p, q); }
void func_001C27E0(u8 *p, u8 *q) { func_00175700(p); if (--*(s16 *)(p + 30) == 0) func_001C3A80(p, q); }
void func_001C2900(u8 *p, u8 *q) { func_00175700(p); if (--*(s16 *)(p + 30) == 0) func_001C3A80(p, q); }
void func_001C2A20(u8 *p, u8 *q) { func_00175700(p); if (--*(s16 *)(p + 30) == 0) func_001C3A80(p, q); }

void func_002525B0(u8 *p) { p[1036] = 2; p[828] = 5; if (func_00175700(p) < 0) p[6]++; }
void func_002B6AA0(u8 *p) { p[1036] = 2; p[828] = 5; if (func_00175700(p) < 0) p[6]++; }
void func_002B6B20(u8 *p) { p[1036] = 2; p[828] = 5; if (func_00175700(p) < 0) p[6]++; }
void func_002B6C50(u8 *p) { p[1036] = 2; p[828] = 5; if (func_00175700(p) < 0) p[6]++; }

void func_003A7360(u8 *p) { func_0015B200(p, p + 52, 1, 8); func_001E3710(p, 73); p[4]++; p[316] = 0; }
void func_003A7AA0(u8 *p) { func_0015B200(p, p + 52, 1, 8); func_001E3710(p, 73); p[4]++; p[316] = 0; }
void func_003A8240(u8 *p) { func_0015B200(p, p + 52, 1, 8); func_001E3710(p, 73); p[4]++; p[316] = 0; }
void func_003B3FC0(u8 *p) { func_0015B200(p, p + 52, 1, 8); func_001E3710(p, 73); p[4]++; p[316] = 0; }

void func_001AA230(u8 *p, u8 *q) { if (func_00175700(p) < 0) func_001AC3F0(p, q); }
void func_001AB430(u8 *p, u8 *q) { if (func_00175700(p) < 0) func_001AC3F0(p, q); }
void func_001AB500(u8 *p, u8 *q) { if (func_00175700(p) < 0) func_001AC3F0(p, q); }
void func_001AC2E0(u8 *p, u8 *q) { if (func_00175700(p) < 0) func_001AC3F0(p, q); }

void func_0021AFE0(u8 *p) { if (func_00175700(p) < 0) { func_00175C00(p, 0); func_001843A0(p); } }
void func_00266830(u8 *p) { if (func_00175700(p) < 0) { func_00175C00(p, 0); func_001843A0(p); } }
void func_002E6780(u8 *p) { if (func_00175700(p) < 0) { func_00175C00(p, 0); func_001843A0(p); } }
void func_00320490(u8 *p) { if (func_00175700(p) < 0) { func_00175C00(p, 0); func_001843A0(p); } }

void func_00283780(u8 *p) { if (func_00175700(p) < 0) { p[525] = 1; func_001843A0(p); } }
void func_00284880(u8 *p) { if (func_00175700(p) < 0) { p[525] = 1; func_001843A0(p); } }
void func_002BA540(u8 *p) { if (func_00175700(p) < 0) { p[525] = 1; func_001843A0(p); } }
void func_002BDBD0(u8 *p) { if (func_00175700(p) < 0) { p[525] = 1; func_001843A0(p); } }

void func_0015E2A0(u8 *unused, u8 *p) { func_00152550(p, 0); p[316] = 0; p[4] = 4; }
void func_0015E9A0(u8 *unused, u8 *p) { func_00152550(p, 0); p[316] = 0; p[4] = 4; }
void func_00160150(u8 *unused, u8 *p) { func_00152550(p, 0); p[316] = 0; p[4] = 4; }
void func_001627C0(u8 *unused, u8 *p) { func_00152550(p, 0); p[316] = 0; p[4] = 4; }

void func_00211FE0(u8 *p) { if (func_00175700(p) < 0) { p[5]++; func_00175C00(p, 0); } }
void func_002456E0(u8 *p) { if (func_00175700(p) < 0) { p[5]++; func_00175C00(p, 0); } }
void func_00245730(u8 *p) { if (func_00175700(p) < 0) { p[5]++; func_00175C00(p, 0); } }

void func_0029A1F0(u8 *p) { if (func_00175700(p) < 0) { p[1037] = 0; p[1036] = 0; p[827] = 0; p[828] = 0; func_001843A0(p); } }
void func_002B5A60(u8 *p) { if (func_00175700(p) < 0) { p[1037] = 0; p[1036] = 0; p[827] = 0; p[828] = 0; func_001843A0(p); } }
void func_002C3310(u8 *p) { if (func_00175700(p) < 0) { p[1037] = 0; p[1036] = 0; p[827] = 0; p[828] = 0; func_001843A0(p); } }

void func_00258E40(u8 *p) { if ((s8)p[339] < 0) { p[7]++; func_001757E0(p, 19, 5); } func_00175700(p); }
void func_00258F40(u8 *p) { if ((s8)p[339] < 0) { p[7]++; func_001757E0(p, 19, 5); } func_00175700(p); }
void func_00259040(u8 *p) { if ((s8)p[339] < 0) { p[7]++; func_001757E0(p, 19, 5); } func_00175700(p); }

void func_0036B8B0(u8 *p) { func_00175700(p); if ((s8)p[339] < 0) { p[4]++; p[316] = 0; } }
void func_0036BF80(u8 *p) { func_00175700(p); if ((s8)p[339] < 0) { p[4]++; p[316] = 0; } }
void func_0036F9A0(u8 *p) { func_00175700(p); if ((s8)p[339] < 0) { p[4]++; p[316] = 0; } }

void func_00199120(u8 *p) { func_001E3210(p, 43); p[4]++; p[316] = 0; }
void func_0037A7C0(u8 *p) { func_001E3210(p, 43); p[4]++; p[316] = 0; }
void func_0037CB10(u8 *p) { func_001E3210(p, 43); p[4]++; p[316] = 0; }
