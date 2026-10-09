typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
extern int func_00175700(u8 *);
extern int func_002F8EB0(u8 *);
extern void func_003AF9F0(u8 *, u8, u8);
extern void func_001E3210(u8 *, int);
extern void func_002F8E40(u8 *);

void func_002F8FC0(u8 *p, void *context)
{
    s8 result = (s8)func_00175700(p);
    u8 *q = (u8 *)context;
    s32 i;

    if (result < 0) {
        func_002F8EB0(p);
        return;
    }
    if (*(s8 *)(p + 337) != 0) {
        p[337] = 0;
        i = 0;
        do {
            if (q[i] == 0) {
                q[i] = 1;
                func_003AF9F0(p, 0, (u8)i);
            }
            i++;
        } while (i < 6);
        func_001E3210(p, 34);
    }
    func_002F8E40(p);
}
