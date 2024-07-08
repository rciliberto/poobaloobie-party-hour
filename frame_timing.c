/**
 * Struct that contains data related to frame timing.
 */
typedef struct FrameData {
    /** Timestamp of last frame in seconds since game started */
    float64 last_time;

    /** Current timestamp in seconds since game started */
    float64 now;

    /** Delta time between frames */
    float64 delta_t;
} FrameData;

/** Global struct for tracking frame data */
static FrameData frame_data = {};

/**
 * Frame data calculation at end of frame
 */
void frame_data_calculate() {
    frame_data.now = os_get_current_time_in_seconds();
    frame_data.delta_t = frame_data.now - frame_data.last_time;
    frame_data.last_time = frame_data.now;
}


#if CONFIGURATION != RELEASE
/** Time since last full second */
float64 seconds_counter;

/** number of frames in the past second */
s32 frame_count;

/**
 * Log fps every second
 */
void frame_data_log_fps() {
    seconds_counter += frame_data.delta_t;
    frame_count += 1;
    if (seconds_counter > 1.0) {
        log_info("fps: %i", frame_count);
        seconds_counter = 0.0;
        frame_count = 0;
    }
}
#endif
