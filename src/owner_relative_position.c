typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {s16 x,y;s8 effect;u8 animation;} AnimationStateRecord;
extern AnimationStateRecord D_0044C0E0[34];
extern u8 D_004D18A6[];
extern int func_00175670(u8 *);
void func_001BD7D0(u8 *p,void *owner_context)
{
    u8 *owner=(u8 *)owner_context;
    AnimationStateRecord *row;
    int facing;
    if(owner[0x1E4]!=0x1D || owner[0x1FD]!=3) {
        p[4]++;
        p[0x13C]=0;
        return;
    }
    if(D_004D18A6[0]&(1u<<(owner[2]^1)))return;
    if((s8)func_00175670(p)<0) {
        p[4]++;
        p[0x13C]=0;
        return;
    }
    row=&D_0044C0E0[p[0x20]];
    facing=*(s16*)(owner+0x140);
    *(s16*)(p+0x140)=facing;
    if(facing==0)
        *(float*)(p+0x34)=*(float*)(owner+0x34)+1.66666662693023681640625f*(float)row->x;
    else
        *(float*)(p+0x34)=*(float*)(owner+0x34)-1.66666662693023681640625f*(float)row->x;
    *(float*)(p+0x38)=*(float*)(owner+0x38)+2.142857074737548828125f*(float)row->y;
}
