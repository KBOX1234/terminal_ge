struct object new_object(int id) {
    struct object obj;

    // Set default values
    obj.pos = (struct vector_2){0, 0};          // Default position (0,0)
    
    obj.has_texture = false;                    // No texture by default
    memset(&obj.texture, 0, sizeof(struct text_image)); // Zero out texture
    
    obj.is_transperent = false;                 // Not transparent
    obj.has_colide_box = false;                 // No collision box
    obj.box = (struct colideBox){0};            // Default empty collision box
    obj.size = (struct vector_2){0, 0};         // Default size (0,0)
    
    obj.custom_data = NULL;                     // No custom data
    obj.id = id;                                 // Default ID (0)
    
    obj.solid = false;                          // Not solid
    obj.square_pixel_aspect = false;            // Default pixel aspect (false)

    return obj;
}

void set_object_texture(struct object* obj, struct text_image img){
    obj->has_texture = true;

    obj->texture = img;
}

void set_object_pos(struct object* obj, struct vector_2 pos){
    obj->pos = pos;
}

void update_obj(struct object* obj){
    obj->box.a = v2p(obj->pos);
    obj->box.b = v2p(obj->pos);

    obj->box.b.x = obj->box.b.x + obj->size.x;
    obj->box.b.y = obj->box.b.y + obj->size.y;
}

void draw_object(struct object* obj){
    if(obj->has_texture == true){
        render_text_image(obj->texture, obj->pos.x, obj->pos.y, obj->square_pixel_aspect);
    }
}