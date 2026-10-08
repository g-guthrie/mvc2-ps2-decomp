typedef unsigned char u8;
typedef signed char s8;

extern volatile s8 D_004F1D20;
extern u8 D_004F1D30[];
extern void func_00418000(void *);
extern void func_00418010(void);

void func_0016D260(void) {
    if (D_004F1D20)
        func_00418000(D_004F1D30);
    else
        func_00418010();
}
