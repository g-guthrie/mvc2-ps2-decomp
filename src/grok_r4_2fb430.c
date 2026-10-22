/* Metrowerks: ./try.sh src/grok_r4_2fb430.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;

extern void func_0018C6E0(void *);
extern int func_001757E0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_00182C30(u8 *, int);
extern void func_00182DB0(u8 *, int);

void func_002FB430(u8 *p)
{
    f32 tmp[3];

    if (p[34] & 1) {
        p[486] ^= 1;
        *(short *)(p + 320) = p[486];
    }
    p[436] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 15, 4);
    tmp[0] = -85.0f;
    tmp[2] = 0;
    tmp[1] = 53.57142639160156f;
    func_0015D010(p, tmp);
    func_00182C30(*(u8 **)(p + 476), 16);
    func_00182DB0(p, 1);
    *(short *)(p + 28) = 48;
}
