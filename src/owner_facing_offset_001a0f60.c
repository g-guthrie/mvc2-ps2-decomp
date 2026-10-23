/* Inherit the supplied owner state and position, preserve its facing byte, and select the offset animation. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;u8 pad5C[0xE0],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
void func_001A0F60(u8 *actor,u8 *owner)
{
    Actor *p=(Actor*)actor,*q=(Actor*)owner;
    s32 n;
    s32 *d;
    s32 *s;
    s = (s32 *)(owner + 0xEC);
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = owner[2];
    actor[1] = owner[1];
    p->scale.x = q->scale.x;
    p->scale.y = q->scale.y;
    p->mode = q->mode;
    p->variant = q->variant;
    p->group = q->group;
    p->scale = q->scale;
    p->layer = q->layer;
    ++p->phase;p->layer=0;
    p->position=q->position;
    p->savedFacing=(s8)p->facing;
    {u32 selection=q->choice;
     if(p->facing) {
      p->position.x+=266.666656494140625f;
      selection+=3;
      p->facing=0;
     }
     func_001757E0(actor,23,(u8)(selection+26));
    }
}
