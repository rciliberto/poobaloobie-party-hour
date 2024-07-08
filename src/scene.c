#define MAX_SCENE_ENTITIES 256

typedef struct Scene {
    /** image used for the background of the scene */
    Gfx_Image *background_image;
    Entity *entities[MAX_SCENE_ENTITIES];
} Scene;

/**
 * Draw the background in the center of the window. Scale appropriately based on window aspect ratio.
 */
void scene_draw_background(const Scene *scene) {
    if ((float64) window.width / window.height > ASPECT_RATIO) {
        draw_image(scene->background_image, v2(window.height * -0.5 * ASPECT_RATIO, window.height * -0.5),
                   v2(window.height * ASPECT_RATIO, window.height), COLOR_WHITE);
    } else {
        draw_image(scene->background_image, v2(window.width * -0.5, window.width * -0.5 * (1 / ASPECT_RATIO)),
                   v2(window.width, window.width * (1 / ASPECT_RATIO)), COLOR_WHITE);
    }
}

/**
 * Draw all entities associated with the scene.
 * @param scene The scene to draw entities
 */
void scene_draw_entities(const Scene *scene) {
    for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
        if (!scene->entities[0]) return;
        draw_entity(scene->entities[i]);
    }
}
