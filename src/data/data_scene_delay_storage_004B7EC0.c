typedef struct { float x, y, z; } ScenePosition;

/* Native delay row 11 overlaps the first position vector. These are two
 * views of the same bytes, not independently owned overlapping objects. */
union SceneDelayStorage {
    struct { signed short prefix[56]; ScenePosition positions[3]; } physical;
    signed short delay_rows[12][5];
};
union SceneDelayStorage gSceneDelayStorage_004B7EC0 = {
    {
        { 20, 10, 40, 50, 30, 10, 30, 20, 40, 50, 50, 30, 20, 10, 40, 40, 50, 10, 30, 20, 10, 30, 0, 20, 0, 20, 0, 10, 30, 0, 30, 0, 20, 0, 10, 10, 0, 20, 0, 30, 30, 10, 0, 20, 0, 0, 0, 10, 30, 20, 0, 20, 30, 0, 10, 0 },
        { { -200.0f, 9.60000038f, -154.0f }, { 0.0f, 9.60000038f, -124.0f }, { 300.0f, 9.60000038f, -94.0f } }
    }
};
typedef char SceneDelayStorage_size[sizeof(union SceneDelayStorage) == 148 ? 1 : -1];
