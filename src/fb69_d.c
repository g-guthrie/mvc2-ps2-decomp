typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004779F0[];

#define SET(n, t) do { p->id = (n); p->tbl = D_004779F0 + 0x30 * (t); } while (0)

typedef struct { u32 pad0; u32 w4; u32 w8; u32 wC; u8 pad[0x2C]; s32 id; u8 *tbl; } S_d;

void func_003E0F60(S_d *p) {
    u32 low;
    u32 key;
    u32 top;
    u32 w;
    p->id = -1;
    p->tbl = 0;
    w = p->wC;
    key = p->w4 | p->w8;
    top = w & 0xFF000000;
    low = w & 0xFFFFFF;
    switch (top) {
    case 0:
        switch (low) {
            case 0x102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(0, 0);
                    break;
                case 0x521235:
                case 0x121235:
                    SET(1, 1);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(2, 2);
                    break;
                }
                break;
            case 0x20102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(3, 3);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(4, 4);
                    break;
                }
                break;
            case 0x106:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(5, 5);
                    break;
                case 0x521235:
                case 0x121235:
                    SET(6, 6);
                    break;
                }
                break;
            case 0x100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(7, 7);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(8, 8);
                    break;
                }
                break;
            case 0x20100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(9, 9);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(10, 10);
                    break;
                }
                break;
            case 0x0:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(11, 11);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(12, 12);
                    break;
                }
                break;
            case 0x2:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(13, 13);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(14, 14);
                    break;
                }
                break;
            case 0x20000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(15, 15);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(16, 16);
                    break;
                }
                break;
            case 0x20002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(17, 17);
                    break;
                case 0x21025:
                case 0x421025:
                    SET(18, 18);
                    break;
                }
                break;
            case 0x142:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(19, 19);
                    break;
                }
                break;
            case 0x8102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(20, 20);
                    break;
                }
                break;
            case 0x28102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(21, 21);
                    break;
                }
                break;
            case 0x8100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(22, 22);
                    break;
                }
                break;
            case 0x8000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(23, 23);
                    break;
                }
                break;
            case 0x8002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(24, 24);
                    break;
                }
                break;
            case 0x28100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(25, 25);
                    break;
                }
                break;
            case 0x28000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(26, 26);
                    break;
                }
                break;
            case 0x28002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(27, 27);
                    break;
                }
                break;
            case 0x4102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(28, 28);
                    break;
                }
                break;
            case 0x24102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(29, 29);
                    break;
                }
                break;
            case 0x4100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(30, 30);
                    break;
                }
                break;
            case 0x24100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(31, 31);
                    break;
                }
                break;
            case 0x4002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(32, 32);
                    break;
                }
                break;
            case 0x24002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(33, 33);
                    break;
                }
                break;
            case 0x4000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(34, 34);
                    break;
                }
                break;
            case 0x24000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(35, 35);
                    break;
                }
                break;
            case 0xc102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(36, 36);
                    break;
                }
                break;
            case 0x2c102:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(37, 37);
                    break;
                }
                break;
            case 0xc100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(38, 38);
                    break;
                }
                break;
            case 0x2c100:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(39, 39);
                    break;
                }
                break;
            case 0xc002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(40, 40);
                    break;
                }
                break;
            case 0x2c002:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(41, 41);
                    break;
                }
                break;
            case 0xc000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(42, 42);
                    break;
                }
                break;
            case 0x2c000:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(44, 43);
                    break;
                }
                break;
            case 0x28040:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(45, 44);
                    break;
                }
                break;
            case 0x2c040:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(46, 45);
                    break;
                }
                break;
            case 0x2c140:
                switch (key) {
                case 0x21035:
                case 0x421035:
                    SET(47, 46);
                    break;
                }
                break;
        }
        break;
    case 0x01000000:
        switch (key) {
        case 0x21025:
            SET(48, 47);
            break;
        }
        break;
    case 0x06000000:
        switch (key) {
        case 0x521235:
        case 0x121235:
            SET(49, 48);
            break;
        }
        break;
    }
}
