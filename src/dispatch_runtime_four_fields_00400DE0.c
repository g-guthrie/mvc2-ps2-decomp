typedef signed int s32;

extern s32 func_0040AB68(s32 first, s32 second, s32 third, s32 fourth);

s32 func_00400DE0(const s32 *record)
{
    s32 result = 0;

    if (record != 0) {
        result = func_0040AB68(record[0], record[2], record[3], record[1]);
    } else {
        func_0040AB68(0, 0, 0, 0);
    }

    return result;
}
