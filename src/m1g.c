typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


s32 func_001B4B30(u8 *p) {
if (*(u16 *)(p + 0xD0) != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
p[6] = 3;
switch (p[0x20]) {
case 0xD:
p[0x24] = 0xC;
break;
case 0xE:
p[0x24] = 7;
break;
case 0xF:
p[0x24] = 7;
break;
}
if (*(f32 *)(p + 0x5C) < 0.0f) {
*(s16 *)(p + 0x140) = 0;
} else {
*(s16 *)(p + 0x140) = 1;
}
return 1;
}
return 0;
}
