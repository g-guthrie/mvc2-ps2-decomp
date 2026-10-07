/* Dispatch the active animation or the mode-specific input nibble. */
typedef unsigned char u8;
extern void func_00244400(u8 *);
void func_00244380(u8 *p) {
    if (p[0x215]) func_00244400(p);
    else {
        int mode = p[0x212];
        if (!mode && ((signed char)p[0x1ea] & 15)) func_00244400(p);
        else if (mode && ((signed char)p[0x1ea] & 240)) func_00244400(p);
    }
}
extern void func_002C6340(u8 *);
void func_002C62C0(u8 *p) {
    if (p[0x215]) func_002C6340(p);
    else {
        int mode = p[0x212];
        if (!mode && ((signed char)p[0x1ea] & 15)) func_002C6340(p);
        else if (mode && ((signed char)p[0x1ea] & 240)) func_002C6340(p);
    }
}
extern void func_002E99F0(u8 *);
void func_002E9970(u8 *p) {
    if (p[0x215]) func_002E99F0(p);
    else {
        int mode = p[0x212];
        if (!mode && ((signed char)p[0x1ea] & 15)) func_002E99F0(p);
        else if (mode && ((signed char)p[0x1ea] & 240)) func_002E99F0(p);
    }
}
extern void func_003011B0(u8 *);
void func_00301130(u8 *p) {
    if (p[0x215]) func_003011B0(p);
    else {
        int mode = p[0x212];
        if (!mode && ((signed char)p[0x1ea] & 15)) func_003011B0(p);
        else if (mode && ((signed char)p[0x1ea] & 240)) func_003011B0(p);
    }
}
extern void func_00305A00(u8 *);
void func_00305980(u8 *p) {
    if (p[0x215]) func_00305A00(p);
    else {
        int mode = p[0x212];
        if (!mode && ((signed char)p[0x1ea] & 15)) func_00305A00(p);
        else if (mode && ((signed char)p[0x1ea] & 240)) func_00305A00(p);
    }
}
