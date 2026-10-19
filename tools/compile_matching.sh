#!/bin/sh
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"
: "${MWCCPS2_30:?set MWCCPS2_30 to private mwccps2-3.0-011126/mwccps2.exe}"

: "${SNCPP:?set SNCPP to SN GCC 2.95.2 cpp.exe}"
: "${SNCC1:?set SNCC1 to SN GCC 2.95.2 cc1.exe}"
: "${SNAS:?set SNAS to the matching SN ee-as.exe}"

: "${EE96CC1:?set EE96CC1 to EE GCC 2.96 cc1}"

# Sony 2.9 lives in its own env file, so a caller that sourced only
# private/build.env still gets EE29CC1 rather than failing mid-build.
if [ -z "${EE29CC1:-}" ] && [ -f private/sony29.env ]; then
    . private/sony29.env
fi

PYTHON=${PYTHON:-python3}
MATCH_FLAGS=${MATCH_FLAGS:--O3 -sdatathreshold 0}
SNCPP=${SNCPP:-private/toolchain/compilers/sn-gcc-2.95.2/cpp.exe}
SNCC1=${SNCC1:-private/toolchain/compilers/sn-gcc-2.95.2/cc1.exe}
SNAS=${SNAS:-private/toolchain/compilers/sn-gcc-2.95.2/ee-as.exe}
GNUAS=${GNUAS:-${AS:-mipsel-linux-gnu-as}}
BUILD=build/matching
mkdir -p "$BUILD"

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/main.c -c -lang c $MATCH_FLAGS -o "$BUILD/main.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/simple_leaves.c -c -lang c $MATCH_FLAGS -o "$BUILD/simple_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_dispatch_001712A0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/state_dispatch_001712A0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/global_counter_leaves.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/global_counter_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/field_store_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/field_store_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/gp_accessors.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/gp_accessors.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/gp_leaf_batch.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/gp_leaf_batch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/gp_leaf_batch2.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/gp_leaf_batch2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_gp_r2.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_gp_r2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves3.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves3.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves4.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves4.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves5.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves5.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves6.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves6.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves7.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves7.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves8.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves8.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves9.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves9.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves10.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves10.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves11.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves11.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves12.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves12.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves13.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves13.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves14.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves14.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves15.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves15.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves16.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves16.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves17.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves17.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves18.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves18.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves19.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves19.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/small_cluster_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/small_cluster_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves20.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves20.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail_call_leaves21.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/tail_call_leaves21.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/setter_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/setter_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/byte_setter_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/byte_setter_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/byte_setter_pairs.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/byte_setter_pairs.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_set.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_set.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pointer_field_setters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/pointer_field_setters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/struct_field_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/struct_field_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/global_accessors.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/global_accessors.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/field_block_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/field_block_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/leaf_batch_a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/leaf_batch_a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/leaf_batch_b.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/leaf_batch_b.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/leaf_batch_c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/leaf_batch_c.o"
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
    src/composite_gp_dispatch_heads.c -c -lang c -O3 -sdatathreshold 8 -i src/data \
    -o "$BUILD/composite_gp_dispatch_heads.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_001794A0.c -c -lang c -O4,p -sdatathreshold 0 \
    -o "$BUILD/func_001794A0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/func_001794A0.o" private/SLUS_204.86.rom \
    --source src/func_001794A0.c
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
    src/state_return_family.c -c -lang c -O4 -sdatathreshold 0 \
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
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/event_value_dispatch.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/event_value_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/indirect68_family.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/indirect68_family.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tail12.c -c -lang c $MATCH_FLAGS -o "$BUILD/tail12.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/flag_clear_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/flag_clear_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/cluster_batch1.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/cluster_batch1.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/signed_flag_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/signed_flag_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/signed_dispatch_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/signed_dispatch_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/agentA_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/agentA_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_0018.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_001.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_001.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_001gp.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_r1_001gp.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/agentB_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/agentB_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/agentC_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/agentC_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/agentD_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/agentD_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_0028.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_002a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_002a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0027.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0027.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_sz54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_sz54.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_sz0c.c -c -lang c -O2 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_sz0c.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_sz68.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_sz68.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0034.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0034.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0039.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0039.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0029.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0029.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_neg.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_neg.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0024.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0024.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0024.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0024.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pair_flag_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/pair_flag_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round2_pairs1.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round2_pairs1.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/round2_small.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round2_small.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round2_hard.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round2_hard.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round3_0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round3_0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round3_1.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round3_1.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round3_2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round3_2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round3_3.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round3_3.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_tiny_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_tiny_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_tiny2.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_tiny2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0014.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0014.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0014.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0014.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_0015.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0015.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_size40.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_size40.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_size54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_size54.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4_sz54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w4_sz54.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001f.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001f.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_sz58.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_sz58.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_sz58.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sz58.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_sz70.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sz70.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_sz78.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sz78.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_sz80.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sz80.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_sz88.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sz88.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0040.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_r1_0040.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_002c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_r2_002c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_tail_r2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_tail_r2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_med_leaves.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_med_leaves.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_003c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_003c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0012.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0012.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/round4_0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round4_0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/round4_3.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/round4_3.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_round4_2fix.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_round4_2fix.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_dup_clusters.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_dup_clusters.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0020.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_0020.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0018.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0018.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0019.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0019.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_001c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_001c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0038.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0028.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_size60.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_size60.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r3_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r3_0028.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r1_0030.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r1_0030.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0030.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_r2_0030.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0010.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0010.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_r2_0010_30.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0010_30.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0038.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0034.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_r2_0034.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_dispatch_r2.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_dispatch_r2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_fpu_r2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_fpu_r2.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0011.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0011.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_fpu.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_fpu.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_r2_0020.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_r2_0020.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_001c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_001c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001d.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_001d.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0016.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0016.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0017.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0017.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_dispatch_00176DC0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/state_dispatch_00176DC0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0022.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0022.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_001a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_001a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_002c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_002c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_001e.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_001e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0020.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0020.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0026.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0026.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_002e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_002e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0030.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0030.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0031.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0031.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0038.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_pairs.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_pairs.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_pairs.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w6_pairs.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_001c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_001c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4_szc0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w4_szc0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0035.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0035.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_sz68.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_sz68.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0041.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_0041.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0015.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0015.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0019.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0019.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_001a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001e.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0012.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0012.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0014.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0014.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0016.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0016.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0018.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001b.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001b.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_001c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0017.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0017.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0024.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0024.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_sz54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_sz54.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0020.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0020.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0022.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0022.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_002c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_002c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0030.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0030.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_002a.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_002a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_002a.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w6_002a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0024.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_0024.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_002e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_002e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0038.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0038.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_003a.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_003a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0026.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0026.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0034.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0034.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0028.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w6_0028.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_sz40.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_sz40.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_szc0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_szc0.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_003c.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_003e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_sz0c.c -c -lang c -O2 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_sz0c.o"
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w3_sz54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_sz54.o"

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003a.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_003a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4_sz80.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w4_sz80.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_sz80.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_sz80.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/float_clamp.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/float_clamp.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/physics_floor_clamp.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/physics_floor_clamp.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/physics_timer_inc.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/physics_timer_inc.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_pair_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/state_pair_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_pair_zero_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/state_pair_zero_dispatch.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/nibble_state_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/nibble_state_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/main.o" private/SLUS_204.86.rom --source src/main.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/simple_leaves.o" private/SLUS_204.86.rom --source src/simple_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/state_dispatch_001712A0.o" private/SLUS_204.86.rom \
    --source src/state_dispatch_001712A0.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/global_counter_leaves.o" private/SLUS_204.86.rom \
    --source src/global_counter_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/field_store_leaves.o" private/SLUS_204.86.rom \
    --source src/field_store_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/gp_accessors.o" private/SLUS_204.86.rom \
    --source src/gp_accessors.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/gp_leaf_batch.o" private/SLUS_204.86.rom \
    --source src/gp_leaf_batch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/gp_leaf_batch2.o" private/SLUS_204.86.rom \
    --source src/gp_leaf_batch2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_gp_r2.o" private/SLUS_204.86.rom \
    --source src/grok_gp_r2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves2.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves3.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves3.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves4.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves4.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves5.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves5.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves6.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves6.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves7.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves7.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves8.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves8.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves9.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves9.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves10.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves10.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves11.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves11.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves12.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves12.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves13.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves13.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves14.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves14.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves15.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves15.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves16.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves16.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves17.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves17.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves18.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves18.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves19.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves19.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/small_cluster_leaves.o" private/SLUS_204.86.rom \
    --source src/small_cluster_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves20.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves20.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail_call_leaves21.o" private/SLUS_204.86.rom \
    --source src/tail_call_leaves21.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/setter_leaves.o" private/SLUS_204.86.rom \
    --source src/setter_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/byte_setter_leaves.o" private/SLUS_204.86.rom \
    --source src/byte_setter_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/byte_setter_pairs.o" private/SLUS_204.86.rom \
    --source src/byte_setter_pairs.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_set.o" private/SLUS_204.86.rom \
    --source src/grok_w3_set.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/pointer_field_setters.o" private/SLUS_204.86.rom \
    --source src/pointer_field_setters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/struct_field_leaves.o" private/SLUS_204.86.rom \
    --source src/struct_field_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/global_accessors.o" private/SLUS_204.86.rom \
    --source src/global_accessors.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/field_block_leaves.o" private/SLUS_204.86.rom \
    --source src/field_block_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/leaf_batch_a.o" private/SLUS_204.86.rom \
    --source src/leaf_batch_a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/leaf_batch_b.o" private/SLUS_204.86.rom \
    --source src/leaf_batch_b.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/leaf_batch_c.o" private/SLUS_204.86.rom \
    --source src/leaf_batch_c.c
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
"$PYTHON" tools/verify_object.py \
    "$BUILD/event_value_dispatch.o" private/SLUS_204.86.rom \
    --source src/event_value_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/indirect68_family.o" private/SLUS_204.86.rom \
    --source src/indirect68_family.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/tail12.o" private/SLUS_204.86.rom --source src/tail12.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/flag_clear_dispatch.o" private/SLUS_204.86.rom \
    --source src/flag_clear_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/cluster_batch1.o" private/SLUS_204.86.rom \
    --source src/cluster_batch1.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/signed_flag_clusters.o" private/SLUS_204.86.rom \
    --source src/signed_flag_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/signed_dispatch_clusters.o" private/SLUS_204.86.rom \
    --source src/signed_dispatch_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/agentA_clusters.o" private/SLUS_204.86.rom \
    --source src/agentA_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/agentB_clusters.o" private/SLUS_204.86.rom \
    --source src/agentB_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/agentC_clusters.o" private/SLUS_204.86.rom \
    --source src/agentC_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/agentD_clusters.o" private/SLUS_204.86.rom \
    --source src/agentD_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0028.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_002a.o" private/SLUS_204.86.rom \
    --source src/grok_w3_002a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0027.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0027.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz54.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz54.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz0c.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz0c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz68.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz68.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0034.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0034.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0039.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0039.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0029.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0029.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_neg.o" private/SLUS_204.86.rom \
    --source src/grok_w3_neg.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0024.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0024.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0028.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/pair_flag_clusters.o" private/SLUS_204.86.rom \
    --source src/pair_flag_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round2_pairs1.o" private/SLUS_204.86.rom \
    --source src/round2_pairs1.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round2_small.o" private/SLUS_204.86.rom \
    --source src/round2_small.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round2_hard.o" private/SLUS_204.86.rom \
    --source src/round2_hard.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round3_0.o" private/SLUS_204.86.rom \
    --source src/round3_0.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round3_1.o" private/SLUS_204.86.rom \
    --source src/round3_1.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round3_2.o" private/SLUS_204.86.rom \
    --source src/round3_2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round3_3.o" private/SLUS_204.86.rom \
    --source src/round3_3.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_tiny_leaves.o" private/SLUS_204.86.rom \
    --source src/grok_tiny_leaves.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_tiny2.o" private/SLUS_204.86.rom \
    --source src/grok_tiny2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0014.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0014.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0014.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0014.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0015.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0015.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_size40.o" private/SLUS_204.86.rom \
    --source src/grok_size40.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_002c.o" private/SLUS_204.86.rom \
    --source src/grok_r2_002c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_tail_r2.o" private/SLUS_204.86.rom \
    --source src/grok_tail_r2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_size54.o" private/SLUS_204.86.rom \
    --source src/grok_size54.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w4_sz54.o" private/SLUS_204.86.rom \
    --source src/grok_w4_sz54.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001f.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001f.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz58.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz58.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sz58.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sz58.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sz70.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sz70.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sz78.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sz78.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sz80.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sz80.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sz88.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sz88.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_003c.o" private/SLUS_204.86.rom \
    --source src/grok_r2_003c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0012.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0012.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round4_0.o" private/SLUS_204.86.rom \
    --source src/round4_0.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/round4_3.o" private/SLUS_204.86.rom \
    --source src/round4_3.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_round4_2fix.o" private/SLUS_204.86.rom \
    --source src/grok_round4_2fix.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_dup_clusters.o" private/SLUS_204.86.rom \
    --source src/grok_dup_clusters.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0020.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0020.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0018.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0018.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0018.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0018.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0018.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0018.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0019.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0019.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_001c.o" private/SLUS_204.86.rom \
    --source src/grok_r2_001c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0038.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0030.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0030.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0030.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0030.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_001.o" private/SLUS_204.86.rom \
    --source src/grok_r1_001.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_001gp.o" private/SLUS_204.86.rom \
    --source src/grok_r1_001gp.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0010.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0010.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0010_30.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0010_30.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0038.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0028.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r3_0028.o" private/SLUS_204.86.rom \
    --source src/grok_r3_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r1_0040.o" private/SLUS_204.86.rom \
    --source src/grok_r1_0040.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0034.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0034.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_dispatch_r2.o" private/SLUS_204.86.rom \
    --source src/grok_dispatch_r2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_size60.o" private/SLUS_204.86.rom \
    --source src/grok_size60.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_fpu_r2.o" private/SLUS_204.86.rom \
    --source src/grok_fpu_r2.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_fpu.o" private/SLUS_204.86.rom \
    --source src/grok_w3_fpu.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_r2_0020.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0020.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_001c.o" private/SLUS_204.86.rom \
    --source src/grok_w3_001c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001d.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001d.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0016.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0016.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0017.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0017.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/state_dispatch_00176DC0.o" private/SLUS_204.86.rom \
    --source src/state_dispatch_00176DC0.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0022.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0022.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_001a.o" private/SLUS_204.86.rom \
    --source src/grok_w3_001a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_002c.o" private/SLUS_204.86.rom \
    --source src/grok_w3_002c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_001e.o" private/SLUS_204.86.rom \
    --source src/grok_w3_001e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0020.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0020.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0026.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0026.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_002e.o" private/SLUS_204.86.rom \
    --source src/grok_w3_002e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0030.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0030.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0031.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0031.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0038.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_pairs.o" private/SLUS_204.86.rom \
    --source src/grok_w3_pairs.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_pairs.o" private/SLUS_204.86.rom \
    --source src/grok_w6_pairs.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_001c.o" private/SLUS_204.86.rom \
    --source src/grok_w7_001c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w4_sz80.o" private/SLUS_204.86.rom \
    --source src/grok_w4_sz80.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w4_szc0.o" private/SLUS_204.86.rom \
    --source src/grok_w4_szc0.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0035.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0035.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_003c.o" private/SLUS_204.86.rom \
    --source src/grok_w3_003c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_003e.o" private/SLUS_204.86.rom \
    --source src/grok_w3_003e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz0c.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz0c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz54.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz54.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003f.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_003f.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_003f.o" private/SLUS_204.86.rom \
    --source src/grok_w3_003f.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_sz68.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz68.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0041.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0041.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0015.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0015.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0019.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0019.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001a.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001e.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0012.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0012.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0014.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0014.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0016.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0016.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0018.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0018.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001b.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001b.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_001c.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0017.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0017.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0024.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_sz54.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz54.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0020.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0020.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_002c.o" private/SLUS_204.86.rom \
    --source src/grok_w5_002c.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0030.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0030.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_002a.o" private/SLUS_204.86.rom \
    --source src/grok_w5_002a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_002a.o" private/SLUS_204.86.rom \
    --source src/grok_w6_002a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0024.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_002e.o" private/SLUS_204.86.rom \
    --source src/grok_w5_002e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0038.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0038.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_003a.o" private/SLUS_204.86.rom \
    --source src/grok_w7_003a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0026.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0026.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0034.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0034.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0028.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_0028.o" private/SLUS_204.86.rom \
    --source src/grok_w6_0028.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_sz40.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz40.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_sz80.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz80.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_szc0.o" private/SLUS_204.86.rom \
    --source src/grok_w5_szc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_neg.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_neg.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_neg.o" private/SLUS_204.86.rom \
    --source src/grok_w5_neg.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0020.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_0020.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0020.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0020.c
PYTHON="$PYTHON" tools/compile_matching_data.sh
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_003a.o" private/SLUS_204.86.rom \
    --source src/grok_w3_003a.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0013.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0013.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0013.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0013.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0022.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0022.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0022.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0022.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_003c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_003c.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_003c.o" private/SLUS_204.86.rom \
    --source src/grok_w5_003c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0032.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0032.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0032.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0032.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_gp.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_gp.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_gp.o" private/SLUS_204.86.rom \
    --source src/grok_w5_gp.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_disp.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_disp.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_disp.o" private/SLUS_204.86.rom \
    --source src/grok_w5_disp.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_003e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_003e.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_003e.o" private/SLUS_204.86.rom \
    --source src/grok_w5_003e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w5_fpu.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_fpu.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_fpu.o" private/SLUS_204.86.rom \
    --source src/grok_w5_fpu.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/float_clamp.o" private/SLUS_204.86.rom \
    --source src/float_clamp.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/physics_floor_clamp.o" private/SLUS_204.86.rom \
    --source src/physics_floor_clamp.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/physics_timer_inc.o" private/SLUS_204.86.rom \
    --source src/physics_timer_inc.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/state_pair_dispatch.o" private/SLUS_204.86.rom \
    --source src/state_pair_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/state_pair_zero_dispatch.o" private/SLUS_204.86.rom \
    --source src/state_pair_zero_dispatch.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/nibble_state_dispatch.o" private/SLUS_204.86.rom \
    --source src/nibble_state_dispatch.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_0030.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w6_0030.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_0030.o" private/SLUS_204.86.rom \
    --source src/grok_w6_0030.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_neg.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w6_neg.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_neg.o" private/SLUS_204.86.rom \
    --source src/grok_w6_neg.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_0036.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w6_0036.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_0036.o" private/SLUS_204.86.rom \
    --source src/grok_w6_0036.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w6_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w6_0018.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w6_0018.o" private/SLUS_204.86.rom \
    --source src/grok_w6_0018.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_002c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_002c.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_002c.o" private/SLUS_204.86.rom \
    --source src/grok_w7_002c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_evt.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_evt.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_evt.o" private/SLUS_204.86.rom \
    --source src/grok_w7_evt.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_sza0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_sza0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_sza0.o" private/SLUS_204.86.rom \
    --source src/grok_w7_sza0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0032.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0032.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0032.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0032.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_001a.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_001a.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_001a.o" private/SLUS_204.86.rom \
    --source src/grok_w7_001a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_003c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_003c.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_003c.o" private/SLUS_204.86.rom \
    --source src/grok_w7_003c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_002e.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_002e.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_002e.o" private/SLUS_204.86.rom \
    --source src/grok_w7_002e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_002e2.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_002e2.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_002e2.o" private/SLUS_204.86.rom \
    --source src/grok_w7_002e2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_evt2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_evt2.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_evt2.o" private/SLUS_204.86.rom \
    --source src/grok_w7_evt2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0022.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0022.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0022.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0022.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_003e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_003e.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_003e.o" private/SLUS_204.86.rom \
    --source src/grok_w7_003e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0034.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0034.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0034.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0034.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_phys.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_phys.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_phys.o" private/SLUS_204.86.rom \
    --source src/grok_w7_phys.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0026.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0026.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0026.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0026.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupclones_sdt8.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dupclones_sdt8.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupclones_sdt8.o" private/SLUS_204.86.rom \
    --source src/dupclones_sdt8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupclones_std.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupclones_std.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupclones_std.o" private/SLUS_204.86.rom \
    --source src/dupclones_std.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_001e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_001e.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_001e.o" private/SLUS_204.86.rom \
    --source src/grok_w7_001e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0028.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_0028.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0028.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0028.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_record_actions.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/grok_w7_record_actions.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_record_actions.o" private/SLUS_204.86.rom \
    --source src/grok_w7_record_actions.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_evt3.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_evt3.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_evt3.o" private/SLUS_204.86.rom \
    --source src/grok_w7_evt3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_0036.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_0036.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0036.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0036.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_gate100.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_gate100.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_gate100.o" private/SLUS_204.86.rom \
    --source src/dupcluster_gate100.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_gate96.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_gate96.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_gate96.o" private/SLUS_204.86.rom \
    --source src/dupcluster_gate96.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_gate92c.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_gate92c.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_gate92c.o" private/SLUS_204.86.rom \
    --source src/dupcluster_gate92c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_gate92.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_gate92.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_gate92.o" private/SLUS_204.86.rom \
    --source src/dupcluster_gate92.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_gate96b.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_gate96b.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_gate96b.o" private/SLUS_204.86.rom \
    --source src/dupcluster_gate96b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_0013C730.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_0013C730.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_0013C730.o" private/SLUS_204.86.rom \
    --source src/dupcluster_0013C730.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_00177CE0.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_00177CE0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_00177CE0.o" private/SLUS_204.86.rom \
    --source src/dupcluster_00177CE0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_00178DA0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_00178DA0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_00178DA0.o" private/SLUS_204.86.rom \
    --source src/dupcluster_00178DA0.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/dupcluster_00191F50.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_00191F50.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_00191F50.o" private/SLUS_204.86.rom \
    --source src/dupcluster_00191F50.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_001519E0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_001519E0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_001519E0.o" private/SLUS_204.86.rom \
    --source src/dupcluster_001519E0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_003ABFE0.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_003ABFE0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_003ABFE0.o" private/SLUS_204.86.rom \
    --source src/dupcluster_003ABFE0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_001863F0.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_001863F0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_001863F0.o" private/SLUS_204.86.rom \
    --source src/dupcluster_001863F0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_00278F50.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/dupcluster_00278F50.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_00278F50.o" private/SLUS_204.86.rom \
    --source src/dupcluster_00278F50.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_00184110.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_00184110.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_00184110.o" private/SLUS_204.86.rom \
    --source src/dupcluster_00184110.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dupcluster_001A9650.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dupcluster_001A9650.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dupcluster_001A9650.o" private/SLUS_204.86.rom \
    --source src/dupcluster_001A9650.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_phys2.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w7_phys2.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_phys2.o" private/SLUS_204.86.rom \
    --source src/grok_w7_phys2.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_0040.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_0040.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_0040.o" private/SLUS_204.86.rom \
    --source src/grok_w7_0040.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/frame_scale_updates.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/frame_scale_updates.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/frame_scale_updates.o" private/SLUS_204.86.rom \
    --source src/frame_scale_updates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/object_pool.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/object_pool.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/object_pool.o" private/SLUS_204.86.rom \
    --source src/object_pool.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/move_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/move_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/move_setup.o" private/SLUS_204.86.rom \
    --source src/move_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/ground_reset.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/ground_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/ground_reset.o" private/SLUS_204.86.rom \
    --source src/ground_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/motion_start.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/motion_start.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/motion_start.o" private/SLUS_204.86.rom \
    --source src/motion_start.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/deferred_move_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/deferred_move_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/deferred_move_setup.o" private/SLUS_204.86.rom \
    --source src/deferred_move_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/air_step.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/air_step.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/air_step.o" private/SLUS_204.86.rom \
    --source src/air_step.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_frames.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/animation_frames.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/animation_frames.o" private/SLUS_204.86.rom \
    --source src/animation_frames.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/accepted_transitions.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/accepted_transitions.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/accepted_transitions.o" private/SLUS_204.86.rom \
    --source src/accepted_transitions.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/priority_dispatch.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/priority_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/priority_dispatch.o" private/SLUS_204.86.rom \
    --source src/priority_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dependent_spawns.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dependent_spawns.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dependent_spawns.o" private/SLUS_204.86.rom \
    --source src/dependent_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/system_select.c -c -lang c $MATCH_FLAGS -o "$BUILD/system_select.o"
"$PYTHON" tools/verify_object.py "$BUILD/system_select.o" private/SLUS_204.86.rom --source src/system_select.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/command_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/command_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/command_gates.o" private/SLUS_204.86.rom --source src/command_gates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/record_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/record_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/record_gates.o" private/SLUS_204.86.rom --source src/record_gates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/one_shot_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/one_shot_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/one_shot_gates.o" private/SLUS_204.86.rom --source src/one_shot_gates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/enabled_one_shot.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/enabled_one_shot.o"
"$PYTHON" tools/verify_object.py "$BUILD/enabled_one_shot.o" private/SLUS_204.86.rom --source src/enabled_one_shot.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/record_flags.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/record_flags.o"
"$PYTHON" tools/verify_object.py "$BUILD/record_flags.o" private/SLUS_204.86.rom --source src/record_flags.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/command_reset.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/command_reset.o"
"$PYTHON" tools/verify_object.py "$BUILD/command_reset.o" private/SLUS_204.86.rom --source src/command_reset.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/state_first_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_first_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_first_gates.o" private/SLUS_204.86.rom --source src/state_first_gates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/parent_state_dispatch.c -c -lang c $MATCH_FLAGS -o "$BUILD/parent_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/parent_state_dispatch.o" private/SLUS_204.86.rom --source src/parent_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pending_commands.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/pending_commands.o"
"$PYTHON" tools/verify_object.py "$BUILD/pending_commands.o" private/SLUS_204.86.rom --source src/pending_commands.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/frame_callbacks.c -c -lang c $MATCH_FLAGS -o "$BUILD/frame_callbacks.o"
"$PYTHON" tools/verify_object.py "$BUILD/frame_callbacks.o" private/SLUS_204.86.rom --source src/frame_callbacks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/frame_activation.c -c -lang c $MATCH_FLAGS -o "$BUILD/frame_activation.o"
"$PYTHON" tools/verify_object.py "$BUILD/frame_activation.o" private/SLUS_204.86.rom --source src/frame_activation.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/air_late_setup.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/air_late_setup.o"
"$PYTHON" tools/verify_object.py "$BUILD/air_late_setup.o" private/SLUS_204.86.rom --source src/air_late_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/angle_initializers.c -c -lang c $MATCH_FLAGS -o "$BUILD/angle_initializers.o"
"$PYTHON" tools/verify_object.py "$BUILD/angle_initializers.o" private/SLUS_204.86.rom --source src/angle_initializers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/follow_layers.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/follow_layers.o"
"$PYTHON" tools/verify_object.py "$BUILD/follow_layers.o" private/SLUS_204.86.rom --source src/follow_layers.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/shared_state_updates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/shared_state_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/shared_state_updates.o" private/SLUS_204.86.rom --source src/shared_state_updates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/init_continue.c -c -lang c $MATCH_FLAGS -o "$BUILD/init_continue.o"
"$PYTHON" tools/verify_object.py "$BUILD/init_continue.o" private/SLUS_204.86.rom --source src/init_continue.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/small_state_controls.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/small_state_controls.o"
"$PYTHON" tools/verify_object.py "$BUILD/small_state_controls.o" private/SLUS_204.86.rom --source src/small_state_controls.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pair_table_copy.c -c -lang c $MATCH_FLAGS -o "$BUILD/pair_table_copy.o"
"$PYTHON" tools/verify_object.py "$BUILD/pair_table_copy.o" private/SLUS_204.86.rom --source src/pair_table_copy.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/parent_state_copy.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/parent_state_copy.o"
"$PYTHON" tools/verify_object.py "$BUILD/parent_state_copy.o" private/SLUS_204.86.rom --source src/parent_state_copy.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/counter_state_controls.c -c -lang c $MATCH_FLAGS -o "$BUILD/counter_state_controls.o"
"$PYTHON" tools/verify_object.py "$BUILD/counter_state_controls.o" private/SLUS_204.86.rom --source src/counter_state_controls.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/menu_drift.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/menu_drift.o"
"$PYTHON" tools/verify_object.py "$BUILD/menu_drift.o" private/SLUS_204.86.rom --source src/menu_drift.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/signed_state_dispatch.c -c -lang c $MATCH_FLAGS -o "$BUILD/signed_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/signed_state_dispatch.o" private/SLUS_204.86.rom --source src/signed_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/timed_flag_callback.c -c -lang c $MATCH_FLAGS -o "$BUILD/timed_flag_callback.o"
"$PYTHON" tools/verify_object.py "$BUILD/timed_flag_callback.o" private/SLUS_204.86.rom --source src/timed_flag_callback.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/float_callbacks.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/float_callbacks.o"
"$PYTHON" tools/verify_object.py "$BUILD/float_callbacks.o" private/SLUS_204.86.rom --source src/float_callbacks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/height_limits.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/height_limits.o"
"$PYTHON" tools/verify_object.py "$BUILD/height_limits.o" private/SLUS_204.86.rom --source src/height_limits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fade_step.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/fade_step.o"
"$PYTHON" tools/verify_object.py "$BUILD/fade_step.o" private/SLUS_204.86.rom --source src/fade_step.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/float_state_limits.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/float_state_limits.o"
"$PYTHON" tools/verify_object.py "$BUILD/float_state_limits.o" private/SLUS_204.86.rom --source src/float_state_limits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/float_motion_transitions.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/float_motion_transitions.o"
"$PYTHON" tools/verify_object.py "$BUILD/float_motion_transitions.o" private/SLUS_204.86.rom --source src/float_motion_transitions.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/mode_stance_move_setup.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/mode_stance_move_setup.o"
"$PYTHON" tools/verify_object.py "$BUILD/mode_stance_move_setup.o" private/SLUS_204.86.rom --source src/mode_stance_move_setup.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/live_interaction_stance_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/live_interaction_stance_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/live_interaction_stance_gates.o" private/SLUS_204.86.rom --source src/live_interaction_stance_gates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/free_slot_interaction_commits.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/free_slot_interaction_commits.o"
"$PYTHON" tools/verify_object.py "$BUILD/free_slot_interaction_commits.o" private/SLUS_204.86.rom --source src/free_slot_interaction_commits.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/selected_target_interactions.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/selected_target_interactions.o"
"$PYTHON" tools/verify_object.py "$BUILD/selected_target_interactions.o" private/SLUS_204.86.rom --source src/selected_target_interactions.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/live_target_selection.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/live_target_selection.o"
"$PYTHON" tools/verify_object.py "$BUILD/live_target_selection.o" private/SLUS_204.86.rom --source src/live_target_selection.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/child_owner_stance_dispatch.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/child_owner_stance_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/child_owner_stance_dispatch.o" private/SLUS_204.86.rom --source src/child_owner_stance_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/linked_parameter_child_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/linked_parameter_child_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/linked_parameter_child_spawns.o" private/SLUS_204.86.rom --source src/linked_parameter_child_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_angle_child_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_angle_child_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_angle_child_spawns.o" private/SLUS_204.86.rom --source src/owner_angle_child_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/uniform_key_motion_steps.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/uniform_key_motion_steps.o"
"$PYTHON" tools/verify_object.py "$BUILD/uniform_key_motion_steps.o" private/SLUS_204.86.rom --source src/uniform_key_motion_steps.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/live_interaction_phase_commits.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/live_interaction_phase_commits.o"
"$PYTHON" tools/verify_object.py "$BUILD/live_interaction_phase_commits.o" private/SLUS_204.86.rom --source src/live_interaction_phase_commits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/planar_floor_motion.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/planar_floor_motion.o"
"$PYTHON" tools/verify_object.py "$BUILD/planar_floor_motion.o" private/SLUS_204.86.rom --source src/planar_floor_motion.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/directional_target_gates.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/directional_target_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/directional_target_gates.o" private/SLUS_204.86.rom --source src/directional_target_gates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/contact_effect_dispatch.c -c -lang c -O3 -sdatathreshold 32 -o "$BUILD/contact_effect_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/contact_effect_dispatch.o" private/SLUS_204.86.rom --source src/contact_effect_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/unoccupied_stance_mode_commits.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/unoccupied_stance_mode_commits.o"
"$PYTHON" tools/verify_object.py "$BUILD/unoccupied_stance_mode_commits.o" private/SLUS_204.86.rom --source src/unoccupied_stance_mode_commits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_stance_animation_waits.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_stance_animation_waits.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_stance_animation_waits.o" private/SLUS_204.86.rom --source src/owner_stance_animation_waits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/elevated_position_effect_spawns.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/elevated_position_effect_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/elevated_position_effect_spawns.o" private/SLUS_204.86.rom --source src/elevated_position_effect_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/preset_vector_effect_spawns.c -c -lang c -O3 -sdatathreshold 8 -i src/data -o "$BUILD/preset_vector_effect_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/preset_vector_effect_spawns.o" private/SLUS_204.86.rom --source src/preset_vector_effect_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/preset_position_effect_spawns.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/preset_position_effect_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/preset_position_effect_spawns.o" private/SLUS_204.86.rom --source src/preset_position_effect_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/signed_axis_mode_updates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/signed_axis_mode_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/signed_axis_mode_updates.o" private/SLUS_204.86.rom --source src/signed_axis_mode_updates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_generation_dispatch.c -c -lang c -O3 -sdatathreshold 0 -i src/data -o "$BUILD/owner_generation_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_generation_dispatch.o" private/SLUS_204.86.rom --source src/owner_generation_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/positioned_zero_motion_effects.c -c -lang c -O3 -sdatathreshold 8 -i src/data -o "$BUILD/positioned_zero_motion_effects.o"
"$PYTHON" tools/verify_object.py "$BUILD/positioned_zero_motion_effects.o" private/SLUS_204.86.rom --source src/positioned_zero_motion_effects.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/indexed_angle_effect_spawns.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/indexed_angle_effect_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/indexed_angle_effect_spawns.o" private/SLUS_204.86.rom --source src/indexed_angle_effect_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_planar_offset_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_planar_offset_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_planar_offset_spawns.o" private/SLUS_204.86.rom --source src/owner_planar_offset_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/stance_flip_launch_effects.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/stance_flip_launch_effects.o"
"$PYTHON" tools/verify_object.py "$BUILD/stance_flip_launch_effects.o" private/SLUS_204.86.rom --source src/stance_flip_launch_effects.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_generation_child_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_generation_child_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_generation_child_spawns.o" private/SLUS_204.86.rom --source src/owner_generation_child_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/preset_effect_followup_spawns.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/preset_effect_followup_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/preset_effect_followup_spawns.o" private/SLUS_204.86.rom --source src/preset_effect_followup_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_first_floor_commits.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/animation_first_floor_commits.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_first_floor_commits.o" private/SLUS_204.86.rom --source src/animation_first_floor_commits.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_two_parameter_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_two_parameter_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_two_parameter_spawns.o" private/SLUS_204.86.rom --source src/owner_two_parameter_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/countdown_position_restores.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/countdown_position_restores.o"
"$PYTHON" tools/verify_object.py "$BUILD/countdown_position_restores.o" private/SLUS_204.86.rom --source src/countdown_position_restores.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_phase_countdown_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_phase_countdown_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_phase_countdown_gates.o" private/SLUS_204.86.rom --source src/owner_phase_countdown_gates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_animation_selector_sync.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_animation_selector_sync.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_animation_selector_sync.o" private/SLUS_204.86.rom --source src/owner_animation_selector_sync.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/global_phase_frame_hooks.c -c -lang c -O3 -sdatathreshold 8 -i src/data -o "$BUILD/global_phase_frame_hooks.o"
"$PYTHON" tools/verify_object.py "$BUILD/global_phase_frame_hooks.o" private/SLUS_204.86.rom --source src/global_phase_frame_hooks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_stance_state_dispatch.c -c -lang c -O3 -sdatathreshold 8 -i src/data -o "$BUILD/owner_stance_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_stance_state_dispatch.o" private/SLUS_204.86.rom --source src/owner_stance_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/side_inhibit_state_dispatch.c -c -lang c -O3 -sdatathreshold 8 -i src/data -o "$BUILD/side_inhibit_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/side_inhibit_state_dispatch.o" private/SLUS_204.86.rom --source src/side_inhibit_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/inhibit_owner_phase_gates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/inhibit_owner_phase_gates.o"
"$PYTHON" tools/verify_object.py "$BUILD/inhibit_owner_phase_gates.o" private/SLUS_204.86.rom --source src/inhibit_owner_phase_gates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/inhibit_state_controls.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/inhibit_state_controls.o"
"$PYTHON" tools/verify_object.py "$BUILD/inhibit_state_controls.o" private/SLUS_204.86.rom --source src/inhibit_state_controls.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/inhibit_owner_motion_sync.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/inhibit_owner_motion_sync.o"
"$PYTHON" tools/verify_object.py "$BUILD/inhibit_owner_motion_sync.o" private/SLUS_204.86.rom --source src/inhibit_owner_motion_sync.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/inhibit_character_state_dispatch.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/inhibit_character_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/inhibit_character_state_dispatch.o" private/SLUS_204.86.rom --source src/inhibit_character_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/linked_child_list_destroy.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/linked_child_list_destroy.o"
"$PYTHON" tools/verify_object.py "$BUILD/linked_child_list_destroy.o" private/SLUS_204.86.rom --source src/linked_child_list_destroy.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/fixed_entry_updates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/fixed_entry_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/fixed_entry_updates.o" private/SLUS_204.86.rom --source src/fixed_entry_updates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/entry_group_updates.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/entry_group_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/entry_group_updates.o" private/SLUS_204.86.rom --source src/entry_group_updates.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/indexed_owner_child_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/indexed_owner_child_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/indexed_owner_child_spawns.o" private/SLUS_204.86.rom --source src/indexed_owner_child_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_facing_animation_gate.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_facing_animation_gate.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_facing_animation_gate.o" private/SLUS_204.86.rom --source src/owner_facing_animation_gate.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/owner_state_snapshot.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_state_snapshot.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_snapshot.o" private/SLUS_204.86.rom --source src/owner_state_snapshot.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_generation_parameter_spawns.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_generation_parameter_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_generation_parameter_spawns.o" private/SLUS_204.86.rom --source src/owner_generation_parameter_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/fixed_launch_effect_initializers.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/fixed_launch_effect_initializers.o"
"$PYTHON" tools/verify_object.py "$BUILD/fixed_launch_effect_initializers.o" private/SLUS_204.86.rom --source src/fixed_launch_effect_initializers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_substate_animation_entry.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_substate_animation_entry.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_substate_animation_entry.o" private/SLUS_204.86.rom --source src/owner_substate_animation_entry.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/positioned_timed_effect_spawns.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/positioned_timed_effect_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/positioned_timed_effect_spawns.o" private/SLUS_204.86.rom --source src/positioned_timed_effect_spawns.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/positioned_unit_scale_spawns.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/positioned_unit_scale_spawns.o"
"$PYTHON" tools/verify_object.py "$BUILD/positioned_unit_scale_spawns.o" private/SLUS_204.86.rom --source src/positioned_unit_scale_spawns.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_small_wrappers.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_small_wrappers.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_small_wrappers.o" private/SLUS_204.86.rom --source src/luna_a_small_wrappers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/positioned_motion_constants.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/positioned_motion_constants.o"
"$PYTHON" tools/verify_object.py "$BUILD/positioned_motion_constants.o" private/SLUS_204.86.rom --source src/positioned_motion_constants.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/negative_short_transition.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/negative_short_transition.o"
"$PYTHON" tools/verify_object.py "$BUILD/negative_short_transition.o" private/SLUS_204.86.rom --source src/negative_short_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_state_transfers.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/animation_state_transfers.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_state_transfers.o" private/SLUS_204.86.rom --source src/animation_state_transfers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/transition_sequence_recoveries.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/transition_sequence_recoveries.o"
"$PYTHON" tools/verify_object.py "$BUILD/transition_sequence_recoveries.o" private/SLUS_204.86.rom --source src/transition_sequence_recoveries.c

"$WIBO" "$SNCPP" -P src/sn_runtime_leaves.c "$BUILD/sn_runtime_leaves.i"
"$WIBO" "$SNCC1" "$BUILD/sn_runtime_leaves.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sn_runtime_leaves.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sn_runtime_leaves.o" "$BUILD/sn_runtime_leaves.s"
"$PYTHON" tools/verify_object.py "$BUILD/sn_runtime_leaves.o" private/SLUS_204.86.rom --source src/sn_runtime_leaves.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/runtime_shift.c -c -lang c -O2 -sdatathreshold 0 -o "$BUILD/runtime_shift.o"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_shift.o" private/SLUS_204.86.rom --source src/runtime_shift.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/conditional_mode_transition.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/conditional_mode_transition.o"
"$PYTHON" tools/verify_object.py "$BUILD/conditional_mode_transition.o" private/SLUS_204.86.rom --source src/conditional_mode_transition.c

# Fixed-scale effect callbacks: state variants, follow-up calls, and choices.
for unit in effect_state_callbacks effect_followup_callbacks; do
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "src/$unit.c" -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/effect_choice_callbacks.c -c -lang c -O4 -Op -sdatathreshold 8 \
    -o "$BUILD/effect_choice_callbacks.o"
"$PYTHON" tools/verify_object.py "$BUILD/effect_choice_callbacks.o" private/SLUS_204.86.rom \
    --source src/effect_choice_callbacks.c

# Input-state gates and animation position callbacks.
for unit in height_input_gates ground_input_gates mode_input_gates animation_position_callbacks ground_transition_gates elevated_mode_input_gates animation_numbered_effects wrapped_degree_phases; do
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "src/$unit.c" -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/ordered_input_checks.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/ordered_input_checks.o"
"$PYTHON" tools/verify_object.py "$BUILD/ordered_input_checks.o" private/SLUS_204.86.rom \
    --source src/ordered_input_checks.c

# Scale integration, relative-record walks, and animation state handlers.
for unit in uniform_scale_steps animation_spawn_positions relative_record_walks relative_scale_interpolation; do
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "src/$unit.c" -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done
for unit in owner_state_dispatch indexed_scale_steps three_axis_key_steps animation_nibble_dispatch filtered_interaction_dispatch indexed_child_parameters timed_child_parameters stance_restore_transitions completed_owner_dispatch owner_depth_dispatch airborne_landing_steps vertical_landing_animations planar_motion_resets mode_motion_updates table_transition_input_gates interaction_stance_resets pending_phase_events descending_event_contacts airborne_event_motion; do
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "src/$unit.c" -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/conditional_animation_updates.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/conditional_animation_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/conditional_animation_updates.o" private/SLUS_204.86.rom \
    --source src/conditional_animation_updates.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/clamped_state_dispatch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/clamped_state_dispatch.o"
"$PYTHON" tools/verify_object.py "$BUILD/clamped_state_dispatch.o" private/SLUS_204.86.rom \
    --source src/clamped_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/effect_fade_states.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/effect_fade_states.o"
"$PYTHON" tools/verify_object.py "$BUILD/effect_fade_states.o" private/SLUS_204.86.rom \
    --source src/effect_fade_states.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/accepted_transition_resets.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/accepted_transition_resets.o"
"$PYTHON" tools/verify_object.py "$BUILD/accepted_transition_resets.o" private/SLUS_204.86.rom \
    --source src/accepted_transition_resets.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_displacement_events.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/animation_displacement_events.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_displacement_events.o" private/SLUS_204.86.rom \
    --source src/animation_displacement_events.c

for unit in live_owner_stance_resets accepted_interaction_latches owner_threshold_latches latched_interaction_stances unoccupied_interaction_stances; do
    MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
        "src/$unit.c" -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done

for unit in global_phase_events global_phase_animation_steps; do
    MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
        "src/$unit.c" -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/$unit.o"
    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" private/SLUS_204.86.rom \
        --source "src/$unit.c"
done

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/launch_record_initializers.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/launch_record_initializers.o"
"$PYTHON" tools/verify_object.py "$BUILD/launch_record_initializers.o" private/SLUS_204.86.rom --source src/launch_record_initializers.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/state_reference_check.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_reference_check.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_reference_check.o" private/SLUS_204.86.rom --source src/state_reference_check.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/motion_speed_transition.c -c -lang c -O4 -Op -sdatathreshold 8 -o "$BUILD/motion_speed_transition.o"
"$PYTHON" tools/verify_object.py "$BUILD/motion_speed_transition.o" private/SLUS_204.86.rom --source src/motion_speed_transition.c

"$WIBO" "$SNCPP" -P src/runtime_state_slots.c "$BUILD/runtime_state_slots.i"
"$WIBO" "$SNCC1" "$BUILD/runtime_state_slots.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/runtime_state_slots.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_state_slots.o" "$BUILD/runtime_state_slots.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_state_slots.o" private/SLUS_204.86.rom --source src/runtime_state_slots.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_gp_tail.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/luna_a_gp_tail.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_gp_tail.o" private/SLUS_204.86.rom --source src/luna_a_gp_tail.c

"$WIBO" "$SNCPP" -P src/set_runtime_option_fields_0040ADF0.c \
    "$BUILD/set_runtime_option_fields_0040ADF0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/set_runtime_option_fields_0040ADF0.i" \
    "$BUILD/set_runtime_option_fields_0040ADF0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_option_fields_0040ADF0.o" \
    "$BUILD/set_runtime_option_fields_0040ADF0.s"
"$PYTHON" tools/verify_object.py "$BUILD/set_runtime_option_fields_0040ADF0.o" \
    private/SLUS_204.86.rom --source src/set_runtime_option_fields_0040ADF0.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_parameter_callback_0040AF58.c \
    "$BUILD/dispatch_runtime_parameter_callback_0040AF58.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_parameter_callback_0040AF58.i" \
    "$BUILD/dispatch_runtime_parameter_callback_0040AF58.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_parameter_callback_0040AF58.o" \
    "$BUILD/dispatch_runtime_parameter_callback_0040AF58.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_parameter_callback_0040AF58.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_parameter_callback_0040AF58.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_message_004098A8.c \
    "$BUILD/dispatch_runtime_message_004098A8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_message_004098A8.i" \
    "$BUILD/dispatch_runtime_message_004098A8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_message_004098A8.o" \
    "$BUILD/dispatch_runtime_message_004098A8.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_message_004098A8.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_message_004098A8.c

"$WIBO" "$SNCPP" -P src/set_runtime_status_mode_0040CA70.c \
    "$BUILD/set_runtime_status_mode_0040CA70.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/set_runtime_status_mode_0040CA70.i" \
    "$BUILD/set_runtime_status_mode_0040CA70.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_status_mode_0040CA70.o" \
    "$BUILD/set_runtime_status_mode_0040CA70.s"
"$PYTHON" tools/verify_object.py "$BUILD/set_runtime_status_mode_0040CA70.o" \
    private/SLUS_204.86.rom --source src/set_runtime_status_mode_0040CA70.c

"$WIBO" "$SNCPP" -P src/release_runtime_record_handle_00408EA0.c \
    "$BUILD/release_runtime_record_handle_00408EA0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/release_runtime_record_handle_00408EA0.i" \
    "$BUILD/release_runtime_record_handle_00408EA0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/release_runtime_record_handle_00408EA0.o" \
    "$BUILD/release_runtime_record_handle_00408EA0.s"
"$PYTHON" tools/verify_object.py "$BUILD/release_runtime_record_handle_00408EA0.o" \
    private/SLUS_204.86.rom --source src/release_runtime_record_handle_00408EA0.c

"$WIBO" "$SNCPP" -P src/indexed_runtime_accessors.c "$BUILD/indexed_runtime_accessors.i"
"$WIBO" "$SNCC1" "$BUILD/indexed_runtime_accessors.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/indexed_runtime_accessors.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/indexed_runtime_accessors.o" "$BUILD/indexed_runtime_accessors.s"
"$PYTHON" tools/verify_object.py "$BUILD/indexed_runtime_accessors.o" private/SLUS_204.86.rom --source src/indexed_runtime_accessors.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_record_adjustment.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/luna_a_record_adjustment.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_record_adjustment.o" private/SLUS_204.86.rom --source src/luna_a_record_adjustment.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/luna_a_status_checks.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_status_checks.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_status_checks.o" private/SLUS_204.86.rom --source src/luna_a_status_checks.c

"$WIBO" "$SNCPP" -P src/small_runtime_initializers.c "$BUILD/small_runtime_initializers.i"
"$WIBO" "$SNCC1" "$BUILD/small_runtime_initializers.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/small_runtime_initializers.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/small_runtime_initializers.o" "$BUILD/small_runtime_initializers.s"
"$PYTHON" tools/verify_object.py "$BUILD/small_runtime_initializers.o" private/SLUS_204.86.rom --source src/small_runtime_initializers.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_signed_offset.c -c -lang c -O4 -Op -sdatathreshold 0 \
    -o "$BUILD/luna_a_signed_offset.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_signed_offset.o" private/SLUS_204.86.rom --source src/luna_a_signed_offset.c

"$WIBO" "$SNCPP" -P src/indexed_pointer_accessors.c "$BUILD/indexed_pointer_accessors.i"
"$WIBO" "$SNCC1" "$BUILD/indexed_pointer_accessors.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/indexed_pointer_accessors.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/indexed_pointer_accessors.o" "$BUILD/indexed_pointer_accessors.s"
"$PYTHON" tools/verify_object.py "$BUILD/indexed_pointer_accessors.o" private/SLUS_204.86.rom --source src/indexed_pointer_accessors.c

"$WIBO" "$SNCPP" -P src/ee_math_wrappers.c "$BUILD/ee_math_wrappers.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/ee_math_wrappers.i" "$BUILD/ee_math_wrappers.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee_math_wrappers.o" "$BUILD/ee_math_wrappers.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee_math_wrappers.o" private/SLUS_204.86.rom --source src/ee_math_wrappers.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_compare_positions.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_compare_positions.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_compare_positions.o" private/SLUS_204.86.rom --source src/luna_a_compare_positions.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_global_flag_guard.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/luna_a_global_flag_guard.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_global_flag_guard.o" private/SLUS_204.86.rom --source src/luna_a_global_flag_guard.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_object_threshold.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_object_threshold.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_object_threshold.o" private/SLUS_204.86.rom --source src/luna_a_object_threshold.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_mask_lookup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_mask_lookup.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_mask_lookup.o" private/SLUS_204.86.rom --source src/luna_a_mask_lookup.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_state_sync.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/luna_a_state_sync.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_state_sync.o" private/SLUS_204.86.rom --source src/luna_a_state_sync.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_effect_initializer.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_effect_initializer.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_effect_initializer.o" private/SLUS_204.86.rom --source src/luna_a_effect_initializer.c

"$WIBO" "$SNCPP" -P src/ee96_scalar_thunks.c "$BUILD/ee96_scalar_thunks.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/ee96_scalar_thunks.i" "$BUILD/ee96_scalar_thunks.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_scalar_thunks.o" "$BUILD/ee96_scalar_thunks.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_scalar_thunks.o" private/SLUS_204.86.rom --source src/ee96_scalar_thunks.c

"$WIBO" "$SNCPP" -P src/ee96_constant_thunks.c "$BUILD/ee96_constant_thunks.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_constant_thunks.i" "$BUILD/ee96_constant_thunks.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_constant_thunks.o" "$BUILD/ee96_constant_thunks.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_constant_thunks.o" private/SLUS_204.86.rom --source src/ee96_constant_thunks.c

"$WIBO" "$SNCPP" -P src/ee96_callback_thunks.c "$BUILD/ee96_callback_thunks.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_callback_thunks.i" "$BUILD/ee96_callback_thunks.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_callback_thunks.o" "$BUILD/ee96_callback_thunks.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_callback_thunks.o" private/SLUS_204.86.rom --source src/ee96_callback_thunks.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_global_defaults.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_global_defaults.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_global_defaults.o" private/SLUS_204.86.rom --source src/luna_a_global_defaults.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_conditional_callbacks.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_conditional_callbacks.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_conditional_callbacks.o" private/SLUS_204.86.rom --source src/luna_a_conditional_callbacks.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_callback_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/luna_a_callback_setup.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_callback_setup.o" private/SLUS_204.86.rom --source src/luna_a_callback_setup.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_motion_update.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_motion_update.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_motion_update.o" private/SLUS_204.86.rom --source src/luna_a_motion_update.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_particle_initializer.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/luna_a_particle_initializer.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_particle_initializer.o" private/SLUS_204.86.rom --source src/luna_a_particle_initializer.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_secondary_particle_initializer.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_secondary_particle_initializer.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_secondary_particle_initializer.o" private/SLUS_204.86.rom --source src/luna_a_secondary_particle_initializer.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/luna_a_basic_particle_initializer.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/luna_a_basic_particle_initializer.o"
"$PYTHON" tools/verify_object.py "$BUILD/luna_a_basic_particle_initializer.o" private/SLUS_204.86.rom --source src/luna_a_basic_particle_initializer.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/matrix_multiply_003F3C40.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/matrix_multiply_003F3C40.o"
"$PYTHON" tools/verify_object.py "$BUILD/matrix_multiply_003F3C40.o" private/SLUS_204.86.rom --source src/matrix_multiply_003F3C40.c

"$WIBO" "$SNCPP" -P src/ee96_register_callback_003FB108.c "$BUILD/ee96_register_callback_003FB108.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/ee96_register_callback_003FB108.i" "$BUILD/ee96_register_callback_003FB108.s"
"$GNUAS" -EL -march=r5900 -mabi=eabi -G8 -o "$BUILD/ee96_register_callback_003FB108.o" "$BUILD/ee96_register_callback_003FB108.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_register_callback_003FB108.o" private/SLUS_204.86.rom --source src/ee96_register_callback_003FB108.c

"$WIBO" "$SNCPP" -P src/ee96_cleanup_thunks.c "$BUILD/ee96_cleanup_thunks.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_cleanup_thunks.i" "$BUILD/ee96_cleanup_thunks.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_cleanup_thunks.o" "$BUILD/ee96_cleanup_thunks.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_cleanup_thunks.o" private/SLUS_204.86.rom --source src/ee96_cleanup_thunks.c

"$WIBO" "$SNCPP" -P src/ee96_string_thunk.c "$BUILD/ee96_string_thunk.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_string_thunk.i" "$BUILD/ee96_string_thunk.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_string_thunk.o" "$BUILD/ee96_string_thunk.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_string_thunk.o" private/SLUS_204.86.rom --source src/ee96_string_thunk.c

"$WIBO" "$SNCPP" -P src/ee96_validation_thunk.c "$BUILD/ee96_validation_thunk.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_validation_thunk.i" "$BUILD/ee96_validation_thunk.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_validation_thunk.o" "$BUILD/ee96_validation_thunk.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_validation_thunk.o" private/SLUS_204.86.rom --source src/ee96_validation_thunk.c

"$WIBO" "$SNCPP" -P src/ee96_string_chain.c "$BUILD/ee96_string_chain.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/ee96_string_chain.i" "$BUILD/ee96_string_chain.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/ee96_string_chain.o" "$BUILD/ee96_string_chain.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_string_chain.o" private/SLUS_204.86.rom --source src/ee96_string_chain.c

"$WIBO" "$SNCPP" -P src/sdk_random_number_0011F5D8.c "$BUILD/sdk_random_number_0011F5D8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_random_number_0011F5D8.i" "$BUILD/sdk_random_number_0011F5D8.s"
"$GNUAS" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/sdk_random_number_0011F5D8.o" "$BUILD/sdk_random_number_0011F5D8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_random_number_0011F5D8.o" private/SLUS_204.86.rom --source src/sdk_random_number_0011F5D8.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/vector_frame_compare_004148C0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/vector_frame_compare_004148C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/vector_frame_compare_004148C0.o" private/SLUS_204.86.rom --source src/vector_frame_compare_004148C0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/vector_frame_store_004149D0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/vector_frame_store_004149D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/vector_frame_store_004149D0.o" private/SLUS_204.86.rom --source src/vector_frame_store_004149D0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/vector_frame_reset_00414A40.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/vector_frame_reset_00414A40.o"
"$PYTHON" tools/verify_object.py "$BUILD/vector_frame_reset_00414A40.o" private/SLUS_204.86.rom --source src/vector_frame_reset_00414A40.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/tim2_header_writer_00416290.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/tim2_header_writer_00416290.o"
"$PYTHON" tools/verify_object.py "$BUILD/tim2_header_writer_00416290.o" private/SLUS_204.86.rom --source src/tim2_header_writer_00416290.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_words_00423AA0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/append_words_00423AA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_words_00423AA0.o" private/SLUS_204.86.rom --source src/append_words_00423AA0.c

"$WIBO" "$SNCPP" -P src/address_remap_00102520.c "$BUILD/address_remap_00102520.i"
"$WIBO" "$SNCC1" "$BUILD/address_remap_00102520.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/address_remap_00102520.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/address_remap_00102520.o" "$BUILD/address_remap_00102520.s"
"$PYTHON" tools/verify_object.py "$BUILD/address_remap_00102520.o" private/SLUS_204.86.rom --source src/address_remap_00102520.c

"$WIBO" "$SNCPP" -P src/bounded_lookup_00102580.c "$BUILD/bounded_lookup_00102580.i"
"$WIBO" "$SNCC1" "$BUILD/bounded_lookup_00102580.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/bounded_lookup_00102580.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/bounded_lookup_00102580.o" "$BUILD/bounded_lookup_00102580.s"
"$PYTHON" tools/verify_object.py "$BUILD/bounded_lookup_00102580.o" private/SLUS_204.86.rom --source src/bounded_lookup_00102580.c

"$WIBO" "$SNCPP" -P src/copy_record_00102860.c "$BUILD/copy_record_00102860.i"
"$WIBO" "$SNCC1" "$BUILD/copy_record_00102860.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/copy_record_00102860.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/copy_record_00102860.o" "$BUILD/copy_record_00102860.s"
"$PYTHON" tools/verify_object.py "$BUILD/copy_record_00102860.o" private/SLUS_204.86.rom --source src/copy_record_00102860.c

"$WIBO" "$SNCPP" -P src/mmio_exchange_00102898.c "$BUILD/mmio_exchange_00102898.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/mmio_exchange_00102898.i" "$BUILD/mmio_exchange_00102898.s"
"${AS:-mipsel-linux-gnu-as}" -EL -march=r5900 -mabi=eabi -G0 -o "$BUILD/mmio_exchange_00102898.o" "$BUILD/mmio_exchange_00102898.s"
"$PYTHON" tools/verify_object.py "$BUILD/mmio_exchange_00102898.o" private/SLUS_204.86.rom --source src/mmio_exchange_00102898.c

"$WIBO" "$SNCPP" -P src/float_copy_001037B8.c "$BUILD/float_copy_001037B8.i"
"$WIBO" "$SNCC1" "$BUILD/float_copy_001037B8.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/float_copy_001037B8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/float_copy_001037B8.o" "$BUILD/float_copy_001037B8.s"
"$PYTHON" tools/verify_object.py "$BUILD/float_copy_001037B8.o" private/SLUS_204.86.rom --source src/float_copy_001037B8.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/mode_flags_0041DE10.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/mode_flags_0041DE10.o"
"$PYTHON" tools/verify_object.py "$BUILD/mode_flags_0041DE10.o" private/SLUS_204.86.rom --source src/mode_flags_0041DE10.c

"$WIBO" "$SNCPP" -P src/indexed_slots_00105F10.c "$BUILD/indexed_slots_00105F10.i"
"$WIBO" "$SNCC1" "$BUILD/indexed_slots_00105F10.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/indexed_slots_00105F10.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/indexed_slots_00105F10.o" "$BUILD/indexed_slots_00105F10.s"
"$PYTHON" tools/verify_object.py "$BUILD/indexed_slots_00105F10.o" private/SLUS_204.86.rom --source src/indexed_slots_00105F10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_clear_00423650.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/append_clear_00423650.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_clear_00423650.o" private/SLUS_204.86.rom --source src/append_clear_00423650.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_bool_004236C0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/append_bool_004236C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_bool_004236C0.o" private/SLUS_204.86.rom --source src/append_bool_004236C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_flags_004239D0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/append_flags_004239D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_flags_004239D0.o" private/SLUS_204.86.rom --source src/append_flags_004239D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/validate_queue_state_00423990.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/validate_queue_state_00423990.o"
"$PYTHON" tools/verify_object.py "$BUILD/validate_queue_state_00423990.o" private/SLUS_204.86.rom --source src/validate_queue_state_00423990.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/queue_state_transition_00423930.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/queue_state_transition_00423930.o"
"$PYTHON" tools/verify_object.py "$BUILD/queue_state_transition_00423930.o" private/SLUS_204.86.rom --source src/queue_state_transition_00423930.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_type29_00423240.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/append_type29_00423240.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_type29_00423240.o" private/SLUS_204.86.rom --source src/append_type29_00423240.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_tag_004235D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/append_tag_004235D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_tag_004235D0.o" private/SLUS_204.86.rom --source src/append_tag_004235D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/append_type28_004231D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/append_type28_004231D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/append_type28_004231D0.o" private/SLUS_204.86.rom --source src/append_type28_004231D0.c


MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/init_packet_queue_00422CC0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/init_packet_queue_00422CC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/init_packet_queue_00422CC0.o" \
    private/SLUS_204.86.rom --source src/init_packet_queue_00422CC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tagged_record_value_00420B00.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/tagged_record_value_00420B00.o"
"$PYTHON" tools/verify_object.py "$BUILD/tagged_record_value_00420B00.o" \
    private/SLUS_204.86.rom --source src/tagged_record_value_00420B00.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/nonzero_float_flag_00417770.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/nonzero_float_flag_00417770.o"
"$PYTHON" tools/verify_object.py "$BUILD/nonzero_float_flag_00417770.o" \
    private/SLUS_204.86.rom --source src/nonzero_float_flag_00417770.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/tagged_counter_record_00420BA0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/tagged_counter_record_00420BA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/tagged_counter_record_00420BA0.o" \
    private/SLUS_204.86.rom --source src/tagged_counter_record_00420BA0.c

# EE GCC layout with the original SN assembler's R5900 pseudo-instruction encoding.
"$WIBO" "$SNCPP" -P src/reentrant_heap_0011F858.c "$BUILD/reentrant_heap_0011F858.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/reentrant_heap_0011F858.i" "$BUILD/reentrant_heap_0011F858.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/reentrant_heap_0011F858.o" "$BUILD/reentrant_heap_0011F858.s"
"$PYTHON" tools/verify_object.py "$BUILD/reentrant_heap_0011F858.o" private/SLUS_204.86.rom --source src/reentrant_heap_0011F858.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/initialize_packet_runtime_00422DB0.c -c -lang c -O3 \
    -sdatathreshold 8 -o "$BUILD/initialize_packet_runtime_00422DB0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_packet_runtime_00422DB0.o" \
    private/SLUS_204.86.rom --source src/initialize_packet_runtime_00422DB0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/poll_packet_buffer_00422D20.c -c -lang c -O3 -Op \
    -sdatathreshold 8 -o "$BUILD/poll_packet_buffer_00422D20.o"
"$PYTHON" tools/verify_object.py "$BUILD/poll_packet_buffer_00422D20.o" \
    private/SLUS_204.86.rom --source src/poll_packet_buffer_00422D20.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/initialize_mode5_subsystem_00420310.c -c -lang c -O3 \
    -sdatathreshold 8 -o "$BUILD/initialize_mode5_subsystem_00420310.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_mode5_subsystem_00420310.o" \
    private/SLUS_204.86.rom --source src/initialize_mode5_subsystem_00420310.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/register_packet_wait_00422C20.c -c -lang c -O3 \
    -sdatathreshold 8 -o "$BUILD/register_packet_wait_00422C20.o"
"$PYTHON" tools/verify_object.py "$BUILD/register_packet_wait_00422C20.o" \
    private/SLUS_204.86.rom --source src/register_packet_wait_00422C20.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/refresh_packet_handle_00422C70.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/refresh_packet_handle_00422C70.o"
"$PYTHON" tools/verify_object.py "$BUILD/refresh_packet_handle_00422C70.o" \
    private/SLUS_204.86.rom --source src/refresh_packet_handle_00422C70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/release_packet_callback_00422BF0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/release_packet_callback_00422BF0.o"
"$PYTHON" tools/verify_object.py "$BUILD/release_packet_callback_00422BF0.o" \
    private/SLUS_204.86.rom --source src/release_packet_callback_00422BF0.c

"$WIBO" "$SNCPP" -P src/sdk_reentrant_seek_0011C9B8.c "$BUILD/sdk_reentrant_seek_0011C9B8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_reentrant_seek_0011C9B8.i" "$BUILD/sdk_reentrant_seek_0011C9B8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_reentrant_seek_0011C9B8.o" "$BUILD/sdk_reentrant_seek_0011C9B8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_reentrant_seek_0011C9B8.o" private/SLUS_204.86.rom --source src/sdk_reentrant_seek_0011C9B8.c

"$WIBO" "$SNCPP" -P src/sdk_file_seek_0011FAB0.c "$BUILD/sdk_file_seek_0011FAB0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_seek_0011FAB0.i" "$BUILD/sdk_file_seek_0011FAB0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_seek_0011FAB0.o" "$BUILD/sdk_file_seek_0011FAB0.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_seek_0011FAB0.o" private/SLUS_204.86.rom --source src/sdk_file_seek_0011FAB0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_grounded_velocity_reset.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_grounded_velocity_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_grounded_velocity_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_grounded_velocity_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_stalled_floor_recovery.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_stalled_floor_recovery.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_stalled_floor_recovery.o" private/SLUS_204.86.rom \
    --source src/grok_w7_stalled_floor_recovery.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_stationary_floor_acceleration.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_stationary_floor_acceleration.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_stationary_floor_acceleration.o" private/SLUS_204.86.rom \
    --source src/grok_w7_stationary_floor_acceleration.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_inhibit_resume_handler.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_inhibit_resume_handler.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_inhibit_resume_handler.o" private/SLUS_204.86.rom \
    --source src/grok_w7_inhibit_resume_handler.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_stationary_motion_check.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_stationary_motion_check.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_stationary_motion_check.o" private/SLUS_204.86.rom \
    --source src/grok_w7_stationary_motion_check.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_velocity_interaction_dispatch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_velocity_interaction_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_velocity_interaction_dispatch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_velocity_interaction_dispatch.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/finalize_transfer_buffer_00421270.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/finalize_transfer_buffer_00421270.o"
"$PYTHON" tools/verify_object.py "$BUILD/finalize_transfer_buffer_00421270.o" \
    private/SLUS_204.86.rom --source src/finalize_transfer_buffer_00421270.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_transfer_backend_00420920.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/select_transfer_backend_00420920.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_transfer_backend_00420920.o" \
    private/SLUS_204.86.rom --source src/select_transfer_backend_00420920.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_transfer_backend_004206D0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/select_transfer_backend_004206D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_transfer_backend_004206D0.o" \
    private/SLUS_204.86.rom --source src/select_transfer_backend_004206D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/update_backend_timeout_004205F0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/update_backend_timeout_004205F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_backend_timeout_004205F0.o" \
    private/SLUS_204.86.rom --source src/update_backend_timeout_004205F0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/reset_backend_state_00420660.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_backend_state_00420660.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_backend_state_00420660.o" \
    private/SLUS_204.86.rom --source src/reset_backend_state_00420660.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/backend_lifecycle_handlers_00420840.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/backend_lifecycle_handlers_00420840.o"
"$PYTHON" tools/verify_object.py "$BUILD/backend_lifecycle_handlers_00420840.o" \
    private/SLUS_204.86.rom --source src/backend_lifecycle_handlers_00420840.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_backend_00420720.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_backend_00420720.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_backend_00420720.o" \
    private/SLUS_204.86.rom --source src/initialize_backend_00420720.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_backend_004204C0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_backend_004204C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_backend_004204C0.o" \
    private/SLUS_204.86.rom --source src/initialize_backend_004204C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_runtime_storage_00420340.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_storage_00420340.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_storage_00420340.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_storage_00420340.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/clear_backend_tables_00420230.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/clear_backend_tables_00420230.o"
"$PYTHON" tools/verify_object.py "$BUILD/clear_backend_tables_00420230.o" \
    private/SLUS_204.86.rom --source src/clear_backend_tables_00420230.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_dma_context_00420980.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_dma_context_00420980.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_dma_context_00420980.o" \
    private/SLUS_204.86.rom --source src/initialize_dma_context_00420980.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_negative_action_completions.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_negative_action_completions.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_negative_action_completions.o" private/SLUS_204.86.rom \
    --source src/grok_w7_negative_action_completions.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_wait_frame_motion.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_wait_frame_motion.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_wait_frame_motion.o" private/SLUS_204.86.rom \
    --source src/grok_w7_wait_frame_motion.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_zero_frame_velocity_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_zero_frame_velocity_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_zero_frame_velocity_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_zero_frame_velocity_setup.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_nonzero_state_launch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_nonzero_state_launch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_nonzero_state_launch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_nonzero_state_launch.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_negative_floor_rebound.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_negative_floor_rebound.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_negative_floor_rebound.o" private/SLUS_204.86.rom \
    --source src/grok_w7_negative_floor_rebound.c



MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_effect_parameters_00420400.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_effect_parameters_00420400.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_effect_parameters_00420400.o" \
    private/SLUS_204.86.rom --source src/initialize_effect_parameters_00420400.c


"$WIBO" "$SNCPP" -P src/count_runtime_chains_00410468.c \
    "$BUILD/count_runtime_chains_00410468.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/count_runtime_chains_00410468.i" "$BUILD/count_runtime_chains_00410468.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/count_runtime_chains_00410468.o" \
    "$BUILD/count_runtime_chains_00410468.s"
"$PYTHON" tools/verify_object.py "$BUILD/count_runtime_chains_00410468.o" \
    private/SLUS_204.86.rom --source src/count_runtime_chains_00410468.c

"$WIBO" "$SNCPP" -P src/sdk_reentrant_read_0011F640.c "$BUILD/sdk_reentrant_read_0011F640.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_reentrant_read_0011F640.i" "$BUILD/sdk_reentrant_read_0011F640.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_reentrant_read_0011F640.o" "$BUILD/sdk_reentrant_read_0011F640.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_reentrant_read_0011F640.o" private/SLUS_204.86.rom --source src/sdk_reentrant_read_0011F640.c

"$WIBO" "$SNCPP" -P src/sdk_file_read_0011F9C8.c "$BUILD/sdk_file_read_0011F9C8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_read_0011F9C8.i" "$BUILD/sdk_file_read_0011F9C8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_read_0011F9C8.o" "$BUILD/sdk_file_read_0011F9C8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_read_0011F9C8.o" private/SLUS_204.86.rom --source src/sdk_file_read_0011F9C8.c

"$WIBO" "$SNCPP" -P src/write_runtime_remaining_size_00400B58.c \
    "$BUILD/write_runtime_remaining_size_00400B58.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/write_runtime_remaining_size_00400B58.i" \
    "$BUILD/write_runtime_remaining_size_00400B58.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/write_runtime_remaining_size_00400B58.o" \
    "$BUILD/write_runtime_remaining_size_00400B58.s"
"$PYTHON" tools/verify_object.py "$BUILD/write_runtime_remaining_size_00400B58.o" \
    private/SLUS_204.86.rom --source src/write_runtime_remaining_size_00400B58.c

"$WIBO" "$SNCPP" -P src/adjust_runtime_object_offset_00400658.c \
    "$BUILD/adjust_runtime_object_offset_00400658.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/adjust_runtime_object_offset_00400658.i" \
    "$BUILD/adjust_runtime_object_offset_00400658.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/adjust_runtime_object_offset_00400658.o" \
    "$BUILD/adjust_runtime_object_offset_00400658.s"
"$PYTHON" tools/verify_object.py "$BUILD/adjust_runtime_object_offset_00400658.o" \
    private/SLUS_204.86.rom --source src/adjust_runtime_object_offset_00400658.c

"$WIBO" "$SNCPP" -P src/initialize_runtime_object_state_004006E8.c \
    "$BUILD/initialize_runtime_object_state_004006E8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/initialize_runtime_object_state_004006E8.i" \
    "$BUILD/initialize_runtime_object_state_004006E8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/initialize_runtime_object_state_004006E8.o" \
    "$BUILD/initialize_runtime_object_state_004006E8.s"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_object_state_004006E8.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_object_state_004006E8.c

"$WIBO" "$SNCPP" -P src/release_runtime_object_resource_00400740.c \
    "$BUILD/release_runtime_object_resource_00400740.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/release_runtime_object_resource_00400740.i" \
    "$BUILD/release_runtime_object_resource_00400740.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/release_runtime_object_resource_00400740.o" \
    "$BUILD/release_runtime_object_resource_00400740.s"
"$PYTHON" tools/verify_object.py "$BUILD/release_runtime_object_resource_00400740.o" \
    private/SLUS_204.86.rom --source src/release_runtime_object_resource_00400740.c

"$WIBO" "$SNCPP" -P src/release_runtime_object_004005F8.c \
    "$BUILD/release_runtime_object_004005F8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/release_runtime_object_004005F8.i" \
    "$BUILD/release_runtime_object_004005F8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/release_runtime_object_004005F8.o" \
    "$BUILD/release_runtime_object_004005F8.s"
"$PYTHON" tools/verify_object.py "$BUILD/release_runtime_object_004005F8.o" \
    private/SLUS_204.86.rom --source src/release_runtime_object_004005F8.c

"$WIBO" "$SNCPP" -P src/process_active_runtime_entries_00400AF8.c \
    "$BUILD/process_active_runtime_entries_00400AF8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/process_active_runtime_entries_00400AF8.i" \
    "$BUILD/process_active_runtime_entries_00400AF8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/process_active_runtime_entries_00400AF8.o" \
    "$BUILD/process_active_runtime_entries_00400AF8.s"
"$PYTHON" tools/verify_object.py "$BUILD/process_active_runtime_entries_00400AF8.o" \
    private/SLUS_204.86.rom --source src/process_active_runtime_entries_00400AF8.c

"$WIBO" "$SNCPP" -P src/cleanup_runtime_entry_table_0040D118.c \
    "$BUILD/cleanup_runtime_entry_table_0040D118.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/cleanup_runtime_entry_table_0040D118.i" \
    "$BUILD/cleanup_runtime_entry_table_0040D118.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/cleanup_runtime_entry_table_0040D118.o" \
    "$BUILD/cleanup_runtime_entry_table_0040D118.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/cleanup_runtime_entry_table_0040D118.o" \
    private/SLUS_204.86.rom --source src/cleanup_runtime_entry_table_0040D118.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_entry_version_00400AD0.c \
    "$BUILD/dispatch_runtime_entry_version_00400AD0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_entry_version_00400AD0.i" \
    "$BUILD/dispatch_runtime_entry_version_00400AD0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_entry_version_00400AD0.o" \
    "$BUILD/dispatch_runtime_entry_version_00400AD0.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_entry_version_00400AD0.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_entry_version_00400AD0.c

"$WIBO" "$SNCPP" -P src/zero_runtime_object_00400308.c \
    "$BUILD/zero_runtime_object_00400308.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/zero_runtime_object_00400308.i" \
    "$BUILD/zero_runtime_object_00400308.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/zero_runtime_object_00400308.o" \
    "$BUILD/zero_runtime_object_00400308.s"
"$PYTHON" tools/verify_object.py "$BUILD/zero_runtime_object_00400308.o" \
    private/SLUS_204.86.rom --source src/zero_runtime_object_00400308.c

"$WIBO" "$SNCPP" -P src/read_runtime_mode_00401920.c \
    "$BUILD/read_runtime_mode_00401920.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_mode_00401920.i" \
    "$BUILD/read_runtime_mode_00401920.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_mode_00401920.o" \
    "$BUILD/read_runtime_mode_00401920.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_runtime_mode_00401920.o" \
    private/SLUS_204.86.rom --source src/read_runtime_mode_00401920.c

"$WIBO" "$SNCPP" -P src/read_runtime_record_mode_0040A218.c \
    "$BUILD/read_runtime_record_mode_0040A218.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_record_mode_0040A218.i" \
    "$BUILD/read_runtime_record_mode_0040A218.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_record_mode_0040A218.o" \
    "$BUILD/read_runtime_record_mode_0040A218.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_runtime_record_mode_0040A218.o" \
    private/SLUS_204.86.rom --source src/read_runtime_record_mode_0040A218.c

"$WIBO" "$SNCPP" -P src/read_runtime_record_state_0040BCB8.c \
    "$BUILD/read_runtime_record_state_0040BCB8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_record_state_0040BCB8.i" \
    "$BUILD/read_runtime_record_state_0040BCB8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_record_state_0040BCB8.o" \
    "$BUILD/read_runtime_record_state_0040BCB8.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_runtime_record_state_0040BCB8.o" \
    private/SLUS_204.86.rom --source src/read_runtime_record_state_0040BCB8.c

"$WIBO" "$SNCPP" -P src/read_runtime_record_field_0040D178.c \
    "$BUILD/read_runtime_record_field_0040D178.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_record_field_0040D178.i" \
    "$BUILD/read_runtime_record_field_0040D178.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_record_field_0040D178.o" \
    "$BUILD/read_runtime_record_field_0040D178.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/read_runtime_record_field_0040D178.o" \
    private/SLUS_204.86.rom --source src/read_runtime_record_field_0040D178.c

"$WIBO" "$SNCPP" -P src/reset_runtime_record_state_0040CF98.c \
    "$BUILD/reset_runtime_record_state_0040CF98.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/reset_runtime_record_state_0040CF98.i" \
    "$BUILD/reset_runtime_record_state_0040CF98.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/reset_runtime_record_state_0040CF98.o" \
    "$BUILD/reset_runtime_record_state_0040CF98.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/reset_runtime_record_state_0040CF98.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_record_state_0040CF98.c

"$WIBO" "$SNCPP" -P src/read_scaled_runtime_fields_0040A310.c \
    "$BUILD/read_scaled_runtime_fields_0040A310.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_scaled_runtime_fields_0040A310.i" \
    "$BUILD/read_scaled_runtime_fields_0040A310.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_scaled_runtime_fields_0040A310.o" \
    "$BUILD/read_scaled_runtime_fields_0040A310.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/read_scaled_runtime_fields_0040A310.o" \
    private/SLUS_204.86.rom --source src/read_scaled_runtime_fields_0040A310.c

"$WIBO" "$SNCPP" -P src/initialize_runtime_descriptor_00404408.c \
    "$BUILD/initialize_runtime_descriptor_00404408.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/initialize_runtime_descriptor_00404408.i" \
    "$BUILD/initialize_runtime_descriptor_00404408.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/initialize_runtime_descriptor_00404408.o" \
    "$BUILD/initialize_runtime_descriptor_00404408.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/initialize_runtime_descriptor_00404408.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_descriptor_00404408.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_record_fields_00404360.c \
    "$BUILD/dispatch_runtime_record_fields_00404360.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_record_fields_00404360.i" \
    "$BUILD/dispatch_runtime_record_fields_00404360.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_record_fields_00404360.o" \
    "$BUILD/dispatch_runtime_record_fields_00404360.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_record_fields_00404360.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_record_fields_00404360.c

"$WIBO" "$SNCPP" -P src/copy_runtime_record_halfwords_00404388.c \
    "$BUILD/copy_runtime_record_halfwords_00404388.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/copy_runtime_record_halfwords_00404388.i" \
    "$BUILD/copy_runtime_record_halfwords_00404388.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/copy_runtime_record_halfwords_00404388.o" \
    "$BUILD/copy_runtime_record_halfwords_00404388.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/copy_runtime_record_halfwords_00404388.o" \
    private/SLUS_204.86.rom --source src/copy_runtime_record_halfwords_00404388.c

"$WIBO" "$SNCPP" -P src/clear_runtime_service_table_00404240.c \
    "$BUILD/clear_runtime_service_table_00404240.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/clear_runtime_service_table_00404240.i" \
    "$BUILD/clear_runtime_service_table_00404240.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/clear_runtime_service_table_00404240.o" \
    "$BUILD/clear_runtime_service_table_00404240.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/clear_runtime_service_table_00404240.o" \
    private/SLUS_204.86.rom --source src/clear_runtime_service_table_00404240.c

"$WIBO" "$SNCPP" -P src/clear_runtime_record_buffer_004043C0.c \
    "$BUILD/clear_runtime_record_buffer_004043C0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/clear_runtime_record_buffer_004043C0.i" \
    "$BUILD/clear_runtime_record_buffer_004043C0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/clear_runtime_record_buffer_004043C0.o" \
    "$BUILD/clear_runtime_record_buffer_004043C0.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/clear_runtime_record_buffer_004043C0.o" \
    private/SLUS_204.86.rom --source src/clear_runtime_record_buffer_004043C0.c

"$WIBO" "$SNCPP" -P src/clear_runtime_record_payload_0040B6E0.c \
    "$BUILD/clear_runtime_record_payload_0040B6E0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/clear_runtime_record_payload_0040B6E0.i" \
    "$BUILD/clear_runtime_record_payload_0040B6E0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/clear_runtime_record_payload_0040B6E0.o" \
    "$BUILD/clear_runtime_record_payload_0040B6E0.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/clear_runtime_record_payload_0040B6E0.o" \
    private/SLUS_204.86.rom --source src/clear_runtime_record_payload_0040B6E0.c

"$WIBO" "$SNCPP" -P src/log_unimplemented_runtime_service_0040EF48.c \
    "$BUILD/log_unimplemented_runtime_service_0040EF48.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/log_unimplemented_runtime_service_0040EF48.i" \
    "$BUILD/log_unimplemented_runtime_service_0040EF48.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/log_unimplemented_runtime_service_0040EF48.o" \
    "$BUILD/log_unimplemented_runtime_service_0040EF48.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/log_unimplemented_runtime_service_0040EF48.o" \
    private/SLUS_204.86.rom --source src/log_unimplemented_runtime_service_0040EF48.c

"$WIBO" "$SNCPP" -P src/read_versioned_runtime_state_00401F38.c \
    "$BUILD/read_versioned_runtime_state_00401F38.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_versioned_runtime_state_00401F38.i" \
    "$BUILD/read_versioned_runtime_state_00401F38.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_versioned_runtime_state_00401F38.o" \
    "$BUILD/read_versioned_runtime_state_00401F38.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_versioned_runtime_state_00401F38.o" \
    private/SLUS_204.86.rom --source src/read_versioned_runtime_state_00401F38.c

"$WIBO" "$SNCPP" -P src/set_runtime_record_reload_00402208.c \
    "$BUILD/set_runtime_record_reload_00402208.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/set_runtime_record_reload_00402208.i" \
    "$BUILD/set_runtime_record_reload_00402208.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_record_reload_00402208.o" \
    "$BUILD/set_runtime_record_reload_00402208.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/set_runtime_record_reload_00402208.o" \
    private/SLUS_204.86.rom --source src/set_runtime_record_reload_00402208.c

"$WIBO" "$SNCPP" -P src/set_runtime_object_offset_00400CF8.c \
    "$BUILD/set_runtime_object_offset_00400CF8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/set_runtime_object_offset_00400CF8.i" \
    "$BUILD/set_runtime_object_offset_00400CF8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_object_offset_00400CF8.o" \
    "$BUILD/set_runtime_object_offset_00400CF8.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/set_runtime_object_offset_00400CF8.o" \
    private/SLUS_204.86.rom --source src/set_runtime_object_offset_00400CF8.c

"$WIBO" "$SNCPP" -P src/call_runtime_scalar_action_004087A0.c \
    "$BUILD/call_runtime_scalar_action_004087A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/call_runtime_scalar_action_004087A0.i" \
    "$BUILD/call_runtime_scalar_action_004087A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/call_runtime_scalar_action_004087A0.o" \
    "$BUILD/call_runtime_scalar_action_004087A0.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/call_runtime_scalar_action_004087A0.o" \
    private/SLUS_204.86.rom --source src/call_runtime_scalar_action_004087A0.c

"$WIBO" "$SNCPP" -P src/compare_runtime_path_bytes_0040C088.c \
    "$BUILD/compare_runtime_path_bytes_0040C088.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/compare_runtime_path_bytes_0040C088.i" \
    "$BUILD/compare_runtime_path_bytes_0040C088.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/compare_runtime_path_bytes_0040C088.o" \
    "$BUILD/compare_runtime_path_bytes_0040C088.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/compare_runtime_path_bytes_0040C088.o" \
    private/SLUS_204.86.rom --source src/compare_runtime_path_bytes_0040C088.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_state_metric_00408808.c \
    "$BUILD/dispatch_runtime_state_metric_00408808.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_state_metric_00408808.i" \
    "$BUILD/dispatch_runtime_state_metric_00408808.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_state_metric_00408808.o" \
    "$BUILD/dispatch_runtime_state_metric_00408808.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_state_metric_00408808.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_state_metric_00408808.c

"$WIBO" "$SNCPP" -P src/query_runtime_state_boolean_004087B8.c \
    "$BUILD/query_runtime_state_boolean_004087B8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/query_runtime_state_boolean_004087B8.i" \
    "$BUILD/query_runtime_state_boolean_004087B8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/query_runtime_state_boolean_004087B8.o" \
    "$BUILD/query_runtime_state_boolean_004087B8.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/query_runtime_state_boolean_004087B8.o" \
    private/SLUS_204.86.rom --source src/query_runtime_state_boolean_004087B8.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_four_fields_00400DE0.c \
    "$BUILD/dispatch_runtime_four_fields_00400DE0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_four_fields_00400DE0.i" \
    "$BUILD/dispatch_runtime_four_fields_00400DE0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_four_fields_00400DE0.o" \
    "$BUILD/dispatch_runtime_four_fields_00400DE0.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_four_fields_00400DE0.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_four_fields_00400DE0.c

"$WIBO" "$SNCPP" -P src/read_runtime_record_fields_00405350.c \
    "$BUILD/read_runtime_record_fields_00405350.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_record_fields_00405350.i" \
    "$BUILD/read_runtime_record_fields_00405350.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_record_fields_00405350.o" \
    "$BUILD/read_runtime_record_fields_00405350.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_runtime_record_fields_00405350.o" \
    private/SLUS_204.86.rom --source src/read_runtime_record_fields_00405350.c

"$WIBO" "$SNCPP" -P src/process_active_runtime_records_004050A0.c \
    "$BUILD/process_active_runtime_records_004050A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/process_active_runtime_records_004050A0.i" \
    "$BUILD/process_active_runtime_records_004050A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/process_active_runtime_records_004050A0.o" \
    "$BUILD/process_active_runtime_records_004050A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/process_active_runtime_records_004050A0.o" \
    private/SLUS_204.86.rom --source src/process_active_runtime_records_004050A0.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_object_value_004020D8.c \
    "$BUILD/dispatch_runtime_object_value_004020D8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_object_value_004020D8.i" \
    "$BUILD/dispatch_runtime_object_value_004020D8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_object_value_004020D8.o" \
    "$BUILD/dispatch_runtime_object_value_004020D8.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_object_value_004020D8.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_object_value_004020D8.c

"$WIBO" "$SNCPP" -P src/clamp_runtime_state_value_0040EDE0.c \
    "$BUILD/clamp_runtime_state_value_0040EDE0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/clamp_runtime_state_value_0040EDE0.i" \
    "$BUILD/clamp_runtime_state_value_0040EDE0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/clamp_runtime_state_value_0040EDE0.o" \
    "$BUILD/clamp_runtime_state_value_0040EDE0.s"
"$PYTHON" tools/verify_object.py "$BUILD/clamp_runtime_state_value_0040EDE0.o" \
    private/SLUS_204.86.rom --source src/clamp_runtime_state_value_0040EDE0.c

"$WIBO" "$SNCPP" -P src/set_runtime_slot_pair_004075B8.c \
    "$BUILD/set_runtime_slot_pair_004075B8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/set_runtime_slot_pair_004075B8.i" \
    "$BUILD/set_runtime_slot_pair_004075B8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_slot_pair_004075B8.o" \
    "$BUILD/set_runtime_slot_pair_004075B8.s"
"$PYTHON" tools/verify_object.py "$BUILD/set_runtime_slot_pair_004075B8.o" \
    private/SLUS_204.86.rom --source src/set_runtime_slot_pair_004075B8.c

"$WIBO" "$SNCPP" -P src/runtime_message_callbacks_00400D20.c \
    "$BUILD/runtime_message_callbacks_00400D20.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/runtime_message_callbacks_00400D20.i" \
    "$BUILD/runtime_message_callbacks_00400D20.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_message_callbacks_00400D20.o" \
    "$BUILD/runtime_message_callbacks_00400D20.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_message_callbacks_00400D20.o" \
    private/SLUS_204.86.rom --source src/runtime_message_callbacks_00400D20.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_message_00405D98.c \
    "$BUILD/dispatch_runtime_message_00405D98.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_message_00405D98.i" \
    "$BUILD/dispatch_runtime_message_00405D98.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_message_00405D98.o" \
    "$BUILD/dispatch_runtime_message_00405D98.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_message_00405D98.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_message_00405D98.c

"$WIBO" "$SNCPP" -P src/prepare_archive_and_pack_00410688.c \
    "$BUILD/prepare_archive_and_pack_00410688.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/prepare_archive_and_pack_00410688.i" "$BUILD/prepare_archive_and_pack_00410688.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/prepare_archive_and_pack_00410688.o" \
    "$BUILD/prepare_archive_and_pack_00410688.s"
"$PYTHON" tools/verify_object.py "$BUILD/prepare_archive_and_pack_00410688.o" \
    private/SLUS_204.86.rom --source src/prepare_archive_and_pack_00410688.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_first_frame_reset.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_first_frame_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_first_frame_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_first_frame_reset.c


"$WIBO" "$SNCPP" -P src/sdk_reentrant_write_00122500.c "$BUILD/sdk_reentrant_write_00122500.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_reentrant_write_00122500.i" "$BUILD/sdk_reentrant_write_00122500.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_reentrant_write_00122500.o" "$BUILD/sdk_reentrant_write_00122500.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_reentrant_write_00122500.o" private/SLUS_204.86.rom --source src/sdk_reentrant_write_00122500.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_reverse_acceleration_resets.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_reverse_acceleration_resets.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_reverse_acceleration_resets.o" private/SLUS_204.86.rom \
    --source src/grok_w7_reverse_acceleration_resets.c


"$WIBO" "$SNCPP" -P src/sdk_file_write_0011FA30.c "$BUILD/sdk_file_write_0011FA30.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_write_0011FA30.i" "$BUILD/sdk_file_write_0011FA30.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_write_0011FA30.o" "$BUILD/sdk_file_write_0011FA30.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_write_0011FA30.o" private/SLUS_204.86.rom --source src/sdk_file_write_0011FA30.c

"$WIBO" "$SNCPP" -P src/derive_archive_segment_004106E8.c \
    "$BUILD/derive_archive_segment_004106E8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/derive_archive_segment_004106E8.i" "$BUILD/derive_archive_segment_004106E8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/derive_archive_segment_004106E8.o" \
    "$BUILD/derive_archive_segment_004106E8.s"
"$PYTHON" tools/verify_object.py "$BUILD/derive_archive_segment_004106E8.o" \
    private/SLUS_204.86.rom --source src/derive_archive_segment_004106E8.c

"$WIBO" "$SNCPP" -P src/sdk_file_flush_0011F6A0.c "$BUILD/sdk_file_flush_0011F6A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_flush_0011F6A0.i" "$BUILD/sdk_file_flush_0011F6A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_flush_0011F6A0.o" "$BUILD/sdk_file_flush_0011F6A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_flush_0011F6A0.o" private/SLUS_204.86.rom --source src/sdk_file_flush_0011F6A0.c

"$WIBO" "$SNCPP" -P src/sdk_file_close_0011FB18.c "$BUILD/sdk_file_close_0011FB18.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_close_0011FB18.i" "$BUILD/sdk_file_close_0011FB18.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_close_0011FB18.o" "$BUILD/sdk_file_close_0011FB18.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_close_0011FB18.o" private/SLUS_204.86.rom --source src/sdk_file_close_0011FB18.c

"$WIBO" "$SNCPP" -P src/sdk_reentrant_close_00119E80.c "$BUILD/sdk_reentrant_close_00119E80.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_reentrant_close_00119E80.i" "$BUILD/sdk_reentrant_close_00119E80.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_reentrant_close_00119E80.o" "$BUILD/sdk_reentrant_close_00119E80.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_reentrant_close_00119E80.o" private/SLUS_204.86.rom --source src/sdk_reentrant_close_00119E80.c

"$WIBO" "$SNCPP" -P src/query_runtime_value_004103D8.c \
    "$BUILD/query_runtime_value_004103D8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/query_runtime_value_004103D8.i" "$BUILD/query_runtime_value_004103D8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/query_runtime_value_004103D8.o" \
    "$BUILD/query_runtime_value_004103D8.s"
"$PYTHON" tools/verify_object.py "$BUILD/query_runtime_value_004103D8.o" \
    private/SLUS_204.86.rom --source src/query_runtime_value_004103D8.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_substate_gated_increment.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_substate_gated_increment.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_substate_gated_increment.o" private/SLUS_204.86.rom \
    --source src/grok_w7_substate_gated_increment.c

"$WIBO" "$SNCPP" -P src/decode_hex_length_004105D8.c \
    "$BUILD/decode_hex_length_004105D8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/decode_hex_length_004105D8.i" "$BUILD/decode_hex_length_004105D8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/decode_hex_length_004105D8.o" \
    "$BUILD/decode_hex_length_004105D8.s"
"$PYTHON" tools/verify_object.py "$BUILD/decode_hex_length_004105D8.o" \
    private/SLUS_204.86.rom --source src/decode_hex_length_004105D8.c

"$WIBO" "$SNCPP" -P src/sdk_cleanup_context_0011B768.c "$BUILD/sdk_cleanup_context_0011B768.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_cleanup_context_0011B768.i" "$BUILD/sdk_cleanup_context_0011B768.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_cleanup_context_0011B768.o" "$BUILD/sdk_cleanup_context_0011B768.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_cleanup_context_0011B768.o" private/SLUS_204.86.rom --source src/sdk_cleanup_context_0011B768.c

"$WIBO" "$SNCPP" -P src/sdk_cleanup_default_0011B788.c "$BUILD/sdk_cleanup_default_0011B788.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_cleanup_default_0011B788.i" "$BUILD/sdk_cleanup_default_0011B788.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_cleanup_default_0011B788.o" "$BUILD/sdk_cleanup_default_0011B788.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_cleanup_default_0011B788.o" private/SLUS_204.86.rom --source src/sdk_cleanup_default_0011B788.c

"$WIBO" "$SNCPP" -P src/release_runtime_reference_00410BD8.c \
    "$BUILD/release_runtime_reference_00410BD8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/release_runtime_reference_00410BD8.i" "$BUILD/release_runtime_reference_00410BD8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/release_runtime_reference_00410BD8.o" \
    "$BUILD/release_runtime_reference_00410BD8.s"
"$PYTHON" tools/verify_object.py "$BUILD/release_runtime_reference_00410BD8.o" \
    private/SLUS_204.86.rom --source src/release_runtime_reference_00410BD8.c

"$WIBO" "$SNCPP" -P src/sdk_file_walk_0011C838.c "$BUILD/sdk_file_walk_0011C838.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_file_walk_0011C838.i" "$BUILD/sdk_file_walk_0011C838.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_file_walk_0011C838.o" "$BUILD/sdk_file_walk_0011C838.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_file_walk_0011C838.o" private/SLUS_204.86.rom --source src/sdk_file_walk_0011C838.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_global_state.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_global_state.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_global_state.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_global_state.c

"$WIBO" "$SNCPP" -P src/sdk_initialize_context_0011B7A8.c "$BUILD/sdk_initialize_context_0011B7A8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_initialize_context_0011B7A8.i" "$BUILD/sdk_initialize_context_0011B7A8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_initialize_context_0011B7A8.o" "$BUILD/sdk_initialize_context_0011B7A8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_initialize_context_0011B7A8.o" private/SLUS_204.86.rom --source src/sdk_initialize_context_0011B7A8.c

"$WIBO" "$SNCPP" -P src/consume_runtime_span_00410000.c \
    "$BUILD/consume_runtime_span_00410000.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/consume_runtime_span_00410000.i" "$BUILD/consume_runtime_span_00410000.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/consume_runtime_span_00410000.o" \
    "$BUILD/consume_runtime_span_00410000.s"
"$PYTHON" tools/verify_object.py "$BUILD/consume_runtime_span_00410000.o" \
    private/SLUS_204.86.rom --source src/consume_runtime_span_00410000.c

"$WIBO" "$SNCPP" -P src/merge_runtime_span_00410290.c \
    "$BUILD/merge_runtime_span_00410290.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/merge_runtime_span_00410290.i" "$BUILD/merge_runtime_span_00410290.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/merge_runtime_span_00410290.o" \
    "$BUILD/merge_runtime_span_00410290.s"
"$PYTHON" tools/verify_object.py "$BUILD/merge_runtime_span_00410290.o" \
    private/SLUS_204.86.rom --source src/merge_runtime_span_00410290.c

"$WIBO" "$SNCPP" -P src/initialize_runtime_state_0040FEA8.c \
    "$BUILD/initialize_runtime_state_0040FEA8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/initialize_runtime_state_0040FEA8.i" "$BUILD/initialize_runtime_state_0040FEA8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/initialize_runtime_state_0040FEA8.o" \
    "$BUILD/initialize_runtime_state_0040FEA8.s"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_state_0040FEA8.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_state_0040FEA8.c

"$WIBO" "$SNCPP" -P src/count_runtime_span_0040FF88.c \
    "$BUILD/count_runtime_span_0040FF88.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/count_runtime_span_0040FF88.i" "$BUILD/count_runtime_span_0040FF88.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/count_runtime_span_0040FF88.o" \
    "$BUILD/count_runtime_span_0040FF88.s"
"$PYTHON" tools/verify_object.py "$BUILD/count_runtime_span_0040FF88.o" \
    private/SLUS_204.86.rom --source src/count_runtime_span_0040FF88.c

"$WIBO" "$SNCPP" -P src/runtime_mode_wrappers_00411A18.c \
    "$BUILD/runtime_mode_wrappers_00411A18.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/runtime_mode_wrappers_00411A18.i" "$BUILD/runtime_mode_wrappers_00411A18.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_mode_wrappers_00411A18.o" \
    "$BUILD/runtime_mode_wrappers_00411A18.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_mode_wrappers_00411A18.o" \
    private/SLUS_204.86.rom --source src/runtime_mode_wrappers_00411A18.c

"$WIBO" "$SNCPP" -P src/manage_runtime_reference_00411B98.c \
    "$BUILD/manage_runtime_reference_00411B98.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/manage_runtime_reference_00411B98.i" \
    "$BUILD/manage_runtime_reference_00411B98.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/manage_runtime_reference_00411B98.o" \
    "$BUILD/manage_runtime_reference_00411B98.s"
"$PYTHON" tools/verify_object.py "$BUILD/manage_runtime_reference_00411B98.o" \
    private/SLUS_204.86.rom --source src/manage_runtime_reference_00411B98.c

"$WIBO" "$SNCPP" -P src/initialize_runtime_service_00411B28.c \
    "$BUILD/initialize_runtime_service_00411B28.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/initialize_runtime_service_00411B28.i" \
    "$BUILD/initialize_runtime_service_00411B28.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/initialize_runtime_service_00411B28.o" \
    "$BUILD/initialize_runtime_service_00411B28.s"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_service_00411B28.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_service_00411B28.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/cleanup_runtime_object_00413DA0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/cleanup_runtime_object_00413DA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/cleanup_runtime_object_00413DA0.o" \
    private/SLUS_204.86.rom --source src/cleanup_runtime_object_00413DA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/transition_runtime_state_00416670.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/transition_runtime_state_00416670.o"
"$PYTHON" tools/verify_object.py "$BUILD/transition_runtime_state_00416670.o" \
    private/SLUS_204.86.rom --source src/transition_runtime_state_00416670.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/scale_runtime_state_value_00416770.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/scale_runtime_state_value_00416770.o"
"$PYTHON" tools/verify_object.py "$BUILD/scale_runtime_state_value_00416770.o" \
    private/SLUS_204.86.rom --source src/scale_runtime_state_value_00416770.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/normalize_runtime_state_size_00416730.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/normalize_runtime_state_size_00416730.o"
"$PYTHON" tools/verify_object.py "$BUILD/normalize_runtime_state_size_00416730.o" \
    private/SLUS_204.86.rom --source src/normalize_runtime_state_size_00416730.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_state_entry_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_state_entry_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_state_entry_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_state_entry_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_motion_triggered_state.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_motion_triggered_state.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_motion_triggered_state.o" private/SLUS_204.86.rom \
    --source src/grok_w7_motion_triggered_state.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_indexed_flag_transition.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_indexed_flag_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_indexed_flag_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_indexed_flag_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_transition_orchestrator.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_transition_orchestrator.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_transition_orchestrator.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_transition_orchestrator.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_state_dispatch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_state_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_state_dispatch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_state_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_indexed_context_callback.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_indexed_context_callback.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_indexed_context_callback.o" private/SLUS_204.86.rom \
    --source src/grok_w7_indexed_context_callback.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_timer_controller.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_timer_controller.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_timer_controller.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_timer_controller.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/grok_w7_compact_state_latch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_compact_state_latch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_compact_state_latch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_compact_state_latch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_external_state_trigger.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_external_state_trigger.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_external_state_trigger.o" private/SLUS_204.86.rom \
    --source src/grok_w7_external_state_trigger.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_state_setup_callbacks.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_state_setup_callbacks.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_state_setup_callbacks.o" private/SLUS_204.86.rom \
    --source src/grok_w7_state_setup_callbacks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_velocity_transfer_state.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_velocity_transfer_state.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_velocity_transfer_state.o" private/SLUS_204.86.rom \
    --source src/grok_w7_velocity_transfer_state.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_masked_flag_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_masked_flag_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_masked_flag_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_masked_flag_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_negative_result_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_negative_result_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_negative_result_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_negative_result_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_indexed_transition_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_indexed_transition_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_indexed_transition_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_indexed_transition_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_gated_countdown_callback.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_gated_countdown_callback.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_gated_countdown_callback.o" private/SLUS_204.86.rom \
    --source src/grok_w7_gated_countdown_callback.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_global_gate_callbacks.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_global_gate_callbacks.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_global_gate_callbacks.o" private/SLUS_204.86.rom \
    --source src/grok_w7_global_gate_callbacks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_signed_flag_spawn_position.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_signed_flag_spawn_position.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_signed_flag_spawn_position.o" private/SLUS_204.86.rom \
    --source src/grok_w7_signed_flag_spawn_position.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_variant_transitions.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_variant_transitions.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_variant_transitions.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_variant_transitions.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_conditional_phase_chain.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_conditional_phase_chain.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_conditional_phase_chain.o" private/SLUS_204.86.rom \
    --source src/grok_w7_conditional_phase_chain.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_state_two_marker_restart.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_state_two_marker_restart.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_state_two_marker_restart.o" private/SLUS_204.86.rom \
    --source src/grok_w7_state_two_marker_restart.c

"$WIBO" "$SNCPP" -P src/sdk_initialize_file_0011B598.c "$BUILD/sdk_initialize_file_0011B598.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_initialize_file_0011B598.i" "$BUILD/sdk_initialize_file_0011B598.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_initialize_file_0011B598.o" "$BUILD/sdk_initialize_file_0011B598.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_initialize_file_0011B598.o" private/SLUS_204.86.rom --source src/sdk_initialize_file_0011B598.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_selected_runtime_transform_004171E0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_selected_runtime_transform_004171E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_selected_runtime_transform_004171E0.o" \
    private/SLUS_204.86.rom --source src/reset_selected_runtime_transform_004171E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/zero_runtime_word_00416A70.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/zero_runtime_word_00416A70.o"
"$PYTHON" tools/verify_object.py "$BUILD/zero_runtime_word_00416A70.o" \
    private/SLUS_204.86.rom --source src/zero_runtime_word_00416A70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/reset_runtime_entry_slots_00414FE0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/reset_runtime_entry_slots_00414FE0.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_runtime_entry_slots_00414FE0.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_entry_slots_00414FE0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/reset_runtime_transform_heap_004152E0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_runtime_transform_heap_004152E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_runtime_transform_heap_004152E0.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_transform_heap_004152E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_runtime_services_00418C70.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_services_00418C70.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_services_00418C70.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_services_00418C70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_mode_result_00418AA0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dispatch_runtime_mode_result_00418AA0.o"
# MWCC emits this switch table as a local object; alias its symbol to the
# existing absolute table so the function verifier can resolve its address.
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @18=jtbl_004BEE40 \
    "$BUILD/dispatch_runtime_mode_result_00418AA0.o" \
    "$BUILD/dispatch_runtime_mode_result_00418AA0.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_mode_result_00418AA0.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_mode_result_00418AA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/convert_runtime_angles_00417D50.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/convert_runtime_angles_00417D50.o"
"$PYTHON" tools/verify_object.py "$BUILD/convert_runtime_angles_00417D50.o" \
    private/SLUS_204.86.rom --source src/convert_runtime_angles_00417D50.c

"$WIBO" "$SNCPP" -P src/sdk_allocate_file_glue_0011B5F8.c "$BUILD/sdk_allocate_file_glue_0011B5F8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_allocate_file_glue_0011B5F8.i" "$BUILD/sdk_allocate_file_glue_0011B5F8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_allocate_file_glue_0011B5F8.o" "$BUILD/sdk_allocate_file_glue_0011B5F8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_allocate_file_glue_0011B5F8.o" private/SLUS_204.86.rom --source src/sdk_allocate_file_glue_0011B5F8.c

"$WIBO" "$SNCPP" -P src/sdk_default_static_record_0011C998.c "$BUILD/sdk_default_static_record_0011C998.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_default_static_record_0011C998.i" "$BUILD/sdk_default_static_record_0011C998.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_default_static_record_0011C998.o" "$BUILD/sdk_default_static_record_0011C998.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_default_static_record_0011C998.o" private/SLUS_204.86.rom --source src/sdk_default_static_record_0011C998.c

"$WIBO" "$SNCPP" -P src/sdk_parse_integer64_00120838.c "$BUILD/sdk_parse_integer64_00120838.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_parse_integer64_00120838.i" "$BUILD/sdk_parse_integer64_00120838.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_parse_integer64_00120838.o" "$BUILD/sdk_parse_integer64_00120838.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_parse_integer64_00120838.o" private/SLUS_204.86.rom --source src/sdk_parse_integer64_00120838.c

"$WIBO" "$SNCPP" -P src/sdk_return_size_class_node_0011DB30.c "$BUILD/sdk_return_size_class_node_0011DB30.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_return_size_class_node_0011DB30.i" "$BUILD/sdk_return_size_class_node_0011DB30.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_return_size_class_node_0011DB30.o" "$BUILD/sdk_return_size_class_node_0011DB30.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_return_size_class_node_0011DB30.o" private/SLUS_204.86.rom --source src/sdk_return_size_class_node_0011DB30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/transform_runtime_point_00417E30.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/transform_runtime_point_00417E30.o"
"$PYTHON" tools/verify_object.py "$BUILD/transform_runtime_point_00417E30.o" \
    private/SLUS_204.86.rom --source src/transform_runtime_point_00417E30.c

"$WIBO" "$SNCPP" -P src/sdk_allocate_size_class_node_0011DA88.c "$BUILD/sdk_allocate_size_class_node_0011DA88.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_allocate_size_class_node_0011DA88.i" "$BUILD/sdk_allocate_size_class_node_0011DA88.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_allocate_size_class_node_0011DA88.o" "$BUILD/sdk_allocate_size_class_node_0011DA88.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_allocate_size_class_node_0011DA88.o" private/SLUS_204.86.rom --source src/sdk_allocate_size_class_node_0011DA88.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/compose_runtime_matrix_translation_004173C0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/compose_runtime_matrix_translation_004173C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/compose_runtime_matrix_translation_004173C0.o" \
    private/SLUS_204.86.rom --source src/compose_runtime_matrix_translation_004173C0.c

"$WIBO" "$SNCPP" -P src/sdk_initialize_single_word_0011DED8.c "$BUILD/sdk_initialize_single_word_0011DED8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_initialize_single_word_0011DED8.i" "$BUILD/sdk_initialize_single_word_0011DED8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_initialize_single_word_0011DED8.o" "$BUILD/sdk_initialize_single_word_0011DED8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_initialize_single_word_0011DED8.o" private/SLUS_204.86.rom --source src/sdk_initialize_single_word_0011DED8.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/initialize_runtime_menu_notice_00420560.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_menu_notice_00420560.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_menu_notice_00420560.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_menu_notice_00420560.c

"$WIBO" "$SNCPP" -P src/sdk_write_character_0011B9D0.c "$BUILD/sdk_write_character_0011B9D0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_write_character_0011B9D0.i" "$BUILD/sdk_write_character_0011B9D0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_write_character_0011B9D0.o" "$BUILD/sdk_write_character_0011B9D0.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_write_character_0011B9D0.o" private/SLUS_204.86.rom --source src/sdk_write_character_0011B9D0.c

"$WIBO" "$SNCPP" -P src/sdk_buffered_character_0011B9F8.c "$BUILD/sdk_buffered_character_0011B9F8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_buffered_character_0011B9F8.i" "$BUILD/sdk_buffered_character_0011B9F8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_buffered_character_0011B9F8.o" "$BUILD/sdk_buffered_character_0011B9F8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_buffered_character_0011B9F8.o" private/SLUS_204.86.rom --source src/sdk_buffered_character_0011B9F8.c

"$WIBO" "$SNCPP" -P src/sdk_write_string_0011BA90.c "$BUILD/sdk_write_string_0011BA90.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_write_string_0011BA90.i" "$BUILD/sdk_write_string_0011BA90.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_write_string_0011BA90.o" "$BUILD/sdk_write_string_0011BA90.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_write_string_0011BA90.o" private/SLUS_204.86.rom --source src/sdk_write_string_0011BA90.c

"$WIBO" "$SNCPP" -P src/sdk_default_heap_0011CB70.c "$BUILD/sdk_default_heap_0011CB70.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py "$BUILD/sdk_default_heap_0011CB70.i" "$BUILD/sdk_default_heap_0011CB70.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_default_heap_0011CB70.o" "$BUILD/sdk_default_heap_0011CB70.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_default_heap_0011CB70.o" private/SLUS_204.86.rom --source src/sdk_default_heap_0011CB70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_expanded_runtime_workspace_00415300.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_expanded_runtime_workspace_00415300.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_expanded_runtime_workspace_00415300.o" \
    private/SLUS_204.86.rom --source src/reset_expanded_runtime_workspace_00415300.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_runtime_service_pool_004154C0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_runtime_service_pool_004154C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_runtime_service_pool_004154C0.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_service_pool_004154C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/clear_runtime_service_workspace_00415450.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/clear_runtime_service_workspace_00415450.o"
"$PYTHON" tools/verify_object.py "$BUILD/clear_runtime_service_workspace_00415450.o" \
    private/SLUS_204.86.rom --source src/clear_runtime_service_workspace_00415450.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/transform_homogeneous_point_003DE480.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/transform_homogeneous_point_003DE480.o"
"$PYTHON" tools/verify_object.py "$BUILD/transform_homogeneous_point_003DE480.o" \
    private/SLUS_204.86.rom --source src/transform_homogeneous_point_003DE480.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/transform_runtime_view_point_003DE680.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/transform_runtime_view_point_003DE680.o"
"$PYTHON" tools/verify_object.py "$BUILD/transform_runtime_view_point_003DE680.o" \
    private/SLUS_204.86.rom --source src/transform_runtime_view_point_003DE680.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_runtime_graphics_matrix_003F38A0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_graphics_matrix_003F38A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_graphics_matrix_003F38A0.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_graphics_matrix_003F38A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/get_bmp_pixel_data_003F3850.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/get_bmp_pixel_data_003F3850.o"
"$PYTHON" tools/verify_object.py "$BUILD/get_bmp_pixel_data_003F3850.o" \
    private/SLUS_204.86.rom --source src/get_bmp_pixel_data_003F3850.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/align_graphics_extent_003F5180.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/align_graphics_extent_003F5180.o"
"$PYTHON" tools/verify_object.py "$BUILD/align_graphics_extent_003F5180.o" \
    private/SLUS_204.86.rom --source src/align_graphics_extent_003F5180.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/get_format_record_count_003F1E10.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/get_format_record_count_003F1E10.o"
"$PYTHON" tools/verify_object.py "$BUILD/get_format_record_count_003F1E10.o" \
    private/SLUS_204.86.rom --source src/get_format_record_count_003F1E10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_format_callback_count_003F14A0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_format_callback_count_003F14A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_format_callback_count_003F14A0.o" \
    private/SLUS_204.86.rom --source src/initialize_format_callback_count_003F14A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_constant_vector_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_constant_vector_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_constant_vector_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_constant_vector_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_vertical_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_vertical_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_vertical_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_vertical_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_two_float_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_two_float_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_two_float_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_two_float_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_secondary_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_secondary_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_secondary_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_secondary_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_masked_float_effect_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_masked_float_effect_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_masked_float_effect_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_masked_float_effect_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_conditional_scaled_velocity.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_conditional_scaled_velocity.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_conditional_scaled_velocity.o" private/SLUS_204.86.rom \
    --source src/grok_w7_conditional_scaled_velocity.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/copy_format_record_payload_003F1E70.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/copy_format_record_payload_003F1E70.o"
"$PYTHON" tools/verify_object.py "$BUILD/copy_format_record_payload_003F1E70.o" \
    private/SLUS_204.86.rom --source src/copy_format_record_payload_003F1E70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_zero_phase_counter_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_zero_phase_counter_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_zero_phase_counter_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_zero_phase_counter_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_velocity_sign_reset_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_velocity_sign_reset_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_velocity_sign_reset_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_velocity_sign_reset_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_transition_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_transition_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_transition_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_transition_reset.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/get_format_word_by_index_003F1410.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/get_format_word_by_index_003F1410.o"
"$PYTHON" tools/verify_object.py "$BUILD/get_format_word_by_index_003F1410.o" \
    private/SLUS_204.86.rom --source src/get_format_word_by_index_003F1410.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/random_state_step.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/random_state_step.o"
"$PYTHON" tools/verify_object.py "$BUILD/random_state_step.o" \
    private/SLUS_204.86.rom --source src/random_state_step.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/get_format_table_count_003F13A0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/get_format_table_count_003F13A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/get_format_table_count_003F13A0.o" \
    private/SLUS_204.86.rom --source src/get_format_table_count_003F13A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/project_point_to_xy.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/project_point_to_xy.o"
"$PYTHON" tools/verify_object.py "$BUILD/project_point_to_xy.o" \
    private/SLUS_204.86.rom --source src/project_point_to_xy.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_gated_motion_advancement.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_gated_motion_advancement.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_gated_motion_advancement.o" private/SLUS_204.86.rom \
    --source src/grok_w7_gated_motion_advancement.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_position_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_position_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_position_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_position_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_short_position_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_short_position_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_short_position_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_short_position_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_shared_workspace.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_shared_workspace.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_shared_workspace.o" \
    private/SLUS_204.86.rom --source src/initialize_shared_workspace.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_flagged_transition_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_flagged_transition_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_flagged_transition_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_flagged_transition_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_match_choices.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_match_choices.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_match_choices.o" \
    private/SLUS_204.86.rom --source src/initialize_match_choices.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_payload_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_payload_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_payload_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_payload_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/advance_global_phase.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/advance_global_phase.o"
"$PYTHON" tools/verify_object.py "$BUILD/advance_global_phase.o" \
    private/SLUS_204.86.rom --source src/advance_global_phase.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_flag_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_flag_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_flag_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_flag_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_three_axis_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_three_axis_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_three_axis_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_three_axis_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/status_flag_updates.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/status_flag_updates.o"
"$PYTHON" tools/verify_object.py "$BUILD/status_flag_updates.o" \
    private/SLUS_204.86.rom --source src/status_flag_updates.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_signed_update_position.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_signed_update_position.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_signed_update_position.o" private/SLUS_204.86.rom \
    --source src/grok_w7_signed_update_position.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/randomized_object_state.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/randomized_object_state.o"
"$PYTHON" tools/verify_object.py "$BUILD/randomized_object_state.o" \
    private/SLUS_204.86.rom --source src/randomized_object_state.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_vector_template.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_vector_template.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_vector_template.o" \
    private/SLUS_204.86.rom --source src/initialize_vector_template.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_mirrored_float_state_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_mirrored_float_state_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_mirrored_float_state_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_mirrored_float_state_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_mirrored_timer_entry_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_mirrored_timer_entry_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_mirrored_timer_entry_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_mirrored_timer_entry_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_mirrored_float_reset_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_mirrored_float_reset_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_mirrored_float_reset_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_mirrored_float_reset_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_owner_context_timer_dispatch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_owner_context_timer_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_owner_context_timer_dispatch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_owner_context_timer_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_state_decay_gate.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_state_decay_gate.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_state_decay_gate.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_state_decay_gate.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_anim_sequence.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_anim_sequence.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_anim_sequence.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_anim_sequence.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_position_finalizer.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_position_finalizer.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_position_finalizer.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_position_finalizer.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_motion_threshold_resume.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_motion_threshold_resume.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_motion_threshold_resume.o" private/SLUS_204.86.rom \
    --source src/grok_w7_motion_threshold_resume.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_conditional_float_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_conditional_float_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_conditional_float_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_conditional_float_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_countdown_phase_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_countdown_phase_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_countdown_phase_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_countdown_phase_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_countdown_motion_restart.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_countdown_motion_restart.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_countdown_motion_restart.o" private/SLUS_204.86.rom \
    --source src/grok_w7_countdown_motion_restart.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_fixed_phase_entry.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_fixed_phase_entry.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_fixed_phase_entry.o" private/SLUS_204.86.rom \
    --source src/grok_w7_fixed_phase_entry.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_state_exit.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_state_exit.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_state_exit.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_state_exit.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_float_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_float_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_float_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_float_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_masked_timer_phase_handler.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_masked_timer_phase_handler.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_masked_timer_phase_handler.o" private/SLUS_204.86.rom \
    --source src/grok_w7_masked_timer_phase_handler.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_deferred_float_state_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_deferred_float_state_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_deferred_float_state_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_deferred_float_state_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_deadline_position_transition.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_deadline_position_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_deadline_position_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_deadline_position_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_stateful_motion_entry.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_stateful_motion_entry.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_stateful_motion_entry.o" private/SLUS_204.86.rom \
    --source src/grok_w7_stateful_motion_entry.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_negative_actor_transition.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_negative_actor_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_negative_actor_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_negative_actor_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_conditional_vector_entry.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_conditional_vector_entry.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_conditional_vector_entry.o" private/SLUS_204.86.rom \
    --source src/grok_w7_conditional_vector_entry.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_owner_context_float_setup.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w7_owner_context_float_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_owner_context_float_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_owner_context_float_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_activation_validator.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_activation_validator.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_activation_validator.o" private/SLUS_204.86.rom \
    --source src/grok_w7_activation_validator.c
"$WIBO" "$SNCPP" -P src/runtime_remaining_size_004006A0.c \
    "$BUILD/runtime_remaining_size_004006A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/runtime_remaining_size_004006A0.i" \
    "$BUILD/runtime_remaining_size_004006A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_remaining_size_004006A0.o" \
    "$BUILD/runtime_remaining_size_004006A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_remaining_size_004006A0.o" \
    private/SLUS_204.86.rom --source src/runtime_remaining_size_004006A0.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_result_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_result_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_result_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_result_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_motion_limit_callback.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_motion_limit_callback.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_motion_limit_callback.o" private/SLUS_204.86.rom \
    --source src/grok_w7_motion_limit_callback.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_grounded_result_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_grounded_result_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_grounded_result_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_grounded_result_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_contextual_grounded_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_contextual_grounded_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_contextual_grounded_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_contextual_grounded_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_motion_timer_warning.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_motion_timer_warning.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_motion_timer_warning.o" private/SLUS_204.86.rom \
    --source src/grok_w7_motion_timer_warning.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_contextual_timed_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_contextual_timed_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_contextual_timed_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_contextual_timed_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_contextual_motion_recovery.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_contextual_motion_recovery.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_contextual_motion_recovery.o" private/SLUS_204.86.rom \
    --source src/grok_w7_contextual_motion_recovery.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_float_toggle_launch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_float_toggle_launch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_float_toggle_launch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_float_toggle_launch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_state_transition.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_state_transition.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_state_transition.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_state_transition.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_target_flip_dispatch.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_target_flip_dispatch.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_target_flip_dispatch.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_target_flip_dispatch.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_stage_motion_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_stage_motion_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_stage_motion_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_stage_motion_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_contextual_actor_handoff.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_contextual_actor_handoff.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_contextual_actor_handoff.o" private/SLUS_204.86.rom \
    --source src/grok_w7_contextual_actor_handoff.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_signed_context_handoff.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_signed_context_handoff.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_signed_context_handoff.o" private/SLUS_204.86.rom \
    --source src/grok_w7_signed_context_handoff.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_effect_frame_increment.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_effect_frame_increment.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_effect_frame_increment.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_effect_frame_increment.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_context_timer_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_context_timer_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_context_timer_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_context_timer_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_action_frame_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_action_frame_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_action_frame_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_action_frame_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_context_frame_setup.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_context_frame_setup.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_context_frame_setup.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_context_frame_setup.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_action_trigger.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_action_trigger.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_action_trigger.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_action_trigger.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_phase_increment.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_phase_increment.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_phase_increment.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_phase_increment.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timered_single_flag_callback.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timered_single_flag_callback.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timered_single_flag_callback.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timered_single_flag_callback.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_gate_timer_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_gate_timer_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_gate_timer_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_gate_timer_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_timed_sequence_fanout.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_timed_sequence_fanout.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_timed_sequence_fanout.o" private/SLUS_204.86.rom \
    --source src/grok_w7_timed_sequence_fanout.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_position_refresh.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_position_refresh.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_position_refresh.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_position_refresh.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_target_flag_query.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_target_flag_query.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_target_flag_query.o" private/SLUS_204.86.rom \
    --source src/grok_w7_target_flag_query.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_motion_state_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_motion_state_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_motion_state_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_motion_state_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_motion_floor_clamp.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_motion_floor_clamp.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_motion_floor_clamp.o" private/SLUS_204.86.rom \
    --source src/grok_w7_motion_floor_clamp.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_negative_flag_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_negative_flag_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_negative_flag_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_negative_flag_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_timer_state_reset.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_timer_state_reset.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_timer_state_reset.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_timer_state_reset.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w7_context_timer_flag_position.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_w7_context_timer_flag_position.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w7_context_timer_flag_position.o" private/SLUS_204.86.rom \
    --source src/grok_w7_context_timer_flag_position.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/animation_data_selector_00175A30.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/animation_data_selector_00175A30.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_data_selector_00175A30.o" \
    private/SLUS_204.86.rom --source src/animation_data_selector_00175A30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_record_strategy_0041AE60.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/dispatch_runtime_record_strategy_0041AE60.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/dispatch_runtime_record_strategy_0041AE60.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_record_strategy_0041AE60.c

"$WIBO" "$SNCPP" -P src/detect_runtime_path_prefix_0040BF00.c \
    "$BUILD/detect_runtime_path_prefix_0040BF00.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/detect_runtime_path_prefix_0040BF00.i" \
    "$BUILD/detect_runtime_path_prefix_0040BF00.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/detect_runtime_path_prefix_0040BF00.o" \
    "$BUILD/detect_runtime_path_prefix_0040BF00.s"
"$PYTHON" tools/verify_object.py \
    "$BUILD/detect_runtime_path_prefix_0040BF00.o" \
    private/SLUS_204.86.rom --source src/detect_runtime_path_prefix_0040BF00.c


MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/lookup_runtime_sine_00417440.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/lookup_runtime_sine_00417440.o"
"$PYTHON" tools/verify_object.py "$BUILD/lookup_runtime_sine_00417440.o" \
    private/SLUS_204.86.rom --source src/lookup_runtime_sine_00417440.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_runtime_global_state_0041F860.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/reset_runtime_global_state_0041F860.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_runtime_global_state_0041F860.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_global_state_0041F860.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_animation_mode_0041B0E0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dispatch_runtime_animation_mode_0041B0E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_animation_mode_0041B0E0.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_animation_mode_0041B0E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_runtime_animation_state_0041AA10.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/update_runtime_animation_state_0041AA10.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_runtime_animation_state_0041AA10.o" \
    private/SLUS_204.86.rom --source src/update_runtime_animation_state_0041AA10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/initialize_backend_notice_004207C0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_backend_notice_004207C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_backend_notice_004207C0.o" \
    private/SLUS_204.86.rom --source src/initialize_backend_notice_004207C0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/copy_animation_records_00175B40.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/copy_animation_records_00175B40.o"
"$PYTHON" tools/verify_object.py "$BUILD/copy_animation_records_00175B40.o" \
    private/SLUS_204.86.rom --source src/copy_animation_records_00175B40.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_motion_event_0039E4E0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/create_motion_event_0039E4E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_motion_event_0039E4E0.o" \
    private/SLUS_204.86.rom --source src/create_motion_event_0039E4E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_motion_event_stream_0039EE60.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/update_motion_event_stream_0039EE60.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_motion_event_stream_0039EE60.o" \
    private/SLUS_204.86.rom --source src/update_motion_event_stream_0039EE60.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/initialize_motion_event_stream_0039ED60.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/initialize_motion_event_stream_0039ED60.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_motion_event_stream_0039ED60.o" \
    private/SLUS_204.86.rom --source src/initialize_motion_event_stream_0039ED60.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_callback_00411978.c \
    "$BUILD/dispatch_runtime_callback_00411978.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_callback_00411978.i" \
    "$BUILD/dispatch_runtime_callback_00411978.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_callback_00411978.o" \
    "$BUILD/dispatch_runtime_callback_00411978.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_callback_00411978.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_callback_00411978.c

"$WIBO" "$SNCPP" -P src/invoke_runtime_slot_callback_00411288.c \
    "$BUILD/invoke_runtime_slot_callback_00411288.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/invoke_runtime_slot_callback_00411288.i" \
    "$BUILD/invoke_runtime_slot_callback_00411288.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/invoke_runtime_slot_callback_00411288.o" \
    "$BUILD/invoke_runtime_slot_callback_00411288.s"
"$PYTHON" tools/verify_object.py "$BUILD/invoke_runtime_slot_callback_00411288.o" \
    private/SLUS_204.86.rom --source src/invoke_runtime_slot_callback_00411288.c

"$WIBO" "$SNCPP" -P src/read_runtime_service_table_00411B00.c \
    "$BUILD/read_runtime_service_table_00411B00.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/read_runtime_service_table_00411B00.i" \
    "$BUILD/read_runtime_service_table_00411B00.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_runtime_service_table_00411B00.o" \
    "$BUILD/read_runtime_service_table_00411B00.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_runtime_service_table_00411B00.o" \
    private/SLUS_204.86.rom --source src/read_runtime_service_table_00411B00.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_text_callback_00411380.c \
    "$BUILD/dispatch_runtime_text_callback_00411380.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/dispatch_runtime_text_callback_00411380.i" \
    "$BUILD/dispatch_runtime_text_callback_00411380.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/dispatch_runtime_text_callback_00411380.o" \
    "$BUILD/dispatch_runtime_text_callback_00411380.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_text_callback_00411380.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_text_callback_00411380.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_text_pair_callback_004113D0.c \
    "$BUILD/dispatch_runtime_text_pair_callback_004113D0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/dispatch_runtime_text_pair_callback_004113D0.i" \
    "$BUILD/dispatch_runtime_text_pair_callback_004113D0.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/dispatch_runtime_text_pair_callback_004113D0.o" \
    "$BUILD/dispatch_runtime_text_pair_callback_004113D0.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_text_pair_callback_004113D0.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_text_pair_callback_004113D0.c

"$WIBO" "$SNCPP" -P src/submit_runtime_value_command_00411228.c \
    "$BUILD/submit_runtime_value_command_00411228.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 \
    "$BUILD/submit_runtime_value_command_00411228.i" \
    "$BUILD/submit_runtime_value_command_00411228.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/submit_runtime_value_command_00411228.o" \
    "$BUILD/submit_runtime_value_command_00411228.s"
"$PYTHON" tools/verify_object.py "$BUILD/submit_runtime_value_command_00411228.o" \
    private/SLUS_204.86.rom --source src/submit_runtime_value_command_00411228.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/initialize_runtime_object_once_00413D50.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_object_once_00413D50.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_object_once_00413D50.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_object_once_00413D50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/prepare_runtime_request_00413DF0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/prepare_runtime_request_00413DF0.o"
"$PYTHON" tools/verify_object.py "$BUILD/prepare_runtime_request_00413DF0.o" \
    private/SLUS_204.86.rom --source src/prepare_runtime_request_00413DF0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/prepare_runtime_transform_pair_00417170.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/prepare_runtime_transform_pair_00417170.o"
"$PYTHON" tools/verify_object.py "$BUILD/prepare_runtime_transform_pair_00417170.o" \
    private/SLUS_204.86.rom --source src/prepare_runtime_transform_pair_00417170.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    -i src src/dispatch_runtime_message_by_state_0041B130.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dispatch_runtime_message_by_state_0041B130.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_message_by_state_0041B130.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_message_by_state_0041B130.c

"$WIBO" "$SNCPP" -P src/dispatch_runtime_indexed_callback_00411818.c \
    "$BUILD/dispatch_runtime_indexed_callback_00411818.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
    "$BUILD/dispatch_runtime_indexed_callback_00411818.i" \
    "$BUILD/dispatch_runtime_indexed_callback_00411818.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/dispatch_runtime_indexed_callback_00411818.o" \
    "$BUILD/dispatch_runtime_indexed_callback_00411818.s"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_indexed_callback_00411818.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_indexed_callback_00411818.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_scene_anchor_00141250.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/create_scene_anchor_00141250.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_scene_anchor_00141250.o" \
    private/SLUS_204.86.rom --source src/create_scene_anchor_00141250.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_owner_overlay_0014A220.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/create_owner_overlay_0014A220.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_overlay_0014A220.o" \
    private/SLUS_204.86.rom --source src/create_owner_overlay_0014A220.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_mode_event_001382F0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/create_mode_event_001382F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_mode_event_001382F0.o" \
    private/SLUS_204.86.rom --source src/create_mode_event_001382F0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_owner_mode_event_001555A0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/create_owner_mode_event_001555A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_mode_event_001555A0.o" \
    private/SLUS_204.86.rom --source src/create_owner_mode_event_001555A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_unit_scale_event_0015C130.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/create_unit_scale_event_0015C130.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_unit_scale_event_0015C130.o" \
    private/SLUS_204.86.rom --source src/create_unit_scale_event_0015C130.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/reset_runtime_fade_state_0041D5F0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/reset_runtime_fade_state_0041D5F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/reset_runtime_fade_state_0041D5F0.o" \
    private/SLUS_204.86.rom --source src/reset_runtime_fade_state_0041D5F0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_marked_event_00135DB0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/create_marked_event_00135DB0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_marked_event_00135DB0.o" \
    private/SLUS_204.86.rom --source src/create_marked_event_00135DB0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_updated_event_0015BFB0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/create_updated_event_0015BFB0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_updated_event_0015BFB0.o" \
    private/SLUS_204.86.rom --source src/create_updated_event_0015BFB0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/create_counted_position_event_001571D0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/create_counted_position_event_001571D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_counted_position_event_001571D0.o" \
    private/SLUS_204.86.rom --source src/create_counted_position_event_001571D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/advance_runtime_grid_position_0041D020.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/advance_runtime_grid_position_0041D020.o"
"$PYTHON" tools/verify_object.py "$BUILD/advance_runtime_grid_position_0041D020.o" \
    private/SLUS_204.86.rom --source src/advance_runtime_grid_position_0041D020.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_runtime_effect_backend_0041C4B0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_runtime_effect_backend_0041C4B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_effect_backend_0041C4B0.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_effect_backend_0041C4B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_runtime_animation_backend_0041C400.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_runtime_animation_backend_0041C400.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_runtime_animation_backend_0041C400.o" \
    private/SLUS_204.86.rom --source src/initialize_runtime_animation_backend_0041C400.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_animation_effect_0041C550.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/dispatch_runtime_animation_effect_0041C550.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_animation_effect_0041C550.o" \
    private/SLUS_204.86.rom --source src/dispatch_runtime_animation_effect_0041C550.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_kind_event_001569C0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_kind_event_001569C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_kind_event_001569C0.o" \
 private/SLUS_204.86.rom --source src/create_owner_kind_event_001569C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_variant_mode_event_00138280.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_variant_mode_event_00138280.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_variant_mode_event_00138280.o" \
 private/SLUS_204.86.rom --source src/create_variant_mode_event_00138280.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_child_scale_event_0015BE90.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_child_scale_event_0015BE90.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_child_scale_event_0015BE90.o" \
 private/SLUS_204.86.rom --source src/create_child_scale_event_0015BE90.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_unit_color_event_00140FD0.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_unit_color_event_00140FD0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_unit_color_event_00140FD0.o" \
 private/SLUS_204.86.rom --source src/create_unit_color_event_00140FD0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_scene_resource_event_00136C80.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_scene_resource_event_00136C80.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_scene_resource_event_00136C80.o" \
 private/SLUS_204.86.rom --source src/create_scene_resource_event_00136C80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_position_event_0014E7B0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_position_event_0014E7B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_position_event_0014E7B0.o" \
 private/SLUS_204.86.rom --source src/create_owner_position_event_0014E7B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_timer_event_0014EEC0.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_owner_timer_event_0014EEC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_timer_event_0014EEC0.o" \
 private/SLUS_204.86.rom --source src/create_owner_timer_event_0014EEC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_child_position_event_001396E0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_child_position_event_001396E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_child_position_event_001396E0.o" \
 private/SLUS_204.86.rom --source src/create_child_position_event_001396E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_indexed_position_event_00144260.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_indexed_position_event_00144260.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_indexed_position_event_00144260.o" \
 private/SLUS_204.86.rom --source src/create_indexed_position_event_00144260.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_small_scale_event_001445A0.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_small_scale_event_001445A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_small_scale_event_001445A0.o" \
 private/SLUS_204.86.rom --source src/create_small_scale_event_001445A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_cloned_scene_event_00135600.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_cloned_scene_event_00135600.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_cloned_scene_event_00135600.o" \
 private/SLUS_204.86.rom --source src/create_cloned_scene_event_00135600.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_background_scale_event_00136B60.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_background_scale_event_00136B60.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_background_scale_event_00136B60.o" \
 private/SLUS_204.86.rom --source src/create_background_scale_event_00136B60.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_offset_effect_0015D010.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_offset_effect_0015D010.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_offset_effect_0015D010.o" \
 private/SLUS_204.86.rom --source src/create_offset_effect_0015D010.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_resource_depth_event_0014D9E0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_resource_depth_event_0014D9E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_resource_depth_event_0014D9E0.o" \
 private/SLUS_204.86.rom --source src/create_resource_depth_event_0014D9E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_fixed_position_event_0014EA80.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_fixed_position_event_0014EA80.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_fixed_position_event_0014EA80.o" \
 private/SLUS_204.86.rom --source src/create_fixed_position_event_0014EA80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_position_scale_color_events.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/create_position_scale_color_events.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_position_scale_color_events.o" \
 private/SLUS_204.86.rom --source src/create_position_scale_color_events.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_callback_001B0FA0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_callback_001B0FA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_callback_001B0FA0.o" \
 private/SLUS_204.86.rom --source src/create_owner_callback_001B0FA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_child_event_0019CD70.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_child_event_0019CD70.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_child_event_0019CD70.o" \
 private/SLUS_204.86.rom --source src/create_owner_child_event_0019CD70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_two_context_event_001ACDC0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_two_context_event_001ACDC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_two_context_event_001ACDC0.o" \
 private/SLUS_204.86.rom --source src/create_two_context_event_001ACDC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_mode_child_001978B0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_mode_child_001978B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_mode_child_001978B0.o" \
 private/SLUS_204.86.rom --source src/create_owner_mode_child_001978B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_flags_event_001D6B50.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_flags_event_001D6B50.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_flags_event_001D6B50.o" \
 private/SLUS_204.86.rom --source src/create_owner_flags_event_001D6B50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_event_registration_0037EA30.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_event_registration_0037EA30.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_event_registration_0037EA30.o" \
 private/SLUS_204.86.rom --source src/create_event_registration_0037EA30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/round_impact_002CE1D0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/round_impact_002CE1D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/round_impact_002CE1D0.o" \
 private/SLUS_204.86.rom --source src/round_impact_002CE1D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/batch2.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/batch2.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch2.o" private/SLUS_204.86.rom --source src/batch2.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/batch3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/batch3.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch3.o" private/SLUS_204.86.rom --source src/batch3.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/batch3b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/batch3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch3b.o" private/SLUS_204.86.rom --source src/batch3b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/batch4.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/batch4.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch4.o" private/SLUS_204.86.rom --source src/batch4.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave3.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave3.o" private/SLUS_204.86.rom --source src/wave3.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave3b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave3b.o" private/SLUS_204.86.rom --source src/wave3b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave6.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave6.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave6.o" private/SLUS_204.86.rom --source src/wave6.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave6b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave6b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave6b.o" private/SLUS_204.86.rom --source src/wave6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave7.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave7.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave7.o" private/SLUS_204.86.rom --source src/wave7.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave7b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave7b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave7b.o" private/SLUS_204.86.rom --source src/wave7b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/batch5.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/batch5.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch5.o" private/SLUS_204.86.rom --source src/batch5.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/batch5_30.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/batch5_30.o"
"$PYTHON" tools/verify_object.py "$BUILD/batch5_30.o" private/SLUS_204.86.rom --source src/batch5_30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave5.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave5.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave5.o" private/SLUS_204.86.rom --source src/wave5.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave5b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave5b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave5b.o" private/SLUS_204.86.rom --source src/wave5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave4.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/wave4.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave4.o" private/SLUS_204.86.rom --source src/wave4.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave4b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave4b.o" private/SLUS_204.86.rom --source src/wave4b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave1x.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave1x.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave1x.o" private/SLUS_204.86.rom --source src/wave1x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave1b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave1b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave1b.o" private/SLUS_204.86.rom --source src/wave1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave1d.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/wave1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave1d.o" private/SLUS_204.86.rom --source src/wave1d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave8.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave8.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave8.o" private/SLUS_204.86.rom --source src/wave8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave8b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave8b.o" private/SLUS_204.86.rom --source src/wave8b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave10.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave10.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave10.o" private/SLUS_204.86.rom --source src/wave10.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave10b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave10b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave10b.o" private/SLUS_204.86.rom --source src/wave10b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave13.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave13.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave13.o" private/SLUS_204.86.rom --source src/wave13.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave13b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave13b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave13b.o" private/SLUS_204.86.rom --source src/wave13b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave13c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave13c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave13c.o" private/SLUS_204.86.rom --source src/wave13c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave13d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave13d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave13d.o" private/SLUS_204.86.rom --source src/wave13d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave0.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/wave0.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave0.o" private/SLUS_204.86.rom --source src/wave0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave0b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/wave0b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave0b.o" private/SLUS_204.86.rom --source src/wave0b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave0c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/wave0c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave0c.o" private/SLUS_204.86.rom --source src/wave0c.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/dispatch_conditional_chain_001FC080.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/dispatch_conditional_chain_001FC080.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_conditional_chain_001FC080.o" \
 private/SLUS_204.86.rom --source src/dispatch_conditional_chain_001FC080.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_cleared_mode_child_001D36E0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_cleared_mode_child_001D36E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_cleared_mode_child_001D36E0.o" \
 private/SLUS_204.86.rom --source src/create_cleared_mode_child_001D36E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_two_mode_event_001D2730.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_two_mode_event_001D2730.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_two_mode_event_001D2730.o" \
 private/SLUS_204.86.rom --source src/create_owner_two_mode_event_001D2730.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/dispatch_owner_mode_0039C960.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/dispatch_owner_mode_0039C960.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_owner_mode_0039C960.o" \
 private/SLUS_204.86.rom --source src/dispatch_owner_mode_0039C960.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/build_dma_address_003DBA30.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/build_dma_address_003DBA30.o"
"$PYTHON" tools/verify_object.py "$BUILD/build_dma_address_003DBA30.o" \
 private/SLUS_204.86.rom --source src/build_dma_address_003DBA30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/dispatch_handoff_mode_0020A910.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/dispatch_handoff_mode_0020A910.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_handoff_mode_0020A910.o" \
 private/SLUS_204.86.rom --source src/dispatch_handoff_mode_0020A910.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/child_mode_dispatchers.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/child_mode_dispatchers.o"
"$PYTHON" tools/verify_object.py "$BUILD/child_mode_dispatchers.o" \
 private/SLUS_204.86.rom --source src/child_mode_dispatchers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/initialize_collision_state_002E7700.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/initialize_collision_state_002E7700.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_collision_state_002E7700.o" \
 private/SLUS_204.86.rom --source src/initialize_collision_state_002E7700.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/dispatch_child_mode_00362760.c -c -lang c -O3 -sdatathreshold 8 \
 -o "$BUILD/dispatch_child_mode_00362760.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_child_mode_00362760.o" \
 private/SLUS_204.86.rom --source src/dispatch_child_mode_00362760.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/advance_owned_event_002CE850.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/advance_owned_event_002CE850.o"
"$PYTHON" tools/verify_object.py "$BUILD/advance_owned_event_002CE850.o" \
 private/SLUS_204.86.rom --source src/advance_owned_event_002CE850.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_two_context_child_001D1B80.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_two_context_child_001D1B80.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_two_context_child_001D1B80.o" \
 private/SLUS_204.86.rom --source src/create_two_context_child_001D1B80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave11.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave11.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave11.o" private/SLUS_204.86.rom --source src/wave11.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave11b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave11b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave11b.o" private/SLUS_204.86.rom --source src/wave11b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave12.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave12.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave12.o" private/SLUS_204.86.rom --source src/wave12.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave12b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave12b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave12b.o" private/SLUS_204.86.rom --source src/wave12b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave12c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave12c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave12c.o" private/SLUS_204.86.rom --source src/wave12c.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave14.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave14.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave14.o" private/SLUS_204.86.rom --source src/wave14.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave14b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave14b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave14b.o" private/SLUS_204.86.rom --source src/wave14b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave14c.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/wave14c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave14c.o" private/SLUS_204.86.rom --source src/wave14c.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave14d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave14d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave14d.o" private/SLUS_204.86.rom --source src/wave14d.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave15.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave15.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave15.o" private/SLUS_204.86.rom --source src/wave15.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave15b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave15b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave15b.o" private/SLUS_204.86.rom --source src/wave15b.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave15p.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/wave15p.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave15p.o" private/SLUS_204.86.rom --source src/wave15p.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave9.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave9.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave9.o" private/SLUS_204.86.rom --source src/wave9.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave9b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave9b.o" private/SLUS_204.86.rom --source src/wave9b.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
 src/activate_threshold_mode_001EE480.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/activate_threshold_mode_001EE480.o"
"$PYTHON" tools/verify_object.py "$BUILD/activate_threshold_mode_001EE480.o" \
 private/SLUS_204.86.rom --source src/activate_threshold_mode_001EE480.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_two_context_state_001D8580.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_two_context_state_001D8580.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_two_context_state_001D8580.o" \
 private/SLUS_204.86.rom --source src/create_two_context_state_001D8580.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_linked_flags_event_001CCC20.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_linked_flags_event_001CCC20.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_linked_flags_event_001CCC20.o" \
 private/SLUS_204.86.rom --source src/create_linked_flags_event_001CCC20.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_inherited_mode_event_00194100.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_inherited_mode_event_00194100.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_inherited_mode_event_00194100.o" \
 private/SLUS_204.86.rom --source src/create_inherited_mode_event_00194100.c

"$WIBO" "$SNCPP" -P src/sdk_reentrant_seek_0011EAA0.c \
 "$BUILD/sdk_reentrant_seek_0011EAA0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py \
 "$BUILD/sdk_reentrant_seek_0011EAA0.i" "$BUILD/sdk_reentrant_seek_0011EAA0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk_reentrant_seek_0011EAA0.o" \
 "$BUILD/sdk_reentrant_seek_0011EAA0.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk_reentrant_seek_0011EAA0.o" \
 private/SLUS_204.86.rom --source src/sdk_reentrant_seek_0011EAA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_mode_flags_child_001CB610.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_mode_flags_child_001CB610.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_mode_flags_child_001CB610.o" \
 private/SLUS_204.86.rom --source src/create_mode_flags_child_001CB610.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
 src/create_owner_mode_timer_00199DE0.c -c -lang c -O3 -sdatathreshold 0 \
 -o "$BUILD/create_owner_mode_timer_00199DE0.o"
"$PYTHON" tools/verify_object.py "$BUILD/create_owner_mode_timer_00199DE0.o" \
 private/SLUS_204.86.rom --source src/create_owner_mode_timer_00199DE0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave16.c -c -lang c -O3 -Op -o "$BUILD/wave16.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave16.o" private/SLUS_204.86.rom --source src/wave16.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave16b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave16b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave16b.o" private/SLUS_204.86.rom --source src/wave16b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave16c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave16c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave16c.o" private/SLUS_204.86.rom --source src/wave16c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave17.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave17.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave17.o" private/SLUS_204.86.rom --source src/wave17.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave17b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave17b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave17b.o" private/SLUS_204.86.rom --source src/wave17b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave21.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave21.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave21.o" private/SLUS_204.86.rom --source src/wave21.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave21b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave21b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave21b.o" private/SLUS_204.86.rom --source src/wave21b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave2.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave2.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave2.o" private/SLUS_204.86.rom --source src/wave2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave2b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave2b.o" private/SLUS_204.86.rom --source src/wave2b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave2c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave2c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave2c.o" private/SLUS_204.86.rom --source src/wave2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave24.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave24.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave24.o" private/SLUS_204.86.rom --source src/wave24.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave24b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave24b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave24b.o" private/SLUS_204.86.rom --source src/wave24b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave24c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave24c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave24c.o" private/SLUS_204.86.rom --source src/wave24c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave20.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave20.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave20.o" private/SLUS_204.86.rom --source src/wave20.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave20b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave20b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave20b.o" private/SLUS_204.86.rom --source src/wave20b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave29.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave29.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave29.o" private/SLUS_204.86.rom --source src/wave29.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave29b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave29b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave29b.o" private/SLUS_204.86.rom --source src/wave29b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave29c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave29c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave29c.o" private/SLUS_204.86.rom --source src/wave29c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave29d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave29d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave29d.o" private/SLUS_204.86.rom --source src/wave29d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave19.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave19.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave19.o" private/SLUS_204.86.rom --source src/wave19.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave19b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/wave19b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave19b.o" private/SLUS_204.86.rom --source src/wave19b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave22.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/wave22.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave22.o" private/SLUS_204.86.rom --source src/wave22.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave18.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/wave18.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave18.o" private/SLUS_204.86.rom --source src/wave18.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave18b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/wave18b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave18b.o" private/SLUS_204.86.rom --source src/wave18b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave32.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave32.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave32.o" private/SLUS_204.86.rom --source src/wave32.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave32b.c -c -lang c -O3 -Op -o "$BUILD/wave32b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave32b.o" private/SLUS_204.86.rom --source src/wave32b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave32c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave32c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave32c.o" private/SLUS_204.86.rom --source src/wave32c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave32d.c -c -lang c -O3,p -o "$BUILD/wave32d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave32d.o" private/SLUS_204.86.rom --source src/wave32d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave25.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave25.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave25.o" private/SLUS_204.86.rom --source src/wave25.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave25b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/wave25b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave25b.o" private/SLUS_204.86.rom --source src/wave25b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave25d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave25d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave25d.o" private/SLUS_204.86.rom --source src/wave25d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave27.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27.o" private/SLUS_204.86.rom --source src/wave27.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave27b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27b.o" private/SLUS_204.86.rom --source src/wave27b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27c.c -c -lang c -O3 -Op -o "$BUILD/wave27c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27c.o" private/SLUS_204.86.rom --source src/wave27c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave27e.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27e.o" private/SLUS_204.86.rom --source src/wave27e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27f.c -c -lang c -O3 -Op -o "$BUILD/wave27f.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27f.o" private/SLUS_204.86.rom --source src/wave27f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27g.c -c -lang c -O3 -Op -o "$BUILD/wave27g.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27g.o" private/SLUS_204.86.rom --source src/wave27g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave27h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave27h.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave27h.o" private/SLUS_204.86.rom --source src/wave27h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave28.c -c -lang c -O3 -Op -o "$BUILD/wave28.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave28.o" private/SLUS_204.86.rom --source src/wave28.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave28b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave28b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave28b.o" private/SLUS_204.86.rom --source src/wave28b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave28c.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/wave28c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave28c.o" private/SLUS_204.86.rom --source src/wave28c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave28d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave28d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave28d.o" private/SLUS_204.86.rom --source src/wave28d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave31.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave31.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave31.o" private/SLUS_204.86.rom --source src/wave31.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_stage_actor_001804F0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_stage_actor_001804F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_stage_actor_001804F0.o" \
    private/SLUS_204.86.rom --source src/initialize_stage_actor_001804F0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_stage_actor_00180890.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/initialize_stage_actor_00180890.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_stage_actor_00180890.o" \
    private/SLUS_204.86.rom --source src/initialize_stage_actor_00180890.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/dispatch_stage_actor_00180F20.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/dispatch_stage_actor_00180F20.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_stage_actor_00180F20.o" \
    private/SLUS_204.86.rom --source src/dispatch_stage_actor_00180F20.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave31b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave31b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave31b.o" private/SLUS_204.86.rom --source src/wave31b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave31c.c -c -lang c -O3 -Op -o "$BUILD/wave31c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave31c.o" private/SLUS_204.86.rom --source src/wave31c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave33.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave33.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave33.o" private/SLUS_204.86.rom --source src/wave33.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave33b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave33b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave33b.o" private/SLUS_204.86.rom --source src/wave33b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave34.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave34.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave34.o" private/SLUS_204.86.rom --source src/wave34.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave34b.c -c -lang c -O3,p -o "$BUILD/wave34b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave34b.o" private/SLUS_204.86.rom --source src/wave34b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave34c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave34c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave34c.o" private/SLUS_204.86.rom --source src/wave34c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave34d.c -c -lang c -O3 -Op -o "$BUILD/wave34d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave34d.o" private/SLUS_204.86.rom --source src/wave34d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave34e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave34e.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave34e.o" private/SLUS_204.86.rom --source src/wave34e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave26.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave26.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave26.o" private/SLUS_204.86.rom --source src/wave26.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave26b.c -c -lang c -O4 -sdatathreshold 8 -o "$BUILD/wave26b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave26b.o" private/SLUS_204.86.rom --source src/wave26b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave23.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/wave23.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave23.o" private/SLUS_204.86.rom --source src/wave23.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave23b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave23b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave23b.o" private/SLUS_204.86.rom --source src/wave23b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave23c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/wave23c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave23c.o" private/SLUS_204.86.rom --source src/wave23c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave23d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave23d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave23d.o" private/SLUS_204.86.rom --source src/wave23d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave30.c -c -lang c -O3 -Op -o "$BUILD/wave30.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave30.o" private/SLUS_204.86.rom --source src/wave30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave30b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave30b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave30b.o" private/SLUS_204.86.rom --source src/wave30b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave30c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave30c.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave30c.o" private/SLUS_204.86.rom --source src/wave30c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/wave30d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/wave30d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave30d.o" private/SLUS_204.86.rom --source src/wave30d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave35.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave35.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave35.o" private/SLUS_204.86.rom --source src/wave35.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave35b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/wave35b.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave35b.o" private/SLUS_204.86.rom --source src/wave35b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave35d.c -c -lang c -O3 -Op -o "$BUILD/wave35d.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave35d.o" private/SLUS_204.86.rom --source src/wave35d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/wave35f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/wave35f.o"
"$PYTHON" tools/verify_object.py "$BUILD/wave35f.o" private/SLUS_204.86.rom --source src/wave35f.c
"$WIBO" "$SNCPP" -P src/sdk0.c "$BUILD/sdk0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0.i" "$BUILD/sdk0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0.o" "$BUILD/sdk0.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0.o" private/SLUS_204.86.rom --source src/sdk0.c
"$WIBO" "$SNCPP" -P src/sdk0b.c "$BUILD/sdk0b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0b.i" "$BUILD/sdk0b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0b.o" "$BUILD/sdk0b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0b.o" private/SLUS_204.86.rom --source src/sdk0b.c
"$WIBO" "$SNCPP" -P src/sdk0c.c "$BUILD/sdk0c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0c.i" "$BUILD/sdk0c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0c.o" "$BUILD/sdk0c.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0c.o" private/SLUS_204.86.rom --source src/sdk0c.c
"$WIBO" "$SNCPP" -P src/sdk0d.c "$BUILD/sdk0d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0d.i" "$BUILD/sdk0d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0d.o" "$BUILD/sdk0d.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0d.o" private/SLUS_204.86.rom --source src/sdk0d.c
"$WIBO" "$SNCPP" -P src/sdk0f.c "$BUILD/sdk0f.i"
"$WIBO" "$SNCC1" "$BUILD/sdk0f.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sdk0f.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0f.o" "$BUILD/sdk0f.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0f.o" private/SLUS_204.86.rom --source src/sdk0f.c
"$WIBO" "$SNCPP" -P src/sdk0g.c "$BUILD/sdk0g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0g.i" "$BUILD/sdk0g.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0g.o" "$BUILD/sdk0g.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0g.o" private/SLUS_204.86.rom --source src/sdk0g.c
"$WIBO" "$SNCPP" -P src/sdk0h.c "$BUILD/sdk0h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk0h.i" "$BUILD/sdk0h.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk0h.o" "$BUILD/sdk0h.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk0h.o" private/SLUS_204.86.rom --source src/sdk0h.c
"$WIBO" "$SNCPP" -P src/sdk1.c "$BUILD/sdk1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk1.i" "$BUILD/sdk1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk1.o" "$BUILD/sdk1.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk1.o" private/SLUS_204.86.rom --source src/sdk1.c
"$WIBO" "$SNCPP" -P src/sdk1b.c "$BUILD/sdk1b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/sdk1b.i" "$BUILD/sdk1b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/sdk1b.o" "$BUILD/sdk1b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk1b.o" private/SLUS_204.86.rom --source src/sdk1b.c
"$WIBO" "$SNCPP" -P src/sdk1c.c "$BUILD/sdk1c.i"
"$WIBO" "$SNCC1" "$BUILD/sdk1c.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sdk1c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk1c.o" "$BUILD/sdk1c.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk1c.o" private/SLUS_204.86.rom --source src/sdk1c.c
"$WIBO" "$SNCPP" -P src/sdk1d.c "$BUILD/sdk1d.i"
"$WIBO" "$SNCC1" "$BUILD/sdk1d.i" -O2 -G0 -ffunction-sections -ffixed-v0 -ffixed-v1 -quiet -o "$BUILD/sdk1d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk1d.o" "$BUILD/sdk1d.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk1d.o" private/SLUS_204.86.rom --source src/sdk1d.c
"$WIBO" "$SNCPP" -P src/sdk3.c "$BUILD/sdk3.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk3.i" "$BUILD/sdk3.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk3.o" "$BUILD/sdk3.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk3.o" private/SLUS_204.86.rom --source src/sdk3.c
"$WIBO" "$SNCPP" -P src/sdk3b.c "$BUILD/sdk3b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk3b.i" "$BUILD/sdk3b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk3b.o" "$BUILD/sdk3b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk3b.o" private/SLUS_204.86.rom --source src/sdk3b.c
"$WIBO" "$SNCPP" -P src/sdk3d.c "$BUILD/sdk3d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk3d.i" "$BUILD/sdk3d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk3d.o" "$BUILD/sdk3d.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk3d.o" private/SLUS_204.86.rom --source src/sdk3d.c
"$WIBO" "$SNCPP" -P src/sdk3e.c "$BUILD/sdk3e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk3e.i" "$BUILD/sdk3e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk3e.o" "$BUILD/sdk3e.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk3e.o" private/SLUS_204.86.rom --source src/sdk3e.c
"$WIBO" "$SNCPP" -P src/sdk3f.c "$BUILD/sdk3f.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/sdk3f.i" "$BUILD/sdk3f.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/sdk3f.o" "$BUILD/sdk3f.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk3f.o" private/SLUS_204.86.rom --source src/sdk3f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g4.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g4.o"
"$PYTHON" tools/verify_object.py "$BUILD/g4.o" private/SLUS_204.86.rom --source src/g4.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g4b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/g4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g4b.o" private/SLUS_204.86.rom --source src/g4b.c
"$WIBO" "$SNCPP" -P src/sdk4.c "$BUILD/sdk4.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk4.i" "$BUILD/sdk4.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk4.o" "$BUILD/sdk4.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk4.o" private/SLUS_204.86.rom --source src/sdk4.c
"$WIBO" "$SNCPP" -P src/sdk4c.c "$BUILD/sdk4c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/sdk4c.i" "$BUILD/sdk4c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/sdk4c.o" "$BUILD/sdk4c.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk4c.o" private/SLUS_204.86.rom --source src/sdk4c.c
"$WIBO" "$SNCPP" -P src/sdk4d.c "$BUILD/sdk4d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk4d.i" "$BUILD/sdk4d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk4d.o" "$BUILD/sdk4d.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk4d.o" private/SLUS_204.86.rom --source src/sdk4d.c
"$WIBO" "$SNCPP" -P src/sdk2.c "$BUILD/sdk2.i"
"$WIBO" "$SNCC1" "$BUILD/sdk2.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sdk2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk2.o" "$BUILD/sdk2.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2.o" private/SLUS_204.86.rom --source src/sdk2.c
"$WIBO" "$SNCPP" -P src/sdk2b.c "$BUILD/sdk2b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk2b.i" "$BUILD/sdk2b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk2b.o" "$BUILD/sdk2b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2b.o" private/SLUS_204.86.rom --source src/sdk2b.c
"$WIBO" "$SNCPP" -P src/sdk2c.c "$BUILD/sdk2c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk2c.i" "$BUILD/sdk2c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk2c.o" "$BUILD/sdk2c.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2c.o" private/SLUS_204.86.rom --source src/sdk2c.c
"$WIBO" "$SNCPP" -P src/sdk2d.c "$BUILD/sdk2d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk2d.i" "$BUILD/sdk2d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk2d.o" "$BUILD/sdk2d.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2d.o" private/SLUS_204.86.rom --source src/sdk2d.c
"$WIBO" "$SNCPP" -P src/sdk2e.c "$BUILD/sdk2e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk2e.i" "$BUILD/sdk2e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk2e.o" "$BUILD/sdk2e.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2e.o" private/SLUS_204.86.rom --source src/sdk2e.c
"$WIBO" "$SNCPP" -P src/sdk2g.c "$BUILD/sdk2g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/sdk2g.i" "$BUILD/sdk2g.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/sdk2g.o" "$BUILD/sdk2g.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk2g.o" private/SLUS_204.86.rom --source src/sdk2g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g9.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g9.o"
"$PYTHON" tools/verify_object.py "$BUILD/g9.o" private/SLUS_204.86.rom --source src/g9.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g9b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g9b.o" private/SLUS_204.86.rom --source src/g9b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g9c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g9c.o" private/SLUS_204.86.rom --source src/g9c.c
"$WIBO" "$SNCPP" -P src/sdk5.c "$BUILD/sdk5.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk5.i" "$BUILD/sdk5.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk5.o" "$BUILD/sdk5.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk5.o" private/SLUS_204.86.rom --source src/sdk5.c
"$WIBO" "$SNCPP" -P src/sdk5b.c "$BUILD/sdk5b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/sdk5b.i" "$BUILD/sdk5b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sdk5b.o" "$BUILD/sdk5b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk5b.o" private/SLUS_204.86.rom --source src/sdk5b.c
"$WIBO" "$SNCPP" -P src/sdk5c.c "$BUILD/sdk5c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/sdk5c.i" "$BUILD/sdk5c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/sdk5c.o" "$BUILD/sdk5c.s"
"$PYTHON" tools/verify_object.py "$BUILD/sdk5c.o" private/SLUS_204.86.rom --source src/sdk5c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g0.o"
"$PYTHON" tools/verify_object.py "$BUILD/g0.o" private/SLUS_204.86.rom --source src/g0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g0b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g0b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g0b.o" private/SLUS_204.86.rom --source src/g0b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g0c.c -c -lang c -O3 -Op -o "$BUILD/g0c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g0c.o" private/SLUS_204.86.rom --source src/g0c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g0d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/g0d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g0d.o" private/SLUS_204.86.rom --source src/g0d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g2.o"
"$PYTHON" tools/verify_object.py "$BUILD/g2.o" private/SLUS_204.86.rom --source src/g2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g2g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g2g.o"
"$PYTHON" tools/verify_object.py "$BUILD/g2g.o" private/SLUS_204.86.rom --source src/g2g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g2op.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g2op.o"
"$PYTHON" tools/verify_object.py "$BUILD/g2op.o" private/SLUS_204.86.rom --source src/g2op.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g2p.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/g2p.o"
"$PYTHON" tools/verify_object.py "$BUILD/g2p.o" private/SLUS_204.86.rom --source src/g2p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g2b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g2b.o" private/SLUS_204.86.rom --source src/g2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g10b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g10b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g10b.o" private/SLUS_204.86.rom --source src/g10b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g10c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g10c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g10c.o" private/SLUS_204.86.rom --source src/g10c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g10d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g10d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g10d.o" private/SLUS_204.86.rom --source src/g10d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g10e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g10e.o"
"$PYTHON" tools/verify_object.py "$BUILD/g10e.o" private/SLUS_204.86.rom --source src/g10e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g11.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g11.o"
"$PYTHON" tools/verify_object.py "$BUILD/g11.o" private/SLUS_204.86.rom --source src/g11.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g11b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g11b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g11b.o" private/SLUS_204.86.rom --source src/g11b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g11c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/g11c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g11c.o" private/SLUS_204.86.rom --source src/g11c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g11d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g11d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g11d.o" private/SLUS_204.86.rom --source src/g11d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g5.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g5.o"
"$PYTHON" tools/verify_object.py "$BUILD/g5.o" private/SLUS_204.86.rom --source src/g5.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g5b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g5b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g5b.o" private/SLUS_204.86.rom --source src/g5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g5c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g5c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g5c.o" private/SLUS_204.86.rom --source src/g5c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g5d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g5d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g5d.o" private/SLUS_204.86.rom --source src/g5d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g5e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g5e.o"
"$PYTHON" tools/verify_object.py "$BUILD/g5e.o" private/SLUS_204.86.rom --source src/g5e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g8.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g8.o"
"$PYTHON" tools/verify_object.py "$BUILD/g8.o" private/SLUS_204.86.rom --source src/g8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g8b.c -c -lang c -O3 -Op -o "$BUILD/g8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g8b.o" private/SLUS_204.86.rom --source src/g8b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g8c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g8c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g8c.o" private/SLUS_204.86.rom --source src/g8c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g13.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g13.o"
"$PYTHON" tools/verify_object.py "$BUILD/g13.o" private/SLUS_204.86.rom --source src/g13.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g13b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g13b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g13b.o" private/SLUS_204.86.rom --source src/g13b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g13c.c -c -lang c -O3 -Op -o "$BUILD/g13c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g13c.o" private/SLUS_204.86.rom --source src/g13c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12.o" private/SLUS_204.86.rom --source src/g12.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12g.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12g.o" private/SLUS_204.86.rom --source src/g12g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12h.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12h.o" private/SLUS_204.86.rom --source src/g12h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12i.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12i.o" private/SLUS_204.86.rom --source src/g12i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12l.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12l.o" private/SLUS_204.86.rom --source src/g12l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g12b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12b.o" private/SLUS_204.86.rom --source src/g12b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g12e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g12e.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12e.o" private/SLUS_204.86.rom --source src/g12e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g12d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g12d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12d.o" private/SLUS_204.86.rom --source src/g12d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g12f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/g12f.o"
"$PYTHON" tools/verify_object.py "$BUILD/g12f.o" private/SLUS_204.86.rom --source src/g12f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g1.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1.o" private/SLUS_204.86.rom --source src/g1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g1b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1b.o" private/SLUS_204.86.rom --source src/g1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1c.o" private/SLUS_204.86.rom --source src/g1c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1d.o" private/SLUS_204.86.rom --source src/g1d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/g1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1e.o" private/SLUS_204.86.rom --source src/g1e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g1f.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1f.o" private/SLUS_204.86.rom --source src/g1f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g1g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/g1g.o" private/SLUS_204.86.rom --source src/g1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g3.o"
"$PYTHON" tools/verify_object.py "$BUILD/g3.o" private/SLUS_204.86.rom --source src/g3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_tick_001A14D0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/owner_state_tick_001A14D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_tick_001A14D0.o" \
    private/SLUS_204.86.rom --source src/owner_state_tick_001A14D0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_tick_001A27A0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/owner_state_tick_001A27A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_tick_001A27A0.o" \
    private/SLUS_204.86.rom --source src/owner_state_tick_001A27A0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g3b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g3b.o" private/SLUS_204.86.rom --source src/g3b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g3c.c -c -lang c -O3 -Op -o "$BUILD/g3c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g3c.o" private/SLUS_204.86.rom --source src/g3c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g3d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g3d.o"
"$PYTHON" tools/verify_object.py "$BUILD/g3d.o" private/SLUS_204.86.rom --source src/g3d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g3e.c -c -lang c -O4,p -o "$BUILD/g3e.o"
"$PYTHON" tools/verify_object.py "$BUILD/g3e.o" private/SLUS_204.86.rom --source src/g3e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g7.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g7.o"
"$PYTHON" tools/verify_object.py "$BUILD/g7.o" private/SLUS_204.86.rom --source src/g7.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g7c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g7c.o"
"$PYTHON" tools/verify_object.py "$BUILD/g7c.o" private/SLUS_204.86.rom --source src/g7c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g7s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g7s.o"
"$PYTHON" tools/verify_object.py "$BUILD/g7s.o" private/SLUS_204.86.rom --source src/g7s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g7p.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/g7p.o"
"$PYTHON" tools/verify_object.py "$BUILD/g7p.o" private/SLUS_204.86.rom --source src/g7p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g6.c -c -lang c -O3 -Op -o "$BUILD/g6.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6.o" private/SLUS_204.86.rom --source src/g6.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g6b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g6b.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6b.o" private/SLUS_204.86.rom --source src/g6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g6g8.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g6g8.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6g8.o" private/SLUS_204.86.rom --source src/g6g8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/g6fp.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/g6fp.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6fp.o" private/SLUS_204.86.rom --source src/g6fp.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g6_30.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/g6_30.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6_30.o" private/SLUS_204.86.rom --source src/g6_30.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g6_30g8.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/g6_30g8.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6_30g8.o" private/SLUS_204.86.rom --source src/g6_30g8.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/g6_30p.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/g6_30p.o"
"$PYTHON" tools/verify_object.py "$BUILD/g6_30p.o" private/SLUS_204.86.rom --source src/g6_30p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h0.o"
"$PYTHON" tools/verify_object.py "$BUILD/h0.o" private/SLUS_204.86.rom --source src/h0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h0b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h0b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h0b.o" private/SLUS_204.86.rom --source src/h0b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h0c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h0c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h0c.o" private/SLUS_204.86.rom --source src/h0c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h1.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1.o" private/SLUS_204.86.rom --source src/h1.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h1b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h1b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1b.o" private/SLUS_204.86.rom --source src/h1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1c.o" private/SLUS_204.86.rom --source src/h1c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1d.o" private/SLUS_204.86.rom --source src/h1d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1e.o" private/SLUS_204.86.rom --source src/h1e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h1f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h1f.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1f.o" private/SLUS_204.86.rom --source src/h1f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1g.o" private/SLUS_204.86.rom --source src/h1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h1h.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1h.o" private/SLUS_204.86.rom --source src/h1h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h1i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h1i.o"
"$PYTHON" tools/verify_object.py "$BUILD/h1i.o" private/SLUS_204.86.rom --source src/h1i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h2.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2.o" private/SLUS_204.86.rom --source src/h2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h2b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2b.o" private/SLUS_204.86.rom --source src/h2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h2c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h2c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2c.o" private/SLUS_204.86.rom --source src/h2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h2d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h2d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2d.o" private/SLUS_204.86.rom --source src/h2d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h2e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h2e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2e.o" private/SLUS_204.86.rom --source src/h2e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h2f.c -c -lang c -O3 -Op -inline off -o "$BUILD/h2f.o"
"$PYTHON" tools/verify_object.py "$BUILD/h2f.o" private/SLUS_204.86.rom --source src/h2f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h3.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3.o" private/SLUS_204.86.rom --source src/h3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3b.o" private/SLUS_204.86.rom --source src/h3b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h3c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3c.o" private/SLUS_204.86.rom --source src/h3c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/h3d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3d.o" private/SLUS_204.86.rom --source src/h3d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/h3e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3e.o" private/SLUS_204.86.rom --source src/h3e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/h3f.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3f.o" private/SLUS_204.86.rom --source src/h3f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h3g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/h3g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3g.o" private/SLUS_204.86.rom --source src/h3g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h3h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h3h.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3h.o" private/SLUS_204.86.rom --source src/h3h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h3i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h3i.o"
"$PYTHON" tools/verify_object.py "$BUILD/h3i.o" private/SLUS_204.86.rom --source src/h3i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h4.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h4.o"
"$PYTHON" tools/verify_object.py "$BUILD/h4.o" private/SLUS_204.86.rom --source src/h4.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h4b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h4b.o" private/SLUS_204.86.rom --source src/h4b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h4c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h4c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h4c.o" private/SLUS_204.86.rom --source src/h4c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h4d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h4d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h4d.o" private/SLUS_204.86.rom --source src/h4d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h4e.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/h4e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h4e.o" private/SLUS_204.86.rom --source src/h4e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h5.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h5.o"
"$PYTHON" tools/verify_object.py "$BUILD/h5.o" private/SLUS_204.86.rom --source src/h5.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h5b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h5b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h5b.o" private/SLUS_204.86.rom --source src/h5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h5c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h5c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h5c.o" private/SLUS_204.86.rom --source src/h5c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h5d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h5d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h5d.o" private/SLUS_204.86.rom --source src/h5d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h5e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/h5e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h5e.o" private/SLUS_204.86.rom --source src/h5e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h6.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h6.o"
"$PYTHON" tools/verify_object.py "$BUILD/h6.o" private/SLUS_204.86.rom --source src/h6.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h6b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h6b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h6b.o" private/SLUS_204.86.rom --source src/h6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h7.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h7.o"
"$PYTHON" tools/verify_object.py "$BUILD/h7.o" private/SLUS_204.86.rom --source src/h7.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h7p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h7p.o"
"$PYTHON" tools/verify_object.py "$BUILD/h7p.o" private/SLUS_204.86.rom --source src/h7p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h7g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h7g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h7g.o" private/SLUS_204.86.rom --source src/h7g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h7c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/h7c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h7c.o" private/SLUS_204.86.rom --source src/h7c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h8.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h8.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8.o" private/SLUS_204.86.rom --source src/h8.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h8b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8b.o" private/SLUS_204.86.rom --source src/h8b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h8g.c -c -lang c -O3 -sdatathreshold 256 -o "$BUILD/h8g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8g.o" private/SLUS_204.86.rom --source src/h8g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h8h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h8h.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8h.o" private/SLUS_204.86.rom --source src/h8h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h8q.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h8q.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8q.o" private/SLUS_204.86.rom --source src/h8q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h8p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h8p.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8p.o" private/SLUS_204.86.rom --source src/h8p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h8r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h8r.o"
"$PYTHON" tools/verify_object.py "$BUILD/h8r.o" private/SLUS_204.86.rom --source src/h8r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h9.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h9.o"
"$PYTHON" tools/verify_object.py "$BUILD/h9.o" private/SLUS_204.86.rom --source src/h9.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h9b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h9b.o" private/SLUS_204.86.rom --source src/h9b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h9c.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/h9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h9c.o" private/SLUS_204.86.rom --source src/h9c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h9d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h9d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h9d.o" private/SLUS_204.86.rom --source src/h9d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h10.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h10.o"
"$PYTHON" tools/verify_object.py "$BUILD/h10.o" private/SLUS_204.86.rom --source src/h10.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h10b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h10b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h10b.o" private/SLUS_204.86.rom --source src/h10b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h10c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h10c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h10c.o" private/SLUS_204.86.rom --source src/h10c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h10d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h10d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h10d.o" private/SLUS_204.86.rom --source src/h10d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h10e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h10e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h10e.o" private/SLUS_204.86.rom --source src/h10e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h11.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11.o" private/SLUS_204.86.rom --source src/h11.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h11b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h11b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11b.o" private/SLUS_204.86.rom --source src/h11b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h11c.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11c.o" private/SLUS_204.86.rom --source src/h11c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h11d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11d.o" private/SLUS_204.86.rom --source src/h11d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/h11f.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11f.o" private/SLUS_204.86.rom --source src/h11f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h11g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11g.o" private/SLUS_204.86.rom --source src/h11g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h11h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h11h.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11h.o" private/SLUS_204.86.rom --source src/h11h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h11i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/h11i.o"
"$PYTHON" tools/verify_object.py "$BUILD/h11i.o" private/SLUS_204.86.rom --source src/h11i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h12.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h12.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12.o" private/SLUS_204.86.rom --source src/h12.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h12b.c -c -lang c -O3 -Op -o "$BUILD/h12b.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12b.o" private/SLUS_204.86.rom --source src/h12b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h12d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h12d.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12d.o" private/SLUS_204.86.rom --source src/h12d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h12e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/h12e.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12e.o" private/SLUS_204.86.rom --source src/h12e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/h12f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/h12f.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12f.o" private/SLUS_204.86.rom --source src/h12f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h12g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h12g.o"
"$PYTHON" tools/verify_object.py "$BUILD/h12g.o" private/SLUS_204.86.rom --source src/h12g.c
"$WIBO" "$SNCPP" -P src/k0.c "$BUILD/k0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k0.i" "$BUILD/k0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k0.o" "$BUILD/k0.s"
"$PYTHON" tools/verify_object.py "$BUILD/k0.o" private/SLUS_204.86.rom --source src/k0.c
"$WIBO" "$SNCPP" -P src/k0a.c "$BUILD/k0a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k0a.i" "$BUILD/k0a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k0a.o" "$BUILD/k0a.s"
"$PYTHON" tools/verify_object.py "$BUILD/k0a.o" private/SLUS_204.86.rom --source src/k0a.c
"$WIBO" "$SNCPP" -P src/k0b.c "$BUILD/k0b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k0b.i" "$BUILD/k0b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k0b.o" "$BUILD/k0b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k0b.o" private/SLUS_204.86.rom --source src/k0b.c
"$WIBO" "$SNCPP" -P src/k1.c "$BUILD/k1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k1.i" "$BUILD/k1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k1.o" "$BUILD/k1.s"
"$PYTHON" tools/verify_object.py "$BUILD/k1.o" private/SLUS_204.86.rom --source src/k1.c
"$WIBO" "$SNCPP" -P src/k1a.c "$BUILD/k1a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k1a.i" "$BUILD/k1a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k1a.o" "$BUILD/k1a.s"
"$PYTHON" tools/verify_object.py "$BUILD/k1a.o" private/SLUS_204.86.rom --source src/k1a.c
"$WIBO" "$SNCPP" -P src/k1b.c "$BUILD/k1b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k1b.i" "$BUILD/k1b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k1b.o" "$BUILD/k1b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k1b.o" private/SLUS_204.86.rom --source src/k1b.c
"$WIBO" "$SNCPP" -P src/k2.c "$BUILD/k2.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k2.i" "$BUILD/k2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k2.o" "$BUILD/k2.s"
"$PYTHON" tools/verify_object.py "$BUILD/k2.o" private/SLUS_204.86.rom --source src/k2.c
"$WIBO" "$SNCPP" -P src/k2b.c "$BUILD/k2b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k2b.i" "$BUILD/k2b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k2b.o" "$BUILD/k2b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k2b.o" private/SLUS_204.86.rom --source src/k2b.c
"$WIBO" "$SNCPP" -P src/k2s.c "$BUILD/k2s.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k2s.i" "$BUILD/k2s.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k2s.o" "$BUILD/k2s.s"
"$PYTHON" tools/verify_object.py "$BUILD/k2s.o" private/SLUS_204.86.rom --source src/k2s.c
"$WIBO" "$SNCPP" -P src/k3.c "$BUILD/k3.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k3.i" "$BUILD/k3.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k3.o" "$BUILD/k3.s"
"$PYTHON" tools/verify_object.py "$BUILD/k3.o" private/SLUS_204.86.rom --source src/k3.c
"$WIBO" "$SNCPP" -P src/k4.c "$BUILD/k4.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k4.i" "$BUILD/k4.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k4.o" "$BUILD/k4.s"
"$PYTHON" tools/verify_object.py "$BUILD/k4.o" private/SLUS_204.86.rom --source src/k4.c
"$WIBO" "$SNCPP" -P src/k4b.c "$BUILD/k4b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k4b.i" "$BUILD/k4b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k4b.o" "$BUILD/k4b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k4b.o" private/SLUS_204.86.rom --source src/k4b.c
"$WIBO" "$SNCPP" -P src/k5.c "$BUILD/k5.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k5.i" "$BUILD/k5.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k5.o" "$BUILD/k5.s"
"$PYTHON" tools/verify_object.py "$BUILD/k5.o" private/SLUS_204.86.rom --source src/k5.c
"$WIBO" "$SNCPP" -P src/k5b.c "$BUILD/k5b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k5b.i" "$BUILD/k5b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k5b.o" "$BUILD/k5b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k5b.o" private/SLUS_204.86.rom --source src/k5b.c
"$WIBO" "$SNCPP" -P src/k5h.c "$BUILD/k5h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k5h.i" "$BUILD/k5h.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k5h.o" "$BUILD/k5h.s"
"$PYTHON" tools/verify_object.py "$BUILD/k5h.o" private/SLUS_204.86.rom --source src/k5h.c
"$WIBO" "$SNCPP" -P src/k6.c "$BUILD/k6.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k6.i" "$BUILD/k6.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k6.o" "$BUILD/k6.s"
"$PYTHON" tools/verify_object.py "$BUILD/k6.o" private/SLUS_204.86.rom --source src/k6.c
"$WIBO" "$SNCPP" -P src/k6a.c "$BUILD/k6a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 "$BUILD/k6a.i" "$BUILD/k6a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/k6a.o" "$BUILD/k6a.s"
"$PYTHON" tools/verify_object.py "$BUILD/k6a.o" private/SLUS_204.86.rom --source src/k6a.c
"$WIBO" "$SNCPP" -P src/k6b.c "$BUILD/k6b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 "$BUILD/k6b.i" "$BUILD/k6b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/k6b.o" "$BUILD/k6b.s"
"$PYTHON" tools/verify_object.py "$BUILD/k6b.o" private/SLUS_204.86.rom --source src/k6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/h6s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/h6s.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @23=jtbl_004B3AA0 \
    "$BUILD/h6s.o" "$BUILD/h6s.o"
"$PYTHON" tools/verify_object.py "$BUILD/h6s.o" private/SLUS_204.86.rom --source src/h6s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m0.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m0.o"
"$PYTHON" tools/verify_object.py "$BUILD/m0.o" private/SLUS_204.86.rom --source src/m0.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m0b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m0b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m0b.o" private/SLUS_204.86.rom --source src/m0b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m0c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m0c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m0c.o" private/SLUS_204.86.rom --source src/m0c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m1.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m1.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1.o" private/SLUS_204.86.rom --source src/m1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m1b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m1b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1b.o" private/SLUS_204.86.rom --source src/m1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m1c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1c.o" private/SLUS_204.86.rom --source src/m1c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m1d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1d.o" private/SLUS_204.86.rom --source src/m1d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m1e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1e.o" private/SLUS_204.86.rom --source src/m1e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m1f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m1f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1f.o" private/SLUS_204.86.rom --source src/m1f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m1g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m1g.o" private/SLUS_204.86.rom --source src/m1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m3.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3.o" private/SLUS_204.86.rom --source src/m3.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m3b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3b.o" private/SLUS_204.86.rom --source src/m3b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m3c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3c.o" private/SLUS_204.86.rom --source src/m3c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m3e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3e.o" private/SLUS_204.86.rom --source src/m3e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m3f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3f.o" private/SLUS_204.86.rom --source src/m3f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m3g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3g.o" private/SLUS_204.86.rom --source src/m3g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m3h.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3h.o" private/SLUS_204.86.rom --source src/m3h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m3i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3i.o" private/SLUS_204.86.rom --source src/m3i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m3j.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3j.o" private/SLUS_204.86.rom --source src/m3j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m4.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4.o" private/SLUS_204.86.rom --source src/m4.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m4b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4b.o" private/SLUS_204.86.rom --source src/m4b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m4c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4c.o" private/SLUS_204.86.rom --source src/m4c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m5.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5.o" private/SLUS_204.86.rom --source src/m5.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m5b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5b.o" private/SLUS_204.86.rom --source src/m5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m5c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5c.o" private/SLUS_204.86.rom --source src/m5c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m5d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5d.o" private/SLUS_204.86.rom --source src/m5d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m5f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m5f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5f.o" private/SLUS_204.86.rom --source src/m5f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5g.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/m5g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5g.o" private/SLUS_204.86.rom --source src/m5g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m6.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6.o" private/SLUS_204.86.rom --source src/m6.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m6b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6b.o" private/SLUS_204.86.rom --source src/m6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m6c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6c.o" private/SLUS_204.86.rom --source src/m6c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6d.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/m6d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6d.o" private/SLUS_204.86.rom --source src/m6d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m6e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m6e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6e.o" private/SLUS_204.86.rom --source src/m6e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m7.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m7.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7.o" private/SLUS_204.86.rom --source src/m7.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m7b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m7b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7b.o" private/SLUS_204.86.rom --source src/m7b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m7c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m7c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7c.o" private/SLUS_204.86.rom --source src/m7c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m7d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m7d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7d.o" private/SLUS_204.86.rom --source src/m7d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m7e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m7e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7e.o" private/SLUS_204.86.rom --source src/m7e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m7f.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/m7f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7f.o" private/SLUS_204.86.rom --source src/m7f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8.o" private/SLUS_204.86.rom --source src/m8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8b.o" private/SLUS_204.86.rom --source src/m8b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8c.o" private/SLUS_204.86.rom --source src/m8c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m8d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8d.o" private/SLUS_204.86.rom --source src/m8d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8e.o" private/SLUS_204.86.rom --source src/m8e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8f.o" private/SLUS_204.86.rom --source src/m8f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m8g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8g.o" private/SLUS_204.86.rom --source src/m8g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8i.o" private/SLUS_204.86.rom --source src/m8i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8j.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8j.o" private/SLUS_204.86.rom --source src/m8j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8k.c -c -lang c -O3 -Op -fp off -o "$BUILD/m8k.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8k.o" private/SLUS_204.86.rom --source src/m8k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8m.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8m.o" private/SLUS_204.86.rom --source src/m8m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8n.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8n.o" private/SLUS_204.86.rom --source src/m8n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m9.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m9.o"
"$PYTHON" tools/verify_object.py "$BUILD/m9.o" private/SLUS_204.86.rom --source src/m9.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m9b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m9b.o" private/SLUS_204.86.rom --source src/m9b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m9c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m9c.o" private/SLUS_204.86.rom --source src/m9c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m9d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m9d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m9d.o" private/SLUS_204.86.rom --source src/m9d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m9e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m9e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m9e.o" private/SLUS_204.86.rom --source src/m9e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m10.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10.o" private/SLUS_204.86.rom --source src/m10.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m10b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m10b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10b.o" private/SLUS_204.86.rom --source src/m10b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m10c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10c.o" private/SLUS_204.86.rom --source src/m10c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m10d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10d.o" private/SLUS_204.86.rom --source src/m10d.c
"$WIBO" "$SNCPP" -P src/s0.c "$BUILD/s0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s0.i" "$BUILD/s0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s0.o" "$BUILD/s0.s"
"$PYTHON" tools/verify_object.py "$BUILD/s0.o" private/SLUS_204.86.rom --source src/s0.c
"$WIBO" "$SNCPP" -P src/s0b.c "$BUILD/s0b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s0b.i" "$BUILD/s0b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s0b.o" "$BUILD/s0b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s0b.o" private/SLUS_204.86.rom --source src/s0b.c
"$WIBO" "$SNCPP" -P src/s0h.c "$BUILD/s0h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s0h.i" "$BUILD/s0h.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s0h.o" "$BUILD/s0h.s"
"$PYTHON" tools/verify_object.py "$BUILD/s0h.o" private/SLUS_204.86.rom --source src/s0h.c
"$WIBO" "$SNCPP" -P src/s1.c "$BUILD/s1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s1.i" "$BUILD/s1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s1.o" "$BUILD/s1.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1.o" private/SLUS_204.86.rom --source src/s1.c
"$WIBO" "$SNCPP" -P src/s1b.c "$BUILD/s1b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s1b.i" "$BUILD/s1b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s1b.o" "$BUILD/s1b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1b.o" private/SLUS_204.86.rom --source src/s1b.c
"$WIBO" "$SNCPP" -P src/s1f.c "$BUILD/s1f.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s1f.i" "$BUILD/s1f.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s1f.o" "$BUILD/s1f.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1f.o" private/SLUS_204.86.rom --source src/s1f.c
"$WIBO" "$SNCPP" -P src/s1g.c "$BUILD/s1g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s1g.i" "$BUILD/s1g.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s1g.o" "$BUILD/s1g.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1g.o" private/SLUS_204.86.rom --source src/s1g.c
"$WIBO" "$SNCPP" -P src/s1j.c "$BUILD/s1j.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s1j.i" "$BUILD/s1j.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s1j.o" "$BUILD/s1j.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1j.o" private/SLUS_204.86.rom --source src/s1j.c
"$WIBO" "$SNCPP" -P src/s1k.c "$BUILD/s1k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s1k.i" "$BUILD/s1k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s1k.o" "$BUILD/s1k.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1k.o" private/SLUS_204.86.rom --source src/s1k.c
"$WIBO" "$SNCPP" -P src/s1l.c "$BUILD/s1l.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s1l.i" "$BUILD/s1l.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s1l.o" "$BUILD/s1l.s"
"$PYTHON" tools/verify_object.py "$BUILD/s1l.o" private/SLUS_204.86.rom --source src/s1l.c
"$WIBO" "$SNCPP" -P src/s3.c "$BUILD/s3.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s3.i" "$BUILD/s3.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s3.o" "$BUILD/s3.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3.o" private/SLUS_204.86.rom --source src/s3.c
"$WIBO" "$SNCPP" -P src/s3b.c "$BUILD/s3b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s3b.i" "$BUILD/s3b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s3b.o" "$BUILD/s3b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3b.o" private/SLUS_204.86.rom --source src/s3b.c
"$WIBO" "$SNCPP" -P src/s3v.c "$BUILD/s3v.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s3v.i" "$BUILD/s3v.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s3v.o" "$BUILD/s3v.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3v.o" private/SLUS_204.86.rom --source src/s3v.c
"$WIBO" "$SNCPP" -P src/s4.c "$BUILD/s4.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s4.i" "$BUILD/s4.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s4.o" "$BUILD/s4.s"
"$PYTHON" tools/verify_object.py "$BUILD/s4.o" private/SLUS_204.86.rom --source src/s4.c
"$WIBO" "$SNCPP" -P src/s4b.c "$BUILD/s4b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s4b.i" "$BUILD/s4b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s4b.o" "$BUILD/s4b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s4b.o" private/SLUS_204.86.rom --source src/s4b.c
"$WIBO" "$SNCPP" -P src/s5.c "$BUILD/s5.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s5.i" "$BUILD/s5.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s5.o" "$BUILD/s5.s"
"$PYTHON" tools/verify_object.py "$BUILD/s5.o" private/SLUS_204.86.rom --source src/s5.c
"$WIBO" "$SNCPP" -P src/s5a.c "$BUILD/s5a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s5a.i" "$BUILD/s5a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s5a.o" "$BUILD/s5a.s"
"$PYTHON" tools/verify_object.py "$BUILD/s5a.o" private/SLUS_204.86.rom --source src/s5a.c
"$WIBO" "$SNCPP" -P src/s5b.c "$BUILD/s5b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s5b.i" "$BUILD/s5b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s5b.o" "$BUILD/s5b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s5b.o" private/SLUS_204.86.rom --source src/s5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r1e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/r1e.o" private/SLUS_204.86.rom --source src/r1e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r1g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/r1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/r1g.o" private/SLUS_204.86.rom --source src/r1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r1h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r1h.o"
"$PYTHON" tools/verify_object.py "$BUILD/r1h.o" private/SLUS_204.86.rom --source src/r1h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r1l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r1l.o"
"$PYTHON" tools/verify_object.py "$BUILD/r1l.o" private/SLUS_204.86.rom --source src/r1l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r2.o"
"$PYTHON" tools/verify_object.py "$BUILD/r2.o" private/SLUS_204.86.rom --source src/r2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r2b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/r2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/r2b.o" private/SLUS_204.86.rom --source src/r2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m2.o"
"$PYTHON" tools/verify_object.py "$BUILD/m2.o" private/SLUS_204.86.rom --source src/m2.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m2b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m2b.o" private/SLUS_204.86.rom --source src/m2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m2c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m2c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m2c.o" private/SLUS_204.86.rom --source src/m2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m2d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m2d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m2d.o" private/SLUS_204.86.rom --source src/m2d.c
"$WIBO" "$SNCPP" -P src/s2.c "$BUILD/s2.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s2.i" "$BUILD/s2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s2.o" "$BUILD/s2.s"
"$PYTHON" tools/verify_object.py "$BUILD/s2.o" private/SLUS_204.86.rom --source src/s2.c
"$WIBO" "$SNCPP" -P src/s2b.c "$BUILD/s2b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/s2b.i" "$BUILD/s2b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s2b.o" "$BUILD/s2b.s"
"$PYTHON" tools/verify_object.py "$BUILD/s2b.o" private/SLUS_204.86.rom --source src/s2b.c
"$WIBO" "$SNCPP" -P src/s2c.c "$BUILD/s2c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s2c.i" "$BUILD/s2c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s2c.o" "$BUILD/s2c.s"
"$PYTHON" tools/verify_object.py "$BUILD/s2c.o" private/SLUS_204.86.rom --source src/s2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s2m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/s2m.o"
"$PYTHON" tools/verify_object.py "$BUILD/s2m.o" private/SLUS_204.86.rom --source src/s2m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/r0.o"
"$PYTHON" tools/verify_object.py "$BUILD/r0.o" private/SLUS_204.86.rom --source src/r0.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/r0d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/r0d.o"
"$PYTHON" tools/verify_object.py "$BUILD/r0d.o" private/SLUS_204.86.rom --source src/r0d.c
"$WIBO" "$SNCPP" -P src/r0b.c "$BUILD/r0b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/r0b.i" "$BUILD/r0b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/r0b.o" "$BUILD/r0b.s"
"$PYTHON" tools/verify_object.py "$BUILD/r0b.o" private/SLUS_204.86.rom --source src/r0b.c
"$WIBO" "$SNCPP" -P src/s3o1.c "$BUILD/s3o1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O1 "$BUILD/s3o1.i" "$BUILD/s3o1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s3o1.o" "$BUILD/s3o1.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3o1.o" private/SLUS_204.86.rom --source src/s3o1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r1m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r1m.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @13=jtbl_004B1200 \
    "$BUILD/r1m.o" "$BUILD/r1m.o"
"$PYTHON" tools/verify_object.py "$BUILD/r1m.o" private/SLUS_204.86.rom --source src/r1m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n2.o"
"$PYTHON" tools/verify_object.py "$BUILD/n2.o" private/SLUS_204.86.rom --source src/n2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n2b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n2b.o" private/SLUS_204.86.rom --source src/n2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n2c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n2c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n2c.o" private/SLUS_204.86.rom --source src/n2c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n2d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n2d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n2d.o" private/SLUS_204.86.rom --source src/n2d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n2e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n2e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n2e.o" private/SLUS_204.86.rom --source src/n2e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n3.o"
"$PYTHON" tools/verify_object.py "$BUILD/n3.o" private/SLUS_204.86.rom --source src/n3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n3b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n3b.o" private/SLUS_204.86.rom --source src/n3b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n3c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n3c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n3c.o" private/SLUS_204.86.rom --source src/n3c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n3d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n3d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n3d.o" private/SLUS_204.86.rom --source src/n3d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n3e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n3e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n3e.o" private/SLUS_204.86.rom --source src/n3e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n5.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/n5.o"
"$PYTHON" tools/verify_object.py "$BUILD/n5.o" private/SLUS_204.86.rom --source src/n5.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n5b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n5b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n5b.o" private/SLUS_204.86.rom --source src/n5b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n7.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n7.o"
"$PYTHON" tools/verify_object.py "$BUILD/n7.o" private/SLUS_204.86.rom --source src/n7.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n7b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n7b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n7b.o" private/SLUS_204.86.rom --source src/n7b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n7c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n7c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n7c.o" private/SLUS_204.86.rom --source src/n7c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n7e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n7e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n7e.o" private/SLUS_204.86.rom --source src/n7e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n7f.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/n7f.o"
"$PYTHON" tools/verify_object.py "$BUILD/n7f.o" private/SLUS_204.86.rom --source src/n7f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n8.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/n8.o"
"$PYTHON" tools/verify_object.py "$BUILD/n8.o" private/SLUS_204.86.rom --source src/n8.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n8b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n8b.o" private/SLUS_204.86.rom --source src/n8b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n8c.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/n8c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n8c.o" private/SLUS_204.86.rom --source src/n8c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n8d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/n8d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n8d.o" private/SLUS_204.86.rom --source src/n8d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n10.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n10.o"
"$PYTHON" tools/verify_object.py "$BUILD/n10.o" private/SLUS_204.86.rom --source src/n10.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n10b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n10b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n10b.o" private/SLUS_204.86.rom --source src/n10b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n10c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n10c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n10c.o" private/SLUS_204.86.rom --source src/n10c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n10d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n10d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n10d.o" private/SLUS_204.86.rom --source src/n10d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n10e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n10e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n10e.o" private/SLUS_204.86.rom --source src/n10e.c
"$WIBO" "$SNCPP" -P src/p1.c "$BUILD/p1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p1.i" "$BUILD/p1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p1.o" "$BUILD/p1.s"
"$PYTHON" tools/verify_object.py "$BUILD/p1.o" private/SLUS_204.86.rom --source src/p1.c
"$WIBO" "$SNCPP" -P src/p1b.c "$BUILD/p1b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p1b.i" "$BUILD/p1b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p1b.o" "$BUILD/p1b.s"
"$PYTHON" tools/verify_object.py "$BUILD/p1b.o" private/SLUS_204.86.rom --source src/p1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p1c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/p1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/p1c.o" private/SLUS_204.86.rom --source src/p1c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p1d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/p1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/p1d.o" private/SLUS_204.86.rom --source src/p1d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/p1e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/p1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/p1e.o" private/SLUS_204.86.rom --source src/p1e.c
"$WIBO" "$SNCPP" -P src/p3.c "$BUILD/p3.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p3.i" "$BUILD/p3.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p3.o" "$BUILD/p3.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3.o" private/SLUS_204.86.rom --source src/p3.c
"$WIBO" "$SNCPP" -P src/p3c.c "$BUILD/p3c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p3c.i" "$BUILD/p3c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p3c.o" "$BUILD/p3c.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3c.o" private/SLUS_204.86.rom --source src/p3c.c
"$WIBO" "$SNCPP" -P src/p3i.c "$BUILD/p3i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p3i.i" "$BUILD/p3i.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p3i.o" "$BUILD/p3i.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3i.o" private/SLUS_204.86.rom --source src/p3i.c
"$WIBO" "$SNCPP" -P src/p3j.c "$BUILD/p3j.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p3j.i" "$BUILD/p3j.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p3j.o" "$BUILD/p3j.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3j.o" private/SLUS_204.86.rom --source src/p3j.c
"$WIBO" "$SNCPP" -P src/p3k.c "$BUILD/p3k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p3k.i" "$BUILD/p3k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p3k.o" "$BUILD/p3k.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3k.o" private/SLUS_204.86.rom --source src/p3k.c
"$WIBO" "$SNCPP" -P src/p3s.c "$BUILD/p3s.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O1 "$BUILD/p3s.i" "$BUILD/p3s.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p3s.o" "$BUILD/p3s.s"
"$PYTHON" tools/verify_object.py "$BUILD/p3s.o" private/SLUS_204.86.rom --source src/p3s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p3m.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/p3m.o"
"$PYTHON" tools/verify_object.py "$BUILD/p3m.o" private/SLUS_204.86.rom --source src/p3m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p3r.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/p3r.o"
"$PYTHON" tools/verify_object.py "$BUILD/p3r.o" private/SLUS_204.86.rom --source src/p3r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p3p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/p3p.o"
"$PYTHON" tools/verify_object.py "$BUILD/p3p.o" private/SLUS_204.86.rom --source src/p3p.c
"$WIBO" "$SNCPP" -P src/p4.c "$BUILD/p4.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p4.i" "$BUILD/p4.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p4.o" "$BUILD/p4.s"
"$PYTHON" tools/verify_object.py "$BUILD/p4.o" private/SLUS_204.86.rom --source src/p4.c
"$WIBO" "$SNCPP" -P src/p4e.c "$BUILD/p4e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p4e.i" "$BUILD/p4e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p4e.o" "$BUILD/p4e.s"
"$PYTHON" tools/verify_object.py "$BUILD/p4e.o" private/SLUS_204.86.rom --source src/p4e.c
"$WIBO" "$SNCPP" -P src/p4g.c "$BUILD/p4g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p4g.i" "$BUILD/p4g.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p4g.o" "$BUILD/p4g.s"
"$PYTHON" tools/verify_object.py "$BUILD/p4g.o" private/SLUS_204.86.rom --source src/p4g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p4m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/p4m.o"
"$PYTHON" tools/verify_object.py "$BUILD/p4m.o" private/SLUS_204.86.rom --source src/p4m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p4f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/p4f.o"
"$PYTHON" tools/verify_object.py "$BUILD/p4f.o" private/SLUS_204.86.rom --source src/p4f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n1.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1.o" private/SLUS_204.86.rom --source src/n1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1b.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/n1b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1b.o" private/SLUS_204.86.rom --source src/n1b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1c.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/n1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1c.o" private/SLUS_204.86.rom --source src/n1c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1d.c -c -lang c -O3,p -Op -sdatathreshold 8 -o "$BUILD/n1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1d.o" private/SLUS_204.86.rom --source src/n1d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n1e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/n1e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1e.o" private/SLUS_204.86.rom --source src/n1e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1g.c -c -lang c -O3,p -Op -sdatathreshold 8 -o "$BUILD/n1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1g.o" private/SLUS_204.86.rom --source src/n1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1i.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/n1i.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1i.o" private/SLUS_204.86.rom --source src/n1i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n1j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/n1j.o"
"$PYTHON" tools/verify_object.py "$BUILD/n1j.o" private/SLUS_204.86.rom --source src/n1j.c
"$WIBO" "$SNCPP" -P src/n1k.c "$BUILD/n1k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/n1k.i" "$BUILD/n1k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/n1k.o" "$BUILD/n1k.s"
"$PYTHON" tools/verify_object.py "$BUILD/n1k.o" private/SLUS_204.86.rom --source src/n1k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3.o" private/SLUS_204.86.rom --source src/q3.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3o.o" private/SLUS_204.86.rom --source src/q3o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q3p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3p.o" private/SLUS_204.86.rom --source src/q3p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3g.o" private/SLUS_204.86.rom --source src/q3g.c
"$WIBO" "$SNCPP" -P src/q3e.c "$BUILD/q3e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/q3e.i" "$BUILD/q3e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/q3e.o" "$BUILD/q3e.s"
"$PYTHON" tools/verify_object.py "$BUILD/q3e.o" private/SLUS_204.86.rom --source src/q3e.c
"$WIBO" "$SNCPP" -P src/p0.c "$BUILD/p0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p0.i" "$BUILD/p0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p0.o" "$BUILD/p0.s"
"$PYTHON" tools/verify_object.py "$BUILD/p0.o" private/SLUS_204.86.rom --source src/p0.c
"$WIBO" "$SNCPP" -P src/p0a.c "$BUILD/p0a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p0a.i" "$BUILD/p0a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p0a.o" "$BUILD/p0a.s"
"$PYTHON" tools/verify_object.py "$BUILD/p0a.o" private/SLUS_204.86.rom --source src/p0a.c
"$WIBO" "$SNCPP" -P src/p0g.c "$BUILD/p0g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 "$BUILD/p0g.i" "$BUILD/p0g.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/p0g.o" "$BUILD/p0g.s"
"$PYTHON" tools/verify_object.py "$BUILD/p0g.o" private/SLUS_204.86.rom --source src/p0g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p0m.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/p0m.o"
"$PYTHON" tools/verify_object.py "$BUILD/p0m.o" private/SLUS_204.86.rom --source src/p0m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q2d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q2d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2d.o" private/SLUS_204.86.rom --source src/q2d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q2e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q2e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2e.o" private/SLUS_204.86.rom --source src/q2e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n4.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n4.o"
"$PYTHON" tools/verify_object.py "$BUILD/n4.o" private/SLUS_204.86.rom --source src/n4.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n4b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/n4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n4b.o" private/SLUS_204.86.rom --source src/n4b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n4c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n4c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n4c.o" private/SLUS_204.86.rom --source src/n4c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n4d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n4d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n4d.o" private/SLUS_204.86.rom --source src/n4d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n4e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n4e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n4e.o" private/SLUS_204.86.rom --source src/n4e.c
"$WIBO" "$SNCPP" -P src/p2.c "$BUILD/p2.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/p2.i" "$BUILD/p2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p2.o" "$BUILD/p2.s"
"$PYTHON" tools/verify_object.py "$BUILD/p2.o" private/SLUS_204.86.rom --source src/p2.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/p2b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/p2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/p2b.o" private/SLUS_204.86.rom --source src/p2b.c
"$WIBO" "$SNCPP" -P src/p2c.c "$BUILD/p2c.i"
"$WIBO" "$SNCC1" "$BUILD/p2c.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/p2c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/p2c.o" "$BUILD/p2c.s"
"$PYTHON" tools/verify_object.py "$BUILD/p2c.o" private/SLUS_204.86.rom --source src/p2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n9.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n9.o"
"$PYTHON" tools/verify_object.py "$BUILD/n9.o" private/SLUS_204.86.rom --source src/n9.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n9b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n9b.o" private/SLUS_204.86.rom --source src/n9b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n9c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n9c.o" private/SLUS_204.86.rom --source src/n9c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n9d.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/n9d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n9d.o" private/SLUS_204.86.rom --source src/n9d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_0013C350.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/func_0013C350.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_0013C350.o" private/SLUS_204.86.rom --source src/func_0013C350.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_001385D0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_001385D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_001385D0.o" private/SLUS_204.86.rom --source src/func_001385D0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00138650.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00138650.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00138650.o" private/SLUS_204.86.rom --source src/func_00138650.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00139AB0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00139AB0.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00139AB0.o" private/SLUS_204.86.rom --source src/func_00139AB0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_0013A230.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_0013A230.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_0013A230.o" private/SLUS_204.86.rom --source src/func_0013A230.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00155620.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00155620.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00155620.o" private/SLUS_204.86.rom --source src/func_00155620.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_0015A520.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_0015A520.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_0015A520.o" private/SLUS_204.86.rom --source src/func_0015A520.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00162430.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00162430.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00162430.o" private/SLUS_204.86.rom --source src/func_00162430.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_0016C3F0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/func_0016C3F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_0016C3F0.o" private/SLUS_204.86.rom --source src/func_0016C3F0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00176980.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00176980.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00176980.o" private/SLUS_204.86.rom --source src/func_00176980.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/func_00163110.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/func_00163110.o"
"$PYTHON" tools/verify_object.py "$BUILD/func_00163110.o" private/SLUS_204.86.rom --source src/func_00163110.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n9p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n9p.o"
"$PYTHON" tools/verify_object.py "$BUILD/n9p.o" private/SLUS_204.86.rom --source src/n9p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q0.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0.o" private/SLUS_204.86.rom --source src/q0.c
"$WIBO" "$SNCPP" -P src/q0e.c "$BUILD/q0e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/q0e.i" "$BUILD/q0e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/q0e.o" "$BUILD/q0e.s"
"$PYTHON" tools/verify_object.py "$BUILD/q0e.o" private/SLUS_204.86.rom --source src/q0e.c
"$WIBO" "$SNCPP" -P src/q0e1.c "$BUILD/q0e1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O1 --extra-flags="-fschedule-insns2" "$BUILD/q0e1.i" "$BUILD/q0e1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/q0e1.o" "$BUILD/q0e1.s"
"$PYTHON" tools/verify_object.py "$BUILD/q0e1.o" private/SLUS_204.86.rom --source src/q0e1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q1c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1c.o" private/SLUS_204.86.rom --source src/q1c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q1g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1g.o" private/SLUS_204.86.rom --source src/q1g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1h.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q1h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1h.o" private/SLUS_204.86.rom --source src/q1h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1d.o" private/SLUS_204.86.rom --source src/q1d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n6.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n6.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6.o" private/SLUS_204.86.rom --source src/n6.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n6b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n6b.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6b.o" private/SLUS_204.86.rom --source src/n6b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n6c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n6c.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6c.o" private/SLUS_204.86.rom --source src/n6c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n6d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n6d.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6d.o" private/SLUS_204.86.rom --source src/n6d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n6e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/n6e.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6e.o" private/SLUS_204.86.rom --source src/n6e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n6f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/n6f.o"
"$PYTHON" tools/verify_object.py "$BUILD/n6f.o" private/SLUS_204.86.rom --source src/n6f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n0.o"
"$PYTHON" tools/verify_object.py "$BUILD/n0.o" private/SLUS_204.86.rom --source src/n0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n0g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/n0g.o"
"$PYTHON" tools/verify_object.py "$BUILD/n0g.o" private/SLUS_204.86.rom --source src/n0g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/n0op.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/n0op.o"
"$PYTHON" tools/verify_object.py "$BUILD/n0op.o" private/SLUS_204.86.rom --source src/n0op.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/n030.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/n030.o"
"$PYTHON" tools/verify_object.py "$BUILD/n030.o" private/SLUS_204.86.rom --source src/n030.c
"$WIBO" "$SNCPP" -P src/s39a.c "$BUILD/s39a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/s39a.i" "$BUILD/s39a.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s39a.o" "$BUILD/s39a.s"
"$PYTHON" tools/verify_object.py "$BUILD/s39a.o" private/SLUS_204.86.rom --source src/s39a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/s39b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/s39b.o"
"$PYTHON" tools/verify_object.py "$BUILD/s39b.o" private/SLUS_204.86.rom --source src/s39b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s39c.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/s39c.o"
"$PYTHON" tools/verify_object.py "$BUILD/s39c.o" private/SLUS_204.86.rom --source src/s39c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s39d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/s39d.o"
"$PYTHON" tools/verify_object.py "$BUILD/s39d.o" private/SLUS_204.86.rom --source src/s39d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m5h.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5h.o" private/SLUS_204.86.rom --source src/m5h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m5j.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5j.o" private/SLUS_204.86.rom --source src/m5j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m5k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m5k.o"
"$PYTHON" tools/verify_object.py "$BUILD/m5k.o" private/SLUS_204.86.rom --source src/m5k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m15.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15.o" private/SLUS_204.86.rom --source src/m15.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m15b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m15b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15b.o" private/SLUS_204.86.rom --source src/m15b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m15c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15c.o" private/SLUS_204.86.rom --source src/m15c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m15d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15d.o" private/SLUS_204.86.rom --source src/m15d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m15e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15e.o" private/SLUS_204.86.rom --source src/m15e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m15f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15f.o" private/SLUS_204.86.rom --source src/m15f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m15g.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/m15g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m15g.o" private/SLUS_204.86.rom --source src/m15g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m3k.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3k.o" private/SLUS_204.86.rom --source src/m3k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m3l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m3l.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3l.o" private/SLUS_204.86.rom --source src/m3l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3m.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m3m.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3m.o" private/SLUS_204.86.rom --source src/m3m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3o.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/m3o.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3o.o" private/SLUS_204.86.rom --source src/m3o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m3p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m3p.o"
"$PYTHON" tools/verify_object.py "$BUILD/m3p.o" private/SLUS_204.86.rom --source src/m3p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m4d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4d.o" private/SLUS_204.86.rom --source src/m4d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4e.c -c -lang c -O3 -Op -o "$BUILD/m4e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4e.o" private/SLUS_204.86.rom --source src/m4e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m4f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4f.o" private/SLUS_204.86.rom --source src/m4f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4g.c -c -lang c -O3 -Op -o "$BUILD/m4g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4g.o" private/SLUS_204.86.rom --source src/m4g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m4h.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4h.o" private/SLUS_204.86.rom --source src/m4h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m4i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m4i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m4i.o" private/SLUS_204.86.rom --source src/m4i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m11.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m11.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11.o" private/SLUS_204.86.rom --source src/m11.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m11b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m11b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11b.o" private/SLUS_204.86.rom --source src/m11b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m11c.c -c -lang c -O3 -Op -o "$BUILD/m11c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11c.o" private/SLUS_204.86.rom --source src/m11c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m11d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m11d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11d.o" private/SLUS_204.86.rom --source src/m11d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m11f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m11f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11f.o" private/SLUS_204.86.rom --source src/m11f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m11i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m11i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m11i.o" private/SLUS_204.86.rom --source src/m11i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8p.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8p.o" private/SLUS_204.86.rom --source src/m8p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8s.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8s.o" private/SLUS_204.86.rom --source src/m8s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8t.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8t.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8t.o" private/SLUS_204.86.rom --source src/m8t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8u.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8u.o" private/SLUS_204.86.rom --source src/m8u.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m8v.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m8v.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8v.o" private/SLUS_204.86.rom --source src/m8v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8w.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8w.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8w.o" private/SLUS_204.86.rom --source src/m8w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m8x.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m8x.o"
"$PYTHON" tools/verify_object.py "$BUILD/m8x.o" private/SLUS_204.86.rom --source src/m8x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m2a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9m2a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m2a.o" private/SLUS_204.86.rom --source src/w9m2a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m2b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w9m2b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m2b.o" private/SLUS_204.86.rom --source src/w9m2b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m2c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9m2c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m2c.o" private/SLUS_204.86.rom --source src/w9m2c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m2d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w9m2d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m2d.o" private/SLUS_204.86.rom --source src/w9m2d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w9m2g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9m2g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m2g.o" private/SLUS_204.86.rom --source src/w9m2g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m13.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m13.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13.o" private/SLUS_204.86.rom --source src/m13.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m13b.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/m13b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13b.o" private/SLUS_204.86.rom --source src/m13b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m13c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/m13c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13c.o" private/SLUS_204.86.rom --source src/m13c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m13d.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/m13d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13d.o" private/SLUS_204.86.rom --source src/m13d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m13f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m13f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13f.o" private/SLUS_204.86.rom --source src/m13f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m13e.c -c -lang c -O4 -Op -sdatathreshold 8 -o "$BUILD/m13e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m13e.o" private/SLUS_204.86.rom --source src/m13e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w9b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9b.o" private/SLUS_204.86.rom --source src/w9b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9c.o" private/SLUS_204.86.rom --source src/w9c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w9d.c -c -lang c -O3 -sdatathreshold 16 -o "$BUILD/w9d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9d.o" private/SLUS_204.86.rom --source src/w9d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9f.o" private/SLUS_204.86.rom --source src/w9f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w9h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9h.o" private/SLUS_204.86.rom --source src/w9h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m14.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m14.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14.o" private/SLUS_204.86.rom --source src/m14.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m14c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m14c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14c.o" private/SLUS_204.86.rom --source src/m14c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m14d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m14d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14d.o" private/SLUS_204.86.rom --source src/m14d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m14e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m14e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14e.o" private/SLUS_204.86.rom --source src/m14e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m14b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m14b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14b.o" private/SLUS_204.86.rom --source src/m14b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m14g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m14g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m14g.o" private/SLUS_204.86.rom --source src/m14g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m7g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m7g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7g.o" private/SLUS_204.86.rom --source src/m7g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m7i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m7i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7i.o" private/SLUS_204.86.rom --source src/m7i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m7j.c -c -lang c -O3 -Op -o "$BUILD/m7j.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7j.o" private/SLUS_204.86.rom --source src/m7j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m7k.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m7k.o"
"$PYTHON" tools/verify_object.py "$BUILD/m7k.o" private/SLUS_204.86.rom --source src/m7k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m10e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m10e.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10e.o" private/SLUS_204.86.rom --source src/m10e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m10f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10f.o" private/SLUS_204.86.rom --source src/m10f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10g.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/m10g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10g.o" private/SLUS_204.86.rom --source src/m10g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m10h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m10h.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10h.o" private/SLUS_204.86.rom --source src/m10h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m10i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m10i.o"
"$PYTHON" tools/verify_object.py "$BUILD/m10i.o" private/SLUS_204.86.rom --source src/m10i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m12.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m12.o"
"$PYTHON" tools/verify_object.py "$BUILD/m12.o" private/SLUS_204.86.rom --source src/m12.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m12b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m12b.o"
"$PYTHON" tools/verify_object.py "$BUILD/m12b.o" private/SLUS_204.86.rom --source src/m12b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m12c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m12c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m12c.o" private/SLUS_204.86.rom --source src/m12c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m12d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m12d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m12d.o" private/SLUS_204.86.rom --source src/m12d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m99.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m99.o"
"$PYTHON" tools/verify_object.py "$BUILD/m99.o" private/SLUS_204.86.rom --source src/m99.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m99d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m99d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m99d.o" private/SLUS_204.86.rom --source src/m99d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m99f.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/m99f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m99f.o" private/SLUS_204.86.rom --source src/m99f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9a.o" private/SLUS_204.86.rom --source src/w9a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9ag.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9ag.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9ag.o" private/SLUS_204.86.rom --source src/w9ag.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9aop.c -c -lang c -O3 -Op -o "$BUILD/w9aop.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9aop.o" private/SLUS_204.86.rom --source src/w9aop.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9agop.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w9agop.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9agop.o" private/SLUS_204.86.rom --source src/w9agop.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w9a30.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9a30.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9a30.o" private/SLUS_204.86.rom --source src/w9a30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9t.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/w9t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9t.o" private/SLUS_204.86.rom --source src/w9t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6w9a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/m6w9a.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9a.o" private/SLUS_204.86.rom --source src/m6w9a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6w9c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m6w9c.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9c.o" private/SLUS_204.86.rom --source src/m6w9c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6w9d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m6w9d.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9d.o" private/SLUS_204.86.rom --source src/m6w9d.c
"$WIBO" "$SNCPP" -P src/m6w9e.c "$BUILD/m6w9e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/m6w9e.i" "$BUILD/m6w9e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/m6w9e.o" "$BUILD/m6w9e.s"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9e.o" private/SLUS_204.86.rom --source src/m6w9e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m6w9f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/m6w9f.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9f.o" private/SLUS_204.86.rom --source src/m6w9f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/m6w9g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/m6w9g.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9g.o" private/SLUS_204.86.rom --source src/m6w9g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/m6w9h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/m6w9h.o"
"$PYTHON" tools/verify_object.py "$BUILD/m6w9h.o" private/SLUS_204.86.rom --source src/m6w9h.c
"$WIBO" "$SNCPP" -P src/s3w9e.c "$BUILD/s3w9e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/s3w9e.i" "$BUILD/s3w9e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s3w9e.o" "$BUILD/s3w9e.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3w9e.o" private/SLUS_204.86.rom --source src/s3w9e.c
"$WIBO" "$SNCPP" -P src/s3w9g.c "$BUILD/s3w9g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/s3w9g.i" "$BUILD/s3w9g.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s3w9g.o" "$BUILD/s3w9g.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3w9g.o" private/SLUS_204.86.rom --source src/s3w9g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s3w9m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/s3w9m.o"
"$PYTHON" tools/verify_object.py "$BUILD/s3w9m.o" private/SLUS_204.86.rom --source src/s3w9m.c
"$WIBO" "$SNCPP" -P src/s3w9a.c "$BUILD/s3w9a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/s3w9a.i" "$BUILD/s3w9a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/s3w9a.o" "$BUILD/s3w9a.s"
"$PYTHON" tools/verify_object.py "$BUILD/s3w9a.o" private/SLUS_204.86.rom --source src/s3w9a.c
"$WIBO" "$SNCPP" -P src/s4w9g.c "$BUILD/s4w9g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/s4w9g.i" "$BUILD/s4w9g.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/s4w9g.o" "$BUILD/s4w9g.s"
"$PYTHON" tools/verify_object.py "$BUILD/s4w9g.o" private/SLUS_204.86.rom --source src/s4w9g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s4w9mw.c -c -lang c -O3 -Op -fp off -o "$BUILD/s4w9mw.o"
"$PYTHON" tools/verify_object.py "$BUILD/s4w9mw.o" private/SLUS_204.86.rom --source src/s4w9mw.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/s4w9mw2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/s4w9mw2.o"
"$PYTHON" tools/verify_object.py "$BUILD/s4w9mw2.o" private/SLUS_204.86.rom --source src/s4w9mw2.c
"$WIBO" "$SNCPP" -P src/w9s2.c "$BUILD/w9s2.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w9s2.i" "$BUILD/w9s2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w9s2.o" "$BUILD/w9s2.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2.o" private/SLUS_204.86.rom --source src/w9s2.c
"$WIBO" "$SNCPP" -P src/w9s2e.c "$BUILD/w9s2e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/w9s2e.i" "$BUILD/w9s2e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w9s2e.o" "$BUILD/w9s2e.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2e.o" private/SLUS_204.86.rom --source src/w9s2e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9s2g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9s2g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2g.o" private/SLUS_204.86.rom --source src/w9s2g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9s2gp.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w9s2gp.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2gp.o" private/SLUS_204.86.rom --source src/w9s2gp.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9s2f.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/w9s2f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2f.o" private/SLUS_204.86.rom --source src/w9s2f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w9s2m30.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9s2m30.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2m30.o" private/SLUS_204.86.rom --source src/w9s2m30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9s2m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9s2m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9s2m.o" private/SLUS_204.86.rom --source src/w9s2m.c
"$WIBO" "$SNCPP" -P src/w9e0.c "$BUILD/w9e0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w9e0.i" "$BUILD/w9e0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w9e0.o" "$BUILD/w9e0.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9e0.o" private/SLUS_204.86.rom --source src/w9e0.c
"$WIBO" "$SNCPP" -P src/w9e1.c "$BUILD/w9e1.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w9e1.i" "$BUILD/w9e1.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w9e1.o" "$BUILD/w9e1.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9e1.o" private/SLUS_204.86.rom --source src/w9e1.c
"$WIBO" "$SNCPP" -P src/w9e8.c "$BUILD/w9e8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w9e8.i" "$BUILD/w9e8.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w9e8.o" "$BUILD/w9e8.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9e8.o" private/SLUS_204.86.rom --source src/w9e8.c
"$WIBO" "$SNCPP" -P src/w9a0.c "$BUILD/w9a0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w9a0.i" "$BUILD/w9a0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w9a0.o" "$BUILD/w9a0.s"
"$PYTHON" tools/verify_object.py "$BUILD/w9a0.o" private/SLUS_204.86.rom --source src/w9a0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w9m0.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m0.o" private/SLUS_204.86.rom --source src/w9m0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m8.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w9m8.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m8.o" private/SLUS_204.86.rom --source src/w9m8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m3.c -c -lang c -O3,p -o "$BUILD/w9m3.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m3.o" private/SLUS_204.86.rom --source src/w9m3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w9m3op.c -c -lang c -O3 -sdatathreshold 0 -Op -o "$BUILD/w9m3op.o"
"$PYTHON" tools/verify_object.py "$BUILD/w9m3op.o" private/SLUS_204.86.rom --source src/w9m3op.c
"$WIBO" "$SNCPP" -P src/s4w9.c "$BUILD/s4w9.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 "$BUILD/s4w9.i" "$BUILD/s4w9.s"
"$PYTHON" tools/fix_switch_table.py "$BUILD/s4w9.s" jtbl_004BC800
"$WIBO" "$SNAS" -G0 -o "$BUILD/s4w9.o" "$BUILD/s4w9.s"
"$PYTHON" tools/verify_object.py "$BUILD/s4w9.o" private/SLUS_204.86.rom --source src/s4w9.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_a.o" private/SLUS_204.86.rom --source src/q0_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q0_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_f.o" private/SLUS_204.86.rom --source src/q0_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q0_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_b.o" private/SLUS_204.86.rom --source src/q0_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_c.o" private/SLUS_204.86.rom --source src/q0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_d.o" private/SLUS_204.86.rom --source src/q0_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q0_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_e.o" private/SLUS_204.86.rom --source src/q0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/pw24_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_a.o" private/SLUS_204.86.rom --source src/pw24_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/pw24_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_b.o" private/SLUS_204.86.rom --source src/pw24_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/pw24_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_c.o" private/SLUS_204.86.rom --source src/pw24_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/pw24_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/pw24_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_d.o" private/SLUS_204.86.rom --source src/pw24_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_e.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/pw24_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_e.o" private/SLUS_204.86.rom --source src/pw24_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/pw24_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_f.o" private/SLUS_204.86.rom --source src/pw24_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/pw24_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_g.o" private/SLUS_204.86.rom --source src/pw24_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/pw24_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_h.o" private/SLUS_204.86.rom --source src/pw24_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_i.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/pw24_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_i.o" private/SLUS_204.86.rom --source src/pw24_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw24_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/pw24_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw24_j.o" private/SLUS_204.86.rom --source src/pw24_j.c
"$WIBO" "$SNCPP" -P src/b10s2_a.c "$BUILD/b10s2_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s2_a.i" "$BUILD/b10s2_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s2_a.o" "$BUILD/b10s2_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_a.o" private/SLUS_204.86.rom --source src/b10s2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s2_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_b.o" private/SLUS_204.86.rom --source src/b10s2_b.c
"$WIBO" "$SNCPP" -P src/b10s2_c.c "$BUILD/b10s2_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s2_c.i" "$BUILD/b10s2_c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s2_c.o" "$BUILD/b10s2_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_c.o" private/SLUS_204.86.rom --source src/b10s2_c.c
"$WIBO" "$SNCPP" -P src/b10s2_d.c "$BUILD/b10s2_d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/b10s2_d.i" "$BUILD/b10s2_d.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/b10s2_d.o" "$BUILD/b10s2_d.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_d.o" private/SLUS_204.86.rom --source src/b10s2_d.c
"$WIBO" "$SNCPP" -P src/b10s2_e.c "$BUILD/b10s2_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/b10s2_e.i" "$BUILD/b10s2_e.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/b10s2_e.o" "$BUILD/b10s2_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_e.o" private/SLUS_204.86.rom --source src/b10s2_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s2_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/b10s2_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_g.o" private/SLUS_204.86.rom --source src/b10s2_g.c
"$WIBO" "$SNCPP" -P src/b10s2_h.c "$BUILD/b10s2_h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/b10s2_h.i" "$BUILD/b10s2_h.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/b10s2_h.o" "$BUILD/b10s2_h.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_h.o" private/SLUS_204.86.rom --source src/b10s2_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/b10s2_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s2_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s2_j.o" private/SLUS_204.86.rom --source src/b10s2_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_a.o" private/SLUS_204.86.rom --source src/q1_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_b.o" private/SLUS_204.86.rom --source src/q1_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_c.o" private/SLUS_204.86.rom --source src/q1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/q1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_d.o" private/SLUS_204.86.rom --source src/q1_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q1_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_e.o" private/SLUS_204.86.rom --source src/q1_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_f.o" private/SLUS_204.86.rom --source src/q1_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q9_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q9_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_a.o" private/SLUS_204.86.rom --source src/q9_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q9_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_b.o" private/SLUS_204.86.rom --source src/q9_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q9_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q9_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_c.o" private/SLUS_204.86.rom --source src/q9_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_a.o" private/SLUS_204.86.rom --source src/q8_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_b.o" private/SLUS_204.86.rom --source src/q8_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_c.o" private/SLUS_204.86.rom --source src/q8_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_d.o" private/SLUS_204.86.rom --source src/q8_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_a.o" private/SLUS_204.86.rom --source src/q7_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_b.o" private/SLUS_204.86.rom --source src/q7_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q7_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_c.o" private/SLUS_204.86.rom --source src/q7_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_d.o" private/SLUS_204.86.rom --source src/q7_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q10_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q10_a.o" private/SLUS_204.86.rom --source src/q10_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q10_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q10_b.o" private/SLUS_204.86.rom --source src/q10_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q10_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q10_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q10_c.o" private/SLUS_204.86.rom --source src/q10_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q10_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q10_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q10_d.o" private/SLUS_204.86.rom --source src/q10_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q10_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q10_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q10_e.o" private/SLUS_204.86.rom --source src/q10_e.c
"$WIBO" "$SNCPP" -P src/pw39_a.c "$BUILD/pw39_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_a.i" "$BUILD/pw39_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_a.o" "$BUILD/pw39_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_a.o" private/SLUS_204.86.rom --source src/pw39_a.c
"$WIBO" "$SNCPP" -P src/pw39_b.c "$BUILD/pw39_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/pw39_b.i" "$BUILD/pw39_b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/pw39_b.o" "$BUILD/pw39_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_b.o" private/SLUS_204.86.rom --source src/pw39_b.c
"$WIBO" "$SNCPP" -P src/pw39_c.c "$BUILD/pw39_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/pw39_c.i" "$BUILD/pw39_c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_c.o" "$BUILD/pw39_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_c.o" private/SLUS_204.86.rom --source src/pw39_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw39_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/pw39_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_d.o" private/SLUS_204.86.rom --source src/pw39_d.c
"$WIBO" "$SNCPP" -P src/pw39_e.c "$BUILD/pw39_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_e.i" "$BUILD/pw39_e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_e.o" "$BUILD/pw39_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_e.o" private/SLUS_204.86.rom --source src/pw39_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s_0_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/b10s_0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_a.o" private/SLUS_204.86.rom --source src/b10s_0_a.c
"$WIBO" "$SNCPP" -P src/b10s_0_e.c "$BUILD/b10s_0_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/b10s_0_e.i" "$BUILD/b10s_0_e.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/b10s_0_e.o" "$BUILD/b10s_0_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_e.o" private/SLUS_204.86.rom --source src/b10s_0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s_0_f.c -c -lang c -O1,p -sdatathreshold 8 -o "$BUILD/b10s_0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_f.o" private/SLUS_204.86.rom --source src/b10s_0_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s_0_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s_0_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_g.o" private/SLUS_204.86.rom --source src/b10s_0_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s_0_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s_0_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_h.o" private/SLUS_204.86.rom --source src/b10s_0_h.c
"$WIBO" "$SNCPP" -P src/b10s_0_i.c "$BUILD/b10s_0_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s_0_i.i" "$BUILD/b10s_0_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s_0_i.o" "$BUILD/b10s_0_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_i.o" private/SLUS_204.86.rom --source src/b10s_0_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/b10s_0_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s_0_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_j.o" private/SLUS_204.86.rom --source src/b10s_0_j.c
"$WIBO" "$SNCPP" -P src/b10s_0_k.c "$BUILD/b10s_0_k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s_0_k.i" "$BUILD/b10s_0_k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s_0_k.o" "$BUILD/b10s_0_k.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_k.o" private/SLUS_204.86.rom --source src/b10s_0_k.c
"$WIBO" "$SNCPP" -P src/b10s_0_m.c "$BUILD/b10s_0_m.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s_0_m.i" "$BUILD/b10s_0_m.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s_0_m.o" "$BUILD/b10s_0_m.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_m.o" private/SLUS_204.86.rom --source src/b10s_0_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/b10s_0_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/b10s_0_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_n.o" private/SLUS_204.86.rom --source src/b10s_0_n.c
"$WIBO" "$SNCPP" -P src/b10s_0_t.c "$BUILD/b10s_0_t.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s_0_t.i" "$BUILD/b10s_0_t.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s_0_t.o" "$BUILD/b10s_0_t.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_t.o" private/SLUS_204.86.rom --source src/b10s_0_t.c
"$WIBO" "$SNCPP" -P src/b10s_0_w.c "$BUILD/b10s_0_w.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/b10s_0_w.i" "$BUILD/b10s_0_w.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/b10s_0_w.o" "$BUILD/b10s_0_w.s"
"$PYTHON" tools/verify_object.py "$BUILD/b10s_0_w.o" private/SLUS_204.86.rom --source src/b10s_0_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q15_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q15_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q15_a.o" private/SLUS_204.86.rom --source src/q15_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q15_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q15_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q15_b.o" private/SLUS_204.86.rom --source src/q15_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q15_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q15_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q15_c.o" private/SLUS_204.86.rom --source src/q15_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q15_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q15_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q15_d.o" private/SLUS_204.86.rom --source src/q15_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q15_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q15_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q15_f.o" private/SLUS_204.86.rom --source src/q15_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_a.o" private/SLUS_204.86.rom --source src/q3_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_c.o" private/SLUS_204.86.rom --source src/q3_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_d.o" private/SLUS_204.86.rom --source src/q3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_e.o" private/SLUS_204.86.rom --source src/q3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q11_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q11_a.o" private/SLUS_204.86.rom --source src/q11_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q11_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q11_b.o" private/SLUS_204.86.rom --source src/q11_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q13_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q13_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q13_a.o" private/SLUS_204.86.rom --source src/q13_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q13_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q13_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q13_b.o" private/SLUS_204.86.rom --source src/q13_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q13_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q13_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q13_c.o" private/SLUS_204.86.rom --source src/q13_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q13_d.c -c -lang c -O3 -Op -fp off -o "$BUILD/q13_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q13_d.o" private/SLUS_204.86.rom --source src/q13_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q13_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q13_e.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @22=jtbl_004B48B0 \
    "$BUILD/q13_e.o" "$BUILD/q13_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q13_e.o" private/SLUS_204.86.rom --source src/q13_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_a.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_a.o" private/SLUS_204.86.rom --source src/q5_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_b.o" private/SLUS_204.86.rom --source src/q5_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q5_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q5_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_c.o" private/SLUS_204.86.rom --source src/q5_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_d.o" private/SLUS_204.86.rom --source src/q5_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q5_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q5_e.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @14=jtbl_004B11E0 \
    "$BUILD/q5_e.o" "$BUILD/q5_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_e.o" private/SLUS_204.86.rom --source src/q5_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q5_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_f.o" private/SLUS_204.86.rom --source src/q5_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q14_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_a.o" private/SLUS_204.86.rom --source src/q14_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q14_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_b.o" private/SLUS_204.86.rom --source src/q14_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_c.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q14_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_c.o" private/SLUS_204.86.rom --source src/q14_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q14_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q14_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_d.o" private/SLUS_204.86.rom --source src/q14_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q14_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_e.o" private/SLUS_204.86.rom --source src/q14_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/q14_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_f.o" private/SLUS_204.86.rom --source src/q14_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q14_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_g.o" private/SLUS_204.86.rom --source src/q14_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q14_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_h.o" private/SLUS_204.86.rom --source src/q14_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q14_i.c -c -lang c -O2 -sdatathreshold 0 -o "$BUILD/q14_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q14_i.o" private/SLUS_204.86.rom --source src/q14_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q12_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q12_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q12_a.o" private/SLUS_204.86.rom --source src/q12_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q12_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q12_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q12_b.o" private/SLUS_204.86.rom --source src/q12_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q12_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q12_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q12_c.o" private/SLUS_204.86.rom --source src/q12_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q12_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q12_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q12_d.o" private/SLUS_204.86.rom --source src/q12_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q12_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q12_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q12_e.o" private/SLUS_204.86.rom --source src/q12_e.c
"$WIBO" "$SNCPP" -P src/r3_a.c "$BUILD/r3_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/r3_a.i" "$BUILD/r3_a.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/r3_a.o" "$BUILD/r3_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/r3_a.o" private/SLUS_204.86.rom --source src/r3_a.c
"$WIBO" "$SNCPP" -P src/r3_b.c "$BUILD/r3_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/r3_b.i" "$BUILD/r3_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/r3_b.o" "$BUILD/r3_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/r3_b.o" private/SLUS_204.86.rom --source src/r3_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/r3_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/r3_c.o" private/SLUS_204.86.rom --source src/r3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r3_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/r3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/r3_d.o" private/SLUS_204.86.rom --source src/r3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_a.o" private/SLUS_204.86.rom --source src/q4_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_b.o" private/SLUS_204.86.rom --source src/q4_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q4_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_c.o" private/SLUS_204.86.rom --source src/q4_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_d.o" private/SLUS_204.86.rom --source src/q4_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q4_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_e.o" private/SLUS_204.86.rom --source src/q4_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_1.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_1.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_1.o" private/SLUS_204.86.rom --source src/q6_1.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_2.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q6_2.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_2.o" private/SLUS_204.86.rom --source src/q6_2.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q6_3.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_3.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_3.o" private/SLUS_204.86.rom --source src/q6_3.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r5_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/r5_a.o" private/SLUS_204.86.rom --source src/r5_a.c
"$WIBO" "$SNCPP" -P src/r5_b.c "$BUILD/r5_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/r5_b.i" "$BUILD/r5_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/r5_b.o" "$BUILD/r5_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/r5_b.o" private/SLUS_204.86.rom --source src/r5_b.c
"$WIBO" "$SNCPP" -P src/r5_c.c "$BUILD/r5_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/r5_c.i" "$BUILD/r5_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/r5_c.o" "$BUILD/r5_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/r5_c.o" private/SLUS_204.86.rom --source src/r5_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r5_d.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/r5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/r5_d.o" private/SLUS_204.86.rom --source src/r5_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r4.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r4.o"
"$PYTHON" tools/verify_object.py "$BUILD/r4.o" private/SLUS_204.86.rom --source src/r4.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/r4b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/r4b.o"
"$PYTHON" tools/verify_object.py "$BUILD/r4b.o" private/SLUS_204.86.rom --source src/r4b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/r4c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/r4c.o"
"$PYTHON" tools/verify_object.py "$BUILD/r4c.o" private/SLUS_204.86.rom --source src/r4c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/r4d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/r4d.o"
"$PYTHON" tools/verify_object.py "$BUILD/r4d.o" private/SLUS_204.86.rom --source src/r4d.c
"$WIBO" "$SNCPP" -P src/r4e.c "$BUILD/r4e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/r4e.i" "$BUILD/r4e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/r4e.o" "$BUILD/r4e.s"
"$PYTHON" tools/verify_object.py "$BUILD/r4e.o" private/SLUS_204.86.rom --source src/r4e.c
"$WIBO" "$SNCPP" -P src/pw39_f.c "$BUILD/pw39_f.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_f.i" "$BUILD/pw39_f.s"
"$WIBO" "$SNAS" -mips4 -G0 -o "$BUILD/pw39_f.o" "$BUILD/pw39_f.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_f.o" private/SLUS_204.86.rom --source src/pw39_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t5_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t5_a.o" private/SLUS_204.86.rom --source src/t5_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t5_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t5_b.o" private/SLUS_204.86.rom --source src/t5_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t5_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t5_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t5_c.o" private/SLUS_204.86.rom --source src/t5_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t5_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t5_d.o" private/SLUS_204.86.rom --source src/t5_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t5_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t5_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t5_e.o" private/SLUS_204.86.rom --source src/t5_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t15_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t15_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_a.o" private/SLUS_204.86.rom --source src/t15_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t15_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t15_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_b.o" private/SLUS_204.86.rom --source src/t15_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t15_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t15_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_c.o" private/SLUS_204.86.rom --source src/t15_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t15_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t15_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_d.o" private/SLUS_204.86.rom --source src/t15_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t15_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/t15_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_e.o" private/SLUS_204.86.rom --source src/t15_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t15_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t15_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/t15_f.o" private/SLUS_204.86.rom --source src/t15_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t3.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t3.o"
"$PYTHON" tools/verify_object.py "$BUILD/t3.o" private/SLUS_204.86.rom --source src/t3.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t3b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t3b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t3b.o" private/SLUS_204.86.rom --source src/t3b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t3c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t3c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t3c.o" private/SLUS_204.86.rom --source src/t3c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t3d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t3d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t3d.o" private/SLUS_204.86.rom --source src/t3d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t12_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t12_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t12_a.o" private/SLUS_204.86.rom --source src/t12_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t12_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t12_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t12_b.o" private/SLUS_204.86.rom --source src/t12_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t12_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t12_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t12_c.o" private/SLUS_204.86.rom --source src/t12_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t12_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t12_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t12_d.o" private/SLUS_204.86.rom --source src/t12_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t8.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t8.o"
"$PYTHON" tools/verify_object.py "$BUILD/t8.o" private/SLUS_204.86.rom --source src/t8.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t8b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/t8b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t8b.o" private/SLUS_204.86.rom --source src/t8b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t8c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t8c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t8c.o" private/SLUS_204.86.rom --source src/t8c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t8d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t8d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t8d.o" private/SLUS_204.86.rom --source src/t8d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t8e.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/t8e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t8e.o" private/SLUS_204.86.rom --source src/t8e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t0.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0.o" private/SLUS_204.86.rom --source src/t0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t0b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t0b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0b.o" private/SLUS_204.86.rom --source src/t0b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t0c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t0c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0c.o" private/SLUS_204.86.rom --source src/t0c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t0d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t0d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0d.o" private/SLUS_204.86.rom --source src/t0d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t0e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t0e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0e.o" private/SLUS_204.86.rom --source src/t0e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t0f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t0f.o"
"$PYTHON" tools/verify_object.py "$BUILD/t0f.o" private/SLUS_204.86.rom --source src/t0f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_a.o" private/SLUS_204.86.rom --source src/t4_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/t4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_b.o" private/SLUS_204.86.rom --source src/t4_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t4_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_c.o" private/SLUS_204.86.rom --source src/t4_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t4_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_d.o" private/SLUS_204.86.rom --source src/t4_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t4_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_e.o" private/SLUS_204.86.rom --source src/t4_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t4_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_f.o" private/SLUS_204.86.rom --source src/t4_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t4_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t4_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/t4_g.o" private/SLUS_204.86.rom --source src/t4_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t7_a.c -c -lang c -O3,p -Op -sdatathreshold 8 -o "$BUILD/t7_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t7_a.o" private/SLUS_204.86.rom --source src/t7_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t7_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t7_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t7_b.o" private/SLUS_204.86.rom --source src/t7_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t7_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/t7_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t7_e.o" private/SLUS_204.86.rom --source src/t7_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t14_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t14_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t14_a.o" private/SLUS_204.86.rom --source src/t14_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t14_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t14_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t14_b.o" private/SLUS_204.86.rom --source src/t14_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t14_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t14_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t14_c.o" private/SLUS_204.86.rom --source src/t14_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t14_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t14_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t14_d.o" private/SLUS_204.86.rom --source src/t14_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t14_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t14_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t14_e.o" private/SLUS_204.86.rom --source src/t14_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t13_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t13_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t13_a.o" private/SLUS_204.86.rom --source src/t13_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t13_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t13_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t13_b.o" private/SLUS_204.86.rom --source src/t13_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t13_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t13_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t13_c.o" private/SLUS_204.86.rom --source src/t13_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t13_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t13_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t13_d.o" private/SLUS_204.86.rom --source src/t13_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t13_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/t13_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t13_e.o" private/SLUS_204.86.rom --source src/t13_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t9_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_a.o" private/SLUS_204.86.rom --source src/t9_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_b.o" private/SLUS_204.86.rom --source src/t9_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t9_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_d.o" private/SLUS_204.86.rom --source src/t9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_e.o" private/SLUS_204.86.rom --source src/t9_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_g.o" private/SLUS_204.86.rom --source src/t9_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_h.o" private/SLUS_204.86.rom --source src/t9_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t9_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_i.o" private/SLUS_204.86.rom --source src/t9_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t9_k.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t9_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/t9_k.o" private/SLUS_204.86.rom --source src/t9_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t11_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t11_a.o" private/SLUS_204.86.rom --source src/t11_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t11_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t11_b.o" private/SLUS_204.86.rom --source src/t11_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t11_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t11_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t11_c.o" private/SLUS_204.86.rom --source src/t11_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t11_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t11_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t11_e.o" private/SLUS_204.86.rom --source src/t11_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t6_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t6_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_a.o" private/SLUS_204.86.rom --source src/t6_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t6_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t6_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_b.o" private/SLUS_204.86.rom --source src/t6_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t6_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t6_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_c.o" private/SLUS_204.86.rom --source src/t6_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t6_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t6_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_d.o" private/SLUS_204.86.rom --source src/t6_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t6_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t6_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_e.o" private/SLUS_204.86.rom --source src/t6_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t6_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t6_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_f.o" private/SLUS_204.86.rom --source src/t6_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t6_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/t6_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/t6_g.o" private/SLUS_204.86.rom --source src/t6_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t1_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t1_a.o" private/SLUS_204.86.rom --source src/t1_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t1_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t1_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t1_b.o" private/SLUS_204.86.rom --source src/t1_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t1_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t1_c.o" private/SLUS_204.86.rom --source src/t1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t1_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t1_d.o" private/SLUS_204.86.rom --source src/t1_d.c
"$WIBO" "$SNCPP" -P src/u0_a.c "$BUILD/u0_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u0_a.i" "$BUILD/u0_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u0_a.o" "$BUILD/u0_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/u0_a.o" private/SLUS_204.86.rom --source src/u0_a.c
"$WIBO" "$SNCPP" -P src/u0_b.c "$BUILD/u0_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/u0_b.i" "$BUILD/u0_b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/u0_b.o" "$BUILD/u0_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/u0_b.o" private/SLUS_204.86.rom --source src/u0_b.c
"$WIBO" "$SNCPP" -P src/u0_c.c "$BUILD/u0_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u0_c.i" "$BUILD/u0_c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u0_c.o" "$BUILD/u0_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/u0_c.o" private/SLUS_204.86.rom --source src/u0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u0_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/u0_d.o" private/SLUS_204.86.rom --source src/u0_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/u0_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/u0_e.o" private/SLUS_204.86.rom --source src/u0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u0_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/u0_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/u0_g.o" private/SLUS_204.86.rom --source src/u0_g.c
"$WIBO" "$SNCPP" -P src/u2b.c "$BUILD/u2b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u2b.i" "$BUILD/u2b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u2b.o" "$BUILD/u2b.s"
"$PYTHON" tools/verify_object.py "$BUILD/u2b.o" private/SLUS_204.86.rom --source src/u2b.c
"$WIBO" "$SNCPP" -P src/u2c.c "$BUILD/u2c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/u2c.i" "$BUILD/u2c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u2c.o" "$BUILD/u2c.s"
"$PYTHON" tools/verify_object.py "$BUILD/u2c.o" private/SLUS_204.86.rom --source src/u2c.c
"$WIBO" "$SNCPP" -P src/u2d.c "$BUILD/u2d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u2d.i" "$BUILD/u2d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u2d.o" "$BUILD/u2d.s"
"$PYTHON" tools/verify_object.py "$BUILD/u2d.o" private/SLUS_204.86.rom --source src/u2d.c
"$WIBO" "$SNCPP" -P src/u2e.c "$BUILD/u2e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u2e.i" "$BUILD/u2e.s"
"$WIBO" "$SNAS" -mips4 -G0 -o "$BUILD/u2e.o" "$BUILD/u2e.s"
"$PYTHON" tools/verify_object.py "$BUILD/u2e.o" private/SLUS_204.86.rom --source src/u2e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u2.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u2.o"
"$PYTHON" tools/verify_object.py "$BUILD/u2.o" private/SLUS_204.86.rom --source src/u2.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/u2f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u2f.o"
"$PYTHON" tools/verify_object.py "$BUILD/u2f.o" private/SLUS_204.86.rom --source src/u2f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u2h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/u2h.o"
"$PYTHON" tools/verify_object.py "$BUILD/u2h.o" private/SLUS_204.86.rom --source src/u2h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t2_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t2_a.o" private/SLUS_204.86.rom --source src/t2_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t2_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t2_b.o" private/SLUS_204.86.rom --source src/t2_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t2_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t2_c.o" private/SLUS_204.86.rom --source src/t2_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t10_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_a.o" private/SLUS_204.86.rom --source src/t10_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t10_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/t10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_b.o" private/SLUS_204.86.rom --source src/t10_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t10_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t10_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_c.o" private/SLUS_204.86.rom --source src/t10_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t10_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t10_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_d.o" private/SLUS_204.86.rom --source src/t10_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t10_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/t10_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_e.o" private/SLUS_204.86.rom --source src/t10_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t10_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/t10_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_f.o" private/SLUS_204.86.rom --source src/t10_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/t10_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/t10_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_g.o" private/SLUS_204.86.rom --source src/t10_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/t10_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/t10_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/t10_h.o" private/SLUS_204.86.rom --source src/t10_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u3_b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/u3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_b.o" private/SLUS_204.86.rom --source src/u3_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u3_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/u3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_c.o" private/SLUS_204.86.rom --source src/u3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u3_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_d.o" private/SLUS_204.86.rom --source src/u3_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/u3_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/u3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_f.o" private/SLUS_204.86.rom --source src/u3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u3_k.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/u3_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_k.o" private/SLUS_204.86.rom --source src/u3_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/u3_m.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/u3_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/u3_m.o" private/SLUS_204.86.rom --source src/u3_m.c
"$WIBO" "$SNCPP" -P src/u3_g.c "$BUILD/u3_g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_g.i" "$BUILD/u3_g.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_g.o" "$BUILD/u3_g.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_g.o" private/SLUS_204.86.rom --source src/u3_g.c
"$WIBO" "$SNCPP" -P src/u3_i.c "$BUILD/u3_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_i.i" "$BUILD/u3_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_i.o" "$BUILD/u3_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_i.o" private/SLUS_204.86.rom --source src/u3_i.c
"$WIBO" "$SNCPP" -P src/u3_q.c "$BUILD/u3_q.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_q.i" "$BUILD/u3_q.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_q.o" "$BUILD/u3_q.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_q.o" private/SLUS_204.86.rom --source src/u3_q.c
"$WIBO" "$SNCPP" -P src/u3_r.c "$BUILD/u3_r.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_r.i" "$BUILD/u3_r.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_r.o" "$BUILD/u3_r.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_r.o" private/SLUS_204.86.rom --source src/u3_r.c
"$WIBO" "$SNCPP" -P src/u3_u.c "$BUILD/u3_u.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_u.i" "$BUILD/u3_u.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_u.o" "$BUILD/u3_u.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_u.o" private/SLUS_204.86.rom --source src/u3_u.c
"$WIBO" "$SNCPP" -P src/u3_v.c "$BUILD/u3_v.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/u3_v.i" "$BUILD/u3_v.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/u3_v.o" "$BUILD/u3_v.s"
"$PYTHON" tools/verify_object.py "$BUILD/u3_v.o" private/SLUS_204.86.rom --source src/u3_v.c
"$WIBO" "$SNCPP" -P src/pw39_ee.c "$BUILD/pw39_ee.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_ee.i" "$BUILD/pw39_ee.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_ee.o" "$BUILD/pw39_ee.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_ee.o" private/SLUS_204.86.rom --source src/pw39_ee.c
"$WIBO" "$SNCPP" -P src/pw39_ee2.c "$BUILD/pw39_ee2.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_ee2.i" "$BUILD/pw39_ee2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_ee2.o" "$BUILD/pw39_ee2.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_ee2.o" private/SLUS_204.86.rom --source src/pw39_ee2.c
"$WIBO" "$SNCPP" -P src/pw39_ee8.c "$BUILD/pw39_ee8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/pw39_ee8.i" "$BUILD/pw39_ee8.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/pw39_ee8.o" "$BUILD/pw39_ee8.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_ee8.o" private/SLUS_204.86.rom --source src/pw39_ee8.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/pw39_mw30.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/pw39_mw30.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_mw30.o" private/SLUS_204.86.rom --source src/pw39_mw30.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/pw39_mw30p.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/pw39_mw30p.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_mw30p.o" private/SLUS_204.86.rom --source src/pw39_mw30p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/pw39_mw.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/pw39_mw.o"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_mw.o" private/SLUS_204.86.rom --source src/pw39_mw.c
"$WIBO" "$SNCPP" -P src/pw39_eejt.c "$BUILD/pw39_eejt.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/pw39_eejt.i" "$BUILD/pw39_eejt.s"
"$PYTHON" tools/fix_switch_table.py "$BUILD/pw39_eejt.s" jtbl_004BDA20
"$WIBO" "$SNAS" -G0 -o "$BUILD/pw39_eejt.o" "$BUILD/pw39_eejt.s"
"$PYTHON" tools/verify_object.py "$BUILD/pw39_eejt.o" private/SLUS_204.86.rom --source src/pw39_eejt.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v1_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_a.o" private/SLUS_204.86.rom --source src/v1_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v1_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v1_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_b.o" private/SLUS_204.86.rom --source src/v1_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v1_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/v1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_c.o" private/SLUS_204.86.rom --source src/v1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v1_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_d.o" private/SLUS_204.86.rom --source src/v1_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v1_e.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/v1_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_e.o" private/SLUS_204.86.rom --source src/v1_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v1_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v1_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v1_f.o" private/SLUS_204.86.rom --source src/v1_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v0_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v0_a.o" private/SLUS_204.86.rom --source src/v0_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v0_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v0_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v0_b.o" private/SLUS_204.86.rom --source src/v0_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v0_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v0_c.o" private/SLUS_204.86.rom --source src/v0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v8_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v8_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v8_a.o" private/SLUS_204.86.rom --source src/v8_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v8_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v8_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v8_b.o" private/SLUS_204.86.rom --source src/v8_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v8_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/v8_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v8_c.o" private/SLUS_204.86.rom --source src/v8_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v11_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v11_a.o" private/SLUS_204.86.rom --source src/v11_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v11_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v11_b.o" private/SLUS_204.86.rom --source src/v11_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v11_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v11_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v11_c.o" private/SLUS_204.86.rom --source src/v11_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v11_d.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/v11_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v11_d.o" private/SLUS_204.86.rom --source src/v11_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v11_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v11_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v11_e.o" private/SLUS_204.86.rom --source src/v11_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v9_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v9_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v9_a.o" private/SLUS_204.86.rom --source src/v9_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v9_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v9_b.o" private/SLUS_204.86.rom --source src/v9_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v9_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v9_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v9_c.o" private/SLUS_204.86.rom --source src/v9_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v9_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v9_d.o" private/SLUS_204.86.rom --source src/v9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v12_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_a.o" private/SLUS_204.86.rom --source src/v12_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v12_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_b.o" private/SLUS_204.86.rom --source src/v12_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v12_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_c.o" private/SLUS_204.86.rom --source src/v12_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v12_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_d.o" private/SLUS_204.86.rom --source src/v12_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_e.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/v12_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_e.o" private/SLUS_204.86.rom --source src/v12_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v12_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/v12_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v12_f.o" private/SLUS_204.86.rom --source src/v12_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v15_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v15_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v15_a.o" private/SLUS_204.86.rom --source src/v15_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v15_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v15_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v15_b.o" private/SLUS_204.86.rom --source src/v15_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v15_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v15_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v15_c.o" private/SLUS_204.86.rom --source src/v15_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v15_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v15_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v15_d.o" private/SLUS_204.86.rom --source src/v15_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v4_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_a.o" private/SLUS_204.86.rom --source src/v4_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v4_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_b.o" private/SLUS_204.86.rom --source src/v4_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v4_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v4_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_c.o" private/SLUS_204.86.rom --source src/v4_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v4_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v4_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_d.o" private/SLUS_204.86.rom --source src/v4_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v4_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v4_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_e.o" private/SLUS_204.86.rom --source src/v4_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v4_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/v4_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v4_f.o" private/SLUS_204.86.rom --source src/v4_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v3_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_a.o" private/SLUS_204.86.rom --source src/v3_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v3_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_b.o" private/SLUS_204.86.rom --source src/v3_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v3_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_e.o" private/SLUS_204.86.rom --source src/v3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v3_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v3_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_g.o" private/SLUS_204.86.rom --source src/v3_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v3_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v3_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_h.o" private/SLUS_204.86.rom --source src/v3_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v3_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v3_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_i.o" private/SLUS_204.86.rom --source src/v3_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v3_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v3_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/v3_j.o" private/SLUS_204.86.rom --source src/v3_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v5_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v5_a.o" private/SLUS_204.86.rom --source src/v5_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v5_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v5_b.o" private/SLUS_204.86.rom --source src/v5_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v5_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v5_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v5_c.o" private/SLUS_204.86.rom --source src/v5_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v5_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v5_d.o" private/SLUS_204.86.rom --source src/v5_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v5_g.c -c -lang c -O3 -sdatathreshold 256 -o "$BUILD/v5_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/v5_g.o" private/SLUS_204.86.rom --source src/v5_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v6_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v6_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_a.o" private/SLUS_204.86.rom --source src/v6_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v6_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v6_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_b.o" private/SLUS_204.86.rom --source src/v6_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v6_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v6_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_c.o" private/SLUS_204.86.rom --source src/v6_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v6_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v6_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_d.o" private/SLUS_204.86.rom --source src/v6_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v6_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v6_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_e.o" private/SLUS_204.86.rom --source src/v6_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v6_f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/v6_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_f.o" private/SLUS_204.86.rom --source src/v6_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v6_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v6_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/v6_g.o" private/SLUS_204.86.rom --source src/v6_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v7_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v7_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_a.o" private/SLUS_204.86.rom --source src/v7_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v7_b.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/v7_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_b.o" private/SLUS_204.86.rom --source src/v7_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v7_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v7_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_c.o" private/SLUS_204.86.rom --source src/v7_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v7_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v7_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_d.o" private/SLUS_204.86.rom --source src/v7_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v7_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v7_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_e.o" private/SLUS_204.86.rom --source src/v7_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v7_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v7_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_f.o" private/SLUS_204.86.rom --source src/v7_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v7_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v7_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/v7_g.o" private/SLUS_204.86.rom --source src/v7_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v10_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_a.o" private/SLUS_204.86.rom --source src/v10_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v10_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_b.o" private/SLUS_204.86.rom --source src/v10_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v10_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v10_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_c.o" private/SLUS_204.86.rom --source src/v10_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v10_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/v10_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_d.o" private/SLUS_204.86.rom --source src/v10_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v10_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v10_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_e.o" private/SLUS_204.86.rom --source src/v10_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v10_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v10_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v10_f.o" private/SLUS_204.86.rom --source src/v10_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v2_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v2_a.o" private/SLUS_204.86.rom --source src/v2_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v2_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v2_b.o" private/SLUS_204.86.rom --source src/v2_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v2_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v2_c.o" private/SLUS_204.86.rom --source src/v2_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v2_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v2_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v2_d.o" private/SLUS_204.86.rom --source src/v2_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v13_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v13_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v13_a.o" private/SLUS_204.86.rom --source src/v13_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v13_b.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/v13_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v13_b.o" private/SLUS_204.86.rom --source src/v13_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v13_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v13_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v13_c.o" private/SLUS_204.86.rom --source src/v13_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v13_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/v13_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v13_d.o" private/SLUS_204.86.rom --source src/v13_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v13_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v13_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v13_e.o" private/SLUS_204.86.rom --source src/v13_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v14_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v14_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_a.o" private/SLUS_204.86.rom --source src/v14_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v14_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v14_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_b.o" private/SLUS_204.86.rom --source src/v14_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v14_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v14_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_c.o" private/SLUS_204.86.rom --source src/v14_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v14_d.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/v14_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_d.o" private/SLUS_204.86.rom --source src/v14_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v14_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/v14_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_e.o" private/SLUS_204.86.rom --source src/v14_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/v14_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/v14_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_f.o" private/SLUS_204.86.rom --source src/v14_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/v14_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/v14_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/v14_g.o" private/SLUS_204.86.rom --source src/v14_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w0_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w0_a.o" private/SLUS_204.86.rom --source src/w0_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w0_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w0_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w0_l.o" private/SLUS_204.86.rom --source src/w0_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w0_t.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w0_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w0_t.o" private/SLUS_204.86.rom --source src/w0_t.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w0_d.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w0_d.o" private/SLUS_204.86.rom --source src/w0_d.c
"$WIBO" "$SNCPP" -P src/w0_b.c "$BUILD/w0_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_b.i" "$BUILD/w0_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_b.o" "$BUILD/w0_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_b.o" private/SLUS_204.86.rom --source src/w0_b.c
"$WIBO" "$SNCPP" -P src/w0_i.c "$BUILD/w0_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_i.i" "$BUILD/w0_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_i.o" "$BUILD/w0_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_i.o" private/SLUS_204.86.rom --source src/w0_i.c
"$WIBO" "$SNCPP" -P src/w0_k.c "$BUILD/w0_k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_k.i" "$BUILD/w0_k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_k.o" "$BUILD/w0_k.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_k.o" private/SLUS_204.86.rom --source src/w0_k.c
"$WIBO" "$SNCPP" -P src/w0_n.c "$BUILD/w0_n.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_n.i" "$BUILD/w0_n.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_n.o" "$BUILD/w0_n.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_n.o" private/SLUS_204.86.rom --source src/w0_n.c
"$WIBO" "$SNCPP" -P src/w0_s.c "$BUILD/w0_s.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_s.i" "$BUILD/w0_s.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_s.o" "$BUILD/w0_s.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_s.o" private/SLUS_204.86.rom --source src/w0_s.c
"$WIBO" "$SNCPP" -P src/w0_ab.c "$BUILD/w0_ab.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w0_ab.i" "$BUILD/w0_ab.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_ab.o" "$BUILD/w0_ab.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_ab.o" private/SLUS_204.86.rom --source src/w0_ab.c
"$WIBO" "$SNCPP" -P src/w0_e.c "$BUILD/w0_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w0_e.i" "$BUILD/w0_e.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w0_e.o" "$BUILD/w0_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_e.o" private/SLUS_204.86.rom --source src/w0_e.c
"$WIBO" "$SNCPP" -P src/w0_u.c "$BUILD/w0_u.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w0_u.i" "$BUILD/w0_u.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w0_u.o" "$BUILD/w0_u.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_u.o" private/SLUS_204.86.rom --source src/w0_u.c
"$WIBO" "$SNCPP" -P src/w0_r.c "$BUILD/w0_r.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/w0_r.i" "$BUILD/w0_r.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w0_r.o" "$BUILD/w0_r.s"
"$PYTHON" tools/verify_object.py "$BUILD/w0_r.o" private/SLUS_204.86.rom --source src/w0_r.c
"$WIBO" "$SNCPP" -P src/w3_a.c "$BUILD/w3_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w3_a.i" "$BUILD/w3_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w3_a.o" "$BUILD/w3_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w3_a.o" private/SLUS_204.86.rom --source src/w3_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w3_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w3_b.o" private/SLUS_204.86.rom --source src/w3_b.c
"$WIBO" "$SNCPP" -P src/w3_c.c "$BUILD/w3_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w3_c.i" "$BUILD/w3_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w3_c.o" "$BUILD/w3_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w3_c.o" private/SLUS_204.86.rom --source src/w3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w3_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w3_d.o" private/SLUS_204.86.rom --source src/w3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_a.o" private/SLUS_204.86.rom --source src/w2_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w2_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w2_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_e.o" private/SLUS_204.86.rom --source src/w2_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w2_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_f.o" private/SLUS_204.86.rom --source src/w2_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_g.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w2_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_g.o" private/SLUS_204.86.rom --source src/w2_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w2_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_h.o" private/SLUS_204.86.rom --source src/w2_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w2_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_i.o" private/SLUS_204.86.rom --source src/w2_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w2_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_j.o" private/SLUS_204.86.rom --source src/w2_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w2_k.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w2_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w2_k.o" private/SLUS_204.86.rom --source src/w2_k.c
"$WIBO" "$SNCPP" -P src/w2_d.c "$BUILD/w2_d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-falign-jumps=1" "$BUILD/w2_d.i" "$BUILD/w2_d.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_d.o" "$BUILD/w2_d.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_d.o" private/SLUS_204.86.rom --source src/w2_d.c
"$WIBO" "$SNCPP" -P src/w2_l.c "$BUILD/w2_l.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_l.i" "$BUILD/w2_l.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_l.o" "$BUILD/w2_l.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_l.o" private/SLUS_204.86.rom --source src/w2_l.c
"$WIBO" "$SNCPP" -P src/w2_m.c "$BUILD/w2_m.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_m.i" "$BUILD/w2_m.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_m.o" "$BUILD/w2_m.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_m.o" private/SLUS_204.86.rom --source src/w2_m.c
"$WIBO" "$SNCPP" -P src/w2_o.c "$BUILD/w2_o.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_o.i" "$BUILD/w2_o.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_o.o" "$BUILD/w2_o.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_o.o" private/SLUS_204.86.rom --source src/w2_o.c
"$WIBO" "$SNCPP" -P src/w2_p.c "$BUILD/w2_p.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_p.i" "$BUILD/w2_p.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_p.o" "$BUILD/w2_p.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_p.o" private/SLUS_204.86.rom --source src/w2_p.c
"$WIBO" "$SNCPP" -P src/w2_q.c "$BUILD/w2_q.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_q.i" "$BUILD/w2_q.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_q.o" "$BUILD/w2_q.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_q.o" private/SLUS_204.86.rom --source src/w2_q.c
"$WIBO" "$SNCPP" -P src/w2_n.c "$BUILD/w2_n.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w2_n.i" "$BUILD/w2_n.s"
"$PYTHON" tools/fix_switch_table.py "$BUILD/w2_n.s" jtbl_004BDE00
"$WIBO" "$SNAS" -G0 -o "$BUILD/w2_n.o" "$BUILD/w2_n.s"
"$PYTHON" tools/verify_object.py "$BUILD/w2_n.o" private/SLUS_204.86.rom --source src/w2_n.c
"$WIBO" "$SNCPP" -P src/w1_b.c "$BUILD/w1_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1_b.i" "$BUILD/w1_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1_b.o" "$BUILD/w1_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1_b.o" private/SLUS_204.86.rom --source src/w1_b.c
"$WIBO" "$SNCPP" -P src/w1_c.c "$BUILD/w1_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w1_c.i" "$BUILD/w1_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w1_c.o" "$BUILD/w1_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1_c.o" private/SLUS_204.86.rom --source src/w1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w1_d.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @47=jtbl_004BAC20 \
    "$BUILD/w1_d.o" "$BUILD/w1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1_d.o" private/SLUS_204.86.rom --source src/w1_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_a.o" private/SLUS_204.86.rom --source src/x3_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_b.o" private/SLUS_204.86.rom --source src/x3_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x3_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_c.o" private/SLUS_204.86.rom --source src/x3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_d.o" private/SLUS_204.86.rom --source src/x3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_e.o" private/SLUS_204.86.rom --source src/x3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_f.o" private/SLUS_204.86.rom --source src/x3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_g.o" private/SLUS_204.86.rom --source src/x3_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x3_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_h.o" private/SLUS_204.86.rom --source src/x3_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x3_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_i.o" private/SLUS_204.86.rom --source src/x3_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x3_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_j.o" private/SLUS_204.86.rom --source src/x3_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x3_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_k.o" private/SLUS_204.86.rom --source src/x3_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_l.o" private/SLUS_204.86.rom --source src/x3_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_m.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x3_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_m.o" private/SLUS_204.86.rom --source src/x3_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x3_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_n.o" private/SLUS_204.86.rom --source src/x3_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_p.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_p.o" private/SLUS_204.86.rom --source src/x3_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_q.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_q.o" private/SLUS_204.86.rom --source src/x3_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x3_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_r.o" private/SLUS_204.86.rom --source src/x3_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x3_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_s.o" private/SLUS_204.86.rom --source src/x3_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x3_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x3_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/x3_t.o" private/SLUS_204.86.rom --source src/x3_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x0_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_a.o" private/SLUS_204.86.rom --source src/x0_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x0_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x0_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_b.o" private/SLUS_204.86.rom --source src/x0_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x0_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_c.o" private/SLUS_204.86.rom --source src/x0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x0_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_d.o" private/SLUS_204.86.rom --source src/x0_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x0_e.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/x0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_e.o" private/SLUS_204.86.rom --source src/x0_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x0_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_f.o" private/SLUS_204.86.rom --source src/x0_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x0_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/x0_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/x0_g.o" private/SLUS_204.86.rom --source src/x0_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x11_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_a.o" private/SLUS_204.86.rom --source src/x11_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x11_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_b.o" private/SLUS_204.86.rom --source src/x11_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x11_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x11_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_c.o" private/SLUS_204.86.rom --source src/x11_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x11_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x11_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_d.o" private/SLUS_204.86.rom --source src/x11_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x11_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/x11_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_e.o" private/SLUS_204.86.rom --source src/x11_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x11_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/x11_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x11_f.o" private/SLUS_204.86.rom --source src/x11_f.c
"$WIBO" "$SNCPP" -P src/mmi_a.c "$BUILD/mmi_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/mmi_a.i" "$BUILD/mmi_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/mmi_a.o" "$BUILD/mmi_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/mmi_a.o" private/SLUS_204.86.rom --source src/mmi_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x9_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_b.o" private/SLUS_204.86.rom --source src/x9_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_c.o" private/SLUS_204.86.rom --source src/x9_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_d.c -c -lang c -O3 -Op -fp off -o "$BUILD/x9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_d.o" private/SLUS_204.86.rom --source src/x9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_e.o" private/SLUS_204.86.rom --source src/x9_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x9_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_f.o" private/SLUS_204.86.rom --source src/x9_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_g.o" private/SLUS_204.86.rom --source src/x9_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x9_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/x9_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_h.o" private/SLUS_204.86.rom --source src/x9_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x9_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_i.o" private/SLUS_204.86.rom --source src/x9_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x9_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_j.o" private/SLUS_204.86.rom --source src/x9_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x9_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_k.o" private/SLUS_204.86.rom --source src/x9_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_l.o" private/SLUS_204.86.rom --source src/x9_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x9_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x9_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/x9_m.o" private/SLUS_204.86.rom --source src/x9_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x6_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x6_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_a.o" private/SLUS_204.86.rom --source src/x6_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x6_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x6_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_b.o" private/SLUS_204.86.rom --source src/x6_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x6_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x6_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_c.o" private/SLUS_204.86.rom --source src/x6_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x6_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x6_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_g.o" private/SLUS_204.86.rom --source src/x6_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x6_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x6_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_d.o" private/SLUS_204.86.rom --source src/x6_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x6_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x6_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_e.o" private/SLUS_204.86.rom --source src/x6_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x6_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x6_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x6_f.o" private/SLUS_204.86.rom --source src/x6_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x4_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x4_a.o" private/SLUS_204.86.rom --source src/x4_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x4_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x4_b.o" private/SLUS_204.86.rom --source src/x4_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x2_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x2_a.o" private/SLUS_204.86.rom --source src/x2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x2_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x2_b.o" private/SLUS_204.86.rom --source src/x2_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x2_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x2_c.o" private/SLUS_204.86.rom --source src/x2_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x2_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x2_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x2_d.o" private/SLUS_204.86.rom --source src/x2_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x2_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x2_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x2_e.o" private/SLUS_204.86.rom --source src/x2_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x5_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_b.o" private/SLUS_204.86.rom --source src/x5_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x5_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/x5_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_c.o" private/SLUS_204.86.rom --source src/x5_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x5_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/x5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_d.o" private/SLUS_204.86.rom --source src/x5_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x5_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/x5_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_e.o" private/SLUS_204.86.rom --source src/x5_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x5_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x5_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_f.o" private/SLUS_204.86.rom --source src/x5_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x5_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/x5_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_g.o" private/SLUS_204.86.rom --source src/x5_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x5_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/x5_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_h.o" private/SLUS_204.86.rom --source src/x5_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x5_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/x5_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/x5_i.o" private/SLUS_204.86.rom --source src/x5_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/x10_a.c -c -lang c -O3 -Op -sdatathreshold 256 -o "$BUILD/x10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/x10_a.o" private/SLUS_204.86.rom --source src/x10_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/x10_b.c -c -lang c -O3 -Op -sdatathreshold 256 -o "$BUILD/x10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/x10_b.o" private/SLUS_204.86.rom --source src/x10_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y11_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_a.o" private/SLUS_204.86.rom --source src/y11_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y11_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_b.o" private/SLUS_204.86.rom --source src/y11_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y11_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y11_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_c.o" private/SLUS_204.86.rom --source src/y11_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y11_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y11_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_d.o" private/SLUS_204.86.rom --source src/y11_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y11_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y11_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_e.o" private/SLUS_204.86.rom --source src/y11_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y11_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y11_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_f.o" private/SLUS_204.86.rom --source src/y11_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y11_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y11_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_g.o" private/SLUS_204.86.rom --source src/y11_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y11_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y11_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y11_h.o" private/SLUS_204.86.rom --source src/y11_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y6_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y6_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_a.o" private/SLUS_204.86.rom --source src/y6_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y6_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y6_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_c.o" private/SLUS_204.86.rom --source src/y6_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y6_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y6_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_d.o" private/SLUS_204.86.rom --source src/y6_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y6_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y6_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_f.o" private/SLUS_204.86.rom --source src/y6_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y6_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y6_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_g.o" private/SLUS_204.86.rom --source src/y6_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y6_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y6_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_h.o" private/SLUS_204.86.rom --source src/y6_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y6_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y6_j.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @18=jtbl_004B3DA0 \
    "$BUILD/y6_j.o" "$BUILD/y6_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/y6_j.o" private/SLUS_204.86.rom --source src/y6_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y13_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y13_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y13_a.o" private/SLUS_204.86.rom --source src/y13_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y13_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y13_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y13_b.o" private/SLUS_204.86.rom --source src/y13_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y13_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y13_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y13_c.o" private/SLUS_204.86.rom --source src/y13_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y13_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y13_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y13_d.o" private/SLUS_204.86.rom --source src/y13_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y2_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y2_a.o" private/SLUS_204.86.rom --source src/y2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y2_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y2_b.o" private/SLUS_204.86.rom --source src/y2_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y9_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y9_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_a.o" private/SLUS_204.86.rom --source src/y9_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y9_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_b.o" private/SLUS_204.86.rom --source src/y9_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y9_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y9_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_c.o" private/SLUS_204.86.rom --source src/y9_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y9_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_d.o" private/SLUS_204.86.rom --source src/y9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y9_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y9_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_e.o" private/SLUS_204.86.rom --source src/y9_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y9_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y9_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y9_h.o" private/SLUS_204.86.rom --source src/y9_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y7_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_a.o" private/SLUS_204.86.rom --source src/y7_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y7_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_b.o" private/SLUS_204.86.rom --source src/y7_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y7_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y7_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_d.o" private/SLUS_204.86.rom --source src/y7_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y7_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_e.o" private/SLUS_204.86.rom --source src/y7_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y7_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_f.o" private/SLUS_204.86.rom --source src/y7_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y7_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_h.o" private/SLUS_204.86.rom --source src/y7_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y7_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_i.o" private/SLUS_204.86.rom --source src/y7_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y7_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_k.o" private/SLUS_204.86.rom --source src/y7_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y7_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_l.o" private/SLUS_204.86.rom --source src/y7_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y7_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_m.o" private/SLUS_204.86.rom --source src/y7_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_n.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y7_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_n.o" private/SLUS_204.86.rom --source src/y7_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y7_o.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y7_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/y7_o.o" private/SLUS_204.86.rom --source src/y7_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y12_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_a.o" private/SLUS_204.86.rom --source src/y12_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y12_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y12_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_b.o" private/SLUS_204.86.rom --source src/y12_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y12_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_c.o" private/SLUS_204.86.rom --source src/y12_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_d.c -c -lang c -O3 -fp off -sdatathreshold 0 -o "$BUILD/y12_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_d.o" private/SLUS_204.86.rom --source src/y12_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y12_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_e.o" private/SLUS_204.86.rom --source src/y12_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y12_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_f.o" private/SLUS_204.86.rom --source src/y12_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_g.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/y12_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_g.o" private/SLUS_204.86.rom --source src/y12_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y12_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y12_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y12_h.o" private/SLUS_204.86.rom --source src/y12_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y10_a.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/y10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_a.o" private/SLUS_204.86.rom --source src/y10_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y10_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_b.o" private/SLUS_204.86.rom --source src/y10_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y10_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y10_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_c.o" private/SLUS_204.86.rom --source src/y10_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y10_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y10_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_d.o" private/SLUS_204.86.rom --source src/y10_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y10_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y10_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_e.o" private/SLUS_204.86.rom --source src/y10_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y10_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/y10_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_f.o" private/SLUS_204.86.rom --source src/y10_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y10_g.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/y10_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_g.o" private/SLUS_204.86.rom --source src/y10_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y10_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y10_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y10_h.o" private/SLUS_204.86.rom --source src/y10_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y8_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_a.o" private/SLUS_204.86.rom --source src/y8_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y8_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_b.o" private/SLUS_204.86.rom --source src/y8_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y8_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_c.o" private/SLUS_204.86.rom --source src/y8_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y8_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_d.o" private/SLUS_204.86.rom --source src/y8_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_e.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/y8_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_e.o" private/SLUS_204.86.rom --source src/y8_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y8_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_f.o" private/SLUS_204.86.rom --source src/y8_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_g.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/y8_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_g.o" private/SLUS_204.86.rom --source src/y8_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y8_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y8_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_h.o" private/SLUS_204.86.rom --source src/y8_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y8_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y8_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/y8_i.o" private/SLUS_204.86.rom --source src/y8_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y3_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_a.o" private/SLUS_204.86.rom --source src/y3_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y3_b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/y3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_b.o" private/SLUS_204.86.rom --source src/y3_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y3_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_c.o" private/SLUS_204.86.rom --source src/y3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y3_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_e.o" private/SLUS_204.86.rom --source src/y3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y3_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_f.o" private/SLUS_204.86.rom --source src/y3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y3_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y3_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_g.o" private/SLUS_204.86.rom --source src/y3_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y3_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y3_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y3_h.o" private/SLUS_204.86.rom --source src/y3_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y4_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y4_a.o" private/SLUS_204.86.rom --source src/y4_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y4_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y4_b.o" private/SLUS_204.86.rom --source src/y4_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y4_c.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/y4_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y4_c.o" private/SLUS_204.86.rom --source src/y4_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y4_d.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/y4_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y4_d.o" private/SLUS_204.86.rom --source src/y4_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y5_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_a.o" private/SLUS_204.86.rom --source src/y5_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y5_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_b.o" private/SLUS_204.86.rom --source src/y5_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y5_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/y5_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_d.o" private/SLUS_204.86.rom --source src/y5_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y5_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y5_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_e.o" private/SLUS_204.86.rom --source src/y5_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y5_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/y5_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_f.o" private/SLUS_204.86.rom --source src/y5_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y5_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y5_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/y5_i.o" private/SLUS_204.86.rom --source src/y5_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_a.o" private/SLUS_204.86.rom --source src/y1_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_c.o" private/SLUS_204.86.rom --source src/y1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_d.o" private/SLUS_204.86.rom --source src/y1_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_e.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/y1_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_e.o" private/SLUS_204.86.rom --source src/y1_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y1_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y1_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_f.o" private/SLUS_204.86.rom --source src/y1_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/y1_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_g.o" private/SLUS_204.86.rom --source src/y1_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y1_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_h.o" private/SLUS_204.86.rom --source src/y1_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_i.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/y1_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_i.o" private/SLUS_204.86.rom --source src/y1_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y1_j.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y1_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/y1_j.o" private/SLUS_204.86.rom --source src/y1_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_c.o" private/SLUS_204.86.rom --source src/y0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_d.o" private/SLUS_204.86.rom --source src/y0_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_e.o" private/SLUS_204.86.rom --source src/y0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_f.o" private/SLUS_204.86.rom --source src/y0_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_h.o" private/SLUS_204.86.rom --source src/y0_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y0_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_i.o" private/SLUS_204.86.rom --source src/y0_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_j.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y0_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_j.o" private/SLUS_204.86.rom --source src/y0_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y0_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_k.o" private/SLUS_204.86.rom --source src/y0_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y0_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_l.o" private/SLUS_204.86.rom --source src/y0_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y0_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_m.o" private/SLUS_204.86.rom --source src/y0_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/y0_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/y0_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_o.o" private/SLUS_204.86.rom --source src/y0_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y0_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_p.o" private/SLUS_204.86.rom --source src/y0_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/y0_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_q.o" private/SLUS_204.86.rom --source src/y0_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/y0_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/y0_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/y0_r.o" private/SLUS_204.86.rom --source src/y0_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z4_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z4_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_a.o" private/SLUS_204.86.rom --source src/z4_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z4_b.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/z4_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_b.o" private/SLUS_204.86.rom --source src/z4_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z4_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z4_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_c.o" private/SLUS_204.86.rom --source src/z4_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z4_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z4_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_d.o" private/SLUS_204.86.rom --source src/z4_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_radial_snap_0015C2E0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/actor_radial_snap_0015C2E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_radial_snap_0015C2E0.o" \
    private/SLUS_204.86.rom --source src/actor_radial_snap_0015C2E0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_spawn_0014F9F0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/actor_spawn_0014F9F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_spawn_0014F9F0.o" \
    private/SLUS_204.86.rom --source src/actor_spawn_0014F9F0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z4_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z4_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_e.o" private/SLUS_204.86.rom --source src/z4_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z4_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z4_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_f.o" private/SLUS_204.86.rom --source src/z4_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z4_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z4_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z4_g.o" private/SLUS_204.86.rom --source src/z4_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z2_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z2_a.o" private/SLUS_204.86.rom --source src/z2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z2_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z2_b.o" private/SLUS_204.86.rom --source src/z2_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z2_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z2_c.o" private/SLUS_204.86.rom --source src/z2_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z2_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z2_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z2_d.o" private/SLUS_204.86.rom --source src/z2_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z2_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z2_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z2_e.o" private/SLUS_204.86.rom --source src/z2_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z5_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_a.o" private/SLUS_204.86.rom --source src/z5_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z5_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z5_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_b.o" private/SLUS_204.86.rom --source src/z5_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z5_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_c.o" private/SLUS_204.86.rom --source src/z5_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z5_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_e.o" private/SLUS_204.86.rom --source src/z5_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z5_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z5_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_f.o" private/SLUS_204.86.rom --source src/z5_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z5_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_h.o" private/SLUS_204.86.rom --source src/z5_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_timed_motion_001EAB70.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/actor_timed_motion_001EAB70.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_timed_motion_001EAB70.o" \
    private/SLUS_204.86.rom --source src/actor_timed_motion_001EAB70.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z5_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_i.o" private/SLUS_204.86.rom --source src/z5_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z5_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_j.o" private/SLUS_204.86.rom --source src/z5_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z5_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_k.o" private/SLUS_204.86.rom --source src/z5_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z5_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_l.o" private/SLUS_204.86.rom --source src/z5_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z5_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z5_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_m.o" private/SLUS_204.86.rom --source src/z5_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z5_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z5_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_n.o" private/SLUS_204.86.rom --source src/z5_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z5_o.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z5_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/z5_o.o" private/SLUS_204.86.rom --source src/z5_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z7_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z7_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_a.o" private/SLUS_204.86.rom --source src/z7_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z7_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z7_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_b.o" private/SLUS_204.86.rom --source src/z7_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z7_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z7_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_c.o" private/SLUS_204.86.rom --source src/z7_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z7_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z7_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_d.o" private/SLUS_204.86.rom --source src/z7_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z7_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z7_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_e.o" private/SLUS_204.86.rom --source src/z7_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z7_h.c -c -lang c -O3 -Op -sdatathreshold 256 -o "$BUILD/z7_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_h.o" private/SLUS_204.86.rom --source src/z7_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z7_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z7_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z7_i.o" private/SLUS_204.86.rom --source src/z7_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z6_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z6_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z6_a.o" private/SLUS_204.86.rom --source src/z6_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_motion_clamp_001A1230.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/actor_motion_clamp_001A1230.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_motion_clamp_001A1230.o" \
    private/SLUS_204.86.rom --source src/actor_motion_clamp_001A1230.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z6_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z6_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z6_b.o" private/SLUS_204.86.rom --source src/z6_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z6_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z6_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z6_c.o" private/SLUS_204.86.rom --source src/z6_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z8_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z8_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_a.o" private/SLUS_204.86.rom --source src/z8_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z8_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z8_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_b.o" private/SLUS_204.86.rom --source src/z8_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z8_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z8_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_c.o" private/SLUS_204.86.rom --source src/z8_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_anim_progress_001EB9C0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/actor_anim_progress_001EB9C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_anim_progress_001EB9C0.o" \
    private/SLUS_204.86.rom --source src/actor_anim_progress_001EB9C0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_motion_timer_00297B40.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/actor_motion_timer_00297B40.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_motion_timer_00297B40.o" \
    private/SLUS_204.86.rom --source src/actor_motion_timer_00297B40.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z8_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z8_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_d.o" private/SLUS_204.86.rom --source src/z8_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z8_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z8_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_h.o" private/SLUS_204.86.rom --source src/z8_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z8_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z8_i.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @28=jtbl_004B3A50 \
    "$BUILD/z8_i.o" "$BUILD/z8_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z8_i.o" private/SLUS_204.86.rom --source src/z8_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z11_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z11_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_a.o" private/SLUS_204.86.rom --source src/z11_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z11_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z11_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_b.o" private/SLUS_204.86.rom --source src/z11_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z11_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z11_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_c.o" private/SLUS_204.86.rom --source src/z11_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z11_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z11_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_d.o" private/SLUS_204.86.rom --source src/z11_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z11_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z11_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_e.o" private/SLUS_204.86.rom --source src/z11_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z11_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z11_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z11_f.o" private/SLUS_204.86.rom --source src/z11_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z3_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_a.o" private/SLUS_204.86.rom --source src/z3_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z3_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_b.o" private/SLUS_204.86.rom --source src/z3_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z3_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_c.o" private/SLUS_204.86.rom --source src/z3_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z3_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_d.o" private/SLUS_204.86.rom --source src/z3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z3_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_e.o" private/SLUS_204.86.rom --source src/z3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z3_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z3_f.o" private/SLUS_204.86.rom --source src/z3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z9_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_a.o" private/SLUS_204.86.rom --source src/z9_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z9_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_b.o" private/SLUS_204.86.rom --source src/z9_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z9_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_c.o" private/SLUS_204.86.rom --source src/z9_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_d.o" private/SLUS_204.86.rom --source src/z9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z9_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_e.o" private/SLUS_204.86.rom --source src/z9_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z9_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_f.o" private/SLUS_204.86.rom --source src/z9_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z9_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_g.o" private/SLUS_204.86.rom --source src/z9_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z9_i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z9_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_i.o" private/SLUS_204.86.rom --source src/z9_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_k.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z9_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_k.o" private/SLUS_204.86.rom --source src/z9_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z9_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_l.o" private/SLUS_204.86.rom --source src/z9_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z9_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z9_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_m.o" private/SLUS_204.86.rom --source src/z9_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z9_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z9_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/z9_n.o" private/SLUS_204.86.rom --source src/z9_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z0_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_a.o" private/SLUS_204.86.rom --source src/z0_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z0_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_b.o" private/SLUS_204.86.rom --source src/z0_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z0_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_c.o" private/SLUS_204.86.rom --source src/z0_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z0_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_d.o" private/SLUS_204.86.rom --source src/z0_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z0_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_e.o" private/SLUS_204.86.rom --source src/z0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_f.o" private/SLUS_204.86.rom --source src/z0_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z0_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_g.o" private/SLUS_204.86.rom --source src/z0_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_h.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z0_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_h.o" private/SLUS_204.86.rom --source src/z0_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z0_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z0_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_i.o" private/SLUS_204.86.rom --source src/z0_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z0_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z0_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/z0_j.o" private/SLUS_204.86.rom --source src/z0_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_a.o" private/SLUS_204.86.rom --source src/z1_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z1_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_b.o" private/SLUS_204.86.rom --source src/z1_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_c.o" private/SLUS_204.86.rom --source src/z1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_d.o" private/SLUS_204.86.rom --source src/z1_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z1_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_e.o" private/SLUS_204.86.rom --source src/z1_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z1_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_f.o" private/SLUS_204.86.rom --source src/z1_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z1_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_g.o" private/SLUS_204.86.rom --source src/z1_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z1_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_h.o" private/SLUS_204.86.rom --source src/z1_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z1_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_i.o" private/SLUS_204.86.rom --source src/z1_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z1_j.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/z1_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_j.o" private/SLUS_204.86.rom --source src/z1_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_k.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z1_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_k.o" private/SLUS_204.86.rom --source src/z1_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z1_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_l.o" private/SLUS_204.86.rom --source src/z1_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_m.o" private/SLUS_204.86.rom --source src/z1_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z1_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_n.o" private/SLUS_204.86.rom --source src/z1_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z1_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z1_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/z1_o.o" private/SLUS_204.86.rom --source src/z1_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z13_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z13_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_a.o" private/SLUS_204.86.rom --source src/z13_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z13_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z13_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_b.o" private/SLUS_204.86.rom --source src/z13_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z13_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z13_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_c.o" private/SLUS_204.86.rom --source src/z13_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z13_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z13_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_e.o" private/SLUS_204.86.rom --source src/z13_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z13_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z13_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_f.o" private/SLUS_204.86.rom --source src/z13_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z13_g.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/z13_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z13_g.o" private/SLUS_204.86.rom --source src/z13_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z10_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z10_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z10_a.o" private/SLUS_204.86.rom --source src/z10_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z10_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z10_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z10_b.o" private/SLUS_204.86.rom --source src/z10_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z10_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z10_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z10_c.o" private/SLUS_204.86.rom --source src/z10_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z10_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z10_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z10_e.o" private/SLUS_204.86.rom --source src/z10_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z12_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_a.o" private/SLUS_204.86.rom --source src/z12_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/z12_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_b.o" private/SLUS_204.86.rom --source src/z12_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_c.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z12_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_c.o" private/SLUS_204.86.rom --source src/z12_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_d.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z12_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_d.o" private/SLUS_204.86.rom --source src/z12_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/z12_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_e.o" private/SLUS_204.86.rom --source src/z12_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z12_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/z12_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_f.o" private/SLUS_204.86.rom --source src/z12_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/z12_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_g.o" private/SLUS_204.86.rom --source src/z12_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/z12_h.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/z12_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_h.o" private/SLUS_204.86.rom --source src/z12_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/z12_i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/z12_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/z12_i.o" private/SLUS_204.86.rom --source src/z12_i.c

: "${EE29CC1:?run tools/setup_sony29.py and source private/sony29.env}"
"$WIBO" "$SNCPP" -P src/sony29_thread_lifecycle.c "$BUILD/sony29_thread_lifecycle.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_thread_lifecycle.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_thread_lifecycle.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_thread_lifecycle.o" "$BUILD/sony29_thread_lifecycle.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_thread_lifecycle.o" private/SLUS_204.86.rom --source src/sony29_thread_lifecycle.c

"$WIBO" "$SNCPP" -P src/sony29_interrupt_state.c "$BUILD/sony29_interrupt_state.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_interrupt_state.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_interrupt_state.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_interrupt_state.o" "$BUILD/sony29_interrupt_state.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_interrupt_state.o" private/SLUS_204.86.rom --source src/sony29_interrupt_state.c

"$WIBO" "$SNCPP" -P src/read_rom_version_001004E0.c "$BUILD/read_rom_version_001004E0.i"
"$WIBO" "$EE29CC1" "$BUILD/read_rom_version_001004E0.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/read_rom_version_001004E0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_rom_version_001004E0.o" "$BUILD/read_rom_version_001004E0.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_rom_version_001004E0.o" private/SLUS_204.86.rom --source src/read_rom_version_001004E0.c

"$WIBO" "$SNCPP" -P src/update_runtime_mode_state_00101D50.c "$BUILD/update_runtime_mode_state_00101D50.i"
"$WIBO" "$EE29CC1" "$BUILD/update_runtime_mode_state_00101D50.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/update_runtime_mode_state_00101D50.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/update_runtime_mode_state_00101D50.o" "$BUILD/update_runtime_mode_state_00101D50.s"
"$PYTHON" tools/verify_object.py "$BUILD/update_runtime_mode_state_00101D50.o" private/SLUS_204.86.rom --source src/update_runtime_mode_state_00101D50.c

"$WIBO" "$SNCPP" -P src/sony29_buffer_slot_control.c "$BUILD/sony29_buffer_slot_control.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_buffer_slot_control.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_buffer_slot_control.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_buffer_slot_control.o" "$BUILD/sony29_buffer_slot_control.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_buffer_slot_control.o" private/SLUS_204.86.rom --source src/sony29_buffer_slot_control.c


"$WIBO" "$SNCPP" -P src/sony29_cache_line_rounding.c "$BUILD/sony29_cache_line_rounding.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_cache_line_rounding.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_cache_line_rounding.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_cache_line_rounding.o" "$BUILD/sony29_cache_line_rounding.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_cache_line_rounding.o" private/SLUS_204.86.rom --source src/sony29_cache_line_rounding.c

"$WIBO" "$SNCPP" -P src/sony29_rpc_queries.c "$BUILD/sony29_rpc_queries.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_rpc_queries.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_rpc_queries.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_rpc_queries.o" "$BUILD/sony29_rpc_queries.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_rpc_queries.o" private/SLUS_204.86.rom --source src/sony29_rpc_queries.c

"$WIBO" "$SNCPP" -P src/sony29_timed_semaphore_wait.c "$BUILD/sony29_timed_semaphore_wait.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_timed_semaphore_wait.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_timed_semaphore_wait.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_timed_semaphore_wait.o" "$BUILD/sony29_timed_semaphore_wait.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_timed_semaphore_wait.o" private/SLUS_204.86.rom --source src/sony29_timed_semaphore_wait.c

"$WIBO" "$SNCPP" -P src/sony29_global_call_forwarder_00107AE8.c "$BUILD/sony29_global_call_forwarder_00107AE8.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_global_call_forwarder_00107AE8.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_global_call_forwarder_00107AE8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_global_call_forwarder_00107AE8.o" "$BUILD/sony29_global_call_forwarder_00107AE8.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_global_call_forwarder_00107AE8.o" private/SLUS_204.86.rom --source src/sony29_global_call_forwarder_00107AE8.c

"$WIBO" "$SNCPP" -P src/sony29_syscall_parameters.c "$BUILD/sony29_syscall_parameters.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_syscall_parameters.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_syscall_parameters.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_syscall_parameters.o" "$BUILD/sony29_syscall_parameters.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_syscall_parameters.o" private/SLUS_204.86.rom --source src/sony29_syscall_parameters.c

"$WIBO" "$SNCPP" -P src/sony29_control_probe.c "$BUILD/sony29_control_probe.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_control_probe.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_control_probe.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_control_probe.o" "$BUILD/sony29_control_probe.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_control_probe.o" private/SLUS_204.86.rom --source src/sony29_control_probe.c

"$WIBO" "$SNCPP" -P src/sony29_rpc_wait.c "$BUILD/sony29_rpc_wait.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_rpc_wait.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_rpc_wait.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_rpc_wait.o" "$BUILD/sony29_rpc_wait.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_rpc_wait.o" private/SLUS_204.86.rom --source src/sony29_rpc_wait.c

"$WIBO" "$SNCPP" -P src/sony29_syscall_dispatchers.c "$BUILD/sony29_syscall_dispatchers.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_syscall_dispatchers.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_syscall_dispatchers.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_syscall_dispatchers.o" "$BUILD/sony29_syscall_dispatchers.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_syscall_dispatchers.o" private/SLUS_204.86.rom --source src/sony29_syscall_dispatchers.c

"$WIBO" "$SNCPP" -P src/sony29_ring_cursor_00105088.c "$BUILD/sony29_ring_cursor_00105088.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_ring_cursor_00105088.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_ring_cursor_00105088.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_ring_cursor_00105088.o" "$BUILD/sony29_ring_cursor_00105088.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_ring_cursor_00105088.o" private/SLUS_204.86.rom --source src/sony29_ring_cursor_00105088.c

"$WIBO" "$SNCPP" -P src/sony29_rpc_result.c "$BUILD/sony29_rpc_result.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_rpc_result.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_rpc_result.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_rpc_result.o" "$BUILD/sony29_rpc_result.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_rpc_result.o" private/SLUS_204.86.rom --source src/sony29_rpc_result.c

"$WIBO" "$SNCPP" -P src/sony29_varargs_forwarder_00105E48.c "$BUILD/sony29_varargs_forwarder_00105E48.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_varargs_forwarder_00105E48.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_varargs_forwarder_00105E48.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_varargs_forwarder_00105E48.o" "$BUILD/sony29_varargs_forwarder_00105E48.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_varargs_forwarder_00105E48.o" private/SLUS_204.86.rom --source src/sony29_varargs_forwarder_00105E48.c

"$WIBO" "$SNCPP" -P src/sony29_varargs_handler_00105E80.c "$BUILD/sony29_varargs_handler_00105E80.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_varargs_handler_00105E80.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_varargs_handler_00105E80.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_varargs_handler_00105E80.o" "$BUILD/sony29_varargs_handler_00105E80.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_varargs_handler_00105E80.o" private/SLUS_204.86.rom --source src/sony29_varargs_handler_00105E80.c

"$WIBO" "$SNCPP" -P src/write_gs_register_packet_00100908.c "$BUILD/write_gs_register_packet_00100908.i"
"$WIBO" "$EE29CC1" "$BUILD/write_gs_register_packet_00100908.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/write_gs_register_packet_00100908.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/write_gs_register_packet_00100908.o" "$BUILD/write_gs_register_packet_00100908.s"
"$PYTHON" tools/verify_object.py "$BUILD/write_gs_register_packet_00100908.o" private/SLUS_204.86.rom --source src/write_gs_register_packet_00100908.c

"$WIBO" "$SNCPP" -P src/sony29_clear_flag_00106898.c "$BUILD/sony29_clear_flag_00106898.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_clear_flag_00106898.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_clear_flag_00106898.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_clear_flag_00106898.o" "$BUILD/sony29_clear_flag_00106898.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_clear_flag_00106898.o" private/SLUS_204.86.rom --source src/sony29_clear_flag_00106898.c

"$WIBO" "$SNCPP" -P src/sony29_guarded_rpc.c "$BUILD/sony29_guarded_rpc.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_guarded_rpc.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_guarded_rpc.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_guarded_rpc.o" "$BUILD/sony29_guarded_rpc.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_guarded_rpc.o" private/SLUS_204.86.rom --source src/sony29_guarded_rpc.c

"$WIBO" "$SNCPP" -P src/sony29_event_callbacks.c "$BUILD/sony29_event_callbacks.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_event_callbacks.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_event_callbacks.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_event_callbacks.o" "$BUILD/sony29_event_callbacks.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_event_callbacks.o" private/SLUS_204.86.rom --source src/sony29_event_callbacks.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L0_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/L0_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/L0_c.o" private/SLUS_204.86.rom --source src/L0_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/L0_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/L0_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/L0_e.o" private/SLUS_204.86.rom --source src/L0_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L0_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/L0_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/L0_f.o" private/SLUS_204.86.rom --source src/L0_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/L0_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/L0_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/L0_h.o" private/SLUS_204.86.rom --source src/L0_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/L1_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/L1_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/L1_a.o" private/SLUS_204.86.rom --source src/L1_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L1_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/L1_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/L1_c.o" private/SLUS_204.86.rom --source src/L1_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L2_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/L2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/L2_a.o" private/SLUS_204.86.rom --source src/L2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L2_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/L2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/L2_c.o" private/SLUS_204.86.rom --source src/L2_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L2_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/L2_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/L2_d.o" private/SLUS_204.86.rom --source src/L2_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L3_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/L3_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_a.o" private/SLUS_204.86.rom --source src/L3_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L3_b.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/L3_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_b.o" private/SLUS_204.86.rom --source src/L3_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/L3_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/L3_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_c.o" private/SLUS_204.86.rom --source src/L3_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/L3_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/L3_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_d.o" private/SLUS_204.86.rom --source src/L3_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L3_e.c -c -lang c -O3 -sdatathreshold 256 -o "$BUILD/L3_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_e.o" private/SLUS_204.86.rom --source src/L3_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/L3_f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/L3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/L3_f.o" private/SLUS_204.86.rom --source src/L3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_e.o" private/SLUS_204.86.rom --source src/q7_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/actor_grounded_motion_002BC230.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/actor_grounded_motion_002BC230.o"
"$PYTHON" tools/verify_object.py "$BUILD/actor_grounded_motion_002BC230.o" \
    private/SLUS_204.86.rom --source src/actor_grounded_motion_002BC230.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_f.o" private/SLUS_204.86.rom --source src/q7_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_g.o" private/SLUS_204.86.rom --source src/q7_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q7_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_h.o" private/SLUS_204.86.rom --source src/q7_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_j.o" private/SLUS_204.86.rom --source src/q7_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_k.o" private/SLUS_204.86.rom --source src/q7_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_l.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q7_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_l.o" private/SLUS_204.86.rom --source src/q7_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_m.o" private/SLUS_204.86.rom --source src/q7_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_n.o" private/SLUS_204.86.rom --source src/q7_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_o.o" private/SLUS_204.86.rom --source src/q7_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_p.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_p.o" private/SLUS_204.86.rom --source src/q7_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_q.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q7_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_q.o" private/SLUS_204.86.rom --source src/q7_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_r.o" private/SLUS_204.86.rom --source src/q7_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_t.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q7_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_t.o" private/SLUS_204.86.rom --source src/q7_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_v.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_v.o" private/SLUS_204.86.rom --source src/q7_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_w.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_w.o" private/SLUS_204.86.rom --source src/q7_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_x.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q7_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_x.o" private/SLUS_204.86.rom --source src/q7_x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_y.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_y.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_y.o" private/SLUS_204.86.rom --source src/q7_y.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q7_z.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_z.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_z.o" private/SLUS_204.86.rom --source src/q7_z.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q7_aa.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q7_aa.o"
"$PYTHON" tools/verify_object.py "$BUILD/q7_aa.o" private/SLUS_204.86.rom --source src/q7_aa.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_f.o" private/SLUS_204.86.rom --source src/q3_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q3_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_h.o" private/SLUS_204.86.rom --source src/q3_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_i.o" private/SLUS_204.86.rom --source src/q3_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_j.o" private/SLUS_204.86.rom --source src/q3_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_k.o" private/SLUS_204.86.rom --source src/q3_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_l.o" private/SLUS_204.86.rom --source src/q3_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_m.o" private/SLUS_204.86.rom --source src/q3_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_n.o" private/SLUS_204.86.rom --source src/q3_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_o.o" private/SLUS_204.86.rom --source src/q3_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3_p.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q3_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_p.o" private/SLUS_204.86.rom --source src/q3_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q3_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_q.o" private/SLUS_204.86.rom --source src/q3_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_r.o" private/SLUS_204.86.rom --source src/q3_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_s.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q3_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_s.o" private/SLUS_204.86.rom --source src/q3_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q3_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_t.o" private/SLUS_204.86.rom --source src/q3_t.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q3_u.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q3_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_u.o" private/SLUS_204.86.rom --source src/q3_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_v.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_v.o" private/SLUS_204.86.rom --source src/q3_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q3_w.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q3_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/q3_w.o" private/SLUS_204.86.rom --source src/q3_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_ad.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q6_ad.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_ad.o" private/SLUS_204.86.rom --source src/q6_ad.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_ae.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_ae.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_ae.o" private/SLUS_204.86.rom --source src/q6_ae.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_af.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_af.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @12=jtbl_004B83B0 \
    "$BUILD/q6_af.o" "$BUILD/q6_af.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_af.o" private/SLUS_204.86.rom --source src/q6_af.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q6_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_d.o" private/SLUS_204.86.rom --source src/q6_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_e.o" private/SLUS_204.86.rom --source src/q6_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q6_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_f.o" private/SLUS_204.86.rom --source src/q6_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q6_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_g.o" private/SLUS_204.86.rom --source src/q6_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_h.o" private/SLUS_204.86.rom --source src/q6_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_i.o" private/SLUS_204.86.rom --source src/q6_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_j.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_j.o" private/SLUS_204.86.rom --source src/q6_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_k.o" private/SLUS_204.86.rom --source src/q6_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_l.o" private/SLUS_204.86.rom --source src/q6_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q6_m.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q6_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_m.o" private/SLUS_204.86.rom --source src/q6_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_n.o" private/SLUS_204.86.rom --source src/q6_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_o.o" private/SLUS_204.86.rom --source src/q6_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_p.o" private/SLUS_204.86.rom --source src/q6_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_q.o" private/SLUS_204.86.rom --source src/q6_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_r.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q6_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_r.o" private/SLUS_204.86.rom --source src/q6_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_s.o" private/SLUS_204.86.rom --source src/q6_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_t.o" private/SLUS_204.86.rom --source src/q6_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_u.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_u.o" private/SLUS_204.86.rom --source src/q6_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_v.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q6_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_v.o" private/SLUS_204.86.rom --source src/q6_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_w.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q6_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_w.o" private/SLUS_204.86.rom --source src/q6_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_x.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_x.o" private/SLUS_204.86.rom --source src/q6_x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_y.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_y.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_y.o" private/SLUS_204.86.rom --source src/q6_y.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_z.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q6_z.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_z.o" private/SLUS_204.86.rom --source src/q6_z.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q6_aa.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/q6_aa.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_aa.o" private/SLUS_204.86.rom --source src/q6_aa.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q6_ab.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q6_ab.o"
"$PYTHON" tools/verify_object.py "$BUILD/q6_ab.o" private/SLUS_204.86.rom --source src/q6_ab.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q9_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q9_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_d.o" private/SLUS_204.86.rom --source src/q9_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q9_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q9_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_e.o" private/SLUS_204.86.rom --source src/q9_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q9_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q9_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q9_f.o" private/SLUS_204.86.rom --source src/q9_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q0_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_g.o" private/SLUS_204.86.rom --source src/q0_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q0_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_k.o" private/SLUS_204.86.rom --source src/q0_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q0_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_h.o" private/SLUS_204.86.rom --source src/q0_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q0_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q0_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_i.o" private/SLUS_204.86.rom --source src/q0_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q0_j.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q0_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q0_j.o" private/SLUS_204.86.rom --source src/q0_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_f.o" private/SLUS_204.86.rom --source src/q4_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_g.o" private/SLUS_204.86.rom --source src/q4_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_h.o" private/SLUS_204.86.rom --source src/q4_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_k.o" private/SLUS_204.86.rom --source src/q4_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_l.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_l.o" private/SLUS_204.86.rom --source src/q4_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_m.o" private/SLUS_204.86.rom --source src/q4_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_n.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_n.o" private/SLUS_204.86.rom --source src/q4_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_o.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_o.o" private/SLUS_204.86.rom --source src/q4_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_p.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_p.o" private/SLUS_204.86.rom --source src/q4_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_q.o" private/SLUS_204.86.rom --source src/q4_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_r.o" private/SLUS_204.86.rom --source src/q4_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_s.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q4_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_s.o" private/SLUS_204.86.rom --source src/q4_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q4_t.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_t.o" private/SLUS_204.86.rom --source src/q4_t.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q4_u.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q4_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/q4_u.o" private/SLUS_204.86.rom --source src/q4_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q5_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_g.o" private/SLUS_204.86.rom --source src/q5_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q5_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_h.o" private/SLUS_204.86.rom --source src/q5_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q5_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_i.o" private/SLUS_204.86.rom --source src/q5_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_j.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q5_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_j.o" private/SLUS_204.86.rom --source src/q5_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_k.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q5_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_k.o" private/SLUS_204.86.rom --source src/q5_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q5_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q5_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_l.o" private/SLUS_204.86.rom --source src/q5_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q5_m.c -c -lang c -O4 -Op -sdatathreshold 0 -o "$BUILD/q5_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_m.o" private/SLUS_204.86.rom --source src/q5_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q5_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q5_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_n.o" private/SLUS_204.86.rom --source src/q5_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q5_o.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q5_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q5_o.o" private/SLUS_204.86.rom --source src/q5_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_e.o" private/SLUS_204.86.rom --source src/q8_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_f.o" private/SLUS_204.86.rom --source src/q8_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_g.o" private/SLUS_204.86.rom --source src/q8_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q8_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_h.o" private/SLUS_204.86.rom --source src/q8_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q8_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_i.o" private/SLUS_204.86.rom --source src/q8_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q8_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_j.o" private/SLUS_204.86.rom --source src/q8_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_k.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_k.o" private/SLUS_204.86.rom --source src/q8_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_l.o" private/SLUS_204.86.rom --source src/q8_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_m.o" private/SLUS_204.86.rom --source src/q8_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_n.o" private/SLUS_204.86.rom --source src/q8_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_o.o" private/SLUS_204.86.rom --source src/q8_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_p.o" private/SLUS_204.86.rom --source src/q8_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_q.o" private/SLUS_204.86.rom --source src/q8_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_r.o" private/SLUS_204.86.rom --source src/q8_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_s.o" private/SLUS_204.86.rom --source src/q8_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_t.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_t.o" private/SLUS_204.86.rom --source src/q8_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_u.o" private/SLUS_204.86.rom --source src/q8_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_v.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_v.o" private/SLUS_204.86.rom --source src/q8_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_w.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q8_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_w.o" private/SLUS_204.86.rom --source src/q8_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_x.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_x.o" private/SLUS_204.86.rom --source src/q8_x.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q8_y.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_y.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_y.o" private/SLUS_204.86.rom --source src/q8_y.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_z.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_z.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_z.o" private/SLUS_204.86.rom --source src/q8_z.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_aa.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q8_aa.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_aa.o" private/SLUS_204.86.rom --source src/q8_aa.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_ab.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q8_ab.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_ab.o" private/SLUS_204.86.rom --source src/q8_ab.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q8_ac.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q8_ac.o"
"$PYTHON" tools/verify_object.py "$BUILD/q8_ac.o" private/SLUS_204.86.rom --source src/q8_ac.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_indicator_001EA110.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/state_indicator_001EA110.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_indicator_001EA110.o" \
    private/SLUS_204.86.rom --source src/state_indicator_001EA110.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_g.o" private/SLUS_204.86.rom --source src/q1_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/q1_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_i.o" private/SLUS_204.86.rom --source src/q1_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q1_j.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/q1_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_j.o" private/SLUS_204.86.rom --source src/q1_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_k.o" private/SLUS_204.86.rom --source src/q1_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/q1_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_l.o" private/SLUS_204.86.rom --source src/q1_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_m.o" private/SLUS_204.86.rom --source src/q1_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_n.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/q1_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_n.o" private/SLUS_204.86.rom --source src/q1_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q1_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q1_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_o.o" private/SLUS_204.86.rom --source src/q1_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q1_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q1_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/q1_q.o" private/SLUS_204.86.rom --source src/q1_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q2_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2_a.o" private/SLUS_204.86.rom --source src/q2_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q2_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/q2_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2_b.o" private/SLUS_204.86.rom --source src/q2_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q2_c.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/q2_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2_c.o" private/SLUS_204.86.rom --source src/q2_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/q2_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/q2_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2_d.o" private/SLUS_204.86.rom --source src/q2_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/q2_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/q2_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/q2_e.o" private/SLUS_204.86.rom --source src/q2_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/R2_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/R2_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/R2_a.o" private/SLUS_204.86.rom --source src/R2_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1710_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_a.o" private/SLUS_204.86.rom --source src/w1710_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1710_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_b.o" private/SLUS_204.86.rom --source src/w1710_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1710_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_c.o" private/SLUS_204.86.rom --source src/w1710_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1710_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_d.o" private/SLUS_204.86.rom --source src/w1710_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1710_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_e.o" private/SLUS_204.86.rom --source src/w1710_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1710_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_f.o" private/SLUS_204.86.rom --source src/w1710_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1710_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1710_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_g.o" private/SLUS_204.86.rom --source src/w1710_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_h.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w1710_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_h.o" private/SLUS_204.86.rom --source src/w1710_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1710_i.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w1710_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_i.o" private/SLUS_204.86.rom --source src/w1710_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_j.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1710_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_j.o" private/SLUS_204.86.rom --source src/w1710_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1710_k.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/w1710_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_k.o" private/SLUS_204.86.rom --source src/w1710_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1710_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_m.o" private/SLUS_204.86.rom --source src/w1710_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1710_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1710_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1710_n.o" private/SLUS_204.86.rom --source src/w1710_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w178_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w178_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_a.o" private/SLUS_204.86.rom --source src/w178_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w178_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w178_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_b.o" private/SLUS_204.86.rom --source src/w178_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w178_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w178_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_c.o" private/SLUS_204.86.rom --source src/w178_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w178_d.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/w178_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_d.o" private/SLUS_204.86.rom --source src/w178_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w178_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w178_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_e.o" private/SLUS_204.86.rom --source src/w178_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w178_f.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/w178_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w178_f.o" private/SLUS_204.86.rom --source src/w178_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_a.o" private/SLUS_204.86.rom --source src/w173_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_b.o" private/SLUS_204.86.rom --source src/w173_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_c.o" private/SLUS_204.86.rom --source src/w173_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w173_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_d.o" private/SLUS_204.86.rom --source src/w173_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_e.o" private/SLUS_204.86.rom --source src/w173_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_f.o" private/SLUS_204.86.rom --source src/w173_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w173_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_g.o" private/SLUS_204.86.rom --source src/w173_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_h.o" private/SLUS_204.86.rom --source src/w173_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_i.o" private/SLUS_204.86.rom --source src/w173_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_j.o" private/SLUS_204.86.rom --source src/w173_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w173_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_k.o" private/SLUS_204.86.rom --source src/w173_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_l.o" private/SLUS_204.86.rom --source src/w173_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_m.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w173_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_m.o" private/SLUS_204.86.rom --source src/w173_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_n.o" private/SLUS_204.86.rom --source src/w173_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w173_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_o.o" private/SLUS_204.86.rom --source src/w173_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_p.o" private/SLUS_204.86.rom --source src/w173_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_q.o" private/SLUS_204.86.rom --source src/w173_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_r.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w173_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_r.o" private/SLUS_204.86.rom --source src/w173_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w173_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_s.o" private/SLUS_204.86.rom --source src/w173_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w173_t.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w173_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_t.o" private/SLUS_204.86.rom --source src/w173_t.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w173_u.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w173_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w173_u.o" private/SLUS_204.86.rom --source src/w173_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w179_a.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w179_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_a.o" private/SLUS_204.86.rom --source src/w179_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w179_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w179_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_b.o" private/SLUS_204.86.rom --source src/w179_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w179_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w179_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_c.o" private/SLUS_204.86.rom --source src/w179_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w179_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w179_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_d.o" private/SLUS_204.86.rom --source src/w179_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w179_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w179_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_e.o" private/SLUS_204.86.rom --source src/w179_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w179_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w179_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_f.o" private/SLUS_204.86.rom --source src/w179_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w179_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w179_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_g.o" private/SLUS_204.86.rom --source src/w179_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w179_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w179_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w179_h.o" private/SLUS_204.86.rom --source src/w179_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w172_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w172_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_a.o" private/SLUS_204.86.rom --source src/w172_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w172_b.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w172_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_b.o" private/SLUS_204.86.rom --source src/w172_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w172_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w172_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_c.o" private/SLUS_204.86.rom --source src/w172_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w172_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w172_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_d.o" private/SLUS_204.86.rom --source src/w172_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w172_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w172_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_e.o" private/SLUS_204.86.rom --source src/w172_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w172_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w172_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w172_f.o" private/SLUS_204.86.rom --source src/w172_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w177_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_a.o" private/SLUS_204.86.rom --source src/w177_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_b.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w177_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_b.o" private/SLUS_204.86.rom --source src/w177_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w177_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_c.o" private/SLUS_204.86.rom --source src/w177_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w177_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_d.o" private/SLUS_204.86.rom --source src/w177_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w177_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_e.o" private/SLUS_204.86.rom --source src/w177_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w177_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_f.o" private/SLUS_204.86.rom --source src/w177_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w177_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_g.o" private/SLUS_204.86.rom --source src/w177_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w177_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w177_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_h.o" private/SLUS_204.86.rom --source src/w177_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w177_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w177_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w177_i.o" private/SLUS_204.86.rom --source src/w177_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w171_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_a.o" private/SLUS_204.86.rom --source src/w171_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w171_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_b.o" private/SLUS_204.86.rom --source src/w171_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w171_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w171_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_c.o" private/SLUS_204.86.rom --source src/w171_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w171_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_d.o" private/SLUS_204.86.rom --source src/w171_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w171_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_e.o" private/SLUS_204.86.rom --source src/w171_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w171_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w171_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_f.o" private/SLUS_204.86.rom --source src/w171_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w171_g.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/w171_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_g.o" private/SLUS_204.86.rom --source src/w171_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w171_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_h.o" private/SLUS_204.86.rom --source src/w171_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w171_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w171_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_i.o" private/SLUS_204.86.rom --source src/w171_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w171_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_k.o" private/SLUS_204.86.rom --source src/w171_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w171_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_l.o" private/SLUS_204.86.rom --source src/w171_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w171_m.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @21=jtbl_004B7370 \
    "$BUILD/w171_m.o" "$BUILD/w171_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_m.o" private/SLUS_204.86.rom --source src/w171_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w171_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_n.o" private/SLUS_204.86.rom --source src/w171_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w171_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_o.o" private/SLUS_204.86.rom --source src/w171_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w171_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_p.o" private/SLUS_204.86.rom --source src/w171_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w171_r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w171_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_r.o" private/SLUS_204.86.rom --source src/w171_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_s.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w171_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_s.o" private/SLUS_204.86.rom --source src/w171_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w171_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w171_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w171_t.o" private/SLUS_204.86.rom --source src/w171_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w176_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_a.o" private/SLUS_204.86.rom --source src/w176_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w176_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w176_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_b.o" private/SLUS_204.86.rom --source src/w176_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w176_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_c.o" private/SLUS_204.86.rom --source src/w176_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w176_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_e.o" private/SLUS_204.86.rom --source src/w176_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w176_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_f.o" private/SLUS_204.86.rom --source src/w176_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_g.o" private/SLUS_204.86.rom --source src/w176_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w176_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_i.o" private/SLUS_204.86.rom --source src/w176_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_j.o" private/SLUS_204.86.rom --source src/w176_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w176_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w176_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_m.o" private/SLUS_204.86.rom --source src/w176_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w176_n.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w176_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_n.o" private/SLUS_204.86.rom --source src/w176_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_p.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w176_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_p.o" private/SLUS_204.86.rom --source src/w176_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_q.o" private/SLUS_204.86.rom --source src/w176_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w176_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_r.o" private/SLUS_204.86.rom --source src/w176_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_s.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_s.o" private/SLUS_204.86.rom --source src/w176_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_t.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w176_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_t.o" private/SLUS_204.86.rom --source src/w176_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w176_u.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w176_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w176_u.o" private/SLUS_204.86.rom --source src/w176_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_a.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w170_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_a.o" private/SLUS_204.86.rom --source src/w170_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w170_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_b.o" private/SLUS_204.86.rom --source src/w170_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w170_d.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w170_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_d.o" private/SLUS_204.86.rom --source src/w170_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w170_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_e.o" private/SLUS_204.86.rom --source src/w170_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w170_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_g.o" private/SLUS_204.86.rom --source src/w170_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w170_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_h.o" private/SLUS_204.86.rom --source src/w170_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w170_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_i.o" private/SLUS_204.86.rom --source src/w170_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w170_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_j.o" private/SLUS_204.86.rom --source src/w170_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_k.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w170_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_k.o" private/SLUS_204.86.rom --source src/w170_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w170_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_l.o" private/SLUS_204.86.rom --source src/w170_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w170_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_m.o" private/SLUS_204.86.rom --source src/w170_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w170_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w170_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_n.o" private/SLUS_204.86.rom --source src/w170_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_o.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w170_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_o.o" private/SLUS_204.86.rom --source src/w170_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_p.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w170_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_p.o" private/SLUS_204.86.rom --source src/w170_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w170_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w170_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w170_q.o" private/SLUS_204.86.rom --source src/w170_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w175_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w175_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_a.o" private/SLUS_204.86.rom --source src/w175_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w175_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w175_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_b.o" private/SLUS_204.86.rom --source src/w175_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w175_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w175_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_c.o" private/SLUS_204.86.rom --source src/w175_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w175_d.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w175_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_d.o" private/SLUS_204.86.rom --source src/w175_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w175_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w175_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_e.o" private/SLUS_204.86.rom --source src/w175_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w175_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w175_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_f.o" private/SLUS_204.86.rom --source src/w175_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w175_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w175_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_g.o" private/SLUS_204.86.rom --source src/w175_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w175_h.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/w175_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w175_h.o" private/SLUS_204.86.rom --source src/w175_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w174_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_a.o" private/SLUS_204.86.rom --source src/w174_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w174_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_b.o" private/SLUS_204.86.rom --source src/w174_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w174_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_c.o" private/SLUS_204.86.rom --source src/w174_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w174_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w174_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_d.o" private/SLUS_204.86.rom --source src/w174_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w174_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_e.o" private/SLUS_204.86.rom --source src/w174_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w174_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w174_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_g.o" private/SLUS_204.86.rom --source src/w174_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w174_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_h.o" private/SLUS_204.86.rom --source src/w174_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w174_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_i.o" private/SLUS_204.86.rom --source src/w174_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_j.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w174_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_j.o" private/SLUS_204.86.rom --source src/w174_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_k.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w174_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_k.o" private/SLUS_204.86.rom --source src/w174_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_l.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w174_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_l.o" private/SLUS_204.86.rom --source src/w174_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w174_m.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w174_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w174_m.o" private/SLUS_204.86.rom --source src/w174_m.c
"$WIBO" "$SNCPP" -P src/w181_a.c "$BUILD/w181_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w181_a.i" "$BUILD/w181_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w181_a.o" "$BUILD/w181_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w181_a.o" private/SLUS_204.86.rom --source src/w181_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w181_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_c.o" private/SLUS_204.86.rom --source src/w181_c.c
"$WIBO" "$SNCPP" -P src/w181_d.c "$BUILD/w181_d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w181_d.i" "$BUILD/w181_d.s"
"$WIBO" "$SNAS" -mips4 -G0 -o "$BUILD/w181_d.o" "$BUILD/w181_d.s"
"$PYTHON" tools/verify_object.py "$BUILD/w181_d.o" private/SLUS_204.86.rom --source src/w181_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w181_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_e.o" private/SLUS_204.86.rom --source src/w181_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w181_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_f.o" private/SLUS_204.86.rom --source src/w181_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w181_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_g.o" private/SLUS_204.86.rom --source src/w181_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w181_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_h.o" private/SLUS_204.86.rom --source src/w181_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_i.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w181_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_i.o" private/SLUS_204.86.rom --source src/w181_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w181_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w181_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_j.o" private/SLUS_204.86.rom --source src/w181_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w181_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_k.o" private/SLUS_204.86.rom --source src/w181_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w181_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_l.o" private/SLUS_204.86.rom --source src/w181_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w181_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_m.o" private/SLUS_204.86.rom --source src/w181_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w181_n.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w181_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_n.o" private/SLUS_204.86.rom --source src/w181_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w181_o.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w181_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w181_o.o" private/SLUS_204.86.rom --source src/w181_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w184_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w184_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_b.o" private/SLUS_204.86.rom --source src/w184_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w184_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w184_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_c.o" private/SLUS_204.86.rom --source src/w184_c.c
"$WIBO" "$SNCPP" -P src/w184_d.c "$BUILD/w184_d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w184_d.i" "$BUILD/w184_d.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w184_d.o" "$BUILD/w184_d.s"
"$PYTHON" tools/verify_object.py "$BUILD/w184_d.o" private/SLUS_204.86.rom --source src/w184_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w184_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w184_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_e.o" private/SLUS_204.86.rom --source src/w184_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_luna_oct19_callbacks.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_luna_oct19_callbacks.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_luna_oct19_callbacks.o" private/SLUS_204.86.rom --source src/grok_luna_oct19_callbacks.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_luna_oct19_callbacks_b2.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/grok_luna_oct19_callbacks_b2.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_luna_oct19_callbacks_b2.o" private/SLUS_204.86.rom --source src/grok_luna_oct19_callbacks_b2.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w184_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w184_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_f.o" private/SLUS_204.86.rom --source src/w184_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w184_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w184_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_g.o" private/SLUS_204.86.rom --source src/w184_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w184_h.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w184_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_h.o" private/SLUS_204.86.rom --source src/w184_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w184_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w184_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_i.o" private/SLUS_204.86.rom --source src/w184_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w184_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w184_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w184_j.o" private/SLUS_204.86.rom --source src/w184_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_c.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w186_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_c.o" private/SLUS_204.86.rom --source src/w186_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w186_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_e.o" private/SLUS_204.86.rom --source src/w186_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w186_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_f.o" private/SLUS_204.86.rom --source src/w186_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w186_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w186_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_g.o" private/SLUS_204.86.rom --source src/w186_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w186_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_h.o" private/SLUS_204.86.rom --source src/w186_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w186_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_k.o" private/SLUS_204.86.rom --source src/w186_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w186_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_l.o" private/SLUS_204.86.rom --source src/w186_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w186_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_n.o" private/SLUS_204.86.rom --source src/w186_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w186_o.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @24=jtbl_004B5B50 \
    "$BUILD/w186_o.o" "$BUILD/w186_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_o.o" private/SLUS_204.86.rom --source src/w186_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_p.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w186_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_p.o" private/SLUS_204.86.rom --source src/w186_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_q.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w186_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_q.o" private/SLUS_204.86.rom --source src/w186_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w186_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_r.o" private/SLUS_204.86.rom --source src/w186_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w186_s.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w186_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w186_s.o" private/SLUS_204.86.rom --source src/w186_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_c.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w180_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_c.o" private/SLUS_204.86.rom --source src/w180_c.c
"$WIBO" "$SNCPP" -P src/w180_e.c "$BUILD/w180_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w180_e.i" "$BUILD/w180_e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w180_e.o" "$BUILD/w180_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/w180_e.o" private/SLUS_204.86.rom --source src/w180_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w180_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_f.o" private/SLUS_204.86.rom --source src/w180_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w180_g.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @23=jtbl_004B7330 \
    "$BUILD/w180_g.o" "$BUILD/w180_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_g.o" private/SLUS_204.86.rom --source src/w180_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w180_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_h.o" private/SLUS_204.86.rom --source src/w180_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_j.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_j.o" private/SLUS_204.86.rom --source src/w180_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_k.o" private/SLUS_204.86.rom --source src/w180_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w180_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_m.o" private/SLUS_204.86.rom --source src/w180_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_n.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w180_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_n.o" private/SLUS_204.86.rom --source src/w180_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w180_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_o.o" private/SLUS_204.86.rom --source src/w180_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w180_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w180_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_p.o" private/SLUS_204.86.rom --source src/w180_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w180_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_q.o" private/SLUS_204.86.rom --source src/w180_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w180_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_r.o" private/SLUS_204.86.rom --source src/w180_r.c
"$WIBO" "$SNCPP" -P src/w180_s.c "$BUILD/w180_s.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w180_s.i" "$BUILD/w180_s.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w180_s.o" "$BUILD/w180_s.s"
"$PYTHON" tools/verify_object.py "$BUILD/w180_s.o" private/SLUS_204.86.rom --source src/w180_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_t.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_t.o" private/SLUS_204.86.rom --source src/w180_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_u.o" private/SLUS_204.86.rom --source src/w180_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_v.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w180_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_v.o" private/SLUS_204.86.rom --source src/w180_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w180_w.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w180_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/w180_w.o" private/SLUS_204.86.rom --source src/w180_w.c
"$WIBO" "$SNCPP" -P src/w180_x.c "$BUILD/w180_x.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/w180_x.i" "$BUILD/w180_x.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w180_x.o" "$BUILD/w180_x.s"
"$PYTHON" tools/verify_object.py "$BUILD/w180_x.o" private/SLUS_204.86.rom --source src/w180_x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w182_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_c.o" private/SLUS_204.86.rom --source src/w182_c.c
"$WIBO" "$SNCPP" -P src/w182_e.c "$BUILD/w182_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w182_e.i" "$BUILD/w182_e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w182_e.o" "$BUILD/w182_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/w182_e.o" private/SLUS_204.86.rom --source src/w182_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_f.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_f.o" private/SLUS_204.86.rom --source src/w182_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w182_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_g.o" private/SLUS_204.86.rom --source src/w182_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_h.o" private/SLUS_204.86.rom --source src/w182_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w182_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_i.o" private/SLUS_204.86.rom --source src/w182_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_j.o" private/SLUS_204.86.rom --source src/w182_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_k.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_k.o" private/SLUS_204.86.rom --source src/w182_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_l.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w182_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_l.o" private/SLUS_204.86.rom --source src/w182_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w182_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_m.o" private/SLUS_204.86.rom --source src/w182_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w182_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w182_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w182_n.o" private/SLUS_204.86.rom --source src/w182_n.c
"$WIBO" "$SNCPP" -P src/w185_c.c "$BUILD/w185_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w185_c.i" "$BUILD/w185_c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w185_c.o" "$BUILD/w185_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w185_c.o" private/SLUS_204.86.rom --source src/w185_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w185_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_e.o" private/SLUS_204.86.rom --source src/w185_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w185_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_f.o" private/SLUS_204.86.rom --source src/w185_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w185_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_h.o" private/SLUS_204.86.rom --source src/w185_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_i.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/w185_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_i.o" private/SLUS_204.86.rom --source src/w185_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w185_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w185_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_j.o" private/SLUS_204.86.rom --source src/w185_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_k.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w185_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_k.o" private/SLUS_204.86.rom --source src/w185_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w185_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w185_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w185_l.o" private/SLUS_204.86.rom --source src/w185_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_b.o" private/SLUS_204.86.rom --source src/w183_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w183_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_d.o" private/SLUS_204.86.rom --source src/w183_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_e.o" private/SLUS_204.86.rom --source src/w183_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w183_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_f.o" private/SLUS_204.86.rom --source src/w183_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w183_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_g.o" private/SLUS_204.86.rom --source src/w183_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_h.o" private/SLUS_204.86.rom --source src/w183_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_i.o" private/SLUS_204.86.rom --source src/w183_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_j.o" private/SLUS_204.86.rom --source src/w183_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_k.o" private/SLUS_204.86.rom --source src/w183_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_l.o" private/SLUS_204.86.rom --source src/w183_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_m.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w183_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_m.o" private/SLUS_204.86.rom --source src/w183_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_n.o" private/SLUS_204.86.rom --source src/w183_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_p.o" private/SLUS_204.86.rom --source src/w183_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w183_q.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w183_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_q.o" private/SLUS_204.86.rom --source src/w183_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_r.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w183_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_r.o" private/SLUS_204.86.rom --source src/w183_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w183_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_s.o" private/SLUS_204.86.rom --source src/w183_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_t.o" private/SLUS_204.86.rom --source src/w183_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_v.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_v.o" private/SLUS_204.86.rom --source src/w183_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_w.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w183_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_w.o" private/SLUS_204.86.rom --source src/w183_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_x.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w183_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_x.o" private/SLUS_204.86.rom --source src/w183_x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w183_z.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w183_z.o"
"$PYTHON" tools/verify_object.py "$BUILD/w183_z.o" private/SLUS_204.86.rom --source src/w183_z.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_b.o" private/SLUS_204.86.rom --source src/w1813_b.c
"$WIBO" "$SNCPP" -P src/w1813_c.c "$BUILD/w1813_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1813_c.i" "$BUILD/w1813_c.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1813_c.o" "$BUILD/w1813_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_c.o" private/SLUS_204.86.rom --source src/w1813_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_e.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_e.o" private/SLUS_204.86.rom --source src/w1813_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_f.o" private/SLUS_204.86.rom --source src/w1813_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_g.o" private/SLUS_204.86.rom --source src/w1813_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1813_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_h.o" private/SLUS_204.86.rom --source src/w1813_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1813_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_i.o" private/SLUS_204.86.rom --source src/w1813_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1813_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_j.o" private/SLUS_204.86.rom --source src/w1813_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_k.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_k.o" private/SLUS_204.86.rom --source src/w1813_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1813_l.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w1813_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_l.o" private/SLUS_204.86.rom --source src/w1813_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_m.o" private/SLUS_204.86.rom --source src/w1813_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_o.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1813_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_o.o" private/SLUS_204.86.rom --source src/w1813_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_p.o" private/SLUS_204.86.rom --source src/w1813_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1813_q.c -c -lang c -O3,p -Op -sdatathreshold 8 -o "$BUILD/w1813_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_q.o" private/SLUS_204.86.rom --source src/w1813_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_r.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_r.o" private/SLUS_204.86.rom --source src/w1813_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_u.o" private/SLUS_204.86.rom --source src/w1813_u.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1813_v.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1813_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_v.o" private/SLUS_204.86.rom --source src/w1813_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_w.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1813_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_w.o" private/SLUS_204.86.rom --source src/w1813_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1813_x.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1813_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_x.o" private/SLUS_204.86.rom --source src/w1813_x.c
"$WIBO" "$SNCPP" -P src/w1813_y.c "$BUILD/w1813_y.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1813_y.i" "$BUILD/w1813_y.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1813_y.o" "$BUILD/w1813_y.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1813_y.o" private/SLUS_204.86.rom --source src/w1813_y.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1810_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_c.o" private/SLUS_204.86.rom --source src/w1810_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_d.o" private/SLUS_204.86.rom --source src/w1810_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_e.o" private/SLUS_204.86.rom --source src/w1810_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_f.o" private/SLUS_204.86.rom --source src/w1810_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_g.o" private/SLUS_204.86.rom --source src/w1810_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1810_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_h.o" private/SLUS_204.86.rom --source src/w1810_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1810_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_i.o" private/SLUS_204.86.rom --source src/w1810_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_j.o" private/SLUS_204.86.rom --source src/w1810_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1810_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_k.o" private/SLUS_204.86.rom --source src/w1810_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_l.o" private/SLUS_204.86.rom --source src/w1810_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_m.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1810_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_m.o" private/SLUS_204.86.rom --source src/w1810_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1810_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1810_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_n.o" private/SLUS_204.86.rom --source src/w1810_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_o.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/w1810_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_o.o" private/SLUS_204.86.rom --source src/w1810_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_p.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/w1810_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_p.o" private/SLUS_204.86.rom --source src/w1810_p.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1810_r.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1810_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_r.o" private/SLUS_204.86.rom --source src/w1810_r.c
"$WIBO" "$SNCPP" -P src/w1810_s.c "$BUILD/w1810_s.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1810_s.i" "$BUILD/w1810_s.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1810_s.o" "$BUILD/w1810_s.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1810_s.o" private/SLUS_204.86.rom --source src/w1810_s.c
"$WIBO" "$SNCPP" -P src/w1811_b.c "$BUILD/w1811_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w1811_b.i" "$BUILD/w1811_b.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w1811_b.o" "$BUILD/w1811_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_b.o" private/SLUS_204.86.rom --source src/w1811_b.c
"$WIBO" "$SNCPP" -P src/w1811_e.c "$BUILD/w1811_e.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="-fno-schedule-insns" "$BUILD/w1811_e.i" "$BUILD/w1811_e.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w1811_e.o" "$BUILD/w1811_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_e.o" private/SLUS_204.86.rom --source src/w1811_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_g.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1811_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_g.o" private/SLUS_204.86.rom --source src/w1811_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1811_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_h.o" private/SLUS_204.86.rom --source src/w1811_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1811_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_j.o" private/SLUS_204.86.rom --source src/w1811_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1811_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_k.o" private/SLUS_204.86.rom --source src/w1811_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1811_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_l.o" private/SLUS_204.86.rom --source src/w1811_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1811_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1811_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_m.o" private/SLUS_204.86.rom --source src/w1811_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1811_o.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1811_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_o.o" private/SLUS_204.86.rom --source src/w1811_o.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/animation_move_handlers_0023AAD0_00287220.c -c -lang c \
    -O3 -sdatathreshold 8 -o "$BUILD/animation_move_handlers_0023AAD0_00287220.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/animation_move_handlers_0023AAD0_00287220.o" \
    private/SLUS_204.86.rom \
    --source src/animation_move_handlers_0023AAD0_00287220.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_q.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1811_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_q.o" private/SLUS_204.86.rom --source src/w1811_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_s.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1811_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_s.o" private/SLUS_204.86.rom --source src/w1811_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1811_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_u.o" private/SLUS_204.86.rom --source src/w1811_u.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1811_v.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1811_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_v.o" private/SLUS_204.86.rom --source src/w1811_v.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_x.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1811_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_x.o" private/SLUS_204.86.rom --source src/w1811_x.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1811_y.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1811_y.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1811_y.o" private/SLUS_204.86.rom --source src/w1811_y.c
"$WIBO" "$SNCPP" -P src/w188_a.c "$BUILD/w188_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w188_a.i" "$BUILD/w188_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w188_a.o" "$BUILD/w188_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w188_a.o" private/SLUS_204.86.rom --source src/w188_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w188_b.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w188_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_b.o" private/SLUS_204.86.rom --source src/w188_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w188_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w188_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_c.o" private/SLUS_204.86.rom --source src/w188_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w188_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w188_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_d.o" private/SLUS_204.86.rom --source src/w188_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w188_e.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w188_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_e.o" private/SLUS_204.86.rom --source src/w188_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w188_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w188_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_g.o" private/SLUS_204.86.rom --source src/w188_g.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w188_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w188_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_h.o" private/SLUS_204.86.rom --source src/w188_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w188_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w188_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w188_j.o" private/SLUS_204.86.rom --source src/w188_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1812_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_a.o" private/SLUS_204.86.rom --source src/w1812_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_callback_00163F90.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/dispatch_callback_00163F90.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_callback_00163F90.o" \
    private/SLUS_204.86.rom --source src/dispatch_callback_00163F90.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1812_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_b.o" private/SLUS_204.86.rom --source src/w1812_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1812_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_c.o" private/SLUS_204.86.rom --source src/w1812_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_flight_update_002A4D30.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/animation_flight_update_002A4D30.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_flight_update_002A4D30.o" \
    private/SLUS_204.86.rom --source src/animation_flight_update_002A4D30.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1812_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1812_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_d.o" private/SLUS_204.86.rom --source src/w1812_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_e.c -c -lang c -O3 -Op -fp off -sdatathreshold 8 -o "$BUILD/w1812_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_e.o" private/SLUS_204.86.rom --source src/w1812_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w1812_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_f.o" private/SLUS_204.86.rom --source src/w1812_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1812_g.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1812_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_g.o" private/SLUS_204.86.rom --source src/w1812_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1812_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1812_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_h.o" private/SLUS_204.86.rom --source src/w1812_h.c
"$WIBO" "$SNCPP" -P src/w1812_i.c "$BUILD/w1812_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1812_i.i" "$BUILD/w1812_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1812_i.o" "$BUILD/w1812_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1812_i.o" private/SLUS_204.86.rom --source src/w1812_i.c
"$WIBO" "$SNCPP" -P src/w189_a.c "$BUILD/w189_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w189_a.i" "$BUILD/w189_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w189_a.o" "$BUILD/w189_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w189_a.o" private/SLUS_204.86.rom --source src/w189_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w189_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_b.o" private/SLUS_204.86.rom --source src/w189_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w189_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_c.o" private/SLUS_204.86.rom --source src/w189_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w189_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w189_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_d.o" private/SLUS_204.86.rom --source src/w189_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_e.c -c -lang c -O3 -Op -sdatathreshold 256 -o "$BUILD/w189_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_e.o" private/SLUS_204.86.rom --source src/w189_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w189_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_f.o" private/SLUS_204.86.rom --source src/w189_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w189_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w189_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_h.o" private/SLUS_204.86.rom --source src/w189_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_i.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w189_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_i.o" private/SLUS_204.86.rom --source src/w189_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_j.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/w189_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_j.o" private/SLUS_204.86.rom --source src/w189_j.c
"$WIBO" "$SNCPP" -P src/w189_k.c "$BUILD/w189_k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/w189_k.i" "$BUILD/w189_k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w189_k.o" "$BUILD/w189_k.s"
"$PYTHON" tools/verify_object.py "$BUILD/w189_k.o" private/SLUS_204.86.rom --source src/w189_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w189_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w189_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w189_l.o" private/SLUS_204.86.rom --source src/w189_l.c

"$WIBO" "$SNCPP" -P src/sony29_message_dispatch.c "$BUILD/sony29_message_dispatch.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_message_dispatch.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_message_dispatch.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_message_dispatch.o" "$BUILD/sony29_message_dispatch.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_message_dispatch.o" private/SLUS_204.86.rom --source src/sony29_message_dispatch.c

"$WIBO" "$SNCPP" -P src/sony29_handler_registration.c "$BUILD/sony29_handler_registration.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_handler_registration.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_handler_registration.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_handler_registration.o" "$BUILD/sony29_handler_registration.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_handler_registration.o" private/SLUS_204.86.rom --source src/sony29_handler_registration.c

"$WIBO" "$SNCPP" -P src/side_packet_dispatch_001023C8.c "$BUILD/side_packet_dispatch_001023C8.i"
"$WIBO" "$EE29CC1" "$BUILD/side_packet_dispatch_001023C8.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/side_packet_dispatch_001023C8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/side_packet_dispatch_001023C8.o" "$BUILD/side_packet_dispatch_001023C8.s"
"$PYTHON" tools/verify_object.py "$BUILD/side_packet_dispatch_001023C8.o" private/SLUS_204.86.rom --source src/side_packet_dispatch_001023C8.c

"$WIBO" "$SNCPP" -P src/sony29_rpc_initialize.c "$BUILD/sony29_rpc_initialize.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_rpc_initialize.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_rpc_initialize.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_rpc_initialize.o" "$BUILD/sony29_rpc_initialize.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_rpc_initialize.o" private/SLUS_204.86.rom --source src/sony29_rpc_initialize.c

"$WIBO" "$SNCPP" -P src/sony29_rpc_compatibility.c "$BUILD/sony29_rpc_compatibility.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_rpc_compatibility.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_rpc_compatibility.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_rpc_compatibility.o" "$BUILD/sony29_rpc_compatibility.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_rpc_compatibility.o" private/SLUS_204.86.rom --source src/sony29_rpc_compatibility.c

"$WIBO" "$SNCPP" -P src/record_threshold_poll_00102498.c "$BUILD/record_threshold_poll_00102498.i"
"$WIBO" "$EE29CC1" "$BUILD/record_threshold_poll_00102498.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/record_threshold_poll_00102498.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/record_threshold_poll_00102498.o" "$BUILD/record_threshold_poll_00102498.s"
"$PYTHON" tools/verify_object.py "$BUILD/record_threshold_poll_00102498.o" private/SLUS_204.86.rom --source src/record_threshold_poll_00102498.c

"$WIBO" "$SNCPP" -P src/sony29_word_copies.c "$BUILD/sony29_word_copies.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_word_copies.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_word_copies.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_word_copies.o" "$BUILD/sony29_word_copies.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_word_copies.o" private/SLUS_204.86.rom --source src/sony29_word_copies.c

"$WIBO" "$SNCPP" -P src/sony29_wait_idle.c "$BUILD/sony29_wait_idle.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_wait_idle.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_wait_idle.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_wait_idle.o" "$BUILD/sony29_wait_idle.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_wait_idle.o" private/SLUS_204.86.rom --source src/sony29_wait_idle.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_pair_value_timers_00190130.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/update_pair_value_timers_00190130.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_pair_value_timers_00190130.o" private/SLUS_204.86.rom --source src/update_pair_value_timers_00190130.c

"$WIBO" "$SNCPP" -P src/ee96_o1_wrappers.c "$BUILD/ee96_o1_wrappers.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O1 "$BUILD/ee96_o1_wrappers.i" "$BUILD/ee96_o1_wrappers.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/ee96_o1_wrappers.o" "$BUILD/ee96_o1_wrappers.s"
"$PYTHON" tools/verify_object.py "$BUILD/ee96_o1_wrappers.o" private/SLUS_204.86.rom --source src/ee96_o1_wrappers.c

"$WIBO" "$SNCPP" -P src/sony29_status_resets.c "$BUILD/sony29_status_resets.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_status_resets.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_status_resets.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_status_resets.o" "$BUILD/sony29_status_resets.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_status_resets.o" private/SLUS_204.86.rom --source src/sony29_status_resets.c

"$WIBO" "$SNCPP" -P src/sony29_scalar_wrappers.c "$BUILD/sony29_scalar_wrappers.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_scalar_wrappers.i" -O2 -G0 -ffunction-sections -quiet -o "$BUILD/sony29_scalar_wrappers.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_scalar_wrappers.o" "$BUILD/sony29_scalar_wrappers.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_scalar_wrappers.o" private/SLUS_204.86.rom --source src/sony29_scalar_wrappers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_entity_state_002004B0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_entity_state_002004B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_entity_state_002004B0.o" private/SLUS_204.86.rom --source src/initialize_entity_state_002004B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_attachment_00201A80.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_actor_attachment_00201A80.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_attachment_00201A80.o" private/SLUS_204.86.rom --source src/initialize_actor_attachment_00201A80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_state_00200960.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/dispatch_runtime_state_00200960.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_state_00200960.o" private/SLUS_204.86.rom --source src/dispatch_runtime_state_00200960.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_entity_attachment_00202CA0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/initialize_entity_attachment_00202CA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_entity_attachment_00202CA0.o" private/SLUS_204.86.rom --source src/initialize_entity_attachment_00202CA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_entity_motion_state_00202860.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/update_entity_motion_state_00202860.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_entity_motion_state_00202860.o" private/SLUS_204.86.rom --source src/update_entity_motion_state_00202860.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/advance_entity_motion_state_002029D0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/advance_entity_motion_state_002029D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/advance_entity_motion_state_002029D0.o" private/SLUS_204.86.rom --source src/advance_entity_motion_state_002029D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_runtime_update_00203360.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/dispatch_runtime_update_00203360.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_runtime_update_00203360.o" private/SLUS_204.86.rom --source src/dispatch_runtime_update_00203360.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_interaction_flags_00167700.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/select_interaction_flags_00167700.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_interaction_flags_00167700.o" \
    private/SLUS_204.86.rom --source src/select_interaction_flags_00167700.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_launch_0021F740.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/initialize_actor_launch_0021F740.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_launch_0021F740.o" \
    private/SLUS_204.86.rom --source src/initialize_actor_launch_0021F740.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_launch_0021F8E0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/initialize_actor_launch_0021F8E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_launch_0021F8E0.o" \
    private/SLUS_204.86.rom --source src/initialize_actor_launch_0021F8E0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/initialize_parent_actor_00378E90.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/initialize_parent_actor_00378E90.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_parent_actor_00378E90.o" \
    private/SLUS_204.86.rom --source src/initialize_parent_actor_00378E90.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/setup_entity_motion_state_00207AC0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/setup_entity_motion_state_00207AC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/setup_entity_motion_state_00207AC0.o" private/SLUS_204.86.rom --source src/setup_entity_motion_state_00207AC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_interaction_variant_00349320.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/initialize_interaction_variant_00349320.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_interaction_variant_00349320.o" \
    private/SLUS_204.86.rom --source src/initialize_interaction_variant_00349320.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/advance_entity_attachment_event_00207C80.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/advance_entity_attachment_event_00207C80.o"
"$PYTHON" tools/verify_object.py "$BUILD/advance_entity_attachment_event_00207C80.o" private/SLUS_204.86.rom --source src/advance_entity_attachment_event_00207C80.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w187_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_e.o" private/SLUS_204.86.rom --source src/w187_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_f.o" private/SLUS_204.86.rom --source src/w187_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_h.o" private/SLUS_204.86.rom --source src/w187_h.c
"$WIBO" "$SNCPP" -P src/w187_i.c "$BUILD/w187_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w187_i.i" "$BUILD/w187_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w187_i.o" "$BUILD/w187_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/w187_i.o" private/SLUS_204.86.rom --source src/w187_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w187_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_j.o" private/SLUS_204.86.rom --source src/w187_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_l.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w187_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_l.o" private/SLUS_204.86.rom --source src/w187_l.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w187_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_m.o" private/SLUS_204.86.rom --source src/w187_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_n.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w187_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_n.o" private/SLUS_204.86.rom --source src/w187_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_q.o" private/SLUS_204.86.rom --source src/w187_q.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_r.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w187_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_r.o" private/SLUS_204.86.rom --source src/w187_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_s.o" private/SLUS_204.86.rom --source src/w187_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_t.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_t.o" private/SLUS_204.86.rom --source src/w187_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_u.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w187_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_u.o" private/SLUS_204.86.rom --source src/w187_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_v.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w187_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_v.o" private/SLUS_204.86.rom --source src/w187_v.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_w.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/w187_w.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_w.o" private/SLUS_204.86.rom --source src/w187_w.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_x.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w187_x.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_x.o" private/SLUS_204.86.rom --source src/w187_x.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_y.c -c -lang c -O3,p -Op -sdatathreshold 0 -o "$BUILD/w187_y.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_y.o" private/SLUS_204.86.rom --source src/w187_y.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w187_z.c -c -lang c -O3 -Op -fp off -sdatathreshold 0 -o "$BUILD/w187_z.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_z.o" private/SLUS_204.86.rom --source src/w187_z.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w187_aa.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w187_aa.o"
"$PYTHON" tools/verify_object.py "$BUILD/w187_aa.o" private/SLUS_204.86.rom --source src/w187_aa.c
"$WIBO" "$SNCPP" -P src/sony29_b.c "$BUILD/sony29_b.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_b.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_b.o" "$BUILD/sony29_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_b.o" private/SLUS_204.86.rom --source src/sony29_b.c
"$WIBO" "$SNCPP" -P src/sony29_e.c "$BUILD/sony29_e.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_e.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_e.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_e.o" "$BUILD/sony29_e.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_e.o" private/SLUS_204.86.rom --source src/sony29_e.c
"$WIBO" "$SNCPP" -P src/sony29_f.c "$BUILD/sony29_f.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_f.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_f.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_f.o" "$BUILD/sony29_f.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_f.o" private/SLUS_204.86.rom --source src/sony29_f.c
"$WIBO" "$SNCPP" -P src/sony29_h.c "$BUILD/sony29_h.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_h.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_h.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_h.o" "$BUILD/sony29_h.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_h.o" private/SLUS_204.86.rom --source src/sony29_h.c
"$WIBO" "$SNCPP" -P src/sony29_i.c "$BUILD/sony29_i.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_i.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_i.o" "$BUILD/sony29_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_i.o" private/SLUS_204.86.rom --source src/sony29_i.c
"$WIBO" "$SNCPP" -P src/sony29_j.c "$BUILD/sony29_j.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_j.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_j.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_j.o" "$BUILD/sony29_j.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_j.o" private/SLUS_204.86.rom --source src/sony29_j.c
"$WIBO" "$SNCPP" -P src/sony29_k.c "$BUILD/sony29_k.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_k.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_k.o" "$BUILD/sony29_k.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_k.o" private/SLUS_204.86.rom --source src/sony29_k.c
"$WIBO" "$SNCPP" -P src/sony29_l.c "$BUILD/sony29_l.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_l.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_l.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_l.o" "$BUILD/sony29_l.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_l.o" private/SLUS_204.86.rom --source src/sony29_l.c
"$WIBO" "$SNCPP" -P src/sony29_n.c "$BUILD/sony29_n.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_n.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_n.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_n.o" "$BUILD/sony29_n.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_n.o" private/SLUS_204.86.rom --source src/sony29_n.c
"$WIBO" "$SNCPP" -P src/sony29_o.c "$BUILD/sony29_o.i"
"$WIBO" "$EE29CC1" "$BUILD/sony29_o.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/sony29_o.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/sony29_o.o" "$BUILD/sony29_o.s"
"$PYTHON" tools/verify_object.py "$BUILD/sony29_o.o" private/SLUS_204.86.rom --source src/sony29_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_a.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w196_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_a.o" private/SLUS_204.86.rom --source src/w196_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w196_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_b.o" private/SLUS_204.86.rom --source src/w196_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_c.o" private/SLUS_204.86.rom --source src/w196_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w196_d.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w196_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_d.o" private/SLUS_204.86.rom --source src/w196_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_e.o" private/SLUS_204.86.rom --source src/w196_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_f.o" private/SLUS_204.86.rom --source src/w196_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w196_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_g.o" private/SLUS_204.86.rom --source src/w196_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_h.o" private/SLUS_204.86.rom --source src/w196_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_j.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w196_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_j.o" private/SLUS_204.86.rom --source src/w196_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_k.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w196_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_k.o" private/SLUS_204.86.rom --source src/w196_k.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w196_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w196_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_l.o" private/SLUS_204.86.rom --source src/w196_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w196_m.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w196_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w196_m.o" private/SLUS_204.86.rom --source src/w196_m.c
"$WIBO" "$SNCPP" -P src/w196_n.c "$BUILD/w196_n.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w196_n.i" "$BUILD/w196_n.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w196_n.o" "$BUILD/w196_n.s"
"$PYTHON" tools/verify_object.py "$BUILD/w196_n.o" private/SLUS_204.86.rom --source src/w196_n.c
"$WIBO" "$SNCPP" -P src/w196_o.c "$BUILD/w196_o.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w196_o.i" "$BUILD/w196_o.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w196_o.o" "$BUILD/w196_o.s"
"$PYTHON" tools/verify_object.py "$BUILD/w196_o.o" private/SLUS_204.86.rom --source src/w196_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w198_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w198_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_a.o" private/SLUS_204.86.rom --source src/w198_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w198_c.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w198_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_c.o" private/SLUS_204.86.rom --source src/w198_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w198_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w198_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_d.o" private/SLUS_204.86.rom --source src/w198_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w198_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w198_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_e.o" private/SLUS_204.86.rom --source src/w198_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w198_f.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w198_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_f.o" private/SLUS_204.86.rom --source src/w198_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w198_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w198_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w198_g.o" private/SLUS_204.86.rom --source src/w198_g.c
"$WIBO" "$SNCPP" -P src/w198_i.c "$BUILD/w198_i.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w198_i.i" "$BUILD/w198_i.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w198_i.o" "$BUILD/w198_i.s"
"$PYTHON" tools/verify_object.py "$BUILD/w198_i.o" private/SLUS_204.86.rom --source src/w198_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_d.o" private/SLUS_204.86.rom --source src/w1910_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1910_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_e.o" private/SLUS_204.86.rom --source src/w1910_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1910_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_f.o" private/SLUS_204.86.rom --source src/w1910_f.c
"$WIBO" "$SNCPP" -P src/w1910_g.c "$BUILD/w1910_g.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1910_g.i" "$BUILD/w1910_g.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1910_g.o" "$BUILD/w1910_g.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_g.o" private/SLUS_204.86.rom --source src/w1910_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_h.o" private/SLUS_204.86.rom --source src/w1910_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1910_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_i.o" private/SLUS_204.86.rom --source src/w1910_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1910_j.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1910_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_j.o" private/SLUS_204.86.rom --source src/w1910_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1910_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1910_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_k.o" private/SLUS_204.86.rom --source src/w1910_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1910_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_l.o" private/SLUS_204.86.rom --source src/w1910_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_m.o" private/SLUS_204.86.rom --source src/w1910_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_o.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1910_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_o.o" private/SLUS_204.86.rom --source src/w1910_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1910_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_p.o" private/SLUS_204.86.rom --source src/w1910_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1910_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_q.o" private/SLUS_204.86.rom --source src/w1910_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_s.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1910_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_s.o" private/SLUS_204.86.rom --source src/w1910_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_t.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_t.o" private/SLUS_204.86.rom --source src/w1910_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_u.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_u.o" private/SLUS_204.86.rom --source src/w1910_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1910_v.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1910_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1910_v.o" private/SLUS_204.86.rom --source src/w1910_v.c
"$WIBO" "$SNCPP" -P src/w1912_b.c "$BUILD/w1912_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1912_b.i" "$BUILD/w1912_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1912_b.o" "$BUILD/w1912_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_b.o" private/SLUS_204.86.rom --source src/w1912_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1912_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_c.o" private/SLUS_204.86.rom --source src/w1912_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_d.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1912_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_d.o" private/SLUS_204.86.rom --source src/w1912_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1912_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_e.o" private/SLUS_204.86.rom --source src/w1912_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1912_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_f.o" private/SLUS_204.86.rom --source src/w1912_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w1912_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_g.o" private/SLUS_204.86.rom --source src/w1912_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1912_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_h.o" private/SLUS_204.86.rom --source src/w1912_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1912_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_i.o" private/SLUS_204.86.rom --source src/w1912_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1912_k.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1912_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_k.o" private/SLUS_204.86.rom --source src/w1912_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1912_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_l.o" private/SLUS_204.86.rom --source src/w1912_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1912_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_m.o" private/SLUS_204.86.rom --source src/w1912_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_n.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1912_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_n.o" private/SLUS_204.86.rom --source src/w1912_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1912_p.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1912_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_p.o" private/SLUS_204.86.rom --source src/w1912_p.c
"$WIBO" "$SNCPP" -P src/w1912_q.c "$BUILD/w1912_q.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1912_q.i" "$BUILD/w1912_q.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1912_q.o" "$BUILD/w1912_q.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_q.o" private/SLUS_204.86.rom --source src/w1912_q.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1912_r.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1912_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1912_r.o" private/SLUS_204.86.rom --source src/w1912_r.c
"$WIBO" "$SNCPP" -P src/w194_a.c "$BUILD/w194_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w194_a.i" "$BUILD/w194_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w194_a.o" "$BUILD/w194_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w194_a.o" private/SLUS_204.86.rom --source src/w194_a.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w194_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w194_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_c.o" private/SLUS_204.86.rom --source src/w194_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w194_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_d.o" private/SLUS_204.86.rom --source src/w194_d.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w194_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_e.o" private/SLUS_204.86.rom --source src/w194_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_f.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w194_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_f.o" private/SLUS_204.86.rom --source src/w194_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_g.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_g.o" private/SLUS_204.86.rom --source src/w194_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_i.o" private/SLUS_204.86.rom --source src/w194_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w194_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w194_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_j.o" private/SLUS_204.86.rom --source src/w194_j.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w194_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_l.o" private/SLUS_204.86.rom --source src/w194_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_m.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w194_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_m.o" private/SLUS_204.86.rom --source src/w194_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w194_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_n.o" private/SLUS_204.86.rom --source src/w194_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_o.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w194_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_o.o" private/SLUS_204.86.rom --source src/w194_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_p.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w194_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_p.o" private/SLUS_204.86.rom --source src/w194_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w194_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w194_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w194_q.o" private/SLUS_204.86.rom --source src/w194_q.c
"$WIBO" "$SNCPP" -P src/w192_c.c "$BUILD/w192_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w192_c.i" "$BUILD/w192_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w192_c.o" "$BUILD/w192_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w192_c.o" private/SLUS_204.86.rom --source src/w192_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_d.o" private/SLUS_204.86.rom --source src/w192_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_h.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_h.o" private/SLUS_204.86.rom --source src/w192_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w192_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_i.o" private/SLUS_204.86.rom --source src/w192_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_j.o" private/SLUS_204.86.rom --source src/w192_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w192_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_l.o" private/SLUS_204.86.rom --source src/w192_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_n.o" private/SLUS_204.86.rom --source src/w192_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w192_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w192_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_o.o" private/SLUS_204.86.rom --source src/w192_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_q.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_q.o" private/SLUS_204.86.rom --source src/w192_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_r.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w192_r.o"
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" \
    --redefine-sym @18=jtbl_004B73E0 \
    --redefine-sym @46=jtbl_004B7410 \
    --redefine-sym @64=jtbl_004B7440 \
    --redefine-sym @92=jtbl_004B7470 \
    "$BUILD/w192_r.o" "$BUILD/w192_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_r.o" private/SLUS_204.86.rom --source src/w192_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w192_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_s.o" private/SLUS_204.86.rom --source src/w192_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_t.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w192_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_t.o" private/SLUS_204.86.rom --source src/w192_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/animation_displacement_002A4290.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/animation_displacement_002A4290.o"
"$PYTHON" tools/verify_object.py "$BUILD/animation_displacement_002A4290.o" \
    private/SLUS_204.86.rom --source src/animation_displacement_002A4290.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w192_u.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w192_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w192_u.o" private/SLUS_204.86.rom --source src/w192_u.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1913_a.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1913_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1913_a.o" private/SLUS_204.86.rom --source src/w1913_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1913_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1913_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1913_b.o" private/SLUS_204.86.rom --source src/w1913_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1913_c.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w1913_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1913_c.o" private/SLUS_204.86.rom --source src/w1913_c.c
"$WIBO" "$SNCPP" -P src/w197_a.c "$BUILD/w197_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w197_a.i" "$BUILD/w197_a.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w197_a.o" "$BUILD/w197_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w197_a.o" private/SLUS_204.86.rom --source src/w197_a.c
"$WIBO" "$SNCPP" -P src/w197_c.c "$BUILD/w197_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w197_c.i" "$BUILD/w197_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w197_c.o" "$BUILD/w197_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w197_c.o" private/SLUS_204.86.rom --source src/w197_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_d.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w197_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_d.o" private/SLUS_204.86.rom --source src/w197_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_e.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_e.o" private/SLUS_204.86.rom --source src/w197_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_h.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_h.o" private/SLUS_204.86.rom --source src/w197_h.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w197_i.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w197_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_i.o" private/SLUS_204.86.rom --source src/w197_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_j.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w197_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_j.o" private/SLUS_204.86.rom --source src/w197_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_k.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_k.o" private/SLUS_204.86.rom --source src/w197_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_l.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_l.o" private/SLUS_204.86.rom --source src/w197_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_m.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w197_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_m.o" private/SLUS_204.86.rom --source src/w197_m.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w197_n.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w197_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_n.o" private/SLUS_204.86.rom --source src/w197_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_p.o" private/SLUS_204.86.rom --source src/w197_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w197_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w197_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w197_q.o" private/SLUS_204.86.rom --source src/w197_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w199_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w199_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_b.o" private/SLUS_204.86.rom --source src/w199_b.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w199_c.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w199_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_c.o" private/SLUS_204.86.rom --source src/w199_c.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w199_d.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w199_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_d.o" private/SLUS_204.86.rom --source src/w199_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w199_e.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w199_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_e.o" private/SLUS_204.86.rom --source src/w199_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w199_f.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w199_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_f.o" private/SLUS_204.86.rom --source src/w199_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w199_h.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w199_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_h.o" private/SLUS_204.86.rom --source src/w199_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w199_k.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w199_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w199_k.o" private/SLUS_204.86.rom --source src/w199_k.c
"$WIBO" "$SNCPP" -P src/w199_m.c "$BUILD/w199_m.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w199_m.i" "$BUILD/w199_m.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w199_m.o" "$BUILD/w199_m.s"
"$PYTHON" tools/verify_object.py "$BUILD/w199_m.o" private/SLUS_204.86.rom --source src/w199_m.c
"$WIBO" "$SNCPP" -P src/w191_a.c "$BUILD/w191_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w191_a.i" "$BUILD/w191_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w191_a.o" "$BUILD/w191_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w191_a.o" private/SLUS_204.86.rom --source src/w191_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_b.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w191_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_b.o" private/SLUS_204.86.rom --source src/w191_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w191_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_e.o" private/SLUS_204.86.rom --source src/w191_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_h.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w191_h.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_h.o" private/SLUS_204.86.rom --source src/w191_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_i.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w191_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_i.o" private/SLUS_204.86.rom --source src/w191_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_k.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w191_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_k.o" private/SLUS_204.86.rom --source src/w191_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_l.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w191_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_l.o" private/SLUS_204.86.rom --source src/w191_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w191_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_m.o" private/SLUS_204.86.rom --source src/w191_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w191_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_n.o" private/SLUS_204.86.rom --source src/w191_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_o.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w191_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_o.o" private/SLUS_204.86.rom --source src/w191_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w191_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_q.o" private/SLUS_204.86.rom --source src/w191_q.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_r.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w191_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_r.o" private/SLUS_204.86.rom --source src/w191_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w191_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w191_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_s.o" private/SLUS_204.86.rom --source src/w191_s.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w191_t.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w191_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_t.o" private/SLUS_204.86.rom --source src/w191_t.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w191_v.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w191_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w191_v.o" private/SLUS_204.86.rom --source src/w191_v.c
"$WIBO" "$SNCPP" -P src/w190_a.c "$BUILD/w190_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w190_a.i" "$BUILD/w190_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w190_a.o" "$BUILD/w190_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w190_a.o" private/SLUS_204.86.rom --source src/w190_a.c
"$WIBO" "$SNCPP" -P src/w190_h.c "$BUILD/w190_h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w190_h.i" "$BUILD/w190_h.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w190_h.o" "$BUILD/w190_h.s"
"$PYTHON" tools/verify_object.py "$BUILD/w190_h.o" private/SLUS_204.86.rom --source src/w190_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w190_b.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w190_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w190_b.o" private/SLUS_204.86.rom --source src/w190_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w190_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w190_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w190_c.o" private/SLUS_204.86.rom --source src/w190_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w190_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w190_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w190_e.o" private/SLUS_204.86.rom --source src/w190_e.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w190_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w190_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w190_f.o" private/SLUS_204.86.rom --source src/w190_f.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w190_g.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w190_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w190_g.o" private/SLUS_204.86.rom --source src/w190_g.c
"$WIBO" "$SNCPP" -P src/w193_b.c "$BUILD/w193_b.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w193_b.i" "$BUILD/w193_b.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w193_b.o" "$BUILD/w193_b.s"
"$PYTHON" tools/verify_object.py "$BUILD/w193_b.o" private/SLUS_204.86.rom --source src/w193_b.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w193_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w193_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w193_c.o" private/SLUS_204.86.rom --source src/w193_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w193_d.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w193_d.o"
"$PYTHON" tools/verify_object.py "$BUILD/w193_d.o" private/SLUS_204.86.rom --source src/w193_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w193_e.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w193_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w193_e.o" private/SLUS_204.86.rom --source src/w193_e.c
"$WIBO" "$SNCPP" -P src/w193_f.c "$BUILD/w193_f.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w193_f.i" "$BUILD/w193_f.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w193_f.o" "$BUILD/w193_f.s"
"$PYTHON" tools/verify_object.py "$BUILD/w193_f.o" private/SLUS_204.86.rom --source src/w193_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_a.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w195_a.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_a.o" private/SLUS_204.86.rom --source src/w195_a.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_c.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w195_c.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_c.o" private/SLUS_204.86.rom --source src/w195_c.c
"$WIBO" "$SNCPP" -P src/w195_d.c "$BUILD/w195_d.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w195_d.i" "$BUILD/w195_d.s"
"$WIBO" "$SNAS" -mips4 -G0 -o "$BUILD/w195_d.o" "$BUILD/w195_d.s"
"$PYTHON" tools/verify_object.py "$BUILD/w195_d.o" private/SLUS_204.86.rom --source src/w195_d.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_f.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w195_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_f.o" private/SLUS_204.86.rom --source src/w195_f.c
"$WIBO" "$SNCPP" -P src/w195_h.c "$BUILD/w195_h.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w195_h.i" "$BUILD/w195_h.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w195_h.o" "$BUILD/w195_h.s"
"$PYTHON" tools/verify_object.py "$BUILD/w195_h.o" private/SLUS_204.86.rom --source src/w195_h.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_i.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w195_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_i.o" private/SLUS_204.86.rom --source src/w195_i.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_j.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w195_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_j.o" private/SLUS_204.86.rom --source src/w195_j.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_k.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w195_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_k.o" private/SLUS_204.86.rom --source src/w195_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w195_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_l.o" private/SLUS_204.86.rom --source src/w195_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_n.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w195_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_n.o" private/SLUS_204.86.rom --source src/w195_n.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_p.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w195_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_p.o" private/SLUS_204.86.rom --source src/w195_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_q.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/w195_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_q.o" private/SLUS_204.86.rom --source src/w195_q.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w195_r.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w195_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_r.o" private/SLUS_204.86.rom --source src/w195_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w195_s.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w195_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w195_s.o" private/SLUS_204.86.rom --source src/w195_s.c
"$WIBO" "$SNCPP" -P src/w195_a2.c "$BUILD/w195_a2.i"
"$WIBO" "$EE29CC1" "$BUILD/w195_a2.i" -O2 -G0 -ffunction-sections  -quiet -o "$BUILD/w195_a2.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w195_a2.o" "$BUILD/w195_a2.s"
"$PYTHON" tools/verify_object.py "$BUILD/w195_a2.o" private/SLUS_204.86.rom --source src/w195_a2.c
"$WIBO" "$SNCPP" -P src/w1911_a.c "$BUILD/w1911_a.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/w1911_a.i" "$BUILD/w1911_a.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1911_a.o" "$BUILD/w1911_a.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_a.o" private/SLUS_204.86.rom --source src/w1911_a.c
"$WIBO" "$SNCPP" -P src/fp_bit_add_parts_001192B0.c "$BUILD/fp_bit_add_parts_001192B0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/fp_bit_add_parts_001192B0.i" "$BUILD/fp_bit_add_parts_001192B0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/fp_bit_add_parts_001192B0.o" "$BUILD/fp_bit_add_parts_001192B0.s"
"$PYTHON" tools/verify_object.py "$BUILD/fp_bit_add_parts_001192B0.o" private/SLUS_204.86.rom --source src/fp_bit_add_parts_001192B0.c
"$WIBO" "$SNCPP" -P src/fp_bit_multiply_001195D0.c "$BUILD/fp_bit_multiply_001195D0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/fp_bit_multiply_001195D0.i" "$BUILD/fp_bit_multiply_001195D0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/fp_bit_multiply_001195D0.o" "$BUILD/fp_bit_multiply_001195D0.s"
"$PYTHON" tools/verify_object.py "$BUILD/fp_bit_multiply_001195D0.o" private/SLUS_204.86.rom --source src/fp_bit_multiply_001195D0.c
"$WIBO" "$SNCPP" -P src/fp_bit_pack_double_00119118.c "$BUILD/fp_bit_pack_double_00119118.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/fp_bit_pack_double_00119118.i" "$BUILD/fp_bit_pack_double_00119118.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/fp_bit_pack_double_00119118.o" "$BUILD/fp_bit_pack_double_00119118.s"
"$PYTHON" tools/verify_object.py "$BUILD/fp_bit_pack_double_00119118.o" private/SLUS_204.86.rom --source src/fp_bit_pack_double_00119118.c
"$WIBO" "$SNCPP" -P src/fp_bit_divide_double_00119858.c "$BUILD/fp_bit_divide_double_00119858.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/fp_bit_divide_double_00119858.i" "$BUILD/fp_bit_divide_double_00119858.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/fp_bit_divide_double_00119858.o" "$BUILD/fp_bit_divide_double_00119858.s"
"$PYTHON" tools/verify_object.py "$BUILD/fp_bit_divide_double_00119858.o" private/SLUS_204.86.rom --source src/fp_bit_divide_double_00119858.c
"$WIBO" "$SNCPP" -P src/newlib_sflags_0011B838.c "$BUILD/newlib_sflags_0011B838.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_sflags_0011B838.i" "$BUILD/newlib_sflags_0011B838.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_sflags_0011B838.o" "$BUILD/newlib_sflags_0011B838.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_sflags_0011B838.o" private/SLUS_204.86.rom --source src/newlib_sflags_0011B838.c
"$WIBO" "$SNCPP" -P src/newlib_sbprintf_00120900.c "$BUILD/newlib_sbprintf_00120900.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_sbprintf_00120900.i" "$BUILD/newlib_sbprintf_00120900.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_sbprintf_00120900.o" "$BUILD/newlib_sbprintf_00120900.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_sbprintf_00120900.o" private/SLUS_204.86.rom --source src/newlib_sbprintf_00120900.c
"$WIBO" "$SNCPP" -P src/newlib_vfprintf_entry_001209B8.c "$BUILD/newlib_vfprintf_entry_001209B8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_vfprintf_entry_001209B8.i" "$BUILD/newlib_vfprintf_entry_001209B8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_vfprintf_entry_001209B8.o" "$BUILD/newlib_vfprintf_entry_001209B8.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_vfprintf_entry_001209B8.o" private/SLUS_204.86.rom --source src/newlib_vfprintf_entry_001209B8.c
"$WIBO" "$SNCPP" -P src/string_stream_printf_00122340.c "$BUILD/string_stream_printf_00122340.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/string_stream_printf_00122340.i" "$BUILD/string_stream_printf_00122340.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/string_stream_printf_00122340.o" "$BUILD/string_stream_printf_00122340.s"
"$PYTHON" tools/verify_object.py "$BUILD/string_stream_printf_00122340.o" private/SLUS_204.86.rom --source src/string_stream_printf_00122340.c
"$WIBO" "$SNCPP" -P src/newlib_fflush_0011B480.c "$BUILD/newlib_fflush_0011B480.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_fflush_0011B480.i" "$BUILD/newlib_fflush_0011B480.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_fflush_0011B480.o" "$BUILD/newlib_fflush_0011B480.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_fflush_0011B480.o" private/SLUS_204.86.rom --source src/newlib_fflush_0011B480.c
"$WIBO" "$SNCPP" -P src/newlib_wsetup_00122560.c "$BUILD/newlib_wsetup_00122560.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_wsetup_00122560.i" "$BUILD/newlib_wsetup_00122560.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_wsetup_00122560.o" "$BUILD/newlib_wsetup_00122560.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_wsetup_00122560.o" private/SLUS_204.86.rom --source src/newlib_wsetup_00122560.c
"$WIBO" "$SNCPP" -P src/newlib_vfprintf_exponent_00122260.c "$BUILD/newlib_vfprintf_exponent_00122260.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_vfprintf_exponent_00122260.i" "$BUILD/newlib_vfprintf_exponent_00122260.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_vfprintf_exponent_00122260.o" "$BUILD/newlib_vfprintf_exponent_00122260.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_vfprintf_exponent_00122260.o" private/SLUS_204.86.rom --source src/newlib_vfprintf_exponent_00122260.c
"$WIBO" "$SNCPP" -P src/newlib_vfprintf_cvt_001220A0.c "$BUILD/newlib_vfprintf_cvt_001220A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_vfprintf_cvt_001220A0.i" "$BUILD/newlib_vfprintf_cvt_001220A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_vfprintf_cvt_001220A0.o" "$BUILD/newlib_vfprintf_cvt_001220A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_vfprintf_cvt_001220A0.o" private/SLUS_204.86.rom --source src/newlib_vfprintf_cvt_001220A0.c
"$WIBO" "$SNCPP" -P src/newlib_fclose_0011B380.c "$BUILD/newlib_fclose_0011B380.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_fclose_0011B380.i" "$BUILD/newlib_fclose_0011B380.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_fclose_0011B380.o" "$BUILD/newlib_fclose_0011B380.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_fclose_0011B380.o" private/SLUS_204.86.rom --source src/newlib_fclose_0011B380.c
"$WIBO" "$SNCPP" -P src/newlib_sfvwrite_0011C458.c "$BUILD/newlib_sfvwrite_0011C458.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_sfvwrite_0011C458.i" "$BUILD/newlib_sfvwrite_0011C458.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_sfvwrite_0011C458.o" "$BUILD/newlib_sfvwrite_0011C458.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_sfvwrite_0011C458.o" private/SLUS_204.86.rom --source src/newlib_sfvwrite_0011C458.c
"$WIBO" "$SNCPP" -P src/newlib_srefill_0011F6D8.c "$BUILD/newlib_srefill_0011F6D8.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_srefill_0011F6D8.i" "$BUILD/newlib_srefill_0011F6D8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_srefill_0011F6D8.o" "$BUILD/newlib_srefill_0011F6D8.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_srefill_0011F6D8.o" private/SLUS_204.86.rom --source src/newlib_srefill_0011F6D8.c
"$WIBO" "$SNCPP" -P src/newlib_dtoa_0011A108.c "$BUILD/newlib_dtoa_0011A108.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/newlib_dtoa_0011A108.i" "$BUILD/newlib_dtoa_0011A108.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_dtoa_0011A108.o" "$BUILD/newlib_dtoa_0011A108.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_dtoa_0011A108.o" private/SLUS_204.86.rom --source src/newlib_dtoa_0011A108.c
"$WIBO" "$SNCPP" -P src/newlib_mprec_helpers.c "$BUILD/newlib_mprec_helpers.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/newlib_mprec_helpers.i" "$BUILD/newlib_mprec_helpers.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_mprec_helpers.o" "$BUILD/newlib_mprec_helpers.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_mprec_helpers.o" private/SLUS_204.86.rom --source src/newlib_mprec_helpers.c
"$WIBO" "$SNCPP" -P src/newlib_strcasecmp_0011FB38.c "$BUILD/newlib_strcasecmp_0011FB38.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" "$BUILD/newlib_strcasecmp_0011FB38.i" "$BUILD/newlib_strcasecmp_0011FB38.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/newlib_strcasecmp_0011FB38.o" "$BUILD/newlib_strcasecmp_0011FB38.s"
"$PYTHON" tools/verify_object.py "$BUILD/newlib_strcasecmp_0011FB38.o" private/SLUS_204.86.rom --source src/newlib_strcasecmp_0011FB38.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_b.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1911_b.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_b.o" private/SLUS_204.86.rom --source src/w1911_b.c
"$WIBO" "$SNCPP" -P src/w1911_c.c "$BUILD/w1911_c.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 --extra-flags="" "$BUILD/w1911_c.i" "$BUILD/w1911_c.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/w1911_c.o" "$BUILD/w1911_c.s"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_c.o" private/SLUS_204.86.rom --source src/w1911_c.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_e.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1911_e.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_e.o" private/SLUS_204.86.rom --source src/w1911_e.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_f.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1911_f.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_f.o" private/SLUS_204.86.rom --source src/w1911_f.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_g.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1911_g.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_g.o" private/SLUS_204.86.rom --source src/w1911_g.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_i.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_i.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_i.o" private/SLUS_204.86.rom --source src/w1911_i.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1911_j.c -c -lang c -O3,p -sdatathreshold 0 -o "$BUILD/w1911_j.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_j.o" private/SLUS_204.86.rom --source src/w1911_j.c
"$WIBO" "$SNCPP" -P src/w1911_k.c "$BUILD/w1911_k.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="-msoft-float" "$BUILD/w1911_k.i" "$BUILD/w1911_k.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/w1911_k.o" "$BUILD/w1911_k.s"
# EE GCC unsigned-double conversion uses the retail unsigned helper.
"${OBJCOPY:-mipsel-linux-gnu-objcopy}" --redefine-sym dptoul=func_00119CE8 "$BUILD/w1911_k.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_k.o" private/SLUS_204.86.rom --source src/w1911_k.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_l.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1911_l.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_l.o" private/SLUS_204.86.rom --source src/w1911_l.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_m.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_m.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_m.o" private/SLUS_204.86.rom --source src/w1911_m.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_n.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/w1911_n.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_n.o" private/SLUS_204.86.rom --source src/w1911_n.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1911_o.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_o.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_o.o" private/SLUS_204.86.rom --source src/w1911_o.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_p.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_p.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_p.o" private/SLUS_204.86.rom --source src/w1911_p.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_q.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_q.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_q.o" private/SLUS_204.86.rom --source src/w1911_q.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1911_r.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1911_r.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_r.o" private/SLUS_204.86.rom --source src/w1911_r.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_s.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/w1911_s.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_s.o" private/SLUS_204.86.rom --source src/w1911_s.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_t.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_t.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_t.o" private/SLUS_204.86.rom --source src/w1911_t.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/w1911_u.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/w1911_u.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_u.o" private/SLUS_204.86.rom --source src/w1911_u.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/w1911_v.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/w1911_v.o"
"$PYTHON" tools/verify_object.py "$BUILD/w1911_v.o" private/SLUS_204.86.rom --source src/w1911_v.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_effect_0036AE90.c -c -lang c -O3,p -sdatathreshold 8 -o "$BUILD/initialize_actor_effect_0036AE90.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_effect_0036AE90.o" \
    private/SLUS_204.86.rom --source src/initialize_actor_effect_0036AE90.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_timed_state_0028B4D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/initialize_actor_timed_state_0028B4D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_timed_state_0028B4D0.o" \
    private/SLUS_204.86.rom --source src/initialize_actor_timed_state_0028B4D0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/effect_handler_0026C020.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/effect_handler_0026C020.o"
"$PYTHON" tools/verify_object.py "$BUILD/effect_handler_0026C020.o" \
    private/SLUS_204.86.rom --source src/effect_handler_0026C020.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initialize_actor_handoff_00321A90.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/initialize_actor_handoff_00321A90.o"
"$PYTHON" tools/verify_object.py "$BUILD/initialize_actor_handoff_00321A90.o" \
    private/SLUS_204.86.rom --source src/initialize_actor_handoff_00321A90.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_entity_velocity_00218750.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/update_entity_velocity_00218750.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_entity_velocity_00218750.o" private/SLUS_204.86.rom --source src/update_entity_velocity_00218750.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_entity_timed_motion_00217AD0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/update_entity_timed_motion_00217AD0.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_entity_timed_motion_00217AD0.o" private/SLUS_204.86.rom --source src/update_entity_timed_motion_00217AD0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/update_damped_actor_motion_002DB600.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/update_damped_actor_motion_002DB600.o"
"$PYTHON" tools/verify_object.py "$BUILD/update_damped_actor_motion_002DB600.o" \
    private/SLUS_204.86.rom --source src/update_damped_actor_motion_002DB600.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/handle_entity_height_threshold_0020FA50.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/handle_entity_height_threshold_0020FA50.o"
"$PYTHON" tools/verify_object.py "$BUILD/handle_entity_height_threshold_0020FA50.o" private/SLUS_204.86.rom --source src/handle_entity_height_threshold_0020FA50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_rebound_motion_00196120.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/owner_rebound_motion_00196120.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_rebound_motion_00196120.o" \
    private/SLUS_204.86.rom --source src/owner_rebound_motion_00196120.c

# Preserve the retail call frames without empty-assembly barriers.
"$WIBO" "$SNCPP" -P src/runtime_framed_calls_0040.c "$BUILD/runtime_framed_calls_0040.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 \
    --extra-flags=-fno-optimize-sibling-calls "$BUILD/runtime_framed_calls_0040.i" "$BUILD/runtime_framed_calls_0040.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_framed_calls_0040.o" "$BUILD/runtime_framed_calls_0040.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_framed_calls_0040.o" private/SLUS_204.86.rom \
    --source src/runtime_framed_calls_0040.c

"$WIBO" "$SNCPP" -P src/runtime_object_storage.c "$BUILD/runtime_object_storage.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 \
    "$BUILD/runtime_object_storage.i" "$BUILD/runtime_object_storage.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/runtime_object_storage.o" "$BUILD/runtime_object_storage.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_object_storage.o" private/SLUS_204.86.rom \
    --source src/runtime_object_storage.c

"$WIBO" "$SNCPP" -P src/runtime_framed_calls_003f.c "$BUILD/runtime_framed_calls_003f.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 \
    --extra-flags=-fno-optimize-sibling-calls "$BUILD/runtime_framed_calls_003f.i" "$BUILD/runtime_framed_calls_003f.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/runtime_framed_calls_003f.o" "$BUILD/runtime_framed_calls_003f.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_framed_calls_003f.o" private/SLUS_204.86.rom \
    --source src/runtime_framed_calls_003f.c

"$WIBO" "$SNCPP" -P src/register_runtime_callback_00411720.c "$BUILD/register_runtime_callback_00411720.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 \
    --extra-flags=-fno-optimize-sibling-calls "$BUILD/register_runtime_callback_00411720.i" "$BUILD/register_runtime_callback_00411720.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/register_runtime_callback_00411720.o" "$BUILD/register_runtime_callback_00411720.s"
"$PYTHON" tools/verify_object.py "$BUILD/register_runtime_callback_00411720.o" private/SLUS_204.86.rom \
    --source src/register_runtime_callback_00411720.c

# This sector-count calculation retains the retail register schedule with the
# first scheduling pass disabled; the compiler still performs its final pass.
"$WIBO" "$SNCPP" -P src/set_runtime_sector_count_004007A0.c "$BUILD/set_runtime_sector_count_004007A0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 \
    --extra-flags=-fno-schedule-insns "$BUILD/set_runtime_sector_count_004007A0.i" "$BUILD/set_runtime_sector_count_004007A0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/set_runtime_sector_count_004007A0.o" "$BUILD/set_runtime_sector_count_004007A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/set_runtime_sector_count_004007A0.o" private/SLUS_204.86.rom \
    --source src/set_runtime_sector_count_004007A0.c

"$WIBO" "$SNCPP" -P src/process_runtime_object_004007F0.c "$BUILD/process_runtime_object_004007F0.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --opt O2 \
    "$BUILD/process_runtime_object_004007F0.i" "$BUILD/process_runtime_object_004007F0.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/process_runtime_object_004007F0.o" "$BUILD/process_runtime_object_004007F0.s"
"$PYTHON" tools/verify_object.py "$BUILD/process_runtime_object_004007F0.o" private/SLUS_204.86.rom \
    --source src/process_runtime_object_004007F0.c

"$WIBO" "$SNCPP" -P src/query_runtime_streams_003FF810.c "$BUILD/query_runtime_streams_003FF810.i"
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 \
    "$BUILD/query_runtime_streams_003FF810.i" "$BUILD/query_runtime_streams_003FF810.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/query_runtime_streams_003FF810.o" "$BUILD/query_runtime_streams_003FF810.s"
"$PYTHON" tools/verify_object.py "$BUILD/query_runtime_streams_003FF810.o" private/SLUS_204.86.rom \
    --source src/query_runtime_streams_003FF810.c

# These are complete callback targets from native tables jtbl_004504E0,
# jtbl_004506C0, jtbl_00450828, jtbl_00450950, jtbl_00450F90,
# jtbl_00458830, jtbl_004C10A0, and jtbl_0045AD08. Each dispatcher ends in
# an indirect jr plus its delay slot immediately before the callback entry.
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_06d10.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_06d10.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_06d10.o" private/SLUS_204.86.rom --source src/grok_n_06d10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_09d30.c -c -lang c -O3 -Op -o "$BUILD/grok_n_09d30.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_09d30.o" private/SLUS_204.86.rom --source src/grok_n_09d30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_0b4b0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_0b4b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_0b4b0.o" private/SLUS_204.86.rom --source src/grok_n_0b4b0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_0ddb0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_0ddb0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_0ddb0.o" private/SLUS_204.86.rom --source src/grok_n_0ddb0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_17bc0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_n_17bc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_17bc0.o" private/SLUS_204.86.rom --source src/grok_n_17bc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_a8880.c -c -lang c -O3 -Op -o "$BUILD/grok_n_a8880.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_a8880.o" private/SLUS_204.86.rom --source src/grok_n_a8880.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_de200.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_de200.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_de200.o" private/SLUS_204.86.rom --source src/grok_n_de200.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_de330.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_de330.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_de330.o" private/SLUS_204.86.rom --source src/grok_n_de330.c


# Additional primary-only table callbacks; entry table slots are recorded in docs/INDEPENDENT_CALLBACK_ENTRIES.csv.
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_0b6c0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z18_0b6c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_0b6c0.o" private/SLUS_204.86.rom --source src/grok_z18_0b6c0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_0d550.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z18_0d550.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_0d550.o" private/SLUS_204.86.rom --source src/grok_z18_0d550.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_9fc40.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z18_9fc40.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_9fc40.o" private/SLUS_204.86.rom --source src/grok_z18_9fc40.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_2abb0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_2abb0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_2abb0.o" private/SLUS_204.86.rom --source src/grok_w2_2abb0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_59dd0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_59dd0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_59dd0.o" private/SLUS_204.86.rom --source src/grok_w2_59dd0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_51b30.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_51b30.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_51b30.o" private/SLUS_204.86.rom --source src/grok_w2_51b30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_59bb0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_59bb0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_59bb0.o" private/SLUS_204.86.rom --source src/grok_w2_59bb0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_59a20.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_59a20.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_59a20.o" private/SLUS_204.86.rom --source src/grok_w2_59a20.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_5a520.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_5a520.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_5a520.o" private/SLUS_204.86.rom --source src/grok_w2_5a520.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_6dea0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_6dea0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_6dea0.o" private/SLUS_204.86.rom --source src/grok_w2_6dea0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_84e90.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_84e90.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_84e90.o" private/SLUS_204.86.rom --source src/grok_w2_84e90.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_7df50.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_7df50.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_7df50.o" private/SLUS_204.86.rom --source src/grok_w2_7df50.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2_6cec0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2_6cec0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2_6cec0.o" private/SLUS_204.86.rom --source src/grok_w2_6cec0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_355f0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_355f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_355f0.o" private/SLUS_204.86.rom --source src/grok_w2b_355f0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_5ee60.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_5ee60.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_5ee60.o" private/SLUS_204.86.rom --source src/grok_w2b_5ee60.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_5efc0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_5efc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_5efc0.o" private/SLUS_204.86.rom --source src/grok_w2b_5efc0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_5f760.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_5f760.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_5f760.o" private/SLUS_204.86.rom --source src/grok_w2b_5f760.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_60310.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_60310.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_60310.o" private/SLUS_204.86.rom --source src/grok_w2b_60310.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_69050.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_69050.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_69050.o" private/SLUS_204.86.rom --source src/grok_w2b_69050.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_60880.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_60880.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_60880.o" private/SLUS_204.86.rom --source src/grok_w2b_60880.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_6cd40.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_6cd40.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_6cd40.o" private/SLUS_204.86.rom --source src/grok_w2b_6cd40.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_591c0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_591c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_591c0.o" private/SLUS_204.86.rom --source src/grok_w2b_591c0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w2b_37f00.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w2b_37f00.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w2b_37f00.o" private/SLUS_204.86.rom --source src/grok_w2b_37f00.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1_d090.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_w1_d090.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1_d090.o" private/SLUS_204.86.rom --source src/grok_w1_d090.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_0040.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w3_0040.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w3_0040.o" private/SLUS_204.86.rom --source src/grok_w3_0040.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1b_19950.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w1b_19950.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1b_19950.o" private/SLUS_204.86.rom --source src/grok_w1b_19950.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1b_0ce90.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w1b_0ce90.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1b_0ce90.o" private/SLUS_204.86.rom --source src/grok_w1b_0ce90.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1b_19d40.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w1b_19d40.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1b_19d40.o" private/SLUS_204.86.rom --source src/grok_w1b_19d40.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1b_0b840.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w1b_0b840.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1b_0b840.o" private/SLUS_204.86.rom --source src/grok_w1b_0b840.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w1b_1b050.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w1b_1b050.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w1b_1b050.o" private/SLUS_204.86.rom --source src/grok_w1b_1b050.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u2_21b80.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_u2_21b80.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u2_21b80.o" private/SLUS_204.86.rom --source src/grok_u2_21b80.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u2_2b990.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_u2_2b990.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u2_2b990.o" private/SLUS_204.86.rom --source src/grok_u2_2b990.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u2_25a20.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_u2_25a20.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u2_25a20.o" private/SLUS_204.86.rom --source src/grok_u2_25a20.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u2_2fbc0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_u2_2fbc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u2_2fbc0.o" private/SLUS_204.86.rom --source src/grok_u2_2fbc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_19080.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_n_19080.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_19080.o" private/SLUS_204.86.rom --source src/grok_n_19080.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_f42b0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_n_f42b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_f42b0.o" private/SLUS_204.86.rom --source src/grok_n_f42b0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_f89e0.c -c -lang c -O3 -Op -o "$BUILD/grok_n_f89e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_f89e0.o" private/SLUS_204.86.rom --source src/grok_n_f89e0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_f58c0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z18_f58c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_f58c0.o" private/SLUS_204.86.rom --source src/grok_z18_f58c0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_f6e90.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_z18_f6e90.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_f6e90.o" private/SLUS_204.86.rom --source src/grok_z18_f6e90.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_f1640.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z18_f1640.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_f1640.o" private/SLUS_204.86.rom --source src/grok_z18_f1640.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_f1ed0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_z18_f1ed0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_f1ed0.o" private/SLUS_204.86.rom --source src/grok_z18_f1ed0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u24_a2800.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/grok_u24_a2800.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u24_a2800.o" private/SLUS_204.86.rom --source src/grok_u24_a2800.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u1c_c6d00.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/grok_u1c_c6d00.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u1c_c6d00.o" private/SLUS_204.86.rom --source src/grok_u1c_c6d00.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_m_69850.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_m_69850.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_m_69850.o" private/SLUS_204.86.rom --source src/grok_m_69850.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z18_b4580.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_z18_b4580.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z18_b4580.o" private/SLUS_204.86.rom --source src/grok_z18_b4580.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z32_41c460.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_z32_41c460.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z32_41c460.o" private/SLUS_204.86.rom --source src/grok_z32_41c460.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z11_516a0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_z11_516a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z11_516a0.o" private/SLUS_204.86.rom --source src/grok_z11_516a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_u18_e4150.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_u18_e4150.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_u18_e4150.o" private/SLUS_204.86.rom --source src/grok_u18_e4150.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_z32_f0db0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_z32_f0db0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_z32_f0db0.o" private/SLUS_204.86.rom --source src/grok_z32_f0db0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_m_3b010.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_m_3b010.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_m_3b010.o" private/SLUS_204.86.rom --source src/grok_m_3b010.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0023E3E0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/independent_state_entry_0023E3E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0023E3E0.o" private/SLUS_204.86.rom \
    --source src/independent_state_entry_0023E3E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002467B0.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/state_entries_002467B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002467B0.o" private/SLUS_204.86.rom --source src/state_entries_002467B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0025AF60.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_0025AF60.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0025AF60.o" private/SLUS_204.86.rom --source src/state_entries_0025AF60.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0021B6B0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_0021B6B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0021B6B0.o" private/SLUS_204.86.rom --source src/state_entries_0021B6B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002047C0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002047C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002047C0.o" private/SLUS_204.86.rom --source src/state_entries_002047C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00247A30.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/state_entries_00247A30.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00247A30.o" private/SLUS_204.86.rom --source src/state_entries_00247A30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0025F580.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_0025F580.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0025F580.o" private/SLUS_204.86.rom --source src/state_entries_0025F580.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0020A020.c -c -lang c -O3 -Op -o "$BUILD/state_entries_0020A020.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0020A020.o" private/SLUS_204.86.rom --source src/state_entries_0020A020.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00211B70.c -c -lang c -O3 -Op -o "$BUILD/state_entries_00211B70.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00211B70.o" private/SLUS_204.86.rom --source src/state_entries_00211B70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002138D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002138D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002138D0.o" private/SLUS_204.86.rom --source src/state_entries_002138D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0021E820.c -c -lang c -O3 -Op -o "$BUILD/state_entries_0021E820.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0021E820.o" private/SLUS_204.86.rom --source src/state_entries_0021E820.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002D6CE0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002D6CE0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002D6CE0.o" private/SLUS_204.86.rom --source src/state_entries_002D6CE0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0022AA50.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_0022AA50.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0022AA50.o" private/SLUS_204.86.rom --source src/state_entries_0022AA50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0026D890.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/state_entries_0026D890.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0026D890.o" private/SLUS_204.86.rom --source src/state_entries_0026D890.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00299080.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/state_entries_00299080.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00299080.o" private/SLUS_204.86.rom --source src/state_entries_00299080.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0020B1B0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_0020B1B0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0020B1B0.o" private/SLUS_204.86.rom --source src/state_entries_0020B1B0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002502D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002502D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002502D0.o" private/SLUS_204.86.rom --source src/state_entries_002502D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00205680.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/state_entries_00205680.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00205680.o" private/SLUS_204.86.rom --source src/state_entries_00205680.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00212160.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_00212160.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00212160.o" private/SLUS_204.86.rom --source src/state_entries_00212160.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00215820.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_00215820.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00215820.o" private/SLUS_204.86.rom --source src/state_entries_00215820.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0021E9D0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_0021E9D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0021E9D0.o" private/SLUS_204.86.rom --source src/state_entries_0021E9D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0023E640.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_0023E640.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0023E640.o" private/SLUS_204.86.rom --source src/state_entries_0023E640.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00240F60.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_00240F60.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00240F60.o" private/SLUS_204.86.rom --source src/state_entries_00240F60.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002529E0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_002529E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002529E0.o" private/SLUS_204.86.rom --source src/state_entries_002529E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00270DE0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_00270DE0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00270DE0.o" private/SLUS_204.86.rom --source src/state_entries_00270DE0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00271C50.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_00271C50.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00271C50.o" private/SLUS_204.86.rom --source src/state_entries_00271C50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00275490.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_00275490.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00275490.o" private/SLUS_204.86.rom --source src/state_entries_00275490.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0027EA20.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/state_entries_0027EA20.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0027EA20.o" private/SLUS_204.86.rom --source src/state_entries_0027EA20.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00288700.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_00288700.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00288700.o" private/SLUS_204.86.rom --source src/state_entries_00288700.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00288DF0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_00288DF0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00288DF0.o" private/SLUS_204.86.rom --source src/state_entries_00288DF0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_0028D270.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_0028D270.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_0028D270.o" private/SLUS_204.86.rom --source src/state_entries_0028D270.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002945C0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002945C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002945C0.o" private/SLUS_204.86.rom --source src/state_entries_002945C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002A6EA0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002A6EA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002A6EA0.o" private/SLUS_204.86.rom --source src/state_entries_002A6EA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002ECDC0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entries_002ECDC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002ECDC0.o" private/SLUS_204.86.rom --source src/state_entries_002ECDC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_00282720.c -c -lang c -O3 -Op -o "$BUILD/state_entries_00282720.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_00282720.o" private/SLUS_204.86.rom --source src/state_entries_00282720.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003145A0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003145A0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003145A0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003145A0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entries_002CED00.c -c -lang c -O3 -Op -sdatathreshold 8 -o "$BUILD/state_entries_002CED00.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entries_002CED00.o" private/SLUS_204.86.rom --source src/state_entries_002CED00.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00361C60.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00361C60.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00361C60.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00361C60.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003140F0.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/independent_state_entry_003140F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003140F0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003140F0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entry_0023E9C0.c -c -lang c -O3 -Op -sdatathreshold 0 -o "$BUILD/state_entry_0023E9C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entry_0023E9C0.o" private/SLUS_204.86.rom --source src/state_entry_0023E9C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_entry_00222290.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/state_entry_00222290.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_entry_00222290.o" private/SLUS_204.86.rom --source src/state_entry_00222290.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00310B70.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00310B70.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00310B70.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00310B70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00317C10.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00317C10.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00317C10.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00317C10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00317EC0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00317EC0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00317EC0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00317EC0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00320F60.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/independent_state_entry_00320F60.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00320F60.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00320F60.c

# Queue-backed runtime entry construction; complete EE GCC 2.96 function.
"$WIBO" "$SNCPP" -P src/runtime_entry_create_0040CC30.c "$BUILD/runtime_entry_create_0040CC30.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/runtime_entry_create_0040CC30.i" "$BUILD/runtime_entry_create_0040CC30.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/runtime_entry_create_0040CC30.o" "$BUILD/runtime_entry_create_0040CC30.s"
"$PYTHON" tools/verify_object.py "$BUILD/runtime_entry_create_0040CC30.o" private/SLUS_204.86.rom --source src/runtime_entry_create_0040CC30.c

# Stream-group constructor retains indexed copies rather than induction pointers.
"$WIBO" "$SNCPP" -P src/create_stream_group_003FF3E8.c "$BUILD/create_stream_group_003FF3E8.i"
"$PYTHON" tools/compile_ee96.py --extra-flags=-fno-strength-reduce "$BUILD/create_stream_group_003FF3E8.i" "$BUILD/create_stream_group_003FF3E8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/create_stream_group_003FF3E8.o" "$BUILD/create_stream_group_003FF3E8.s"
"$PYTHON" tools/verify_object.py "$BUILD/create_stream_group_003FF3E8.o" private/SLUS_204.86.rom --source src/create_stream_group_003FF3E8.c

"$WIBO" "$SNCPP" -P src/create_stream_engine_003F7C38.c "$BUILD/create_stream_engine_003F7C38.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/create_stream_engine_003F7C38.i" "$BUILD/create_stream_engine_003F7C38.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/create_stream_engine_003F7C38.o" "$BUILD/create_stream_engine_003F7C38.s"
"$PYTHON" tools/verify_object.py "$BUILD/create_stream_engine_003F7C38.o" private/SLUS_204.86.rom --source src/create_stream_engine_003F7C38.c

"$WIBO" "$SNCPP" -P src/create_runtime_handle_00404290.c "$BUILD/create_runtime_handle_00404290.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/create_runtime_handle_00404290.i" "$BUILD/create_runtime_handle_00404290.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/create_runtime_handle_00404290.o" "$BUILD/create_runtime_handle_00404290.s"
"$PYTHON" tools/verify_object.py "$BUILD/create_runtime_handle_00404290.o" private/SLUS_204.86.rom --source src/create_runtime_handle_00404290.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00315980.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00315980.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00315980.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00315980.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0031AA30.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0031AA30.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0031AA30.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0031AA30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0031ACA0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0031ACA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0031ACA0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0031ACA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0034ACF0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0034ACF0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0034ACF0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0034ACF0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003572E0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003572E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003572E0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003572E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0036B910.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0036B910.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0036B910.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0036B910.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00388B30.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00388B30.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00388B30.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00388B30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00390060.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00390060.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00390060.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00390060.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0039CE40.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0039CE40.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0039CE40.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0039CE40.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003B9C40.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003B9C40.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003B9C40.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003B9C40.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003BC2C0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003BC2C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003BC2C0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003BC2C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entries_003B0540_003B0D90.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entries_003B0540_003B0D90.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entries_003B0540_003B0D90.o" \
    private/SLUS_204.86.rom --source src/independent_state_entries_003B0540_003B0D90.c

"$WIBO" "$SNCPP" -P src/create_decoder_group_0040E520.c "$BUILD/create_decoder_group_0040E520.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/create_decoder_group_0040E520.i" "$BUILD/create_decoder_group_0040E520.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/create_decoder_group_0040E520.o" "$BUILD/create_decoder_group_0040E520.s"
"$PYTHON" tools/verify_object.py "$BUILD/create_decoder_group_0040E520.o" private/SLUS_204.86.rom --source src/create_decoder_group_0040E520.c

# Keep the final release calls in the framed function without source barriers.
"$WIBO" "$SNCPP" -P src/release_runtime_entries_0040D6A0.c "$BUILD/release_runtime_entries_0040D6A0.i"
"$PYTHON" tools/compile_ee96.py --small-data-threshold 8 --extra-flags=-fno-optimize-sibling-calls "$BUILD/release_runtime_entries_0040D6A0.i" "$BUILD/release_runtime_entries_0040D6A0.s"
"$WIBO" "$SNAS" -G8 -o "$BUILD/release_runtime_entries_0040D6A0.o" "$BUILD/release_runtime_entries_0040D6A0.s"
"$PYTHON" tools/verify_object.py "$BUILD/release_runtime_entries_0040D6A0.o" private/SLUS_204.86.rom --source src/release_runtime_entries_0040D6A0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0031D260.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0031D260.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0031D260.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0031D260.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003112D0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003112D0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003112D0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003112D0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00327E20.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00327E20.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00327E20.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00327E20.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00328140.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00328140.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00328140.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00328140.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_003292F0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_003292F0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_003292F0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_003292F0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00328350.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00328350.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00328350.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00328350.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00328530.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00328530.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00328530.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00328530.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00336210.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00336210.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00336210.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00336210.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_0038D6E0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_0038D6E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_0038D6E0.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_0038D6E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/independent_state_entry_00397630.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/independent_state_entry_00397630.o"
"$PYTHON" tools/verify_object.py "$BUILD/independent_state_entry_00397630.o" \
    private/SLUS_204.86.rom --source src/independent_state_entry_00397630.c

"$WIBO" "$SNCPP" -P src/find_named_runtime_span_0040C6D0.c "$BUILD/find_named_runtime_span_0040C6D0.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/find_named_runtime_span_0040C6D0.i" "$BUILD/find_named_runtime_span_0040C6D0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/find_named_runtime_span_0040C6D0.o" "$BUILD/find_named_runtime_span_0040C6D0.s"
"$PYTHON" tools/verify_object.py "$BUILD/find_named_runtime_span_0040C6D0.o" private/SLUS_204.86.rom --source src/find_named_runtime_span_0040C6D0.c

"$WIBO" "$SNCPP" -P src/close_runtime_directory_0040C578.c "$BUILD/close_runtime_directory_0040C578.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/close_runtime_directory_0040C578.i" "$BUILD/close_runtime_directory_0040C578.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/close_runtime_directory_0040C578.o" "$BUILD/close_runtime_directory_0040C578.s"
"$PYTHON" tools/verify_object.py "$BUILD/close_runtime_directory_0040C578.o" private/SLUS_204.86.rom --source src/close_runtime_directory_0040C578.c

"$WIBO" "$SNCPP" -P src/finish_runtime_entry_0040D8F8.c "$BUILD/finish_runtime_entry_0040D8F8.i"
"$PYTHON" tools/compile_ee96.py --extra-flags=-fno-optimize-sibling-calls "$BUILD/finish_runtime_entry_0040D8F8.i" "$BUILD/finish_runtime_entry_0040D8F8.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/finish_runtime_entry_0040D8F8.o" "$BUILD/finish_runtime_entry_0040D8F8.s"
"$PYTHON" tools/verify_object.py "$BUILD/finish_runtime_entry_0040D8F8.o" private/SLUS_204.86.rom --source src/finish_runtime_entry_0040D8F8.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nop_1b0b20.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nop_1b0b20.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nop_1b0b20.o" private/SLUS_204.86.rom --source src/grok_nop_1b0b20.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nop_1b2930.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nop_1b2930.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nop_1b2930.o" private/SLUS_204.86.rom --source src/grok_nop_1b2930.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nop_1b2fb0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nop_1b2fb0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nop_1b2fb0.o" private/SLUS_204.86.rom --source src/grok_nop_1b2fb0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b0cf0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b0cf0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b0cf0.o" private/SLUS_204.86.rom --source src/grok_nopa_1b0cf0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b2a10.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b2a10.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b2a10.o" private/SLUS_204.86.rom --source src/grok_nopa_1b2a10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nop_fa85c.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nop_fa85c.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nop_fa85c.o" private/SLUS_204.86.rom --source src/grok_nop_fa85c.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b4020.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b4020.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b4020.o" private/SLUS_204.86.rom --source src/grok_nopa_1b4020.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b4120.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b4120.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b4120.o" private/SLUS_204.86.rom --source src/grok_nopa_1b4120.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b4440.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b4440.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b4440.o" private/SLUS_204.86.rom --source src/grok_nopa_1b4440.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopa_1b4fd0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopa_1b4fd0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopa_1b4fd0.o" private/SLUS_204.86.rom --source src/grok_nopa_1b4fd0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_07710.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_07710.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_07710.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_07710.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_0c720.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_0c720.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_0c720.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_0c720.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_0ead0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_0ead0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_0ead0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_0ead0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_0ebf0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_0ebf0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_0ebf0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_0ebf0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_38d50.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_38d50.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_38d50.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_38d50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_403e0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopb_403e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_403e0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_403e0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_424a0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_424a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_424a0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_424a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_425a0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_425a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_425a0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_425a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopb_777e0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopb_777e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopb_777e0.o" \
    private/SLUS_204.86.rom --source src/grok_nopb_777e0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nope_1b0b80.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nope_1b0b80.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nope_1b0b80.o" private/SLUS_204.86.rom --source src/grok_nope_1b0b80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nope_1b0c50.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nope_1b0c50.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nope_1b0c50.o" private/SLUS_204.86.rom --source src/grok_nope_1b0c50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nope_1b2e80.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nope_1b2e80.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nope_1b2e80.o" private/SLUS_204.86.rom --source src/grok_nope_1b2e80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nope_1b36b0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nope_1b36b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nope_1b36b0.o" private/SLUS_204.86.rom --source src/grok_nope_1b36b0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_fde20.c -c -lang c -O3 -Op -o "$BUILD/grok_n_fde20.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_fde20.o" private/SLUS_204.86.rom --source src/grok_n_fde20.c




MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_3077f0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_3077f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_3077f0.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_3077f0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_31e9f0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_31e9f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_31e9f0.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_31e9f0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_30b0f0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_30b0f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_30b0f0.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_30b0f0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_319c30.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_319c30.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_319c30.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_319c30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_n_06600.c -c -lang c -O3 -Op -o "$BUILD/grok_n_06600.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_n_06600.o" \
    private/SLUS_204.86.rom --source src/grok_n_06600.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4b_residual_00312570.c -c -lang c -O4,p -o "$BUILD/grok_w4b_residual_00312570.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w4b_residual_00312570.o" \
    private/SLUS_204.86.rom --source src/grok_w4b_residual_00312570.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5b_0039d280.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_w5b_0039d280.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w5b_0039d280.o" \
    private/SLUS_204.86.rom --source src/grok_w5b_0039d280.c

"$WIBO" "$SNCPP" -P src/read_adx_header_fields_003F9AF0.c "$BUILD/read_adx_header_fields_003F9AF0.i"
"$PYTHON" tools/compile_ee96.py "$BUILD/read_adx_header_fields_003F9AF0.i" "$BUILD/read_adx_header_fields_003F9AF0.s"
"$WIBO" "$SNAS" -G0 -o "$BUILD/read_adx_header_fields_003F9AF0.o" "$BUILD/read_adx_header_fields_003F9AF0.s"
"$PYTHON" tools/verify_object.py "$BUILD/read_adx_header_fields_003F9AF0.o" private/SLUS_204.86.rom --source src/read_adx_header_fields_003F9AF0.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_320750.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_320750.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_320750.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_320750.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_3208c0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopd_3208c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_3208c0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_3208c0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_3209a0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_3209a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_3209a0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_3209a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_320ad0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_320ad0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_320ad0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_320ad0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_320be0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_320be0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_320be0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_320be0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_30b740.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_30b740.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_30b740.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_30b740.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_310db0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopd_310db0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_310db0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_310db0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_311170.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopd_311170.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_311170.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_311170.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4b_residual_00311A90.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_w4b_residual_00311A90.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w4b_residual_00311A90.o" \
    private/SLUS_204.86.rom --source src/grok_w4b_residual_00311A90.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nop_9f2a0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nop_9f2a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nop_9f2a0.o" private/SLUS_204.86.rom --source src/grok_nop_9f2a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopk_1fa740.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopk_1fa740.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopk_1fa740.o" private/SLUS_204.86.rom --source src/grok_nopk_1fa740.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_303438.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_nm3_303438.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_303438.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_303438.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_38f270.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopd_38f270.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_38f270.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_38f270.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5b_003b8ba0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_w5b_003b8ba0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w5b_003b8ba0.o" \
    private/SLUS_204.86.rom --source src/grok_w5b_003b8ba0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_311b30.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_nm3_311b30.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_311b30.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_311b30.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm_302ba0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_nm_302ba0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm_302ba0.o" \
    private/SLUS_204.86.rom --source src/grok_nm_302ba0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4b_residual_003045C0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_w4b_residual_003045C0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w4b_residual_003045C0.o" \
    private/SLUS_204.86.rom --source src/grok_w4b_residual_003045C0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4b_residual_00315CA0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_w4b_residual_00315CA0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_w4b_residual_00315CA0.o" \
    private/SLUS_204.86.rom --source src/grok_w4b_residual_00315CA0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopm_30b250.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopm_30b250.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopm_30b250.o" \
    private/SLUS_204.86.rom --source src/grok_nopm_30b250.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopm_311690.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nopm_311690.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopm_311690.o" \
    private/SLUS_204.86.rom --source src/grok_nopm_311690.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopi_3750d0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopi_3750d0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopi_3750d0.o" \
    private/SLUS_204.86.rom --source src/grok_nopi_3750d0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopi_371370.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopi_371370.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopi_371370.o" \
    private/SLUS_204.86.rom --source src/grok_nopi_371370.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopi_373dd0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopi_373dd0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopi_373dd0.o" \
    private/SLUS_204.86.rom --source src/grok_nopi_373dd0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q0_3402b0.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_q0_3402b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q0_3402b0.o" \
    private/SLUS_204.86.rom --source src/grok_q0_3402b0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopi_3a5ca0.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/grok_nopi_3a5ca0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopi_3a5ca0.o" \
    private/SLUS_204.86.rom --source src/grok_nopi_3a5ca0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopi_3b1e00.c -c -lang c -O4,p -sdatathreshold 8 -o "$BUILD/grok_nopi_3b1e00.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopi_3b1e00.o" \
    private/SLUS_204.86.rom --source src/grok_nopi_3b1e00.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_300090.c -c -lang c -O3 -sdatathreshold 0 -o "$BUILD/grok_nm3_300090.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_300090.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_300090.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_noph_303f20.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_noph_303f20.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_noph_303f20.o" \
    private/SLUS_204.86.rom --source src/grok_noph_303f20.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b3e30.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/event_clone_001b3e30.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b3e30.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b3e30.c
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_noph_315140.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_noph_315140.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_noph_315140.o" \
    private/SLUS_204.86.rom --source src/grok_noph_315140.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nopd_35ffc0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_nopd_35ffc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nopd_35ffc0.o" \
    private/SLUS_204.86.rom --source src/grok_nopd_35ffc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_303500.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_303500.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_303500.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_303500.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_303660.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_303660.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_303660.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_303660.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_nm3_304110.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_nm3_304110.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_nm3_304110.o" \
    private/SLUS_204.86.rom --source src/grok_nm3_304110.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_3068e0.c -c -lang c -O4,p -sdatathreshold 0 -o "$BUILD/grok_q4_3068e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_3068e0.o" \
    private/SLUS_204.86.rom --source src/grok_q4_3068e0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_31edf0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_q4_31edf0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_31edf0.o" \
    private/SLUS_204.86.rom --source src/grok_q4_31edf0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_3239f0.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_q4_3239f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_3239f0.o" \
    private/SLUS_204.86.rom --source src/grok_q4_3239f0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_325460.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_q4_325460.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_325460.o" \
    private/SLUS_204.86.rom --source src/grok_q4_325460.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_325730.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_q4_325730.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_325730.o" \
    private/SLUS_204.86.rom --source src/grok_q4_325730.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_q4_320500.c -c -lang c -O3 -sdatathreshold 8 -o "$BUILD/grok_q4_320500.o"
"$PYTHON" tools/verify_object.py "$BUILD/grok_q4_320500.o" \
    private/SLUS_204.86.rom --source src/grok_q4_320500.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b53e0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/event_clone_001b53e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b53e0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b53e0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001c8fd0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/event_clone_001c8fd0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001c8fd0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001c8fd0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b6fc0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b6fc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b6fc0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b6fc0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b7ab0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b7ab0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b7ab0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b7ab0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b7d10.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b7d10.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b7d10.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b7d10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/event_clone_dispatch_001b76e0.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/event_clone_dispatch_001b76e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_dispatch_001b76e0.o" \
    private/SLUS_204.86.rom --source src/event_clone_dispatch_001b76e0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b7700.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b7700.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b7700.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b7700.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b8e30.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b8e30.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b8e30.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b8e30.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b6040.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b6040.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b6040.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b6040.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/state_init_002f4050.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/state_init_002f4050.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_init_002f4050.o" \
    private/SLUS_204.86.rom --source src/state_init_002f4050.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/launch_motion_002192b0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/launch_motion_002192b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/launch_motion_002192b0.o" \
    private/SLUS_204.86.rom --source src/launch_motion_002192b0.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b6860.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b6860.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b6860.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b6860.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b69d0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b69d0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b69d0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b69d0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b6da0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b6da0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b6da0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b6da0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b65b0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b65b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b65b0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b65b0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b6410.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b6410.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b6410.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b6410.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/edge_slide_0020cb80.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/edge_slide_0020cb80.o"
"$PYTHON" tools/verify_object.py "$BUILD/edge_slide_0020cb80.o" \
    private/SLUS_204.86.rom --source src/edge_slide_0020cb80.c
MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001b61c0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001b61c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001b61c0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001b61c0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/event_clone_001d88c0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/event_clone_001d88c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/event_clone_001d88c0.o" \
    private/SLUS_204.86.rom --source src/event_clone_001d88c0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/state_dispatch_001f56e0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/state_dispatch_001f56e0.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_dispatch_001f56e0.o" \
    private/SLUS_204.86.rom --source src/state_dispatch_001f56e0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/state_action_001f5720.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/state_action_001f5720.o"
"$PYTHON" tools/verify_object.py "$BUILD/state_action_001f5720.o" \
    private/SLUS_204.86.rom --source src/state_action_001f5720.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/capture_transition_00229910.c -c -lang c -O3 -Op -sdatathreshold 0 -i src/data \
    -o "$BUILD/capture_transition_00229910.o"
"$PYTHON" tools/verify_object.py "$BUILD/capture_transition_00229910.o" \
    private/SLUS_204.86.rom --source src/capture_transition_00229910.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/landing_transition_002feda0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/landing_transition_002feda0.o"
"$PYTHON" tools/verify_object.py "$BUILD/landing_transition_002feda0.o" \
    private/SLUS_204.86.rom --source src/landing_transition_002feda0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initial_launch_002218b0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/initial_launch_002218b0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initial_launch_002218b0.o" \
    private/SLUS_204.86.rom --source src/initial_launch_002218b0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/restore_target_0026db70.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/restore_target_0026db70.o"
"$PYTHON" tools/verify_object.py "$BUILD/restore_target_0026db70.o" \
    private/SLUS_204.86.rom --source src/restore_target_0026db70.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/alternating_throw_00253fc0.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/alternating_throw_00253fc0.o"
"$PYTHON" tools/verify_object.py "$BUILD/alternating_throw_00253fc0.o" \
    private/SLUS_204.86.rom --source src/alternating_throw_00253fc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/dispatch_owner_state_002F45E0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/dispatch_owner_state_002F45E0.o"
"$PYTHON" tools/verify_object.py "$BUILD/dispatch_owner_state_002F45E0.o" \
    private/SLUS_204.86.rom --source src/dispatch_owner_state_002F45E0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002F4610.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002F4610.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002F4610.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002F4610.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/crossing_stop_00201150.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/crossing_stop_00201150.o"
"$PYTHON" tools/verify_object.py "$BUILD/crossing_stop_00201150.o" \
    private/SLUS_204.86.rom --source src/crossing_stop_00201150.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/release_owner_0021bae0.c -c -lang c -O3,p -Op -sdatathreshold 8 \
    -o "$BUILD/release_owner_0021bae0.o"
"$PYTHON" tools/verify_object.py "$BUILD/release_owner_0021bae0.o" \
    private/SLUS_204.86.rom --source src/release_owner_0021bae0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/launch_reset_00238200.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/launch_reset_00238200.o"
"$PYTHON" tools/verify_object.py "$BUILD/launch_reset_00238200.o" \
    private/SLUS_204.86.rom --source src/launch_reset_00238200.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/early_motion_initializers.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/early_motion_initializers.o"
"$PYTHON" tools/verify_object.py "$BUILD/early_motion_initializers.o" \
    private/SLUS_204.86.rom --source src/early_motion_initializers.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/side_shift_0020a260.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/side_shift_0020a260.o"
"$PYTHON" tools/verify_object.py "$BUILD/side_shift_0020a260.o" \
    private/SLUS_204.86.rom --source src/side_shift_0020a260.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/repeating_child_effect_00205c10.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/repeating_child_effect_00205c10.o"
"$PYTHON" tools/verify_object.py "$BUILD/repeating_child_effect_00205c10.o" \
    private/SLUS_204.86.rom --source src/repeating_child_effect_00205c10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/counter_effects_00206380.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/counter_effects_00206380.o"
"$PYTHON" tools/verify_object.py "$BUILD/counter_effects_00206380.o" \
    private/SLUS_204.86.rom --source src/counter_effects_00206380.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/initial_launches_0024fae0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/initial_launches_0024fae0.o"
"$PYTHON" tools/verify_object.py "$BUILD/initial_launches_0024fae0.o" \
    private/SLUS_204.86.rom --source src/initial_launches_0024fae0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/query_owner_guard_0024d670.c -c -lang c -O3,p -Op -sdatathreshold 0 \
    -o "$BUILD/query_owner_guard_0024d670.o"
"$PYTHON" tools/verify_object.py "$BUILD/query_owner_guard_0024d670.o" \
    private/SLUS_204.86.rom --source src/query_owner_guard_0024d670.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/scaled_pair_motion_00259400.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/scaled_pair_motion_00259400.o"
"$PYTHON" tools/verify_object.py "$BUILD/scaled_pair_motion_00259400.o" \
    private/SLUS_204.86.rom --source src/scaled_pair_motion_00259400.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/character_dispatch_heads_00231ca0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/character_dispatch_heads_00231ca0.o"
"$PYTHON" tools/verify_object.py "$BUILD/character_dispatch_heads_00231ca0.o" \
    private/SLUS_204.86.rom --source src/character_dispatch_heads_00231ca0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/table_motion_002206a0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/table_motion_002206a0.o"
"$PYTHON" tools/verify_object.py "$BUILD/table_motion_002206a0.o" \
    private/SLUS_204.86.rom --source src/table_motion_002206a0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_character_action_00255950.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \
    -o "$BUILD/select_character_action_00255950.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_character_action_00255950.o" \
    private/SLUS_204.86.rom --source src/select_character_action_00255950.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002833d0.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002833d0.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002833d0.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002833d0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_ground_action_00274060.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \
    -o "$BUILD/select_ground_action_00274060.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_ground_action_00274060.o" \
    private/SLUS_204.86.rom --source src/select_ground_action_00274060.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002B9900.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002B9900.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002B9900.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002B9900.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/motion_stop_002C1580.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/motion_stop_002C1580.o"
"$PYTHON" tools/verify_object.py "$BUILD/motion_stop_002C1580.o" \
    private/SLUS_204.86.rom --source src/motion_stop_002C1580.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/angle_velocity_00237d40.c -c -lang c -O3 -Op -sdatathreshold 0 \
    -o "$BUILD/angle_velocity_00237d40.o"
"$PYTHON" tools/verify_object.py "$BUILD/angle_velocity_00237d40.o" \
    private/SLUS_204.86.rom --source src/angle_velocity_00237d40.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002D5190.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002D5190.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002D5190.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002D5190.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002C6B10.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002C6B10.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002C6B10.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002C6B10.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_launch_actions_00256580.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \
    -o "$BUILD/select_launch_actions_00256580.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_launch_actions_00256580.o" \
    private/SLUS_204.86.rom --source src/select_launch_actions_00256580.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_0029D690.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_0029D690.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_0029D690.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_0029D690.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/select_throw_motion_0021d7c0.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \
    -o "$BUILD/select_throw_motion_0021d7c0.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_throw_motion_0021d7c0.o" \
    private/SLUS_204.86.rom --source src/select_throw_motion_0021d7c0.c

MWCIncludes=$(dirname "$MWCCPS2_30") "$WIBO" "$MWCCPS2_30" \
    src/select_input_variant_0023a440.c -c -lang c -O3,p -Op -sdatathreshold 0 \
    -o "$BUILD/select_input_variant_0023a440.o"
"$PYTHON" tools/verify_object.py "$BUILD/select_input_variant_0023a440.o" \
    private/SLUS_204.86.rom --source src/select_input_variant_0023a440.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_00285E50.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_00285E50.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_00285E50.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_00285E50.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002C1E80.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002C1E80.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002C1E80.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002C1E80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/owner_state_callback_002FB800.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/owner_state_callback_002FB800.o"
"$PYTHON" tools/verify_object.py "$BUILD/owner_state_callback_002FB800.o" \
    private/SLUS_204.86.rom --source src/owner_state_callback_002FB800.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/palette_cycle_0027af80.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/palette_cycle_0027af80.o"
"$PYTHON" tools/verify_object.py "$BUILD/palette_cycle_0027af80.o" \
    private/SLUS_204.86.rom --source src/palette_cycle_0027af80.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/timed_motion_00250b40.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \
    -o "$BUILD/timed_motion_00250b40.o"
"$PYTHON" tools/verify_object.py "$BUILD/timed_motion_00250b40.o" \
    private/SLUS_204.86.rom --source src/timed_motion_00250b40.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/jump_motion_002357f0.c -c -lang c -O3 -Op -sdatathreshold 8 -i src \    -o "$BUILD/jump_motion_002357f0.o"
"$PYTHON" tools/verify_object.py "$BUILD/jump_motion_002357f0.o" \
    private/SLUS_204.86.rom --source src/jump_motion_002357f0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/launch_fixed_motion_0023c450.c -c -lang c -O3 -Op -sdatathreshold 8 \
    -o "$BUILD/launch_fixed_motion_0023c450.o"
"$PYTHON" tools/verify_object.py "$BUILD/launch_fixed_motion_0023c450.o" \
    private/SLUS_204.86.rom --source src/launch_fixed_motion_0023c450.c
