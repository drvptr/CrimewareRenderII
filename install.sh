gcc -c io_xlib.c -o io.o
gcc main.c io.o -lX11 -lXext
