void init_tge(char* name){

    #ifndef DEBUG_WINDOW_WIDTH
    printf("No default debug window size\nAborting\n");
    exit(-1);
    #endif

    #ifndef DEBUG_WINDOW_HEIGHT
    printf("No default debug window size\nAborting\n");
    exit(-1);
    #endif
    init_window(name);
    debug_win = create_window("tge debug window", DEBUG_WINDOW_WIDTH, DEBUG_WINDOW_HEIGHT);

    int error_counter = 0;

    #ifdef SDL_AUDIO

    if(SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf_win(debug_win, 0x40, "sdl2 could not start\n");
        error_counter++;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf_win(debug_win, 0x40, "sdl2 mixer could not start\n");
        error_counter++;
    }
    #endif

    printf_win(debug_win, 0xf0, "%s has started with %d error(s)\n", name, error_counter);

    ms_sleep = 1000 / FPS;
}