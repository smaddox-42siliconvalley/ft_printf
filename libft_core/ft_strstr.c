/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:51:44 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/01 15:25:47 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *thehaystack, char const *needle)
{
	int		found;
	char	*haystack;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	haystack = (char*)thehaystack;
	found = 1;
	if (needle_len == 0)
	{
		return (haystack);
	}
	while (*haystack)
	{
		found = ft_strncmp(haystack, needle, needle_len);
		if (found == 0)
		{
			return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
