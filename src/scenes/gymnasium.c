Scene gymnasium_scene;

/**
 * Initialize the Gymnasium scene. Deactivates entities in the gymnasium scene and re-adds entities to their default
 * state.
 * @return The scene pointer to with gymnasium data.
 */
Scene *init_gymnasium_scene() {
    if (gymnasium_scene.background_image == NULL) {
        gymnasium_scene.background_image = load_image_from_disk(STR("assets/dev_background.png"), get_heap_allocator());
        assert(gymnasium_scene.background_image, "Gymnasium background image failed to load");
    }

    for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
        gymnasium_scene.entities[i].valid = false;
    }

    gymnasium_scene.entities[0] = (Entity) {
        .valid = true,
        .type = poobaloobie,
        .position = v2(-250, -250),
        .size = v2(500,500),
        .visible = true
    };

    return &gymnasium_scene;
}

