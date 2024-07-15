typedef struct ScoreSource {
    bool valid;
    float64 points_per_second;
    u32 number_held;
} ScoreSource;

float64 score_source_contribution(const ScoreSource *source) {
    return source->valid * source->points_per_second * source->number_held;
}

