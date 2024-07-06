
int entry(int argc, char **argv) {

    window.title = STR("Poobaloobie Party Hour");
    window.width = 843;
    window.height = 480;
    window.x = 200;
    window.y = 200;
    window.clear_color = hex_to_rgba(0x6495EDff);

    float64 seconds_counter = 0.0;
    s32 frame_count = 0;

    float64 last_time = os_get_current_time_in_seconds();

    while (!window.should_close) {
        reset_temporary_storage();

        os_update();

        float64 now = os_get_current_time_in_seconds();
        float64 delta_t = now - last_time;
        last_time = now;

        Matrix4 hammer_xform = m4_scalar(1.0);
        hammer_xform         = m4_rotate_z(hammer_xform, (f32)now);
        hammer_xform         = m4_translate(hammer_xform, v3(-.25f, -.25f, 0));
        draw_rect_xform(hammer_xform, v2(.5f, .5f), COLOR_RED);

        gfx_update();
        seconds_counter += delta_t;
        frame_count += 1;
        if (seconds_counter > 1.0) {
            log("fps: %i", frame_count);
            seconds_counter = 0.0;
            frame_count = 0;
        }
    }

    return 0;
}