struct text_image mash_color_and_text(struct text_image color, struct text_image text){
    if(color.x == text.x && color.y == text.y){
        struct text_image rtv;

        rtv.color_data = malloc(text.x*text.y);
        rtv.buffer_data = malloc(text.x*text.y);

        memcpy(rtv.color_data, color.color_data, text.x*text.y);
        memcpy(rtv.buffer_data, text.buffer_data, text.x*text.y);

        return rtv;
    }
    return color;
}