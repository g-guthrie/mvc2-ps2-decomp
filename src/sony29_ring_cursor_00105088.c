typedef struct { int size; int count; char *cur; } RingCursor;

void func_00105088(RingCursor *ring)
{
    ring->count--;
    ring->cur++;
    if (ring->cur == (char *)ring + (ring->size + 16))
        ring->cur = (char *)ring + 16;
}
