typedef unsigned char u8;typedef short s16;typedef float f32;typedef struct {f32 value[3];} V3;typedef struct {V3 values[3];} Row;
typedef struct {u8 pad0[5];u8 phase;u8 pad6[0x1c-6];s16 timer;u8 pad1e[2];u8 selector,alt,pad22,group;u8 pad24[0x10];V3 pos;u8 pad40[0x10];V3 scale;} Object;
extern Row data_f32v3x3_004B1730[];extern f32 data_f32_one_004B18E0[3];
extern void func_0013DFB0(int,V3 *),func_001E3CE0(int);
/* Provisional: this independently matched local copy duplicates the global helper. */
static void func_0013DB00(u8 *owner, int duration, int segment)
{
    V3 *start, *end;
    int index = segment + (owner[0x20] + owner[0x23] * 6) * 3;
    start = (V3 *)((u8 *)data_f32v3x3_004B1730 + index * sizeof(V3));
    end = (V3 *)((u8 *)data_f32v3x3_004B1730 + (index + 1) * sizeof(V3));
    {
        f32 ratio = (end->value[0] - start->value[0]) / duration;
        *(f32 *)(owner + 0x34) = start->value[0] + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->value[1] - start->value[1]) / duration;
        *(f32 *)(owner + 0x38) = start->value[1] + *(s16 *)(owner + 0x1C) * ratio;
    }
    {
        f32 ratio = (end->value[2] - start->value[2]) / duration;
        *(f32 *)(owner + 0x3C) = start->value[2] + *(s16 *)(owner + 0x1C) * ratio;
    }
}
void func_0013DDC0(u8 *actor){Object *p=(Object *)actor;s16 previous=p->timer++;
 if(previous!=8){f32 scale=1.0f+0.375f*(8-p->timer);p->scale.value[0]=scale;p->scale.value[1]=scale;func_0013DB00(actor,8,0);}
 else {p->phase++;p->timer=13;p->pos=data_f32v3x3_004B1730[p->selector+p->group*6].values[1];p->scale=*(V3 *)(void *)data_f32_one_004B18E0;func_0013DFB0(0,&p->pos);func_001E3CE0(0x45);}
}
