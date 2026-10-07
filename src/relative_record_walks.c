/* Follow relative four-byte records to select an animation entry. */
typedef unsigned char u8;
typedef struct RelativeRecord { short skip; short payload; } RelativeRecord;
extern RelativeRecord D_004B7C20[], D_004B7B40[];
extern void func_003315C0(u8 *), func_00331AB0(u8 *);
extern void func_00332920(u8 *), func_00332D30(u8 *);

#define RELATIVE_RECORD_WALK(name, records, next) \
void name(u8 *p) { \
    RelativeRecord *record = (records); int i; \
    for (i = 0; i < p[4]; ++i) record += record->skip; \
    p[7] = *(signed char *)record; \
    p[5] = 1; \
    next(p); \
}

RELATIVE_RECORD_WALK(func_003314F0, D_004B7C20, func_003315C0)
RELATIVE_RECORD_WALK(func_003319E0, D_004B7C20, func_00331AB0)
RELATIVE_RECORD_WALK(func_00332850, D_004B7B40, func_00332920)
RELATIVE_RECORD_WALK(func_00332C60, D_004B7B40, func_00332D30)
