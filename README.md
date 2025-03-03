# Terminal GE
Terminal Game Engin is a game library framework that uses [terminal GL](https://github.com/KBOX1234/terminal_gl).

## What is terminal GE?
Terminal GE is an extention of [terminal GL](https://github.com/KBOX1234/terminal_gl) which adds features that are lacking in [terminal GL](https://github.com/KBOX1234/terminal_gl).

## Basic example
```c
#include "tge.h"

int main(){

    init_tge("test program");


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
    
    while(1){
        fill_screen('#', 0x5e);
        render_window(debug_win, 3, 3);
        scan_input();
        draw_entity(&friend);

        if(is_key_pressed('e')) friend.active_animation = 0;
        if(is_key_pressed('r')) friend.active_animation = 1;

        update();
    }
}
```
## What features does tge add?

- Automatic platform selection
- Music & SFX
- Easy debugging with [tgl_ui](https://github.com/KBOX1234/tgl_gui)
- Vectors
- Animated sprites
- Entities and Objects

## Why do I need this?
(Its the same reason you use chat gpt)
