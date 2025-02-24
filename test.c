#include "tge.h"

int main(){

    init_tge("test program");

    struct music test1 = load_music("turc.wav");

    struct sfx test2 = load_sfx("pew.wav");

    play_music(test1, false);
    play_sfx(test2);
    while(1){
        fill_screen('#', 0x5e);

        render_window(debug_win, 3, 3);

        scan_input();

        if(is_key_pressed('q')){
            system("reset");
            return 0;
        }

        update();
    }
}