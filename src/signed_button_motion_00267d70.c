typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct ActorMotion_00267D70 {
    u8 pad00[0x5C];
    f32 speedX;
    f32 speedY;
    u8 pad64[4];
    f32 accelX;
    f32 accelY;
    u8 pad70[0x140 - 0x70];
    s16 orientation;
    u8 pad142[0x1E7 - 0x142];
    s8 direction;
    u8 pad1E8[0x20D - 0x1E8];
    u8 state20D;
    u8 pad20E[2];
    u8 mode210;
    u8 pad211[0x354 - 0x211];
    u16 buttons354;
    u8 pad356[6];
    u16 buttons35C;
    u16 buttons35E;
} ActorMotion_00267D70;

/* Native caller func_00266F80 passes the actor and zero as the button selector. */
s32 func_00267D70(u8 *actor, s32 useSecondButtonWord)
{
    ActorMotion_00267D70 *p = (ActorMotion_00267D70 *)actor;
    u16 buttons;

    if (useSecondButtonWord != 0)
        buttons = p->buttons35C;
    else
        buttons = p->buttons354;
    if ((buttons & 0xC00) == 0)
        return 0;

    p->speedX = 0.0f;
    p->speedY = 0.0f;
    p->accelX = 0.0f;
    p->accelY = 0.0f;
    p->mode210 = 0;
    p->state20D = 0;
    p->direction = (s8)((p->buttons35E & 0x400) >> 10);

    if (p->orientation == 0) {
        p->speedX = -5.625f;
        if (p->direction != 0)
            p->speedX = -p->speedX;
    } else {
        p->speedX = 5.625f;
        if (p->direction != 0)
            p->speedX = -p->speedX;
    }
    return 1;
}
