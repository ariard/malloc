/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:09:54 by ariard            #+#    #+#             */
/*   Updated: 2018/01/12 19:29:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <dirent.h>
# include "../libft/includes/libft.h"

# define		EXIT(x)		{ ft_dprintf(2, "%s\n", x) ; exit(1); }
# define		P(x)			ft_dprintf(1, "%s\n", x);

# define		DIR_TEST	"/Users/ariard/Projects/malloc/test/"

# define GREEN		"\x1b[32m"
# define RED		"\x1b[31m"
# define YELLOW		"\x1b[33m"
# define RESET		"\x1b[0m"

#endif
