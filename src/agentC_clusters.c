typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001820A0(u8 *);
extern int func_00182300(u8 *);
extern int func_00184540(u8 *);
extern int func_001864A0(u8 *);
extern int func_001865B0(u8 *);
extern int func_00174240(u8 *);
extern int func_001E7F60(u8 *);
extern void func_00186A60(u8 *, int);

#define SEQ_78BC0 \
    func_001820A0(p); \
    func_00182300(p); \
    if ((s8)func_00175700(p) < 0) { \
        func_00184540(p); \
        return; \
    } \
    if (func_001864A0(p)) \
        func_001865B0(p);

void func_00278BC0(u8 *p) { SEQ_78BC0 }
void func_0027B510(u8 *p) { SEQ_78BC0 }
void func_002EE7B0(u8 *p) { SEQ_78BC0 }
void func_00322D70(u8 *p) { SEQ_78BC0 }

#define SEQ_38D780 \
    *(f32 *)(p + 52) += *(f32 *)(p + 92); \
    *(f32 *)(p + 92) += *(f32 *)(p + 104); \
    if (!func_00174240(p)) { \
        p[4]++; \
        p[316] = 0; \
    } \
    func_00175700(p); \
    func_001E7F60(p);

void func_0038D780(u8 *p) { SEQ_38D780 }
void func_0038D980(u8 *p) { SEQ_38D780 }
void func_0041A430(u8 *p) { SEQ_38D780 }
void func_0041A7D0(u8 *p) { SEQ_38D780 }

#define INIT_ED930 \
    { \
        s8 v; \
        p[5] = 0; \
        p[7] = 0; \
        p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: \
            p[509] = 1; \
            p[439] = 1; \
            break; \
        case 1: \
            p[509] = 0; \
            p[439] = 1; \
            break; \
        case 2: \
            p[509] = 2; \
            p[439] = 1; \
            break; \
        } \
        func_00186A60(p, 21); \
    }

void func_001ED930(u8 *p) { INIT_ED930 }
void func_001ED9A0(u8 *p) { INIT_ED930 }
void func_002D0FD0(u8 *p) { INIT_ED930 }
void func_002D1040(u8 *p) { INIT_ED930 }

#define INIT_2734F0 \
    { \
        s8 v; \
        p[5] = 0; \
        p[7] = 0; \
        p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: \
            p[509] = 0; \
            p[439] = 1; \
            break; \
        case 1: \
            p[509] = 1; \
            p[439] = 1; \
            break; \
        case 2: \
            p[509] = 2; \
            p[439] = 1; \
            break; \
        } \
        func_00186A60(p, 21); \
    }

void func_002734F0(u8 *p) { INIT_2734F0 }
void func_00273560(u8 *p) { INIT_2734F0 }
void func_002860F0(u8 *p) { INIT_2734F0 }
void func_00286160(u8 *p) { INIT_2734F0 }
void func_0029ADD0(u8 *p) { INIT_2734F0 }
void func_0029AE40(u8 *p) { INIT_2734F0 }
void func_002BF990(u8 *p) { INIT_2734F0 }
void func_002BFA00(u8 *p) { INIT_2734F0 }
void func_002C4FC0(u8 *p) { INIT_2734F0 }

#define INIT_277ED0 \
    { \
        s8 v; \
        p[5] = 0; \
        p[7] = 0; \
        p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: \
            p[509] = 0; \
            break; \
        case 1: \
            p[509] = 0; \
            break; \
        case 2: \
            p[509] = 0; \
            break; \
        } \
        func_00186A60(p, 29); \
    }

void func_00277ED0(u8 *p) { INIT_277ED0 }
void func_00277F30(u8 *p) { INIT_277ED0 }
void func_0027AAA0(u8 *p) { INIT_277ED0 }
void func_0027AB00(u8 *p) { INIT_277ED0 }
void func_002F67A0(u8 *p) { INIT_277ED0 }
void func_002F6800(u8 *p) { INIT_277ED0 }
void func_0031AFA0(u8 *p) { INIT_277ED0 }
void func_0031B000(u8 *p) { INIT_277ED0 }
