typedef void (*RuntimeAnimationCallback)(void);

/* C callers in grok_w5_0012.c and grok_fq_12ce00.c set this callback slot;
 * native stores at 0012CB80 and 0012D2D4/2D84/2DA0 and a load/call at
 * 0012CB18/CB24 confirm one 32-bit function pointer. Next slot D_0043CD0C
 * independently begins at the immediately following word. */
RuntimeAnimationCallback data_callback_slot_0043CD08[1] = { 0 };
