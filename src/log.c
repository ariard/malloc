#include "malloc.h"

void	logmem(void *ptr, char from, t_area *ar)
{
	static int	file;	
	char		name[100 + 1];
	char		*pid;

	if (!ft_strncmp(ar->reentrancy, "2", 1))
		return;	
	ar->reentrancy = "2";
	if (!file)	
	{
		ft_bzero(name, 100);
		ft_strcpy(name, "/tmp/.tmp-malloc-log-");
		pid = ft_itoa((int)getpid());
		ft_strcat(name, pid);
		file = open(name, O_CREAT | O_WRONLY, 0644);
	}
	if (ptr && file)
		ft_dprintf(file, "[%s] %p size : %lu\n",
			(from == 0) ? "malloc" : "free", ptr, BT(ptr));
	ar->reentrancy = "1";
}
