typedef unsigned int u32;
struct ArchiveSegment
{
    const char *data;
    u32 length;
};

extern u32 func_004105D8(const char *data);

void func_004106E8(const char *data, struct ArchiveSegment *segment)
{
    segment->data = data + 16;
    segment->length = func_004105D8(data + 8);
}
