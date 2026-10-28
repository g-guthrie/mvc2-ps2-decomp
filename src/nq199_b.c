typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x5C]; f32 f5c; u8 pad2[0x1B2 - 0x60]; s8 b1b2; } A36;

void func_002A36F0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_002A3E20(u8 *);
    extern void func_002A3D00(u8 *);
    extern void func_002A3D70(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern f32 func_00117078(f32);
    u32 h;
    f32 v;
    f32 r;
    s16 t;
    u8 k;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) return;
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(s8 *)(p + 0x539) != 0) {
            if (p[0x212] != 0) {
                func_002A3E20(p);
                return;
            }
            switch (p[0x1B7]) {
            default:
                func_002A3D00(p);
                return;
            case 0:
                break;
            }
            func_002A3D70(p);
            return;
        }
        h = *(u16 *)(p + 0x366);
        switch (h & 0x200) {
        default:
            func_002A3D70(p);
            return;
        case 0:
            break;
        }
        switch (h & 0x100) {
        default:
            func_002A3D00(p);
            return;
        case 0:
            break;
        }
        switch (h & 0x60) {
        default:
            func_002A3E20(p);
            return;
        case 0:
            break;
        }
        p[6] = 4;
        p[0x20D] = 2;
        if (((A36 *)p)->b1b2 & 0x11) v = -0.0f;
        else v = -1.25f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] == 0) ((A36 *)p)->f5c *= -1.0f;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBFF00000;
        k = (p[0x1B7] != 0) ? 0xD : 0xC;
        func_001757E0(p, 0x15, k);
        return;
    }
    h = *(u16 *)(p + 0x35C);
    switch (h & 0x200) {
    default:
        func_002A3D70(p);
        return;
    case 0:
        break;
    }
    switch (h & 0x100) {
    default:
        func_002A3D00(p);
        return;
    case 0:
        break;
    }
    if (h & 0x60) {
        func_002A3E20(p);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    switch (t) {
    default:
        r = func_00117078(((A36 *)p)->f5c);
        if (r >= func_00117078(*(f32 *)(p + 0x60))) {
            *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x60);
            *(u32 *)(p + 0x68) = 0;
        }
        return;
    case 0:
        break;
    }
    p[6] = 5;
    k = (p[0x1B7] != 0) ? 0xF : 0xE;
    func_001757E0(p, 0x15, k);
}
