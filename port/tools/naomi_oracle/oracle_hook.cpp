#include "oracle_hook.h"

u32 oracle_hook_pcs[ORACLE_MAX_HOOKS];
int oracle_nhooks;
void (*oracle_pc_hook)(u32 pc);
int oracle_jvs_override;
u32 oracle_jvs_buttons[4];

void oracle_call_hook(u32 pc)
{
	if (oracle_pc_hook != nullptr)
		oracle_pc_hook(pc);
}
