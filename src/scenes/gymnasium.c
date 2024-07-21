/**
 * Initialize the Gymnasium scene. Deactivates entities in the gymnasium scene and re-adds entities to their default
 * state.
 * @return The scene pointer to with gymnasium data.
 */
void init_gymnasium_scene(Scene *scene) {
    assert(scene != NULL, "Cannot initialize null scene");

    const Allocator allocator = get_heap_allocator();

    // Deallocate previous data
    if (scene->background_image != NULL) {
        dealloc(allocator, scene->background_image);
    }

    Gfx_Image *background = load_image_from_disk(STR("res/dev_background_720p.png"), allocator);
    assert(background, "Gymnasium background image failed to load");

    *scene = (Scene) {
        .background_image = background,
        .entities = {
            (Entity) {
                .valid = true,
                .type = entity_poobaloobie,
                .position = v2(-150, -300),
                .visible = true
            },
            (Entity) {
                .valid = true,
                .type = entity_balloon,
                .position = v2(-300, 25),
                .visible = true
            },
            (Entity) {
                .valid = true,
                .type = entity_balloon,
                .position = v2(-150, 50),
                .visible = true
            },
            (Entity) {
                .valid = true,
                .type = entity_balloon,
                .position = v2(150, -20),
                .visible = true
            },
            (Entity) {
                .valid = true,
                .type = entity_balloon,
                .position = v2(300, -60),
                .visible = true
            },
            (Entity) {
                .valid = true,
                .type = entity_punch_table,
                .position = v2(300, -250),
                .visible = false
            },
        },
        .scoring_context = (ScoringContext) {
            .party_points = 0,
            .party_power = 1.0,
            .score_sources = {
                (ScoreSource) {
                    .valid = true,
                    .number_held = 0,
                    .points_per_second = 1,
                },
                (ScoreSource) {
                    .valid = true,
                    .number_held = 0,
                    .points_per_second = 100,
                },
                (ScoreSource) {
                    .valid = true,
                    .number_held = 0,
                    .points_per_second = 1000,
                }
            }
        }
    };
}

