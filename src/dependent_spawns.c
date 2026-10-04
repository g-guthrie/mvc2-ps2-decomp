/* Create active callback objects with a reference to the parent data. */
typedef unsigned char u8;
extern u8 *func_003DA750(void *,int,int);
extern int D_004C2838;
extern void func_00154BF0(u8 *);
extern void func_00154CF0(u8 *);
extern void func_00156830(u8 *);
extern void func_00156930(u8 *);
extern void func_0015C940(u8 *);
extern void func_0015CA60(u8 *);
extern void func_0015CB80(u8 *);
extern void func_0015CCA0(u8 *);
extern void func_0015CDC0(u8 *);

#define DEPENDENT_SPAWN(name,matched_kind,other_kind,callback,tag,flags) \
u8 *name(u8 *parent,int source_kind) { \
 int kind; \
 u8 *object; \
 if ((u8)source_kind == 9) kind=matched_kind; \
 else kind=other_kind; \
 object=func_003DA750(0,(u8)kind,1); \
 if (object) { \
  object[0x13c]=1; \
  *(void (**)(u8 *))(object+0x10)=callback; \
  *(unsigned short *)(object+0xcc)=tag; \
  *(int *)(object+0x84)=D_004C2838; \
  *(unsigned int *)(object+0xd0)=flags; \
  *(u8 **)(object+0xc8)=parent+0x88; \
 } \
 return object; \
}

DEPENDENT_SPAWN(func_00154B60, 20, 56, func_00154BF0, 82, 0x00800400u)
DEPENDENT_SPAWN(func_00154C60, 21, 57, func_00154CF0, 83, 0x00800400u)
DEPENDENT_SPAWN(func_001567A0, 20, 56, func_00156830, 82, 0x00800400u)
DEPENDENT_SPAWN(func_001568A0, 21, 57, func_00156930, 83, 0x00800410u)
DEPENDENT_SPAWN(func_0015C8B0, 31, 67, func_0015C940, 124, 0x00800410u)
DEPENDENT_SPAWN(func_0015C9D0, 31, 67, func_0015CA60, 125, 0x00800410u)
DEPENDENT_SPAWN(func_0015CAF0, 31, 67, func_0015CB80, 126, 0x00800410u)
DEPENDENT_SPAWN(func_0015CC10, 31, 67, func_0015CCA0, 127, 0x00800410u)
DEPENDENT_SPAWN(func_0015CD30, 31, 67, func_0015CDC0, 128, 0x00800413u)
