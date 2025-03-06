#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifdef SDL_AUDIO
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#endif
#include <stdbool.h>
#include <dirent.h>
#include <math.h>
#include "sphysics.h"

#define IMG_LOADING

#include "terminal_gl.h"
#include "tgl_gui.h"

#ifdef _WIN32

    #include "impl/backend_windows.c"
#elif __linux__
    #include "impl/backend_linux.c"
#endif

//window that all debug info is sent to
struct window* debug_win;


#ifdef ENET_NETWORKING
#include "enet/enet.h"

extern ENetHost *client;
extern ENetPeer *server;
extern ENetEvent event;

#include "networking/network.c"

#define CHANNELS 2

#pragma pack(push, 1)

struct packaged_packet{
    size_t size;
    void* data;
};

#pragma pack(pop)

#define DISCONNECTED 1

struct packaged_packet package_packet(void* packet, size_t size);

int send_packet(struct packaged_packet p);

void* unpackage_packet(struct packaged_packet p);

#include "networking/packet.c"

void send_data_tgl_ge(void *data, size_t s, ENetPeer *to);

int connect_to_server(const char* ip_adress, enet_uint16 port);

int receive_packet(int max_wait_time, struct packaged_packet* p);

#include "networking/request.c"

#endif

int FPS = 60;

#ifdef SDL_AUDIO
//tge music wrapper
struct music{
    Mix_Music *data;
};

//tge sfx wrapper
struct sfx{
    Mix_Chunk *data;
};

#endif

//inits tge and sets the window name
void init_tge(char* name);

#ifdef SDL_AUDIO
//load music
struct music load_music(const char* fname);

//load sfx
struct sfx load_sfx(const char* fname);
#include "include/sound.c"

#endif
#include "include/init.c"

//vector 2
struct vector_2{
    int x;
    int y;
};

//vector line
struct vector_line{
    char color;
    char char_;
    struct vector_2 v1;
    struct vector_2 v2;
};


//function for drawing vector lines
void draw_vector_line(struct vector_line line);

#include "include/vector.c"

//animated sprite struct
struct animated_sprite{
    struct text_image* img;
    int frame_count;
    int frame_rate;

    int current_frame;
    int tick_counter;
};

//new animated sprite
struct animated_sprite new_animated_sprite_from_folder(const char* dname, int frame_rate, const char* file_extention);

//draw animated sprite
void draw_animated_sprite(struct animated_sprite* spr, char square_pixel_aspect, struct vector_2 pos);

#include "include/sprite.c"

//combine a text texture and a color texture
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

bool do_entities_colide(struct entity* e1, struct entity* e2);

bool does_entity_and_object_colide(struct entity* e, struct object* o);

#include "include/colide.c"

#define ESCAPE 0x1B

#include "include/input.c"