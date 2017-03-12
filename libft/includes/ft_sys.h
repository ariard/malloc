/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:09:02 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 13:19:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYS_H
# define FT_SYS_H

# define FT_XATTR_SIZE	10000
# define STDIN			STDIN_FILENO
# define STDOUT			STDOUT_FILENO
# define STDERR			STDERR_FILENO
# define STDBUG			3

# include <sys/types.h>
# include <sys/xattr.h>

int		ft_xattr_print(char *path);
int		ft_xattr_count(char *path);
char	*ft_getenv(char **env, char *key);
int		dup2_close(int fd1, int fd2);

#endif
