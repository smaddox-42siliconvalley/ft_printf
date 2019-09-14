/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:13:12 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/19 15:01:47 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t				len(int n, int base)
{
	int i;

	i = 0;
	while (n > 0)
	{
		++i;
		n /= base;
	}
	return (i);
}

static char					*handle_min(void)
{
	char *str;

	str = ft_strnew(11);
	ft_strcpy(str, "-2147483648");
	return (str);
}

char						*ft_itoa_base(int n, int base)
{
	char	*str;
	size_t	size;
	int		sign;

	sign = (n < 0) ? 1 : 0;
	if (sign)
	{
		if (n == -2147483648)
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
