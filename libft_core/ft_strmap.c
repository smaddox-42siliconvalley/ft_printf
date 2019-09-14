/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:02:38 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/04 20:33:58 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			*(new + i) = f(*(s + i));
			i++;
		}
		return (new);
	}
	return (NULL);
}
