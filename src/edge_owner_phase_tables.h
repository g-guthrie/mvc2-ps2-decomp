#ifndef EDGE_OWNER_PHASE_TABLES_H
#define EDGE_OWNER_PHASE_TABLES_H
#include "data/mvc2_state_callbacks.h"
typedef void (*EdgeOwnerPhase)(u8 *, u8 *);
/* Adjacent four-state and five-state groups; both forward the owner context. */
typedef struct {
    EdgeOwnerPhase first[4];
    EdgeOwnerPhase second[5];
} EdgeOwnerPhaseTables;
extern const EdgeOwnerPhaseTables jtbl_0044CD60;
#endif
