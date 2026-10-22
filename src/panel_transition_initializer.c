typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
typedef struct {V3 from,to;} MotionPair;
typedef struct {u8 pad00[0x34]; V3 position; u8 pad40[0x10]; V3 scale,velocity,target;} PanelFields;
extern MotionPair D_0043EAF0[];
extern u8 D_004D18A6[];
extern u32 D_004C2834;
void func_00135910(u8 *p)
{
    PanelFields *v=(PanelFields*)p;
    if(D_004D18A6[0]!=(*(u8**)(p+0x14))[2]+1)return;
    p[4]++;
    p[0x13C]=1;
    *(u32*)(p+0xD0)=0x15;
    if(p[0x20]==0) {
        float start=47.0f,target=150.0f,duration=15.0f;
        *(s16*)(p+0xCC)=108;
        *(u32*)(p+0x84)=D_004C2834;
        v->position.y=-70.0f;
        v->position.z=-200.0f;
        v->scale.x=2.0f;
        v->scale.y=2.0f;
        v->scale.z=1.0f;
        v->position.x=start*(float)(1-2*(*(s16*)(p+0x140)));
        v->target.x=target*(float)(1-2*(*(s16*)(p+0x140)));
        *(u32*)(p+0x44)=(1u-*(s16*)(p+0x140))<<15;
        *(s16*)(p+0x1C)=9;
        v->velocity.x=(v->target.x-v->position.x)/duration;
        v->velocity.y=4.666666507720947265625f;
    } else {
        int palette;
        u8 alternate;
        v->scale.x=2.0f;
        v->scale.y=2.0f;
        v->scale.z=1.0f;
        palette=p[0x1B8];
        *(s16*)(p+0xCC)=109+palette/2;
        *(u32*)(p+0x84)=D_004C2834;
        alternate=0;
        if(*(s8*)(*(u8**)(p+0x18)+0x26D)!=3)alternate=1;
        v->position=D_0043EAF0[p[0x21]+alternate].from;
        v->target=D_0043EAF0[p[0x21]+alternate].to;
        if(*(s16*)(p+0x140)==0) {
            v->position.x=-v->position.x;
            v->target.x=-v->target.x;
        }
        *(s16*)(p+0x1C)=10;
        *(u32*)(p+0x44)=(1u-*(s16*)(p+0x140))<<15;
        v->velocity.x=(v->target.x-v->position.x)/10.0f;
        v->velocity.y=(v->target.y-v->position.y)/10.0f;
        v->velocity.z=(v->target.z-v->position.z)/10.0f;
    }
}
