typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_0025DC40(u8 *p)
{
    f32 *vx;
    f32 *vy;
    f32 *ax;
    f32 *ay;
    f32 t;

    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    vy = (f32 *)(p + 0x60);
    t = *vx;
    *(f32 *)(p + 0x34) += t;
    t = *ax;
    *vx += t;
    t = *vy;
    *(f32 *)(p + 0x38) += t;
    ay = (f32 *)(p + 0x6C);
    t = *(f32 *)(p + 0x6C);
    *vy += t;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *vx = 0.0f;
        *vy = 0.0f;
        *ax = 0.0f;
        *ay = 0.0f;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)p[0x151] == 0)
        func_00175700(p);
}

void func_0025DED0(u8 *p)
{
    f32 *vx;
    f32 *vy;
    f32 *ax;
    f32 *ay;
    f32 t;

    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    vy = (f32 *)(p + 0x60);
    t = *vx;
    *(f32 *)(p + 0x34) += t;
    t = *ax;
    *vx += t;
    t = *vy;
    *(f32 *)(p + 0x38) += t;
    ay = (f32 *)(p + 0x6C);
    t = *(f32 *)(p + 0x6C);
    *vy += t;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *vx = 0.0f;
        *vy = 0.0f;
        *ax = 0.0f;
        *ay = 0.0f;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)p[0x151] == 0)
        func_00175700(p);
}

extern void func_001843A0(u8 *);

void func_002FE370(u8 *p)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *ax = (f32 *)(p + 104);
    f32 *vz = (f32 *)(p + 96);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((*vx * *ax) > 0.0f) {
        *vx = 0.0f;
        *ax = 0.0f;
    }
    if (p[525] == 2) {
        func_00175700(p);
        /* Retail c.lt.s(floor, position) skips the clamp only on ordered less-than. */
        if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) goto floor_done;
        *vz = 0.0f;
        *az = 0.0f;
        p[525] = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_001843A0(p);
    floor_done: ;
    } else if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

void func_002FE790(u8 *p)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *ax = (f32 *)(p + 104);
    f32 *vz = (f32 *)(p + 96);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((*vx * *ax) > 0.0f) {
        *vx = 0.0f;
        *ax = 0.0f;
    }
    if (p[525] == 2) {
        func_00175700(p);
        /* Retail c.lt.s(floor, position) skips the clamp only on ordered less-than. */
        if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) goto floor_done;
        *vz = 0.0f;
        *az = 0.0f;
        p[525] = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_001843A0(p);
    floor_done: ;
    } else if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

extern void func_00184540(u8 *);
extern void func_001865B0(u8 *);

void func_00239400(u8 *p)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *vz = (f32 *)(p + 96);
    f32 *ax = (f32 *)(p + 104);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    /* Retail c.lt.s(position, floor) skips the reset when unordered. */
    if (*(f32 *)(p + 56) < *(f32 *)(p + 1072)) {
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        *vx = 0.0f;
        *vz = 0.0f;
        *ax = 0.0f;
        *az = 0.0f;
        func_001865B0(p);
    }
}

void func_00242C60(u8 *p, u8 *state_unused)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *vz = (f32 *)(p + 96);
    f32 *ax = (f32 *)(p + 104);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    /* Retail c.lt.s(position, floor) skips the reset when unordered. */
    if (*(f32 *)(p + 56) < *(f32 *)(p + 1072)) {
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        *vx = 0.0f;
        *vz = 0.0f;
        *ax = 0.0f;
        *az = 0.0f;
        func_001865B0(p);
    }
}

void func_002EAF20(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    /* Retail c.lt.s(floor, position) exits only on ordered less-than. */
    if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) return;
    p[6]++;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(unsigned int *)(p + 96) = 0xC0892492;
    *(short *)(p + 28) = 8;
}

void func_003025A0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    /* Retail c.lt.s(floor, position) exits only on ordered less-than. */
    if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) return;
    p[6]++;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(unsigned int *)(p + 96) = 0xC0892492;
    *(short *)(p + 28) = 8;
}

void func_002EB050(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((short)--*(short *)(p + 28) == 0) {
        p[6]++;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        *(short *)(p + 28) = 8;
        func_001757E0(p, 18, 2);
    }
}

void func_003026D0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((short)--*(short *)(p + 28) == 0) {
        p[6]++;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        *(short *)(p + 28) = 8;
        func_001757E0(p, 18, 2);
    }
}

extern void func_00183D50(u8 *);

void func_0028AB50(u8 *p, u8 *q)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (*(f32 *)(p + 56) <= *(f32 *)(p + 1072)) {
        q[24]++;
        *(short *)(p + 28) = 10;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_00183D50(p);
    }
}

void func_00291EC0(u8 *p, u8 *q)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (*(f32 *)(p + 56) <= *(f32 *)(p + 1072)) {
        q[24]++;
        *(short *)(p + 28) = 10;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_00183D50(p);
    }
}

void func_002EB0E0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((short)--*(short *)(p + 28) == 0) {
        p[6]++;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        *(short *)(p + 28) = 10;
        func_001757E0(p, 18, 3);
    }
}
