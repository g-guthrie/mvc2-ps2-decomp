extern int D_004399A8;
extern volatile int D_004399AC;
extern int D_004399A0;
extern int D_004399B0;
extern unsigned func_00103DE0(int *);


typedef struct {
    int f0;
    int f4;
} S6C80;
extern S6C80 D_004C6C80;
extern int D_004382FC;
extern int func_00107AB8(int);
extern void func_00107BC0(void);
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00107AE8(void);

extern char D_004C6E88[];
extern char D_004C7080[];
extern int func_0010B198(int);
extern int func_0010B298(void);
extern char *func_00120440(char *, int, int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);

extern int D_00438254;
extern int func_00103DC0(void);
extern int *func_0011B370(void);

extern int D_00438260;
extern unsigned char D_004C3980[];
extern void func_00104FF8(unsigned char *);

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int pad2[2];
} E1C;
typedef struct {
    E1C e[4];
} E70;
extern E1C D_004C83D0[][4];
extern unsigned char *func_0010D860(int);


extern volatile int D_004399D4;
extern volatile int D_004399AC;
extern char D_0043AB80[];
extern char D_0043B3C8[];
extern int func_0010F258(int);
extern void func_00103E00(int);

int func_0010FBE0(void) {
    int v;
    int r;
    int res;

    if (func_0010F258(0x1E) == 0) {
        return 0;
    }
    D_004399D4 = 8;
    r = func_00106E68(D_0043B3C8, 0x16, 0, 0, 0, D_0043AB80, 4, 0, 0);
    if (r < 0) {
        func_00103E00(D_004399AC);
        D_004399D4 = 0;
        res = 0;
    } else {
        D_004399D4 = 0;
        v = *(int *)((unsigned)D_0043AB80 | 0x20000000);
        func_00103E00(D_004399AC);
        res = v;
    }
    return res;
}

extern char D_004C3700[];
extern char D_004C3840[];
extern void func_00104060(int);
extern int func_00104E40(int, void *, void *);
extern void func_001050C8(void);
extern int func_00105020(int);


typedef struct {
    char pad[0x24];
    int f24;
} S8900;
typedef struct {
    int f0;
    int f4;
} S8980;
extern S8900 D_004C8900;
extern S8980 D_004C8980;
extern int D_0043B404;
extern int D_004C9EC0;
extern int func_00103E30(int);

typedef struct {
    int a;
    int b;
} E8;
extern E8 D_004386A8[];
extern int D_004386A0;
extern char D_00438328[];
extern void func_0010C2E8(int, int);
extern int func_0010C2D8(int);
extern void func_0010C290(unsigned, void *, int);

extern unsigned long *func_00100468();

typedef struct {
    int f0;
    int count;
} S3168;
extern S3168 D_004C3168;
extern char _gp[];
extern int D_00438258;
extern int D_004C3160;
extern char D_004C2D60[];
extern void func_00104AE0(void);
extern int func_00103BE0(void *);
extern void func_00103DF0(int);
extern void func_00103C00(int, void *);
extern int func_00103CD0(void);
extern void func_00103C70(int, int);

typedef struct {
    int f0;
    int f4;
    int f8;
    unsigned char name[8];
    int f14;
} S85C0;
extern S85C0 D_004C85C0;
extern char D_004C8380[];
extern void func_0010DA40(int, int, int);

typedef struct {
    int f0;
    int f4;
    int f8;
} S6E80;
extern S6E80 D_004C6E80;


extern int D_0043B400;
extern int func_00107058(void *);
extern void func_00110770(int);

typedef struct {
    char b[8];
} U8;
extern int D_00439990;
extern char D_004AB598[];
extern char D_004AB5B8[];
extern void func_00105E80(char *, ...);

extern char D_004C6E88[];

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char name[0x40];
} S70C0;
extern S70C0 D_004C70C0;
extern void func_001040B0(char *);
extern int func_001041F0(unsigned);
extern void func_00106578(void *, int);
extern void func_001041E0(unsigned, unsigned);
extern int func_001041A0(void *, int);


typedef struct {
    int f0;
    int f4;
} S9158;
extern S9158 D_00439158;
extern void func_0010CEA8(int, int);
extern int func_0010CE68(char *, void *, int);
extern int func_0011FFA0(char *);

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} S5500;
extern S5500 D_004C5500;
extern char D_004C6C00[];
extern char D_004C6140[];
extern void func_00103E20(int);

typedef struct {
    int a;
    int b;
    int c;
    int d;
} E16;
extern int D_004C3AE0;
extern int func_001041B0(void *, int);


typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
} SC98;
extern char D_004C5480[];
extern SC98 *func_001067F0(void *);
extern int func_001063D0(unsigned, void *, int, int, int, int);
extern void func_00106898(void *);

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char name[0x400];
} S89B0;
extern S89B0 D_004C89B0;

extern int func_00104EB0(int, int);
extern void func_00104EE0(int);


typedef struct {
    int f0;
    int f4;
} S76;
typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
} S5500b;
extern S76 *func_00107670(int);

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int pad[3];
} EN1C;
typedef struct {
    EN1C e[4];
} EN70;

extern int D_0043991C;
extern char D_004AB268[];
extern int func_00104180(void);
extern int func_001046D8(int *, int *, int);
