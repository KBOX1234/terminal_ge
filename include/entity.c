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

    moveBox(&friend->box, friend->master_pos);
}

void move_in_direction(struct entity* friend, float angle, int distance){
    float dist = (float)distance;
    
    double angle_rad = angle * (M_PI / 180.0);

    friend->master_pos.x += dist * cos(angle_rad);
    friend->master_pos.y += dist * sin(angle_rad);
}

struct entity new_entity(struct point pos, struct text_image img, int id){
    struct entity friend;
    friend.animation_count = 0;
    friend.has_animations = false;
    friend.has_colide_box = false;
    friend.has_texture = true;
    friend.is_player = false;
    friend.is_transperent = false;
    friend.master_pos = pos;
    friend.size.x = img.x;
    friend.size.y = img.y;
    friend.square_pixel_aspect = false;
    friend.texture = img;
    friend.active_animation = 0;

    friend.solid = true;

    return friend;
}

void add_animation(struct animated_sprite spr, struct entity* friend) {
    friend->has_animations = true;

    struct animated_sprite* tmp_spr = (struct animated_sprite*)malloc(sizeof(struct animated_sprite) * (friend->animation_count + 1));
    if (!tmp_spr) {
        printf_win(debug_win, 0x40, "Memory allocation failed for animations\n");
        return;
    }

    if (friend->animation_count > 0) {
        memcpy(tmp_spr, friend->animations, sizeof(struct animated_sprite) * friend->animation_count);
        free(friend->animations); // Free old memory after copying
    }

    tmp_spr[friend->animation_count] = spr;

    friend->animations = tmp_spr;
    friend->animation_count++;
}


void draw_entity(struct entity* friend){
    update_from_master(friend);
    if(friend->is_transperent == false){
        if(friend->has_animations == true){
            //printf("AAA\n"); 
            draw_animated_sprite(&friend->animations[friend->active_animation], friend->square_pixel_aspect, friend->pos);
        }
    
        else if(friend->has_texture == true){
            render_text_image(friend->texture, friend->pos.x, friend->pos.y, friend->square_pixel_aspect);
        }
    }
}