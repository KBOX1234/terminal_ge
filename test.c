#define ENET_NETWORKING

#define DEBUG_WINDOW_WIDTH 60
#define DEBUG_WINDOW_HEIGHT 30

#include "tge.h"

int main(){

    init_tge("test program");

    struct music test1 = load_music("turc.wav");

    struct sfx test2 = load_sfx("pew.wav");

    play_music(test1, false);
    play_sfx(test2);

    struct vector_line line;
    line.char_ = '#';
    line.color = 0x34;
    line.v1.x = 40;
    line.v1.y = 3;
    line.v2.x = 30;
    line.v2.y = 20;

    struct animated_sprite spr;

    struct vector_2 spr_pos;

    struct text_image default_t = load_image_to_text("test_animation/0.png", ' ');

    spr_pos.x = 20;
    spr_pos.y = 20;

    struct entity friend = new_entity(v2p(spr_pos), default_t, 1);

    spr = new_animated_sprite_from_folder("test_animation", 2, "png");
    struct animated_sprite spr2 = new_animated_sprite_from_folder("second_animation", 2, "png");

    add_animation(spr, &friend);
    add_animation(spr2, &friend);

    struct text_image test_img = load_buffer("test.txt");

    //friend.has_animations = false;
    //friend.has_texture = true;
    
    while(1){
        fill_screen('#', 0x5e);

        render_text_image(test_img, 1, 1, 0);

        render_window(debug_win, 3, 3);

        draw_vector_line(line);

        draw_animated_sprite(&spr, 0, spr_pos);

        scan_input();


        draw_entity(&friend);


        if(is_key_pressed('q')){
            system("reset");
            return 0;
        }

        if(is_key_pressed('w')) spr_pos.y--;
        if(is_key_pressed('s')) spr_pos.y++;
        if(is_key_pressed('a')) spr_pos.x--;
        if(is_key_pressed('d')) spr_pos.x++;

        if(is_key_pressed('e')) friend.active_animation = 0;
        if(is_key_pressed('r')) friend.active_animation = 1;

        update();
    }
}