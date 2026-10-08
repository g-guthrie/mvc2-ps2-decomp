typedef unsigned char u8;

extern void func_00243360(u8 *);
extern void func_002405A0(u8 *);
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
