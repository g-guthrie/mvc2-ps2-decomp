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
    -o "$BUILD/grok_r2_0034.o"
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
    src/grok_w3_0038.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w3_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_pairs.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_pairs.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4_szc0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w4_szc0.o"
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
    src/grok_w5_0019.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0019.o"
    src/grok_w5_001a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_001a.o"
    src/grok_w5_001e.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0012.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0012.o"
    src/grok_w5_0014.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0014.o"
    src/grok_w5_0016.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0016.o"
    src/grok_w5_0018.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0018.o"
    src/grok_w5_001b.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001b.o"
    src/grok_w5_001c.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_001c.o"
    src/grok_w5_0017.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0017.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0024.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0024.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_sz54.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_sz54.o"
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
    src/grok_w5_002e.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_002e.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0038.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0038.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_003a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_003a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0026.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0026.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0034.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_0034.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_0028.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_0028.o"
    src/grok_w5_sz40.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_sz40.o"
    src/grok_w5_szc0.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_szc0.o"

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003a.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_003a.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w4_sz80.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w4_sz80.o"
MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_sz80.c -c -lang c -O3 -sdatathreshold 8 \
    -o "$BUILD/grok_w5_sz80.o"
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
    "$BUILD/grok_r2_0024.o" private/SLUS_204.86.rom \
    --source src/grok_r2_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0024.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0024.c
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
    "$BUILD/grok_w3_0038.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_pairs.o" private/SLUS_204.86.rom \
    --source src/grok_w3_pairs.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w4_sz80.o" private/SLUS_204.86.rom \
    --source src/grok_w4_sz80.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w4_szc0.o" private/SLUS_204.86.rom \
    --source src/grok_w4_szc0.c
    "$BUILD/grok_w3_0035.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0035.c


MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w3_003f.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w3_003f.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_003f.o" private/SLUS_204.86.rom \
    --source src/grok_w3_003f.c
    "$BUILD/grok_w3_sz68.o" private/SLUS_204.86.rom \
    --source src/grok_w3_sz68.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w3_0041.o" private/SLUS_204.86.rom \
    --source src/grok_w3_0041.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0015.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0015.c
    "$BUILD/grok_w5_0019.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0019.c
    "$BUILD/grok_w5_001a.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001a.c
    "$BUILD/grok_w5_001e.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0012.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0012.c
    "$BUILD/grok_w5_0014.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0014.c
    "$BUILD/grok_w5_0016.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0016.c
    "$BUILD/grok_w5_0018.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0018.c
    "$BUILD/grok_w5_001b.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001b.c
    "$BUILD/grok_w5_001c.o" private/SLUS_204.86.rom \
    --source src/grok_w5_001c.c
    "$BUILD/grok_w5_0017.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0017.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0024.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0024.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_sz54.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz54.c
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
    "$BUILD/grok_w5_002e.o" private/SLUS_204.86.rom \
    --source src/grok_w5_002e.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0038.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0038.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_003a.o" private/SLUS_204.86.rom \
    --source src/grok_w5_003a.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0026.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0026.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0034.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0034.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_0028.o" private/SLUS_204.86.rom \
    --source src/grok_w5_0028.c
    "$BUILD/grok_w5_sz40.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz40.c
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_sz80.o" private/SLUS_204.86.rom \
    --source src/grok_w5_sz80.c
    "$BUILD/grok_w5_szc0.o" private/SLUS_204.86.rom \
    --source src/grok_w5_szc0.c

MWCIncludes=$(dirname "$MWCCPS2") "$WIBO" "$MWCCPS2" \
    src/grok_w5_neg.c -c -lang c $MATCH_FLAGS \
    -o "$BUILD/grok_w5_neg.o"
"$PYTHON" tools/verify_object.py \
    "$BUILD/grok_w5_neg.o" private/SLUS_204.86.rom \
    --source src/grok_w5_neg.c
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
