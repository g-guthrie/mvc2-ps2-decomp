typedef unsigned char u8;
typedef struct {
    u8 unknown00[5];u8 state;
    u8 unknown06[0x32];float y;
    u8 unknown3C[0x1A8];u8 action;
    u8 unknown1E5[0x28];u8 mode;
    u8 unknown20E[0x12];u8 *opponent;
    u8 unknown224[0x20C];float floor;
} EligibilityActor;
extern float D_004F1FE0;
extern u8 D_00448FB0[];
int func_0018A6C0(u8 *actor_data)
{
    EligibilityActor *p=(EligibilityActor*)actor_data;
    u8 action;
    if(p->state!=0)return 0;
    action=p->action;
    if(action==0x15)return 0;
    if(action==0x1C)return 0;
    if(p->opponent[0x249]!=0)return 0;
    if(p->mode==2) {
        if(p->y<=p->floor)return 0;
        if(!(p->y < D_004F1FE0 - 68.5714263916015625f))return 0;
    }
    if(D_00448FB0[action]!=0)return 0;
    return 1;
}
