Gfx_Image* background_image;

#define ASPECT_RATIO (16.0 / 9.0)
#define WINDOW_HEIGHT 480

void window_init() {
    window.title = STR("Poobaloobie Party Hour");
    window.width = WINDOW_HEIGHT * ASPECT_RATIO;
    window.height = WINDOW_HEIGHT;
    window.x = 200;
    window.y = 200;
    window.clear_color = hex_to_rgba(0x6495EDff);

    background_image = load_image_from_disk(STR("assets/dev_background.png"), get_heap_allocator());
}

void window_update_start() {
    draw_frame.projection = m4_make_orthographic_projection(window.width * -0.5, window.width * 0.5, window.height * -0.5, window.height * 0.5, -1, 10);
    float zoom = 1;
    draw_frame.view = m4_make_scale(v3(1.0/zoom, 1.0/zoom, 1.0));
}

void window_update_delta(float64 delta_t) {
    if (window.width / window.height > ASPECT_RATIO) {
        draw_image(background_image, v2(window.height * -0.5 * ASPECT_RATIO,window.height * -0.5), v2(window.height * ASPECT_RATIO, window.height), COLOR_WHITE);
    } else {
        draw_image(background_image, v2(window.width * -0.5,window.width * -0.5 * (1 / ASPECT_RATIO)), v2(window.width, window.width * (1 / ASPECT_RATIO)), COLOR_WHITE);
    }
}