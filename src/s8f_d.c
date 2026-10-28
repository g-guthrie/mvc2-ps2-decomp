/* s8f: MW 3.0, ./try30.sh src/s8f_d.c "-O3,p -sdatathreshold 8". func_00175B40 is a static verbatim copy of the real leaf callee credited in src/copy_animation_records_00175B40.c. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x13E]; s16 h13E; } PH;
extern u8 D_004F54D0[];
extern s8 data_s8_004ACD08[];
extern u8 *D_004C2840;

static void func_00175B40(void *context, u8 *destination, const u16 *source, int count) {
 u16 *data;
 int i,j;
 for(i=0;i<count;i++) {
  data=(u16 *)(destination+16);
  *(u32 *)(destination+8)=1;
  for(j=0;j<16;j+=8) {
   data[0]=source[0];
   data[1]=source[1];
   data[2]=source[2];
   data[3]=source[3];
   data[4]=source[4];
   data[5]=source[5];
   data[6]=source[6];
   data[7]=source[7];
   data+=8;
   source+=8;
  }
  destination+=48;
 }
 for(;i<8;i++) {
  *(u32 *)(destination+8)=1;
  destination+=48;
 }
}

void func_00175C00(u8 *p, s32 mode)
{
    extern u16 *func_00175A30(u8 *);
    u8 *d = D_004F54D0 + *(s16 *)(p + 0x13E) * 0x30;
    u16 *src;
    u16 *data;
    s32 i, j;

    switch (mode) {
    default:
    case 0:
        ((PH *)p)->h13E = data_s8_004ACD08[p[0x1B8]];
        src = func_00175A30(p);
        *(u32 *)(d + 8) = 1;
        data = (u16 *)(d + 0x10);
        for (j = 0; j < 16; j += 8) {
            data[0] = src[0];
            data[1] = src[1];
            data[2] = src[2];
            data[3] = src[3];
            data[4] = src[4];
            data[5] = src[5];
            data[6] = src[6];
            data[7] = src[7];
            data += 8;
            src += 8;
        }
        d += 0x30;
        src = (u16 *)(*(u8 **)(p + 0x174) + ((p[0x25] * 8 + 1) << 5));
        for (i = 1; i < 8; i++) {
            *(u32 *)(d + 8) = 1;
            data = (u16 *)(d + 0x10);
            for (j = 0; j < 16; j += 8) {
                data[0] = src[0];
                data[1] = src[1];
                data[2] = src[2];
                data[3] = src[3];
                data[4] = src[4];
                data[5] = src[5];
                data[6] = src[6];
                data[7] = src[7];
                data += 8;
                src += 8;
            }
            d += 0x30;
        }
        return;
    case 8:
        for (i = 0; i < (s8)p[0x30]; i++) {
            *(u32 *)(d + 8) = 1;
            data = (u16 *)(d + 0x10);
            data++;
            for (j = 1; j < 16; j++) {
                *data++ = 0xFFFF;
            }
            d += 0x30;
        }
        break;
    case 9:
        for (i = 0; i < (s8)p[0x30]; i++) {
            *(u32 *)(d + 8) = 1;
            data = (u16 *)(d + 0x10);
            data++;
            for (j = 1; j < 16; j++) {
                *data++ = 0xFF00;
            }
            d += 0x30;
        }
        break;
    case 3:
        if (p[1] == 0x14 && p[0x216] != 0) {
            src = (u16 *)(*(u8 **)(p + 0x174) + ((s8)p[0x30] * 128 + 0x300) * 2 + ((p[0x25] + 0xE) << 5));
            func_00175B40(p, d, src, (s8)p[0x30]);
            break;
        }
    case 4:
    case 5:
    case 6:
        i = ((s8)p[0x30] * 16 * ((*(u32 *)(D_004C2840 + 0x1C) & 1) + (mode - 3) * 2) + 0x300);
        src = (u16 *)*(u8 **)(p + 0x174) + i;
        func_00175B40(p, d, src, (s8)p[0x30]);
        break;
    case 7:
        i = ((s8)p[0x30] * 16 * ((*(u32 *)(D_004C2840 + 0x1C) & 1) * 2 + 3) + 0x300);
        src = (u16 *)*(u8 **)(p + 0x174) + i;
        func_00175B40(p, d, src, (s8)p[0x30]);
        break;
    case 2:
        for (i = 0; i < 8; i++) {
            *(u32 *)(d + 8 + i * 0x30) = 2;
        }
        break;
    case 10:
        for (i = 0; i < 8; i++) {
            *(u32 *)(d + 8 + i * 0x30) = 1;
        }
        break;
    case 1:
        {
            u16 *s2;
            ((PH *)p)->h13E = data_s8_004ACD08[p[0x1B8]];
            s2 = func_00175A30(p);
        switch (p[1]) {
        case 0x14:
        case 0x1C:
        case 0x1D:
            func_00175B40(p, d, s2, (s8)p[0x30] + 2);
            break;
        case 0x2D:
            func_00175B40(p, d, s2, (s8)p[0x30] + 1);
            break;
        default:
            func_00175B40(p, d, s2, (s8)p[0x30]);
            break;
        }
        }
        break;
    }
}
