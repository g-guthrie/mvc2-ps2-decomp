#include "sdk_free_list_types.h"
extern void *func_00119DC8(void *context, u32 count, u32 size);
SdkFreeNode *func_0011DA88(SdkFreeListContext *context, int sizeClass)
{
 SdkFreeNode *node;
 if (context->freeLists == 0) {
  context->freeLists = func_00119DC8(context, sizeof(SdkFreeNode *), 16);
  if (context->freeLists == 0) return 0;
 }
 node = context->freeLists[sizeClass];
 if (node != 0) context->freeLists[sizeClass] = node->next;
 else {
  u32 capacity = 1u << sizeClass;
  node = func_00119DC8(context, 1, sizeof(SdkFreeNode) + capacity * sizeof(u32));
  if (node == 0) return 0;
  node->sizeClass = sizeClass;
  node->capacity = capacity;
 }
 node->used = 0;
 node->sign = 0;
 return node;
}
