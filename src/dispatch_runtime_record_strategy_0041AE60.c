typedef unsigned char u8;
typedef struct A A; typedef struct B B;

extern void func_0041AEA0(A *record, B *owner);
extern void func_0041AF70(u8 *record, u8 *owner);

void func_0041AE60(u8 *record)
{
    u8 mode = record[32];
    u8 *value = *(u8 **)(record + 24);

    if (mode == 0)
        func_0041AEA0((A *)record, (B *)value);
    else
        func_0041AF70(record, value);
}
