#include "action_record.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern void func_00176160(u8 *, int, int, int);
void func_0028D810(u8 *p, u8 *record)
{
    u8 *state = p + 696;
    Mvc2ActionRecord *row = (Mvc2ActionRecord *)record;
    do {
        state[14] = row->delay;
        func_00176160(p, row->mode, row->source_frame + p[37] * 87, row->copy_count);
        if (row->cursor_stride == 1) state[15] = 0;
        else state[15] = 1;
        row += row->cursor_stride;
    } while (state[14] == 0);
    *(u8 **)(state + 16) = (u8 *)row;
}
void func_00294B20(u8 *p, u8 *record)
{
    u8 *state = p + 696;
    Mvc2ActionRecord *row = (Mvc2ActionRecord *)record;
    do {
        state[14] = row->delay;
        func_00176160(p, row->mode, row->source_frame + p[37] * 87, row->copy_count);
        if (row->cursor_stride == 1) state[15] = 0;
        else state[15] = 1;
        row += row->cursor_stride;
    } while (state[14] == 0);
    *(u8 **)(state + 16) = (u8 *)row;
}
