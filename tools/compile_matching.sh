#!/bin/sh
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"
: "${MWCCPS2_30:?set MWCCPS2_30 to private mwccps2-3.0-011126/mwccps2.exe}"

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
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/flag_call_68.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/flag_call_68.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/boolean_state_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/boolean_state_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fpu_pure_updates.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/fpu_pure_updates.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/state_return_family.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/state_return_family.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/ordered_initializers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/ordered_initializers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/duplicate_family.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/duplicate_family.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/float_division_clear.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/float_division_clear.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/counter_steps.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/counter_steps.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/two_pass_wrappers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/two_pass_wrappers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/nonzero_wrappers.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/nonzero_wrappers.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fpu_field_accessors.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/fpu_field_accessors.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fpu_notify.c -c -lang c $MATCH_FLAGS -o "$BUILD/fpu_notify.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/init_indirect_state.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/init_indirect_state.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/conditional_notifications.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/conditional_notifications.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/gp_small_accessors.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/gp_small_accessors.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fpu_state_updates.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/fpu_state_updates.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/load_state_transition.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/load_state_transition.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/direct_state_tail.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/direct_state_tail.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/bulk_copy_112.c -c -lang c -O3,p -sdatathreshold 0 \
    -o "$BUILD/bulk_copy_112.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/conditional_engine_chains.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/conditional_engine_chains.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/conditional_init_tail.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/conditional_init_tail.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_recheck.c -c -lang c $MATCH_FLAGS -o "$BUILD/tail_recheck.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/sequential_heads.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/sequential_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/three_checks.c -c -lang c $MATCH_FLAGS -o "$BUILD/three_checks.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/clear_increment_20.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/clear_increment_20.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/negative_to_state2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/negative_to_state2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/allocator_callbacks.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/allocator_callbacks.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/three_byte_state.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/three_byte_state.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/mode_sync.c -c -lang c $MATCH_FLAGS -o "$BUILD/mode_sync.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/allocator_callbacks116.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/allocator_callbacks116.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/allocator_callbacks76.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/allocator_callbacks76.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/event_callbacks84.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/event_callbacks84.o"

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
"$PYTHON" tools/verify_object.py \
    "$BUILD/flag_call_68.o" private/SLUS_204.86.rom --source src/flag_call_68.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/boolean_state_dispatch.o" private/SLUS_204.86.rom \
    --source src/boolean_state_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/fpu_pure_updates.o" private/SLUS_204.86.rom \
    --source src/fpu_pure_updates.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/state_return_family.o" private/SLUS_204.86.rom \
    --source src/state_return_family.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/ordered_initializers.o" private/SLUS_204.86.rom \
    --source src/ordered_initializers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/duplicate_family.o" private/SLUS_204.86.rom \
    --source src/duplicate_family.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/float_division_clear.o" private/SLUS_204.86.rom \
    --source src/float_division_clear.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/counter_steps.o" private/SLUS_204.86.rom --source src/counter_steps.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/two_pass_wrappers.o" private/SLUS_204.86.rom \
    --source src/two_pass_wrappers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/nonzero_wrappers.o" private/SLUS_204.86.rom \
    --source src/nonzero_wrappers.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/fpu_field_accessors.o" private/SLUS_204.86.rom \
    --source src/fpu_field_accessors.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/fpu_notify.o" private/SLUS_204.86.rom --source src/fpu_notify.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/init_indirect_state.o" private/SLUS_204.86.rom \
    --source src/init_indirect_state.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/conditional_notifications.o" private/SLUS_204.86.rom \
    --source src/conditional_notifications.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/gp_small_accessors.o" private/SLUS_204.86.rom \
    --source src/gp_small_accessors.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/fpu_state_updates.o" private/SLUS_204.86.rom \
    --source src/fpu_state_updates.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/load_state_transition.o" private/SLUS_204.86.rom \
    --source src/load_state_transition.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/direct_state_tail.o" private/SLUS_204.86.rom \
    --source src/direct_state_tail.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/bulk_copy_112.o" private/SLUS_204.86.rom \
    --source src/bulk_copy_112.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/conditional_engine_chains.o" private/SLUS_204.86.rom \
    --source src/conditional_engine_chains.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/conditional_init_tail.o" private/SLUS_204.86.rom \
    --source src/conditional_init_tail.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_recheck.o" private/SLUS_204.86.rom --source src/tail_recheck.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/sequential_heads.o" private/SLUS_204.86.rom \
    --source src/sequential_heads.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/three_checks.o" private/SLUS_204.86.rom --source src/three_checks.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/clear_increment_20.o" private/SLUS_204.86.rom \
    --source src/clear_increment_20.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/negative_to_state2.o" private/SLUS_204.86.rom \
    --source src/negative_to_state2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/allocator_callbacks.o" private/SLUS_204.86.rom \
    --source src/allocator_callbacks.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/three_byte_state.o" private/SLUS_204.86.rom \
    --source src/three_byte_state.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/mode_sync.o" private/SLUS_204.86.rom --source src/mode_sync.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/allocator_callbacks116.o" private/SLUS_204.86.rom \
    --source src/allocator_callbacks116.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/allocator_callbacks76.o" private/SLUS_204.86.rom \
    --source src/allocator_callbacks76.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/event_callbacks84.o" private/SLUS_204.86.rom \
    --source src/event_callbacks84.c

PYTHON="$PYTHON" tools/compile_matching_data.sh
