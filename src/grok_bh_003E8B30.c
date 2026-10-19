typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 D_006207A0[];
extern char D_004BA710[];
extern s32 func_003E8F90(void);
extern void func_003E8C00(s32 *, s32, s32);
extern s32 func_003EBD30(s32 *, s32);
extern void func_003ED0D0(char *);
extern s32 func_003DCFE0(s32, s32);
extern void func_003EABA0(s32 *, u8 *, s32);
extern void func_003E8DF0(s32, s32);

s32 func_003E8B30(s32 *a0, s32 a1)
{
    s32 id;
    u8 *s2;
    id = func_003E8F90();
    s2 = D_006207A0 + ((((u16)id) - 1) << 6);
    func_003E8C00(a0, id, a1);
    if (a0[4] == 0) {
        if (func_003EBD30(&id, 1) == 0) {
            func_003ED0D0(D_004BA710);
            return 0;
        }
        *(s32 *)(s2 + 0x28) = func_003DCFE0(*(s32 *)(s2 + 8), 2);
    } else {
        func_003EABA0(a0, s2, 0);
        func_003E8DF0(id, a1);
    }
    return id;
}
