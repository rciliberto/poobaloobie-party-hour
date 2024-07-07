#include "window.c"
#include "frame_timing.c"

int entry(int argc, char **argv) {
    window_init();

    while (!window.should_close) {
        reset_temporary_storage();
        window_update_start();
        frame_calculation_update();
        os_update();

        draw_background();

        Matrix4 hammer_xform = m4_scalar(1.0);
        hammer_xform         = m4_rotate_z(hammer_xform, frame_data.now);
        hammer_xform         = m4_translate(hammer_xform, v3(-25, -25, 0));
        draw_rect_xform(hammer_xform, v2(50, 50), COLOR_RED);

        gfx_update();
        log_fps();
    }

    return 0;
}