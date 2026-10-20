/* Enter the selected input motion and choose its signed horizontal velocity. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct ActorInputMotion {
 u8 unknown00[7]; u8 state;
 u8 unknown08[0x5C-8]; f32 vx, vy;
 u8 unknown64[4]; f32 ax, ay;
 u8 unknown70[0x140-0x70]; s16 frame;
 u8 unknown142[0x1E7-0x142]; s8 direction;
 u8 unknown1E8[0x20D-0x1E8]; u8 flag20D;
 u8 unknown20E[2]; u8 flag210;
 u8 unknown211[0x354-0x211]; u16 buttons354;
 u8 unknown356[6]; u16 buttons35C; u16 buttons35E;
} ActorInputMotion;

extern int func_001757E0(u8 *, int, int);

int func_00267C90(u8 *buffer, int alt)
{
    ActorInputMotion *p = (ActorInputMotion *)buffer;
    u16 bits;
    int ok = 1;
    if (alt)
        bits = p->buttons35C;
    else
        bits = p->buttons354;
    if (!(bits & 0xC00))
        return 0;
    p->state = ok;
    p->vx = 0.0f;
    p->vy = 0.0f;
    p->ax = 0.0f;
    p->ay = 0.0f;
    p->flag210 = 0;
    p->flag20D = 0;
    p->direction = (u8)((p->buttons35E & 0x400) >> 10);
    func_001757E0((u8 *)p, 0x16, (p->direction + 0x1D) & 0xFF);
    if (p->frame == 0) {
        p->vx = -5.625f;
        if (p->direction)
            p->vx = -p->vx;
    } else {
        p->vx = 5.625f;
        if (p->direction)
            p->vx = -p->vx;
    }
    return ok;
}
