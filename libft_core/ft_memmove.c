/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:00:09 by smaddox           #+#    #+#             */
/*   Updated: 2019/04/30 20:44:19 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*srcs;
	char	*dests;

	srcs = (char*)src;
	dests = (char*)dest;
	i = 0;
	if (src < dest)
	{
		while (n != 0)
		{
			n--;
			*(dests + n) = *(srcs + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(dests + i) = *(srcs + i);
			i++;
		}
	}
	return (dest);
}
