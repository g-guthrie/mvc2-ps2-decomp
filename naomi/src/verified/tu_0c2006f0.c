/* SDK byte consumer [0c2006f0,0c200710).
 * Read the byte before advancing the pointer field: the byte pointer may
 * alias the state object. The two accesses are separate C statements. */
#include "objects.h"
#pragma section Consumer
unsigned int func_0c2006f0(struct SdkByteConsumer *state)
{
    unsigned int value = *state->input;
    state->input++;
    state->input_count--;
    state->output++;
    state->output_count--;
    return value;
}
