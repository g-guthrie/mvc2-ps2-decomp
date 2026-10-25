#ifndef OWNED_ACTOR_STATES_0044C770_H
#define OWNED_ACTOR_STATES_0044C770_H
/* Four lifecycle entries precede 57 modes that receive the actor's owner. */
typedef void (*OwnedActorLifecycleCallback)(unsigned char *);
typedef void (*OwnedActorModeCallback)(unsigned char *, unsigned char *);
typedef struct {
    OwnedActorLifecycleCallback lifecycle[4];
    OwnedActorModeCallback mode[57];
} OwnedActorStateTables;
extern const OwnedActorStateTables jtbl_0044C770;
extern const OwnedActorModeCallback jtbl_0044C780[57];
extern const OwnedActorModeCallback jtbl_0044C868[3];
void func_001C0A90(unsigned char *);
void func_001C0C30(unsigned char *);
void func_001C1300(unsigned char *);
void func_001C1320(unsigned char *);
void func_001C0C60(unsigned char *, unsigned char *);
void func_001C0CC0(unsigned char *, unsigned char *);
void func_001C0D20(unsigned char *, unsigned char *);
void func_001C0D90(unsigned char *, unsigned char *);
void func_001C0E20(unsigned char *, unsigned char *);
void func_001C0EF0(unsigned char *, unsigned char *);
void func_001C0F70(unsigned char *, unsigned char *);
void func_001C0FF0(unsigned char *, unsigned char *);
void func_001C1160(unsigned char *, unsigned char *);
void func_001C1250(unsigned char *, unsigned char *);
void func_001C12B0(unsigned char *, unsigned char *);
void func_001C1010(unsigned char *, unsigned char *);
void func_001C1080(unsigned char *, unsigned char *);
void func_001C1100(unsigned char *, unsigned char *);
void func_001C1330(unsigned char *, unsigned char *);
#endif
