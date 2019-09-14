/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:06:58 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/06 13:12:05 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	new = ft_strnew(len);
	if (!new)
	{
		return (NULL);
	}
	i = 0;
	s = s + start;
	while (*(s + i) && i < len)
	{
		*(new + i) = *(s + i);
		i++;
	}
	return (new);
}
