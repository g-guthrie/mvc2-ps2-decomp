/* Candidate: 19/21 complete functions match. Two functions retain copy
 * scheduling, scratch register, and shared literal placement differences. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c153ac4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void (*table_0c244ae0[])(struct Actor *);
void func_0c0b148e(struct Actor *);
void func_0c0b130c(struct Actor *a)
{
    a->b1fc = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0442fa(a);
    func_0c0432ca(a);
}
void func_0c0b1346(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) a->f56 = a->f41c;
}
void func_0c0b1396(struct Actor *a) { table_0c244ae0[a->b6](a); }
void func_0c0b13a8(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f92 /= 16.0f;
    a->f96 /= 8.0f;
    a->f108 /= 64.0f;
    a->f104 = 0;
    if (a->b1f9 == 2) {
        if (!a->b1a3) func_0c02a0c4(a, 21, 2);
        else func_0c02a0c4(a, 21, 3);
    }
    else {
        func_0c0b130c(a);
        if (!a->b1a3) func_0c02a0c4(a, 21, 0);
        else func_0c02a0c4(a, 21, 1);
    }
    func_0c0b148e(a);
}
void func_0c0b148e(struct Actor *a)
{
    func_0c0b1346(a);
    if (a->b141) { func_0c153ac4(a); a->b141 = 0; }
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2) {
            a->f96 = 0;
            a->f108 = 0;
            func_0c0438de(a);
        } else func_0c0437b8(a);
    }
}

extern void (*table_0c244ae8[])(struct Actor *);
extern void (*table_0c244af4[])(struct Actor *);
extern void func_0c1544e8(struct Actor *, int);
extern float dat_0c2d926c;
void func_0c0b14e4(struct Actor *a) { table_0c244ae8[a->b6](a); }
void func_0c0b14f6(struct Actor *a)
{
    a->b6++;
    func_0c0b130c(a);
    a->b1a1 = 49;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 4);
}
void func_0c0b1542(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        func_0c1544e8(a, 0);
        func_0c1544e8(a, 1);
        func_0c1544e8(a, 2);
        func_0c1544e8(a, 3);
    }
}
void func_0c0b1584(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { func_0c0437b8(a); return; }
    if (a->b141) {
        a->b1a1 = a->b141 + 48;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b141 = 0;
    }
}
void func_0c0b1602(struct Actor *a) { table_0c244af4[a->b6](a); }
void func_0c0b1614(struct Actor *a)
{
    float table[2][2]={{19.2857132f,-0.80357140303f},{19.2857132f,-0.80357140303f}};
    float position;
    a->b6++;
    a->b1a1 = a->b1a3 + 54;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c0b130c(a);
    position = a->b1d2 ? dat_0c2d926c + -320.0f : dat_0c2d926c + 320.0f;
    a->f92 = (position - a->f52) / 32.0f;
    a->f104 = 0;
    a->f96 = table[(unsigned char)a->b1a3][0];
    a->f108 = table[(unsigned char)a->b1a3][1];
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, a->b1a3 + 12);
}

#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0b130c(struct Actor *);
extern void func_0c1a44e4(struct Actor *, int);
extern float dat_0c2d926c;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ActorMotionFloat2 dat_0c244b10[];
extern struct Vec3_tu5_03 dat_0c244b20[];
extern void (*table_0c244b38[])(struct Actor *);
extern void (*table_0c244b40[])(struct Actor *);
void func_0c0b1b86(struct Actor *);
void func_0c0b1718(struct Actor *a)
{
 float *position = (float *)&a->sub2a4;
 func_0c02a026(a);
 if (!a->b141) {
  a->b6++;
  func_0c0451f2(a);
  a->b1d2 = a->w130 = a->b1d2 ^ 1;
  *position = dat_0c2d926c;
 }
}
void func_0c0b1764(struct Actor *a)
{
 float *position = (float *)&a->sub2a4;
 a->f52 += dat_0c2d9260.f12 - *position;
 *position = dat_0c2d9260.f12;
 func_0c02a026(a);
 a->f52 += a->f92; a->f92 += a->f104;
 a->f56 += a->f96; a->f96 += a->f108;
 if (!(a->f56 > a->f41c)) { func_0c0b1b86(a); return; }
 if (!(a->f41c + 222.857132f > a->f56) && a->b1fd) {
  a->b6++;
  a->b1d2 = a->w130 = a->b1d2 ^ 1;
  func_0c02a0c4(a,21,a->b1a3+14);
 }
}
void func_0c0b1826(struct Actor *a)
{
 a->f52 = a->b1d2 ? dat_0c2d926c + -320.0f : dat_0c2d926c + 320.0f;
 func_0c02a026(a);
 if (!a->b141) {
  a->b6++;
  a->s28=a->b1a3 ? 3 : 3; a->s30=0; a->b34=0;
  a->b1a1=a->b1a3 ? 57 : 54;
  a->w1ac=0; a->b19e=0; a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  a->f92=0; a->f96=0; a->f104=0; a->f108=0;
  a->f92=a->b1d2 ? dat_0c244b10[(unsigned char)a->b1a3].x : -dat_0c244b10[(unsigned char)a->b1a3].x;
  a->f96=dat_0c244b10[(unsigned char)a->b1a3].y;
  if (a->b1a3) a->i72=0xf200;
  func_0c1a44e4(a,0);
 }
}
void func_0c0b1940(struct Actor *a)
{
 if (a->b19e && !a->s30) {
  a->s30=1; a->b34++;
  if (--a->s28==0) {
   a->b6++;
   a->f92=a->b1d2 ? dat_0c244b20[(unsigned char)a->b1a3].x : -dat_0c244b20[(unsigned char)a->b1a3].x;
   a->f104=0;
   a->f96=dat_0c244b20[(unsigned char)a->b1a3].y;
   a->f108=dat_0c244b20[(unsigned char)a->b1a3].z;
   a->i72=0;
   func_0c02a0c4(a,21,a->b1a3+16);
   func_0c1a44e4(a,1);
   return;
  }
 }
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 if (!(a->f56>a->f41c)) { a->i72=0; func_0c0b1b86(a); return; }
 func_0c02a026(a);
 if (a->b141) {
  a->b1a1=(a->b1a3 ? 57 : 54)+(char)a->b34;
  a->w1ac=0; a->b19e=0; a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  a->b141=0; a->s30=0;
 }
}
void func_0c0b1af8(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 if (!(a->f56>a->f41c)) func_0c0b1b86(a);
}
void func_0c0b1b54(struct Actor *a)
{
 if (func_0c02a026(a)<0) {
  a->f92=0; a->f96=0; a->f104=0; a->f108=0;
  func_0c0437b8(a);
 }
}
void func_0c0b1b86(struct Actor *a)
{
 a->b6=6; a->b1f9=0; a->f56=a->f41c;
 func_0c043324(a);
 func_0c02a0c4(a,21,a->b1a3+18);
}
void func_0c0b1bb6(struct Actor *a) { table_0c244b38[a->b6](a); }
void func_0c0b1bc8(struct Actor *a) { table_0c244b40[a->b7](a); }
void func_0c0b1bda(struct Actor *a)
{
 a->b7++; a->b1a1=71;
 a->w1ac=0; a->b19e=0; a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,5); func_0c0442fa(a); func_0c0b130c(a);
 func_0c02a0c4(a,21,20);
}
