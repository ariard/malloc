/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:31:48 by jhalford          #+#    #+#             */
/*   Updated: 2018/02/04 15:10:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_signed_conversion(t_fmt *fmt, va_list ap)
{
	char		base10[10];
	long long	arg;

	base10[0] = '0';
	base10[1] = '1';
	base10[2] = '2';
	base10[3] = '3';
	base10[4] = '4';
	base10[5] = '5';
	base10[6] = '6';
	base10[7] = '7';
	base10[8] = '8';
	base10[9] = '9';
	arg = va_arg(ap, int);
	(void)fmt;
	return (ft_lltoa_base(arg, base10, fmt->flags));
}

char	*ft_unsigned_conversion(t_fmt *fmt, va_list ap)
{
	unsigned int		uiarg;
	unsigned long long	ullarg;
	int					i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	if (!*fmt->modifier
			|| ft_strequ(fmt->modifier, "hh")
			|| ft_strequ(fmt->modifier, "h")
			|| ft_strequ(fmt->modifier, "z"))
	{
		uiarg = va_arg(ap, int);
		return (ft_uitoa_base(uiarg, g_convs[i].base));
	}
	ullarg = va_arg(ap, long long);
	return (ft_ulltoa_base(ullarg, g_convs[i].base));
}

char	*ft_char_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	ret = (char *)malloc(sizeof(char) + 1);
	ret[0] = (char)va_arg(ap, int);
	ret[1] = '\0';
	return (ret);
}

char	*ft_str_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	ret = va_arg(ap, char *);
	if (ret == NULL)
		return (ft_strdup("NULL"));
	ret = ft_strdup(ret);
	if (fmt->precision && fmt->precision < (int)ft_strlen(ret))
		ret[fmt->precision] = '\0';
	return (ret);
}
