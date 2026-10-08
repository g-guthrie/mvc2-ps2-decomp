typedef unsigned char u8;

extern void func_00243360(u8 *);
extern void func_002405A0(u8 *);
extern void func_0022E2B0(u8 *);
extern int func_00175700(u8 *);
extern void func_00224120(u8 *);
extern void func_00224330(u8 *);

void func_00243330(u8 *p)
{
    p[6]++;
    *(float *)(p + 96) = 4.285714f;
    *(float *)(p + 108) = -1.6071428060531616f;
    *(float *)(p + 92) = 0.0f;
    *(float *)(p + 104) = 0.0f;
    func_00243360(p);
}

void func_00240540(u8 *p)
{
    p[6]++;
    *(short *)(p + 28) = 24;
    *(float *)(p + 92) = 15.833333f;
    *(float *)(p + 104) = -0.4017857f;
    if (p[486] != 0) {
        *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 104) = -*(float *)(p + 104);
    }
    *(float *)(p + 96) = 0.0f;
    *(float *)(p + 108) = 0.0f;
    func_002405A0(p);
}

void func_00224090(u8 *p)
{
    float speed;
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        *(int *)(p + 92) = 0;
        *(int *)(p + 96) = 0;
        *(int *)(p + 104) = 0;
        *(int *)(p + 108) = 0;
        if (p[486] != 0)
            speed = 16.666666f;
        else
            speed = -16.666666f;
        *(float *)(p + 92) = speed;
        *(short *)(p + 28) = 16;
        func_00224120(p);
    }
}

void func_002242A0(u8 *p)
{
    float speed;
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] != 0)
            speed = -13.333333f;
        else
            speed = 13.333333f;
        *(float *)(p + 92) = speed;
        *(int *)(p + 104) = 0;
        *(int *)(p + 96) = 0x40CDB6DB;
        *(int *)(p + 108) = 0xBF092492;
        func_00224330(p);
    }
}

void func_002347B0(u8 *p)
{
    p[6]++;
    *(float *)(p + 92) = -15.833333f;
    *(float *)(p + 104) = 0.3125f;
    *(float *)(p + 96) = 6.428571f;
    *(float *)(p + 108) = -0.53571427f;
    if (*(short *)(p + 320) != 0) {
        *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 104) = -*(float *)(p + 104);
    }
}

void func_002349C0(u8 *p)
{
    p[6]++;
    *(float *)(p + 92) = 15.833333f;
    *(float *)(p + 104) = -0.3125f;
    *(float *)(p + 96) = 6.428571f;
    *(float *)(p + 108) = -0.53571427f;
    if (*(short *)(p + 320) != 0) {
        *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 104) = -*(float *)(p + 104);
    }
}

void func_00287C30(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] == 0) {
            *(float *)(p + 92) = -13.333333f;
            *(float *)(p + 104) = 0.2604166567325592f;
        } else {
            *(float *)(p + 92) = 13.333333f;
            *(float *)(p + 104) = -0.2604166567325592f;
        }
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
    }
}

void func_00287E40(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] == 0) {
            *(float *)(p + 92) = 12.5f;
            *(float *)(p + 104) = -0.234375f;
        } else {
            *(float *)(p + 92) = -12.5f;
            *(float *)(p + 104) = 0.234375f;
        }
        *(float *)(p + 96) = 5.357142448425293f;
        *(float *)(p + 108) = -0.53571427f;
    }
}

void func_0028F3D0(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] == 0) {
            *(float *)(p + 92) = -10.0f;
            *(float *)(p + 104) = 0.15625f;
        } else {
            *(float *)(p + 92) = 10.0f;
            *(float *)(p + 104) = -0.15625f;
        }
        *(float *)(p + 96) = 4.285714f;
        *(float *)(p + 108) = -0.2678571343421936f;
    }
}

void func_0028F5D0(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] == 0) {
            *(float *)(p + 92) = 10.0f;
            *(float *)(p + 104) = -0.2083333283662796f;
        } else {
            *(float *)(p + 92) = -10.0f;
            *(float *)(p + 104) = 0.2083333283662796f;
        }
        *(float *)(p + 96) = 4.285714f;
        *(float *)(p + 108) = -0.2678571343421936f;
    }
}

void func_002F86A0(u8 *p)
{
    float x, y;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] != 0) {
            x = -20.0f;
        } else {
            x = 20.0f;
        }
        *(float *)(p + 92) = x;
        if (p[486] != 0) {
            y = 0.625f;
        } else {
            y = -0.625f;
        }
        *(float *)(p + 104) = y;
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
    }
}

void func_002D2890(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
        *(float *)(p + 92) = -15.833333f;
        *(float *)(p + 104) = 0.3125f;
        if (p[486] != 0) {
            *(float *)(p + 92) = -*(float *)(p + 92);
            *(float *)(p + 104) = -*(float *)(p + 104);
        }
    }
}

void func_002D2A40(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
        *(float *)(p + 92) = 15.833333f;
        *(float *)(p + 104) = -0.3125f;
        if (p[486] != 0) {
            *(float *)(p + 92) = -*(float *)(p + 92);
            *(float *)(p + 104) = -*(float *)(p + 104);
        }
    }
}

void func_0024F1B0(u8 *p)
{
    float x, y;
    func_00175700(p);
    p[6]++;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    if (p[486] != 0)
        x = 15.833333f;
    else
        x = -15.833333f;
    *(float *)(p + 92) = x;
    if (p[486] != 0)
        y = -0.3125f;
    else
        y = 0.3125f;
    *(float *)(p + 104) = y;
    *(short *)(p + 28) = 14;
}

