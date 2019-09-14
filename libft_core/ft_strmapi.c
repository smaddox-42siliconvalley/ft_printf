/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:03:58 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/06 13:15:50 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (s && f)
	{
		i = 0;
		new = ft_strnew(ft_strlen(s));
		if (!new)
		{
			return (NULL);
		}
		while (*(s + i))
		{
			*(new + i) = f(i, *(s + i));
			i++;
		}
		return (new);
	}
	return (NULL);
}
