#!/bin/sh
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"

PYTHON=${PYTHON:-python3}
MATCH_FLAGS=${MATCH_FLAGS:--O3 -sdatathreshold 0}
BUILD=build/matching
mkdir -p "$BUILD"

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/main.c -c -lang c $MATCH_FLAGS -o "$BUILD/main.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/simple_leaves.c -c -lang c $MATCH_FLAGS -o "$BUILD/simple_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/straight_leaves.c -c -lang c $MATCH_FLAGS -o "$BUILD/straight_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_leaves.c -c -lang c $MATCH_FLAGS -o "$BUILD/tail_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/indirect_dispatch.c -c -lang c $MATCH_FLAGS -o "$BUILD/indirect_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/signed_result_handlers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/signed_result_handlers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/gp_dispatch.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/gp_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/sequential_calls.c -c -lang c $MATCH_FLAGS -o "$BUILD/sequential_calls.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_on_negative.c -c -lang c $MATCH_FLAGS -o "$BUILD/reset_on_negative.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/composite_dispatch_heads.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/composite_dispatch_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/composite_gp_dispatch_heads.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/composite_gp_dispatch_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/argument_dispatch_heads.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/argument_dispatch_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/preaction_dispatch_heads.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/preaction_dispatch_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/success_initializers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/success_initializers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/physics_dispatchers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/physics_dispatchers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/physics_negative_handlers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/physics_negative_handlers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/negative_incrementers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/negative_incrementers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/increment_on_negative.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/increment_on_negative.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/negative_notify.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/negative_notify.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/negative_notify_clear.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/negative_notify_clear.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/conditional_state_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/conditional_state_dispatch.o"

"$PYTHON" tools/verify_object.py \
    "$BUILD/main.o" private/SLUS_204.86.rom --source src/main.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/simple_leaves.o" private/SLUS_204.86.rom --source src/simple_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/straight_leaves.o" private/SLUS_204.86.rom --source src/straight_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_leaves.o" private/SLUS_204.86.rom --source src/tail_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/indirect_dispatch.o" private/SLUS_204.86.rom --source src/indirect_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/signed_result_handlers.o" private/SLUS_204.86.rom \
    --source src/signed_result_handlers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/gp_dispatch.o" private/SLUS_204.86.rom --source src/gp_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/sequential_calls.o" private/SLUS_204.86.rom --source src/sequential_calls.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/reset_on_negative.o" private/SLUS_204.86.rom --source src/reset_on_negative.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/composite_dispatch_heads.o" private/SLUS_204.86.rom \
    --source src/composite_dispatch_heads.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/composite_gp_dispatch_heads.o" private/SLUS_204.86.rom \
    --source src/composite_gp_dispatch_heads.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/argument_dispatch_heads.o" private/SLUS_204.86.rom \
    --source src/argument_dispatch_heads.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/preaction_dispatch_heads.o" private/SLUS_204.86.rom \
    --source src/preaction_dispatch_heads.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/success_initializers.o" private/SLUS_204.86.rom \
    --source src/success_initializers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/physics_dispatchers.o" private/SLUS_204.86.rom \
    --source src/physics_dispatchers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/physics_negative_handlers.o" private/SLUS_204.86.rom \
    --source src/physics_negative_handlers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/negative_incrementers.o" private/SLUS_204.86.rom \
    --source src/negative_incrementers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/increment_on_negative.o" private/SLUS_204.86.rom \
    --source src/increment_on_negative.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/negative_notify.o" private/SLUS_204.86.rom \
    --source src/negative_notify.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/negative_notify_clear.o" private/SLUS_204.86.rom \
    --source src/negative_notify_clear.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/conditional_state_dispatch.o" private/SLUS_204.86.rom \
    --source src/conditional_state_dispatch.c
