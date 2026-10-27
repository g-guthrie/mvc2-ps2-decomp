/* Provisional: complete callback-table ownership and valid indices remain unresolved. */
typedef void (*MenuCallback)(void);
extern MenuCallback D_0043CC90[];
void func_00129080(int index) { D_0043CC90[index](); }
