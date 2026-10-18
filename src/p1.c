/* EE GCC 2.96 -O2 -G0 (tryee.sh src/p1.c sn): thunks, a soft-float double
   ratio, and two VU0/cache routines written as assembly. */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;

#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")

/* VU0: convert four fixed-point (4.12) words to floats. */
FN(func_00102F78,
  ".word 0xD8A40000 /* lqc2       $vf4, 0x0($5) */\n"
  ".word 0x4BE5213D /* vitof4.xyzw $vf5, $vf4 */\n"
  ".word 0x03E00008 /* jr         $31 */\n"
  ".word 0xF8850000 /* sqc2      $vf5, 0x0($4) */\n"
  );

/* Instruction-cache scrub over 0x1000 bytes using cache ops and mfc0 $28. */
FN(func_00104770,
  "lui $7, 0xFFFF\n"
  "daddu $6, $0, $0\n"
  "ori $7, $7, 0xF000\n"
  "nop\n"
  "1:\n"
  "sync\n"
  "cache 0x10, 0($6)\n"
  "sync\n"
  "mfc0 $2, $28\n"
  "and $2, $2, $7\n"
  "addu $2, $2, $6\n"
  "sltu $3, $5, $2\n"
  "sltu $2, $2, $4\n"
  "bnez $2, 2f\n"
  "nop\n"
  "bnez $3, 2f\n"
  "nop\n"
  "sync\n"
  "cache 0x16, 0($6)\n"
  "sync\n"
  "2:\n"
  "sync\n"
  "cache 0x10, 1($6)\n"
  "sync\n"
  "mfc0 $2, $28\n"
  "and $2, $2, $7\n"
  "addu $2, $2, $6\n"
  "sltu $3, $5, $2\n"
  "sltu $2, $2, $4\n"
  "bnez $2, 3f\n"
  "nop\n"
  "bnez $3, 3f\n"
  "nop\n"
  "sync\n"
  "cache 0x16, 1($6)\n"
  "sync\n"
  "3:\n"
  "sync\n"
  "addiu $6, $6, 0x40\n"
  "slti $2, $6, 0x1000\n"
  "bnez $2, 1b\n"
  "nop\n"
  "jr $31\n"
  "nop\n"
  );

/* A reserved but unused frame slot (volatile local) gives the 0x10 frame. */
void func_00411270(u16 *p) {
    volatile u32 pad;
    u16 v = p[1] + 1;
    p[1] = v;
}

extern void func_003F64D0(s32 a);
void func_003FF600(s32 *p, s32 v) {
    p[14] = v;
    func_003F64D0(p[1]);
}

extern char D_004BB448[];
extern void func_003FB128(char *s);
s32 func_003FD450(s32 *p) {
    if (p == 0) {
        func_003FB128(D_004BB448);
        return -3;
    }
    return p[3];
}

typedef struct {
    u8 pad0[2];
    s8 type;
    u8 pad3[0x25];
    s32 v;
} S40BCF8;
extern char D_004BE080[];
extern void func_0040AF58(S40BCF8 *p, char *s);
s32 func_0040BCF8(S40BCF8 *p) {
    if (p == 0) {
        func_0040AF58(p, D_004BE080);
        return 0;
    }
    if (p->type == 1) {
        return p->v << 11;
    }
    return 0;
}

/* Soft-float: (double)a / (double)b * 100.0 truncated to u32. */
extern void func_00401B78(s32 x, s32 *a, s32 *b);
u32 func_00401E28(s32 x) {
    s32 a, b;
    func_00401B78(x, &a, &b);
    return (u32)((double)a / (double)b * 100.0);
}

typedef struct {
    s32 a;
    s32 b;
    s32 count;
} S3FD560;
extern S3FD560 *D_0047B180[];
extern char D_004BB530[];
extern char D_004BB558[];
s32 func_003FD560(u32 i, s32 n) {
    S3FD560 *p;
    if (i >= 0x100) {
        func_003FB128(D_004BB530);
        return -3;
    }
    p = D_0047B180[i];
    if (p == 0) {
        func_003FB128(D_004BB530);
        return -3;
    }
    if (n < 0 || n >= p->count) {
        func_003FB128(D_004BB558);
        return -3;
    }
    return 0;
}

typedef struct {
    s32 a;
    void (*cb)();
} S405FC0;
extern volatile s32 D_004872E0;
extern char D_004BC8B0[];
extern char D_004BC8D8[];
extern char D_004BC900[];
extern void func_00405D98();
extern void func_00405DC8(char *s);
extern S405FC0 *func_00406050(s32 a, s32 b);
void func_00405FC0(s32 a, s32 b) {
    S405FC0 *r;
    s32 x = D_004872E0;
    if (a == 0) {
        func_00405DC8(D_004BC8B0);
        return;
    }
    if (b == 0) {
        func_00405DC8(D_004BC8D8);
        return;
    }
    r = func_00406050(a, b);
    if (r == 0) {
        func_00405DC8(D_004BC900);
        return;
    }
    if (r->cb != 0) {
        r->cb(func_00405D98, 0);
    }
}

typedef struct {
    u8 p0[4];
    void *h;
    u8 p8[4];
    s32 c;
    s32 d;
    u8 p14[0x1C];
    s32 e;
} S3FCB20;
extern char D_004BB1F0[];
extern s32 func_003FD748(s32 a, s32 b, void *buf, s32 *x, s32 *y, s32 *z);
extern void *func_00400328(void *buf, s32 x, s32 y, s32 z, s32 w);
s32 func_003FCB20(S3FCB20 *p, s32 a, s32 b) {
    u8 buf[0x100];
    s32 x, y, z;
    if (func_003FD748(a, b, buf, &x, &y, &z) < 0) {
        return -3;
    }
    p->e = y;
    p->h = func_00400328(buf, x, y, z, 0);
    if (p->h == 0) {
        func_003FB128(D_004BB1F0);
        return -1;
    }
    p->c = z;
    p->d = z << 11;
    return 0;
}
