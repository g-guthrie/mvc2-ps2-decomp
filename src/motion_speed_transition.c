typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_00185490(u8 *);
extern void func_001D36E0(u8 *, int);
extern void func_00183D10(u8 *);
extern u8 *D_004C2794;

void func_002AD6F0(u8 *p)
{
    f32 distance;
    f32 velocity;

    p[316] = 1;
    p[7]++;
    *(s16 *)(p + 28) = 32;
    *(f32 *)(p + 696) = *(f32 *)(p + 52);
    distance = 640.0f;
    velocity = 13.333333f;
    if (*(s16 *)(p + 320) != 0) {
        distance = -distance;
        velocity = -velocity;
    }
    *(f32 *)(p + 92) = velocity;
    *(f32 *)(p + 52) = *(f32 *)(p + 52) - distance;
    *(u32 *)(p + 108) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 18, 0);
}

void func_002F03F0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    p[437] = 53;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 5);
}

void func_002E5F00(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[437] = 48;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    func_00183D10(p);
    func_00175C00(p, 0);
    func_001757E0(p, 21, p[439]);
}

void func_002D3270(u8 *p)
{
    p[6]++;
    p[525] = 2;
    if (p[486] != 0)
        *(int *)(p + 92) = 0x41F00000;
    else
        *(int *)(p + 92) = 0xC1F00000;
    *(int *)(p + 104) = 0;
    *(int *)(p + 96) = 0x3E892492;
    *(int *)(p + 108) = 0xBF4DB6DB;
    p[437] = 51;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 2);
}

void func_002F5D50(u8 *p)
{
    p[6]++;
    p[525] = 2;
    *(int *)(p + 92) = 0x42055555;
    if (p[486] == 0)
        *(float *)(p + 92) = -*(float *)(p + 92);
    *(int *)(p + 104) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 108) = 0xBF3C9249;
    p[437] = 48;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 2);
}

void func_002B6E10(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    p[437] = 77;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 4);
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
}

void func_002BB5A0(u8 *p)
{
    int command;
    p[6]++;
    func_00185490(p);
    *(float *)(p + 56) = *(float *)(p + 1072);
    p[525] = 0;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    func_0018C4B0(p, 10);
    func_00183D10(p);
    command = p[439] != 0 ? 32 : 14;
    func_001757E0(p, 21, (u8)command);
}

void func_002D7700(u8 *p)
{
    u8 angle;
    p[6]++;
    p[701] = 0;
    *(float *)(p + 56) = *(float *)(p + 1072);
    func_00185490(p);
    p[437] = 56;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00175C00(p, 0);
    func_00183D10(p);
    p[525] = 0;
    angle = (u8)(p[439] << 1);
    func_001757E0(p, 21, angle);
}

void func_002BC080(u8 *p)
{
    p[6]++;
    p[437] = p[439] != 0 ? 73 : 71;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 10);
    func_00185490(p);
    p[360] = p[439] != 0 ? 26 : 24;
    func_001757E0(p, 21, p[360]);
}

void func_0027EC60(u8 *p)
{
    p[6]++;
    p[525] = 0;
    p[437] = 59;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 6);
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
}

void func_00231D70(u8 *p)
{
    p[437] = (u8)((signed char)p[336] + 81);
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
}

void func_002F1060(u8 *p)
{
    p[6]++;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    p[525] = 0;
    *(float *)(p + 56) = *(float *)(p + 1072);
    func_00185490(p);
    func_00183D10(p);
    p[437] = 58;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 6);
}

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
void func_002F5CC0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 21, 56);
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 96) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 108) = 0;
    } else if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}


void func_002F3F90(u8 *p)
{
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((p[346] & 0xE0) != 0x80) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    } else {
        p[828] = 5;
        p[1036] = 2;
        p[828] = 5;
    }
}


void func_002F5BA0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 21, 65);
        p[437] = 67;
        p[434] = *(unsigned short *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    if ((signed char)func_00175700(p) < 0)
        func_001843A0(p);
}


void func_002F5C30(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 21, 67);
        p[437] = 68;
        p[434] = *(unsigned short *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    if ((signed char)func_00175700(p) < 0)
        func_001843A0(p);
}


