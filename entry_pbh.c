#include "window.c"
#include "frame_timing.c"
#include "lifecycle.c"

int entry(int argc, char **argv) {
    lifecycle_init();

    while (!window.should_close) {
        lifecycle_update_begin();

        lifecycle_update_delta(frame_data.delta_t);

        Matrix4 hammer_xform = m4_scalar(1.0);
        hammer_xform         = m4_rotate_z(hammer_xform, frame_data.now);
        hammer_xform         = m4_translate(hammer_xform, v3(-25, -25, 0));
        draw_rect_xform(hammer_xform, v2(50, 50), COLOR_RED);

        lifecycle_update_end();
    }

    return 0;
}