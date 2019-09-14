/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:21:56 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/03 21:14:50 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*tempstr1;
	unsigned char	*tempstr2;

	if (!n)
	{
		return (0);
	}
	tempstr1 = (unsigned char*)str1;
	tempstr2 = (unsigned char*)str2;
	i = 0;
	n--;
	while (n != 0 && (*(tempstr1 + i)) == (*(tempstr2 + i)))
	{
		n--;
		i++;
	}
	return ((int)(*(tempstr1 + i)) - (int)(*(tempstr2 + i)));
}
