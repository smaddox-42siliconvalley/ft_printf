/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:15:19 by smaddox           #+#    #+#             */
/*   Updated: 2019/04/30 19:05:03 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char cc;

	cc = c;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (size)
	{
		while (size > 0)
		{
			if ((*d++ = *s++) == cc)
				return (d);
			size--;
		}
	}
	return (NULL);
}
