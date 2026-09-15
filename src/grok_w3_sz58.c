typedef unsigned char u8;
typedef signed char s8;

extern void func_00186A60(u8 *, int);
extern int func_001891F0(u8 *, int);
extern void func_00182C30(u8 *, int);
extern void func_00182DB0(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001757E0(u8 *, int, int);

#define INIT_2A0A70 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 1; break; \
        case 1: p[509] = 1; break; \
        case 2: p[509] = 1; break; \
        } \
        func_00186A60(p, 29); \
    }

void func_002A0A70(u8 *p) { INIT_2A0A70 }
void func_002D8CE0(u8 *p) { INIT_2A0A70 }
void func_002D8D40(u8 *p) { INIT_2A0A70 }
void func_003049B0(u8 *p) { INIT_2A0A70 }

#define INIT_222890 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 6; break; \
        case 1: p[509] = 2; break; \
        case 2: p[509] = 3; break; \
        } \
        p[439] = 1; \
        func_00186A60(p, 29); \
    }

void func_00222890(u8 *p) { INIT_222890 }
void func_002228F0(u8 *p) { INIT_222890 }

#define INIT_2B7FC0 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 3; break; \
        case 1: p[509] = 4; break; \
        case 2: p[509] = 5; break; \
        } \
        p[439] = 1; \
        func_00186A60(p, 29); \
    }

void func_002B7FC0(u8 *p) { INIT_2B7FC0 }
void func_002B8020(u8 *p) { INIT_2B7FC0 }

int func_0024DF70(u8 *p)
{
    if (!func_001891F0(p, 10))
        return 0;
    p[509] = 10;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
int func_002A1210(u8 *p)
{
    if (!func_001891F0(p, 10))
        return 0;
    p[509] = 10;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

int func_0026F400(u8 *p)
{
    if (!func_001891F0(p, 7))
        return 0;
    p[509] = 7;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
int func_002A76A0(u8 *p)
{
    if (!func_001891F0(p, 7))
        return 0;
    p[509] = 7;
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

void func_0021B980(u8 *p, u8 *q)
{
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 6, 6);
    func_001757E0(p, 15, 0);
}
void func_00321230(u8 *p, u8 *q)
{
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 6, 6);
    func_001757E0(p, 15, 0);
}

void func_0021BA50(u8 *p, u8 *q)
{
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 4);
}
void func_00321300(u8 *p, u8 *q)
{
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 4);
}
