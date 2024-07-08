#define MAX_ENTITY_TYPES 128

/**
 * The type of entity that an entity represents.
 */
typedef enum EntityType {
    poobaloobie = 0,
    balloon = 1,
    punch_table = 2,
} EntityType;

/**
 * Buffer of entity graphics assets. Indexed according to EntityType
 */
Gfx_Image *entity_gfx[MAX_ENTITY_TYPES];

/**
 * An entity that can be rendered into the scene
 */
typedef struct Entity {
    bool valid;
    EntityType type;
    Vector2 position;
    Vector2 size;
    bool visible;
} Entity;

/**
 * Initialize and load entity graphics from the disk.
 */
void init_entity_gfx() {
    // Assets to load
    const char *image_uris[] = {
        "assets/dev_poobaloobie.png",
        "assets/dev_balloon.png",
        "assets/dev_punch_table.png",
    };

    // Load graphics and place in graphics buffer
    const Allocator allocator = get_heap_allocator();
    for (int i = 0; i < sizeof(image_uris) / sizeof(char *); i++) {
        entity_gfx[i] = load_image_from_disk(STR(image_uris[i]), allocator);
        assert(entity_gfx[i], "Failed to load asset from disk %s", image_uris[i]);
    }
}

/**
 * Draw an entity in the scene.
 * @param entity The entity to draw
 */
void draw_entity(const Entity *entity) {
    if (entity == NULL || !entity->visible) {
        return;
    }

    Matrix4 xform = m4_scalar(1.0);
    xform         = m4_rotate_z(xform, frame_data.now);
    xform         = m4_translate(xform, v3(entity->position.x, entity->position.y, 0));
    draw_image_xform(entity_gfx[entity->type], xform, entity->size, COLOR_WHITE);
}
