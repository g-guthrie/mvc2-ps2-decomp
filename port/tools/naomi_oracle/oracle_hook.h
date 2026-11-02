// naomi_oracle (port/tools/naomi_oracle): guest-PC hooks for the headless
// arcade oracle.  A block that starts at a hook PC first calls
// oracle_pc_hook(pc); a block never runs through a hook PC (it is split
// there).  Same in the interpreter.
#pragma once
#include "types.h"

#define ORACLE_MAX_HOOKS 16
extern u32 oracle_hook_pcs[ORACLE_MAX_HOOKS];
extern int oracle_nhooks;
extern void (*oracle_pc_hook)(u32 pc);
// JVS buttons (NAOMI_*_KEY bits) per player when oracle_jvs_override is set
extern int oracle_jvs_override;
extern u32 oracle_jvs_buttons[4];

static inline bool oracle_is_hook(u32 pc)
{
	pc &= 0x1FFFFFFF;
	for (int i = 0; i < oracle_nhooks; i++)
		if (oracle_hook_pcs[i] == pc)
			return true;
	return false;
}
void oracle_call_hook(u32 pc);
