typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

typedef struct Event {
    u8 pad00[16];
    void (*callback)(u8 *);
    u8 pad14[4];
    void *arg;
} Event;

extern Event *func_003DA750(s32, s32, s32);
extern void func_00344180(u8 *);
extern void func_00346E70(u8 *);
extern void func_00347AF0(u8 *);
extern void func_00347DD0(u8 *);
extern void func_0034CF30(void);
extern void func_0034CF60(void);
extern void func_003422F0(s32);
extern void func_00359A90(u8 *);
extern void func_00359AE0(u8 *);
extern void func_00359B80(u8 *);
extern void func_00359BD0(u8 *);
extern void func_00359C20(u8 *);

void func_003446C0(void)
{
    Event *e = func_003DA750(0, 6, 0);
    if (e != 0)
        e->callback = func_00344180;
}

void func_00346E20(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00346E70;
        e->arg = arg;
    }
}

void func_00347AA0(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00347AF0;
        e->arg = arg;
    }
}

void func_00347D80(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00347DD0;
        e->arg = arg;
    }
}

void func_0034D300(void)
{
    func_0034CF30();
    func_0034CF60();
}
