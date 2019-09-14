/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:14:00 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/06 13:13:42 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*begin;
	char	*end;
	char	*newstr;
	int		dist;

	if (!s)
		return (NULL);
	begin = (char*)s;
	dist = 0;
	end = (ft_strlen(s) - 1) + (char*)s;
	while (*begin && (*begin == 32 || *begin == 10 || *begin == 9))
		begin++;
	while (end > begin && (*end == 32 || *end == 10 || *end == 9))
		end--;
	while ((begin + dist) <= end)
		dist++;
	newstr = ft_strnew(dist);
	if (!newstr)
		return (NULL);
	newstr = ft_strncpy(newstr, begin, dist);
	return (newstr);
}
