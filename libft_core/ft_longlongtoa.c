/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:55:23 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/19 14:12:24 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len(long long n, int base)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

static char			*handle_min(void)
{
	char *str;

	str = ft_strnew(20);
	ft_strcpy(str, "-9223372036854775808");
	return (str);
}

char				*ft_longlongtoa_base(long long n, int base)
{
	char	*str;
	size_t	size;
	int		sign;

	sign = (n < 0) ? 1 : 0;
	if (sign)
	{
		if (n == LLONG_MIN)
			return (handle_min());
		n *= -1;
	}
	size = len(n, base) + sign;
	str = ft_strnew(size);
	str[0] = sign ? '-' : '0';
	while (n > 0)
	{
		str[--size] = BASE_DIGITS[n % base];
		n /= base;
	}
	return (str);
}
