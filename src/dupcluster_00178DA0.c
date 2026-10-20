typedef unsigned char u8;
extern float D_004F1F4C; extern float D_004F1F40[];
typedef struct { u8 pad[52]; float x; } Object;
void func_00178DA0(Object *p){
float low=(D_004F1F4C-320.0f)+35.0f;
float high; float *table=D_004F1F40;
if (p->x<=low) { p->x=low; return; }
high=(table[3]+320.0f)-35.0f;
if (p->x<high) return;
p->x=high;
}
