typedef float f32;
extern void func_00103038(void *a0, void *a1, f32 value);
extern void func_00103188(void *a0, void *a1, f32 value);
extern void func_001030E0(void *a0, void *a1, f32 value);
void func_00103230(void *destination, void *initial, const f32 *values) {
    func_00103038(destination, initial, values[2]);
    func_00103188(destination, destination, values[1]);
    func_001030E0(destination, destination, values[0]);
}
