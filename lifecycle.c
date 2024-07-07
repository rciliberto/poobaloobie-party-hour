#define BUFFER_SIZE 10

typedef void (*LifecycleCallback)();
typedef void (*UpdateDeltaCallback)(float64 delta_t);

LifecycleCallback lifecycle_init_callbacks[] = {
    window_init,
};

LifecycleCallback lifecycle_update_begin_callbacks[] = {
    reset_temporary_storage,
    window_update_start,
    frame_calculation_update,
    os_update,
};

UpdateDeltaCallback lifecycle_update_delta_callbacks[] = {
    log_fps,
    window_update_delta
};

LifecycleCallback lifecycle_update_end_callbacks[] = {
    gfx_update,
};

void lifecycle_init() {
    for (int i = 0; i < sizeof(lifecycle_init_callbacks) / sizeof(LifecycleCallback); i++) {
        lifecycle_init_callbacks[i]();
    }
}

void lifecycle_update_begin() {
    for (int i = 0; i < sizeof(lifecycle_update_begin_callbacks) / sizeof(LifecycleCallback); i++) {
        lifecycle_update_begin_callbacks[i]();
    }
}

void lifecycle_update_delta(const float64 delta_t) {
    for (int i = 0; i < sizeof(lifecycle_update_delta_callbacks) / sizeof(UpdateDeltaCallback); i++) {
        lifecycle_update_delta_callbacks[i](delta_t);
    }
}

void lifecycle_update_end() {
    for (int i = 0; i < sizeof(lifecycle_update_end_callbacks) / sizeof(LifecycleCallback); i++) {
        lifecycle_update_end_callbacks[i]();
    }
}