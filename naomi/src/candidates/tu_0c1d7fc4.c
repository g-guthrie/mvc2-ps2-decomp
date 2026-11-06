/* The timer update is 22/26 bytes; SHC schedules the limit load after the
 * frame load, while retail places it before. */
struct AnimationTimer_0c1d7fc4 {
    unsigned char pad0[4];
    unsigned char state;
    unsigned char pad5[23];
    short frame;
};

#pragma section N1d7fc4
void func_0c1d7fc4(void *unused, struct AnimationTimer_0c1d7fc4 *timer)
{
    if (++timer->frame >= 8) {
        timer->state = 3;
        timer->frame = 7;
    }
}
