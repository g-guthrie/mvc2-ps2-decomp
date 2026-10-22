typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static int func_00149E30(int x, int n)
{
    int r = 1;
    int i;
    for (i = 0; i < n; i++)
        r *= x;
    return r;
}

typedef struct { u8 p0[0x20]; u8 b20; } P149E;
typedef struct { f32 x, y, z; } V3;

void func_00149EB0(P149E *p, s32 n, s32 cnt, s32 v, V3 *arr)
{
    extern u8 *func_00149D70(u8, u32, V3 *);
    s32 i;
    s32 flag = 0;
    for (i = 0; i < cnt; i++) {
        s32 r = n / func_00149E30(10, cnt - i - 1);
        r = r % 10;
        if (i == cnt - 1) flag = 1;
        if (flag != 0 || r != 0) {
            u8 *q;
            flag = 1;
            q = func_00149D70(p->b20, r + 3, arr);
            if (q != 0) q[0x21] = v;
        }
        arr++;
    }
}
