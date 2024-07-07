#define ASPECT_RATIO (16.0 / 9.0)
#define WINDOW_HEIGHT 480

/** image used for the background of the scene */
Gfx_Image* background_image;

/**
 * Initialize the window on program launch. Set things like width, height, and load data from disk.
 */
void window_init() {
    window.title = STR("Poobaloobie Party Hour");
    window.width = WINDOW_HEIGHT * ASPECT_RATIO;
    window.height = WINDOW_HEIGHT;
    window.x = 200;
    window.y = 200;
    window.clear_color = hex_to_rgba(0x6495EDff);

    background_image = load_image_from_disk(STR("assets/dev_background.png"), get_heap_allocator());
}

/**
 * Update frame properties. Set frame projection and scale.
 */
void frame_update() {
    draw_frame.projection = m4_make_orthographic_projection(window.width * -0.5, window.width * 0.5, window.height * -0.5, window.height * 0.5, -1, 10);
    float zoom = 1;
    draw_frame.view = m4_make_scale(v3(1.0/zoom, 1.0/zoom, 1.0));
}

/**
 * Draw the background in the center of the window. Scale appropriately based on window aspect ratio.
 */
void draw_background() {
    if (window.width / window.height > ASPECT_RATIO) {
        draw_image(background_image, v2(window.height * -0.5 * ASPECT_RATIO,window.height * -0.5), v2(window.height * ASPECT_RATIO, window.height), COLOR_WHITE);
    } else {
        draw_image(background_image, v2(window.width * -0.5,window.width * -0.5 * (1 / ASPECT_RATIO)), v2(window.width, window.width * (1 / ASPECT_RATIO)), COLOR_WHITE);
    }
}