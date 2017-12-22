gcc -c -Wall -Werror -I includes/ -fPIC shared.c inside.c
gcc -shared -o libshared.so inside.o shared.o
gcc -L/home/user/Projects/malloc/ -Wall -I includes/ main.c -o main -lshared
export LD_LIBRARY_PATH=/home/user/Projects/malloc
