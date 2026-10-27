typedef unsigned char u8;
extern int func_001748C0(u8 *, u8 *);
extern void func_00174910(u8 *, int);
extern int func_00175700(u8 *);
void func_003B8A10(u8 *p)
{
    u8 *owner = *(u8 **)(p + 0x14);
    float *offset = (float *)(p + 0xd0);
    float destination[3];
    destination[0] = offset[1];
    if (owner[0x1e6] == 0) destination[0] = -destination[0];
    destination[0] += *(float *)(owner + 0x34);
    destination[1] = *(float *)(owner + 0x38) + offset[2];
    p[0x22] = ((u8)func_001748C0((void *)(p + 0x34), (void *)destination) + 4) >> 3;
    func_00174910(p, 400);
    func_00175700(p);
}
