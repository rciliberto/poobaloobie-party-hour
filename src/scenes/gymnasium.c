/**
 * Initialize the Gymnasium scene. Deactivates entities in the gymnasium scene and re-adds entities to their default
 * state.
 * @return The scene pointer to with gymnasium data.
 */
void init_gymnasium_scene(Scene *scene) {
    assert(scene != NULL, "Cannot initialize null scene");

    const Allocator allocator = get_heap_allocator();

    if (scene->background_image == NULL) {
        scene->background_image = load_image_from_disk(STR("assets/dev_background_720p.png"), allocator);
        assert(scene->background_image, "Gymnasium background image failed to load");
    }

    memset(scene->entities, 0, sizeof(Entity) * ENTITY_MAX);

    scene->entities[0] = (Entity) {
        .valid = true,
        .type = entity_poobaloobie,
        .position = v2(-16, -16),
        .visible = true
    };


    scene->scoring_context = (ScoringContext) {
        .party_points = 0,
        .party_power = 1.0,
        .score_sources = {
            (ScoreSource) {
                .valid = true,
                .number_held = 50,
                .points_per_second = 1,
            }
        }
    };
}

