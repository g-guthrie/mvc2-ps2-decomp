typedef unsigned long long u64;
extern void func_00104210(int, void *);
int func_00104598(int a, char *b) {
    *(u64 *)(b + 0x48) = 0;
    *(int *)(b + 4) = 0x2000;
    return 0;
}



typedef struct Ring { int size; int count; int pad; char *cur; } Ring;
void func_00105048(Ring *r) {
    r->count++;
    r->cur++;
    if (r->cur == (char *)r + (r->size + 16)) r->cur = (char *)r + 16;
}
typedef struct Obj { char pad[0x14]; int len; char pad2[0x18]; int blocks; } Obj;

typedef struct Ent { int key; int a; int off; } Ent;


typedef unsigned int u32;
typedef union { float f; u32 u; } FU;

