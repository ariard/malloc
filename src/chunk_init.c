#include "malloc.h"

/*
** Return a new chunck from the requested size
*/

t_chunk	*chunk_init(void *freespace, size_t size, t_chunk *previous)
{
	t_chunk	*new;

	DBG(GREEN "Init chunk" RESET);
	new = freespace;
	new->next = NULL;		
	new->previous = previous;
	new->status = FULL;
	new->size = size;
	return (new);
}	
