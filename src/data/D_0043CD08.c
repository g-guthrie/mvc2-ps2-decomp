typedef void (*RuntimeAnimationCallback)();

/* One three-slot callback table. func_0012ADE0 calls D_0043CD08[g->b4]
 * (0012ADE0 is the only indexed reader); C callers in grok_w5_0012.c,
 * grok_fq_12ce00.c and sc6_d.c set slot 0, native code at 0041C484..0041CA2C
 * writes, reloads and calls slot 1 (D_0043CD0C), and slot 2 starts out
 * holding func_0012D300. */
extern void func_0012D300();
RuntimeAnimationCallback D_0043CD08[3] = { 0, 0, func_0012D300 };
