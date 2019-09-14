/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:41:47 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/01 15:03:04 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_len;
	size_t i;
	size_t src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	while (*(src + i) && dest_len + i < size - 1 && dest_len < size)
	{
		dest[dest_len + i] = *(src + i);
		i++;
	}
	if (dest_len < size)
	{
		dest[dest_len + i] = '\0';
	}
	return (src_len + (dest_len < size ? dest_len : size));
}
