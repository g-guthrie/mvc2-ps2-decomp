typedef unsigned int u32;
typedef void (*RuntimeDispatchCallback)(void *);
struct RuntimeDispatchEntry { RuntimeDispatchCallback callback; void *context; };
extern struct RuntimeDispatchEntry D_00632440[];
void func_00411818(u32 index)
{
    if (D_00632440[index].callback != 0)
        D_00632440[index].callback(D_00632440[index].context);
}
