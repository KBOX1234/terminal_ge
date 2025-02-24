flags="-lm"
include="-I./terminal_gl -I./stb -I./tgl_gui"

gcc test.c -o test $flags $include