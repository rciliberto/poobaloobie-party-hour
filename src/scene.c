#define MAX_SCENE_ENTITIES 256

typedef struct Scene {
    /** image used for the background of the scene */
    Gfx_Image *background_image;
    Entity entities[MAX_SCENE_ENTITIES];
} Scene;

/**
 * Draw the background in the center of the window. Scale appropriately based on window aspect ratio.
 */
void scene_draw_background(const Scene *scene) {
    draw_image(scene->background_image, v2(VIEW_WIDTH * -0.5, VIEW_HEIGHT * -0.5),
        v2(VIEW_WIDTH, VIEW_HEIGHT), COLOR_WHITE);
}

/**
 * Draw all entities associated with the scene.
 * @param scene The scene to draw entities
 */
void scene_draw_entities(const Scene *scene) {
    for (int i = 0; i < MAX_SCENE_ENTITIES; i++) {
        if (&scene->entities[0] == NULL) return;
        draw_entity(&scene->entities[i]);
    }
}
