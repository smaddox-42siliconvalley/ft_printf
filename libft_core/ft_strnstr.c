/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:01:54 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/03 19:40:58 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		found;
	char	*haystackholder;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	haystackholder = (char*)haystack;
	found = 1;
	if (needle_len == 0)
		return (haystackholder);
	while (*haystackholder && n > 0)
	{
		if (n < needle_len)
			break ;
		found = ft_strncmp(haystackholder, needle, needle_len);
		if (found == 0)
			return (haystackholder);
		haystackholder++;
		n--;
	}
	return (NULL);
}
