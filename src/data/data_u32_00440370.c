typedef struct { float x,y,z; } CardPosition;
typedef char CardPosition_size12[(sizeof(CardPosition)==12)?1:-1];
typedef struct { CardPosition position, alternate_position; } CardPositionPair;
typedef char Pair_size24[(sizeof(CardPositionPair)==24)?1:-1];
CardPositionPair data_u32_00440370[2][3] = {
    {
        { { -10.0f, 64.0f, 43.90000152587891f }, { 10.0f, 58.0f, 43.90000152587891f } },
        { { -30.0f, 67.0f, 43.90000152587891f }, { -10.0f, 61.0f, 43.90000152587891f } },
        { { -40.0f, 72.0f, 43.90000152587891f }, { -20.0f, 65.0f, 43.90000152587891f } },
    },
    {
        { { 10.0f, 64.0f, 43.90000152587891f }, { -10.0f, 58.0f, 43.90000152587891f } },
        { { 30.0f, 67.0f, 43.90000152587891f }, { 10.0f, 61.0f, 43.90000152587891f } },
        { { 40.0f, 72.0f, 43.90000152587891f }, { 20.0f, 65.0f, 43.90000152587891f } },
    },
};
