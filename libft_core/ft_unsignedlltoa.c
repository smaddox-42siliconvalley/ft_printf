/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:55:23 by smaddox           #+#    #+#             */
/*   Updated: 2019/07/19 14:07:49 by smaddox          ###   ########.fr       */
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

char				*ft_unsignedlltoa_base(unsigned long long n, int base)
{
	char	*str;
	size_t	size;

	size = len(n, base);
	str = ft_strnew(size);
	str[0] = '0';
	while (n > 0)
	{
		str[--size] = BASE_DIGITS[n % base];
		n /= base;
	}
	return (str);
}
