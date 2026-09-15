typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PHYSX \
    F(p, 52) += F(p, 92); \
    F(p, 92) += F(p, 104);

#define PHYSY \
    F(p, 56) += F(p, 96); \
    F(p, 96) += F(p, 108);

extern s8 func_00175700(u8 *);
extern int func_00174470(u8 *, ...);
extern void func_0035DE40(u8 *, u8 *);
extern void func_003CAB00(u8 *, u8 *);

void func_0035D900(u8 *p, u8 *q) {
    PHYSY
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_0035DE40(p, q);
    }
}
void func_0035DDC0(u8 *p, u8 *q) {
    PHYSY
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_0035DE40(p, q);
    }
}

void func_003CC650(u8 *p, u8 *q) {
    if (!func_00174470(p, q)) {
        func_003CAB00(p, q);
        return;
    }
    PHYSX
    func_00175700(p);
}
void func_003CCF40(u8 *p, u8 *q) {
    if (!func_00174470(p, q)) {
        func_003CAB00(p, q);
        return;
    }
    PHYSX
    func_00175700(p);
}

void func_00349DF0(u8 *p) {
    u8 *q = *(u8 **)(p + 20);
    if (q[32] == 3)
        F(p, 52) = F(q, 52) + F(p, 92);
    else
        F(p, 52) = F(q, 52) + F(p, 104);
    F(p, 56) = F(q, 56);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}
void func_00349FD0(u8 *p) {
    u8 *q = *(u8 **)(p + 20);
    if (q[32] == 3)
        F(p, 52) = F(q, 52) + F(p, 92);
    else
        F(p, 52) = F(q, 52) + F(p, 104);
    F(p, 56) = F(q, 56);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}