extern void func_003AD480(u8 *, int, int);
void func_002F5AA0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        p[437] = 60;
        p[434] = *(unsigned short *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 21, 61);
        *(s16 *)(p + 28) = -1;
        func_003AD480(p, 1, 1);
    }
    if (p[7] == 0) {
        func_00175700(p);
        if (*(s16 *)(p + 28) == 0) {
            p[7]++;
            func_001757E0(p, 21, 62);
        } else {
            --*(s16 *)(p + 28);
        }
    } else if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}


extern void func_001830D0(u8 *, float *, int);
extern void func_003A9F30(u8 *);
void func_002F3EE0(u8 *p)
{
    float position[3];
    p[828] = 5;
    p[1036] = 2;
    p[828] = 5;
    p[1029] = p[617] == 6 ? 2 : 0;
    func_00175700(p);
    if ((signed char)p[337] != 0) {
        p[1028] = 0;
        p[1029] = 0;
        p[6]++;
        position[0] = 0.0f;
        position[1] = 171.42855834960938f;
        position[2] = 0.0f;
        func_001830D0(p, position, 1);
        func_003A9F30(p);
    }
}


extern void func_002F5FD0(u8 *);
void func_002F5F50(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 96) = 0x40892492;
    *(u32 *)(p + 108) = 0xBECDB6DB;
    *(u32 *)(p + 92) = 0x41555555;
    *(u32 *)(p + 104) = 0;
    if (*(s16 *)(p + 320) == 0)
        *(float *)(p + 92) = -*(float *)(p + 92);
    func_001757E0(p, 2, 4);
    func_002F5FD0(p);
}


void func_002EABF0(u8 *p)
{
    s16 remaining;
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    remaining = --*(s16 *)(p + 28);
    if (remaining == 0) {
        p[6]++;
        *(f32 *)(p + 104) = p[486] ? -0.4166666567325592041015625f :
            0.4166666567325592041015625f;
        func_001757E0(p, 2, 2);
    }
}

void func_00302270(u8 *p)
{
    s16 remaining;
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    remaining = --*(s16 *)(p + 28);
    if (remaining == 0) {
        p[6]++;
        *(f32 *)(p + 104) = p[486] ? -0.4166666567325592041015625f :
            0.4166666567325592041015625f;
        func_001757E0(p, 2, 2);
    }
}

void func_002EA8E0(u8 *p)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_00175700(p);
    if ((signed char)p[434] != 0) {
        p[7]++;
        func_001757E0(p, 20, 5);
        *(u32 *)(p + 92) = 0x40D55555;
        *(u32 *)(p + 104) = 0xBD555555;
        *(u32 *)(p + 96) = 0x414DB6DB;
        *(u32 *)(p + 108) = 0xBF4DB6DB;
        if (*(s16 *)(p + 320) != 0) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
            *(f32 *)(p + 104) = -*(f32 *)(p + 104);
        }
    }
}

void func_00301F60(u8 *p)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_00175700(p);
    if ((signed char)p[434] != 0) {
        p[7]++;
        func_001757E0(p, 20, 5);
        *(u32 *)(p + 92) = 0x40D55555;
        *(u32 *)(p + 104) = 0xBD555555;
        *(u32 *)(p + 96) = 0x414DB6DB;
        *(u32 *)(p + 108) = 0xBF4DB6DB;
        if (*(s16 *)(p + 320) != 0) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
            *(f32 *)(p + 104) = -*(f32 *)(p + 104);
        }
    }
}

void func_002C3EB0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430))
        func_001843A0(p);
}

void func_002C1F30(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (--*(s16 *)(p + 0x1C) == 0) {
        p[6]++;
        func_001757E0(p, 2, 2);
    }
}

void func_002C20F0(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (--*(s16 *)(p + 0x1C) == 0) {
        p[6]++;
        func_001757E0(p, 2, 3);
    }
}

void func_002E1EB0(u8 *p)
{
    s16 timer = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = timer;
    if (timer < 0) {
        *(s16 *)(p + 0x1E) = 4;
        func_001D36E0(p, 0);
    }

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (--*(s16 *)(p + 0x1C) < 0) {
        p[6]++;
        func_001757E0(p, 2, 2);
    }
}
