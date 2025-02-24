#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

#include "terminal_gl.h"
#include "tgl_gui.h"

#ifdef _WIN32

    #include "impl/backend_windows.c"
#elif __linux__
    #include "impl/backend_linux.c"
#endif

struct music{
    Mix_Music *data;
};

struct sfx{
    Mix_Chunk *data;
};

void init_tge();

struct music load_music(const char* fname);
struct sfx load_sfx(const char* fname);

#include "include/init.c"
#include "include/sound.c"