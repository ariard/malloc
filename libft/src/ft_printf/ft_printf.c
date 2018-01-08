/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:27 by jhalford          #+#    #+#             */
/*   Updated: 2018/01/08 18:17:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_convs[] =
{
	{'d', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'i', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'u', "0-", "0123456789", &ft_unsigned_conversion, NULL},
	{'o', "#0-", "01234567", &ft_unsigned_conversion, &ft_pad_sharp_o},
	{'x', "#0-", "0123456789abcdef", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'X', "#0-", "0123456789ABCDEF", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'b', "#0-", "01", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'s', "-", "", &ft_str_conversion, NULL},
	{'c', "-", "", &ft_char_conversion, NULL},
};

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(1, format, ap));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	char	*tmp;
	char	*final;

	str = (char *)format;
	final = ft_strnew(1);
	while (*str)
	{
		tmp = final;
		if (*str == '{')
			ft_printf_color(fd, &final, &str);
		else if (*str == '%')
		{
			if (ft_fmtcalc(&final, &str, ap))
				return (1);
		}
		else
			final = ft_strjoin(final, (char[]){*str++, 0});
		ft_strdel(&tmp);
	}
	ft_putstr_fd(final, fd);
	ft_strdel(&final);
	return (0);
}

int	ft_fmtcalc(char **final, char **str, va_list ap)
{
	t_fmt	*fmt;
	char	*transform;

	*str += 1;
	if (!(fmt = ft_printf_parse(str, ap)))
		return (1);
	if (!fmt->valid)
		ft_strncat(*final, &fmt->conversion, 1);
	else
	{
		transform = ft_transform(fmt, ap);
		*final = ft_strjoin(*final, transform);
		ft_strdel(&transform);
	}
	free(fmt);
	return (0);
}
