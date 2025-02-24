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
    spr_pos.x = 20;
    spr_pos.y = 20;

    spr = new_animated_sprite_from_folder("test_animation", 2, "png");
    
    while(1){
        fill_screen('#', 0x5e);

        render_window(debug_win, 3, 3);

        draw_vector_line(line);

        draw_animated_sprite(&spr, 1, spr_pos);

        scan_input();

        if(is_key_pressed('q')){
            system("reset");
            return 0;
        }

        update();
    }
}