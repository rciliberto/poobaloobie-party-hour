typedef struct ScoringContext ScoringContext;

#include "score_source.c"
#include "bonus_modifier.c"

#define MAX_PASSIVE_SOURCES 25
#define MAX_MODIFIERS 25

/**
 * Struct that holds the scoring context for the scene. Contains information about current points and point sources that
 * the player owns.
 */
struct ScoringContext {
    /** The number of party points currently accrued by the player. */
    float64 party_points;

    /** The current party power mulitplier applied to score calculations. */
    float64 party_power;

    /** The max party power that a player can have. */
    float64 max_party_power;

    /**
     * The different score sources that contribute to the player's score. Score sources are indexed based on their
     * source identity, an integer that represents the order of power of the source. This allows bonus modifiers to
     * find the source that they may be modifying by index and calculate how much of a bonus they contribute.
     */
    ScoreSource score_sources[MAX_PASSIVE_SOURCES];

    /** The bonus modifiers accrued by the player. */
    BonusModifier bonus_modifiers[MAX_MODIFIERS];
};

/**
 * Calculate the contribution of all score sources in the current context in points per second.
 * @param context The current scoring context.
 * @return The contribution per second that all score sources provide.
 */
float64 total_score_source_contribution(const ScoringContext *context) {
    float64 sum = 0;
    for (int i = 0; i < MAX_PASSIVE_SOURCES; i++) {
        const ScoreSource *source = (ScoreSource *) &context->score_sources[i];
        if (source->valid) {
            sum += score_source_contribution(source);
        }
    }

    return sum;
}

/**
 * Calculate the contribution of all bonus modifiers in the current context in points per second.
 * @param context The current scoring context.
 * @return The contribution per second that all bonus modifiers provide
 */
float64 total_bonus_modifier_contribution(const ScoringContext *context) {
    float64 sum = 0;
    for (int i = 0; i < MAX_PASSIVE_SOURCES; i++) {
        if (context->bonus_modifiers[i] == NULL) {
            break;
        }

        sum += (*context->bonus_modifiers[i])(context);
    }

    return sum;
}

/**
 * Calculate the total score contribution of the current scoring context in points per second.
 * @param context The current scoring context.
 * @return The total contribution per second of the current scoring context.
 */
float64 total_score_contribution(const ScoringContext *context) {
    const float64 source_contribution = total_score_source_contribution(context);
    const float64 bonus_contribution = total_bonus_modifier_contribution(context);

    const float64 total_contribution = source_contribution + bonus_contribution;

    const float64 contribution_per_frame = context->party_power * total_contribution;
    return contribution_per_frame;
}
