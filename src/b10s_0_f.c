typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct N { struct N *prev; struct N *next; s32 key; } N;
extern N *D_004C2AB4;
N *func_003EBA40(s32 key) {
    N *n = D_004C2AB4;
    if (n != 0) do {
        if (n->key == key) return n;
        n = n->next;
    } while (n != 0);
    return 0;
}
