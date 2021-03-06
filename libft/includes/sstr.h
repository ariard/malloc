/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:16:25 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 11:35:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSTR_H
# define SSTR_H

char	**ft_sstradd(char **list, char *new);
void	ft_sstrsort(char **list, int (*cmp)());
void	ft_sstrprint(char **list, char sep);
void	ft_sstrprint_fd(int fd, char **list, char sep);
char	**ft_sstrdup(char **list);
void	ft_sstrdel(char **sstr, int index);
void	ft_sstrfree(char **sstr);
char	*ft_sstrcat(char **sstr, char sep);
char	*ft_sstrstr(char **sstr, char *find);

#endif
