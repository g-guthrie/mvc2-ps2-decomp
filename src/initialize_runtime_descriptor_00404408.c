typedef signed int s32;

s32 func_00404408(s32 *object, s32 first, s32 second, s32 third)
{
    if (object[3] == 0) {
        object[6] = first;
        object[7] = second;
        object[8] = third;
        object[5] = 1;
        object[9] = 0;
        return 1;
    }

    return 0;
}
