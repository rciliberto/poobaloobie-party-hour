#define ASPECT_RATIO (16.0 / 9.0)
#define WINDOW_HEIGHT 480

/**
 * Initialize the window on program launch. Set things like width, height, and load data from disk.
 */
void window_init() {
    window.title = STR("Poobaloobie Party Hour");
    window.width = WINDOW_HEIGHT * ASPECT_RATIO;
    window.height = WINDOW_HEIGHT;
    window.x = 200;
    window.y = 200;
    window.clear_color = COLOR_BLACK;
}

/**
 * Update frame properties. Set frame projection and scale.
 */
void window_frame_update() {
    draw_frame.projection = m4_make_orthographic_projection(window.width * -0.5, window.width * 0.5, window.height * -0.5, window.height * 0.5, -1, 10);
    float zoom = 1;
    draw_frame.view = m4_make_scale(v3(1.0/zoom, 1.0/zoom, 1.0));
}