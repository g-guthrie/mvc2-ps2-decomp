typedef unsigned char u8;
typedef struct SdkFreeNode { struct SdkFreeNode *next; int sizeClass; } SdkFreeNode;
typedef struct SdkFreeListContext { u8 unknown[76]; SdkFreeNode **freeLists; } SdkFreeListContext;
void func_0011DB30(SdkFreeListContext *context, SdkFreeNode *value)
{
 if (value != 0) {
  value->next = context->freeLists[value->sizeClass];
  context->freeLists[value->sizeClass] = value;
 }
}
