#include "runtime_resource_record.h"
/* Serialized offsets are target 32-bit address words. Payloads can lie outside
 * the directory array object, so decode the address without C array arithmetic. */
typedef char TargetAddressWord_size_check[sizeof(unsigned int)==sizeof(void *)?1:-1];
typedef unsigned char u8;
typedef struct ChunkDirectoryRecord { int kind; unsigned int size,offset; } ChunkDirectoryRecord;
typedef char ChunkDirectoryRecord_size_check[sizeof(ChunkDirectoryRecord)==12?1:-1];
u8 *func_00416180(void *base,int requested)
{
    ChunkDirectoryRecord *record=(ChunkDirectoryRecord *)base;
    int index=0;
    while(record->kind>=0 && index<requested){record++;index++;}
    if(record->kind<0)return 0;
    return (u8 *)(record->offset+(unsigned int)base);
}

void *func_00416A00(ResourceRecord *base,int requested)
{
    ResourceRecord *record=base;
    int index=0;
    while(record->id>0 && index<requested) {
        record++;
        index++;
    }
    if(record->id<0)return 0;
    return (void *)(record->payload.offset+(unsigned int)base);
}
