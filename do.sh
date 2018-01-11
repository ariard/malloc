gcc -c -Wall -Werror -I includes/ -fPIC shared.c inside.c
gcc -shared -o libshared.so inside.o shared.o
gcc -L/home/user/Projects/malloc/ -Wall -I includes/ main.c -o main -lshared
export LD_LIBRARY_PATH=/home/user/Projects/malloc
gcc -shared -o myuid.so myuid.c
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES=myuid.so
export DYLD_FORCE_FLAT_NAMESPACE=1


Linux :
	LD_LIBRARY_PATH
	LD_PRELOAD
