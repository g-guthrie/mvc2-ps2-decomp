typedef unsigned int u32;
typedef struct Resource { u32 header[2]; const unsigned char *format; u32 fields[2]; u32 *samples; } Resource;
extern int func_004166F0(unsigned char *);
void func_00416570(Resource *resource)
{
    u32 *samples = resource->samples;
    int count = func_004166F0((unsigned char *)resource);
    int format = ((unsigned int)resource->format[0x12] << 8) | resource->format[0x13];
    int i;
    switch (format) { case 0x8105: case 0x8205: case 0x8305:
        for (i = 0; i < count; ++i) {
            int channel = i & 31;
            if (channel >= 8 && channel < 16) {
                int j = i + 8;
                u32 value = samples[i];
                samples[i] = samples[j];
                samples[j] = value;
            }
        }
        break;
    }
}
