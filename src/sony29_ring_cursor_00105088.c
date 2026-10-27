#include "sony_console_ring.h"
typedef SonyConsoleRing RingCursor;

void func_00105088(RingCursor *ring)
{
    ring->count--;
    ring->head++;
    if (ring->head == (char *)ring + (ring->size + 16))
        ring->head = (char *)ring + 16;
}
