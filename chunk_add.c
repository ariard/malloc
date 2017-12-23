#include "malloc.h"

void	*chunck_add(t_bin, size_t req, t_cfg *cfg)
{
	int		*tag;
	int		size;

	size = S_PTR;
	while (req > size)
		size += S_PTR;
	size += 2 * sizeof(int);
	tag = (int *)bin->free_list;
	bin->free_list += size;
	*tag = size;

	return (tag + 1);


void	*chunk_pack(

// pack
// create new free_chunck
// update previous free_chunck->next if one
// update next free_chunck->previous if one


// it s a bin check, if fragmentation is really bad can block even if freespace > size
//
// compta all free chunk to know when give back mem, free_chunk add when free
//
// size with boundary include
//
// on paper first, explicit all particular rules
//
// coaslescing when best-fit failed on first-pass
