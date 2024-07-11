typedef struct ScoringContext ScoringContext;

#include "passive_score_source.c"
#include "score_source_modifiers.c"

#define MAX_PASSIVE_SOURCES 25
#define MAX_MODIFIERS_PER_SOURCE 25

struct ScoringContext {
    float64 party_points;
    float64 party_power;
    float64 max_party_power;

    PassiveScoreSource passive_sources[MAX_PASSIVE_SOURCES];
    int source_modifiers[MAX_PASSIVE_SOURCES][MAX_MODIFIERS_PER_SOURCE];
};

float64 passive_score_base_contribution(const ScoringContext *context) {
    float64 sum = 0;
    for (int i = 0; i < MAX_PASSIVE_SOURCES; i++) {
        const PassiveScoreSource *source = (PassiveScoreSource *) &context->passive_sources[i];
        if (source->valid) {
            sum += passive_score_source_contribution(source);
        }
    }

    return sum;
}

float64 calculate_scoring_fixed(const ScoringContext *context) {
    const float64 base_contribution = passive_score_base_contribution(context);
    const float64 modifier_contribution = 0; //TODO calculate modifier contribution

    const float64 total_contribution = base_contribution + modifier_contribution;

    return FIXED_UPDATE_RATE * context->party_power * total_contribution;
}
