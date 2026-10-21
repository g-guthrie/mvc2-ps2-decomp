typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef struct {
    u32 cls;
    u32 sign;
    s32 normal_exp;
    s32 pad;
    union {u64 ll; u32 l[2];} fraction;
} fp_number_type;
extern void func_001191F0(u64 *,fp_number_type *);
extern fp_number_type *func_001192B0(fp_number_type *,fp_number_type *,fp_number_type *);
extern double func_00119118(fp_number_type *);
double func_00119510(double a,double b) {
 fp_number_type x,y,z;
 func_001191F0((u64 *)&a,&x);
 func_001191F0((u64 *)&b,&y);
 return func_00119118(func_001192B0(&x,&y,&z));
}
