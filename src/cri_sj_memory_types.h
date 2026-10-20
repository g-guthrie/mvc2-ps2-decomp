#ifndef MVC2_CRI_SJ_MEMORY_TYPES_H
#define MVC2_CRI_SJ_MEMORY_TYPES_H
/* The native 32-row layout is identified by the SJMEM UUID and SJ method order.
 * Interface evidence is documented in docs/CRI_SJ_MEMORY_RECOVERY_20261020.md. */
struct CriSjInterface;
typedef void (*CriSjErrorCallback)(void *context, int error_code);
typedef struct CriSjMemory {
    struct CriSjInterface *interface;
    int active;
    void *uuid;
    int remaining;
    int offset;
    char *buffer;
    int size;
    CriSjErrorCallback error_callback;
    void *error_context;
} CriSjMemory;
typedef char CriSjMemory_size_check[sizeof(CriSjMemory) == 0x24 ? 1 : -1];
extern CriSjMemory D_004908F8[32];
void *func_0040F1B8(CriSjMemory *record);
void func_0040F1C0(CriSjMemory *record, CriSjErrorCallback callback, void *context);
void func_0040F1D0(CriSjMemory *record);
int func_0040F478(CriSjMemory *record, int line, int requested, int *available);
#endif
