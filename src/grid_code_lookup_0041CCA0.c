typedef signed short s16;
extern s16 D_00633720[][8];
int func_0041CCA0(s16 code,s16 *column,s16 *row)
{
    int y,x;
    for(y=0;y<8;y++) {
        for(x=0;x<8;x++) {
            if((D_00633720[x][y]&0x3f)==code) {
                *column=x;
                *row=y;
                return 1;
            }
        }
    }
    return 0;
}
