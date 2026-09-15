typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
#define F(p,o) (*(f32 *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define S(p,o) (*(short *)((p)+(o)))

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_0038DE40(u8 *p) {
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[316] = 0;
    }
}
void func_0038E150(u8 *p) {
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[316] = 0;
    }
}
void func_0039BFD0(u8 *p) {
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[316] = 0;
    }
}
void func_0039C350(u8 *p) {
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[316] = 0;
    }
}

void func_00209DE0(u8 *p) {
    func_00175700(p);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if (--S(p,28) == 0)
        p[6]++;
}
void func_0024F250(u8 *p) {
    func_00175700(p);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if (--S(p,28) == 0)
        p[6]++;
}
void func_00282E10(u8 *p) {
    func_00175700(p);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if (--S(p,28) == 0)
        p[6]++;
}
void func_002EEF50(u8 *p) {
    func_00175700(p);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if (--S(p,28) == 0)
        p[6]++;
}

void func_00250880(u8 *p) {
    int *a = (int *)(p + 92);
    int *b = (int *)(p + 96);
    int *c = (int *)(p + 104);
    int *d = (int *)(p + 108);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}
void func_00251530(u8 *p) {
    int *a = (int *)(p + 92);
    int *b = (int *)(p + 96);
    int *c = (int *)(p + 104);
    int *d = (int *)(p + 108);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}
void func_00275270(u8 *p) {
    int *a = (int *)(p + 92);
    int *b = (int *)(p + 96);
    int *c = (int *)(p + 104);
    int *d = (int *)(p + 108);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}
void func_002AA710(u8 *p) {
    int *a = (int *)(p + 92);
    int *b = (int *)(p + 96);
    int *c = (int *)(p + 104);
    int *d = (int *)(p + 108);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}

void func_00287D70(u8 *p) {
    int *a = (int *)(p + 92);
    int *c = (int *)(p + 104);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        *a = 0;
        *c = 0;
    }
}
void func_00287F70(u8 *p) {
    int *a = (int *)(p + 92);
    int *c = (int *)(p + 104);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        *a = 0;
        *c = 0;
    }
}
void func_0028F500(u8 *p) {
    int *a = (int *)(p + 92);
    int *c = (int *)(p + 104);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        *a = 0;
        *c = 0;
    }
}
void func_0028F710(u8 *p) {
    int *a = (int *)(p + 92);
    int *c = (int *)(p + 104);
    F(p,52)+=F(p,92);
    F(p,92)+=F(p,104);
    F(p,56)+=F(p,96);
    F(p,96)+=F(p,108);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        *a = 0;
        *c = 0;
    }
}
