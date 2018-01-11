/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:35:38 by ariard            #+#    #+#             */
/*   Updated: 2018/01/11 19:33:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void		test_launch(char *path, char *env)
{
	close(STDIN);
	close(STDOUT);
	execve(path, (char *[]) { NULL }, (char *[]) { env, NULL });
}

static void		test_analyze(char *test, int status, int *ret)
{
	if (status == 0)
		ft_printf("[%s] :" GREEN" SUCCESS\n"RESET, test);

	if (status > 0)
		ft_printf("[%s] :" RED" FAILURE\n"RESET, test);
	*ret = (0 == status) ? *ret + 1 : *ret;
}

static t_list	*test_load(void)
{
	DIR					*p;
	struct dirent 		*dir; 
	t_list		*tests;

	if (!(p = opendir(DIR_TEST)))
		EXIT("opendir")

	tests = NULL;
	while ((dir = readdir(p)) != NULL)
		if ((strncmp(dir->d_name, ".", 1)))
			ft_lsteadd(&tests, ft_lstnew(dir->d_name, ft_strlen(dir->d_name)));
	return (tests);
}

int		main(void)
{
	char				*env;
	int					pid;
	t_list				*tests;
	t_list				*tmp;
	int					status;
	int					nbr;
	int					ret;
	char				*t;

	env = getenv("TEST_OPTS");

	tests = test_load();

	nbr = ft_lstsize(tests);
	ret = 0;

	while ((tmp = ft_lst_pop(&tests)) && (t = (char *)tmp->content))
	{
		pid = fork();

		if (pid == 0)
			test_launch(ft_strjoin(DIR_TEST, t), env);
		waitpid(pid, &status, WCONTINUED);

		if (WIFEXITED(status))
			test_analyze(t, WEXITSTATUS(status), &ret);
	}
	ft_printf("TESTS : %d/%d\n", ret, nbr);
}
