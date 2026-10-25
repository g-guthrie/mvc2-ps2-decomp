typedef unsigned char u8;typedef unsigned int u32;
typedef struct V3 {float x,y,z;} V3;
typedef struct {
 u8 preKey[7],key,prePhase[0x1B],phase,preDelta[0x2C];
 V3 delta;float movementX,movementY;u8 reserved64[4];float movementZ;u8 preCurrent[0xC];V3 current;u8 preTimer[0x58];u32 timer;
} Transition;
extern V3 D_004B3ED0[3],D_004B3F80[3],D_004B3FB0[3];
extern void func_001615D0(u8*),func_00161820(u8*),func_00161A70(u8*);

void func_00161530(u8*raw){
 Transition *p=(Transition*)raw;
 V3*target=D_004B3ED0;
 p->key++;
 p->key=(u32)p->key%3;
 target+=p->key;
 p->delta.x=(target->x-p->current.x)/20.0f;
 p->delta.y=(target->y-p->current.y)/20.0f;
 p->delta.z=(target->z-p->current.z)/20.0f;
 p->timer=20;p->phase++;
 func_001615D0(raw);
}

void func_00161780(u8*raw){
 Transition *p=(Transition*)raw;
 V3*target=D_004B3F80;
 p->key++;
 p->key=(u32)p->key%3;
 target+=p->key;
 p->delta.x=(target->x-p->current.x)/20.0f;
 p->delta.y=(target->y-p->current.y)/20.0f;
 p->delta.z=(target->z-p->current.z)/20.0f;
 p->timer=20;p->phase++;
 func_00161820(raw);
}

void func_001619D0(u8*raw){
 Transition *p=(Transition*)raw;
 V3*target=D_004B3FB0;
 p->key++;
 p->key=(u32)p->key%3;
 target+=p->key;
 p->movementX=(target->x-p->current.x)/20.0f;
 p->movementY=(target->y-p->current.y)/20.0f;
 p->movementZ=(target->z-p->current.z)/20.0f;
 p->timer=20;p->phase++;
 func_00161A70(raw);
}
