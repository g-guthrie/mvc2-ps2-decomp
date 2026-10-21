/* Newlib readonly double +0, retaining the native eight-byte object. */
typedef char DoubleWidthMustBe8[sizeof(double)==8 ? 1 : -1];
const double gNewlibKernelZero_004AC078 = 0.0;
