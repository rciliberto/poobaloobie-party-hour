#include "window.c"
#include "frame_timing.c"
#include "scoring/scoring.c"
#include "entity.c"
#include "scene.c"
#include "scenes/gymnasium.c"

Scene *scene;

int entry(int argc, char **argv) {
    Allocator allocator = get_heap_allocator();
    window_init();

    init_entity_gfx();
    frame_data_initialize();

    scene = alloc(allocator, sizeof(Scene));
    init_gymnasium_scene(scene);

    Gfx_Font *font = load_font_from_disk(STR("C:/windows/fonts/arial.ttf"), allocator);
    assert(font, "Failed loading arial.ttf, %d", GetLastError());

    while (!window.should_close) {
        reset_temporary_storage();
        window_frame_update();
        frame_data_calculate();
        os_update();

        if (frame_data.fixed_update_counter == 0) {
            scene->scoring_context.party_points += total_score_contribution(&scene->scoring_context) *
                    FIXED_UPDATE_RATE;
        }

        scene_draw_background(scene);
        scene_draw_entities(scene);
        // ui_draw();
        draw_text(font, sprintf(allocator, "Party Points: %.2f", scene->scoring_context.party_points), 16, v2(0, 0),
                  v2(2, 2), COLOR_BLUE);


        gfx_update();

        if (is_key_just_released('P')) {
            frame_data_log_fps();
        }

        if (is_key_down('A')) {
            scene->entities[0].position.x -= 30 * frame_data.delta_t;
        }
        if (is_key_down('D')) {
            scene->entities[0].position.x += 30 * frame_data.delta_t;
        }
        if (is_key_down('S')) {
            scene->entities[0].position.y -= 30 * frame_data.delta_t;
        }
        if (is_key_down('W')) {
            scene->entities[0].position.y += 30 * frame_data.delta_t;
        }
    }

    return 0;
}
