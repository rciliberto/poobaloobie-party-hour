typedef struct PassiveScoreSource {
    bool valid;
    float64 points_per_second;
    u32 number_held;
} PassiveScoreSource;

float64 passive_score_source_contribution(const PassiveScoreSource *source) {
    return source->valid * source->points_per_second * source->number_held;
}

