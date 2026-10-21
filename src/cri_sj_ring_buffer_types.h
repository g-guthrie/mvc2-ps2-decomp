#ifndef MVC2_CRI_SJ_RING_BUFFER_TYPES_H
#define MVC2_CRI_SJ_RING_BUFFER_TYPES_H

struct _sj_vtbl;
#ifndef MVC2_CRI_SJ_INTERFACE_TYPEDEF
#define MVC2_CRI_SJ_INTERFACE_TYPEDEF
typedef struct _sj_vtbl CriSjInterface;
#endif
typedef struct _UUID UUID;
typedef struct {
    signed char *data;
    signed int len;
} SJCK;
typedef struct SJ_OBJ {
    struct _sj_vtbl *vtbl;
} SJ_OBJ;

struct _sj_vtbl {
    void (*QueryInterface)(void);
    void (*AddRef)(void);
    void (*Release)(void);
    void (*Destroy)(SJ_OBJ *object);
    UUID *(*GetUuid)(SJ_OBJ *object);
    void (*Reset)(SJ_OBJ *object);
    void (*GetChunk)(SJ_OBJ *object, signed int id, signed int nbyte, SJCK *chunk);
    void (*UngetChunk)(SJ_OBJ *object, signed int id, SJCK *chunk);
    void (*PutChunk)(SJ_OBJ *object, signed int id, SJCK *chunk);
    signed int (*GetNumData)(SJ_OBJ *object, signed int id);
    signed int (*IsGetChunk)(SJ_OBJ *object, signed int id, signed int nbyte, signed int *available);
    void (*EntryErrFunc)(SJ_OBJ *object, void (*callback)(void *, signed int), void *context);
};
typedef void (*SJRBFErrorCallback)(void *object, signed int error_code);

typedef struct SJRBFRecord {
    SJ_OBJ sj;
    signed int used;
    UUID *uuid;
    signed int unk0C;
    signed int unk10;
    signed int unk14;
    signed int unk18;
    signed char *buf;
    signed int bsize;
    signed int xsize;
    signed int unk28;
    signed int unk2C;
    signed int unk30;
    signed int unk34;
    SJRBFErrorCallback err_func;
    void *err_obj;
} SJRBFRecord;
typedef char SJRBFRecord_size_check[sizeof(SJRBFRecord) == 0x40 ? 1 : -1];
extern SJRBFRecord D_00490DA8[256];

UUID *func_0040F710(SJ_OBJ *object);
void func_0040F718(SJ_OBJ *object, SJRBFErrorCallback callback, void *context);
void func_0040F728(SJ_OBJ *object);
int func_0040F750(SJ_OBJ *object, int line);
int func_0040FC08(SJ_OBJ *object, int line, int requested, int *available);
void func_0040F6D0(SJ_OBJ *object);
void func_0040F7A0(SJ_OBJ *object, int line, int requested, SJCK *chunk);
void func_0040FA70(SJ_OBJ *object, int line, SJCK *chunk);
void func_0040F910(SJ_OBJ *object, int line, SJCK *chunk);
#endif
