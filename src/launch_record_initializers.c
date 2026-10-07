/* Initialize launch velocity, facing-relative offsets, and its animation record. */
typedef unsigned char u8;
typedef struct LaunchRecord { short vx,vy,x,y; u8 animation,event; } LaunchRecord;
extern u8 *D_004C2794;
extern void func_001757E0(u8 *,int,int);
void func_00345CB0(u8 *p,u8 *owner,LaunchRecord *record) {
    int mirrored; float vx,x; unsigned int counter;
    *(float *)(p+0x34)=*(float *)(owner+0x34);
    *(float *)(p+0x38)=*(float *)(owner+0x38);
    mirrored=*(short *)(owner+0x140);
    vx=record->vx; x=record->x;
    if (mirrored) { x=-x; vx=-vx; }
    *(float *)(p+0x34)+=x;
    *(float *)(p+0x38)+=record->y;
    *(float *)(p+0x5c)=vx;
    *(float *)(p+0x60)=record->vy;
    *(float *)(p+0x6c)=0; *(float *)(p+0x68)=0;
    p[0x1b0]=66; p[0x1b1]=66; p[0x1b5]=record->event;
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0; *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794;
    (*(short *)(counter+0x7c))++;
    func_001757E0(p,21,record->animation);
}
void func_0038E2D0(u8 *p,u8 *owner,LaunchRecord *record) {
    int mirrored; float vx,x; unsigned int counter;
    *(float *)(p+0x34)=*(float *)(owner+0x34);
    *(float *)(p+0x38)=*(float *)(owner+0x38);
    mirrored=*(short *)(owner+0x140);
    vx=record->vx; x=record->x;
    if (mirrored) { x=-x; vx=-vx; }
    *(float *)(p+0x34)+=x;
    *(float *)(p+0x38)+=record->y;
    *(float *)(p+0x5c)=vx;
    *(float *)(p+0x60)=record->vy;
    *(float *)(p+0x6c)=0; *(float *)(p+0x68)=0;
    p[0x1b0]=66; p[0x1b1]=66; p[0x1b5]=record->event;
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0; *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794;
    (*(short *)(counter+0x7c))++;
    func_001757E0(p,21,record->animation);
}
void func_0039C4D0(u8 *p,u8 *owner,LaunchRecord *record) {
    int mirrored; float vx,x; unsigned int counter;
    *(float *)(p+0x34)=*(float *)(owner+0x34);
    *(float *)(p+0x38)=*(float *)(owner+0x38);
    mirrored=*(short *)(owner+0x140);
    vx=record->vx; x=record->x;
    if (mirrored) { x=-x; vx=-vx; }
    *(float *)(p+0x34)+=x;
    *(float *)(p+0x38)+=record->y;
    *(float *)(p+0x5c)=vx;
    *(float *)(p+0x60)=record->vy;
    *(float *)(p+0x6c)=0; *(float *)(p+0x68)=0;
    p[0x1b0]=66; p[0x1b1]=66; p[0x1b5]=record->event;
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0; *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794;
    (*(short *)(counter+0x7c))++;
    func_001757E0(p,21,record->animation);
}
