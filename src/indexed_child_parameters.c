/* Initialize a child from its indexed lifetime and scale parameters. */
typedef unsigned char u8;
extern short D_004B3C90[][8];
extern float D_004B3C50[][8];
extern void func_0015E210(u8 *,u8 *);
void func_0015E180(u8 *owner,u8 *p) {
    int index = *(int *)(p+0xdc);
    unsigned int scale;
    unsigned int life = (unsigned int) D_004B3C90;
    scale = (unsigned int)D_004B3C50;
    p[0x13c] = 1;
    life += index * 16;
    scale += index * 32;
    life += *(short *)(p+0x1c) * 2;
    *(short *)(p+0x1e) = *(short *)life;
    scale += *(short *)(p+0x1c) * 4;
    *(float *)(p+0x74) = *(float *)scale;
    p[4] = 2;
    if (p[7]) {
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    func_0015E210(owner,p);
}
extern short D_004B3D70[][8];
extern float D_004B3D30[][8];
extern void func_0015E910(u8 *,u8 *);
void func_0015E880(u8 *owner,u8 *p) {
    int index = *(int *)(p+0xdc);
    unsigned int scale;
    unsigned int life = (unsigned int) D_004B3D70;
    scale = (unsigned int)D_004B3D30;
    p[0x13c] = 1;
    life += index * 16;
    scale += index * 32;
    life += *(short *)(p+0x1c) * 2;
    *(short *)(p+0x1e) = *(short *)life;
    scale += *(short *)(p+0x1c) * 4;
    *(float *)(p+0x74) = *(float *)scale;
    p[4] = 2;
    if (p[7]) {
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    func_0015E910(owner,p);
}
extern short D_004B3EB0[][8];
extern float D_004B3E70[][8];
extern void func_001600C0(u8 *,u8 *);
void func_00160030(u8 *owner,u8 *p) {
    int index = *(int *)(p+0xdc);
    unsigned int scale;
    unsigned int life = (unsigned int) D_004B3EB0;
    scale = (unsigned int)D_004B3E70;
    p[0x13c] = 1;
    life += index * 16;
    scale += index * 32;
    life += *(short *)(p+0x1c) * 2;
    *(short *)(p+0x1e) = *(short *)life;
    scale += *(short *)(p+0x1c) * 4;
    *(float *)(p+0x74) = *(float *)scale;
    p[4] = 2;
    if (p[7]) {
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    func_001600C0(owner,p);
}
