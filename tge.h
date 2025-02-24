#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <dirent.h>

#define IMG_LOADING

#include "terminal_gl.h"
#include "tgl_gui.h"

#ifdef _WIN32

    #include "impl/backend_windows.c"
#elif __linux__
    #include "impl/backend_linux.c"
#endif

#define FPS 60

struct music{
    Mix_Music *data;
};

struct sfx{
    Mix_Chunk *data;
};

struct window* debug_win;

void init_tge(char* name);

struct music load_music(const char* fname);
struct sfx load_sfx(const char* fname);

#include "include/init.c"
#include "include/sound.c"

struct vector_2{
    int x;
    int y;
};

struct vector_line{
    char color;
    char char_;
    struct vector_2 v1;
    struct vector_2 v2;
};

void draw_vector_line(struct vector_line line);

#include "include/vector.c"

struct animated_sprite{
    struct text_image* img;
    int frame_count;
    int frame_rate;

    int current_frame;
    int tick_counter;
};

struct animated_sprite new_animated_sprite_from_folder(const char* dname, int frame_rate, const char* file_extention);

void draw_animated_sprite(struct animated_sprite* spr, char square_pixel_aspect, struct vector_2 pos);

#include "include/sprite.c"
