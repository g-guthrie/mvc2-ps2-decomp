typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct S38 S38;
struct S38 {
    u8 p0[2];
    u8 f2;
    u8 p3;
    u8 f4;
    u8 p5[2];
    u8 f7;
    u8 p8[0x10];
    S38 *f18;
    u8 p1C[0x18];
    f32 f34;
    f32 f38;
    u8 p3C[0x176];
    u8 f1B2;
    u8 f1B3;
    u8 p1B4;
    u8 f1B5;
    u8 p1B6[0xA];
    u16 f1C0;
    u8 p1C2[0x16];
    u32 f1D8;
};
typedef struct {
    u8 p0[0x1E];
    s16 f1E;
    u8 p20[0x148];
    u16 f168;
} Client;

extern u8 *D_004C2794;
extern u8 *D_004C29AC;
extern u8 *D_004C29A8;
extern s16 D_004646C0[16];
extern void func_003859F0(u8 *);
extern void func_00384410(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_00384220(u8 *actor)
{
    S38 *view = (S38 *)actor;
    s16 timer;

    if (*(u16 *)D_004C29AC != ((Client *)view->f18)->f168) {
        func_003859F0(actor);
        return;
    }
    view->f34 = view->f18->f34;
    view->f38 = view->f18->f38;
    view->f1B3 = 0;
    timer = *(s16 *)view->p1C;
    timer--;
    *(s16 *)view->p1C = timer;
    if (timer < 0) {
        view->f7++;
        *(s16 *)view->p1C = D_004646C0[view->f7];
        view->f1B5 = (((Client *)view->f18)->f1E == 1) ? 0x41 : 0x40;
        view->f1B2 = view->f1C0 = 0;
        view->f1D8 = 0;
        {
            u8 *counterBase = (u8 *)((actor[2] << 1) + (u32)D_004C2794);
            *(s16 *)(counterBase + 0x7C) = *(s16 *)(counterBase + 0x7C) + 1;
        }
        func_00384410(actor);
        timer = ((Client *)view->f18)->f1E - 1;
        ((Client *)view->f18)->f1E = timer;
        if (timer < 0) {
            view->f4++;
            D_004C29A8[1] = 0;
            func_001757E0(actor, 0x14, 4);
            func_001E7F60(actor);
            return;
        }
    }
    func_00175700(actor);
    func_001E7F60(actor);
}
