#include "sdk_free_list_types.h"
extern SdkFreeNode *func_0011DA88(SdkFreeListContext *context, int sizeClass);
SdkFreeNode *func_0011DED8(SdkFreeListContext *context, u32 value)
{
 SdkFreeNode *node = func_0011DA88(context, 1);
 *(u32 *)(node + 1) = value;
 node->used = 1;
 return node;
}
