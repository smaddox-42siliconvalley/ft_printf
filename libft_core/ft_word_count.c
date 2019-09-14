/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:46:43 by smaddox           #+#    #+#             */
/*   Updated: 2019/04/30 15:50:37 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char delimiter)
{
	size_t	total;
	int		in_word;

	in_word = 0;
	total = 0;
	while (*s)
	{
		if (*s == delimiter)
		{
			s++;
		}
		else
		{
			total++;
			if (!(s = ft_strchr(s, delimiter)))
			{
				return (total);
			}
		}
	}
	return (total);
}
