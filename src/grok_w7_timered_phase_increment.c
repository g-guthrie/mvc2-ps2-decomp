typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_003B1B70(u8 *, int, int);

void func_00303390(u8 *p)
{
    s16 timer;
    u8 frame;

    func_00175700(p);
    timer = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = timer;
    if (timer != 0)
        return;

    frame = p[0x21];
    p[0x21] = frame + 1;
    func_003B1B70(p, 0, frame);

    if (p[0x1B7] != 0)
        goto nonzero_flag;
    *(s16 *)(p + 0x1E) = 8;
    goto countdown;

nonzero_flag:
    *(s16 *)(p + 0x1E) = 12;

countdown:
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 40;
    }
}

extern void func_003A5A00(u8 *, int, int);
void func_002EBF40(u8 *p)
{
    s16 timer;
    u8 frame;

    func_00175700(p);
    timer = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = timer;
    if (timer != 0)
        return;
    frame = p[0x21];
    p[0x21] = frame + 1;
    func_003A5A00(p, 0, frame);
    if (p[0x1B7] != 0)
        goto nonzero_flag;
    *(s16 *)(p + 0x1E) = 8;
    goto countdown;

nonzero_flag:
    *(s16 *)(p + 0x1E) = 12;

countdown:
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 40;
    }
}
