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

# Setting up
Here is a simple setup guide.
## Linux
All you need to do is to locate the names of the packages for: sdl and sdl_mixer for your distro and install it with your package manager.

After that rember to include these gcc library flags: -lSDL2_mixer -lSDL2 -lm
You will also need to add the include directories: terminal_gl, terminal_gl/stb, and tgl_ui with the -I gcc flag.

The build command should look somthing like this:
```sh
gcc test.c -o test -lm `sdl2-config --cflags --libs` -lSDL2_mixer -g -I./terminal_gl -I./stb -I./tgl_gui -I./dyad/src -I./sphysics
```

## Windows
Download the [sdl2_mixer runtime](https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.8.1/SDL2_mixer-2.8.1-win32-x86.zip), locate SDL2_mixer.dll and include it next to your executable. Also do the same with [SDL2 runtime](https://github.com/libsdl-org/SDL/releases/download/release-2.32.2/SDL2-2.32.2-win32-x86.zip).

Next download the [SDL2 mixer](https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.8.1/SDL2_mixer-devel-2.8.1-mingw.zip) and [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.32.2/SDL2-devel-2.32.2-mingw.zip) sorce code. Create a folder in C: and name it sdl2. Find the folders: include, lib, and bin in the sld2 and sld2_mixer sorce folders and copy them into C:\sdl2 and your done.

To build, include these flags: -lSDL2_mixer -lSDL2 -lm, and these include flags: IC:\sdl2\include\ -LC:\sdl2\lib

The build command should look somthing like this:
```sh
gcc test.c -o test -lm -g -I./terminal_gl -I./stb -I./tgl_gui -I./dyad/src -I./sphysics IC:\sdl2\include\ -LC:\sdl2\lib -lSDL2_mixer -lSDL2
```
