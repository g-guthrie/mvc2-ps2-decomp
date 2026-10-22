typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef struct MotionActor MotionActor;
struct MotionActor {
    u8 unknown00[3];u8 state3,state4;
    u8 unknown05[0xF];MotionActor *parent;
    u8 unknown18[0xA];u8 attached;
    u8 unknown23[0x11];float x;
    u8 unknown38[0x24];float vx;
    u8 unknown60[8];float ax;
    u8 unknown6C[0xD0];s8 active;
};
extern u16 D_004D18DC;
extern u8 D_004D18DB;
void func_001A4A80(u8 *actor_data, u8 *owner, u8 *work)
{
    MotionActor *p=(MotionActor*)actor_data;
    if ((D_004D18DC & (1u << D_004D18DB)) != 0)return;
    p->x=p->parent->x;
    if(p->attached!=0) {
        p->x+=p->vx;
    } else {
        p->x+=p->vx;
        p->vx+=p->ax;
        if(!(p->vx*p->ax<0.0f)) {
            p->state4=2;
            p->active=0;
            p=p->parent;
            if(p->state3==0) *(s8*)(work+4)=-1;
            else p->attached=0;
        }
    }
}
