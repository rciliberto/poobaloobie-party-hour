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

/**
 * Log fps to the console
 */
void frame_data_log_fps() {
    log_info("Frame Time: %.2f ms", frame_data.delta_t * 1000);
    log_info("Frame Rate: %.2f fps", 1.0/frame_data.delta_t);
}
