typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef float f32;
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
#define S(p,o) (*(s16 *)((u8 *)(p)+(o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);
extern int func_001864A0(u8 *);
extern void func_001863F0(u8 *);
extern int func_00185490(u8 *);

#define PHYS \
    F(p,52)+=F(p,92); \
    F(p,92)+=F(p,104); \
    F(p,56)+=F(p,96); \
    F(p,96)+=F(p,108);

#define BODY_2477E0 \
    if (p[361] != 26) return; \
    func_00185490(p); \
    if (p[533] != 0) { \
        F(p, 92) /= 8.0f; \
        F(p, 104) /= 8.0f; \
        F(p, 96) /= 8.0f; \
        F(p, 108) /= 8.0f; \
    } else { \
        I(p, 92) = 0; I(p, 96) = 0; I(p, 104) = 0; I(p, 108) = 0; \
        I(p, 108) = 0xBF4DB6DB; \
    }

void func_002477E0(u8 *p) { BODY_2477E0 }
void func_002EC5B0(u8 *p) { BODY_2477E0 }
void func_003039A0(u8 *p) { BODY_2477E0 }

#define BODY_23B5B0 \
    if (p[531] == 3) func_00183D90(p); \
    PHYS \
    func_001863F0(p); \
    if ((s8)func_00175700(p) < 0) func_001843A0(p);

void func_0023B5B0(u8 *p) { BODY_23B5B0 }
void func_00249E70(u8 *p) { BODY_23B5B0 }
void func_00311780(u8 *p) { BODY_23B5B0 }

#define BODY_232750(a2) \
    func_00175700(p); \
    PHYS \
    if (func_001864A0(p)) { \
        p[6]++; \
        func_001757E0(p, 20, a2); \
        func_00183D50(p); \
    }

void func_00232750(u8 *p) { BODY_232750(2) }
void func_0026AEE0(u8 *p) { BODY_232750(2) }
void func_002EB510(u8 *p) { BODY_232750(2) }

#define BODY_2A0470(a2) \
    func_00175700(p); \
    PHYS \
    if (func_001864A0(p)) { \
        func_00183D50(p); \
        p[6]++; \
        func_001757E0(p, 20, a2); \
    }

void func_002A0470(u8 *p) { BODY_2A0470(1) }
void func_002D86E0(u8 *p) { BODY_2A0470(1) }
void func_0031A260(u8 *p) { BODY_2A0470(1) }

void func_002D2CB0(u8 *p) { BODY_232750(3) }
void func_002D3300(u8 *p) { BODY_232750(3) }
void func_002F5DE0(u8 *p) { BODY_232750(3) }

#define BODY_1F27D0 \
    PHYS \
    if (func_001864A0(p)) { \
        func_00183D50(p); \
        p[7]++; \
        func_001757E0(p, 15, 34); \
    }

void func_001F27D0(u8 *p) { BODY_1F27D0 }
void func_001F2C50(u8 *p) { BODY_1F27D0 }
void func_001F5600(u8 *p) { BODY_1F27D0 }

#define BODY_1C7D60 \
    if (--S(p, 28) == 0) { p[4]++; p[316] = 0; return; } \
    PHYS \
    func_00175700(p);

void func_001C7D60(u8 *p) { BODY_1C7D60 }
void func_001C7FD0(u8 *p) { BODY_1C7D60 }
void func_001C8410(u8 *p) { BODY_1C7D60 }

#define BODY_1DDD90 \
    if (a1[361] != 21) { p[4]++; return; } \
    *(s8 *)(p + 36) = *(s8 *)(a1 + 36); \
    F(p, 52) = F(a1, 52); \
    F(p, 56) = F(a1, 56); \
    F(p, 60) = F(a1, 60); \
    if ((s8)func_00175700(p) < 0) { p[4]++; p[316] = 0; }

void func_001DDD90(u8 *p, u8 *a1) { BODY_1DDD90 }
void func_001DDF30(u8 *p, u8 *a1) { BODY_1DDD90 }
void func_001DE0D0(u8 *p, u8 *a1) { BODY_1DDD90 }
