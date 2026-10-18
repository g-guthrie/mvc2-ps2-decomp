typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct N { u8 pad[0xC]; struct N *next; } N;
void func_003ACC30(N *p, u8 *q) {
    extern void func_003DAA40(); extern void func_003ACCB0();
    s32 i; N *n; u8 *r;
    r = *(u8**)(q+0x28);
    if (r != 0) r[4] = 2;
    n = p; i = 0;
    do { n = n->next; func_003DAA40(n); i++; } while (i < 14);
    func_003ACCB0(p, q);
}

