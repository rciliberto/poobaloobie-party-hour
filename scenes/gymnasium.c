Gfx_Image *gymnasium_background;

/**
 * Initialize the Gymnasium scene. Deallocates entities in the scene and replaces them with Gymnasium specific entities.
 * @param scene The scene pointer to initialize with gymnasium data.
 */
void init_gymnasium_scene(Scene *scene) {
    if (!gymnasium_background) {
        gymnasium_background = load_image_from_disk(STR("assets/dev_background.png"), get_heap_allocator());
        assert(gymnasium_background, "Gymnasium background image failed to load");
    }

    scene->background_image = gymnasium_background;

    for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
        dealloc_entity(scene->entities[i]);
        scene->entities[i] = NULL;
    }

    scene->entities[0] = alloc_entity(poobaloobie, v2(0, 0), v2(100,100), true);
}

