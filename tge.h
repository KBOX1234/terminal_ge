#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <dirent.h>
#include <math.h>
#include "dyad.h"
#include "sphysics.h"

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

struct text_image mash_color_and_text(struct text_image color, struct text_image text);

#include "include/texture.c"
#include "include/utill.c"


//normal entity
struct entity{
    bool is_player;
    struct point master_pos;

    struct vector_2 pos;

    bool has_texture;
    struct text_image texture;

    bool has_animations;
    int animation_count;
    int active_animation;
    struct animated_sprite* animations;
    

    bool is_transperent;

    bool has_colide_box;
    bool square_pixel_aspect;
    struct colideBox box;
    struct vector_2 size;

    void* custom_data;

    long id;

    bool solid;
};

void add_default_texture(struct text_image img, struct entity* friend);

void add_default_texture_from_file(struct entity* friend, const char* fname);

void update_from_master(struct entity* friend);

void move_in_direction(struct entity* friend, float angle, int distance);

struct entity new_entity(struct point pos, struct text_image img, int id);

void add_animation(struct animated_sprite spr, struct entity* friend);

void draw_entity(struct entity* friend);

#include "include/entity.c"

struct object{
    struct vector_2 pos;

    bool has_texture;
    struct text_image texture;

    bool is_transperent;

    bool has_colide_box;
    bool square_pixel_aspect;
    struct colideBox box;
    struct vector_2 size;

    void* custom_data;

    long id;

    bool solid;
};

struct object new_object(int id);

void set_object_texture(struct object* obj, struct text_image img);

void set_object_pos(struct object* obj, struct vector_2 pos);

void update_obj(struct object* obj);

void draw_object(struct object* obj);

#include "include/object.c"