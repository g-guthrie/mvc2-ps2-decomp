typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x3C]; s32 f3c; } A;
extern void func_003E0F60(A *);
extern void func_003EE9A0(void *, A *, s32);
extern void func_003EEC30(void *, A *);
s32 func_003EE8C0(A *a, void *b) {
    func_003E0F60(a);
    if (a->f3c != -1) { func_003EE9A0(b, a, 0); func_003EEC30(b, a); goto done; }
    return 0;
done:
    return 1;
}
