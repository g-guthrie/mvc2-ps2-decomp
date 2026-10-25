typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 pad0[0x34];
    f32 x, y;
    u8 pad3c[0x20];
    f32 vx, vy;
    u8 pad64[4];
    f32 ax, ay;
    u8 pad70[0x28];
    f32 targetX, targetY, baseX, baseY;
} MotionState;
typedef struct { u8 prefix[0x34]; f32 x, y; } OwnerPosition;
extern int func_00175670(u8 *);
extern void func_001975C0(u8 *, u8 *);
/* The GP phase group at 0x004BF598 consumes actor and owner. */
void func_001971B0(u8 *p, u8 *q)
{
    MotionState *m = (MotionState *)p;
    u8 *bounds;
    OwnerPosition *owner = (OwnerPosition *)q;
    m->targetX = m->baseX + owner->x;
    m->targetY = m->baseY + owner->y;
    bounds = p + 0x88;
    if (m->vy <= 0.0f) goto low_y;
    {
        f32 gap = *(f32 *)(bounds + 0x14) - m->y;
        if (!(gap <= 0.0f) && m->ay < 0.0f)
            m->ay = -m->ay;
        gap = *(f32 *)(bounds + 0x14) - m->y;
        if (gap < 0.0f && !(m->ay <= 0.0f))
            m->ay = -m->ay;
    }
    goto adjusted_y;
low_y:
    {
        f32 gap = *(f32 *)(bounds + 0x14) - m->y;
        if (gap < 0.0f && !(m->ay <= 0.0f))
            m->ay = -m->ay;
    }
adjusted_y:
    if (m->vx < 0.0f) {
        f32 gap = *(f32 *)(bounds + 0x10) - m->x;
        if (!(gap <= 0.0f) && m->ax < 0.0f)
            m->ax = -m->ax;
        gap = *(f32 *)(bounds + 0x10) - m->x;
        if (gap < 0.0f && !(m->ax <= 0.0f))
            m->ax = -m->ax;
    } else {
        f32 gap = *(f32 *)(bounds + 0x10) - m->x;
        if (gap < 0.0f && !(m->ax <= 0.0f))
            m->ax = -m->ax;
    }
    m->x += m->vx;
    m->vx += m->ax;
    m->y += m->vy;
    m->vy += m->ay;
    func_00175670(p);
    func_001975C0(p, (u8 *)owner);
}
