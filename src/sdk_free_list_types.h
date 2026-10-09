#ifndef SDK_FREE_LIST_TYPES_H
#define SDK_FREE_LIST_TYPES_H
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct SdkFreeNode { struct SdkFreeNode *next; int sizeClass; u32 capacity; int sign; int used; } SdkFreeNode;
typedef struct SdkFreeListContext { u8 unknown[76]; SdkFreeNode **freeLists; } SdkFreeListContext;
#endif
