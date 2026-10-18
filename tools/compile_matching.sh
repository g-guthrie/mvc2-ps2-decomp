#!/bin/sh
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"
: "${MWCCPS2_30:?set MWCCPS2_30 to private mwccps2-3.0-011126/mwccps2.exe}"

: "${SNCPP:?set SNCPP to SN GCC 2.95.2 cpp.exe}"
: "${SNCC1:?set SNCC1 to SN GCC 2.95.2 cc1.exe}"
: "${SNAS:?set SNAS to the matching SN ee-as.exe}"

: "${EE96CC1:?set EE96CC1 to EE GCC 2.96 cc1}"

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
