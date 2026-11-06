/* Initialization loop02787c matches all68bytes and its SDK literals.
 * Other functions remain partial; linked extent316bytes is exact. */
#include "objects.h"
struct ResourceRecord_02781c { short type; unsigned char pad[6]; void *data; int extra; };
struct ResourceTable_02781c { unsigned int *entries; int count; struct ResourceRecord_02781c *records; };
extern struct ActorFlags *dat_0c2d6f84;
extern char dat_0c420000[],dat_0c810000[],dat_0cc00000[],dat_0d0c6000[],dat_0ce60000[];
extern void func_0c02a762(const void *,void *);
extern void func_0c1e9260(int),func_0c1f0a30(unsigned int,struct ResourceRecord_02781c *);
extern int func_0c022ccc(int,void *,int);
void func_0c02781c(unsigned int index,const void *src,struct ResourceTable_02781c *table)
{
    index *= sizeof(struct ResourceRecord_02781c);
    index += (unsigned int)table->records;
    func_0c02a762(src,((struct ResourceRecord_02781c *)index)->data);
}
void func_0c027830(struct ResourceTable_02781c *table,void *target)
{
    int delta=(int)table->entries-(int)table-16;
    int i,second;
    unsigned int *entries;
    struct ResourceRecord_02781c *record;
    table->entries=(unsigned int *)((int)table->entries-delta);
    table->records=(struct ResourceRecord_02781c *)((int)table->records-delta);
    entries=table->entries;
    for(i=0;i<table->count;i++) entries[i]-=delta;
    record=table->records;
    second=(int)record->data-(int)target;
    for(;record->type;record++) record->data=(void *)((int)record->data-second);
}
void func_0c02787c(int id,struct ResourceTable_02781c **holder,struct ResourceTable_02781c *table)
{
    int i;
    struct ResourceTable_02781c *current;
    func_0c1e9260(id);
    *holder=table;
    for(i=0;i<(*holder)->count;i++) {
        current=*holder;
        func_0c1f0a30(current->entries[i],current->records);
    }
}
void func_0c0278c0(void)
{
    dat_0c2d6f84->p94=dat_0c420000;
    if(dat_0c2d6f84->b84==1) dat_0c2d6f84->p94=dat_0c810000;
    func_0c022ccc(0x8a,dat_0cc00000,0);
    func_0c02a762(dat_0cc00000,dat_0c2d6f84->p94);
    func_0c022ccc(0x329,dat_0d0c6000,0);
    if(dat_0c2d6f84->b41) func_0c022ccc(0x8c,dat_0ce60000,0);
    else func_0c022ccc(0x8b,dat_0ce60000,0);
}
