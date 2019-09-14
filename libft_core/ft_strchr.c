/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:44:54 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/01 15:06:14 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (*(str + i) == (char)c)
		{
			return ((char*)str + i);
		}
		i++;
	}
	return (NULL);
}
