/**
 * Struct that contains data related to frame timing.
 */
typedef struct FrameData {
    /** Time since last full second */
    float64 seconds_counter;

    /** number of frames in the past second */
    s32 frame_count;

    /** Timestamp of last frame in seconds since game started */
    float64 last_time;

    /** Current timestamp in seconds since game started */
    float64 now;

    /** Delta time between frames */
    float64 delta_t;
} frame_data_t;

/** Global struct for tracking frame data */
static frame_data_t frame_data = {};

/** Frame data calculation at start of frame */
void frame_calculation_start() {
    frame_data.now = os_get_current_time_in_seconds();
    frame_data.delta_t = frame_data.now - frame_data.last_time;
    frame_data.last_time = frame_data.now;
}

/** Frame data calculation at end of frame */
void frame_calculation_end() {
    frame_data.seconds_counter += frame_data.delta_t;
    frame_data.frame_count += 1;
    if (frame_data.seconds_counter > 1.0) {
        log("fps: %i", frame_data.frame_count);
        frame_data.seconds_counter = 0.0;
        frame_data.frame_count = 0;
    }
}