void func_0024F4D0(u8 *p)
{
    float x, y;
    p[6]++;
    func_00175700(p);
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    if (p[486] != 0)
        x = -21.666666f;
    else
        x = 21.666666f;
    *(float *)(p + 92) = x;
    if (p[486] != 0)
        y = 0.1041666641831398f;
    else
        y = -0.1041666641831398f;
    *(float *)(p + 104) = y;
    *(short *)(p + 28) = 4;
}

void func_002A8A80(u8 *p)
{
    float x, y;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        if (p[486] != 0)
            x = -15.833333f;
        else
            x = 15.833333f;
        *(float *)(p + 92) = x;
        if (p[486] != 0)
            y = 0.625f;
        else
            y = -0.625f;
        *(float *)(p + 104) = y;
        *(float *)(p + 96) = 5.0f;
        *(float *)(p + 108) = -0.8333333f;
    }
}

void func_00245490(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        *(float *)(p + 92) = 20.0f;
        *(float *)(p + 104) = -0.3125f;
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
        if (p[486] != 0) {
            *(float *)(p + 92) = -*(float *)(p + 92);
            *(float *)(p + 104) = -*(float *)(p + 104);
        }
    }
}

void func_002452E0(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        *(float *)(p + 92) = -16.666666f;
        *(float *)(p + 104) = 0.2604166567325592f;
        *(float *)(p + 96) = 6.428571f;
        *(float *)(p + 108) = -0.53571427f;
        if (p[486] != 0) {
            *(float *)(p + 92) = -*(float *)(p + 92);
            *(float *)(p + 104) = -*(float *)(p + 104);
        }
    }
}

void func_0022E230(u8 *p)
{
    float x, y;
    p[6]++;
    *(volatile int *)(p + 92) = 0;
    *(volatile int *)(p + 96) = 0;
    *(volatile int *)(p + 104) = 0;
    *(volatile int *)(p + 108) = 0;
    if (p[486] != 0)
        x = -13.333333f;
    else
        x = 13.333333f;
    *(float *)(p + 92) = x;
    if (p[486] != 0)
        y = -0.104166664f;
    else
        y = 0.104166664f;
    *(float *)(p + 104) = y;
    func_0022E2B0(p);
}

void func_002B3EE0(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(int *)(p + 96) = 0;
        *(int *)(p + 108) = 0;
        *(short *)(p + 28) = 20;
        if (p[486] != 0) {
            *(float *)(p + 92) = 10.833333f;
            *(float *)(p + 104) = -0.2083333283662796f;
        } else {
            *(float *)(p + 92) = -10.833333f;
            *(float *)(p + 104) = 0.2083333283662796f;
        }
    }
}

void func_002B4150(u8 *p)
{
    float x, y;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(short *)(p + 28) = 16;
        *(int *)(p + 96) = 0;
        *(int *)(p + 108) = 0;
        if (p[486] != 0)
            x = -12.5f;
        else
            x = 12.5f;
        *(float *)(p + 92) = x;
        if (p[486] != 0)
            y = 0.3125f;
        else
            y = -0.3125f;
        *(float *)(p + 104) = y;
        func_002B41F0(p);
    }
}

void func_002E5930(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 337)) {
        p[6]++;
        *(short *)(p + 28) = 30;
        *(float *)(p + 92) = -10.0f;
        *(float *)(p + 104) = 0.0f;
        if (p[486] != 0)
            *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 96) = 0.0f;
        *(float *)(p + 108) = 0.0f;
    }
}

void func_002F3620(u8 *p)
{
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(int *)(p + 96) = 0;
        *(int *)(p + 108) = 0;
        *(float *)(p + 92) = -13.333333f;
        *(float *)(p + 104) = 0.3125f;
        if (p[486] != 0) {
            *(float *)(p + 92) = -*(float *)(p + 92);
            *(float *)(p + 104) = -*(float *)(p + 104);
        }
        *(short *)(p + 28) = 16;
    }
}

void func_002F3810(u8 *p)
{
    float speed;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        *(float *)(p + 96) = 8.571428298950195f;
        *(float *)(p + 108) = -0.8035714030265808f;
        if (p[486] != 0)
            speed = -10.0f;
        else
            speed = 10.0f;
        *(float *)(p + 92) = speed;
    }
}

void func_00282FD0(u8 *p)
{
    float speed;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        if (p[486] != 0)
            speed = -10.0f;
        else
            speed = 10.0f;
        *(float *)(p + 92) = speed;
    }
}

void func_00270330(u8 *p)
{
    float speed;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        if (p[486] != 0)
            speed = 16.666666f;
        else
            speed = -16.666666f;
        *(float *)(p + 92) = speed;
        *(float *)(p + 104) = 0.0f;
        *(short *)(p + 30) = 20;
    }
}

void func_0027D8D0(u8 *p)
{
    float speed;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        if (p[486] != 0)
            speed = 10.833333f;
        else
            speed = -10.833333f;
        *(float *)(p + 92) = speed;
    }
}

void func_0026C560(u8 *p)
{
    float speed;
    func_00175700(p);
    if (!*(signed char *)(p + 337)) {
        p[6]++;
        *(volatile int *)(p + 92) = 0;
        *(volatile int *)(p + 96) = 0;
        *(volatile int *)(p + 104) = 0;
        *(volatile int *)(p + 108) = 0;
        if (p[486] != 0)
            speed = 11.666666f;
        else
            speed = -11.666666f;
        *(float *)(p + 92) = speed;
        *(short *)(p + 28) = 16;
    }
}
