#include "window.c"
#include "frame_timing.c"
#include "entity.c"
#include "scene.c"
#include "scenes/gymnasium.c"
#include "scoring/scoring.c"

Scene *scene;
ScoringContext scoring_context;

int entry(int argc, char **argv) {
    window_init();

    init_entity_gfx();
    frame_data_initialize();
    scene = init_gymnasium_scene();

    Gfx_Font *font = load_font_from_disk(STR("C:/windows/fonts/arial.ttf"), get_heap_allocator());
    assert(font, "Failed loading arial.ttf, %d", GetLastError());

    scoring_context.party_points = 0;
    scoring_context.passive_sources[0].valid = true;
    scoring_context.passive_sources[0].number_held = 1;
    scoring_context.passive_sources[0].points_per_second = 1;

    while (!window.should_close) {
        reset_temporary_storage();
        window_frame_update();
        frame_data_calculate();
        os_update();

        if (frame_data.fixed_update_counter == 0) {
            scoring_context.party_points += calculate_scoring_fixed(&scoring_context);
        }

        scene_draw_background(scene);
        scene_draw_entities(scene);
        draw_text(font, sprintf(get_heap_allocator(), "Party Points: %.2f", scoring_context.party_points), 32, v2(0, 0), v2(1, 1), COLOR_BLACK);


        gfx_update();

        if (is_key_just_released('P')) {
            frame_data_log_fps();
        }
    }

    return 0;
}
