typedef unsigned char u8;

extern void func_001D7380(u8 *);
extern void func_001D7450(u8 *);
extern void func_001DCA90(u8 *);
extern void func_001DCC80(u8 *);
extern void func_001EADD0(u8 *);
extern void func_001EAE40(u8 *);
extern void func_00216B30(u8 *);
extern void func_00216C30(u8 *);
extern void func_002245F0(u8 *);
extern void func_002246E0(u8 *);
extern void func_00227B90(u8 *);
extern void func_00227C00(u8 *);
extern void func_002340F0(u8 *);
extern void func_002341F0(u8 *);
extern void func_0023FB40(u8 *);
extern void func_0023FC90(u8 *);
extern void func_00296EA0(u8 *);
extern void func_00296F10(u8 *);
extern void func_002CD7E0(u8 *);
extern void func_002CD870(u8 *);
extern void func_002DCF30(u8 *);
extern void func_002DD030(u8 *);
extern void func_0031BF20(u8 *);
extern void func_0031C020(u8 *);
extern void func_003292D0(u8 *);
extern void func_00329450(u8 *);
extern void func_00352990(u8 *);
extern void func_00352C90(u8 *);

void func_001D7340(u8 *p) { if (!p[0x20]) func_001D7380(p); else func_001D7450(p); }
void func_001DCA50(u8 *p) { if (!p[0x20]) func_001DCA90(p); else func_001DCC80(p); }
void func_001EAD90(u8 *p) { if (!p[0x6]) func_001EADD0(p); else func_001EAE40(p); }
void func_00216AF0(u8 *p) { if (!p[0x212]) func_00216B30(p); else func_00216C30(p); }
void func_002245B0(u8 *p) { if (!p[0x6]) func_002245F0(p); else func_002246E0(p); }
void func_00227B50(u8 *p) { if (!p[0x6]) func_00227B90(p); else func_00227C00(p); }
void func_002340B0(u8 *p) { if (!p[0x212]) func_002340F0(p); else func_002341F0(p); }
void func_0023FB00(u8 *p) { if (!p[0x212]) func_0023FB40(p); else func_0023FC90(p); }
void func_00296E60(u8 *p) { if (!p[0x6]) func_00296EA0(p); else func_00296F10(p); }
void func_002CD7A0(u8 *p) { if (!p[0x6]) func_002CD7E0(p); else func_002CD870(p); }
void func_002DCEF0(u8 *p) { if (!p[0x212]) func_002DCF30(p); else func_002DD030(p); }
void func_0031BEE0(u8 *p) { if (!p[0x212]) func_0031BF20(p); else func_0031C020(p); }
void func_00329290(u8 *p) { if (!p[0x20]) func_003292D0(p); else func_00329450(p); }
void func_00352950(u8 *p) { if (!p[0x20]) func_00352990(p); else func_00352C90(p); }
