/* Narrow unpacked double precision with a sticky low bit before float packing. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef struct { s32 cls,sign,exp,pad; u64 frac; } DoubleParts;
extern void func_001191F0(u64 *,DoubleParts *);
extern float func_00119028(s32,s32,s32,s32);
float func_00119C90(double value) {
 DoubleParts parts;
 s32 fraction;
 func_001191F0((u64 *)&value,&parts);
 fraction=(s32)(parts.frac>>30);
 if (parts.frac&0x3FFFFFFFULL) fraction|=1;
 return func_00119028(parts.cls,parts.sign,parts.exp,fraction);
}
