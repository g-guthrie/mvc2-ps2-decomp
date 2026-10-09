typedef unsigned int u32;
typedef signed int s32;

struct ArchiveSegment
{
    const char *data;
    s32 checksum;
};

extern s32 func_004105D8(const char *data);

void func_004106E8(const char *data, struct ArchiveSegment *segment)
{
    segment->data = data + 16;
    segment->checksum = func_004105D8(data + 8);
}
