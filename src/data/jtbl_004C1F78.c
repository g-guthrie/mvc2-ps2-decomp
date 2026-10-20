#include "mvc2_state_callbacks.h"

/* func_003AFA70 passes (p, owner); this dispatch target consumes p. */
extern void residual_003AFA90(u8 *);
Mvc2OwnerStateCallback jtbl_004C1F78 = (Mvc2OwnerStateCallback)residual_003AFA90;
