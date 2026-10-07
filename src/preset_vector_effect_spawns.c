/* Spawn an effect with the owner position and its preset scale vector. */
typedef unsigned char u8;
#include "mvc2_effect_vectors.h"
typedef Mvc2EffectVector Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern void func_00156D00(u8 *);
extern Mvc2EffectVector D_00444C60;
void func_00156D70(u8 *owner) {
    u8 *p=func_003DA750(0,0x33,0x1);
    if (p) {
        p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00156D00;
        *(short *)(p+0xcc)=0x18; *(void **)(p+0x84)=D_004C2838;
        *(Vec3 *)(p+0x34)=*(Vec3 *)(owner+0x34);
        *(Vec3 *)(p+0x50)=D_00444C60;
        *(int *)(p+0xd0)=0x800191;
    }
}
extern void func_00158280(u8 *);
extern Mvc2EffectVector D_00444D10;
void func_00158470(u8 *owner) {
    u8 *p=func_003DA750(0,0x20,0x1);
    if (p) {
        p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00158280;
        *(short *)(p+0xcc)=0x3E; *(void **)(p+0x84)=D_004C2838;
        *(Vec3 *)(p+0x34)=*(Vec3 *)owner;
        *(Vec3 *)(p+0x50)=D_00444D10;
        *(int *)(p+0xd0)=0x800031;
    }
}
extern void func_00158510(u8 *);
extern Mvc2EffectVector D_00444D10;
void func_00158710(u8 *owner) {
    u8 *p=func_003DA750(0,0x20,0x1);
    if (p) {
        p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00158510;
        *(short *)(p+0xcc)=0x3F; *(void **)(p+0x84)=D_004C2838;
        *(Vec3 *)(p+0x34)=*(Vec3 *)owner;
        *(Vec3 *)(p+0x50)=D_00444D10;
        *(int *)(p+0xd0)=0x800039;
    }
}
extern void func_001587B0(u8 *);
extern Mvc2EffectVector D_00444D10;
void func_001589A0(u8 *owner) {
    u8 *p=func_003DA750(0,0x20,0x1);
    if (p) {
        p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_001587B0;
        *(short *)(p+0xcc)=0x40; *(void **)(p+0x84)=D_004C2838;
        *(Vec3 *)(p+0x34)=*(Vec3 *)owner;
        *(Vec3 *)(p+0x50)=D_00444D10;
        *(int *)(p+0xd0)=0x800039;
    }
}
extern void func_00158A40(u8 *);
extern Mvc2EffectVector D_00444D10;
void func_00158BD0(u8 *owner) {
    u8 *p=func_003DA750(0,0x20,0x1);
    if (p) {
        p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00158A40;
        *(short *)(p+0xcc)=0x41; *(void **)(p+0x84)=D_004C2838;
        *(Vec3 *)(p+0x34)=*(Vec3 *)owner;
        *(Vec3 *)(p+0x50)=D_00444D10;
        *(int *)(p+0xd0)=0x800039;
    }
}
