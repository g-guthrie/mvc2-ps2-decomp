struct Velocity {char pad[0x5c];float velocity;char pad2[8];float acceleration;};
extern void use(struct Velocity*);
#pragma inline(one)
static float one(void){return 1.0f;}
void context(struct Velocity*a){use(a);{float factor=one();factor+=factor;a->velocity/=factor;a->acceleration/=factor;}}
void literal_control(struct Velocity*a){use(a);a->velocity/=2.0f;a->acceleration/=2.0f;}
