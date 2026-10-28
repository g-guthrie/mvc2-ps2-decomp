typedef unsigned char u8; typedef short s16; typedef struct {s16 x,y;} Point;
extern Point D_00472BC0[];
void func_003A4250(u8 *p)
{
    int index=*(s16 *)(p+0x1e); int next; Point *q=&D_00472BC0[index];
    float x=1.6666666269302368f*(float)q->x; float y=2.142857074737549f*(float)q->y; float nx,ny;
    next=(index+*(s16 *)(p+0x1c))%12; if(next<0) next=11;
    q=&D_00472BC0[next];
    nx=1.6666666269302368f*(float)q->x;
    ny=2.142857074737549f*(float)q->y;
    *(float *)(p+0x68)=(nx-x)/4.0f;
    *(float *)(p+0x6c)=(ny-y)/4.0f;
    p[0x23]=4;
}
