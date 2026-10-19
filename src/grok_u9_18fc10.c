typedef unsigned char u8;
typedef signed short s16;

extern u8 *D_004C2794;
extern void func_0018F9E0(u8 *);
extern void func_00190540(u8 *, u8 *);
extern void func_001902F0(u8 *, u8 *);

void func_0018FC10(u8 *p, u8 *q)
{
    if (*D_004C2794 != 4) {
        func_00190540(p, q);
        func_001902F0(p, q);
        return;
    }
    if (*(s16 *)(p + 0x434) == 0)
        return;
    func_0018F9E0(p);
    if (*(s16 *)(p + 0x434) <= 0) {
        *(s16 *)(p + 0x438) = 1;
        *(s16 *)(p + 0x434) = 1;
    }
    func_00190540(p, q);
    func_001902F0(p, q);
}
