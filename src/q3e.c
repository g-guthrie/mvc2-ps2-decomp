typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BB218[];
extern u8 D_004BB240[];
extern u8 D_004BB270[];
extern void func_003FB128(void *p);
extern s32 func_003FCDE0(void);


extern u8 D_004BC670[];
extern u8 D_004BC6A0[];
extern void func_003FB128(void *p);
extern void func_003FB178(void *p);
extern void func_00401868(void);
extern s32 func_00400528(void *b, s32 c);
extern void func_00401708(void *a, void *b);

void func_00402D18(u8 *a, u8 *b) {
    if (a == 0 || b == 0) {
        func_003FB128(D_004BC670);
        return;
    }
    func_00401868();
    {
        s32 r = func_00400528(b, *(s32 *)(a + 0x10));
        *(s32 *)(a + 8) = r;
        if (r == 0) {
            func_003FB178(D_004BC6A0);
            *(s16 *)(a + 0x60) = -1;
            a[1] = 6;
        } else {
            func_00401708(a, b);
            a[2] = 0;
            a[0x98] = 0;
        }
    }
}

extern u8 D_004BDDD8[];
extern u8 D_004BDDB0[];
extern s32 func_001089F0(s32 h, s32 a, s32 *buf);
extern void func_0011EB60();


extern void func_00104C90();
typedef unsigned long long u64;
extern s32 func_0010CA20(void);
extern void func_0010CA68(void);

