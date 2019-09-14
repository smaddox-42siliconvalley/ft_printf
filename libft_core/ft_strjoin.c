/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:09:11 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/06 13:15:00 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	char *temp;

	if (!(s1 && s2))
		return (NULL);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new)
	{
		return (NULL);
	}
	temp = new;
	while (*s1)
	{
		*temp++ = *s1++;
	}
	while (*s2)
	{
		*temp++ = *s2++;
	}
	*temp = '\0';
	return (new);
}
