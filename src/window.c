#define VIEW_HEIGHT 480.0
#define VIEW_WIDTH 854.0
#define VIEW_ASPECT (VIEW_WIDTH / VIEW_HEIGHT)

/**
 * Initialize the window on program launch. Set things like width, height, and load data from disk.
 */
void window_init() {
    window.title = STR("Poobaloobie Party Hour");
    window.width = VIEW_WIDTH;
    window.height = VIEW_HEIGHT;
    window.x = 200;
    window.y = 200;
    window.clear_color = COLOR_BLACK;
}

/**
 * Update frame properties. Set frame projection and scale.
 */
void window_frame_update() {
	draw_frame.projection = m4_make_orthographic_projection(window.pixel_width * -0.5, window.pixel_width * 0.5,
	    window.pixel_height * -0.5, window.pixel_height * 0.5, -1, 10);
    const float64 window_aspect = (float64) window.pixel_width / window.pixel_height;

    // Set zoom such that the 480p 16:9 area of game is taking up maximal space without exceeding the projection space
    float64 zoom;
    if (window_aspect > VIEW_ASPECT) {
        zoom = (float64) window.pixel_height / VIEW_HEIGHT;
    } else {
        zoom = (float64) window.pixel_width / VIEW_WIDTH;
    }

    draw_frame.view = m4_make_scale(v3(1.0/zoom, 1.0/zoom, 1.0));
}