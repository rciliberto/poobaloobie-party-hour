#include "frame_timing.c"

int entry(int argc, char **argv) {
    window.title = STR("Poobaloobie Party Hour");
    window.width = 843;
    window.height = 480;
    window.x = 200;
    window.y = 200;
    window.clear_color = hex_to_rgba(0x6495EDff);

    while (!window.should_close) {
        reset_temporary_storage();
        os_update();

        Matrix4 hammer_xform = m4_scalar(1.0);
        hammer_xform         = m4_rotate_z(hammer_xform, frame_data.now);
        hammer_xform         = m4_translate(hammer_xform, v3(-.25f, -.25f, 0));
        draw_rect_xform(hammer_xform, v2(.5f, .5f), COLOR_RED);

        gfx_update();
        frame_calculation_update();
    }

    return 0;
}