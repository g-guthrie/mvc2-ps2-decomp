typedef unsigned char u8;

extern void func_001863F0(u8 *);
extern void func_00216EB0(u8 *);
extern void func_00217020(u8 *);
extern void func_00217260(u8 *);
extern void func_00217390(u8 *);
extern void func_002343F0(u8 *);
extern void func_00234430(u8 *);
extern void func_00234470(u8 *);
extern void func_002344B0(u8 *);
extern void func_0023FED0(u8 *);
extern void func_0023FF10(u8 *);
extern void func_0023FF50(u8 *);
extern void func_00240050(u8 *);
extern void func_002DD230(u8 *);
extern void func_002DD350(u8 *);
extern void func_002DD390(u8 *);
extern void func_002DD3D0(u8 *);
extern void func_0031C2A0(u8 *);
extern void func_0031C470(u8 *);
extern void func_0031C6B0(u8 *);
extern void func_0031C7E0(u8 *);

#define PHYS(a, b, c, d) \
    { \
        *(float *)(p + 52) += *(float *)(p + 92); \
        *(float *)(p + 92) += *(float *)(p + 104); \
        *(float *)(p + 56) += *(float *)(p + 96); \
        *(float *)(p + 96) += *(float *)(p + 108); \
        func_001863F0(p); \
        if (p[530] == 0) { \
            if (p[525] == 0) \
                a(p); \
            else \
                b(p); \
        } else { \
            if (p[525] == 0) \
                c(p); \
            else \
                d(p); \
        } \
    }

void func_00216DF0(u8 *p) { PHYS(func_00216EB0, func_00217020, func_00217260, func_00217390) }
void func_00234330(u8 *p) { PHYS(func_002343F0, func_00234430, func_00234470, func_002344B0) }
void func_0023FE10(u8 *p) { PHYS(func_0023FED0, func_0023FF10, func_0023FF50, func_00240050) }
void func_002DD170(u8 *p) { PHYS(func_002DD230, func_002DD350, func_002DD390, func_002DD3D0) }
void func_0031C1E0(u8 *p) { PHYS(func_0031C2A0, func_0031C470, func_0031C6B0, func_0031C7E0) }
