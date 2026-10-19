typedef unsigned char u8;
typedef unsigned int u32;

extern void func_001AD170(void *, u8, u8);
extern void func_0018FDB0(u8 *);
extern void func_001548D0(u8 *, float *, int);
extern void func_00191480(u8 *, u8 *, int);
extern void func_001E3710(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00253FC0(u8 *p)
{
    u8 *target = *(u8 **)(p + 0x1DC);
    float offset[3];
    u32 radius;
    float height;

    p[0x22]++;
    func_001AD170(p, 0, 0);
    func_001AD170(p, 2, 0);
    target[0x1B5] = 0x22;
    func_0018FDB0(p);
    offset[0] = *(float *)(target + 0x34) - *(float *)(p + 0x34);
    if (!(offset[0] <= 0.0f))
        offset[0] = -offset[0];
    radius = target[0x14C];
    height = (float)radius;
    offset[2] = 0;
    offset[1] = 2.142857074737549f * height / 1.7999999523162842f;
    func_001548D0(p, offset, 1);
    func_00191480(target, p, 1);
    func_001E3710(p, 7);
    func_001757E0(target, 13, (u8)((p[0x22] & 1) ? 3 : 0));
}
