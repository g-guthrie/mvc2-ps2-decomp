/* Set the five native TLB entry fields for user-assignable indices. */
typedef unsigned int u32;
extern int func_0010C3E0(u32,u32,u32,u32,u32);
int func_0010C3F0(u32 index,u32 page_mask,u32 entry_hi,u32 entry_lo0,u32 entry_lo1)
{
    if (index - 13u >= 35u) return -1;
    return func_0010C3E0(index,page_mask,entry_hi,entry_lo0,entry_lo1);
}
