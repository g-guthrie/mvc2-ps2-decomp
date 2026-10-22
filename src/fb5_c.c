typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001EFA70(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001864a0(u8 *);
    extern void func_001865B0(u8 *);
    extern void func_001EF8E0(u8 *);
    extern void func_001EF970(u8 *);
    extern void func_001EFA00(u8 *);
    switch (p[0x1FC]) {
    case 0:
        switch (p[6]) {
        case 0:
            if (func_00175700(p) < 0) {
                func_00184540(p);
            }
            if (func_001864a0(p) != 0) {
                func_001865B0(p);
            }
            break;
        case 1:
            if (func_00175700(p) < 0) {
                func_00184540(p);
                func_001757E0(p, 1, 0xC);
            }
            if (func_001864a0(p) != 0) {
                func_001865B0(p);
            }
            break;
        case 2:
            switch (p[7]) {
            case 0:
                func_001EF8E0(p);
                break;
            case 1:
                func_001EF970(p);
                break;
            case 2:
                func_001EFA00(p);
                break;
            }
            break;
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        }
        if (func_001864a0(p) != 0) {
            func_001865B0(p);
        }
        break;
    case 2:
        switch (p[6]) {
        case 0:
            if (func_00175700(p) < 0) {
                func_00184540(p);
            }
            break;
        case 1:
            func_00175700(p);
            break;
        }
        if (func_001864a0(p) != 0) {
            func_001865B0(p);
        }
        break;
    }
}
