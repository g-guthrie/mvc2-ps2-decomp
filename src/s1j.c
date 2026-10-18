typedef signed int s32;
typedef unsigned int u32;
typedef struct T { signed char used; char pad[0x17]; } T;
extern T D_0048EB38[];
extern s32 D_004C247C;
T *func_0040DF28(void) {
    s32 i;
    T *p = 0;
    for (i = 0; i < D_004C247C; i++) {
        p = &D_0048EB38[i];
        if (p->used == 0) break;
    }
    if (i == 16) return 0;
    p->used = 1;
    return p;
}
