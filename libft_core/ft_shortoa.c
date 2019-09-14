/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:54:34 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/19 15:00:53 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len(short n, int base)
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

	str = ft_strnew(6);
	ft_strcpy(str, "-32768");
	return (str);
}

char				*ft_shorttoa_base(short n, int base)
{
	char	*str;
	size_t	size;
	int		sign;

	sign = (n < 0) ? 1 : 0;
	if (sign)
	{
		if (n == -32768)
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
