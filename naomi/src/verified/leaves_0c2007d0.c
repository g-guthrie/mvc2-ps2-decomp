/* SDK byte-stream opcode handlers that skip a counted block of input. */
#include "objects.h"

#pragma section n2007d0
unsigned int func_0c2007d0(struct SdkByteConsumer *s)
{
    unsigned int value = *s->input;
    int rows;
    int cols;
    int i;
    int j;
    s->input++;
    s->input_count--;
    s->output++;
    s->output_count--;
    rows = *s->output;
    s->output++;
    s->output_count--;
    cols = *s->output;
    s->output++;
    s->output_count--;
    if (value != 2) {
        s->input++;
        s->input_count--;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                s->input++;
            }
        }
        s->input_count -= cols * rows;
    }
    return value;
}

#pragma section n200854
unsigned int func_0c200854(struct SdkByteConsumer *s)
{
    unsigned int value = *s->input;
    int n;
    int j;
    s->input++;
    s->input_count--;
    s->output++;
    s->output_count--;
    n = *s->output;
    s->output++;
    s->output_count--;
    if (value != 2) {
        for (j = 0; j < n * 2; j++) {
            s->input++;
        }
        s->input_count -= n * 2;
    }
    return value;
}
