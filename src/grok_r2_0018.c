typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern void func_00175670(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00188F80(u8 *, int);
extern void func_001801E0(void);
extern void func_001802A0(void);
extern void func_0018DDD0(u8 *);
extern void func_0018E0B0(u8 *);

void func_001B3A30(u8 *p) {
    if (*(u16 *)(p + 208) != *(u16 *)(*(u8 **)(p + 24) + 360)) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[316] = 0;
    }
}

void func_001B52F0(u8 *p) {
    if (--*(s16 *)(p + 28) <= 0) p[4] = 2;
    func_00175670(p);
}

extern u8 D_004D18A0;

void func_001BD600(u8 *p) {
    if (D_004D18A0 < 5) {
        p[5]++;
        *(s16 *)(p + 28) = 300;
    }
}


