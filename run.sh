export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES=libft_malloc.so
export DYLD_FORCE_FLAT_NAMESPACE=1

if [ $1 = "error" ]
then
	export MallocErrorAbort=1
	$2 3>STDBUG
elif [ $1 = "log" ]
then
	export MallocLogHistory=1
	$2 3>STDBUG
elif [ $1 = "check" ]
then
	export MallocCheckHeapStart=10
	export MallocCheckHeapEach=1
	$2 3>STDBUG
else
	$1 3>STDBUG
fi
