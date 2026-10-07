/* Select owner-filtered interactions or the per-record interaction handler. */
typedef unsigned char u8;
typedef int (*Interaction)(u8 *,u8 *,u8 *);
extern int func_0018A460(u8 *,u8 *,u8 *,int);
extern Interaction D_00448F10[];
int func_00189310(u8 *p,u8 *owner,u8 *record) {
    if (*(signed char *)(p + 0x539)) {
        if (p[0x471] && (signed char)p[0x45c] == owner[4]) return func_0018A460(p,owner,record,0);
        return 0;
    }
    return D_00448F10[record[0]](p,owner,record);
}
extern int func_0018A460(u8 *,u8 *,u8 *,int);
extern Interaction D_00448F30[];
int func_00189660(u8 *p,u8 *owner,u8 *record) {
    if (*(signed char *)(p + 0x539)) {
        if (p[0x471] && (signed char)p[0x45c] == owner[4]) return func_0018A460(p,owner,record,0);
        return 0;
    }
    return D_00448F30[record[0]](p,owner,record);
}
extern int func_0018A460(u8 *,u8 *,u8 *,int);
extern Interaction D_00448F48[];
int func_00189950(u8 *p,u8 *owner,u8 *record) {
    if (*(signed char *)(p + 0x539)) {
        if (p[0x471] && (signed char)p[0x45c] == owner[4]) return func_0018A460(p,owner,record,0);
        return 0;
    }
    return D_00448F48[record[0]](p,owner,record);
}
extern int func_0018A460(u8 *,u8 *,u8 *,int);
extern Interaction D_00448F60[];
int func_00189B90(u8 *p,u8 *owner,u8 *record) {
    if (*(signed char *)(p + 0x539)) {
        if (p[0x471] && (signed char)p[0x45c] == owner[4]) return func_0018A460(p,owner,record,0);
        return 0;
    }
    return D_00448F60[record[0]](p,owner,record);
}
extern int func_0018A460(u8 *,u8 *,u8 *,int);
extern Interaction D_00448F80[];
int func_00189EE0(u8 *p,u8 *owner,u8 *record) {
    if (*(signed char *)(p + 0x539)) {
        if (p[0x471] && (signed char)p[0x45c] == owner[4]) return func_0018A460(p,owner,record,0);
        return 0;
    }
    return D_00448F80[record[0]](p,owner,record);
}
