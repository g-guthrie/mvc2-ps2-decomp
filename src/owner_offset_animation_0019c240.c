/* Place the effect using signed table offsets and choose its animation by index parity. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef signed short s16;
extern s16 D_0044A8E0[][2],D_0044A8E2[][2];
extern int func_001757E0(u8 *,int,int);
extern void func_0019C420(u8 *);
void func_0019C240(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 x;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    p->visible=1;p->layer=7;
    p->position.x=((Actor*)*(u8**)(actor+0x18))->position.x;
    p->position.y=((Actor*)*(u8**)(actor+0x18))->position.y;
    x=1.66666662693023681640625f*(f32)D_0044A8E0[p->choice][0];
    if(*(s16*)(*(u8**)(actor+0x18)+0x140))x=-x;
    p->position.x+=x;
    p->position.y+=2.142857074737548828125f*(f32)D_0044A8E2[p->choice][0];
    if(p->choice&1)func_001757E0(actor,20,1);else func_001757E0(actor,20,0);
    func_0019C420(actor);
}
