#include "window.c"
#include "frame_timing.c"
#include "entity.c"
#include "scene.c"
#include "scenes/gymnasium.c"

Scene *scene;

int entry(int argc, char **argv) {
    window_init();

    init_entity_gfx();
    scene = init_gymnasium_scene();

    while (!window.should_close) {
        reset_temporary_storage();
        window_frame_update();
        frame_data_calculate();
        os_update();

        scene_draw_background(scene);
        scene_draw_entities(scene);


        gfx_update();

        if (is_key_just_released('P')) {
            frame_data_log_fps();
        }
    }

    return 0;
}