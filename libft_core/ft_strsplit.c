/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:37:55 by smaddox           #+#    #+#             */
/*   Updated: 2019/05/06 18:03:27 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cyclec(char const *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) == c)
	{
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	**derp;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	words = (char**)malloc((word_count + 1) * sizeof(char**));
	derp = words;
	if (words == NULL)
	{
		return (NULL);
	}
	words[word_count] = NULL;
	while (word_count > 0)
	{
		s = s + ft_cyclec(s, c);
		*words = ft_strsub(s, 0, ft_strclen(s, c));
		s = ft_strchr(s, c);
		words++;
		word_count--;
	}
	return (derp);
}
