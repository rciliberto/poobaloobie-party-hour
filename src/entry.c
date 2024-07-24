#include "core/window.c"
#include "core/frame_timing.c"
#include "scoring/scoring.c"
#include "entity.c"
#include "scene/scene.c"
#include "scene/scenes/gymnasium.c"
#include "user_interface/user_interface.c"

Scene *scene;

int entry(int argc, char **argv) {
    const Allocator allocator = get_heap_allocator();
    window_init();

    init_entity_gfx();
    frame_data_initialize();

    scene = alloc(allocator, sizeof(Scene));
    init_gymnasium_scene(scene);

    Gfx_Font *font = load_font_from_disk(STR("C:/windows/fonts/arial.ttf"), allocator);
    assert(font, "Failed loading arial.ttf, %lu", GetLastError());

    while (!window.should_close) {
        reset_temporary_storage();
        window_frame_update();
        frame_data_calculate();
        os_update();

        if (frame_data.fixed_update_counter == 0) {
            scene->scoring_context.party_points +=
                total_score_contribution(&scene->scoring_context) * FIXED_UPDATE_RATE;
        }

        scene_draw_background(scene);
        scene_draw_entities(scene);
        // ui_draw();
        draw_text(font, sprintf(temp_allocator, "Party Points: %.2f", scene->scoring_context.party_points), 16, v2(-150, 270),
                  v2(2, 2), COLOR_BLUE);


        gfx_update();

        if (is_key_just_pressed('F')) {
            frame_data_log_fps();
        }

        if (is_key_just_pressed('P')) {
            for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
                Entity *e = &scene->entities[i];
                if (!e->valid) {
                    break;
                }

                if (e->type == entity_punch_table) {
                    e->visible = !e->visible;
                }
            }
        }

        if (is_key_just_pressed('B')) {
            for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
                Entity *e = &scene->entities[i];
                if (!e->valid) {
                    break;
                }

                if (e->type == entity_balloon) {
                    e->visible = !e->visible;
                }
            }
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

        if (is_key_just_pressed('1')) {
            scene->scoring_context.score_sources[0].number_held++;
        }
        if (is_key_just_pressed('2')) {
            scene->scoring_context.score_sources[1].number_held++;
        }
        if (is_key_just_pressed('3')) {
            scene->scoring_context.score_sources[2].number_held++;
        }
    }

    return 0;
}
