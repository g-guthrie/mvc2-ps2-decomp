/* Integrate event motion and complete it at a descending owner-ground contact. */
typedef unsigned char u8;
extern int func_001745B0(u8 *);
extern int func_00174470(u8 *);
extern int func_00174470(u8 *);
extern void func_00175700(u8 *);
extern int func_00174470(u8 *);
extern void func_00394760(u8 *);
void func_00393960(u8 *p) {
    float delta;
    func_00175700(p);
    delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
    delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
    delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
    delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
    if (!func_00174470(p) || (*(float *)(p+0x60)<0.0f && *(float *)(p+0x38)<=*(float *)(*(u8 **)(p+0x18)+0x430))) func_00394760(p);
}
extern void func_00394760(u8 *);
void func_00393FC0(u8 *p) {
    float delta;
    func_00175700(p);
    delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
    delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
    delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
    delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
    if (!func_00174470(p) || (*(float *)(p+0x60)<0.0f && *(float *)(p+0x38)<=*(float *)(*(u8 **)(p+0x18)+0x430))) func_00394760(p);
}
extern void func_00394760(u8 *);
void func_00394640(u8 *p) {
    float delta;
    func_00175700(p);
    delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
    delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
    delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
    delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
    if (!func_001745B0(p) || (*(float *)(p+0x60)<0.0f && *(float *)(p+0x38)<=*(float *)(*(u8 **)(p+0x18)+0x430))) func_00394760(p);
}
