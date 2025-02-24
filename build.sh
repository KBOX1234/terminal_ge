flags="-lm `sdl2-config --cflags --libs` -lSDL2_mixer -fpermissive"
include="-I./terminal_gl -I./stb -I./tgl_gui -I./dyad"

gcc test.c -o test $flags $include