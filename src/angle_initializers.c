/* Select alternating rotation vectors and prepare their per-frame changes. */
typedef unsigned char u8;
typedef struct Vector3 { float x,y,z; } Vector3;
extern Vector3 D_004B8080[];
extern Vector3 D_004B80A0[];
extern Vector3 D_004B80D0[];
extern Vector3 D_004B8100[];
extern Vector3 D_004B8130[];
extern Vector3 D_004B81D0[];
extern Vector3 D_004B8200[];
extern float D_00583C28;
extern float D_00583C38;
extern float D_00583C48;
extern float D_00583C58;
extern float D_00583C68;
extern float D_00583C78;
extern float D_00583C88;
extern float D_00583C2C;
extern float D_00583C30;
extern float D_00583C3C;
extern float D_00583C40;
extern float D_00583C4C;
extern float D_00583C50;
extern float D_00583C5C;
extern float D_00583C60;
extern float D_00583C6C;
extern float D_00583C70;
extern float D_00583C7C;
extern float D_00583C80;
extern float D_00583C8C;
extern float D_00583C90;
extern void func_00338280(u8 *);
extern void func_00338670(u8 *);
extern void func_00338B30(u8 *);
extern void func_00338D70(u8 *);
extern void func_00339230(u8 *);
extern void func_00339A00(u8 *);
extern void func_00339C40(u8 *);

#define ANGLE_INIT(name,vectors,duration,step_x,step_y,step_z,update) \
void name(u8 *p) { \
 *(Vector3 *)(p+0x5c)=vectors[p[5]]; \
 ++p[5];p[5]&=1; \
 *(Vector3 *)(p+0x68)=vectors[p[5]]; \
 step_x=(*(float *)(p+0x68)-*(float *)(p+0x5c))/duration; \
 step_y=(*(float *)(p+0x6c)-*(float *)(p+0x60))/duration; \
 step_z=(*(float *)(p+0x70)-*(float *)(p+0x64))/duration; \
 p[4]=1; \
 update(p); \
}

ANGLE_INIT(func_003381A0, D_004B8080, 150.0f, D_00583C58, D_00583C5C, D_00583C60, func_00338280)
ANGLE_INIT(func_00338590, D_004B80A0, 150.0f, D_00583C48, D_00583C4C, D_00583C50, func_00338670)
ANGLE_INIT(func_00338A50, D_004B80D0, 100.0f, D_00583C88, D_00583C8C, D_00583C90, func_00338B30)
ANGLE_INIT(func_00338C90, D_004B8100, 100.0f, D_00583C78, D_00583C7C, D_00583C80, func_00338D70)
ANGLE_INIT(func_00339150, D_004B8130, 100.0f, D_00583C68, D_00583C6C, D_00583C70, func_00339230)
ANGLE_INIT(func_00339920, D_004B81D0, 60.0f, D_00583C28, D_00583C2C, D_00583C30, func_00339A00)
ANGLE_INIT(func_00339B60, D_004B8200, 60.0f, D_00583C38, D_00583C3C, D_00583C40, func_00339C40)
