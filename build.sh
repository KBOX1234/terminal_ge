flags="-lm `sdl2-config --cflags --libs` -lSDL2_mixer"
include="-I./terminal_gl -I./stb -I./tgl_gui"

gcc test.c -o test $flags $include