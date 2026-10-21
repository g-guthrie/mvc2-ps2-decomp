#ifndef MVC2_CRI_SJ_MEMORY_TYPES_H
#define MVC2_CRI_SJ_MEMORY_TYPES_H
struct _sj_vtbl;
struct SJ_OBJ;
struct _UUID;
#ifndef MVC2_CRI_SJ_INTERFACE_TYPEDEF
#define MVC2_CRI_SJ_INTERFACE_TYPEDEF
typedef struct _sj_vtbl CriSjInterface;
#endif
/* The native 32-row layout is identified by the SJMEM UUID and SJ method order.
 * Interface evidence is documented in docs/CRI_SJ_MEMORY_RECOVERY_20261020.md. */
typedef void (*CriSjErrorCallback)(void *context, int error_code);
typedef struct CriSjMemory {
    CriSjInterface *interface;
    int active;
    struct _UUID *uuid;
    int remaining;
    int offset;
    char *buffer;
    int size;
    CriSjErrorCallback error_callback;
    void *error_context;
} CriSjMemory;
typedef char CriSjMemory_size_check[sizeof(CriSjMemory) == 0x24 ? 1 : -1];
extern CriSjMemory D_004908F8[32];
struct _UUID *func_0040F1B8(struct SJ_OBJ *object);
void func_0040F1C0(struct SJ_OBJ *object, CriSjErrorCallback callback, void *context);
void func_0040F1D0(struct SJ_OBJ *object);
int func_0040F478(struct SJ_OBJ *object, int line, int requested, int *available);
#endif
