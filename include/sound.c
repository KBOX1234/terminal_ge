struct music load_music(const char* fname){
    struct music return_struct;

    return_struct.data = Mix_LoadMUS(fname);

    if(!return_struct.data){
        printf_win(debug_win, 0x40, "failed to load music: %s\n", fname);
    }

    return return_struct;
}
struct sfx load_sfx(const char* fname){
    struct sfx return_struct;

    return_struct.data = Mix_LoadWAV(fname);

    if(!return_struct.data){
        printf_win(debug_win, 0x40, "failed to load sfx: %s\n", fname);
    }

    return return_struct;
}


void play_music(struct music m, bool play_once){
    if(play_once == true)Mix_PlayMusic(m.data, 0);
    else Mix_PlayMusic(m.data, -1);
}

void play_sfx(struct sfx sfx_s){
    Mix_PlayChannel(-1, sfx_s.data, 0);
}