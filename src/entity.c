/**
 * The type of entity that an entity represents.
 */
typedef enum EntityType {
    entity_null,
    entity_poobaloobie = 1,
    entity_balloon = 2,
    entity_punch_table = 3,
    ENTITY_MAX
} EntityType;

/**
 * Buffer of entity graphics res. Indexed according to EntityType
 */
Gfx_Image *entity_gfx[ENTITY_MAX];

/**
 * An entity that can be rendered into the scene
 */
typedef struct Entity {
    bool valid;
    EntityType type;
    Vector2 position;
    bool visible;
} Entity;

/**
 * Initialize and load entity graphics from the disk.
 */
void init_entity_gfx() {
    const Allocator allocator = get_heap_allocator();

    // Load missing texture
    const char *missing_texture_uri = "res/missing_texture.png";
    Gfx_Image *missing_texture = load_image_from_disk(STR(missing_texture_uri), allocator);
    assert(missing_texture, "Failed to load missing_texture from disk at %s", missing_texture_uri);

    // Set all textures to missing texture
    for (int i = 0; i < ENTITY_MAX / sizeof(char *); i++) {
        entity_gfx[i] = missing_texture;
    }

    // Load graphics and place in graphics buffer
    // This is explicitly done for each asset for now
    entity_gfx[entity_poobaloobie] = load_image_from_disk(STR("res/dev_poobaloobie.png"), allocator);
    entity_gfx[entity_balloon] = load_image_from_disk(STR("res/dev_balloon_16w.png"), allocator);
    entity_gfx[entity_punch_table] = load_image_from_disk(STR("res/dev_punch_table_128w.png"), allocator);
}

/**
 * Draw an entity in the scene.
 * @param entity The entity to draw
 */
void draw_entity(const Entity *entity) {
    if (entity == NULL || !entity->visible) {
        return;
    }

    Gfx_Image *gfx_image = entity_gfx[entity->type];

    Matrix4 xform = m4_scalar(1.0);
    xform         = m4_translate(xform, v3(floorl(entity->position.x), floorl(entity->position.y), 0));
    draw_image_xform(gfx_image, xform, v2(gfx_image->width, gfx_image->height), COLOR_WHITE);
}
