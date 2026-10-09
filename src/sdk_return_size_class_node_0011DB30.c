#include "sdk_free_list_types.h"
void func_0011DB30(SdkFreeListContext *context, SdkFreeNode *value)
{
 if (value != 0) {
  value->next = context->freeLists[value->sizeClass];
  context->freeLists[value->sizeClass] = value;
 }
}
