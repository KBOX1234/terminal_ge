int dir_file_count(const char *dname) {
    DIR *dir = opendir(dname);
    if (dir == NULL) {
        printf_win(debug_win, 0x40, "directory %s does not exist\n", dname);
        return -1;
    }

    int count = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' directories
        if (entry->d_name[0] != '.') {
            count++;
        }
    }

    closedir(dir);
    return count;
}

//file extentions should use "png" for example and not ".png"
struct animated_sprite new_animated_sprite_from_folder(const char* dname, int frame_rate, const char* file_extention){
    int file_count = dir_file_count(dname);
    if(file_count == -1){
        printf_win(debug_win, 0x40, "failed to load sprite\n");
        struct animated_sprite empty;
        empty.frame_count = 0;
        return empty;
    }

    if(file_count == 0){
        printf_win(debug_win, 0x60, "there are 0 files in derectory: %s\nnothing to do\n", dname);

        struct animated_sprite empty;
        empty.frame_count = 0;
        return empty;
    }
    else printf_win(debug_win, 0x20, "loading %d images to sprite\n", file_count);

    struct animated_sprite return_v;

    return_v.img = (struct text_image*)malloc(sizeof(struct text_image)*(file_count));

    return_v.frame_count = file_count-1;
    return_v.frame_rate = frame_rate;

    //init the counter values
    return_v.current_frame = 0;
    return_v.tick_counter = 0;

    //load stuff

    int inc = 0;

    while(inc < file_count){
        char append[100];
        sprintf(append, "%s/%d.%s", dname, inc, file_extention);

        return_v.img[inc] = load_image_to_text(append, '#');
        printf_win(debug_win, 0x20, "loading image: %s to sprite\n", append);
        inc++;
    }

    return return_v;

}

void draw_animated_sprite(struct animated_sprite* spr, char square_pixel_aspect, struct vector_2 pos){
    render_text_image(spr->img[spr->current_frame], pos.x, pos.y, square_pixel_aspect);

    spr->tick_counter++;

    if(spr->tick_counter > FPS/spr->frame_rate){
        spr->tick_counter = 0;
        spr->current_frame++;
    }

    if(spr->current_frame > spr->frame_count){
        spr->current_frame = 0;
    }
}