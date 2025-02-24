int init_sdl2(){
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        return 1;
    }
}

int init_midi(){
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        return 1;
    }
}

void init_tge(){
    if(init_sdl2() < 0) printf("SDL2 could not start\n");
    if(init_midi() < 0) printf("sdl2 midi mixer could not start\n");
}