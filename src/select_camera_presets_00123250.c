extern signed char D_004F1F47, D_004F1F48, D_004F1F49;
extern signed char D_004F2034, D_004F2035, D_004F2036, D_004F2037;
extern const void * const D_0043CB30[5], * const D_0043CB50[5];
extern float D_004F1F4C, D_004F1F50, D_004F1F54, D_004F1F94, D_004F1F98, D_004F1F9C;
extern float D_004F2004, D_004F2008, D_004F200C, D_004F2010, D_004F2014, D_004F2018;
extern float D_004C9F50, D_004C9F54, D_004C9F58, D_004C9F40, D_004C9F44, D_004C9F48;
void func_00123250(void)
{
    const float *first, *second;
    float x, y, z, target_x, target_y, target_z;
    ++D_004F1F47;
    first = D_0043CB30[D_004F1F48];
    second = D_0043CB50[D_004F1F48];
    D_004F2034 = 0;
    D_004F2035 = 0;
    D_004F2036 = 0;
    D_004F2037 = 0;
    D_004F1F4C = first[0]; x = D_004F1F4C;
    D_004F1F50 = first[1]; y = D_004F1F50;
    D_004F1F54 = first[2]; z = D_004F1F54;
    D_004F1F94 = first[3]; target_x = D_004F1F94;
    D_004F1F98 = first[4]; target_y = D_004F1F98;
    D_004F1F9C = first[5]; target_z = D_004F1F9C;
    D_004F2004 = second[0];
    D_004F2008 = second[1];
    D_004F200C = second[2];
    D_004F2010 = second[3];
    D_004F2014 = second[4];
    D_004F2018 = second[5];
    D_004C9F50 = x;
    D_004C9F54 = y;
    D_004C9F58 = z;
    D_004C9F40 = target_x;
    D_004C9F44 = target_y;
    D_004C9F48 = target_z;
    D_004F1F49 = 1;
}
