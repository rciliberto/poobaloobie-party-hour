#include "window.c"
#include "frame_timing.c"
#include "entity.c"
#include "scene.c"
#include "scenes/gymnasium.c"

Scene scene;

int entry(int argc, char **argv) {
    window_init();

    init_entity_gfx();
    init_gymnasium_scene(&scene);

    while (!window.should_close) {
        reset_temporary_storage();
        window_frame_update();
        frame_data_calculate();
        os_update();

        scene_draw_background(&scene);
        scene_draw_entities(&scene);

        Matrix4 hammer_xform = m4_scalar(1.0);
        hammer_xform         = m4_rotate_z(hammer_xform, frame_data.now);
        hammer_xform         = m4_translate(hammer_xform, v3(-25, -25, 0));
        draw_rect_xform(hammer_xform, v2(50, 50), COLOR_RED);

        gfx_update();

#if CONFIGURATION != RELEASE
        frame_data_log_fps();
#endif

    }

    return 0;
}