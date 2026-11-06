/* SDK byte-stream opcode handlers reached through the function-pointer
 * tables at 0x0c269460-0x0c2697dc. */
#include "objects.h"

#pragma section n20068c
int func_0c20068c(struct SdkByteConsumer *s)
{
    s->output++;
    s->output_count--;
    s->output++;
    s->output_count--;
    return 1;
}

#pragma section n20075c
unsigned int func_0c20075c(struct SdkByteConsumer *s)
{
    unsigned int value = *s->input;
    s->input++;
    s->input_count--;
    s->output++;
    s->output_count--;
    if (value != 2) {
        s->input++;
        s->input_count--;
    }
    return value;
}

#pragma section n200936
unsigned int func_0c200936(struct SdkByteConsumer *s)
{
    unsigned int value = *s->input;
    s->input++;
    s->input_count--;
    s->output++;
    s->output_count--;
    s->output += 3;
    s->output_count -= 3;
    return value;
}

#pragma section n200962
int func_0c200962(struct SdkByteConsumer *s)
{
    unsigned char c;
    s->input++;
    s->input_count--;
    s->output++;
    s->output_count--;
    c = *s->output;
    s->output += c * 2;
    s->output_count -= c * 2;
    return 1;
}
