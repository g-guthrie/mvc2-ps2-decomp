/* Integrate planar motion and reset once acceleration and velocity agree. */
typedef unsigned char u8;
extern void func_001843A0(u8 *), func_00183D90(u8 *), func_00175700(u8 *);
void func_002CD440(u8 *p) {
    float delta;
    delta = *(float *)(p+0x5c); *(float *)(p+0x34) += delta;
    delta = *(float *)(p+0x68); *(float *)(p+0x5c) += delta;
    delta = *(float *)(p+0x60); *(float *)(p+0x38) += delta;
    delta = *(float *)(p+0x6c); *(float *)(p+0x60) += delta;
    if (!(*(float *)(p+0x68) * *(float *)(p+0x5c) <= 0.0f)) func_001843A0(p);
    else { func_00183D90(p); func_00175700(p); }
}
void func_002CD680(u8 *p) {
    float delta;
    delta = *(float *)(p+0x5c); *(float *)(p+0x34) += delta;
    delta = *(float *)(p+0x68); *(float *)(p+0x5c) += delta;
    delta = *(float *)(p+0x60); *(float *)(p+0x38) += delta;
    delta = *(float *)(p+0x6c); *(float *)(p+0x60) += delta;
    if (!(*(float *)(p+0x68) * *(float *)(p+0x5c) <= 0.0f)) func_001843A0(p);
    else { func_00183D90(p); func_00175700(p); }
}
void func_002CEBA0(u8 *p) {
    float delta;
    delta = *(float *)(p+0x5c); *(float *)(p+0x34) += delta;
    delta = *(float *)(p+0x68); *(float *)(p+0x5c) += delta;
    delta = *(float *)(p+0x60); *(float *)(p+0x38) += delta;
    delta = *(float *)(p+0x6c); *(float *)(p+0x60) += delta;
    if (!(*(float *)(p+0x68) * *(float *)(p+0x5c) <= 0.0f)) func_001843A0(p);
    else { func_00183D90(p); func_00175700(p); }
}
