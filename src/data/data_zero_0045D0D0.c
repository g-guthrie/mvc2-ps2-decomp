typedef void (*Mvc2Callback)(void);
/* Callback slots 20..27 of the 28-word set at jtbl_0045D080: func_0030C640 copies all
 * 28 words (lw/sw loop to 0x1C) into the actor's table at +0x43C. These eight
 * slots are empty in retail; the 20 populated slots are the .rodata unit before. */
Mvc2Callback data_zero_0045D0D0[8] = { 0 };
