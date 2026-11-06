/* Candidate: func_0c0328a4 (match-start setup) and both pools match except
 * pool offsets; func_0c032a7e (start countdown) hoists the 0xfc9f button mask
 * into r7 at entry, where retail loads it into r3 just before the first AND. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct PlayerSlotScore dat_0c2d7088[];
struct CameraTrack { unsigned char pad0[12]; struct Vec3_tu5_03 eye[2]; unsigned char pad24[0x54 - 0x24]; struct Vec3_tu5_03 target[2]; unsigned char pad6c[0x80 - 0x6c]; float f80; };
extern struct CameraTrack dat_0c2d9260;
extern struct FadeState dat_0c2d93d0;
extern struct ActorInputRecord20 dat_0c2d6f24[];
extern void func_0c037354(void), func_0c0275a4(void), func_0c0268b8(void), func_0c02aa78(void), func_0c02aaac(void);
extern void func_0c027ff0(int), func_0c0343ac(int), func_0c034a1c(int), func_0c0233dc(int), func_0c023a50(void);
extern void func_0c1c910c(void), func_0c1c927a(int), func_0c1c93f6(int, int);
extern void func_0c02a7ea(unsigned int, int, int), func_0c0267c4(void), func_0c0267ce(void), func_0c0275dc(void);
void func_0c0328a4(void)
{
    dat_0c2d6f84->b4++;
    dat_0c2d6f84->s8 = 300;
    dat_0c2d6f84->s14 = 0;
    dat_0c2d6f84->b25 = dat_0c2d6f84->b84 ? 0 : 1;
    if (dat_0c2d7088[0].actor.b52c == 24 && dat_0c2d7088[2].actor.b52c == 24 && dat_0c2d7088[4].actor.b52c == 24) {
        dat_0c2d7088[2].actor.b52c = 25;
        dat_0c2d7088[4].actor.b52c = 26;
    }
    if (dat_0c2d7088[1].actor.b52c == 24 && dat_0c2d7088[3].actor.b52c == 24 && dat_0c2d7088[5].actor.b52c == 24) {
        dat_0c2d7088[3].actor.b52c = 25;
        dat_0c2d7088[5].actor.b52c = 26;
    }
    func_0c037354();
    func_0c0275a4();
    func_0c0268b8();
    func_0c02aa78();
    func_0c02aaac();
    func_0c027ff0(6);
    func_0c0343ac(2);
    func_0c034a1c(68);
    func_0c0233dc(0);
    func_0c023a50();
    dat_0c2d9260.eye[0].x = 0.0f;
    dat_0c2d9260.eye[0].y = 160.0f;
    dat_0c2d9260.eye[0].z = 900.0f;
    dat_0c2d9260.target[0].x = 0.0f;
    dat_0c2d9260.target[0].y = 160.0f;
    dat_0c2d9260.target[0].z = 0.0f;
    dat_0c2d9260.f80 = 0.0f;
    func_0c1c910c();
    func_0c1c927a(0); func_0c1c927a(1); func_0c1c927a(2);
    func_0c1c927a(3); func_0c1c927a(4); func_0c1c927a(5);
    func_0c1c93f6(0, 0); func_0c1c93f6(1, 0); func_0c1c93f6(2, 0);
    func_0c1c93f6(3, 0); func_0c1c93f6(4, 0); func_0c1c93f6(5, 0);
    func_0c1c93f6(0, 1); func_0c1c93f6(1, 1); func_0c1c93f6(2, 1);
    func_0c1c93f6(3, 1); func_0c1c93f6(4, 1); func_0c1c93f6(5, 1);
    func_0c0268b8();
    func_0c02a7ea(-1, 30, 0);
    func_0c0267c4();
    dat_0c2d93d0.enabled = 1;
    dat_0c2d93d0.count = 42;
    dat_0c2d93d0.value = 7000.0f;
    dat_0c2d93d0.red = 255;
    dat_0c2d93d0.green = 255;
    dat_0c2d93d0.blue = 128;
    func_0c0267ce();
}
void func_0c032a7e(void)
{
    int sides;
    struct ActorInputRecord20 *in;
    dat_0c2d6f84->s8--;
    in = dat_0c2d6f24;
    goto L;
L:
    in[0].buttons = in[0].buttons & 0xfc9f;
    in[1].buttons = in[1].buttons & 0xfc9f;
    sides = dat_0c2d6f84->b84;
    if ((sides & 1) && (in[0].buttons & 0x360) || (sides & 2) && (in[1].buttons & 0x360) || dat_0c2d6f84->s8 == 60) {
        dat_0c2d6f84->b4++;
        dat_0c2d6f84->s8 = 60;
        dat_0c2d6f84->s14 = 2;
    }
    if (dat_0c2d6f84->s8 == 150)
        dat_0c2d6f84->s14 = 1;
    dat_0c2d9260.eye[1] = dat_0c2d9260.eye[0];
    dat_0c2d9260.target[1] = dat_0c2d9260.target[0];
    func_0c0275dc();
    func_0c0267ce();
}
