#include "mvc2_state_callbacks.h"

/* func_003B08E0 passes (p, owner); this dispatch target consumes p. */
extern void residual_003B0900(u8 *);
Mvc2OwnerStateCallback jtbl_004C1F88 = (Mvc2OwnerStateCallback)residual_003B0900;
