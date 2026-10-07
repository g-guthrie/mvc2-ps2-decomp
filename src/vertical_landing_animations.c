/* Integrate vertical motion and select the landing animation on contact. */
typedef unsigned char u8;
extern void func_00175700(u8 *), func_00183D50(u8 *);
extern void func_001757E0(u8 *,int,int);
void func_0023C790(u8 *p) {
    float *velocity, *acceleration;
    float delta;
    func_00175700(p);
    delta = *(float *)(p+0x60);
    velocity = (float *)(p+0x60);
    *(float *)(p+0x38) += delta;
    *velocity += *(float *)(p+0x6c);
    acceleration = (float *)(p+0x6c);
    if (!(*(float *)(p+0x430) < *(float *)(p+0x38))) {
        p[7]++;
        *(float *)(p+0x38) = *(float *)(p+0x430);
        p[0x20d] = 0; *velocity = 0; *acceleration = 0;
        func_00183D50(p);
        p[0x169] = 0x15; p[0x168] = 0xD;
        func_001757E0(p,p[0x169],p[0x168]);
    }
}
void func_0023CD40(u8 *p) {
    float *velocity, *acceleration;
    float delta;
    func_00175700(p);
    delta = *(float *)(p+0x60);
    velocity = (float *)(p+0x60);
    *(float *)(p+0x38) += delta;
    *velocity += *(float *)(p+0x6c);
    acceleration = (float *)(p+0x6c);
    if (!(*(float *)(p+0x430) < *(float *)(p+0x38))) {
        p[7]++;
        *(float *)(p+0x38) = *(float *)(p+0x430);
        p[0x20d] = 0; *velocity = 0; *acceleration = 0;
        func_00183D50(p);
        p[0x169] = 0x15; p[0x168] = 0xD;
        func_001757E0(p,p[0x169],p[0x168]);
    }
}
void func_0023D280(u8 *p) {
    float *velocity, *acceleration;
    float delta;
    func_00175700(p);
    delta = *(float *)(p+0x60);
    velocity = (float *)(p+0x60);
    *(float *)(p+0x38) += delta;
    *velocity += *(float *)(p+0x6c);
    acceleration = (float *)(p+0x6c);
    if (!(*(float *)(p+0x430) < *(float *)(p+0x38))) {
        p[7]++;
        *(float *)(p+0x38) = *(float *)(p+0x430);
        p[0x20d] = 0; *velocity = 0; *acceleration = 0;
        func_00183D50(p);
        p[0x169] = 0x15; p[0x168] = 0xD;
        func_001757E0(p,p[0x169],p[0x168]);
    }
}
