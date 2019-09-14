/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:28:58 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/03 22:12:56 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_places(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*alloc_string(int n, int size)
{
	char	*str;

	if (n < 0)
	{
		str = ft_strnew(size + 1);
		if (!str)
		{
			return (NULL);
		}
		str[0] = '-';
	}
	else
	{
		str = ft_strnew(size);
		if (!str)
		{
			return (NULL);
		}
	}
	return (str);
}

static char	*st_solve_edges(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strnew(1);
		if (!str)
		{
			return (NULL);
		}
		return (ft_strcpy(str, "0"));
	}
	if (n == -2147483648)
	{
		str = ft_strnew(10);
		if (!str)
		{
			return (NULL);
		}
		return (ft_strcpy(str, "-2147483648"));
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*newstr;

	size = count_places(n);
	newstr = alloc_string(n, size);
	if (!newstr)
	{
		return (NULL);
	}
	if (n == 0 || n == -2147483648)
		return (st_solve_edges(n));
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n != 0)
	{
		*(newstr + (size - 1)) = (n % 10) + '0';
		size--;
		n /= 10;
	}
	return (newstr);
}
