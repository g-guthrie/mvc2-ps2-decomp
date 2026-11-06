/* SDK consumer/count skip [0c200710,0c20075c).
 * Complete native behavior; uses read-before-pointer-update ordering.
 * Private research only until whole proof and full gate. */
#include "objects.h"
#pragma section ConsumerSkip
unsigned int func_0c200710(struct SdkByteConsumer *state)
{
    unsigned int value = *state->input;
    int count;
    int index;
    state->input++;
    state->input_count--;
    state->output++;
    state->output_count--;
    count = *state->output;
    state->output++;
    state->output_count--;
    for (index = 0; index < count; index++) {
        state->output++;
        state->output_count--;
    }
    return value;
}
