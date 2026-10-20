typedef unsigned char u8;
extern void func_00102F98(void *destination);
extern void func_00102CE8(void *destination, const void *first, const void *second);
extern void func_00102D30(void *destination, const void *source);
extern void func_00102EF0(void *destination, const void *matrix, const void *offset);
extern void func_00102DB8(void *destination, const void *matrix);
void func_001032A8(void *destination, const void *offset, const void *up, const void *forward) {
    u8 matrix[0x50];
    func_00102F98(matrix);
    func_00102CE8(matrix + 0x40, forward, up);
    func_00102D30(matrix, matrix + 0x40);
    func_00102D30(matrix + 0x20, up);
    func_00102CE8(matrix + 0x10, matrix + 0x20, matrix);
    func_00102EF0(matrix, matrix, offset);
    func_00102DB8(destination, matrix);
}
