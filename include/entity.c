//friend :)

void add_default_texture(struct text_image img, struct entity* friend){
    friend->texture = img;
    friend->has_texture = true;
}

void add_default_texture_from_file(struct entity* friend, const char* fname){
    struct text_image img = load_image_to_text(fname, ' ');
    add_default_texture(img, friend);
}

void update_from_master(struct entity* friend){
    friend->pos = p2v(friend->master_pos);

    friend->box.a = v2p(friend->pos);
    friend->box.b = v2p(friend->pos);

    friend->box.b.x = friend->box.b.x + friend->size;
    friend->box.b.y = friend->box.b.y + friend->size;
}

void move_in_direction(struct entity* friend, float angle, int distance){
    float dist = (float)distance;
    
    double angle_rad = angle * (M_PI / 180.0);

    friend->master_pos.x += dist * cos(angle_rad);
    friend->master_pos.y += dist * sin(angle_rad);
}

