struct InputLatch_0c13fe8c {
    unsigned char pad[14];
    unsigned char held;
    unsigned char released;
};

#pragma section N13fe8c
unsigned int func_0c13fe8c(struct InputLatch_0c13fe8c *state,
                            unsigned char held, unsigned char released)
{
    if (state->held)
        return state->held;
    state->held = held;
    state->released = released;
    return 0;
}
