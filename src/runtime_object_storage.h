#ifndef MVC2_RUNTIME_OBJECT_STORAGE_H
#define MVC2_RUNTIME_OBJECT_STORAGE_H

/* Forty 64-byte slots are cleared by 004000F8 and scanned by 00400AF8. */
typedef struct RuntimeObjectStorage {
    signed char active;
    unsigned char state, status, auxiliary;
    signed int context, descriptor, position, base_offset, byte_length;
    signed int word18, word1c, word20, word24, word28;
    signed int block_size, sector_count, word34, word38, word3c;
} RuntimeObjectStorage;

enum { MVC2_RUNTIME_OBJECT_COUNT = 40 };
typedef char RuntimeObjectStorageSizeCheck[(sizeof(RuntimeObjectStorage) == 64) ? 1 : -1];
extern RuntimeObjectStorage gRuntimeObjectPool_00484AC0[MVC2_RUNTIME_OBJECT_COUNT];

void func_00400148(RuntimeObjectStorage *, int, int, int, int);
RuntimeObjectStorage *func_004001A8(int, int, int, int);
RuntimeObjectStorage *func_00400258(int, int, int, int);
void func_004007A0(RuntimeObjectStorage *, int);

#endif
