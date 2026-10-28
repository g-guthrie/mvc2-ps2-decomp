/* func_001089F0: Sony EE GCC 2.9, ./trysony29.sh src/s6a_h.c 0 O2 (exact). The semaphore table D_00438278 is volatile: that keeps i=0 out of the bne delay slot (retail fills it from the target). */
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    s32 w0;
    s32 w4;
} Cur;

typedef struct {
    u8 d[0x400];
} Blk;

typedef struct {
    s32 id;
    void *buf;
    s32 n;
    s32 w0C;
    s32 cmd;
    Blk data;
    s32 w414;
    s32 w418;
    s32 w41C;
} Req;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Sema;

extern Cur *func_00107670(void);
extern void func_00107AB8(s32);
extern void func_00107BC0(void);
extern void func_00107AE8(void);
extern void func_00103E20(s32);
extern void func_00103E00(s32);
extern s32 func_00103DE0(Sema *);
extern void func_00103DF0(s32);
extern void func_00106578(void *, s32);
extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, s32, s32);

extern Req D_004C5500;
extern s32 *D_004C54C8;
extern s32 D_004382FC;
extern s32 D_004382F8;
extern s32 D_0043830C;
extern volatile s32 D_00438278[32];
extern u8 D_004C6190[];
extern u8 D_004C6C00[];
extern u8 D_004C6140[];

s32 func_001089F0(s32 a0, s32 cmd, s32 *a2)
{
    Cur *cur;
    Sema sm;
    s32 buf[4];
    s32 i;
    s32 id;
    s32 r;
    Req *rq;
    s32 one = 1;
    s32 w;

    rq = &D_004C5500;
    cur = func_00107670();
    func_00107AB8(5);
    D_004C54C8 = a2;
    if (D_004382FC == 0)
        func_00107BC0();
    if (cur == 0 || cur->w4 == 0) {
        func_00107AE8();
        return -9;
    }
    rq->w414 = 0;
    rq->w418 = 0;
    if (cmd == 2)
        goto c2;
    if (cmd < 3) {
        if (cmd == one)
            goto c1;
        goto dflt;
    }
    if (cmd == 3)
        goto c3;
    goto dflt;
c1:
        func_00103E20(D_0043830C);
        for (i = 0; i < 32; i++)
            if (D_00438278[i] != -1)
                break;
        if (i == 32)
            *D_004C54C8 = 0;
        else
            *D_004C54C8 = 1;
        func_00103E00(D_0043830C);
        func_00107AE8();
        return 0;
c2:
        *a2 = *(s32 *)((u32)(D_004C6190 + D_004382F8 * 0x440) | 0x20000000);
        func_00107AE8();
        return 0;
c3:
        *(u64 *)a2 = *(u64 *)((u32)(D_004C6190 + D_004382F8 * 0x440) | 0x20000000);
        func_00107AE8();
        return 0;
dflt:
        w = cur->w0;
        rq->cmd = cmd;
        rq->w0C = w;
        if (a2 == 0) {
            rq->w41C = 0;
        } else {
            rq->w41C = 0x400;
            rq->data = *(Blk *)a2;
        }
        sm.f4 = 1;
        sm.f8 = 0;
        sm.f14 = 0;
        id = func_00103DE0(&sm);
        rq->buf = buf;
        rq->id = id;
        rq->n = 4;
        func_00106578(&D_004C5500, 0x420);
        if (func_00106E68(D_004C6C00, 5, 0, &D_004C5500, 0x420, D_004C6140, 4, 0, 0) < 0) {
            func_00103DF0(id);
            func_00107AE8();
            return -0xB;
        }
        r = *(s32 *)((u32)D_004C6140 | 0x20000000);
        func_00107AE8();
        if (r == 0) {
            func_00103DF0(id);
            return -0xB;
        }
        func_00103E20(id);
        func_00103DF0(id);
        return buf[0];
}
