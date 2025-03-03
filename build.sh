flags="-lm `sdl2-config --cflags --libs` -lSDL2_mixer -lenet -g"
include="-I./terminal_gl -I./stb -I./tgl_gui -I./dyad/src -I./sphysics"

gcc test.c -o test $flags $include