/* D_0043CC90: the writable 10-entry .data menu callback table (see leaf_batch_a.c). */
typedef void (*MenuCallback)(void);
extern MenuCallback D_0043CC90[10];
void func_00129080(int index) { D_0043CC90[index](); }
