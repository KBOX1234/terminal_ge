#include "tge.h"

int main(){

    init_tge();

    struct music test1 = load_music("turc.wav");

    struct sfx test2 = load_sfx("pew.wav");

    play_music(test1, false);
    play_sfx(test2);
    while(1);
}