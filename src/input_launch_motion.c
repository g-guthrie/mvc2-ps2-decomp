/* Native input bits choose exactly three four-halfword launch presets. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct {
    u8 unknown00[6];u8 state6,state7;
    u8 unknown08[0x54];float vx,vy;
    u8 unknown64[4];float ax,ay;
    u8 unknown70[0x176];u8 facing;s8 direction;
    u8 unknown1E8[0x25];u8 state20D;
    u8 unknown20E[2];u8 flag210;
    u8 unknown211[0x14D];u16 input;
} MotionActor;
extern s16 data_u32_004489C0[16];
void func_00178BE0(u8 *data)
{
    MotionActor *p=(MotionActor*)data;
    u16 input;
    s16 *preset;
    float vertical=2.142857074737548828125f;
    float horizontal=1.66666662693023681640625f;
    p->state6=3;
    p->state7=0;
    p->flag210=0;
    p->state20D=2;
    input=p->input;
    if ((input&0xC00)==0) p->direction=-1;
    else if(input&0x800) p->direction=0;
    else p->direction=1;
    preset=data_u32_004489C0;
    preset+=4*(p->direction+1);
    p->vy=(vertical*(float)preset[0])/256.0f;
    p->ay=(vertical*(float)preset[1])/256.0f;
    p->vx=(horizontal*(float)preset[2])/256.0f;
    p->ax=(horizontal*(float)preset[3])/256.0f;
    if(p->facing!=0) {
        p->vx=-p->vx;
        p->ax=-p->ax;
    }
}
